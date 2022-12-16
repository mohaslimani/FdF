/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:16:01 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/13 19:20:48 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((*s1 == '\0' && *s2 == '\0') || n == 0)
		return (0);
	else if (*s1 == *s2)
		return (ft_strncmp(++s1, ++s2, --n));
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
