/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:43:24 by alamy             #+#    #+#             */
/*   Updated: 2017/12/21 15:34:20 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;

	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	if (fd == -1)
		return (1);

	get_next_line(fd, &line);
	printf("%d %s\n", 1, line);

	get_next_line(fd2, &line);
	printf("%d %s\n", 1, line);

	get_next_line(fd, &line);
	printf("%d %s\n", 2, line);

	get_next_line(fd2, &line);
	printf("%d %s\n", 2, line);

	get_next_line(fd, &line);
	printf("%d %s\n", 3, line);

	get_next_line(fd2, &line);
	printf("%d %s\n", 3, line);

	free(line);

	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%d %s\n", i, line);
		i++;
	}
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}
