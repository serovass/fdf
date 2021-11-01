/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 22:10:13 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/28 14:39:05 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_first_len(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	fn;

	if (set == NULL)
		return (0);
	fn = 0;
	i = 0;
	j = 0;
	while (set[i] != '\0')
	{
		if (s1[j] == set[i])
		{
			fn++;
			j++;
			i = -1;
		}
		i++;
	}
	return (fn);
}

static int	ft_last_len(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	ln;

	if (set == NULL)
		return (0);
	j = ft_strlen(s1);
	ln = 0;
	i = 0;
	j = j - 1;
	while (set[i] != '\0')
	{
		if (s1[j] == set[i])
		{
			ln++;
			j--;
			i = -1;
		}
		i++;
	}
	return (ln);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		j;
	int		len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) - ft_first_len(s1, set) - ft_last_len(s1, set);
	if (len < 0)
		len = 0;
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	j = ft_first_len(s1, set);
	while (len > 0)
	{
		s2[i] = s1[j];
		len--;
		i++;
		j++;
	}
	s2[i] = '\0';
	return (s2);
}
