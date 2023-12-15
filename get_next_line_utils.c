/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeferre <maeferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:18:32 by maeferre          #+#    #+#             */
/*   Updated: 2023/12/15 02:31:23 by maeferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*fill(char *str, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;

	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2) && s2[j - 1] != '\n')
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

	if (!s1 || !s2)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len_total + 1));
	if (!str)
		return (NULL);
	fill(str, s1, s2);
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

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = s;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
	return (s);
}
