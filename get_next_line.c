/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:34:08 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/04/27 16:18:14 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_line(char **str, char **line)
{
	int i;
	char *tmp;

	i = 0;
	while(*str[i] != '\n')
		i++;
	if(*str[i] == '\n' || *str[i] == '\0')
	{
		
	}
}

int	get_next_line(int fd, char **line)
{
	static char *saved ;
	int rd;
	char *buf;

	if(!(buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return 0;
	while((rd = read(fd, buf, BUF_SIZE)) > 0)
	{
		
	}
	return (saved[fd]);
}
