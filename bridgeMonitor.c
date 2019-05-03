#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define N 4
#define S 3
typedef int bridge;
bridge Nor=1,Sor=1,mid=2;
void crossN(int i)
{
	while(Nor<1||mid<1) ;
	Nor--;
	mid--;
	printf("passerby %d crosses the bridge North.\n",i);
	printf("passerby %d is on the middle of the bridge.\n",i);
	Nor++;
	sleep(2);
}

void crossS(int i)
{
	while(Sor<1||mid<1) ;
	Sor--;
	mid--;
	printf("passerby %d crosses the bridge Sorth.\n",i);
	printf("passerby %d is on the middle of the bridge.\n",i);
	Sor++;
	sleep(2);
}

void waitM(char ch,int i)
{
	if(ch=='N')
	{
		while(Sor<1) ;
		Sor--;
		mid++;
		printf("\t\t\t\t\tpasserby %d crosses the bridge Sorth.\n",i);
		printf("\t\t\t\t\t\t\t\t\t\tpasserby %d crosses the bridge all.\n",i);
		Sor++;
	}
	else
	{
		while(Nor<1) ;
		Nor--;
		mid++;
		printf("\t\t\t\t\tpasserby %d crosses the bridge North.\n",i);
		printf("\t\t\t\t\t\t\t\t\t\tpasserby %d crosses the bridge all.\n",i);
		Nor++;
	}
} 

void *passerbyN(void *p)
{
	int i=*(int*)p;
	while(1)
	{
		crossN(i);
		waitM('N',i);
	}
}
void *passerbyS(void *p)
{
	int i=*(int*)p;
	while(1)
	{
		crossS(i);
		waitM('S',i);
	}
}
int main(void)
{
	int i;
	pthread_t tid[N];
	for(i=0;i<N;i++)
	{
		pthread_create(&tid[i],NULL,passerbyN,(void *)(&i));
	    sleep(2);
	}
	for(i=N;i<S+N;i++)
	{
		pthread_create(&tid[i],NULL,passerbyS,(void *)(&i));
	    sleep(2);
	}
	for(i=0;i<N+S;i++)
		pthread_join(tid[i],NULL);
    return 0;
}
