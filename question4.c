#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum1, sum2; /* this data is shared by the thread(s) */

void *runner(void *param); /* the thread */
void *runner2(void *param);
int main(int argc, char *argv[])
{
pthread_t tid[2]; /* the thread identifier */
pthread_attr_t attr; /* set of attributes for the thread */

if (argc != 2) {
	fprintf(stderr,"usage: a.out <integer value>\n");
	/*exit(1);*/
	return -1;
}

if (atoi(argv[1]) < 0) {
	fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
	/*exit(1);*/
	return -1;
}

/* get the default attributes */
pthread_attr_init(&attr);

/* create the thread */
for (int i =0; i < 2; i++)
{
  
}
pthread_create(&tid[0],&attr,runner,argv[1]);
pthread_create(&tid[1],&attr,runner2,argv[1]);


/* now wait for the thread to exit */

  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);


printf("sum thread 1 = %d\n",sum1);
printf("sum thread 2 = %d\n",sum2);
printf("sum  = %d\n",sum1 + sum2);
}

/**
 * The thread will begin control in this function
 */
void *runner(void *param) 
{
int i, upper = atoi(param);
sum1 = 0;

	if (upper > 0) {
		for (i = 1; i <= upper/2; i++)
			sum1 += i;
	}

	pthread_exit(0);
}
void *runner2(void *param) 
{
int i, upper = atoi(param);
sum2 = 0;

	if (upper > 0) {
		for (i = upper/2+1; i <= upper; i++)
			sum2 += i;
	}

	pthread_exit(0);
}