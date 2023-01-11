
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	line_size;

	if (fd < 0)
	{
		return (NULL);
	}
	char c, *line = NULL;
	line_size = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (line_size % BUFFER_SIZE == 0)
		{
			line = realloc(line, (line_size + BUFFER_SIZE) * sizeof(char));
		}
		line[line_size++] = c;
		if (c == '\n')
		{
			break ;
		}
	}
	if (line_size == 0)
	{
		free(line);
		return (NULL);
	}
	line[line_size] = '\0';
	return (line);
}
