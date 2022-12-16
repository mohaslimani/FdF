/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:12:59 by msoulaim          #+#    #+#             */
/*   Updated: 2020/02/11 20:13:02 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		projections(int key, t_fdf *fdf)
{
	if (key == 34)
	{
		fdf->alpha = -1.0471975512;
		fdf->beta = 0.5235987756;
		fdf->gamma = -0.5235987756;
	}
	if (key == 31)
	{
		fdf->alpha = -0.785398;
		fdf->beta = 0;
		fdf->gamma = 0;
	}
	if (key == 8)
	{
		fdf->alpha = -0.785398;
		fdf->beta = 0.785398;
		fdf->gamma = 0;
	}
	if (key == 35)
	{
		fdf->alpha = 0;
		fdf->beta = 0;
		fdf->gamma = 0;
	}
}

void		angle(int key, t_fdf *fdf)
{
	if (key == 91)
		fdf->alpha = fdf->alpha - 0.1;
	if (key == 84)
		fdf->alpha = fdf->alpha + 0.1;
	if (key == 86)
		fdf->beta = fdf->beta - 0.1;
	if (key == 88)
		fdf->beta = fdf->beta + 0.1;
	if (key == 92)
		fdf->gamma = fdf->gamma + 0.1;
	if (key == 89)
		fdf->gamma = fdf->gamma - 0.1;
}

void		sides(int key, t_fdf *fdf)
{
	if (key == 124 || key == 1 || key == 13)
		fdf->x_side = fdf->x_side + 7;
	if (key == 123 || key == 12 || key == 0)
		fdf->x_side = fdf->x_side - 7;
	if (key == 125 || key == 1 || key == 0)
		fdf->y_side = fdf->y_side + 7;
	if (key == 126 || key == 12 || key == 13)
		fdf->y_side = fdf->y_side - 7;
	if (key == 67)
		fdf->z_side = fdf->z_side + 0.5;
	if (key == 75)
		fdf->z_side = fdf->z_side - 0.5;
}

int			keys(int key, t_fdf *fdf)
{
	if (key == 53)
		fdf_free_all(fdf);
	if (key == 69)
		fdf->zoom = fdf->zoom + 0.1;
	if (key == 78 && fdf->zoom > 0.01)
		fdf->zoom = fdf->zoom - 0.1;
	angle(key, fdf);
	projections(key, fdf);
	sides(key, fdf);
	if (key == 69 || key == 78
	|| key == 91 || key == 84 || key == 86 || key == 88 || key == 92
	|| key == 89 || key == 34 || key == 31 || key == 8 || key == 35
	|| key == 124 || key == 1 || key == 13 || key == 123 || key == 12
	|| key == 0 || key == 125 || key == 67 || key == 75 || key == 126)
		draw_fdf(fdf);
	return (0);
}

void		event(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, keys, fdf);
	mlx_hook(fdf->win, 17, 0, fdf_free_all, fdf);
	mlx_hook(fdf->win2, 2, 0, keys, fdf);
	mlx_hook(fdf->win2, 17, 0, fdf_free_all, fdf);
	mlx_loop(fdf->mlx);
}
