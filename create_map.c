/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:24:39 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/09/09 07:35:09 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(int fd, t_info* info)
{
	char	*line;

	info->map = calloc(1, sizeof(char *));
	line = get_next_line(fd);
	if (!line)
		invalid_map(info, "No map found: ");
	info->map_width = ft_strlen(line);
	while (line)
	{
		info->map_height += 1;
		check_line(line, info);
		info->map = ft_arrayjoin(info->map, line);
		line = get_next_line(fd);
	}
	last_line(info);
	if (info->player != 1 || info->exit != 1)
		invalid_map(info, "Missing player or exit: ");
}

void	flood_fill(int x, int y, char **map, t_info *info)
{
	if (x < 0 || x == info->map_width - 1 || y < 0 || y == info->map_height - 1 || map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
		info->exit -= 1;
		return ;
	}
	else if (map[y][x] == 'P')
	{
		map[y][x] = 'F';
		info->player -= 1;
	}
	else if (map[y][x] == 'C')
	{
		map[y][x] = 'F';
		info->collectibles -= 1;
	}
	map[y][x] = 'F';
	flood_fill(x + 1, y, map, info);
	flood_fill(x - 1, y, map, info);
	flood_fill(x, y + 1, map, info);
	flood_fill(x, y - 1, map, info);
}

void    find_player(t_info *info)
{
	char **map;
	int x;
	int y;

	map = info->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				flood_fill(x, y, info->map, info);
				return ;
			}
			x++;
		}
		y++;
	}
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
	find_player(info);
	if (info->collectibles != 0 || info->exit != 0 || info->player != 0)
		invalid_map(info, "Map not accesible: ");
}
