/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:53:53 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/22 23:16:22 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putchar(char n)
{
	write(1, &n, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	num;
	unsigned int	snum;
	unsigned int	j;

	j = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	num = nb;
	snum = num;
	while (num > 9)
	{
		j = j * 10;
		num = num / 10;
	}
	while (j > 0)
	{
		ft_putchar(snum / j + '0');
		snum = snum - (snum / j) * j;
		j = j / 10;
	}
}
