/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:27:49 by mkaratzi          #+#    #+#             */
/*   Updated: 2022/11/23 19:26:22 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char *mains, ...);
int			ft_intputchar(int character, int count);
int			ft_intstr(char *src, int count);
int			ft_intptr(unsigned long long pointer, int count);
int			ft_inthex(unsigned long long num, int count, int instruction);
int			ft_checker(va_list args, const char tag, int count);
int			ft_intitoa(int a, int count);
int			ft_intutoa(unsigned int a, int count);
size_t		ft_strlen(const char *string);
int			ft_intdigits(int number);
int			ft_intudigits(unsigned int number);

#endif