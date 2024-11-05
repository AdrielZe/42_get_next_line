/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:54:01 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/05 15:14:18 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>

char	*ft_strchr(char const *s, int c);
char	*ft_strjoin(char *str1, char *str2);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
size_t	ft_strlen(char const *string);
char	*get_next_line(int fd);
int	ft_endl(char	*buffer);
char	*string_to_add(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif