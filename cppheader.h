
//Book : many references taken from the Book.
//Advanced Programming in unix environment
//For more underdstanding Page No. is mentioned along side

//#include<iostream>
#include<string.h>
#include<cstring>
//#include<stdin>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h> //page 14 Book
#include<unistd.h>
#include<stdio.h>
using namespace std;


char cwd[1000];







int jai(char * l,char **arg)
{
    while(*l != '\0')
    {
        while(*l == ' ' || *l == '\t' || *l == '\n' )
        *l++='\0';
        
        *arg=l;
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
        if( execvp(*argv,argv) < 0)
        {
            printf("***Error: Command Not found\n");
            exit(1);
        }
    }
    else{
        while(wait(&status)!=pid);
    }
}











void promptcall()         //To display on prompt
{
    char displayprompt[1001];
    if(getcwd(cwd,sizeof(cwd))!=NULL)
    {
        strcpy(displayprompt,"Jeevesh:");
        strcat(displayprompt,cwd);
        strcat(displayprompt,"$ ");
        printf("%s",displayprompt);
    }
    else
    {
            perror("getcwd() error"); // refer perror in Book 
    }
    
}