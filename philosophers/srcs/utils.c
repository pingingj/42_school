/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:16:12 by dgarcez-          #+#    #+#             */
/*   Updated: 2025/07/18 23:15:56 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	omega_free(t_table *table)
{
	if (table->ph && table->ph->philos)
		free(table->ph->philos);
	if (table->forks)
		free(table->forks);
	if (table->ph)
		free(table->ph);
	free(table);
}
void	exit_msg(t_table *table, char *which)
{
	if (which)
		printf("%s\n", which);
	if (table)
		omega_free(table);
	exit(1);
}

long	ft_atol(char *num)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while(num[i] && (num[i] == ' ' || (num[i] >= 9 && num[i] <= 13)))
		i++;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			sign = -1;
		i++;
	}
	while(num[i] && (num[i] >= '0' && num[i] <= '9'))
	{
		result = result * 10 + num[i] - '0';
		if (result > INT_MAX)
			break;
		i++;
	}
	if (num[i] && (num[i] < '0' || num[i] > '9'))
		result = 0;
	return (result * sign);
}
