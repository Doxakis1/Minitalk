/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:57:13 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/24 09:59:51 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_checker(va_list args, const char tag, int count)
{
	if (tag == 'c')
		count = ft_intputchar(va_arg(args, int), count);
	else if (tag == 's')
		count = ft_intstr(va_arg(args, char *), count);
	else if (tag == 'p')
		count = ft_intptr(va_arg(args, unsigned long long), count);
	else if (tag == 'd' || tag == 'i')
		count = ft_intitoa(va_arg(args, int), count);
	else if (tag == 'u')
		count = ft_intutoa(va_arg(args, unsigned int), count);
	else if (tag == 'x' || tag == 'X')
		count = ft_inthex(va_arg(args, unsigned int), count, tag);
	else if (tag == '%')
		count = ft_intputchar(tag, count);
	return (count);
}

int	ft_printf(const char *mains, ...)
{
	int		i;
	va_list	args;
	int		printed;

	i = 0;
	printed = 0;
	va_start(args, mains);
	while (mains[i])
	{
		if (mains[i] == '%' && mains[i + 1] != '\0')
		{
			printed = ft_checker(args, mains[i + 1], printed);
			i++;
		}
		else
			printed = ft_intputchar(mains[i], printed);
		i++;
	}
	va_end(args);
	return (printed);
}
