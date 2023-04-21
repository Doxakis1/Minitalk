/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:38:46 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 08:50:18 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include "ft_printf.h"

typedef struct active_pid_s{
	int		pid;
	int		signal;
	size_t	current;
	size_t	msg_length;
}	t_current_pid;

int	ft_atoi(const char *str);

#endif