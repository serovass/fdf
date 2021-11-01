/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:47:14 by gnaida            #+#    #+#             */
/*   Updated: 2021/10/08 21:34:01 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear_map(t_fdf *data)
{
	int	i;

	if (data->z == NULL)
		return ;
	i = 0;
	while (data->z[i] != NULL)
	{
		free(data->z[i]);
		i++;
	}
	free(data->z);
}