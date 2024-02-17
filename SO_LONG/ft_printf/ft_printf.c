/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:21:51 by zel-khad          #+#    #+#             */
/*   Updated: 2023/12/08 14:40:56 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int flag)
{
	static int	count = 1;

	if (flag == 1)
	{
		write(1, &c, 1);
		return (count++, 0);
	}
	else if (flag == 2)
	{
		return (count = 0, 0);
	}
	return (count);
}

static void	interpreter_input(va_list *list, int current_char)
{
	if (current_char == 's')
	{
		ft_putstr(va_arg(*list, char *));
	}
	else if (current_char == 'p')
		ft_address(va_arg(*list, unsigned long long));
	else if (current_char == 'x')
		ft_hexdecimal(va_arg(*list, unsigned int), false);
	else if (current_char == 'X')
		ft_hexdecimal(va_arg(*list, unsigned int), true);
	else if (current_char == 'd' || current_char == 'i')
		ft_putnbr(va_arg(*list, int));
	else if (current_char == 'u')
		ft_unsigned(va_arg(*list, unsigned int));
	else if (current_char == 'c')
		ft_putchar(va_arg(*list, int), 1);
	else if (current_char == '%')
		ft_putchar('%', 1);
	else
		ft_putchar(current_char, 1);
}

int	ft_printf(const char *target, ...)
{
	va_list	list;
	int		i;

	i = 0;
	if ((target[i] == '%' && target[i + 1] == '\0'))
		return (0);
	va_start(list, target);
	ft_putchar(0, 2);
	while (target[i])
	{
		if (target[i] == '%' && (target[i] == '%' && target[i + 1] != '\0'))
		{
			interpreter_input(&list, target[i + 1]);
			i++;
		}
		else if (target[i] == '%' && target[i + 1] == '\0')
			break ;
		else
			ft_putchar(target[i], 1);
		i++;
	}
	va_end(list);
	return (ft_putchar(0, 0));
}
