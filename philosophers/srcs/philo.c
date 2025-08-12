/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:56:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/08/12 18:32:37 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	sleep_philo(t_philo *philo, long time_sleep)
{
	long	start;
	long	curr_time;
	long	elapsed;

	if (time_sleep <= 0)
		return (true);
	start = get_time(philo->table);
	curr_time = 0;
	elapsed = 0;
	while (elapsed < time_sleep)
	{
		curr_time = get_time(philo->table);
		elapsed = curr_time - start;
		pthread_mutex_lock(&philo->table->dead_m);
		if (philo->table->sim_run == false)
		{
			pthread_mutex_unlock(&philo->table->dead_m);
			return (false);
		}
		pthread_mutex_unlock(&philo->table->dead_m);
		usleep(100);
	}
	return (true);
}

static	bool	pick_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left_f);
	else
		pthread_mutex_lock(philo->right_f);
	if (philo_msg(philo, "has taken a fork\n", FORK) == false)
	{
		if (philo->id % 2 == 0)
			pthread_mutex_unlock(philo->left_f);
		else
			pthread_mutex_unlock(philo->right_f);
		return (false);
	}
	if (!one_philo(philo))
		return (false);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_f);
	else
		pthread_mutex_lock(philo->left_f);
	if (philo_msg(philo, "has taken a fork\n", FORK) == false)
	{
		drop_forks(philo);
		return (false);
	}
	return (true);
}

bool	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->last_meal_m);
	philo->last_meal = get_time(NULL);
	pthread_mutex_unlock(&philo->table->last_meal_m);
	pthread_mutex_lock(&philo->table->full_m);
	philo->amount_eat++;
	pthread_mutex_unlock(&philo->table->full_m);
	if (philo_msg(philo, "is eating\n", EAT) == false)
	{
		drop_forks(philo);
		return (false);
	}
	drop_forks(philo);
	return (true);
}

void	*routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	if (philo->id % 2 == 0)
		sleep_philo(philo, philo->table->time_eat / 2);
	while (1)
	{
		if (pick_forks(philo) == false)
			return (NULL);
		if (eating(philo) == false)
			return (NULL);
		if (philo_msg(philo, "is sleeping\n", SLEEP) == false)
			return (NULL);
		if (philo_msg(philo, "is thinking\n", THINK) == false)
			return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc < 5 || argc > 6)
		exit_msg(table, "Invalid amout of arguments\n");
	table = create_table(argv);
	if (table == NULL)
		return (1);
	create_philos(table);
	start_routine(table);
	omega_free(table);
}
