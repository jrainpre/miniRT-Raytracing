#include "miniRT.h"

char	**read_file(char *file)
{
	int		fd;
	char	**scene_arr;
	char	*line;
	int		lines;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	lines = 0;
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			lines++;
	}
	if (close(fd) == -1)
	{
		perror("close");
		exit(1);
	}
	scene_arr = malloc_or_print_error((lines + 1) * sizeof (char *));
	if (scene_arr == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	i = 0;
	while (i < lines)
	{
		scene_arr[i] = get_next_line(fd);
		i++;
	}
	scene_arr[i] = NULL;
	if (close(fd) == -1)
	{
		perror("close");
		exit(1);
	}
	return (scene_arr);
}
