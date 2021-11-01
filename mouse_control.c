/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:34:28 by gnaida            #+#    #+#             */
/*   Updated: 2021/10/05 22:35:45 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_deal_mouse(int mouse, int width, int height, t_fdf *data)
{
	(void)width;
	(void)height;
	if (mouse == 1 && data->zzoom < 3)
		data->zzoom += 0.10;
	else if (mouse == 2 && data->zzoom > -3)
		data->zzoom -= 0.1;
	else if (mouse == 5 && (data->zoom < 30 || (data->zoom < 100 \
	&& data->height < 200)))
		data->zoom += 1;
	else if (mouse == 4 && data->zoom > 1)
		data->zoom -= 1;
	else
		return (0);
	ft_draw_map(data);
	return (0);
}
