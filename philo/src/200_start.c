/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   200_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:13:57 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 18:42:28 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	start_philo(t_table *table)
{
	int		i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philos);
	if (!table->philos)
		error_exit("Error: Malloc failed", 2);
	table->forks = malloc(sizeof(t_fork) * table->nbr_of_philos);
	if (!table->forks)
		error_exit("Error: Malloc failed", 2);
	
}
