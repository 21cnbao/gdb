#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

struct thread_param
{
	char info;
	int num;
};

void* thread_fun(void* param)
{
	struct thread_param* p;
	
	p=(struct thread_param*)param;
	int i;

	printf("thread pid:%d, tid:%lu\n",getpid(), pthread_self());
	for(i=0;i<p->num;i++){

#if  0 /* change to #if 1 for debugging high cpu-loading issues */
		while(1);
#else
		sleep(1);

#if 0 /* change to #if 1 for debugging core dump */
		if (i==10){
			volatile *p=0;
			*p=0;
		}
#endif

#endif
		printf("%i: %c\n",i,p->info);
	}
		
	return NULL;
}

int main(void)
{
	pthread_t tid1,tid2;
	struct thread_param info1;
	struct thread_param info2;
	int ret;

	info1.info='T';
	info1.num=2000000;

	printf("main pid:%d, tid:%lu\n",getpid(), pthread_self());
	
	ret=pthread_create(&tid1,NULL,thread_fun,&info1);
	if(ret==-1){
		perror("cannot create new thread");
		return 1;
	}

	info2.info='S';
	info2.num=300000;
	
	ret=pthread_create(&tid2,NULL,thread_fun,&info2);
	if(ret==-1){
		perror("cannot create new thread");
		return 1;
	}

	if(pthread_join(tid1,NULL)!=0){
		perror("call pthread_join function fail");
		return 1;
	}

	if(pthread_join(tid2,NULL)!=0){
		perror("call pthread_join function fail");
		return 1;
	}

	return 0;
}	
