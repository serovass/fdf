/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mapfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:43:50 by gnaida            #+#    #+#             */
/*   Updated: 2021/10/05 22:37:51 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_error(t_fdf *data, char *mes)
{
	if (data != NULL)
		ft_clear_map(data);
	ft_putstr_fd(mes, 0);
	exit (0);
}

static int	ft_count_width(char *line)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != ' ')
		{
			width++;
			while (line[i] != ' ' && line[i] != '\0' && line[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return (width);
}

static void	ft_get_hight_and_width(char *filename, t_fdf *data)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		ft_error(NULL, "No data found!\n");
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		width = ft_count_width(line);
		if (data->width == 0)
			data->width = width;
		else if (data->width != width)
			ft_error(NULL, "Found wrong line length!\n");
		data->height++;
		free(line);
	}
	close(fd);
	if (data->width == 0 || data->height == 0)
		ft_error(NULL, "No data found!\n");
}

static void	ft_fill_z_array(char *line, int *zi, int width)
{
	char	**zstr;
	int		i;

	zstr = ft_split(line, ' ');
	if (zstr == NULL)
		ft_error(NULL, "Memory error!\n");
	i = 0;
	while (zstr[i] && width)
	{
		zi[i] = ft_atoi(zstr[i]);
		free(zstr[i]);
		i++;
		width--;
	}
	free(zstr);
}

void	ft_read_mapfile(char *filename, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	ft_get_hight_and_width(filename, data);
	data->z = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (data->z == NULL)
		ft_error(NULL, "Memory error!\n");
	data->z[0] = NULL;
	i = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		ft_error(NULL, "No data found!\n");
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		data->z[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		ft_bzero(data->z[i], data->width);
		if (data->z[i] == NULL)
			ft_error(data, "Memory error!\n");
		ft_fill_z_array(line, data->z[i], data->width);
		free(line);
		i++;
	}
	close(fd);
	data->z[i] = NULL;
}
