/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:57:28 by root              #+#    #+#             */
/*   Updated: 2025/02/26 22:31:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	cleaning(char	*buff, int *index, pid_t *client_id, pid_t client_si_pid)
{
	(*client_id) = client_si_pid;
	(*index) = 0;
	int	i;

	i = 0;
	while(buff[i])
	{
		buff[i] = '\0';
		i++;
	}
}

int	power(int nb, int power)
{
	if(power == 0)
		return (1);
	int	result;
	result = 128;
	while(power > 0)
	{
		result = result / nb;
		power--;
	}
	return (result);
}

char	convert_char(char *buff)
{
	int	result;
	int	i;
    char	character;
	i = 0;
	result = 0;
	while(buff[i])
	{
		if(buff[i] == '1')
			result += power(2, i);
		i++;
	}
	character = result;
	return (character);
}

void handle_signal(int signal, siginfo_t *client, void *empty) 
{
    static char buff[9]; 
    static int index;
	static pid_t	client_id;
	char	character;

	if(!client_id || client_id != client->si_pid)
		cleaning(buff, &index, &client_id, client->si_pid);
	(void)empty;
    if (signal == SIGUSR1)
        buff[index] = '1';
    else if (signal == SIGUSR2)
        buff[index] = '0';
    index++;
    if (index == 8)
    {
		index = 0;
		buff[8] = '\0';  
        character = convert_char(buff);
		if(character != '\0')
			write(1, &character, 1);
		else
			kill(client->si_pid, SIGUSR2);
    }
	kill(client->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("Error performing sigaction\n");
        return 1;
    }
    
    ft_printf("server id = %d\n", getpid());
    while (1) {
        sleep(1);
    }

    return 0;
}
