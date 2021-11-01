/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:55:48 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/28 14:48:20 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;
	size_t			i;

	if (((src == NULL) && (dst == NULL)) || (n == 0))
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s[i] == ch)
		{
			d[i] = s[i];
			i++;
			return (&d[i]);
		}
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
