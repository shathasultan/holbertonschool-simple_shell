#include "main.h"

/**
 * _getline - Read a line from stdin using a static buffer
 *
 * Return: Pointer to a malloc'd string (without newline), or NULL on EOF/error
 */
char *_getline(void)
{
	static char buf[1024];
	static size_t pos;
	static size_t len;
	char *line = NULL;
	size_t line_len = 0;
	ssize_t r;
	char c;

	while (1)
	{
		if (pos >= len)
		{
			r = read(STDIN_FILENO, buf, sizeof(buf));
			if (r <= 0)
			{
				/* EOF or error: return any collected data or NULL */
				if (line_len == 0)
				{
					free(line);
					return (NULL);
				}
				line = realloc(line, line_len + 1);
				if (line == NULL)
					return (NULL);
				line[line_len] = '\0';
				return (line);
			}
			len = (size_t)r;
			pos = 0;
		}

		c = buf[pos++];
		if (c == '\n')
		{
			line = realloc(line, line_len + 1);
			if (line == NULL)
				return (NULL);
			line[line_len] = '\0';
			return (line);
		}

		line = realloc(line, line_len + 1);
		if (line == NULL)
			return (NULL);
		line[line_len++] = c;
	}
}
