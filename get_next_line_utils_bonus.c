/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:37:12 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/03 23:47:12 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dstsize != 0)
	{
		while (*src && dstsize-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_size);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*rtn;
	size_t	size;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len + 1;
	rtn = (char *)malloc(sizeof(char) * size);
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, s1, s1_len + 1);
	ft_strlcpy(rtn + s1_len, s2, s2_len + 1);
	free(s1);
	return (rtn);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	string_size;

	string_size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * string_size);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, string_size);
	return (s2);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*ptr;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	if (start + len > str_len)
		len = str_len - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	ptr = substring;
	s += start;
	while (*s && len-- > 0)
		*ptr++ = *s++;
	*ptr = '\0';
	return (substring);
}
