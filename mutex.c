/*Write a program to create two threads and both the threads are sharing a common variable whose value is initialized by 2.
First thread should increment the shared value by 1 and the other thread should decrement by 1. In order to avoid context switching and 
to attain consistency use Mutex Lock. Create a scenario such that after every execution, the value of the shared variable should be 
consistent.*/

#include<pthread.h>
#include<stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
  
void *fun1();
void *fun2();
pthread_mutex_t lock; 
pthread_mutex_t lock2; 
int shared=2;

void *inc()
{
 pthread_mutex_lock(&lock);
    int x;
    x=shared;
    x++;   
    sleep(1);  
    shared=x;  
 pthread_mutex_unlock(&lock); 
}
void *dec()
{
 pthread_mutex_lock(&lock);
    int y;
    y=shared;
    y--;  
    sleep(1);  
    shared=y; 
 pthread_mutex_unlock(&lock);
}

int main()
{
pthread_t thread_inc, thread_dec;
pthread_create(&thread_inc, NULL, inc, NULL);
pthread_create(&thread_dec, NULL, dec, NULL);
pthread_join(thread_inc, NULL);
pthread_join(thread_dec,NULL);
pthread_mutex_destroy(&lock);
printf("Final value of shared is %d\n",shared); 
}

