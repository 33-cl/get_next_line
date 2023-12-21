/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:18:32 by maeferre          #+#    #+#             */
/*   Updated: 2023/12/21 20:33:51 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*fill(char *str, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);

	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < len_s2)
	{
		str[i + j] = s2[j];
		j++;
	}
		
	str[i + j] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		len_total;
	char		*str;

	if (!s1 && !s2)
		return (NULL);
	/*if (s1 && !s2)
	{
		str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
		if (!str)
		{
			free(s1);
			return (NULL);
		}
		str = ft_strcpy(str, s1);
		free(s1);
		return (str);
	}
	if (s2 && !s1)
	{
		str = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		if (!str)
		{
			return (NULL);
		}
		str = ft_strcpy(str, s2);
		return (str);
	}*/
	len_total = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len_total + 1));
	if (!str)
		return (NULL);
	str = fill(str, s1, s2);
	free(s1);
	return (str);
}



void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*char_dest;
	const unsigned char	*char_src;

	i = 0;
	char_dest = dest;
	char_src = src;
	if (!dest && !src)
		return (NULL);
	if (char_dest > char_src)
	{
		while (n > 0)
		{
			char_dest[n - 1] = char_src[n - 1];
			n--;
		}
	}
	while (i < n && char_dest <= char_src)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
