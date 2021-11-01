/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 23:30:37 by gnaida            #+#    #+#             */
/*   Updated: 2021/09/10 16:39:29 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((ss1[i] != '\0') && (ss2[i] != '\0') \
			&& (ss1[i] == ss2[i]) && (n > 0))
	{
		n--;
		if (n == 0)
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (ss1[i] - ss2[i]);
}
