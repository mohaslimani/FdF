/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:29:35 by msoulaim          #+#    #+#             */
/*   Updated: 2020/01/30 17:29:38 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf fdf;

	if (ac != 2)
		ft_putendl("Usage: ./fdf file");
	else
	{
		fdf.av = av[1];
		get_check_coor(&fdf, av);
		init_fdf(&fdf);
		draw_fdf(&fdf);
		event(&fdf);
	}
	return (0);
}
