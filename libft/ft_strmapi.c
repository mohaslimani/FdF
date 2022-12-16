/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 02:12:35 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/14 15:54:35 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!(s == NULL || f == NULL))
	{
		str = (char *)malloc(ft_strlen(s) + 1);
		if (str == NULL)
			return (NULL);
		while (i < ft_strlen(s))
		{
			str[i] = (*f)(i, (char)s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
