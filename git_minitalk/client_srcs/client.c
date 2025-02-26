/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:13:18 by root              #+#    #+#             */
/*   Updated: 2025/02/26 19:16:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

int	global_ack = 0;

void	kill_check(pid_t id, int signal)
{
	if (kill(id, signal) < 0)
	{
		perror("Error sending signal\n");
		exit(1);
	}
}

void	action_handler(int	signal)
{
	if(signal == SIGUSR1)
		global_ack = 1;
	if(signal == SIGUSR2)
		write(1, "Message recieved\n", 18);
}

void	send_bits(char *c, int server_id)
{
	int	i;
	int	j;
	int bit;
	
	j = 0;
	bit = 0;
	while(1)
	{
		i = 7;
		while(i >= 0)
		{
			bit = (c[j] >> i) & 1;
			if(bit == 1)
				kill_check(server_id, SIGUSR1);
			else
				kill_check(server_id, SIGUSR2);
			while(global_ack == 0)
				usleep(50);
			global_ack = 0;
			i--;
		}
		if(c[j] == '\0')
			break;
		j++;
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
	sigaction(SIGUSR2, &sa, NULL);
	server_id = ft_atoi(argv[1]);
	if(server_id <= 0)
	{
		perror("Not valid id\n");
		exit(1);
	}
	send_bits(argv[2], server_id);
}
