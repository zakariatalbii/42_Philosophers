/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:56:28 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/19 02:56:48 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_end_mx(t_data *data, int flag)
{
	int	end;

	pthread_mutex_lock(&data->end_mx);
	if (flag)
		data->end = flag;
	end = data->end;
	pthread_mutex_unlock(&data->end_mx);
	return (end);
}

void	ft_print_mx(t_philo *philo, char *stat, int died)
{
	pthread_mutex_lock(&philo->data->print_mx);
	if (died || !ft_end_mx(philo->data, 0))
		printf("%lld %d %s\n", ft_timestamp_ms(philo->data->start),
			philo->id, stat);
	pthread_mutex_unlock(&philo->data->print_mx);
}

t_time	ft_l_meal_mx(t_philo *philo, int flag)
{
	t_time	l_meal;

	pthread_mutex_lock(&philo->l_meal_mx);
	if (flag)
		philo->l_meal = ft_timeval_ms();
	l_meal = philo->l_meal;
	pthread_mutex_unlock(&philo->l_meal_mx);
	return (l_meal);
}
