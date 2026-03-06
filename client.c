/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:53:51 by djang             #+#    #+#             */
/*   Updated: 2024/05/07 21:53:53 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_binary(int pid, char word)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((word & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		send_binary(pid, message[i]);
		i++;
	}
	send_binary(pid, '\n');
	send_binary(pid, '\0');
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Wrong formats!!\n", 1);
		ft_putstr_fd("Retry please!\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
}
