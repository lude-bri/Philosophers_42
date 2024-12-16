/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   210_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:49:17 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 20:10:10 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	eat(t_table *table, t_philo *philo);

void	philo_do(t_philo *philo, long long time, char *action)
{
	long	start;

	start = get_time();
	pthread_mutex_lock(&philo->table->print_mtx);
	if (ended_meal(philo->table))
	{
		pthread_mutex_unlock(&philo->table->print_mtx);
		return ;
	}
	if (*action)
		printf("%lld %d %s\n", get_time() - philo->table->start_meal, philo->id, action);
	pthread_mutex_unlock(&philo->table->print_mtx);
	if (time > 0)
		while (get_time() - start < time)
			usleep(100);
}

void	philo_eat(t_philo *philo)
{
	t_table		*table;

	table = philo->table;
	if (table->nbr_of_philos % 2)
	{
		pthread_mutex_lock(&table->forks[philo->right_fork]);
		pthread_mutex_lock(&table->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&table->forks[philo->left_fork]);
		pthread_mutex_lock(&table->forks[philo->right_fork]);
	}
	eat(table, philo);
}

static void	eat(t_table *table, t_philo *philo)
{
	philo_do(philo, 0, "has taken a fork");
	philo_do(philo, 0, "has taken a fork");
	philo_do(philo, table->time_to_eat, "is eating");
	pthread_mutex_lock(&table->eat_mtx);
	philo->last_meal_time = get_time();
	philo->meals_counter += 1;
	pthread_mutex_unlock(&table->eat_mtx);
	pthread_mutex_unlock(&table->forks[philo->left_fork]);
	pthread_mutex_unlock(&table->forks[philo->right_fork]);
}

void	philo_sleep(t_philo *philo, t_table *table)
{
	philo_do(philo, table->time_to_sleep, "is sleeping");
	if (table->nbr_of_philos % 2)
		philo_do(philo, table->time_to_eat, "is thinking");
	else
		philo_do(philo, (table->time_to_die
				- (table->time_to_eat + table->time_to_sleep
					+ table->nbr_of_philos)), "is thinking");
}
