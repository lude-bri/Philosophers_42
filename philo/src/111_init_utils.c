/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   111_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:14 by luigi             #+#    #+#             */
/*   Updated: 2024/12/04 16:46:39 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *nprt)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nprt[i] == '\n')
		return (0);
	while ((nprt[i] == 32) || (nprt[i] >= 9 && nprt[i] <= 13))
		i++;
	if (nprt[i] == '+' || nprt[i] == '-')
	{
		if (nprt[i] == '-')
			sign *= -1;
		i++;
	}
	while (nprt[i] >= 48 && nprt[i] <= 57)
	{
		result = (result * 10) + (nprt[i] - '0');
		i++;
	}
	return (result * sign);
}

