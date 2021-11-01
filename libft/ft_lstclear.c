/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:22:01 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/29 20:19:56 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*lnext;

	if (lst == NULL)
		return ;
	l = *lst;
	if (l != NULL)
		lnext = l->next;
	while (l != NULL)
	{
		del(l->content);
		free(l);
		l = lnext;
		if (l != NULL)
			lnext = l->next;
	}
	*lst = NULL;
}
