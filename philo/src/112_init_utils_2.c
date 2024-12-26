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

//Validates and sanitizes a numeric string input.
//Ensures the input is a positive number and within allowed constraints
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
		error_exit("Error: only positive numbers allowed", STD_ERR, NULL, NONE);
	if (!is_digit(*str))
		error_exit("Error: it's not a correct digit", STD_ERR, NULL, NONE);
	if (len > 10)
		error_exit("Error: INT_MAX is the limit", STD_ERR, NULL, NONE);
	res = str;
	return (res);
}

//Convert a sanitized numeric argument to a long integer.
//Ensures the values does not exceed INT_MAX
int	ft_atol(const char *str)
{
	long	number;

	number = 0;
	str = sanity_check(str);
	while (is_digit(*str))
		number = (number * 10) + (*str++ - '0');
	if (number > INT_MAX)
		error_exit("Error: INT_MAX is the limit", STD_ERR, NULL, NONE);
	return (number);
}

//Retrieves the current time in milliseconds
//Combines seconds and microseconds for milliseconds precision
long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1e3 + time.tv_usec / 1e3);
}
