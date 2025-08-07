/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:16:41 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/08/06 13:37:20 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "pthread.h"
#include "limits.h"
#include "stdbool.h"
#include "sys/time.h"

#define THINK 1
#define FORK 2
#define EAT 3
#define SLEEP 4 

// #define MALLOC_FAIL_PROBABILITY 4

// static inline void *random_fail_malloc(size_t size) {
//     if ((rand() % MALLOC_FAIL_PROBABILITY) == 0)
//         return (NULL);
//     return (malloc(size));
// }

// #define malloc(x) random_fail_malloc(x)

typedef struct s_philo
{
	int			id;
	long		last_meal;
	int			amount_eat;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_t		thread;
	struct s_table *table;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	last_meal_m;
	pthread_mutex_t	print_m;
	pthread_mutex_t	dead_m;
	pthread_mutex_t eat_m;
	pthread_mutex_t full_m;
	long			num_philos;
	long			time_eat;
	long			time_die;
	long			time_sleep;
	long			num_eat;
	long			time_start;
	bool			sim_run;
}	t_table;

long	ft_atol(char *num);
t_table	*create_table(char **argv);
int		create_philos(t_table *table);
void	start_routine(t_table *table);
void    *routine(void *ph);
void	*monitor(void *ph);
long	get_time(t_table *table);
bool	philo_msg(t_philo *philo, int msg_id);
void	omega_free(t_table *table);
void	exit_msg(t_table *table, char *which);


#endif