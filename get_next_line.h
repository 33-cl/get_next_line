/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:38:07 by maeferre          #+#    #+#             */
/*   Updated: 2023/12/21 20:00:09 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 9
#endif

char 		*ft_strcpy(char *dest, char *src);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);
char		*fill_temp(char *buf);
int			new_line_or_end(char *str);
void		shift_buffer(char *buf);
char		*fill_temp_end(char *buf);

#endif

