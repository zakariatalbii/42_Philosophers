/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:51:28 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/16 15:39:27 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philos_init(t_philo **philos, pthread_mutex_t **forks, t_tools *tls)
{
	int	v;

	*philos = (t_philo *)malloc(sizeof(t_philo) * tls->inp.n_philos);
	if (*philos)
		*forks = malloc(sizeof(pthread_mutex_t) * tls->inp.n_philos);
	if (!*philos || !*forks)
		return (ft_putstr_fd("malloc: Cannot allocate memory\n", 2),
			free(*philos), -1);
	v = -1;
	while (++v < tls->inp.n_philos)
	{
		(*philos)[v].id = v + 1;
		(*philos)[v].l_meal = 0;
		(*philos)[v].tls = tls;
		(*philos)[v].r_fork = &(*forks)[v];
		if (v + 1 == tls->inp.n_philos)
			(*philos)[v].l_fork = *forks;
		else
			(*philos)[v].l_fork = &(*forks)[v + 1];
		pthread_mutex_init(&(*forks)[v], NULL);
	}
	return (0);
}
