/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:38:31 by gnaida            #+#    #+#             */
/*   Updated: 2021/10/01 17:18:12 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_init(t_fdf *data)
{
	data->zoom = 600 / data->width;
	if ((int)data->zoom < 1)
		data->zoom = 1;
	data->zzoom = 1;
	data->angle.iso = 0.5;
	data->angle.alfa = 0;
	data->isometric = 1;
	data->parallel = -1;
	data->translate1 = 500;
	data->translate2 = 350;
	data->color = 0x00CC00;
}

int	main(int argc, char **argv)
{
	t_fdf	data;
	t_img	img;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n", 0);
		exit (0);
	}
	data.width = 0;
	data.height = 0;
	data.z = NULL;
	data.img = &img;
	ft_read_mapfile(argv[1], &data);
	ft_fdf_init(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1300, 800, "42");
	data.img->img = mlx_new_image(data.mlx_ptr, 1300, 800);
	img.addr = mlx_get_data_addr(data.img->img, &data.img->bits_per_pixel, \
	&data.img->line_length, &data.img->endian);
	ft_draw_map(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, ft_deal_key, &data);
	mlx_mouse_hook(data.win_ptr, ft_deal_mouse, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
