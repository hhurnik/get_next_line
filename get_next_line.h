/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:44:38 by hhurnik           #+#    #+#             */
/*   Updated: 2024/07/04 19:50:02 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *start, char *buff);
char	*ft_join(char *dest, char *s1, char *s2);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);
char	*ft_line(char *src);
char	*ft_after_nl(char *string);

#endif