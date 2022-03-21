/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:20:29 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/21 13:20:32 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strmsub(int nb, int sign, unsigned int j, int c)
{
	unsigned int	i;
	char			*ptr;

	if (sign < 0)
		ptr = (char *)malloc(c + 3);
	else
		ptr = (char *)malloc(c + 2);
	if (!ptr)
		return (0);
	i = 0;
	while (j > 0)
	{
		if (sign < 0)
		{
			ptr [0] = '-';
			i++;
			sign = sign * -1;
		}
		ptr[i] = nb / j + 48;
		nb = nb - (nb / j) * j;
		j = j / 10;
		i++;
	}
	ptr [i] = '\0';
	return (ptr);
}

char	*ft_itoa(int nb)
{
	unsigned int	num;
	unsigned int	j;
	unsigned int	i;
	char			*ptr;
	int				sign;

	j = 1;
	sign = 1;
	if (nb < 0)
	{
		sign = -1;
		nb = nb * -1;
	}
	num = nb;
	i = 0;
	while (num > 9)
	{
		j = j * 10;
		num = num / 10;
		i++;
	}
	ptr = ft_strmsub(nb, sign, j, i);
	return (ptr);
}
