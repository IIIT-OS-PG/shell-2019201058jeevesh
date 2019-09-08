//#include<iostream>
#include<string.h>
#include<cstring>
#include<pwd.h>
//#include<stdin>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h> //page 14 Book
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
using namespace std;

int main()
{


int fd=open("/home/jeevesh/Desktop/os_iiith/Assignment1/jairc.txt",O_RDONLY);
char bufferPath[200];
int countChar = read(fd, bufferPath, 200);
bufferPath[countChar] = '\0';
//printf(" eeee  %d  %s",fd,bufferPath);
close(fd);
char mybuffer[200];
int j=0;



//printf("%lu\n",strlen(bufferPath));

//string r=bufferPath.substr(5,92);

for(int i=8;i<=countChar;i++,j++)
{mybuffer[j]=bufferPath[i];
bufferPath[i]='\0';}

//cout<<mybuffer;

setenv("PATH",mybuffer,200);



char *PS1;

char *HOME;
struct  passwd *pwd;
pwd=getpwuid(getuid());
HOME=pwd->pw_dir;



//char *PATH;

char *USER;
char buffer[255];
getlogin_r(buffer,255);
USER=buffer;


char *HOSTNAME;
char hostbuffer[100];
gethostname(hostbuffer,sizeof(hostbuffer));
HOSTNAME=hostbuffer;

printf("%s user",USER);
printf("%s hostname",HOSTNAME);
printf("%s home",HOME);
printf("%s user",USER);



setenv("PATH",mybuffer,200);
//cout<<getenv("PATH");

}