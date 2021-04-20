/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:47:11 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/04/20 17:28:24 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*test(char *str)
{
	static char *save;
	char *buf;
	size_t len;
	size_t res;
	
	len = ft_strlen(save) + ft_strlen(str);
	if(!(buf = (char *)malloc(sizeof(char) * (len + 1))))
		return 0;
	res = ft_strlcpy(buf, save, len + 1);
	ft_strlcpy(buf + res, str, len + 1);
	free(save);
	save = buf;
	return (save);
}

int main(void)
{
	printf("%s\n", test("Olá"));
	printf("%s\n", test("esta tudo"));
	printf("%s\n", test("bem "));
	printf("%s\n", test("contigo?"));
	return 0;
}