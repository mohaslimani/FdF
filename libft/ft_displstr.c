/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:45:41 by msoulaim          #+#    #+#             */
/*   Updated: 2019/04/19 18:55:36 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_displstr(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
	{
		ft_putstr(" List is empty.");
	}
	else
	{
		tmp = lst;
		while (tmp != NULL)
		{
			if (tmp->content)
				return ;
			ft_putstr(tmp->content);
			ft_putchar('\n');
			tmp = tmp->next;
		}
	}
}
