#include "so_long.h"

void	invalid_map(t_info *info, char *str)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		free(info->map[i]);
		i++;
	}
	free (info->map);
	free (info);
	write(2, str, ft_strlen(str));
	write(2, "Invalid\n", 9);
	exit(1);
}

int	is_valid(char c)
{
	char	*valid;

	valid = "10CPE";
	while (*valid)
	{
		if (*valid == c)
			return (1);
		valid++;
	}
	return (0);
}

void	check_line(char *line, t_info *info)
{
	if ((int)ft_strlen(line) != info->map_width)
			invalid_map(info, "Map not rectangular: ");
	if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
		invalid_map(info, "Map not closed: ");
	while (*line)
	{
		if (info->map_height == 1)
		{
			if (*line != '1' && *line != 10)
				invalid_map(info, "Map not closed: ");
		}
		else
		{
			if (is_valid(*line) == 0 && *line != 10)
				invalid_map(info, "Wrong character: ");
		}
		line++;
	}
}

void	last_line(t_info *info)
{
	int	i;
	char	*last_line;

	i = 0;
	while (info->map[i])
		i++;
	last_line = info->map[i - 1];
	while (*last_line)
	{
		if (*last_line != '1' && *last_line != 10)
			invalid_map(info, "Map not closed: ");
		last_line++;
	}
}