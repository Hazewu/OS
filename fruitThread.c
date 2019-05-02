#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

typedef int semaphore;
semaphore mutex=1;
int apple=0,orange=0;
void *father(void *p);
void *daughter(void *p);
void *son(void *p);
void put();

int main(void)
{
	pthread_t fa,da,so;
	pthread_create(&fa,NULL,father,NULL);
	pthread_create(&da,NULL,daughter,NULL);
	pthread_create(&so,NULL,son,NULL);
	sleep(100);
        return 0;
}

void *father(void *p)
{
	while(1)
	{
                while(mutex<=0);
                mutex--;

		if(apple<1&&orange<1)
		{
			put();
			printf("\n\t\t\t\tfather puts a piece of fruit.\n");
			printf("\t\t\t\tnow,orange:%d,apple:%d\n",orange,apple);
		}
               
                mutex++;
	}
        pthread_exit((void*)20);
}

void *daughter(void *p)
{
	while(1)
	{
		while(mutex<=0);
                mutex--;

		if(apple==1)
		{
			apple--;
			printf("\ndaughter ate an apple.\n");
			printf("now,orange:%d,apple:%d\n",orange,apple);
		}
		
                mutex++;
	}
        pthread_exit((void*)20);
}

void *son(void *p)
{
	while(1)
	{
		while(mutex<=0);
                mutex--;

		if(orange==1)
		{
			orange--;
			printf("\nson ate an orange.\n");
			printf("now,orange:%d,apple:%d",orange,apple);
		}

		mutex++;
	}
        pthread_exit((void*)20);
}

void put()
{
        sleep(2);
	srand((int)time(0));
	if((rand()%3)==0)
		apple++;
	else
		orange++;
}

	

