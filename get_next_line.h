/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colauren <colauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 11:33:28 by colauren          #+#    #+#             */
/*   Updated: 2026/11/27 13:58:29 by colauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_calloc(size_t nmemb, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strrchr(const char *s, int c);
char				*ft_free(char *str, char *buf);
char				*read_fd(int fd, char *r);
char				*ft_line(char *buffer);
char				*ft_next(char *buffer);
char				*get_next_line(int fd);
void				ft_bzero(void *s, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

#endif