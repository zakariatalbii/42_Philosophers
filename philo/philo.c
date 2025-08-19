/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:51:06 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/19 18:46:17 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_philo_destroy(t_data *data)
{
	int	v;

	pthread_mutex_destroy(&data->print_mx);
	pthread_mutex_destroy(&data->end_mx);
	v = -1;
	while (++v < data->n_philos)
	{
		pthread_mutex_destroy(data->philos[v].r_fork);
		pthread_mutex_destroy(&data->philos[v].l_meal_mx);
		pthread_mutex_destroy(&data->philos[v].n_meal_mx);
	}
	free(data->philos);
	free(data->forks);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		exit_s;

	if (ft_inputs(&data, argc, argv) || ft_philos_init(&data))
		return (-1);
	exit_s = ft_simulation(&data);
	ft_philo_destroy(&data);
	return (exit_s);
}
