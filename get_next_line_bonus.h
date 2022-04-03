/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:34:48 by iugolin           #+#    #+#             */
/*   Updated: 2022/04/03 23:46:38 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# ifndef READ_ERROR
#  define READ_ERROR -1
# endif

size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

#endif
