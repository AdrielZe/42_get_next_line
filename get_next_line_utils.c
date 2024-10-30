/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:54:42 by asilveir          #+#    #+#             */
/*   Updated: 2024/10/30 19:01:49 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
// Usado para retornar o tamanho da string e mallocar o valor
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
//Usada para encontrar a ocorrência do primeiro '\n' presente na linha atual ( se houver )
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
//Concatena duas strings. Usado para concatenar o valor do buffer na string 'stash', que vai acumular os caracteres pelos quais o buffer passa
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

// Retorna a string presente na linha até o '\n', removendo a parte do buffer que não vamos usar
char	*copy_until_break(char *stash, char *buffer)
{
	int		i;
	int		j;
	char	*string_result;
	char	*string_formatted;

	i = 0;
	j = 0;
	string_result = malloc(1000);
	if (!string_result)
		return (NULL);
	while ((stash[i]) && (stash[i] != '\n'))
	{
		string_result[i] = stash[i];
		i++;
	}
	string_result[i] = '\0';
	if (!buffer)
		return (string_result);
	else
		return (ft_strjoin(buffer, string_result));
}

// Verifica a string a ser adicionada ao início da próxima linha (retorna os carácteres presentes após '\n' na string)
char	*string_to_add(char *s)
{
	char	*string;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	string = malloc(50);
	while (s[i] != '\n')
		i++;
	while (s[i])
	{
		string[j] = s[i];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}
