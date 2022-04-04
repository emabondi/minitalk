/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:23:48 by ebondi            #+#    #+#             */
/*   Updated: 2022/04/03 17:23:48 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *str)
{
	ft_printf("%s error\n", str);  //da cambiare
	exit (1);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		printf("%d\n", (c >> i) & 1);
		if (((c >> i) & 1) == 0)
			if(kill(pid, SIGUSR1) == -1)
				ft_error("PID");
		else
			if (kill(pid, SIGUSR2) == -1)
				ft_error("PID");
		sleep(1);
		i--;
	}
}

void	send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		send_char(pid, msg[i]);
		i++;
	}
}

int	check_args(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
		return (0);
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (ft_isprint(argv[2][i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*msg;

	if(check_args(argc, argv) == 0)
		ft_error("ARG");
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	send_message(pid, msg);
	return (0);
}