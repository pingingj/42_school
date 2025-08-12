/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:31:42 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/08/12 18:53:47 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	one_philo(t_philo *philo)
{
	if (philo->table->num_philos == 1)
	{
		sleep_philo(philo, philo->table->time_die);
		pthread_mutex_unlock(philo->right_f);
		return (false);
	}
	return (true);
}

void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
	}
	else
	{
		pthread_mutex_unlock(philo->right_f);
		pthread_mutex_unlock(philo->left_f);
	}
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
