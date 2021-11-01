/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:12:15 by gnaida            #+#    #+#             */
/*   Updated: 2021/10/05 22:34:01 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	float	ft_limit_pi(float angle)
{
	if (angle > 0 && angle >= 6.28)
		return (0);
	else if (angle < 0 && angle <= -6.28)
		return (6.28);
	return (angle);
}

static void	ft_change_color(int key, t_fdf *data)
{
	if (key == 5)
		data->color = 0x00CC00;
	else if (key == 9)
		data->color = 0x660000;
	else if (key == 11)
		data->color = 0x0000FF;
}

static void	ft_translate(int key, t_fdf *data)
{
	if (key == 123)
		data->translate1 -= 5;
	else if (key == 124)
		data->translate1 += 5;
	else if (key == 125)
		data->translate2 += 5;
	else if (key == 126)
		data->translate2 -= 5;
}

static void	ft_rotate(int key, t_fdf *data)
{
	if (key == 87)
	{
		data->angle.iso = 0.5;
		data->angle.alfa = 0.01;
	}
	else if (key == 84 || key == 1)
		data->angle.alfa = ft_limit_pi(data->angle.alfa + 0.1);
	else if (key == 91 || key == 13)
		data->angle.alfa = ft_limit_pi(data->angle.alfa - 0.1);
}

static void	ft_zzoom(int key, t_fdf *data)
{
	if (key == 47 && data->zzoom < 3)
		data->zzoom += 0.10;
	else if (key == 43 && data->zzoom > -3)
		data->zzoom -= 0.1;
}

int	ft_deal_key(int key, t_fdf *data)
{
	if (key == 34)
		data->isometric = -data->isometric;
	else if (key == 47 || key == 43)
		ft_zzoom(key, data);
	else if (key == 24 && data->zoom < 50)
		data->zoom += 1;
	else if (key == 27 && data->zoom > 1)
		data->zoom -= 1;
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_translate(key, data);
	else if (key == 84 || key == 1 || key == 87 || key == 13 || key == 91)
		ft_rotate(key, data);
	else if (key == 5 || key == 9 || key == 11)
		ft_change_color(key, data);
	else if (key == 53)
	{
		ft_clear_map(data);
		exit (0);
	}
	else
		return (0);
	ft_draw_map(data);
	return (0);
}
