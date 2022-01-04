/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <asabani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:52:38 by asabani           #+#    #+#             */
/*   Updated: 2022/01/04 17:01:52 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char heap[0x5b8d80] = {0x0};
	char buff;
	int nbyte = 0x0;
	int i = 0x0;
	if (fd < 0x0 || BUFFER_SIZE <= 0x0)
		return (0);
	while ((nbyte = read(fd, &buff, 0x1)) && nbyte > 0x0)
	{
		heap[i++] = buff;
		if (buff == '\n')
			break;
	}
	heap[i] = '\0';
	if (nbyte <= 0x0 && i == 0x0)
		return (0x0);
	return ft_strdup(heap);
}
