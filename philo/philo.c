#include "philo.h"

int main(int ac, char **av)
{
    t_data *data;
    t_philosopher *philosophers;
    int i;

    data = init_data(ac, av);
    philosophers = malloc(sizeof(t_philosopher) * data->num_philosophers);
    if (!philosophers)
        return 1;
    i = 0;
    while(i < data->num_philosophers)
    {
        philosophers[i].id = i + 1;
        philosophers[i].data = data;
        philosophers[i].last_meal_time = get_current_time();
        philosophers[i].times_eaten = 0;
        philosophers[i].dead = 0;
        pthread_create(&philosophers[i].thread, NULL, philo_task, &philosophers[i]);
        i++;
    }
    i = 0;
    while(i < data->num_philosophers)
    {
        pthread_join(philosophers[i].thread, NULL);
        if(philosophers[i].dead)
            break;
        i++;
    }

    free(philosophers);
    free(data->forks);
    free(data);
    return 0;
}
