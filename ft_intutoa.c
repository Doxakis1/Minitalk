/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intutoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:54:42 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/23 19:31:07 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intutoa(unsigned int a, int count)
{
	int		counter;
	char	*str;
	long	number;

	counter = ft_intudigits(a);
	number = a;
	str = malloc(sizeof(char) * counter + 1);
	if (str == NULL)
		return (count);
	if (number <= 0)
		str[0] = '0';
	str[counter--] = '\0';
	while (number)
	{
		str[counter--] = number % 10 + '0';
		number = number / 10;
	}
	count = ft_intstr(str, count);
	free(str);
	return (count);
}
