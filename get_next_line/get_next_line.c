/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:43:10 by lfabbian          #+#    #+#             */
/*   Updated: 2022/11/16 14:12:15 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line()
{
	int fd;
	int	bytes_read;
	char	buffer[BUFFER_SIZE];

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = 0;

	return (buffer);
}

int main()
{
	printf("%s\n", get_next_line());
	printf("%s\n", get_next_line());
}