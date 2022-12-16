/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:47:46 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/19 18:26:54 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*o;
	t_list	*p;

	if (f == NULL || lst == NULL)
		return (NULL);
	o = f(lst);
	p = o;
	if (o == NULL || p == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		o->next = f(lst);
		if (o->next == NULL)
			return (NULL);
		o = o->next;
	}
	return (p);
}
