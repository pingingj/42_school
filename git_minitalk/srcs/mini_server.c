/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:57:28 by root              #+#    #+#             */
/*   Updated: 2025/03/06 15:42:38 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	cleaning(char **string, int *i, int *index)
{
	*string = NULL;
	*i = 0;
	*index = 0;
}

void	put_str(char *string, char c, int *index, int *i)
{
	string[*i] = c;
	*i += 1;
	if (c == '\0')
	{
		ft_putendl_fd(string, 1);
		free(string);
		string = NULL;
		*i = 0;
	}
	*index = 0;
}

void	recieve_string(int signal, siginfo_t *client, int length)
{
	static int		i;
	static char		*string;
	static char		c;
	static int		index;
	static pid_t	client_id;

	if (!client_id || client_id != client->si_pid)
	{
		cleaning(&string, &i, &index);
		client_id = client->si_pid;
	}
	if (!string)
		string = malloc(length * (sizeof(char)) + 1);
	if (string == NULL)
		return ;
	c = c << 1;
	if (signal == SIGUSR1)
		c |= 1;
	else if (signal == SIGUSR2)
		c |= 0;
	index++;
	if (index == 8)
		put_str(string, c, &index, &i);
	kill_check(client->si_pid, SIGUSR1);
}

void	handle_signal(int signal, siginfo_t *client, void *empty)
{
	static int		bits;
	static int		length;
	static pid_t	client_id;

	if (!client_id || client_id != client->si_pid)
	{
		client_id = client->si_pid;
		bits = 0;
	}
	(void)empty;
	if (bits == 32)
	{
		recieve_string(signal, client, length);
		return ;
	}
	if (bits < 32)
	{
		length = length << 1;
		if (signal == SIGUSR1 && bits != 32)
			length |= 1;
		bits++;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL)
		== -1)
	{
		perror("Error performing sigaction\n");
		return (1);
	}
	ft_printf("server id = %d\n", getpid());
	while (1)
		pause();
	return (0);
}
