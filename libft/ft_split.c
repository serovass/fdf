/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:55:41 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/28 15:19:04 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**ft_free_pp(char **pp)
{
	size_t	i;

	i = 0;
	while (pp[i] != NULL)
	{
		free(pp[i]);
		i++;
	}
	free(pp);
	return (NULL);
}

static size_t	ft_get_len(char const *si, char c)
{
	size_t	elemlen;
	size_t	i;

	i = 0;
	elemlen = 0;
	while ((si[i] != c) && (si[i] != '\0'))
	{
		elemlen++;
		i++;
	}
	return (elemlen);
}

static char	*ft_get_elem(char const *si, char c)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = ft_get_len(si, c);
	p = (char *)malloc(sizeof(*p) * (len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		p[i] = si[i];
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_fill_pp(char **pp, char const *s, char c)
{
	size_t	i;
	size_t	ipp;
	char	*p;

	i = 0;
	ipp = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			p = ft_get_elem(&s[i], c);
			if (p == NULL)
				return (ft_free_pp(pp));
			pp[ipp] = p;
			ipp++;
			i = i - 1 + ft_get_len(&s[i], c);
		}
		i++;
	}
	pp[ipp] = NULL;
	return (pp);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	elemnum;
	char	**pp;

	if (s == NULL)
		return (NULL);
	i = 0;
	elemnum = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			elemnum++;
		i++;
	}
	pp = (char **)malloc(sizeof(*pp) * (1 + elemnum));
	if (pp == NULL)
		return (NULL);
	pp = ft_fill_pp(pp, s, c);
	return (pp);
}
