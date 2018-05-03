/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:27:09 by nsikora           #+#    #+#             */
/*   Updated: 2017/11/16 14:15:33 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstaddtoend(t_list **alst, t_list *new)
{
	t_list		*t;

	if (alst && *alst && new)
	{
		t = *alst;
		while (t->next)
			t = t->next;
		t->next = new;
		t->next->next = NULL;
	}
	if (!(*alst))
	{
		*alst = new;
		(*alst)->next = NULL;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ret;

	ret = NULL;
	while (lst)
	{
		ft_lstaddtoend(&ret, f(lst));
		lst = lst->next;
	}
	return (ret);
}
