/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:39:14 by daniel            #+#    #+#             */
/*   Updated: 2025/08/03 22:32:37 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	check_vars(t_table *table, char **argv)
{
	if (argv[5])
	{
		table->num_eat = ft_atol(argv[5]);
		if (table->num_eat <= 0 || table->num_eat > INT_MAX)
			exit_msg(table, "Invalid amount to eat");
	}
	if (table->num_philos <= 0 || table->num_philos > INT_MAX)
		exit_msg(table, "Invalid amount of philosophers");
	if (table->time_die <= 0 || table->time_die > INT_MAX)
		exit_msg(table, "Invalid time to die");
	if (table->time_eat <= 0 || table->time_eat > INT_MAX)
		exit_msg(table, "Invalid time to eat");
	if (table->time_sleep <= 0 || table->time_sleep > INT_MAX)
		exit_msg(table, "Invalid time to sleep");
}

t_table	*create_table(char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		exit_msg(NULL, "Failed malloc making_table");
	table->num_philos = ft_atol(argv[1]);
	table->time_die = ft_atol(argv[2]);
	table->time_eat = ft_atol(argv[3]);
	table->time_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->num_eat = ft_atol(argv[5]);
	else
		table->num_eat = -1;
	table->philos = NULL;
	table->forks = NULL;
	table->sim_run = false;
	table->time_start = -1;
	check_vars(table, argv);
	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (!table->philos)
		exit_msg(table, "Failed malloc table->philos");
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!table->forks)
		exit_msg(table, "Failed malloc table->forks");
	return (table);
}

int	create_philos(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&table->print_m, NULL) != 0)
		exit_msg(table, "Mutex init failed");
	if (pthread_mutex_init(&table->last_meal_m, NULL) != 0)
		exit_msg(table, "Mutex init failed");
	table->time_start = get_time(table);
	while(i < table->num_philos)
	{
		table->philos[i].id = i;
		table->philos[i].last_meal = table->time_start;
		table->philos[i].table = table;
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			exit_msg(table, "Mutex init failed");
		i++;
	}
	i = 0;
	while(i < table->num_philos)
	{
		table->philos[i].left_f = &table->forks[i];
		table->philos[i].right_f = &table->forks[(i + 1) % table->num_philos];
		i++;
	}
	return (1);
}

void	start_routine(t_table *table)
{
	int	i;
	pthread_t	tmonitor;

	i = 0;
	table->sim_run = true;
	if (pthread_create(&tmonitor, NULL, monitor, table))
		exit_msg(table, "Failed to create thread");
	while(i < table->num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, routine, &table->philos[i]) != 0)
        	exit_msg(table, "Failed to create thread");
		i++;
	}
	i = 0;
	pthread_join(tmonitor, NULL);
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}
