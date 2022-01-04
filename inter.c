/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:18:42 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/04 16:21:01 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	char	hash[256] = {0};
	char	*s1 = av[1], *s2 = av[2];

	while (*s2)
	{
		hash[(int)*s2] = 1;
		s2++;
	}
	while (*s1)
	{
		if (hash[(int)*s1] == 1)
		{
			ft_putchar(*s1);
			hash[(int)*s1] = 0;
		}
		s1++;
	}
	ft_putchar('\n');
}
