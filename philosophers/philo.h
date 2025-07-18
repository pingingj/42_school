/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:16:41 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/07/18 23:15:27 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include "stdlib.h"
#include "stdio.h"
#include "pthread.h"
#include "limits.h"
#include "stdbool.h"

#define MALLOC_FAIL_PROBABILITY 4

static inline void *random_fail_malloc(size_t size) {
    if ((rand() % MALLOC_FAIL_PROBABILITY) == 0)
        return (NULL);
    return (malloc(size));
}

#define malloc(x) random_fail_malloc(x)

typedef struct s_philo
{
	pthread_t	*philos;
	int			id;
	long		last_meal;
}	t_philo;

typedef struct s_table
{
	t_philo			*ph;
	long			num_philos;
	pthread_mutex_t	*forks;
	bool			sim_run;
	long			time_eat;
	long			num_eat;
	long			time_die;
	long			time_sleep;
}	t_table;

long	ft_atol(char *num);
void	omega_free(t_table *table);
void	exit_msg(t_table *table, char *which);



#endif