#include "philo.h"

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    int left_fork = philo->id - 1;
    int right_fork = philo->id % philo->num_philosophers;
    int i = 0;

    while (philo->num_times_to_eat == -1 || i < philo->num_times_to_eat) {
        usleep(philo->time_to_sleep * 1000);

        pthread_mutex_lock(&philo->print_mutex);
        printf("%ld %d is thinking\n", time(NULL), philo->id);
        pthread_mutex_unlock(&philo->print_mutex);

        pthread_mutex_lock(&philo->forks[left_fork]);
        
        pthread_mutex_lock(&philo->print_mutex);
        printf("%ld %d has taken a fork\n", time(NULL), philo->id);
        pthread_mutex_unlock(&philo->print_mutex);

        pthread_mutex_lock(&philo->forks[right_fork]);

        pthread_mutex_lock(&philo->print_mutex);
        printf("%ld %d has taken a fork\n", time(NULL), philo->id);
        pthread_mutex_unlock(&philo->print_mutex);

        pthread_mutex_lock(&philo->print_mutex);
        printf("%ld %d is eating\n", time(NULL), philo->id);
        pthread_mutex_unlock(&philo->print_mutex);

        usleep(philo->time_to_eat * 1000);

        pthread_mutex_unlock(&philo->forks[right_fork]);
        pthread_mutex_unlock(&philo->forks[left_fork]);

        i++;
    }

    return NULL;
}

int main(int argc, char **argv)
{
    if (argc != 5 && argc != 6)
    {
        write_error_msg("Usage: num_philosophers time_to_die time_to_eat time_to_sleep [num_times_to_eat]");
        return 1;
    }
    int i;

    i = 0;
    int num_philosophers = ft_atoi(argv[1]);
    int time_to_die = ft_atoi(argv[2]);
    int time_to_eat = ft_atoi(argv[3]);
    int time_to_sleep = ft_atoi(argv[4]);
    int num_times_to_eat ;
    if(argc == 6)
        num_times_to_eat = ft_atoi(argv[5]);
    else
        num_times_to_eat = -1;

    t_philo *philos = malloc(sizeof(t_philo) * num_philosophers);
    pthread_t *threads = malloc(sizeof(pthread_t) * num_philosophers);
    pthread_mutex_t *forks = malloc(sizeof(pthread_mutex_t) * num_philosophers);

    while(i < num_philosophers)
    {
        philos[i].id = i + 1;
        philos[i].num_philosophers = num_philosophers;
        philos[i].time_to_die = time_to_die;
        philos[i].time_to_eat = time_to_eat;
        philos[i].time_to_sleep = time_to_sleep;
        philos[i].num_times_to_eat = num_times_to_eat;
        philos[i].forks = forks;
        pthread_mutex_init(&philos[i].print_mutex, NULL);
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    i = 0;
    while(i < num_philosophers)
    {
        pthread_create(&threads[i], NULL, philo_routine, &philos[i]);
        i++;
    }
    i = 0;
    while(i < num_philosophers )
    {
        pthread_join(threads[i], NULL);
        i++;
    }

    i = 0;
    while( i < num_philosophers)
    {
        pthread_mutex_destroy(&forks[i]);
        pthread_mutex_destroy(&philos[i].print_mutex);
        i++;
    }

    free(philos);
    free(threads);
    free(forks);

    return 0;
}

