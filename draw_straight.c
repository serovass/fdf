/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:48:00 by gnaida            #+#    #+#             */
/*   Updated: 2021/10/05 21:55:13 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_zoom(t_line *line, t_fdf *data)
{
	line->x *= data->zoom;
	line->y *= data->zoom;
	line->x1 *= data->zoom;
	line->y1 *= data->zoom;
	line->z1 *= data->zzoom * data->zoom;
	line->z *= data->zzoom * data->zoom;
}

static void	ft_get_steps(t_line *line)
{
	float	max;

	line->xstep = line->x1 - line->x;
	line->ystep = line->y1 - line->y;
	if (fabs(line->xstep) > fabs(line->ystep))
		max = fabs(line->xstep);
	else
		max = fabs(line->ystep);
	line->xstep /= max;
	line->ystep /= max;
}

static void	ft_put_line(t_line *line, t_fdf *data, int c)
{
	while ((int)(line->x - line->x1) || (int)(line->y - line->y1))
	{
		if (line->pre_z > 0 && line->pre_z1 == 0)
		{
			my_mlx_pixel_put(data, (int)line->x, (int)line->y, data->color + c);
			if (c >= 5 && (int)fabs((line->y - line->y1) / line->ystep) < 51)
				c -= 5;
		}	
		else if (line->pre_z == 0 && line->pre_z1 > 0)
		{
			my_mlx_pixel_put(data, (int)line->x, (int)line->y, data->color + c);
			if (c <= 245)
				c += 5;
		}
		else if (line->pre_z != 0 || line->pre_z1 != 0)
			my_mlx_pixel_put(data, (int)line->x, (int)line->y, \
			data->color + 255);
		else
			my_mlx_pixel_put(data, (int)line->x, (int)line->y, data->color);
		line->x += line->xstep;
		line->y += line->ystep;
	}
}

void	ft_draw_line(t_line line, t_fdf *data)
{
	int	c;

	line.z = data->z[(int)line.y][(int)line.x];
	line.z1 = data->z[(int)line.y1][(int)line.x1];
	line.pre_z = line.z;
	line.pre_z1 = line.z1;
	ft_get_zoom(&line, data);
	ft_get_projection(&line.x, &line.y, &line.z, data);
	ft_get_projection(&line.x1, &line.y1, &line.z1, data);
	ft_get_steps(&line);
	if (line.pre_z > 0 && line.pre_z1 == 0)
		c = 250;
	else
		c = 0;
	ft_put_line(&line, data, c);
}
