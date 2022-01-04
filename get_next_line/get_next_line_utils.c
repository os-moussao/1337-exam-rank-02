/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <asabani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:58:27 by asabani           #+#    #+#             */
/*   Updated: 2022/01/04 17:00:29 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strdup(char *str)
{
    int len = 0x0;
    while (str[len])
        len++;
    char *new_str = malloc(sizeof(char) * (len + 1));
    if (!new_str)
        return (0x0);
    int i = -1;
    while (++i < len)
        new_str[i] = str[i];
    new_str[i] = 0x0;
    return (new_str);
}