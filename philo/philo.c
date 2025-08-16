/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:51:06 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/16 15:38:50 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_tools			tls;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	pthread_mutex_init(&tls.mxs.t_mx, NULL);
	pthread_mutex_init(&tls.mxs.p_mx, NULL);
	if (ft_inputs(&tls, argc, argv) || ft_philos_init(&philos, &forks, &tls))
		return (1);
	ft_simulation(philos, tls.inp.n_philos);
	return (0);
}
