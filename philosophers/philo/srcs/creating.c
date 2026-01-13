/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:39:14 by daniel            #+#    #+#             */
/*   Updated: 2025/08/13 13:43:24 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static bool	check_vars(t_table *table, char **argv)
{
	if (argv[5])
	{
		table->num_eat = ft_atol(argv[5]);
		if (table->num_eat <= 0 || table->num_eat > INT_MAX)
			return (exit_msg(table, "Invalid amount to eat\n", 0, 0), false);
	}
	if (table->num_philos <= 0 || table->num_philos > INT_MAX)
		return (exit_msg(table, "Invalid amount of philosophers\n", 0, 0),
			false);
	if (table->time_die <= 0 || table->time_die > INT_MAX)
		return (exit_msg(table, "Invalid time to die\n", 0, 0), false);
	if (table->time_eat <= 0 || table->time_eat > INT_MAX)
		return (exit_msg(table, "Invalid time to eat\n", 0, 0), false);
	if (table->time_sleep <= 0 || table->time_sleep > INT_MAX)
		return (exit_msg(table, "Invalid time to sleep\n", 0, 0), false);
	return (true);
}

t_table	*create_table(char **argv)
{
	t_table	*table;

	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (exit_msg(NULL, "Failed malloc making_table\n", 0, 0), NULL);
	table->num_philos = ft_atol(argv[1]);
	table->time_die = ft_atol(argv[2]);
	table->time_eat = ft_atol(argv[3]);
	table->time_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->num_eat = ft_atol(argv[5]);
	else
		table->num_eat = -1;
	table->sim_run = false;
	table->time_start = 0;
	if (check_vars(table, argv) == false)
		return (NULL);
	table->philos = ft_calloc(table->num_philos, sizeof(t_philo));
	if (!table->philos)
		return (exit_msg(table, "Failed malloc table->philos\n", 0, 0), NULL);
	table->forks = ft_calloc(table->num_philos, sizeof(pthread_mutex_t));
	if (!table->forks)
		return (exit_msg(table, "Failed malloc table->forks\n", 0, 0), NULL);
	return (table);
}

int	create_philos(t_table *table)
{
	int	i;

	i = 0;
	if (init_mutexes(table) == false)
		return (-1);
	table->time_start = get_time(table);
	while (i < table->num_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].last_meal = table->time_start;
		table->philos[i].amount_eat = 0;
		table->philos[i].table = table;
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (exit_msg(table, "Mutex init failed\n", 4, i), -1);
		i++;
	}
	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].left_f = &table->forks[i];
		table->philos[i].right_f = &table->forks[(i + 1) % table->num_philos];
		i++;
	}
	return (1);
}

int	start_routine(t_table *table)
{
	int			i;
	pthread_t	tmonitor;

	i = 0;
	table->sim_run = true;
	if (pthread_create(&tmonitor, NULL, monitor, table))
		return (exit_msg(table, "Failed to create thread\n", 4,
				table->num_philos), -1);
	while (i < table->num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, routine,
				&table->philos[i]) != 0)
			return (exit_msg(table, "Failed to create thread\n", 4,
					table->num_philos), -1);
		i++;
	}
	i = 0;
	pthread_join(tmonitor, NULL);
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	return (1);
}
