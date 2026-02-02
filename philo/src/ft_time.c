/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:51:17 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/19 02:25:27 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	ft_timeval_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000LL);
}

t_time	ft_timestamp_ms(t_time start)
{
	return (ft_timeval_ms() - start);
}

void	ft_sleep_ms(unsigned int ms)
{
	t_time	time;

	time = ft_timeval_ms();
	while (ft_timeval_ms() - time < ms)
		usleep(500);
}
