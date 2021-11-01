/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:24:32 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/28 15:23:55 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_js_len(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	return (i + j);
}

static char	*ft_js_fill(const char *s1, const char *s2, char *js)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		js[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		js[j] = s2[i];
		i++;
		j++;
	}
	js[j] = '\0';
	return (js);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*js;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	js = (char *)malloc(sizeof(*js) * (ft_js_len(s1, s2) + 1));
	if (js == NULL)
		return (NULL);
	js = ft_js_fill(s1, s2, js);
	return (js);
}
