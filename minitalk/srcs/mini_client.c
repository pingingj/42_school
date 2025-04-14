/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:13:18 by root              #+#    #+#             */
/*   Updated: 2025/03/06 16:26:47 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

int		g_global_ack = 0;

void	action_handler(int signal)
{
	if (signal == SIGUSR1)
		g_global_ack = 1;
}

void	send_bits_num(int c, int server_id)
{
	int	i;
	int	bit;

	i = 31;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill_check(server_id, SIGUSR1);
		else
			kill_check(server_id, SIGUSR2);
		while (g_global_ack == 0)
			usleep(50);
		g_global_ack = 0;
		i--;
	}
}

void	send_bits_char(char c, int server_id)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill_check(server_id, SIGUSR1);
		else
			kill_check(server_id, SIGUSR2);
		while (g_global_ack == 0)
			usleep(50);
		g_global_ack = 0;
		i--;
	}
}

int	main(int argc, char **argv)
{
	int					server_id;
	struct sigaction	sa;
	int					length;
	int					i;

	i = -1;
	length = ft_strlen(argv[2]);
	if (argc != 3)
		return(ft_putstr_fd("Please input only two arguments\n",2), 1);
	sa.sa_handler = &action_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	server_id = ft_atoi(argv[1]);
	if (server_id <= 0)
	{
		perror("Not valid id\n");
		exit(1);
	}
	send_bits_num(length, server_id);
	while (argv[2][++i])
		send_bits_char(argv[2][i], server_id);
	send_bits_char('\0', server_id);
	ft_printf("Message recieved");
}
