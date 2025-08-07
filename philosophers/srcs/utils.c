/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:16:12 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/08/07 13:56:46 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	omega_free(t_table *table)
{
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	free(table);
}

void	exit_msg(t_table *table, char *which)
{
	if (which)
		while(which && *which)
			write(2, which++, 1);
	if (table)
		omega_free(table);
	exit(1);
}

long	get_time(t_table *table)
{
	struct timeval time;
	long	current_t;
	gettimeofday(&time, NULL);
	current_t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (!table)
		return (current_t);
	else
		return (current_t - table->time_start);
}

bool	philo_msg(t_philo *philo, int msg_id)
{
	pthread_mutex_lock(&philo->table->print_m);
	pthread_mutex_lock(&philo->table->dead_m);
	if (philo->table->sim_run == false)
	{
		pthread_mutex_unlock(&philo->table->dead_m);
		pthread_mutex_unlock(&philo->table->print_m);
		return (false);
	}
	pthread_mutex_unlock(&philo->table->dead_m);
	if (msg_id == 1)
		printf("%ld %d is thinking\n", get_time(philo->table), philo->id);
	else if (msg_id == 2)
		printf("%ld %d has taken a fork\n", get_time(philo->table), philo->id);
	else if (msg_id == 3)
		printf("%ld %d is eating\n", get_time(philo->table), philo->id);
	else if (msg_id == 4)
		printf("%ld %d is sleeping\n", get_time(philo->table), philo->id);
	pthread_mutex_unlock(&philo->table->print_m);
	return (true);
}

long	ft_atol(char *num)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while(num[i] && (num[i] == ' ' || (num[i] >= 9 && num[i] <= 13)))
		i++;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			sign = -1;
		i++;
	}
	while(num[i] && (num[i] >= '0' && num[i] <= '9'))
	{
		result = result * 10 + num[i] - '0';
		if (result > INT_MAX)
			break;
		i++;
	}
	if (num[i] && (num[i] < '0' || num[i] > '9'))
		result = 0;
	return (result * sign);
}
