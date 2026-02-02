/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:51:28 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/19 18:26:35 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philos_init(t_data *data)
{
	int	v;

	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philos);
	if (data->philos)
		data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->philos || !data->forks)
		return (ft_putstr_fd("malloc: Cannot allocate memory\n", 2),
			free(data->philos), -1);
	v = -1;
	while (++v < data->n_philos)
	{
		data->philos[v].id = v + 1;
		data->philos[v].l_meal = ft_timeval_ms();
		data->philos[v].n_meal = 0;
		data->philos[v].data = data;
		data->philos[v].r_fork = &data->forks[v];
		if (v + 1 == data->n_philos)
			data->philos[v].l_fork = data->forks;
		else
			data->philos[v].l_fork = &data->forks[v + 1];
		pthread_mutex_init(&data->forks[v], NULL);
		pthread_mutex_init(&data->philos[v].l_meal_mx, NULL);
		pthread_mutex_init(&data->philos[v].n_meal_mx, NULL);
	}
	return (0);
}
