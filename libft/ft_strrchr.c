/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 04:35:28 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/13 18:28:16 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long len;

	len = ft_strlen(s) + 1;
	while (--len >= 0)
		if ((char)s[len] == (char)c)
			return ((char *)(s + len));
	return (0);
}
