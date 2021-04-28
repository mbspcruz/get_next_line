/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:34:08 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/04/28 18:48:36 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_line(char **str, char **line)
{
	int i;
	char *tmp;

	i = 0;
	/* run until find \n */
	while(*str[i] != '\n' && *str[i])
		i++;
	/* save the str to the line and store the rest of the data after the newline in the tmp var
	** if the line didnt have a break duplicate 
	*/
	if(*str[i] == '\n')
	{
		*line = ft_substr(*str, 0, i);
		tmp = ft_strdup(*str + i + 1);
		free(*str);
		*str = tmp;
	}
	else if (*str == '\0')
	{
		*line = ft_strdup(*str);
		free(*str);
		str = 0;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char *saved ;
	int rd;
	char *buf;

	if(!(buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (-1);
	while((rd = read(fd, buf, BUF_SIZE)) > 0)
	{
		
	}
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