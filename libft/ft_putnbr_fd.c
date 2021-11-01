/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:29:53 by gnaida            #+#    #+#             */
/*   Updated: 2021/04/28 17:45:24 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static long int	ft_if_min(int n, int fd)
{
	long int	longn;

	longn = n;
	if (longn < 0)
	{
		write(fd, "-", 1);
		return (-1 * longn);
	}
	return (longn);
}

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long int	longn;
	long int	rank;

	longn = ft_if_min(n, fd);
	rank = 1;
	while (longn >= 10)
	{
		longn = longn / 10;
		rank = rank * 10;
	}
	longn = n;
	if (longn < 0)
		longn = -1 * longn;
	while (rank >= 10)
	{
		c = longn / rank + '0';
		write(fd, &c, 1);
		longn = longn - rank * (longn / rank);
		rank = rank / 10;
	}
	c = longn + '0';
	write(fd, &c, 1);
}
