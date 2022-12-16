/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:56:54 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/18 21:05:24 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*o;

	o = (t_list *)malloc(sizeof(t_list));
	if (o == NULL)
		return (NULL);
	o->next = NULL;
	if (content == NULL)
	{
		o->content = NULL;
		o->content_size = 0;
		return (o);
	}
	o->content = malloc(sizeof(content_size));
	if (o->content == NULL)
	{
		free(o);
		return (NULL);
	}
	ft_memmove(o->content, content, content_size);
	o->content_size = content_size;
	return (o);
}
