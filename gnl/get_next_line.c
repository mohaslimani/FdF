/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:41:09 by msoulaim          #+#    #+#             */
/*   Updated: 2019/05/08 21:10:52 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_lstat		*ft_new(const int fd, t_lstat **lst)
{
	if ((*lst = (t_lstat *)malloc(sizeof(t_lstat))))
	{
		(*lst)->fd = fd;
		(*lst)->content = (char *)ft_memalloc(1);
		(*lst)->next = NULL;
	}
	return (*lst);
}

t_lstat		*ft_lst(const int fd, t_lstat **tete)
{
	t_lstat	*alst;

	if (!*tete)
		ft_new(fd, tete);
	alst = *tete;
	while (alst != NULL)
	{
		if (alst->fd == fd)
			return (alst);
		alst = alst->next;
	}
	ft_new(fd, &alst);
	alst->next = *tete;
	*tete = alst;
	return (alst);
}

void		get_next_line_b(const int fd, t_lstat *stat, int *ret)
{
	char			*tmp;
	char			str[BUFF_SIZE + 1];

	*ret = 0;
	while (!(ft_strchr(stat->content, '\n')) &&
			(*ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		tmp = stat->content;
		str[*ret] = '\0';
		stat->content = ft_strjoin(stat->content, str);
		free(tmp);
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_lstat	*o;
	t_lstat			*stat;
	unsigned int	i;
	int				ret;
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	stat = ft_lst(fd, &o);
	get_next_line_b(fd, stat, &ret);
	if (ret < 1 && !*(stat->content))
		return (ret);
	if (!ft_strchr(stat->content, '\n'))
	{
		*line = ft_strdup(stat->content);
		ft_strclr(stat->content);
		return (1);
	}
	i = ft_strlen(stat->content) - ft_strlen(ft_strchr(stat->content, '\n'));
	*line = ft_strsub(stat->content, 0, i);
	tmp = stat->content;
	stat->content = ft_strdup(stat->content + i + 1);
	ft_strdel(&tmp);
	return (1);
}
