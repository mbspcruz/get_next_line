/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:05:21 by david             #+#    #+#             */
/*   Updated: 2021/05/18 20:54:21 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line_before_n(char *line)
{
	int		i;
	char	*tmp;

	if (!line)
		return (0);
	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (line && line[i] && line[i] != '\n')
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_line_after_n(char *line)
{
	char	*sv;
	int		i;
	int		b;

	if (!line)
		return (0);
	i = 0;
	b = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (0);
	}
	sv = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!sv)
		return (0);
	i++;
	while (line[i])
		sv[b++] = line[i++];
	sv[b] = '\0';
	free(line);
	return (sv);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[OP_MX];
	int			rd;
	char		buf[BUF_SIZE + 1];
	char		*tmp;

	if (!line || BUF_SIZE < 1 || read(fd, 0, 0) == -1)
		return (-1);
	rd = 1;
	if (save[fd] == 0)
		save[fd] = ft_strdup("");
	while (!ft_strchr(save[fd], '\n') && rd)
	{
		rd = read(fd, buf, BUF_SIZE);
		if (rd == -1)
			return (-1);
		buf[rd] = '\0';
		tmp = ft_strjoin(save[fd], buf);
		free(save[fd]);
		save[fd] = tmp;
	}
	*line = ft_line_before_n(save[fd]);
	save[fd] = ft_line_after_n(save[fd]);
	return (rd > 0);
}
