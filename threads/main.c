#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    int *num = (int *)(arg);
    printf("The number is %d.\n",*num);
    usleep(10000);
    printf("hi\n");
    return NULL;
}

void *thread2_function(void *arg)
{
    printf ("Thread 2 is running.\n");
    return NULL;
}


int main()
{
    pthread_t thread1;
    pthread_t thread2;
    int value_1 = 2;
    int value_2 = 4;

    pthread_create(&thread1,NULL,thread_function,(void *) &value_1);
    pthread_create(&thread2,NULL,thread_function,(void *) &value_2);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    return 0;
}