/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:54:42 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/05 16:22:49 by asilveir         ###   ########.fr       */
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
	int		i;
	char	*string_to_search_in;

	if (!s || !c)
		return (NULL);
	i = 0;
	string_to_search_in = (char *)s;
	while (string_to_search_in[i])
	{
		if (string_to_search_in[i] == (char) c)
			return (&string_to_search_in[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*concat_string;
	size_t		size_to_alloc;
	size_t		i;
	size_t		j;

	if (!str1)
	{
		str1 = malloc(sizeof(char));
		str1[0] = '\0';
	}
	size_to_alloc = ((ft_strlen(str1) + ft_strlen(str2)) + 1);
	concat_string = malloc((size_to_alloc));
	if (!concat_string)
		return (NULL);
	i = 0;
	j = 0; 
	while (str1[i])
	{
		concat_string[i] = str1[i];
		i++;
	}
	while (str2[j])
		concat_string[i++] = str2[j++];
	concat_string[i] = '\0';
	free(str1);
	return (concat_string);
}
size_t	check_len(size_t len, size_t strlen, unsigned int start)
{
	if (len > strlen - start)
	{
		len = strlen - start;
		return (len);
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc((1) * sizeof(char));
		substr[0] = '\0';
		return (substr);
	}
	len = check_len(len, ft_strlen(s), start);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_endl(char	*buffer)
{
	size_t	i;

	i = 0;
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}