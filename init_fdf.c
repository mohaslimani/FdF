/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:05:58 by msoulaim          #+#    #+#             */
/*   Updated: 2020/02/14 16:41:23 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	init_line(t_xy a, t_xy b)
{
	t_line	line;

	line.x0 = a.x;
	line.y0 = a.y;
	line.x1 = b.x;
	line.y1 = b.y;
	line.dx = abs(line.x1 - line.x0);
	line.sx = line.x0 < line.x1 ? 1 : -1;
	line.dy = abs(line.y1 - line.y0);
	line.sy = line.y0 < line.y1 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	return (line);
}

int		color(int z, int color)
{
	if (color != 0)
		return (color);
	if (z > 12)
		return (0xFF00EC);
	if (z > 6)
		return (0x9700FF);
	if (z > 3)
		return (0x0023FF);
	if (z > 2)
		return (0x00FFD4);
	if (z > 1)
		return (0x42FF00);
	if (z > 0)
		return (0xFF0000);
	return (0xFFFFFF);
}

void	init_fdf_2(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	fdf->xy = (t_xy **)malloc(fdf->toll_coor * sizeof(t_xy*));
	while (i < fdf->toll_coor)
	{
		j = 0;
		fdf->xy[i] = (t_xy *)malloc(fdf->l3ard_coor * sizeof(t_xy));
		while (j < fdf->l3ard_coor)
		{
			fdf->xy[i][j].x = j * fdf->pp - ((fdf->l3ard_coor / 2) * fdf->pp);
			fdf->xy[i][j].y = i * fdf->pp - ((fdf->toll_coor / 2) * fdf->pp);
			fdf->xy[i][j].color = color(fdf->coordon[i][j].z,
													fdf->coordon[i][j].color);
			j++;
		}
		i++;
	}
}

void	str_put(t_fdf *fdf)
{
	fdf->win2 = mlx_new_window(fdf->mlx, 450, 500, "CONTROL :)");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 15, 0xFF0000, "--MENU--");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 60, 0xBDFF00, "  246789_for\
															_rotating");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 95, 0xBDFF00, "  arrows\
										_for_moving_up/down/right/left");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 130, 0xBDFF00, "  (+/-) are \
															for zooming");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 165, 0xBDFF00, "  (q/w/a/s)\
												_for_moving_into_corners");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 200, 0xBDFF00, "  (i)_for_\
													isometrique_projection");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 235, 0xBDFF00, "  (p)_for_\
													parallel_projection");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 270, 0xBDFF00, "  (o)_for_\
											(oblique/top_down)_projection");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 305, 0xBDFF00, "  (c)_for_\
													cavalier_projection");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 340, 0xBDFF00, "  (DIVIDE/MULTIPLY)\
														_control_hight");
	mlx_string_put(fdf->mlx, fdf->win2, 10, 375, 0xBDFF00, "  ESC_\
														for_shut_down");
}

void	init_fdf(t_fdf *fdf)
{
	if (fdf->toll_coor > fdf->l3ard_coor)
		fdf->pp = 500 / fdf->toll_coor;
	else
		fdf->pp = 500 / fdf->l3ard_coor;
	fdf->zoom = 1;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, fdf->av);
	str_put(fdf);
	fdf->img = mlx_new_image(fdf->mlx, 1000, 1000);
	fdf->img_data = (int *)mlx_get_data_addr(fdf->img,
				&(fdf->bpp), &(fdf->sline), &(fdf->endian));
	fdf->alpha = 0;
	fdf->gamma = 0;
	fdf->beta = 0;
	fdf->z_side = 1;
	fdf->x_side = 500 - (fdf->l3ard_coor / 2) * fdf->pp;
	fdf->y_side = 500 - (fdf->toll_coor / 2) * fdf->pp;
	init_fdf_2(fdf);
}
