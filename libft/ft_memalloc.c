/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 00:35:07 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/14 15:50:45 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (s == NULL)
		return (NULL);
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
	return ((void *)s);
}
