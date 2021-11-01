/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 21:46:14 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/22 21:47:57 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_equal(const char *hay, const char *need, size_t len)
{
	size_t	ii;
	size_t	ll;

	ii = 0;
	ll = len;
	while ((hay[ii]) == need[ii] && (ll != 0))
	{
		ii++;
		ll--;
		if (need[ii] == '\0')
			return (1);
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	equal;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((len != 0) && (haystack[i] != '\0'))
	{
		equal = ft_equal(&haystack[i], needle, len);
		if (equal == 1)
			return ((char *)&haystack[i]);
		i++;
		len--;
	}
	return (NULL);
}
