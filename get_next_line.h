/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:38:07 by maeferre          #+#    #+#             */
/*   Updated: 2023/12/15 01:52:16 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_bzero(void *s, size_t n);
char		*fill_temp(char *buf);
int			new_line_in_buf(char *str);
void		shift_buffer(char *buf);

#endif

