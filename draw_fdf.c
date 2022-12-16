/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:16:49 by msoulaim          #+#    #+#             */
/*   Updated: 2020/02/04 17:16:51 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x < 1000 && x >= 0 && y >= 0 && y < 1000)
		fdf->img_data[x + y * 1000] = color;
}

t_xy		project(int i, int j, t_fdf *fdf)
{
	t_xy	new;
	int		z;
	int		previous_x;
	int		previous_y;

	z = fdf->coordon[i][j].z * fdf->z_side;
	new.color = fdf->xy[i][j].color;
	previous_y = fdf->xy[i][j].y;
	new.y = previous_y * cos(fdf->alpha) + z * sin(fdf->alpha);
	z = -previous_y * sin(fdf->alpha) + z * cos(fdf->alpha);
	previous_x = fdf->xy[i][j].x;
	new.x = previous_x * cos(fdf->beta) + z * sin(fdf->beta);
	z = -previous_x * sin(fdf->beta) + z * cos(fdf->beta);
	previous_x = new.x;
	new.x = new.x * cos(fdf->gamma) - new.y * sin(fdf->gamma);
	new.y = previous_x * sin(fdf->gamma) + new.y * cos(fdf->gamma);
	new.x = new.x * fdf->zoom + (fdf->l3ard_coor / 2) * fdf->pp + fdf->x_side;
	new.y = new.y * fdf->zoom + (fdf->toll_coor / 2) * fdf->pp + fdf->y_side;
	return (new);
}

void		line(t_xy a, t_xy b, t_fdf *fdf)
{
	t_line	line;

	line = init_line(a, b);
	while (1)
	{
		put_pixel(fdf, line.x0, line.y0, a.color);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			line.x0 += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			line.y0 += line.sy;
		}
	}
}

void		draw_map(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->toll_coor)
	{
		j = 0;
		while (j < fdf->l3ard_coor)
		{
			if (j != fdf->l3ard_coor - 1)
				line(project(i, j, fdf), project(i, j + 1, fdf), fdf);
			if (i != fdf->toll_coor - 1)
				line(project(i, j, fdf), project(i + 1, j, fdf), fdf);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void		draw_fdf(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			put_pixel(fdf, i, j, 0x000000);
			j++;
		}
		i++;
	}
	if (fdf->l3ard_coor == 1 && fdf->toll_coor == 1)
		put_pixel(fdf, 500, 500, 0xFFFFFF);
	draw_map(fdf);
}
