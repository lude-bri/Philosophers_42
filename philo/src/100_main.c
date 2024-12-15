/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:46:51 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 19:06:41 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//each philo is a thread
//each fork is a mutex

//the idea is set by number
//1. number of philosophers

//2. time_to_die (in milliseconds): if a philo didnt start eating 
//time_to_die milliseconds since the beginning of the last meal or
//the beginning of the simulation, they die.

//3. time_to_eat (in milliseconds): the time it takes for a philo to eat. 
//During that time, they will need to hold two forks

//4. time_to_sleep: the time a philo will spend sleeping

//5. number_of_times_each_philosopher_must_eat: if all philo have eating 
//at least number_of_times_each_philosopher_must_eat times, 
//the simulation stops.
// if not specified, the simulation stops when a philo dies.

int	main(int ac, char **av)
{
	t_table		table;

	if ((ac == 5) || (ac == 6))
	{
		memset(&table, 0, sizeof(t_table));
		init_table(av, &table);
		//when all philos are full or one died (otherwise it will be endless)
		// kill_philo();
	}
	else
		printf("Error: try n_of_philo time_to_die time_to_eat time_to_sleep\n");
}
