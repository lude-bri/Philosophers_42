/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   300_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:42:51 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 19:44:33 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ended_meal(t_table *table)
{
	int		ended;

	pthread_mutex_lock(&table->end_mtx);
	ended = table->end_meal;
	pthread_mutex_unlock(&table->end_mtx);
	return (ended);
}
