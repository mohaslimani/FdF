/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 01:52:26 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/14 02:10:31 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*str;
	size_t		i;

	i = 0;
	if (!(s == NULL || f == NULL))
	{
		str = (char *)malloc(ft_strlen(s) + 1);
		if (str == NULL)
			return (NULL);
		while (i < ft_strlen(s))
		{
			str[i] = (*f)((char)s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
