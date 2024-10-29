/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:17:43 by asilveir          #+#    #+#             */
/*   Updated: 2024/10/29 20:34:17 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 5

static char *words_to_add = "";
static int	times_function_was_called;

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
char *copy_until_break(char *stash, char *buffer)
{
	char	*string_result;
	char	*string_formatted;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	string_result = malloc(1000);
	if (!string_result)
		return (NULL);
	while((stash[i]) && (stash[i] != '\n'))
	{
		string_result[i] = stash[i];
		i++;
	}
	string_result[i] = '\0';
	if(!buffer)
		return (string_result);
	else 
		return (ft_strjoin(buffer, string_result));
}

char *string_to_add(char *s)
{
	char *string;
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	string = malloc(50);
	while (s[i] != '\n')
		i++;
	while(s[i])
	{
		string[j] = s[i];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}

char *get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*stash;
	char	*line;


	stash = malloc(100);
	line = malloc(100);
	printf("%d\n", times_function_was_called);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		stash = ft_strjoin(stash,buffer);
		if (ft_strchr(buffer,'\n'))
		{
			if (times_function_was_called == 0)
			{
				words_to_add = "";
			}
			if (times_function_was_called >= 1)
			{
				line = copy_until_break(stash, words_to_add);
			}
			line = copy_until_break(stash, words_to_add);
			if (times_function_was_called == 0)
			{
				words_to_add = string_to_add(buffer);
			}
			times_function_was_called++;
			words_to_add = string_to_add(buffer);
			printf("%s\n", line);
			return (line);
		}
	}
	return ("0");
}

int	main()
{
	int	fd;
	

	fd = open("teste.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);

}