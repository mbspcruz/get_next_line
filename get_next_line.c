/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:05:21 by david             #+#    #+#             */
/*   Updated: 2021/05/14 14:26:09 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
** get_next_line is a function that will store in the paramenter "line" 
** a line that has been read from the fd, this is a sucession of 0 to n
** character that end with '\n', while line should not have stored the '\n'
** It's important to check if the buf is empty, to check if its has 0
** memory allocated except the last buf. Steps, check the presence of '\n'
*/
char    *ft_line_bf_n(char *line)
{
    int i;
    char *tmp;

    if (!line)
        return (0);
    i = 0;
    while(line && line[i] && line[i] != '\n')
        i++;
    if(!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
        return (0);
    i = 0;
    while(line && line[i] && line[i] != '\n')
    {
        tmp[i] = line[i];
        i++;
    }
    tmp[i] = '\0';
    return(tmp);
}

char    *ft_line_af_n(char *line)
{
    int i;
    char *sv;
	int b;
    
    if (!line)
        return (0);
    i = 0;
    b = 0;
    while(line[i] && line[i] != '\n')
        i++;
    if (!(sv = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1))))
        return (0);
    while(line[i])
    {
        i++;
        sv[b] = line[i];
        b++;
    }
    sv[b] = '\0';
    return (sv);
}

// int ft_check_nl(char *line)
// {
//     int i;

//     i = 0;
//     //printf("*line: %s", line);
//     // printf("line[i]: %c", line[i]);
//     while (line && line[i])
//     {
//         if (line[i] == '\n')
//         {
//             return(1);
//         }
//         i++;
//     }
//     return (0);
// }

int get_next_line(int fd, char **line)
{
    static char *save[OP_MX];
    int rd;
    char *buf;
    
    buf = (char *)malloc(sizeof(char) * BUF_SIZE + 1);
    while((rd = read(fd, buf, BUF_SIZE)) > 0)
    {
        buf[rd] = '\0';
        save[fd] = ft_strjoin(save[fd], buf);
        if (ft_strchr(buf, '\n'))
            break;
    }
    free(buf);
    *line = ft_line_bf_n(save[fd]);
    save[fd] = ft_line_af_n(save[fd]);

    if (!*line || rd < 0)
        return (-1);
    else if (rd == 0)
        return (0);
    else
        return (1);
}

// int main(void)
// {
// 	char *line;
// 	int fd;
// 	int fd2;
// 	int	counter;

// 	fd = open("txt.txt", O_RDONLY);
// 	fd2 = open("txt2.txt", O_RDONLY);
// 	while(get_next_line(fd, &line))
// 	{
// 		printf("%s\n\n", line);
// 	}
// 	while(get_next_line(fd2, &line))
// 	{
// 		printf("%s\n\n", line);
// 	}
		
// }

/*int main()
{
    char ola[]="Ola esta tudo supe \n bem?";
    char ola2[]="Ola esta tudo supe \n bem?";
    printf("%s \n", ft_line_bf_n(ola));
    
    printf("%s", ft_line_af_n(ola2));
    return (0);
 } */
/*int main(int argc, char **argv)
{
	int fd, ret, line_count;
	char *line;

	line_count = 1;
	ret = 0;
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf(" \n [ Return: %d ] | A line has been read #%d => %s\n", ret, line_count, line);
			line_count++;
			free(line);
		}
        ret = get_next_line(fd, &line);
		printf(" \n [ Return: %d ] A line has been read #%d: %s\n", ret, line_count++, line);
		printf("\n");
		if (ret == -1)
			printf("-----------\n An error happened\n");
		else if (ret == 0)
		{
			printf("-----------\n EOF has been reached\n");
			free(line);
		}
		close(fd);
	}
}
*/