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

void	handler(int	sig)
{
	static char	c = 0;
	static int	i = 1;
	int	j = 7;

	while (j > 0){
		ft_printf("%d", (c >> j) & 1);
		j--;
	}
	ft_printf ("\n");
	//ft_printf("ciao %d\n", i);
	//ft_printf("sig:%d SIGUSR1:%d SIGUSR2:%d\n", sig, SIGUSR1, SIGUSR2);
	if (i == 8)
	{
		i = 1;
		ft_printf("%d\n", c);
		c = 0;
		return ;
	}
	if (sig == SIGUSR1)
		c |= 0;
	else
		c |= 1;
	i++;
	//ft_printf("%d\n", c);
	c >>= 1;
}

int	main()
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}