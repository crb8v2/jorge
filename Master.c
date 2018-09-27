#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
void perror(const char *s);
void master();
void worker();
int detachandremove(int shmid, void *shmaddr);
#define SHMKEY 45887
#define BUFF_SZ sizeof (int)



void master()
{
	int i;
	char arg1[10];
//	char arg2[10];
//	char arg3[10];
	int k = 5;
	snprintf(arg1,10,"%d", k);
//	snprintf(arg2,10,"%s"," -n");
//	snprintf(arg3,10,"%d", 7);
	int shmid = shmget (SHMKEY, BUFF_SZ, 0666| IPC_CREAT );
	if (shmid == -1)
	{
		fprintf(stderr,"Parent:...Error in shmget ...\n");
		exit (1);
	}

	int * pint = ( int * )( shmat(shmid, NULL,0 ));
	int seconds;
	int milliseconds;
	for (i = 0;i < 5;i++)
	{
		if(fork() == 0) {
			execl("./Worker", "Worker", NULL);
		}
	}

}




int main ( int argc, char *argv[] ) {
	int flag = 0;
	char arg1[10];
	char arg2[10];
	char arg3[10];
	int i = 5;
	snprintf(arg1, 10, "%d", i);
	snprintf(arg2, 10, "%s", " -n");
	snprintf(arg3, 10, "%d", 7);
	pid_t childpid = 0;
	int n, opt;
	while ((opt = getopt(argc, argv, "hnp:")) != -1) {
		switch (opt) {
			case 'h':
				fprintf(stderr, "Enter number of process to run\n");
				exit(0);
				break;
			case 'n':
				n = atoi(argv[2]);
				flag = 1;
				break;

			case 'p':
				perror(argv[0]);
				break;
		}
	}

	if (flag == 1){
		master();
	}
}

//

///*
//void worker()
//{
//	int i;
//	char arg1[10];
//	//char arg2[10];
//	//char arg3[10];
//	int k = 5;
//	snprintf(arg1,10,"%d", k);
//	//snprintf(arg2,10,"%s"," -n");
//	//snprintf(arg3,10,"%d", 7);
//	 sleep (5);
//	 int shmid = shmget (SHMKEY, BUFF_SZ, 0666);
//   	 if ( shmid == -1 )
//   	 {
//		fprintf(stderr, "Child: ... Error in shmget ...");
//		exit ( 1 );
//   	 }
//
//         int * cint = ( int * )( shmat ( shmid, 0, 0 ) );
//		fprintf(stderr,"Parent: Written Val.: = ");
//   	 for ( i =0 ; i < 5; i++ )
//   	 {
//		sleep ( 1 );
//		execlp("./worker","./worker",arg1,(char *)NULL);
//		fprintf(stderr, "failed to exec worker!\n ");
//   	 }
//	if(detachandremove(shmid,cint)== -1){
//		perror("Failed to destroy shared memory segment");
//	}
//} */
int detachandremove(int shmid, void *shmaddr)
{
	int error = 0;
	if (shmdt(shmaddr) == -1)
		error = errno;
	if ((shmctl(shmid, IPC_RMID, NULL) == -1) && !error)
		error = errno;
	if(!error)
		return 0;
	errno = error;
	return -1;
}
