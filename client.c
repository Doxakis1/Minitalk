/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:25:38 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/04/05 09:11:48 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile t_current_pid	g_current_pid;

void	send_value(int pid, int c, int bits)
{
	while (bits)
	{
		if (!g_current_pid.signal)
			usleep(1);
		else
		{
			bits--;
			g_current_pid.signal = 0;
			if ((c & (1 << bits)))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
		}
	}
	while (!g_current_pid.signal)
		usleep(1);
}

void	send_string(int pid, char *str)
{
	if (!str)
		return ;
	while (*str)
		send_value(pid, *str++, sizeof(char) * 8);
	send_value(pid, 0, sizeof(char) * 8);
}

void	handler(int signal, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (signal == SIGUSR2)
		exit(ft_printf("Message could not be delivered!\n"));
	g_current_pid.signal = 1;
}

int	initialize(struct sigaction *action)
{
	g_current_pid.pid = 0;
	g_current_pid.signal = 0;
	g_current_pid.current = -1;
	action->sa_sigaction = handler;
	action->sa_flags = SA_SIGINFO;
	sigemptyset(&(action->sa_mask));
	sigaddset(&(action->sa_mask), SIGUSR1);
	sigaddset(&(action->sa_mask), SIGUSR2);
	sigaction(SIGUSR1, action, NULL);
	sigaction(SIGUSR2, action, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	initialize(&action);
	if (argc != 3)
		return (ft_printf("Invalid number of arguments!\n"));
	g_current_pid.pid = ft_atoi(argv[1]);
	if (g_current_pid.pid <= 0)
		return (ft_printf("Invalid pid!\n"));
	g_current_pid.msg_length = ft_strlen(argv[2]) + 1;
	if (g_current_pid.msg_length == 1)
		return (ft_printf("Invalid string\n"));
	g_current_pid.signal = kill(g_current_pid.pid, SIGUSR1);
	while (!g_current_pid.signal)
		usleep(100);
	if (g_current_pid.signal == -1)
		exit(ft_printf("Message could not be delivered!\n"));
	ft_printf("Server is ready to receive us\n");
	send_value(g_current_pid.pid, g_current_pid.msg_length, sizeof(int) * 8);
	send_string(g_current_pid.pid, argv[2]);
	ft_printf("Sent successfully!\n");
	return (0);
}
