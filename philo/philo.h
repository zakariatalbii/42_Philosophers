/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:50:57 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/16 15:39:00 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef long long	t_time;

typedef struct s_tools
{
	struct s_inputs
	{
		int	n_philos;
		int	t_die;
		int	t_eat;
		int	t_sleep;
		int	n_times_eat;
	}	inp;
	struct s_mutexes
	{
		pthread_mutex_t	t_mx;
		pthread_mutex_t	p_mx;
	}	mxs;
}	t_tools;

typedef struct s_philo
{
	int				id;
	int				l_meal;
	pthread_t		thread_id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_tools			*tls;
}	t_philo;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
long	ft_atol(const char *str);

t_time	ft_timeval_ms(void);
t_time	ft_timestamp_ms(pthread_mutex_t *time_m);
void	ft_sleep_ms(unsigned int ms);

int		ft_inputs(t_tools *tools, int argc, char **argv);
int		ft_philos_init(t_philo **philos, pthread_mutex_t **forks,
			t_tools *tools);
void	ft_simulation(t_philo *philos, int n_philos);

#endif