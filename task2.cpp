// History command implemented:   syntax::  history (without any arguments)s // checked 





#include<iostream>
#include"cppheader.h"
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#include<string>
#include<cstring>
#include<list>

list<string> history;
//int count_parameters;


void history_call()
{
  list<string>:: iterator it;
  for(it=history.end();it!=history.begin();it--)
  cout<<*it<<endl;
  cout<<*it<<endl;
}







void parsing_pipe(char **argv,int count_pipes)
{
char *pi_jai[5][5];
  int j=0;
  

  int i=0;
  int k=0;
  while(argv[i]!=NULL)
  {
    
    
    if(strcmp(argv[i],"|")==0)
    {
     pi_jai[j][k]=NULL; 
      ++j;k=0;++i;
      continue;
    }
    pi_jai[j][k]=argv[i];
    
  
  // printf("%s\n",pi_jai[j][k]);
  ++i;++k;
  }
pi_jai[j][k]=NULL;  

  int fd[count_pipes][2];
  
for(k=0;k<count_pipes;k++)
{
if (pipe(fd[k]) < 0) 
        exit(1); 
}

for(k=0;k<=count_pipes;k++)
{
  if(k==0)
  {
   int pid;
   
    if(( pid=fork())==0)
    {
    dup2(fd[0][1],1);
    close(fd[0][1]);
    close(fd[0][0]);
    
               cout<<" loop 1"<<" ";
                 if(execvp(*pi_jai[k],pi_jai[k]) < 0)
                    {
                    printf("***Error: Command Not found\n");
                    exit(1);
                     }
                     cout<<" loop 1"<<" ";
                     close(fd[0][0]);
  
    }
    else
    {
      wait(NULL);
      close(fd[0][1]);
    //close(fd[0][0]);
     // exit(1);
    }
    
  }
  else if(k==count_pipes)
  {
    int pid;
   if((pid=fork())==0)
   {
   
    dup2(fd[k-1][0],0);
    close(fd[k-1][0]);//closed now
    close(fd[k-1][1]);
  
                    
                    
                    cout<<" loop 2"<<" ";
                    
                    if(execvp(*pi_jai[k],pi_jai[k])<0)
                    {
                      printf("***Error: Command Not found\n");
                    exit(1);

                    }
                    exit(1);
                    
                    
                    // cout<<" loop 2"<<" ";
                    // if(execvp(*pi_jai[k],pi_jai[k]) < 0)
                    //{
                    //printf("***Error: Command Not found\n");
                    //exit(1);
                     //}
                    //cout<<" loop 2"<<" ";*/

  
  }
  else
  {
    wait(NULL);
   //close(fd[k-1][0]); 
    close(fd[k-1][1]);//closedow
    //exit(1);
      
  }
  
  }
  else
  {

    int pid;
    if((pid=fork())==0)
   {
      dup2(fd[k][1],1);
    dup2(fd[k-1][0],0);

   close(fd[k-1][0]);
    close(fd[k][1]);
     
     
    
       cout<<" loop 3"<<" ";
    
                if(execvp(*pi_jai[k],pi_jai[k]) < 0)
                {
                printf("***Error: Command Not found\n");
                exit(1);
                 }

         // cout<<" loop 3"<<" ";
  }
  else
  {
    wait(NULL);
    //close(fd[k-1][1]);//close(fd[k-1][0]);
    close(fd[k][1]);
   //exit(1);
      
  }
  
  
}
}











}



















int  main()
{
    
    
  history.clear();
    char buff[1000];
char *argv[64];
int h=0;

    while(1)
{  
        
        promptcall();
        string str;
        getline(cin,str);
        history.push_back(str);// maintaining list for history
        int l=str.size();
        int i;
        for(i=0;i<l;i++)
        buff[i]=str[i];
        buff[i]='\0';
        
        jai(buff, argv);    
                     
        int count_pipes=0;
        for(int j=0;argv[j]!=NULL;j++)
        {
          if(*argv[j]=='|') ++count_pipes;
        }
        
        if(count_pipes)
        {
          //cout<<"pipe"<<count_pipes;
          parsing_pipe(argv,count_pipes);
          continue;
        }
        
        
        
        /*else
        {
          cout<<"no pipe";
        }*/
        
      
      
      //print_parameters(argv);

/*      for(int i=0;i<count_parameters;i++)
      printf("\t %s \n",*(argv+i));
*/
     
     
     
     
      
      
      
      
      
      




      //implementing history command
    
        if(strcmp(argv[0], "history")==0)
       {
         history_call();
         continue;
       }

       if(strcmp(argv[0],"cd")==0)
       {
         directory_ch(argv[1]);
         continue;
       }
      
      
      
      if(strcmp(argv[0], "exit") == 0) 
     { exit(0); }           
      
      jaiexecute(argv); 
     // free(temp);

      

}

return 0;
}
