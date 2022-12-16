/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:30:06 by msoulaim          #+#    #+#             */
/*   Updated: 2020/01/30 17:30:35 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

typedef	struct	s_xyz
{
	int			color;
	int			z;
	int			zga;
}				t_xyz;

typedef	struct	s_xy
{
	int			x;
	int			y;
	int			color;
}				t_xy;

typedef	struct	s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_line;

typedef	struct	s_fdf
{
	t_xyz		**coordon;
	t_xy		**xy;
	char		*av;
	int			toll_coor;
	int			l3ard_coor;
	void		*win;
	void		*win2;
	void		*mlx;
	void		*img;
	int			bpp;
	int			sline;
	int			endian;
	int			*img_data;
	int			pp;
	int			x_side;
	int			y_side;
	float		z_side;
	float		zoom;
	float		alpha;
	float		gamma;
	float		beta;
}				t_fdf;

void			init_fdf(t_fdf *fdf);
void			draw_fdf(t_fdf *fdf);
void			event(t_fdf *fdf);
void			free_coord(t_fdf *fdf);
void			free_2dim(char **str);
int				fdf_free_all(t_fdf *fdf);
t_line			init_line(t_xy a, t_xy b);
void			get_check_coor(t_fdf *fdf, char **av);
t_xyz			**get_coord(char **av);
long	long	htoi(char *str);
#endif
