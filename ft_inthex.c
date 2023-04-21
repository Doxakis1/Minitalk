/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:51:23 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/24 10:01:53 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_inthex(unsigned long long num, int count, int instruction)
{
	char					str[42];
	unsigned long long		holder;
	int						index;

	index = 0;
	if (num == 0)
		str[index++] = num + '0';
	while (num > 0)
	{
		holder = num;
		num = num % 16;
		if (num <= 9)
			str[index++] = num + '0';
		else
			str[index++] = num - 10 + instruction - 23;
		num = holder / 16;
	}
	while (--index >= 0)
	{
		count = ft_intputchar(str[index], count);
	}
	return (count);
}
