/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:02:56 by msoulaim          #+#    #+#             */
/*   Updated: 2020/02/14 18:02:57 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_coord(t_fdf *fdf)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	while (fdf->coordon[0][k].zga != 0)
		k++;
	fdf->l3ard_coor = k;
	i = 0;
	while (fdf->coordon[i])
	{
		j = 0;
		while (fdf->coordon[i][j].zga != 0)
			j++;
		if (k > j)
		{
			ft_putendl_fd("error", 2);
			free_coord(fdf);
			exit(1);
		}
		i++;
	}
	fdf->toll_coor = i;
}

void		get_check_coor(t_fdf *fdf, char **av)
{
	fdf->coordon = get_coord(av);
	if (fdf->coordon == NULL)
	{
		ft_putendl_fd("error", 2);
		exit(1);
	}
	check_coord(fdf);
}
