/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:16:12 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/08/03 21:42:54 by daniel           ###   ########.fr       */
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
	printf("%s\n", which);
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
	if (table->time_start == -1)
		return (current_t);
	else
		return (current_t - table->time_start);
}

void	philo_msg(t_philo *philo, int msg_id)
{
	pthread_mutex_lock(&philo->table->print_m);
	if (msg_id == 1)
		printf("[%ld] Philosopher %d is thinking\n", get_time(philo->table), philo->id);
	else if (msg_id == 2)
		printf("[%ld] Philosopher %d picked up a fork\n", get_time(philo->table), philo->id);
	else if (msg_id == 3)
		printf("[%ld] Philosopher %d is eating\n", get_time(philo->table), philo->id);
	else if (msg_id == 4)
		printf("[%ld] Philosopher %d is sleeping\n", get_time(philo->table), philo->id);
	pthread_mutex_unlock(&philo->table->print_m);
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
