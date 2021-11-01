/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:02:11 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/23 17:03:12 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*ptrc;
	size_t			i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ptrc = (unsigned char *)ptr;
	i = 0;
	while (i < (count * size))
	{
		ptrc[i] = 0;
		i++;
	}
	return (ptr);
}
