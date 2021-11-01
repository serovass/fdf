/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:13:04 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/22 16:14:44 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	dstlen;
	size_t	id;
	size_t	is;

	dstlen = ft_len(dst);
	if (dstsize <= dstlen)
	{
		len = dstsize + ft_len(src);
		return (len);
	}
	len = dstlen + ft_len(src);
	dstsize = dstsize - ft_len(dst) - 1;
	id = dstlen;
	is = 0;
	while ((src[is] != '\0') && (dstsize > 0))
	{
		dst[id] = src[is];
		dstsize--;
		id++;
		is++;
	}
	dst[id] = '\0';
	return (len);
}
