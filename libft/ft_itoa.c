/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:46:16 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/27 15:04:07 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_get_str(long int longn, long int length, long int rank)
{
	long int	i;
	char		*str;

	str = (char *)malloc(sizeof(*str) * (length + 1));
	if (str == NULL)
		return (NULL);
	if (longn < 0)
	{
		longn = -1 * longn;
		str[0] = '-';
		i = 1;
	}
	else
		i = 0;
	while (i < length)
	{
		str[i] = longn / rank + '0';
		longn = longn - rank * (longn / rank);
		rank = rank / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	longn;
	long int	rank;
	long int	length;

	longn = n;
	if (longn < 0)
	{
		longn = -1 * longn;
		length = 2;
	}
	else
		length = 1;
	rank = 1;
	while (longn >= 10)
	{
		longn = longn / 10;
		rank = rank * 10;
		length++;
	}
	longn = n;
	str = ft_get_str(longn, length, rank);
	return (str);
}
