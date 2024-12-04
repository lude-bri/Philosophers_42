/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   110_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:26:07 by luigi             #+#    #+#             */
/*   Updated: 2024/12/04 16:47:32 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	build_philo_plus(char **av)
{
	(void)av;
}

void	build_philo(char **av)
{
	int		size;

	size = ft_atoi(av[1]);

}

void	init_philo(int ac, char **av)
{
	if (ac == 5)
		build_philo_plus(av);
	else
		build_philo(av);
}
