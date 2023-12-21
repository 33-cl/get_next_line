/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:46:39 by maeferre          #+#    #+#             */
/*   Updated: 2023/12/22 00:30:39 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[4096];
	char		*res;

	res = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (new_line_or_end(buf) == 2)
	{
		res = ft_strjoin(res, buf);
		if (!res || !ft_read(fd, buf, res))
			return (NULL);
	}
	if (buf[0] == '\0' && !ft_read(fd, buf, res))
		return (NULL);
	while (new_line_or_end(buf) == 0 && buf[0] != '\0')
	{
		res = ft_strjoin(res, buf);
		if (!res || !ft_read(fd, buf, res))
			return (NULL);
	}
	if (new_line_or_end(buf) == 1 || new_line_or_end(buf) == 2)
		res = ft_strjoin(res, buf);
	shift_buffer(buf);
	return (res);
}

/*
	Reads the file and handles potential errors of the function
	Returns 0 in case of error
	Returns 1 in the other case
*/

int	ft_read(int fd, char *buf, char *res)
{
	int	readed;

	readed = read(fd, buf, BUFFER_SIZE);
	if (readed < 0)
	{
		ft_bzero(buf, BUFFER_SIZE);
		free(res);
		return (0);
	}
	buf[readed] = '\0';
	return (1);
}

/* 
	Creates and fills the temporary variable that adds into res
	ex : |a|a|a|\n|b|b| --> temp |a|a|a| --> res |-----------| |a|a|a|
*/

char	*fill_temp(char *buf)
{
	size_t	len_temp;
	char	*str;

	len_temp = 0;
	while (buf[len_temp] != '\0' && buf[len_temp] != '\n')
		len_temp++;
	if (buf[len_temp] == '\n')
		len_temp++;
	str = malloc(sizeof(char) * (len_temp + 1));
	if (!str)
		return (NULL);
	len_temp = 0;
	while (buf[len_temp] != '\0' && buf[len_temp] != '\n')
	{
		str[len_temp] = buf[len_temp];
		len_temp++;
	}
	if (buf[len_temp] == '\n')
	{
		str[len_temp] = buf[len_temp];
		len_temp++;
	}
	str[len_temp] = '\0';
	return (str);
}

/* 
	Returns an int indicating if there is a '\n' or '\0' in the buffer
	ex : |a|a|a| = 0   |a|\n|a| = 1   |a||\0||\0| = 2
*/

int	new_line_or_end(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	if (i < BUFFER_SIZE)
		return (2);
	return (0);
}

/* 
	Reinitializes buf at the end of get_next_line()
	ex : |a|a|a|\n|a|a|  -->  |a|a|a|\0|\0|\0|
		 |a|a|a|\n|\n|   -->  |\n|\0|\0|\0|\0|
*/

void	shift_buffer(char *buf)
{
	size_t	length;
	size_t	start;
	size_t	i;

	i = 0;
	length = 1;
	if (buf[0] == '\0')
		return ;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	start = i;
	while (buf[i])
	{
		length++;
		i++;
	}
	ft_memmove(buf, buf + start, length);
}
