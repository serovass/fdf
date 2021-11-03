/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:14:20 by gnaida            #+#    #+#             */
/*   Updated: 2021/10/08 21:43:37 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (y > 799 || x > 1299 || y < 2 || x < 2)
		return ;
	dst = data->img->addr + (y * data->img->line_length + x \
	* (data->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static t_line	ft_get_coordinates(float x, float y, float x1, float y1)
{
	t_line	line;

	line.x = x;
	line.y = y;
	line.x1 = x1;
	line.y1 = y1;
	return (line);
}

static void	ft_get_backgrund(t_fdf *data)
{
	int		x;
	int		y;
	float	color;

	y = 0;
	color = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 1300)
		{
			my_mlx_pixel_put(data, x, y, (int)color);
			x++;
		}
		color += 0.1;
		y++;
	}
}

void	ft_draw_map(t_fdf *data)
{
	float	x;
	float	y;

	ft_get_backgrund(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < (data->width - 1))
				ft_draw_line(ft_get_coordinates(x, y, x + 1, y), data);
			if (y < (data->height - 1))
				ft_draw_line(ft_get_coordinates(x, y, x, y + 1), data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img, 0, 0);
}
