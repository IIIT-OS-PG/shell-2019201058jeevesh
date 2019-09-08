
//Book : many references taken from the Book.
//Advanced Programming in unix environment
//For more underdstanding Page No. is mentioned along side

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


char cwd[1000];
int count_parameters;

char *HOSTNAME;
char *USER;
char *PS1;
char *HOME;
char *PATH;
void command_set()
{
//char *PS1;

//char *HOME;
struct  passwd *pwd;
pwd=getpwuid(getuid());
HOME=pwd->pw_dir;



//char *PATH;

//char *USER;
char buffer[255];
getlogin_r(buffer,255);
USER=buffer;

//char *HOSTNAME;
char hostbuffer[100];
gethostname(hostbuffer,sizeof(hostbuffer));
HOSTNAME=hostbuffer;

}


//my rc file 




void jairc()
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

//PATH=bufferPath;

setenv("PATH",mybuffer,1);
//cout<<getenv("PATH");

}



//





















void directory_ch(char *args)
{
 
 
 chdir(args);
  /*  char *c="/home";
   // char *d="/home/jeevseh";

    if(args[0]=='\0')
    {
        chdir(c);
    }
    else if((strcmp(args,"~")==0)  || (strcmp(args,"~/")==0))
    {
        chdir(c);
    }
    /*else if(strcmp(args,".."))
    {
        char cwda[255];
        int i=0,j;
        getcwd(cwda,sizeof(cwda));
        for(i=1;i<sizeof(cwda);i++)
        {
            if(cwda[i]=='/')
            {
                cwda[i]='\0';
                break;
            }
        }
        chdir(cwda);


    }
    else if(strcmp(args,"/"))
    {
        char jai[255];
        jai[0]='\0';
        chdir(jai);

    }
    else
    {
            char path[255];
            char cwd[255];

            getcwd(cwd,sizeof(cwd));
            for(int i=0;i<sizeof(cwd);i++)
                path[i]=cwd[i];

            strcat(path,"/");
            strcat(path,args);
           // cout<<path;
            chdir(path);

    }
*/
}








int jai(char * l,char **arg)
{
     count_parameters=0;
    /*
    char *tryy=l;

    while(*tryy !='\0')
    {
        if(*tryy++ == '|')
        {
            parsing_pipe(l,arg);
            return 0;
        }
    }
    */
    
    while(*l != '\0')
    {
        while(*l == ' ' || *l == '\t' || *l == '\n' )
        *l++='\0';
        
        *arg=l;
        //printf("\t %s \n",*arg);
        ++count_parameters;
        ++arg;

        while(*l != ' ' && *l != '\t' && *l != '\n' && *l != '\0')
        l++;

    }
    *arg=NULL;
return 0;
}



void jaiexecute(char **argv)
{
    
    
    pid_t pid;
    int status;

    if((pid = fork())<0)
    {
        printf("****Error: forking child process failed\n");
        exit(1);
    }
    else if(pid == 0)
    {
        
        if(strcmp(argv[count_parameters-1],"&")==0)
            {
                argv[count_parameters-1]=NULL;

                 if(execvp(*argv,argv) < 0)
                    {
                    printf("***Error: Command Not found\n");
                    exit(1);
                     }
            
            
            
            }
    
            if(execvp(*argv,argv)<0){


               printf("***Error: Command Not found\n");
                  exit(1);

            }
        //else( execvp(*argv,argv) < 0)
        //{
            ///printf("***Error: Command Not found\n");
          //  exit(1);
        //}
    }
    else{
       
        while(wait(&status)!=pid);
    }
}











void promptcall()         //To display on prompt
{
    
    char buffer[255];
    getlogin_r(buffer,255);
    
    
    
    
    
    char displayprompt[1001];
    if(getcwd(cwd,sizeof(cwd))!=NULL)
    {
        strcpy(displayprompt,buffer);
        strcat(displayprompt,cwd);
        strcat(displayprompt,"$ ");
        PS1=displayprompt;
        printf("%s",displayprompt);
    }
    else
    {
            perror("getcwd() error"); // refer perror in Book 
    }
    
}