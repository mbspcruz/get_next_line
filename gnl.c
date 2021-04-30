/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:05:21 by david             #+#    #+#             */
/*   Updated: 2021/04/30 02:00:28 by mda-cruz         ###   ########.fr       */
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
char    *ft_line_bf_n(char *str)
{
    int i;
    char *line;

    i = 0;
    if(!(line = malloc(sizeof(char) * i + 1)))
        return (0);
    while(str[i] != '\n' && str[i])
    {
        line[i] = str[i];
        i++;
    }
        
    return(line);
}

char    *ft_line_af_n(char *str)
{
    
}

int main()
{
    char ola[]="Ola esta tudo supe \n bem?";
    printf("%s", ft_line_af_n(ola));
    return (0);
}