/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   112_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:14:21 by luigi             #+#    #+#             */
/*   Updated: 2024/12/23 12:14:49 by luigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

const char	*sanity_check(const char *str)
{
	int			len;
	const char	*res;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Error: only positive numbers allowed", 2, NULL, 0);
	if (!is_digit(*str))
		error_exit("Error: it's not a correct digit", 2, NULL, 0);
	if (len > 10)
		error_exit("Error: INT_MAX is the limit", 2, NULL, 0);
	res = str;
	return (res);
}

int	ft_atol(const char *str)
{
	long	number;

	number = 0;
	str = sanity_check(str);
	while (is_digit(*str))
		number = (number * 10) + (*str++ - '0');
	if (number > INT_MAX)
		error_exit("Error: INT_MAX is the limit", 2, NULL, 0);
	return (number);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1e3 + time.tv_usec / 1e3);
}
