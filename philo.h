/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:50:36 by naanapa           #+#    #+#             */
/*   Updated: 2024/07/09 14:21:56 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philosopher
{
	u_int64_t		id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	u_int64_t		t_last_meal;
	struct s_rules	*rules;
	pthread_t		thread_id;
}					t_philosopher;

typedef struct s_rules
{
	int				nb_philo;
	u_int64_t		time_death;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				all_ate;
	int				died;
	u_int64_t		first_timestamp;
	pthread_mutex_t	t_last_meal_check;
	pthread_mutex_t	x_ate_check;
	pthread_mutex_t	die_check;
	pthread_mutex_t	died_check;
	pthread_mutex_t	all_ate_check;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
}					t_rules;

/*
** ----- utils2.c -----
*/

int					write_error(char *str);
void				eat_control(t_rules *r, t_philosopher *p);
void				ft_free(t_rules *rules);
void				action_print(t_rules *rules, int id, char *string);
void				philo_eats(t_philosopher *philo);
/*
** ----- init.c -----
*/

int					parse(t_rules *rules, char **argv);
int					init_philosophers(t_rules *rules);
int					init_mutex(t_rules *rules);

/*
** ----- utils.c -----
*/

int					ft_atoi(const char *str);
u_int64_t			timestamp(void);
u_int64_t			time_diff(u_int64_t past, u_int64_t pres);
void				smart_sleep(u_int64_t time, t_rules *rules);

/*
** ----- launcher.c -----
*/

int					launcher(t_rules *rules);
void				exit_launcher(t_rules *rules, t_philosopher *philos);

int					destroy_mutex(t_rules *rules);
void				chose_mutex(t_rules *rules, int x);
void				death_checker(t_rules *r, t_philosopher *p, int i, int j);
#endif
