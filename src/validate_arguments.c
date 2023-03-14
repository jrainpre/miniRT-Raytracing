#include "miniRT.h"

int	arguments_valid(int argc, char **argv)
{
	char	*file_ext_pos;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./miniRT <scenefile.rt>\n", STDERR_FILENO);
		return (0);
	}
	file_ext_pos = ft_strnstr(argv[1], ".rt", ft_strlen(argv[1]));
	if (file_ext_pos == NULL || ft_strlen(file_ext_pos) != 3)
	{
		ft_putstr_fd("Error\nFile doesn't end with .rt\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}
