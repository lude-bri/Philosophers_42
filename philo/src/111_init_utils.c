/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   111_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:14 by luigi             #+#    #+#             */
/*   Updated: 2024/12/23 12:14:50 by luigi            ###   ########.fr       */
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
	nprt = sanity_check(nprt);
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

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || (c == 32));
}

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
