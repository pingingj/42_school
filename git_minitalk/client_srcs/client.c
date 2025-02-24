/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:13:18 by root              #+#    #+#             */
/*   Updated: 2025/02/24 20:33:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

int	global_ack = 0;

void	action_handler(int	signal)
{
	if(signal == SIGUSR1)
		global_ack = 1;
}

void	send_bits(char *c, int server_id)
{
	int	i;
	int	j;
	int bit;
	
	j = 0;
	bit = 0;
	while(c[j])
	{
		i = 7;
		while(i >= 0)
		{
			bit = (c[j] >> i) & 1;
			if(bit == 1)
				kill(server_id, SIGUSR1);
			else
				kill(server_id, SIGUSR2);
			usleep(100);
			i--;
		}
		while(global_ack == 0)
			usleep(500);
		j++;
	}
	i = 0;
	while(i < 8)
	{
		kill(server_id, SIGUSR2);
		usleep(100);
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc != 3)
		exit(1);
	int	server_id;
	struct sigaction sa;
	sa.sa_handler = &action_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	server_id = ft_atoi(argv[1]);
	if(server_id < 0)
		exit(1);
	send_bits(argv[2], server_id);
}
