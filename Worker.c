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
//int detachandremove(int shmid, void *shmaddr);
#define SHMKEY 45887
#define BUFF_SZ sizeof (int)

int main(){
    printf("hello world\n");
}
//void worker()
//{
//
//     printf("hello");
//    int i;
//    char arg1[10];
//    //char arg2[10];
//    //char arg3[10];
//    int k = 5;
//    snprintf(arg1,10,"%d", k);
//    //snprintf(arg2,10,"%s"," -n");
//    //snprintf(arg3,10,"%d", 7);
//    sleep (5);
//    int shmid = shmget (SHMKEY, BUFF_SZ, 0666);
//    if ( shmid == -1 )
//    {
//        fprintf(stderr, "Child: ... Error in shmget ...");
//        exit ( 1 );
//    }
//
//    int * cint = ( int * )( shmat ( shmid, 0, 0 ) );
//    fprintf(stderr,"Parent: Written Val.: = ");
//    for ( i =0 ; i < 3; i++ )
//    {
//        sleep ( 1 );
//        fprintf(stderr, "failed to exec worker!\n ");
//    }
//	if(detachandremove(shmid,cint)== -1){
//		perror("Failed to destroy shared memory segment");
//	}
//}
