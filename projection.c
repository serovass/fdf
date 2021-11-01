/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:00:20 by gnaida            #+#    #+#             */
/*   Updated: 2021/10/08 22:07:40 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_isometric(float *x, float *y, float *z, t_fdf *data)
{
	float	pre_y;

	pre_y = *y;
	*y = (*x + pre_y) * sin(data->angle.iso) - (*z);
	*x = (*x - pre_y) * cos(data->angle.iso);
}

void	ft_get_projection(float *x, float *y, float *z, t_fdf *data)
{
	float	pre_y;

	pre_y = *y;
	*y = pre_y * cos(data->angle.alfa) + (*z) * sin(data->angle.alfa);
	*z = -pre_y * sin(data->angle.alfa) + (*z) * cos(data->angle.alfa);
	if (data->isometric > 0)
		ft_get_isometric(x, y, z, data);
	*x += data->translate1;
	*y += data->translate2;
}
