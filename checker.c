/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:48:28 by msoulaim          #+#    #+#             */
/*   Updated: 2019/10/16 20:48:52 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			l3ard(char **splited_line)
{
	int		i;

	i = 0;
	while (splited_line[i])
	{
		i++;
	}
	return (i);
}

int			nbr_lines(char *av)
{
	int		ret;
	int		i;
	int		k;
	char	*line;
	int		fd;

	ret = 0;
	i = 0;
	k = 0;
	fd = open(av, O_RDONLY);
	while ((k = get_next_line(fd, &line)) > 0)
	{
		ret++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (ret);
}

int			check_color(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != ',')
		i++;
	if (str[i] != '\0' && str[i + 1] != '\0'
		&& str[i + 2] != '\0' && str[i + 3])
		return (htoi(str + i + 3));
	return (0);
}

void		get_coord_2(t_xyz **coordon, char **splited_line,
											char **line, int i)
{
	int		j;

	j = 0;
	while (splited_line[j])
	{
		coordon[i][j].z = ft_atoi(splited_line[j]);
		coordon[i][j].color = check_color(splited_line[j]);
		coordon[i][j].zga = 1;
		j++;
	}
	coordon[i][j].zga = 0;
	free_2dim(splited_line);
	free(splited_line);
	splited_line = NULL;
	free(*line);
	*line = NULL;
}

t_xyz		**get_coord(char **av)
{
	int		fd;
	int		i;
	char	*line;
	char	**splited_line;
	t_xyz	**coordon;

	if ((fd = open(av[1], O_RDONLY)) <= 0)
		return (NULL);
	coordon = (t_xyz **)malloc((nbr_lines(av[1]) + 1) * sizeof(t_xyz*));
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		splited_line = ft_strsplit(line, ' ');
		coordon[i] = (t_xyz *)malloc((l3ard(splited_line) + 1) * sizeof(t_xyz));
		get_coord_2(coordon, splited_line, &line, i);
		i++;
	}
	close(fd);
	if (i == 0)
	{
		free(coordon);
		return (NULL);
	}
	coordon[i] = NULL;
	return (coordon);
}
