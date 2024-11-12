/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:25:16 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/12 14:50:15 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_count;

char	*print_msg(char *str, siginfo_t *info, int *j)
{
	str[g_count] = '\0';
	ft_printf("%s\n", str);
	g_count = 0;
	free(str);
	kill(info->si_pid, SIGUSR1);
	*j = 0;
	return (NULL);
}

void	handler_len(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 32)
	{
		g_count = i;
		i = 0;
		bit = 0;
	}
}

void	handler(int signal, siginfo_t *info, void *ucontext)
{
	static int	bit;
	static int	i;
	static int	j;
	static char	*str = NULL;

	(void)ucontext;
	if (str == NULL)
	{
		str = (char *)malloc(sizeof(char ) * g_count + 1);
		if (!str)
			exit(1);
	}
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		str[j++] = i;
		bit = 0;
		i = 0;
	}
	if (g_count != 0 && j == g_count)
		str = print_msg(str, info, &j);
}

int	main(void)
{
	int					pid;
	struct sigaction	sigact;

	pid = getpid();
	ft_printf("PID number: %d\n", pid);
	sigact.sa_sigaction = handler;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	while (1)
	{
		if (g_count == 0)
		{
			signal(SIGUSR1, handler_len);
			signal(SIGUSR2, handler_len);
		}
		else
		{
			sigaction(SIGUSR1, &sigact, NULL);
			sigaction(SIGUSR2, &sigact, NULL);
		}
		pause ();
	}
}
