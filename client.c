/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:16:07 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/24 19:18:13 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_send(int pid, int c)
{
	char			i;
	unsigned char	b;

	i = 0;
	b = 128;
	if (pid < 0)
		return (-1);
	while (i < 8)
	{
		if (c & b)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		}
		usleep(70);
		c = c << 1;
		i++;
	}
	return (0);
}

int	main(int ac, char	**av)
{
	int	i;
	int	j;

	i = 0;
	if (ac != 3)
	{
		write (2, "pleas check args!!\n", 19);
		return (0);
	}
	while (av[2][i])
		j = ft_send(ft_atoi(av[1]), av[2][i++]);
	if (j < 0)
	{
		write(1, "pleas check to enter a valide pid\n", 34);
		return (0);
	}
}
