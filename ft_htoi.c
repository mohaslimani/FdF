/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:28:18 by msoulaim          #+#    #+#             */
/*   Updated: 2020/02/18 19:31:23 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	long		htoi(char *str)
{
	long	long	decimal;
	int				len;
	int				i;
	int				val;

	decimal = 0;
	len = strlen(str);
	len--;
	i = 0;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			val = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			val = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			val = str[i] - 'A' + 10;
		decimal = decimal + val * pow(16, len);
		len--;
		i++;
	}
	return (decimal);
}
