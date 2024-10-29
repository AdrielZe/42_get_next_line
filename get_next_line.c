/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:17:43 by asilveir          #+#    #+#             */
/*   Updated: 2024/10/29 16:18:44 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 5

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
int	look_for_break(char *buffer)
{
	int	i;

	i = 0;
	if (buffer[i] == '\n')
	{
		return (1);
		i++;
	}
	return (0);
}
char *copy_until_break(char *s)
{
	char	*string_result;
	int	i;
	
	i = 0;
	string_result = malloc(ft_strlen(s) + 2);
	if (!string_result)
		return (NULL);
	while(s[i] && s[i] != '\n')
	{
		string_result[i] = s[i];
		i++;
	}
	//printf("%s\n", string_result);
	i = 0;
	if (s[i] == '\n')
		s[i++] = '\n';
	// printf("%s\n", string_result);
	// string_result[i] = '\0';
	return (string_result);
}

char *get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int	i;
	int	j;
	char	*stash;
	char	*line;
	char	*ptr_to_break;
	char	*buffer_word;
	char	**buffer_array;
	int	line_break_index;

	line = NULL;
	i = 0;
	j = 0;
	line_break_index = 0;
	buffer_word = malloc(100);
	buffer_array = malloc(100);
	stash = malloc(1000);
	line = malloc(1000);
	while (read(fd,buffer, BUFFER_SIZE) && !ft_strchr(buffer,'\n'))
	{
		if (ft_strchr(buffer, '\n'))
		{
			while (buffer[line_break_index] != '\n')
				line_break_index++;
			printf("%d", line_break_index);
			while (buffer[line_break_index])
			{
				printf("%c", buffer[line_break_index]);
				line_break_index++;
			}
			printf(" - iteration ok\n");
			while(buffer[line_break_index])
			{
				stash[i] = buffer[line_break_index];
				line_break_index++;
			}
			// printf("%s-", buffer);
		}
		//printf("%s -- ", buffer);
		stash = ft_strjoin(stash, buffer);
		line = copy_until_break(stash);
	}
	printf("%s\n", line);
	stash = "";
	// printf("%s\n", stash);
}

int	main()
{
	int	fd;

	fd = open("teste.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
}