#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock; 
int sharedCounter = 0;

void* incrementCounter(void* thread_id)
{
    pthread_mutex_lock(&lock);

    int id = *((int*)thread_id);
    sharedCounter++;
    printf("Thread %d incremented counter to %d\n", id, sharedCounter);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }
    pthread_create(&t1, NULL, incrementCounter, (void*)&id1);
    pthread_create(&t2, NULL, incrementCounter, (void*)&id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", sharedCounter);

    pthread_mutex_destroy(&lock);

    return 0;
}
