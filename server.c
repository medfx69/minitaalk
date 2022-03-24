/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@strtudent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:15:36 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/24 14:55:59 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int	signum)
{
	static unsigned char	str;
	static	int	i;

	str = str << 1;
		str |= signum;
	i++;
	if (i == 8)
	{
		write(1,&str,1);
		i = 0;
		str = 0;
	}
}
static void	set_zero(int	a)
{
	a = 0;
	sig_handler(1);
}

static void	set_one(int	a)
{
	a = 0;
	sig_handler(0);
}

int	main(void)
{
	int	p_id;

	p_id = getpid();
	ft_putnbr(p_id);
	signal(SIGUSR1,set_zero);
	signal(SIGUSR2,set_one);
	write(1, "\n",1);
	while(1)
		pause();
}
