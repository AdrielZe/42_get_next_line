/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:54:42 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/01 18:36:48 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(char const *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char const *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*concat_string;
	int		size_to_alloc;
	int		i;
	int		j;

	size_to_alloc = (ft_strlen(str1) + ft_strlen(str2));
	i = 0;
	j = 0;
	concat_string = (char *)malloc ((size_to_alloc + 1) * sizeof(char));
	if (!concat_string)
		return (NULL);
	while (str1[i])
	{
		concat_string[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		concat_string[i] = str2[j];
		i++;
		j++;
	}
	concat_string[i] = '\0';
	return (concat_string);
}

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(char const *str)
{
	char	*str_space;
	int		i;

	i = 0;
	str_space = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (str_space == NULL)
		return (NULL);
	while (str[i])
	{
		str_space[i] = str[i];
		i++;
	}
	str_space[i] = '\0';
	return (str_space);
}
