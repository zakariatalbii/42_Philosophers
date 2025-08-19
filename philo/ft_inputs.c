/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:51:37 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/18 16:37:21 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_error_message(int err)
{
	ft_putstr_fd("philo: invalid ", 2);
	if (err == 0)
		ft_putstr_fd("arguments count\n", 2);
	else if (err == 1)
		ft_putstr_fd("<number_of_philosophers>\n", 2);
	else if (err == 2)
		ft_putstr_fd("<time_to_die>\n", 2);
	else if (err == 3)
		ft_putstr_fd("<time_to_eat>\n", 2);
	else if (err == 4)
		ft_putstr_fd("<time_to_sleep>\n", 2);
	else if (err == 5)
		ft_putstr_fd("[number_of_times_each_philosopher_must_eat]\n", 2);
}

static int	ft_isnum(char *str)
{
	if (!*str)
		return (-1);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str)
		return (-1);
	return (0);
}

static int	ft_invalid_inputs(int argc, char **argv)
{
	int	v;

	v = 0;
	if (argc != 5 && argc != 6)
		return (ft_error_message(v), -1);
	while (argv[++v])
	{
		if (ft_isnum(argv[v])
			|| (v != 5 && !ft_atol(argv[v]))
			|| ft_atol(argv[v]) > INT_MAX + 0L)
			return (ft_error_message(v), -1);
	}
	return (0);
}

int	ft_inputs(t_data *data, int argc, char **argv)
{
	if (ft_invalid_inputs(argc, argv))
		return (-1);
	data->n_philos = (int)ft_atol(argv[1]);
	data->t_die = (int)ft_atol(argv[2]);
	data->t_eat = (int)ft_atol(argv[3]);
	data->t_sleep = (int)ft_atol(argv[4]);
	if (argc == 6)
		data->n_times_eat = (int)ft_atol(argv[5]);
	else
		data->n_times_eat = -1;
	return (0);
}
