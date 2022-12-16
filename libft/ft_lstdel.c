/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:22:36 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/18 22:24:14 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*o;
	t_list	*k;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	o = *alst;
	while (o != NULL)
	{
		k = o->next;
		del(o->content, o->content_size);
		ft_memdel((void **)&o);
		o = k;
	}
	*alst = NULL;
}
