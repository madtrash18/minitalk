/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:08:31 by djang             #+#    #+#             */
/*   Updated: 2024/05/10 18:08:33 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static char	word;
	int			pid;

	(void)context;
	pid = info ->si_pid;
	if (signal == SIGUSR1)
		word |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(word, 1);
		if (word == '\0')
			kill(pid, SIGUSR1);
		bit = 0;
		word = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;
	int					pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Invaild insert!\n", 1);
		ft_putstr_fd("Please retry\n", 1);
		return (0);
	}
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &sig_handler;
	sigemptyset(&act.sa_mask);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
