/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:56:28 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/16 15:44:17 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mprint(t_philo *philos, char *stat)
{
	pthread_mutex_lock(&philos->tls->mxs.p_mx);
	printf("%lld %d %s\n", ft_timestamp_ms(&philos->tls->mxs.t_mx),
		philos->id, stat);
	pthread_mutex_unlock(&philos->tls->mxs.p_mx);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_sleep_ms(10);
	pthread_mutex_lock(philo->r_fork);
	ft_mprint(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	ft_mprint(philo, "has taken a fork");
	ft_mprint(philo, "is eating");
	ft_sleep_ms(philo->tls->inp.t_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	ft_mprint(philo, "is sleeping");
	ft_sleep_ms(philo->tls->inp.t_sleep);
	ft_mprint(philo, "is thinking");
	return (NULL);
}

void	ft_simulation(t_philo *philos, int n_philos)
{
	int	v;

	v = -1;
	while (++v < n_philos)
		pthread_create(&philos[v].thread_id, NULL, routine, &philos[v]);
	v = -1;
	while (++v < n_philos)
		pthread_join(philos[v].thread_id, NULL);
}
