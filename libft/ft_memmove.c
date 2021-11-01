/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:53:31 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/21 15:56:23 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_rev_move(unsigned char *d, unsigned const char *s, size_t len)
{
	size_t	i;

	i = len - 1;
	while (i > 0)
	{
		d[i] = s[i];
		i--;
	}
	d[i] = s[i];
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = dst;
	s = src;
	if ((d == s) || (len == 0))
		return (dst);
	if (d < s)
	{	
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (d > s)
	{
		ft_rev_move(d, s, len);
	}
	return (dst);
}
