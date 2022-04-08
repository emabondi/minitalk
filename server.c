/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:59:07 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/04 17:59:07 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int	sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 1;

	if (sig == SIGUSR1)
		c |= 0;
	else
		c |= 1;
	if (i == 8)
	{
		i = 1;
		if (c == 0)
			kill(info->si_pid, SIGUSR2);
		else
			ft_printf("%c", c);
		c = 0;
		return ;
	}
	i++;
	c <<= 1;
}

int	main()
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}