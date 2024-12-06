/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   110_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:26:07 by luigi             #+#    #+#             */
/*   Updated: 2024/12/04 17:33:21 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	*creating_philos(void *data)
{
	(void)data;
	printf("A Philosopher is BORN!\n");
	sleep(3);
	printf("A Philosopher is TIRED!\n");
	return (NULL);
}

void	build_philo_plus(char **av, t_philo *philo)
{
	(void)av;
	(void)philo;
}

void	build_philo(char **av, t_philo *philo)
{
	int			size;
	int			i;

	size = ft_atoi(av[1]);
	philo->thread_id = malloc(sizeof(pthread_t) * size);
	if (size <= 200)
	{	
		i = 0;
		while (i++ < size)
			pthread_create(philo->thread_id + i, NULL, creating_philos, NULL);
		i = 0;
		while (i++ < size)
			pthread_join(philo->thread_id[i], NULL);
	}
}

void	init_philo(int ac, char **av, t_philo *philo, t_table *table)
{
	table->philo_number = ft_atol(av[1]);
	if (ac == 6)
		build_philo_plus(av, philo);
	else
		build_philo(av, philo);
}
