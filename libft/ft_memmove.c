/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:22:59 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/09 21:48:46 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	size_t	j;

	j = -1;
	i = (int)len;
	if (dst <= src)
	{
		while (++j < len)
			((unsigned char *)dst)[j] = ((unsigned char *)src)[j];
	}
	else
		while (--i >= 0)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}
