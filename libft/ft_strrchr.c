/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:11:36 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/27 22:07:00 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = (char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	if (ch == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
