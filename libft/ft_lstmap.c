/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:21:59 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/29 22:06:18 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*lstb;

	if ((lst == NULL) || (f == NULL))
		return (NULL);
	lst2 = ft_lstnew(f(lst->content));
	if (lst2 == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		lstb = ft_lstnew(f(lst->content));
		if (lstb == NULL)
		{
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, lstb);
		lst = lst->next;
	}
	return (lst2);
}
