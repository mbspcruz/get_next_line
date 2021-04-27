/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:34:08 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/04/27 00:51:55 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *saved ;
	int rd;
	char *buf;

	if(!(buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return 0;
	while((rd = read(fd, buf, BUF_SIZE)) > 0)
	{
		if(saved[fd] == '\n')
		{
			saved = buf;

		}
		
		ft_strjoin(&saved[fd], buf);
		
		
	}
	return (saved[fd]);
}
