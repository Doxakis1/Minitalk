/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:51:56 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/23 19:44:32 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intptr(unsigned long long pointer, int count)
{
	write(1, "0x", 2);
	count += 2;
	if (pointer == 0)
	{
		write(1, "0", 1);
		count++;
		return (count);
	}
	count = ft_inthex(pointer, count, 'x');
	return (count);
}
