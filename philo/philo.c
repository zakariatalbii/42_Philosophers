/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:51:06 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/18 18:53:50 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	pthread_mutex_init(&data.print_mx, NULL);
	pthread_mutex_init(&data.end_mx, NULL);
	data.end = 0;
	if (ft_inputs(&data, argc, argv) || ft_philos_init(&data))
		return (1);
	ft_simulation(&data);
	return (0);
}
