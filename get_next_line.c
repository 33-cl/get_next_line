/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:46:39 by maeferre          #+#    #+#             */
/*   Updated: 2023/12/19 23:03:05 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*res;
	char		*temp;
	int			readed;
	
	temp = NULL;
	res = NULL;
	readed = 0;
	
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, buf, BUFFER_SIZE) < 0)
		return (NULL);
	
	// Tant que buf ne contient pas de '\n', on ajoute buf a res puis on met a jour buf
	while (new_line_in_buf(buf) == 0 && buf[0] != '\0')
	{
		res = ft_strjoin(res, buf);
		
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
			return (NULL);
		if (readed == 0)
			break;
	}

	// Quand buf contient '\n', je remplis un temp puis je le join a res
	if (new_line_in_buf(buf) == 1)
	{
		temp = fill_temp(buf);
		res = ft_strjoin(res, temp);
		free(temp);
	}
	
	

	// Reinitialisation du buffer
	shift_buffer(buf);

	return (res);
}

/* 
	Cree et rempli la variable temporaire qui vient s'ajouter au resultat
	ex : |a|a|a|\n|b|b| --> temp |a|a|a| --> res |-----------| |a|a|a|
*/

char	*fill_temp(char *buf)
{
	size_t	len_temp;
	char	*str;
	
	// Count
	if (ft_strlen(buf) == 1 || buf[0] == '\n')
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '\n';
		str[1] = '\0';
		return (str);
	}
	if (buf == NULL)
		return NULL;
	len_temp = 0;
	while (buf[len_temp] != '\0' && buf[len_temp] != '\n')
		len_temp++;
	if (buf[len_temp] == '\n')
		len_temp++;

	// Allocate
	str = malloc(sizeof(char) * (len_temp + 1));
	if (!str)
		return (NULL);

	// Fill
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
	Renvoie un booleen indiquant si il y a un '\n' dans le buffer
	ex : |a|a|a| = 0   |a|\n|a| = 1 
*/

int	new_line_in_buf(char *str)
{
	if (str[0] == '\0')
		return (-1);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

/* 
	Permet de Reinitialiser le buffer a la fin de get_next_line
	ex : |a|a|a|\n|a|a|  -->  |a|a|a|\0|\0|\0|
		 |a|a|a|\n|\n|   -->  |\n|\0|\0|\0|\0|
*/

void	shift_buffer(char *buf)
{
	size_t	length;
	size_t	start;
	size_t	i;

	// Compter la taille de length
	i = 0;
	length = 1;
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
	// Mettre la partie a conserver dans buf
	ft_memmove(buf, buf + start, length);

	// Remplir buf de '\0'
	ft_bzero(buf + length, length);

}
