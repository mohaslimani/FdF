/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:42:25 by msoulaim          #+#    #+#             */
/*   Updated: 2020/02/14 17:59:30 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_2dim(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = str[i];
		i++;
		free(tmp);
	}
	free(str[i]);
}

void		free_coord(t_fdf *fdf)
{
	int		i;
	t_xyz	*tmp;

	i = 0;
	while (fdf->coordon[i])
	{
		tmp = fdf->coordon[i];
		i++;
		free(tmp);
	}
	free(fdf->coordon[i]);
	free(fdf->coordon);
}

int			fdf_free_all(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->toll_coor - 1)
	{
		i++;
		free(fdf->xy[i]);
	}
	free_coord(fdf);
	exit(0);
	return (0);
}
