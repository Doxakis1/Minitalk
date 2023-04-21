/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:39:19 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 08:53:26 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile t_current_pid	g_current_pid;

int	get_value(int bits)
{
	int		size;

	size = 0;
	while (bits)
	{
		if (g_current_pid.signal == -1)
			return (-1);
		else if (!g_current_pid.signal)
			usleep(100);
		else
		{
			bits--;
			if (g_current_pid.signal == SIGUSR1)
				size |= 1 << bits;
			g_current_pid.signal = kill(g_current_pid.pid, SIGUSR1);
			if (!bits)
				return (size);
		}
	}
	return (size);
}

char	*get_message(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(size);
	if (!str)
		return (NULL);
	while (i < size)
		str[i++] = get_value((sizeof(char) * 8));
	return (str);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (!g_current_pid.pid)
		g_current_pid.pid = info->si_pid;
	g_current_pid.signal = sig;
}

int	initialize(struct sigaction *action)
{
	g_current_pid.pid = 0;
	g_current_pid.signal = 0;
	action->sa_sigaction = handler;
	action->sa_flags = SA_SIGINFO;
	sigemptyset(&(action->sa_mask));
	sigaddset(&(action->sa_mask), SIGUSR1);
	sigaddset(&(action->sa_mask), SIGUSR2);
	sigaction(SIGUSR1, action, NULL);
	sigaction(SIGUSR2, action, NULL);
	return (0);
}

int	main(void)
{
	struct sigaction	action;
	int					size;
	char				*str;

	initialize(&action);
	while (1)
	{
		ft_printf("Server pid: %i\n", getpid());
		while (!g_current_pid.signal)
			usleep(1);
		g_current_pid.signal = kill(g_current_pid.pid, SIGUSR1);
		size = get_value((sizeof(int) * 8));
		str = get_message(size);
		if (str)
		{
			ft_printf("We got the following message: %s\n", str);
			free(str);
		}
		else
			return (kill(g_current_pid.pid, SIGUSR2)
				+ write(2, "Failed to allocate memory!\n", 29));
		g_current_pid.pid = 0;
	}
	return (0);
}
