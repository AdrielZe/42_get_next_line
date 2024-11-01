/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:17:43 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/01 15:50:27 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#define BUFFER_SIZE 6

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

char	*process_line(char *stash, char *word_to_insert, int times_function_was_executed)
{
	char *line;

	if (times_function_was_executed <= 0)
	{
		line = "";
		word_to_insert = "";
	}
	else if (times_function_was_executed >= 1)
		line = copy_until_break(stash, word_to_insert);
	else
		line = copy_until_break(stash, word_to_insert);
	return (line);
}
char	*handle_new_line(char **stash, char **word_to_insert , char *buffer, int times_function_was_executed)
{
	char	*line;

	times_function_was_executed = times_function_was_called();
	line = process_line(*stash, *word_to_insert, times_function_was_executed);
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
	{
		i++;
	}
	string_result = malloc(i + 1);
	ft_strlcpy(string_result, stash, i + 1);
	string_result[i] = '\0';
	if (!buffer)
		return (string_result);
	else
		return (ft_strjoin(buffer, string_result));
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*stash;
	char		*line;
	char		*word_to_insert;
	int			times_function_was_executed;
	int bytes_read;

	stash = "";
	if (times_function_was_called() <= 0)
		word_to_insert = word_to_add(NULL);
	else
		word_to_insert = word_to_add(word_to_insert);
	times_function_was_executed = times_function_was_called();
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{

		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);

		if (ft_strchr(buffer, '\n'))
		{
			line = handle_new_line(&stash, &word_to_insert,
					buffer, times_function_was_executed);
			if (!line)
				return (NULL);
			return (line);
		}
	}
	if (bytes_read == 0 && stash && *stash)
	{
		line = ft_strdup(stash);
		free (stash);
		stash = NULL;
		return line;
	}
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
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
		printf("%s\n",get_next_line(fd));
}