/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:16:12 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/08/13 01:46:21 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	omega_free(t_table *table, int destroy, int destroy_forks)
{
	int	i;

	i = 0;
	if (destroy >= 1)
		pthread_mutex_destroy(&table->print_m);
	if (destroy >= 2)
		pthread_mutex_destroy(&table->last_meal_m);
	if (destroy >= 3)
		pthread_mutex_destroy(&table->full_m);
	if (destroy >= 4)
		pthread_mutex_destroy(&table->dead_m);
	while(i < destroy_forks)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	if (table && table->philos)
		free(table->philos);
	if (table && table->forks)
		free(table->forks);
	free(table);
}

void	exit_msg(t_table *table, char *which, int destroy, int	destroy_forks)
{
	if (which)
		while (which && *which)
			write(2, which++, 1);
	if (table)
		omega_free(table, destroy, destroy_forks);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			total;
	size_t			i;

	if (nmemb != 0 && size > (size_t)(-1) / nmemb)
		return (NULL);
	total = nmemb * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	i = 0;
	while (i < total)
		p[i++] = 0;
	return (p);
}
