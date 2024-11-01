/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:54:01 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/01 15:50:09 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>

char	*ft_strchr(char const *s, int c);
char	*ft_strjoin(char const *str1, char const *str2);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
char	*ft_strdup(char const *str);
size_t	ft_strlen(char const *string);
char	*get_next_line(int fd);
char	*copy_until_break(char *stash, char *buffer);
char	*string_to_add(char *s);

#endif