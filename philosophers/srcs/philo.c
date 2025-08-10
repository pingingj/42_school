/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:56:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/08/11 00:15:18 by daniel           ###   ########.fr       */
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
	t_table *table;
	bool	run;
	int	i;
	int	full;

	run = true;
	table = (t_table *)ph;
	while(1)
	{
		full = 0;
		i = 0;
		while(i < table->num_philos)
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

bool	sleep_philo(t_philo *philo, long time_sleep)
{
	long	start;
	long	curr_time;
	long	elapsed;
	
	start = get_time(philo->table);
	curr_time = 0;
	elapsed = 0;
	while(elapsed < time_sleep)
	{
		usleep(100);
		curr_time = get_time(philo->table);
		elapsed = curr_time - start;
		pthread_mutex_lock(&philo->table->dead_m);
		if (philo->table->sim_run == false)
		{
			pthread_mutex_unlock(&philo->table->dead_m); 
			return (false);
		}
		pthread_mutex_unlock(&philo->table->dead_m);
	}
	return (true);
}

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
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
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
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		return (false);
	}
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	return (true);
}

void    *routine(void *ph)
{
    t_philo *philo;
	
	philo = (t_philo *)ph;

	if (philo->id % 2 == 0)
		sleep_philo(philo, philo->table->time_eat / 2);
	while(1)
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

int main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc < 5 || argc > 6)
		exit_msg(table, "Invalid amout of arguments\n");
	table = create_table(argv);
	if (table == NULL)
		return (1);
	//printf("num philo = %ld\ntime death = %ld\ntime eat = %ld\ntime sleep = %ld\nnum eat = %ld\n", table->num_philos, table->time_die, table->time_eat, table->time_sleep, table->num_eat);
	create_philos(table);
	start_routine(table);
	omega_free(table);
}
