# context_switching
Write a program to create two threads and both the threads are sharing a common variable whose value is initialized by 2. First thread should increment the shared value by 1 and the other thread should decrement by 1. In order to avoid context switching and to attain consistency using Mutex Lock.  such that after every execution, the value of the shared variable should be consistent. 

For compiling 

gcc mutex.c -lpthread

For Execution

./a.out
