/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   111_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi <luigi@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:14 by luigi             #+#    #+#             */
/*   Updated: 2024/12/15 19:07:47 by luigi            ###   ########.fr       */
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

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

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

long long	ft_atoll(char *str, int i, long long res)
{
	int	sig;

	sig = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (LLONG_MAX / 10)
			|| (res == LLONG_MAX / 10 && (str[i] - '0') > (LLONG_MAX % 10)))
		{
			if (sig == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sig);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1e3 + time.tv_usec / 1e3);
}
