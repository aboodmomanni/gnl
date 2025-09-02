/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utalities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 06:05:40 by marvin            #+#    #+#             */
/*   Updated: 2025/08/30 06:05:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

size_t f_strlen(char *s)
{
    size_t i = 0;
    while (s && s[i])
        i++;
    return (i);
}

int f_strchr(char *s, int c)
{
    int i;

    if (!s)
        return (-1);
    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
            return (i);
        i++;
    }
    return (-1);
}

char *f_dup(char *s)
{
    size_t len = f_strlen(s);
    char *dup = malloc(len + 1);
    size_t i;

    if (!dup)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[len] = '\0';
    return (dup);
}

char *f_join(char *s1, char *s2)
{
    size_t len1, len2, i;
    char *joined;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (f_dup(s2));
    if (!s2)
        return (s1);
    len1 = f_strlen(s1);
    len2 = f_strlen(s2);
    joined = malloc(len1 + len2 + 1);
    if (!joined)
        return (free(s1), NULL);
    i = -1;
    while (++i < len1)
        joined[i] = s1[i];
    i = -1;
    while (++i < len2)
        joined[len1 + i] = s2[i];
    joined[len1 + len2] = '\0';
    free(s1);
    return (joined);
}

char *f_ssubstr(char *s, unsigned int start, size_t len)
{
    size_t max_len;
    char *sub;
    size_t i;

    if (!s || start >= f_strlen(s))
        return (f_dup(""));
    max_len = f_strlen(s + start);
    if (len > max_len)
        len = max_len;
    sub = malloc(len + 1);
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[len] = '\0';
    return (sub);
}
