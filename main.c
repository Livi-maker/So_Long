#include "so_long.h"

int	main(int ac, char** av)
{
	static t_info* info;

	if (ac < 2)
	{
		write(2, "No map provided\n", 16);
		return (1);
	}
	if (ft_strnstr(av[1], ".ber\0", ft_strlen(av[1])) == 0)
	{
		write(2, "Wrong format\n", 13);
		return (1);
	}
	info = malloc (sizeof(t_info));
	create_map(av[1], info);
}