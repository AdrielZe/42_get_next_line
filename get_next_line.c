/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:17:43 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/01 19:00:58 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#define BUFFER_SIZE 5

char	*word_to_add(const char *new_word)
{
	static char	*word;

	word = NULL;
	if (new_word)
	{
		free(word);
		word = malloc(ft_strlen(new_word) + 1);
		if (!word)
			return (NULL);
		ft_strlcpy(word, new_word, ft_strlen(new_word) + 1);
	}
	return (word);
}

int	times_function_was_called(void)
{
	static int counter = 0;
	
	return (counter++);
}

char *process_and_handle_new_line(char **stash, char **word_to_insert, char *buffer)
{
	char	*line;
	int times_function = times_function_was_called();
	

	if (times_function >= 1)
	{
		line = copy_until_break(*stash, *word_to_insert);
	}
	else
	{
		line = copy_until_break(*stash, *word_to_insert);
	}
	*word_to_insert = word_to_add(string_to_add(buffer));
	if (!line)
		return (NULL);
	free (*stash);
	return (line);
}

char	*copy_until_break(char *stash, char *buffer)
{
	int		i;
	int		j;
	char	*string_result;

	i = 0;
	j = 0;
	while ((stash[i]) && (stash[i] != '\n'))
		i++;
	string_result = malloc(i + 1);
	if (!string_result)
		return (NULL);
	ft_strlcpy(string_result, stash, i + 1);
	if (stash[i] == '\n')
		string_result[i] = '\0';
	if (!buffer)
		return (string_result);
	else
	{
		return (ft_strjoin(buffer, string_result));
	}
}
char	*string_to_add(char *s)
{
	char	*string;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	string = malloc(i + 1);
	if (!string)
       	return (NULL);
	while (s[i])
		string[j++] = s[i++];
	string[j] = '\0';
	return (string);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*stash;
	char		*line;
	char		*word_to_insert;	
	int 	bytes_read;

	stash = malloc(1);
	if (!stash)
		return (NULL);
	*stash = '\0'; 
	if (times_function_was_called() <= 0)
		word_to_insert = word_to_add(NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n'))
		{
			line = process_and_handle_new_line(&stash, &word_to_insert, buffer);
			return (line);
		}
	}
	if (bytes_read == 0 && stash && *stash)
	{
		free(word_to_insert);
		line = ft_strdup(stash);
		free (stash);
		stash = NULL;
		return line;
	}
	free (stash);
	return (NULL);
}

int	main()
{
	int	fd;
	fd = open("teste.txt", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	
}