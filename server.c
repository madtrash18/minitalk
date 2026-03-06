/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:53:31 by djang             #+#    #+#             */
/*   Updated: 2024/05/07 21:53:33 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighand(int signal)
{
	static int	bit;
	static char	word;

	if (signal == SIGUSR1)
		word |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(word, 1);
		bit = 0;
		word = 0;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Invaild insert!\n", 1);
		ft_putstr_fd("Please retry\n", 1);
		return (0);
	}
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, sighand);
	signal(SIGUSR2, sighand);
	while (1)
		pause();
	return (0);
}
