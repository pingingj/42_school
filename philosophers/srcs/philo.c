/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:56:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/06/16 20:31:40 by dgarcez-         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	long	philo;

	if (argc != 4)
	{
		printf("Not enough arguments\n");
		return (1);
    }
	philo = ft_atol(argv[1]);
	if (philo <= 0 || philo > INT_MAX)
	{
		printf("Not valid amount of philosophers\n");
		return (1);
	}
	printf("num philo = %ld\n", philo);
}