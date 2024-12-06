/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   111_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:14 by luigi             #+#    #+#             */
/*   Updated: 2024/12/04 17:17:39 by luigi            ###   ########.fr       */
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

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || (c == 32));
}

char	sanity_check(char *str)
{
	//check negatives
	//check if number is legit
	//check for INT_MAX
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit()
	while (*str)
		len++;
	if (len > 10)
		return (NULL);
}

int	ft_atol(const char *str)
{
	long	number;

	number = 0;
	str = sanity_check(str);
	return (number);
}
