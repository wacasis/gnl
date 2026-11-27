/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colauren <colauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:41:00 by colauren          #+#    #+#             */
/*   Updated: 2026/11/27 15:49:55 by colauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(str, buf);
	free(str);
	return (tmp);
}

char	*read_fd(int fd, char *r)
{
	char	*buffer;
	int		byte_count;

	if (!r)
		r = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_count = 1;
	while (byte_count > 0)
	{
		byte_count = read(fd, buffer, BUFFER_SIZE);
		if (byte_count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_count] = 0;
		r = ft_free(r, buffer);
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (r);
}

char	*ft_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, (sizeof(char)));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str)
	{
		free(str);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(str) - i - 1), sizeof(char));
	i++;
	while (str[i])
		line[j++] = str[i++];
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (next_line);
}

int	main(void)
{
	int fd = open("fil.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}