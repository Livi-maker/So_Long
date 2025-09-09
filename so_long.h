#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"

typedef struct s_info
{
	int				map_height;
	int				map_width;
	char**			map;
	int				collectibles;
	int				player;
	int				exit;
}				t_info;

char**	ft_arrayjoin(char **s1, char *s2);
void	create_map(char *file, t_info *info);
void	last_line(t_info *info);
void	check_line(char *line, t_info *info);
void	invalid_map(t_info *info, char *str);
int		is_valid(char c);
void	print_array(char** array);

#endif
