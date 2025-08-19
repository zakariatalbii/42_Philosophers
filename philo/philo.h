/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:50:57 by zatalbi           #+#    #+#             */
/*   Updated: 2025/08/19 01:34:39 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define _XOPEN_SOURCE 500
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef long long		t_time;
typedef struct s_philo	t_philo ;

typedef struct s_data
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_times_eat;
	pthread_t		m_th_id;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_time			start;
	int				end;
	pthread_mutex_t	end_mx;
	pthread_mutex_t	print_mx;
}	t_data;

struct s_philo
{
	int				id;
	pthread_t		p_th_id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_time			l_meal;
	int				n_meal;
	pthread_mutex_t	l_meal_mx;
	pthread_mutex_t	n_meal_mx;
	t_data			*data;
};

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
long	ft_atol(const char *str);

t_time	ft_timeval_ms(void);
t_time	ft_timestamp_ms(t_time start);
void	ft_sleep_ms(unsigned int ms);

int		ft_end_mx(t_data *data, int flag);
void	ft_print_mx(t_philo *philo, char *stat, int died);
t_time	ft_l_meal_mx(t_philo *philo, int flag);

int		ft_inputs(t_data *data, int argc, char **argv);
int		ft_philos_init(t_data *data);
void	ft_simulation(t_data *data);

#endif