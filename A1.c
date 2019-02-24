#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int tree(int h, int c,char *arg)
{


char ht[10]; /* Used for converting the height(int) to string for exec*/
char cn[10]; /* Used for converting the child(int) to string for exec*/

int i;    

int ret;    /* returning status of the exec()*/

int wpid,status;    /* For wait return status*/

pid_t pid;   /* Procces variable*/

if(h>1)
{
for(i=0;i<c;i++)
{
pid = fork();   /* Fork initialization*/

if(pid>0)
{
while (wpid == (wait(&status))>0);	
continue;
}

else{

if(pid==0)
{

h--;

sprintf(ht,"%d",h); /* Converting int to string*/
sprintf(cn,"%d",c);  /* Converting int to string*/

char *args[]={arg,ht,cn,NULL}; /* args[] for passing into exec()*/

ret = execvp(arg,args);

printf("\n %d",ret);

if (ret == -1)
{
printf("\n Exec() Error" );
}

break;
}
else
{
printf("Fork error");
exit(1);
}
}
}
}
printf("\n(%d)Terminating at height : %d \n",getpid(),h);

return 0;
}



int main(int argc, char *argv[])
{


int c,h; /* No of children and height of tree*/


if(argc>1)
{
h = atoi(argv[1]); /* including arguments in height and child*/
c = atoi(argv[2]);/* including arguments in height and child*/	
}


    printf("\n (%d) : process starting\n", getpid());
    printf("(%d) : parent's id = (%d)\n", getpid(), getppid());
    printf("(%d) : height in the tree = %d\n", getpid(), h);
    printf("(%d) : Creating %d child at height %d\n", getpid(), c, h-1);

tree(h,c,argv[0]); 

}
