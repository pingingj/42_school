/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:16:12 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/08/12 17:31:38 by dgarcez-         ###   ########.fr       */
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
		while (which && *which)
			write(2, which++, 1);
	if (table)
		omega_free(table);
	exit(1);
}

long	get_time(t_table *table)
{
	struct timeval	time;
	long			current_t;

	gettimeofday(&time, NULL);
	current_t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (!table)
		return (current_t);
	else
		return (current_t - table->time_start);
}

bool	philo_msg(t_philo *philo, char *msg, int msg_id)
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
	if (msg)
		printf("%ld %d %s", get_time(philo->table), philo->id, msg);
	pthread_mutex_unlock(&philo->table->print_m);
	if (msg_id == EAT)
		if (!sleep_philo(philo, philo->table->time_eat))
			return (false);
	if (msg_id == SLEEP)
		if (!sleep_philo(philo, philo->table->time_sleep))
			return (false);
	if (msg_id == THINK)
		if (philo->table->num_philos % 2 != 0)
			if (!sleep_philo(philo, philo->table->time_eat * 2
					- philo->table->time_sleep))
				return (false);
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
	while (num[i] && (num[i] == ' ' || (num[i] >= 9 && num[i] <= 13)))
		i++;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			sign = -1;
		i++;
	}
	while (num[i] && (num[i] >= '0' && num[i] <= '9'))
	{
		result = result * 10 + num[i] - '0';
		if (result > INT_MAX)
			break ;
		i++;
	}
	if (num[i] && (num[i] < '0' || num[i] > '9'))
		result = 0;
	return (result * sign);
}
