/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:23:37 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/28 15:28:53 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;
	unsigned int	ls;

	if (s == NULL)
		return (NULL);
	ls = 0;
	while (s[ls] != '\0')
		ls++;
	if (ls <= start)
		len = 0;
	else if (ls <= (len + start))
		len = ls;
	subs = (char *)malloc(sizeof(*subs) * (len + 1));
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (len > i)
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	return (subs);
}
