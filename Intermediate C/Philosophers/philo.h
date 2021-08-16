#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

struct	s_rules;

typedef struct s_philo
{
	int					id;
	int					eat_count;
	int					lf_id;
	int					rf_id;
	long long			t_last_eat;
	struct s_rules		*rules;
	pthread_t			t_id;
}						t_philo;

typedef struct s_rules
{
	int					philo_num;
	int					death_time;
	int					eat_time;
	int					sleap_time;
	int					eat_num;
	int					died;
	int					eat_amount;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	t_philo				philo[250];
}						t_rules;

int			write_error(char *str);
int			which_error(int err);

int			ft_atoi(const char *str);

long long	timestamp(void);
long long	time_diff(long long past, long long pres);
void		action_print(t_rules *rules, int id, char *str);
void		philo_sleep(long long time, t_rules *rules);

int			init_all(t_rules *rules, char **argv);
int			init_mutex(t_rules *rules);
int			init_philos(t_rules *rules);

int			launch_philos(t_rules *rules);
void		*thread_f(void *void_philo);
void		philo_eats(t_philo *philo);
void		deat_checker(t_rules *rules, t_philo *philo);
void		exit_launcher(t_rules *rules, t_philo *philo);

#endif
