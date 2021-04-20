/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:34:08 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/04/20 18:11:10 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static int *saved;
	int rd;
	char *buf;

	if(!(buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return 0;
}

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