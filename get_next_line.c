/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colauren <colauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:41:00 by colauren          #+#    #+#             */
/*   Updated: 2026/11/26 17:28:58 by colauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		res = ft_free(res, buffer);
		if (ft_strchar(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*ft_line(char *buffer)
{
}

char	*ft_next(char *buffer)
{
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char *next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (next_line);
}