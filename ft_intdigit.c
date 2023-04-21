/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:53:35 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/23 18:54:27 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intdigits(int number)
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
