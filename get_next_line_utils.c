/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:54:42 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/06 12:26:20 by asilveir         ###   ########.fr       */
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
	char		*concat_string;
	size_t		i;
	size_t		j;

	if (!str1)
	{
		str1 = malloc(sizeof(char));
		str1[0] = '\0';
	}
	concat_string = malloc((ft_strlen(str1) + ft_strlen(str2)) + 1);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	if (!s)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

int	ft_endl(char	*buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}
