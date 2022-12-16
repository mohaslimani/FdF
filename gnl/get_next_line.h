/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:19:21 by msoulaim          #+#    #+#             */
/*   Updated: 2019/09/23 16:22:41 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/libft.h"
# define BUFF_SIZE 100000

int					get_next_line(const int fd, char **line);

typedef struct		s_lstat
{
	char			*content;
	int				fd;
	struct s_lstat	*next;
}					t_lstat;

#endif
