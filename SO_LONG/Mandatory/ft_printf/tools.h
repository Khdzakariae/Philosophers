/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:00:23 by zel-khad          #+#    #+#             */
/*   Updated: 2023/12/09 12:00:28 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define L_HEX "0123456789abcdef"
# define U_HEX "0123456789ABCDEF"

# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>

int		ft_putchar(char c, int flag);
void	ft_putnbr(int nb);
void	ft_putstr(char *s);
void	ft_hexdecimal(unsigned long long nb, bool mode);
void	ft_unsigned(unsigned int nb);
void	ft_address(unsigned long long address);
#endif
