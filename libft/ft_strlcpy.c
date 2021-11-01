/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:09:01 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/27 19:18:25 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		if (dstsize > 0)
		{
			dst[i] = src[i];
			dstsize--;
			if (dstsize == 0)
				dst[i] = '\0';
		}
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (i);
}
