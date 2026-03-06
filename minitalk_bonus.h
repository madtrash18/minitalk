/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:08:48 by djang             #+#    #+#             */
/*   Updated: 2024/05/10 18:08:50 by djang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# define _GNU_SOURCE

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

void	sig_handler(int signal, siginfo_t *info, void *context);

void	receive_ok(int signal);
void	send_binary(int pid, char word);
void	send_message(int pid, char *message);

#endif
