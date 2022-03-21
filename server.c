/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:15:36 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/21 14:17:36 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int	signum)
{
	
}

int	main(void)
{
	int	p_id;

	p_id = getpid();
	ft_putnbr(p_id);
	signal(SIGINT,sig_handler);
}
