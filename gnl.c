/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:17:58 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/05/17 10:30:02 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_fill_line(char **save, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while(*save[i] != '\n' && *save[i] != '\0')
		i++;
	if (*save[i] == '\n')
	{
		*line = ft_substr(*save, 0, i);
		*save = ft_strdup(*save + 1);
		return (1);
	}
	else
	{
		*line = ft_strdup(*save);
	}
	return (0);

}

int	get_next_line(int fd, char **line) // return 1 line read, 0 EOF, -1 ERROR
{
	static char		*save[OP_MX];
	char			buf[BUF_SIZE + 1];
	int				rd;
	char			*p_n;
	
	while((rd = read(fd, buf, BUF_SIZE)))
	{
		buf[rd] = '\0';
		if(save[fd] == 0)
			save[fd] = ft_strdup(buf);
		else
		{
			save[fd] = ft_strjoin(save[fd], buf);
			
		}
		if (ft_strchr(save[fd], '\n'))
			break;
		
	}
	return (ft_fill_line(&save[fd], line));	
}


int	main()
{
	char *line;
	int fd;
	fd = open("txt.txt", O_RDONLY);
	//fd2 = open("txt2.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	printf("%s\n\n", line);
	printf("%s\n\n", line);
	printf("%s\n\n", line);
	//while(get_next_line(fd2, &line))
	//{
	//	printf("%s\n\n", line);
	//}
}