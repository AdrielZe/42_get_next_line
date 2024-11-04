/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:17:43 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/04 19:56:31 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#define BUFFER_SIZE 1

int	times_function_was_called(void)
{
	static int counter = 0;
	
	return (counter++);
}

char *process_and_handle_new_line(char **stash, char **word_to_insert, char *buffer)
{
	char	*line;
	
	// if (!stash || !buffer)
	// 	return (NULL);
	line = copy_until_break(*stash, *word_to_insert);
	if (!line)
		return (NULL);
	free (*stash);
	stash = NULL;
	return (line);
}
//copia o conteudo da string ate o \n e concatena com o buffer atual
char	*copy_until_break(char *stash, char *buffer)
{
	int		i;
	int		j;
	char	*string_result;
	char	*result;

	i = 0;
	j = 0;
	while ((stash[i]) && (stash[i] != '\n'))
		i++;
	string_result = malloc(i + 1);
	if (!string_result)
		return (NULL);
	ft_strlcpy(string_result, stash, i + 1);
	if (!buffer)
		return (string_result);
	result = ft_strjoin(buffer, string_result);
	free(string_result);
	return result;
}
// String para ser adicionada no inicio do proximo buffer - pega o conteudo depois do '\n'
char	*string_to_add(char *s)
{
   char *string;
    size_t i = 0;
    size_t j = 0;

    while (s[i] && s[i] != '\n')
        i++;
    if (!s[i] || ft_strlen(s + i) == 0)
        return NULL;
    string = malloc(ft_strlen(s + i) + 1);
    if (!string)
        return NULL;
    while (s[++i])
        string[j++] = s[i];
    string[j] = '\0';
    return string;
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*stash;
	char		*line;
	char *temp; 
	static char		*word_to_insert;	
	int 	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (times_function_was_called() <= 0)
		word_to_insert = NULL;
	stash = malloc(1);
	if (!stash)
		return (NULL);
	*stash = '\0'; 
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
		{
			line = process_and_handle_new_line(&stash, &word_to_insert, buffer);
			free(word_to_insert);
			word_to_insert = string_to_add(buffer);
			return (line);
		}
	}
	if (bytes_read == 0 && stash && *stash)
	{	line = ft_strdup(stash);
		if (!line)
			return NULL;
		free (stash);
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
	// printf("%s\n",get_next_line(fd));
	// printf("%s\n",get_next_line(fd));
	// printf("%s\n",get_next_line(fd));
	// printf("%s\n",get_next_line(fd));
	// printf("%s\n",get_next_line(fd));
	// printf("%s\n",get_next_line(fd));
	// printf("%s\n",get_next_line(fd));
}