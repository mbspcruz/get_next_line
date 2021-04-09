/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:34:08 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/04/01 17:12:56 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUF_SIZE 999999
int	main()
{
	int fd;
	int res;
	char buf[BUF_SIZE + 1];
	

	fd = open("txt.txt", O_RDONLY);
	ft_putnbr(fd);
	ft_putchar('\n');
	res = read(fd, buf, BUF_SIZE);
	ft_putstr(buf);
	ft_putchar('\n');
	ft_putnbr(res);
	return (0);
}