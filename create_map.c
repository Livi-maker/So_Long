/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:24:39 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/25 19:24:41 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(int fd, t_info* info)
{
	char	*line;

	info->map_height = 0;
	line = get_next_line(fd);
	info->map_width = ft_strlen(line);
	info->map = calloc(1, sizeof(char *));
	while (line)
	{
		info->map_height += 1;
		check_line(line, info);
		ft_arrayjoin(info->map, line);
		line = get_next_line(fd);
	}
	last_line(info);
}

void create_map(char *file, t_info *info)
{
	int				fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Couldn't open file\n");
		exit(0);
	}
	get_map(fd, info);
	close(fd);
}
