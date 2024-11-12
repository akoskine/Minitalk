/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:25:06 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/12 14:50:11 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Received!\n");
}

void	send_len(int pid, int len)
{
	int	bit;

	bit = 0;
	while (bit < 32)
	{
		if ((len & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
}

void	send(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	len;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Wrong format!\n");
		return (1);
	}
	len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	send_len(pid, len);
	while (argv[2][i] != '\0')
	{
		signal(SIGUSR1, receive);
		signal(SIGUSR2, receive);
		send(pid, argv[2][i]);
		i++;
	}
	return (0);
}
