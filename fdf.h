/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:24:38 by gnaida            #+#    #+#             */
/*   Updated: 2021/10/05 21:55:54 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "./minilibx_macos/mlx.h"
# include <math.h> 
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

typedef struct s_ang
{
	float	iso;
	float	alfa;
}	t_ang;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z;
	float	zoom;
	float	zzoom;
	int		translate1;
	int		translate2;
	int		isometric;
	int		parallel;
	int		color;
	t_ang	angle;
	t_img	*img;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

typedef struct s_line
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	z;
	float	z1;
	float	pre_z;
	float	pre_z1;
	float	xstep;
	float	ystep;
}	t_line;

void	ft_read_mapfile(char *filename, t_fdf *data);
void	ft_clear_map(t_fdf *data);
void	ft_draw_line(t_line line, t_fdf *data);
void	ft_get_projection(float *x, float *y, float *z, t_fdf *data);
void	ft_draw_map(t_fdf *data);
int		ft_deal_key(int key, t_fdf *data);
int		ft_deal_mouse(int mouse, int width, int height, t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
#endif
