/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:34:09 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/03 23:47:28 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	char	*convert_s;

	convert_s = (char *)s;
	while (*convert_s != c)
	{
		if (*convert_s == '\0')
			return (NULL);
		convert_s++;
	}
	return (convert_s);
}

static char	*read_file(int fd, char *buf_line)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == READ_ERROR)
			return (NULL);
		buffer[bytes_read] = '\0';
		buf_line = ft_strjoin_free(buf_line, buffer);
	}
	return (buf_line);
}

static char	*return_line(char *buf_line)
{
	char	*ret;
	char	*nl_position;
	size_t	len;

	ret = NULL;
	if (!*buf_line)
		return (NULL);
	nl_position = ft_strchr(buf_line, '\n');
	if (!nl_position)
		ret = ft_strjoin_free(ret, buf_line);
	else
	{
		len = nl_position - buf_line + 1;
		ret = ft_substr(buf_line, 0, len);
	}
	return (ret);
}

static char	*save_line(char *buf_line)
{
	char	*line;
	char	*nl_position;

	line = NULL;
	nl_position = ft_strchr(buf_line, '\n');
	if (nl_position)
		line = ft_strdup(nl_position + 1);
	free(buf_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf_line[256];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	buf_line[fd] = read_file(fd, buf_line[fd]);
	if (!buf_line[fd])
		return (NULL);
	line = return_line(buf_line[fd]);
	buf_line[fd] = save_line(buf_line[fd]);
	return (line);
}
