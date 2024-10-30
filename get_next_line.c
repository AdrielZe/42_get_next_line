/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:17:43 by asilveir          #+#    #+#             */
/*   Updated: 2024/10/30 19:01:05 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#define BUFFER_SIZE 5

static char *words_to_add = "";

void word_to_add(char *word)
{
	statich char *word_to_add;
	word_to_add = 
}

void foo() 
{
    static int counter = 0;  // Retains value between calls
    counter++;
    printf("Counter: %d\n", counter);
}

char *get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*stash;
	char	*line;
	char	*temp;

	stash = malloc(1);
	line = malloc(1);
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
			return (line);
		}
	}
	free (stash);
	return ("0");
}

int	main()
{
	int	fd;

	fd = open("teste.txt", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
}