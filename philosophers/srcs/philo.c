/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:56:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/07/18 23:41:07 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    *printing(void *num)
{
    // long    *add;

    // add = (long *) (num);
    printf("lol the thread says omg and the num is %ld\n", *(long *)(num));
    return (NULL);
}

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

t_table	*making_table(char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		exit_msg(NULL, "Failed malloc making_table");
	table->num_philos = ft_atol(argv[1]);
	table->time_die = ft_atol(argv[2]);
	table->time_eat = ft_atol(argv[3]);
	table->time_sleep = ft_atol(argv[4]);
	table->ph = NULL;
	table->forks = NULL;
	table->num_eat = -1;
	table->sim_run = false;
	check_vars(table, argv);
	table->ph = malloc(sizeof(t_philo));
	if (!table->ph)
		exit_msg(table, "Failed malloc table->ph");
	table->ph->philos = malloc(sizeof(pthread_t) * table->num_philos);
	if (!table->ph->philos)
		exit_msg(table, "Failed malloc table->ph->philos");
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!table->forks)
		exit_msg(table, "Failed malloc table->forks");
	return (table);
}

int	create_sim(t_table	*table)
{
	int	i;

	i = 0;
	while(i < table->num_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc < 5 || argc > 6)
		exit_msg(table, "Invalid amout of arguments");
	table = making_table(argv);
	if (table == NULL)
		return (1);
	printf("num philo = %ld\n", table->num_philos);
	omega_free(table);
}
