/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   110_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:26:07 by luigi             #+#    #+#             */
/*   Updated: 2024/12/04 17:09:46 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	build_philo_plus(char **av, t_philo *philo)
{
	(void)av;
}

void	build_philo(char **av, t_philo *philo)
{
	int		size;

	size = ft_atoi(av[1]);
	while (size--)
	{
		pthread_create();
	}
}

void	init_philo(int ac, char **av, t_philo *philo)
{
	if (ac == 5)
		build_philo_plus(av, philo);
	else
		build_philo(av, philo);
}
