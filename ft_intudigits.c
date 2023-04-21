/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intudigits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:26:43 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/24 09:51:20 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intudigits(unsigned int number)
{
	int	counter;

	counter = 0;
	if (number <= 0)
		counter++;
	while (number)
	{
		counter++;
		number = number / 10;
	}
	return (counter);
}
