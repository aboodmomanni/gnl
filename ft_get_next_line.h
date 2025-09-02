/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 06:04:56 by marvin            #+#    #+#             */
/*   Updated: 2025/08/30 06:04:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
#define FT_GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
char *extract_line(char *string);
char *update_leftover(char *string);

size_t f_strlen(char *s);
int f_strchr(char *s, int c);
char *f_dup(char *s);
char *f_join(char *s1, char *s2);
char *f_ssubstr(char *s, unsigned int start, size_t len);

#endif
