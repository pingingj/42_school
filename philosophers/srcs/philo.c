/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:56:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/08/03 22:29:35 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*monitor(void *ph)
{
	t_table *table;
	bool	run;
	int	i;

	run = true;
	table = (t_table *)ph;
	while(1)
	{
		i = 0;
		while(i < table->num_philos)
		{
			pthread_mutex_lock(&table->last_meal_m);
			if (get_time(table) - table->philos[i].last_meal > table->time_die)
			{
				table->sim_run = false;
				run = false;
			}
			pthread_mutex_unlock(&table->last_meal_m);
			if (run == false)
				return (NULL);
			i++;
		}
	}
}

void    *routine(void *ph)
{
    t_philo *philo;
	
	philo = (t_philo *)ph;
	while(1)
	{
		philo_msg(philo, THINK);
		if (philo->id % 2 == 0)
			pthread_mutex_lock(philo->left_f);
		else
			pthread_mutex_lock(philo->right_f);
		philo_msg(philo, FORK);
		if (philo->id % 2 == 0)
			pthread_mutex_lock(philo->right_f);
		else
			pthread_mutex_lock(philo->left_f);
		philo_msg(philo, FORK);
		pthread_mutex_lock(&philo->table->last_meal_m);
		philo->last_meal = get_time(philo->table);
		pthread_mutex_unlock(&philo->table->last_meal_m);
		philo_msg(philo, EAT);
		usleep(philo->table->time_eat * 1000);
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		philo_msg(philo, SLEEP);
		usleep(philo->table->time_sleep * 1000);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc < 5 || argc > 6)
		exit_msg(table, "Invalid amout of arguments");
	table = create_table(argv);
	if (table == NULL)
		return (1);
	printf("num philo = %ld\ntime death = %ld\ntime eat = %ld\ntime sleep = %ld\nnum eat = %ld\n", table->num_philos, table->time_die, table->time_eat, table->time_sleep, table->num_eat);
	create_philos(table);
	start_routine(table);
	omega_free(table);
}
