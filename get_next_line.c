/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:17:43 by asilveir          #+#    #+#             */
/*   Updated: 2024/10/28 16:38:00 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:01:32 by asilveir          #+#    #+#             */
/*   Updated: 2024/10/17 11:31:05 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

char *copy_until_break(char *s)
{
	char	*string;
	int	i;

	i = 0;
	string = malloc(ft_strlen(s));
	if (!string)
	{
		return (NULL);
	}
	while(s[i] && s[i] != '\n')
	{
		string[i] = s[i];
		i++;
	}
	return (string);
}

int	main()
{
	int	fd;
	char	buffer[100];
	int	i;
	char	*stash;
	char	*line;

	i = 0;
	stash = malloc(100);
	line = malloc(1000);
	fd = open("teste.txt", O_RDONLY);
	while (read(3,buffer,5) && !ft_strchr(stash, '\n'))
	{
		stash = ft_strjoin(stash, buffer);
		i++;
	}
	line = copy_until_break(stash);
	printf("%s", line);
}