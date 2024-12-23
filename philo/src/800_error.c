/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   800_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:47:10 by luigi             #+#    #+#             */
/*   Updated: 2024/12/23 12:15:50 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_exit(char *error_msg, int error_no, t_table *table,
				int error_code)
{
	printf("%s\n", error_msg);
	exit(error_no);
	if (error_code)
		kill_philo(table, error_code);
}
