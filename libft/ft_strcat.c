/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:25:01 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/13 03:18:40 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t j;

	j = ft_strlen(s1);
	ft_memmove(s1 + ft_strlen(s1), s2, ft_strlen(s2));
	s1[j + ft_strlen(s2)] = '\0';
	return (s1);
}
