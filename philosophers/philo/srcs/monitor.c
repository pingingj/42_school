/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:30:45 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/08/13 02:10:36 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	dead_philo(t_table *table, bool *run, int i)
{
	pthread_mutex_lock(&table->last_meal_m);
	if (get_time(NULL) - table->philos[i].last_meal > table->time_die)
	{
		*run = false;
		pthread_mutex_lock(&table->dead_m);
		table->sim_run = false;
		pthread_mutex_unlock(&table->dead_m);
		pthread_mutex_lock(&table->print_m);
		printf("%ld %d died\n", get_time(table), table->philos[i].id);
		pthread_mutex_unlock(&table->print_m);
	}
	pthread_mutex_unlock(&table->last_meal_m);
}

void	full_philo(t_table *table, bool *run, int i, int *full)
{
	pthread_mutex_lock(&table->full_m);
	if (table->num_eat != -1 && table->philos[i].amount_eat >= table->num_eat)
		(*full)++;
	pthread_mutex_unlock(&table->full_m);
	if ((*full) == table->num_philos)
	{
		pthread_mutex_lock(&table->dead_m);
		table->sim_run = false;
		pthread_mutex_unlock(&table->dead_m);
		*run = false;
	}
}

void	*monitor(void *ph)
{
	t_table	*table;
	bool	run;
	int		i;
	int		full;

	run = true;
	table = (t_table *)ph;
	while (1)
	{
		full = 0;
		i = 0;
		while (i < table->num_philos)
		{
			dead_philo(table, &run, i);
			full_philo(table, &run, i, &full);
			if (run == false)
				return (NULL);
			i++;
		}
		usleep(100);
	}
}
