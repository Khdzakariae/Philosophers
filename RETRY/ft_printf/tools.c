/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:22:16 by zel-khad          #+#    #+#             */
/*   Updated: 2023/12/04 16:36:42 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else if (nb < 0)
	{
		ft_putchar('-', 1);
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0', 1);
}

void	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	while (s[len] != '\0')
	{
		ft_putchar(s[len], 1);
		len++;
	}
}

void	ft_hexdecimal(unsigned long long nb, bool mode)
{
	if (nb > 15)
	{
		ft_hexdecimal((nb / 16), mode);
		ft_hexdecimal((nb % 16), mode);
	}
	else
	{
		if (mode == true)
			ft_putchar(U_HEX[nb], 1);
		else
			ft_putchar(L_HEX[nb], 1);
	}
}

void	ft_unsigned(unsigned int nb)
{
	if (nb > 9)
	{
		ft_unsigned(nb / 10);
		ft_unsigned(nb % 10);
	}
	else
		ft_putchar(nb + '0', 1);
}

void	ft_address(unsigned long long address)
{
	ft_putstr("0x");
	ft_hexdecimal(address, false);
}
