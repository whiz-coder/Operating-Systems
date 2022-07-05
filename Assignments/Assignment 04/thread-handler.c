/* Includes */
#include <unistd.h> /* Symbolic Constants */
#include <sys/types.h> /* Primitive Sytem Data Types */
#include <errno.h> /*Errors*/
#include <stdio.h> /* Input/Output */
#include <stdlib.h> /* General Utilities */
#include <pthread.h> /*POSIX Threads*/
#include <string.h>  /*String Handling*/


#define NUM_RUNS 1000000

/* prototype for thread routine */
void handler ( void *ptr );

int static counter; /* shared variable */

int main()
{
    int i[2];
    pthread_t thread_a;
    pthread_t thread_b;

    i[0] = 0; /* argument to thread*/
    i[1] = 1;

    pthread_create ( &thread_a, NULL, (void *) &handler, (void *) &i[0]);
    pthread_create ( &thread_b, NULL, (void *) &handler, (void *) &i[1]);

    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);

    printf("----------------------------------------------\n");
    printf("Final counter value: %d\n" , counter);
    printf("Error:               %d\n" , (NUM_RUNS*2-counter));
    exit(0);

}

void handler (void *ptr)
{
    int iter = 0;
    int thread_num;
    thread_num = *((int *) ptr);
    printf("Starting thread: %d \n" , thread_num);

    while(iter < NUM_RUNS)
    {
         counter++;
        iter += 1;
    }

    printf("Thread %d, counter = %d \n", thread_num, counter);
    pthread_exit(0); /* exit thread */
}

