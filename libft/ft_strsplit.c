/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:24:09 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/17 19:00:00 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nbchar(char const *str, char c)
{
	int i;

	i = 0;
	while (*(str + i) != '\0' && str[i] != c)
		i++;
	return (i);
}

static	int		mytstr(char **tstr, char const *s, char c)
{
	int		i;
	int		k;
	int		wordcount;

	k = 0;
	i = 0;
	wordcount = ft_nbrstr(s, c);
	while (wordcount-- && *s)
	{
		while (*s == c)
			s++;
		tstr[i] = ft_strsub(s, 0, nbchar(s, c));
		if (tstr == NULL)
			return (0);
		s += nbchar(s, c);
		i++;
	}
	tstr[i] = 0;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tstr;

	if (s == NULL)
		return (NULL);
	tstr = (char **)malloc((ft_nbrstr(s, c) + 1) * sizeof(char*));
	if (tstr == NULL)
		return (NULL);
	if (mytstr(tstr, s, c) == 0)
		return (NULL);
	return (tstr);
}
