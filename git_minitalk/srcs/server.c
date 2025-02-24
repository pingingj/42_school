/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:57:28 by root              #+#    #+#             */
/*   Updated: 2025/02/24 20:36:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

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

void	convert_char(char *buff, int client_id)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while(buff[i])
	{
		if(buff[i] == '1')
			result += power(2, i);
		i++;
	}
	write(1, &result, 1);
	kill(client_id, SIGUSR1);
}

void handle_signal(int signal, siginfo_t *client, void *ucontext) 
{
    static char buff[9]; 
    static int index = 0;

	(void)ucontext;
    if (signal == SIGUSR1)
        buff[index] = '1';
    else if (signal == SIGUSR2)
        buff[index] = '0';
    index++;

    if (index == 8)
    {
        buff[8] = '\0';  
        convert_char(buff, client->si_pid);
        index = 0; 
    }
}

int main(void)
{
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    
    ft_printf("server id = %d\n", getpid());
    while (1) {
        sleep(1);
    }

    return 0;
}