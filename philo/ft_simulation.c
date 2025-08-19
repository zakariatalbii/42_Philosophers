/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:56:28 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/19 18:59:51 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eating(t_philo *philo)
{
	ft_l_meal_mx(philo, 1);
	ft_print_mx(philo, "is eating", 0);
	ft_n_meal_mx(philo, 1);
	ft_l_meal_mx(philo, 1);
	ft_sleep_ms(philo->data->t_eat);
}

static void	*ft_philo_r(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_l_meal_mx(philo, 1);
	if (philo->id % 2 == 0)
	{
		ft_print_mx(philo, "is thinking", 0);
		ft_sleep_ms(1);
	}
	while (!ft_end_mx(philo->data, 0))
	{
		pthread_mutex_lock(philo->r_fork);
		ft_print_mx(philo, "has taken a fork", 0);
		if (philo->data->n_philos == 1)
			break ;
		pthread_mutex_lock(philo->l_fork);
		ft_print_mx(philo, "has taken a fork", 0);
		ft_eating(philo);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		ft_print_mx(philo, "is sleeping", 0);
		ft_sleep_ms(philo->data->t_sleep);
		ft_print_mx(philo, "is thinking", 0);
	}
	return (NULL);
}

static void	*ft_monitor_r(void *arg)
{
	t_data	*data;
	int		count;
	int		v;

	data = (t_data *)arg;
	while (1)
	{
		v = -1;
		while (++v < data->n_philos)
			if (ft_timeval_ms() - ft_l_meal_mx(&data->philos[v], 0)
				>= data->t_die)
				return (ft_end_mx(data, 1),
					ft_print_mx(&data->philos[v], "died", 1), NULL);
		if (data->n_times_eat != -1)
		{
			v = -1;
			count = 0;
			while (++v < data->n_philos)
				if (ft_n_meal_mx(&data->philos[v], 0) >= data->n_times_eat
					&& ++count && count == data->n_philos)
					return (ft_end_mx(data, 1), NULL);
		}
	}
	return (NULL);
}

int	ft_simulation(t_data *data)
{
	t_philo	*philos;
	int		v;

	philos = data->philos;
	pthread_mutex_init(&data->print_mx, NULL);
	pthread_mutex_init(&data->end_mx, NULL);
	data->end = 0;
	data->start = ft_timeval_ms();
	v = -1;
	if (pthread_create(&data->m_th_id, NULL, ft_monitor_r, data))
		return (ft_putstr_fd("pthread_create failed\n", 2), -1);
	while (++v < data->n_philos)
		if (pthread_create(&philos[v].p_th_id, NULL, ft_philo_r, &philos[v]))
			return (ft_putstr_fd("pthread_create failed\n", 2), -1);
	v = -1;
	if (pthread_join(data->m_th_id, NULL))
		return (ft_putstr_fd("pthread_join failed\n", 2), -1);
	while (++v < data->n_philos)
		if (pthread_join(philos[v].p_th_id, NULL))
			return (ft_putstr_fd("pthread_join failed\n", 2), -1);
	return (0);
}
