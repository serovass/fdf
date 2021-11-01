/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:13:01 by gnaida            #+#    #+#             */
/*   Updated: 2021/05/13 22:39:10 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 510

typedef struct s_lst
{
	char			*str;
	char			status;
	int				len;
	int				fd;
	struct s_lst	*next;
}					t_lst;

int		get_next_line(int fd, char **line);
char	*ft_get_line(t_lst *list, int fd, int len, int *reply);
int		ft_get_line_len(t_lst *list, int fd);
void	ft_str_copy(char *s, char *d);
t_lst	*ft_lst_clear(t_lst *list, int fd, int st);
char	*ft_str_add(char *buffi, int len);
t_lst	*ft_l_new(char *buffi, int fd, int len, char status);
int		ft_l_add(t_lst **list, t_lst *newone);
int		ft_buff_split(int fdr, int fd, char *buff, t_lst **list);
int		ft_fd_read(t_lst **list, int fd);

#endif
