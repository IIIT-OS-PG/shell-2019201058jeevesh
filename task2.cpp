// History command implemented:   syntax::  history (without any arguments)s // checked 





#include<iostream>
#include"cppheader.h"
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#include<string>
#include<cstring>
#include<list>
#include<fcntl.h>

list<string> history;
//int count_parameters;


void history_call()
{
  list<string>:: iterator it;
  for(it=history.end();it!=history.begin();it--)
  cout<<*it<<endl;
  cout<<*it<<endl;
}

// REDIRECTION STARTED
//Redirection SUCCESS > 8/9/19

void redirection(char **argv)
{
    int r;
        //for( r=0;argv[r]!=NULL;r++)
        //printf("%s\n",argv[r]);

            char *pi_jai[2][5];
            int j=0;
  
            r=0;
            //int i=0;
            int k=0;
             while(argv[r]!=NULL)
            {
              if(strcmp(argv[r],">")==0)
                {
                pi_jai[j][k]=NULL; 
                ++j;k=0;++r;
                continue;
                }
                pi_jai[j][k]=argv[r];
    
  
               // printf("pi=%s ar=%s \n",pi_jai[j][k],argv[r]);
                 ++r;++k;
            }
                 pi_jai[j][k]=NULL;  

                   // printf(" %s \n",pi_jai[1][0]);
      
          int pid;
          if((pid=fork())==0)
          {
            int fd=open(pi_jai[1][0],O_CREAT | O_WRONLY,0755);
            dup2(fd,STDOUT_FILENO);
           // close(fd);
           if(execvp(*pi_jai[0],pi_jai[0]) < 0)
            {
                printf("***Error: REDIRECTION NOT SUCCESS:Command Not found\n");
                exit(1);
            }
          close(fd);
          
          }
          else
          {
            wait(NULL);
            
          }
          
  }


// REDIRECTION ENDED


//DOUBLE REDIRECTION STArTED



// REDIRECTION STARTED
//Redirection SUCCESS > 8/9/19

void doubleredirection(char **argv)
{
    int r;
        //for( r=0;argv[r]!=NULL;r++)
        //printf("%s\n",argv[r]);

            char *pi_jai[2][5];
            int j=0;
  
            r=0;
            //int i=0;
            int k=0;
             while(argv[r]!=NULL)
            {
              if(strcmp(argv[r],">>")==0)
                {
                pi_jai[j][k]=NULL; 
                ++j;k=0;++r;
                continue;
                }
                pi_jai[j][k]=argv[r];
    
  
               // printf("pi=%s ar=%s \n",pi_jai[j][k],argv[r]);
                 ++r;++k;
            }
                 pi_jai[j][k]=NULL;  

                   // printf(" %s \n",pi_jai[1][0]);
      
          int pid;
          if((pid=fork())==0)
          {
            int fd=open(pi_jai[1][0],O_APPEND|O_CREAT | O_WRONLY,755);
            dup2(fd,STDOUT_FILENO);
           // close(fd);
           if(execvp(*pi_jai[0],pi_jai[0]) < 0)
            {
                printf("***Error: DOUBLEREDIRECTION NOT SUCCESS:Command Not found\n");
                exit(1);
            }
          close(fd);
          
          }
          else
          {
            wait(NULL);
            
          }
          
  }


// DOUBLE REDIRECTION ENDED










//DOUBLEREDIRECTION EDED














// PIPE STARTED
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
    
    
  jairc();
  command_set();
  //printf("%s user \n",USER);
//printf("%s hostname \n",HOSTNAME);
//printf("%s home \n",HOME);
//printf("%s PS1 \n",PS1);
//printf("%s PATH\n",PATH);
  //cout<<" PATH "<<getenv("PATH");
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
        

      //IMPLEMENTING REDIRECTION

      /*
      int flag_redirection=0;
      for(int j=0;argv[j]!=NULL;j++)
        {
          if(*argv[j]=='>') 
          {
            
            /*if(*argv[j+1]=='>'){

              cout<<"\n DOUBLEREDIRECTION FOUND \n";
              doubleredirection(argv);
              break;

            }////////////
          cout<<"\n REDIRECTION FOUND \n";
          flag_redirection=1;
          break;
          }  

          //printf("%s%s",argv[0],argv[2]);
        }

        if(flag_redirection==1)
        {
          redirection(argv);
          continue;
        }
        
        */




      // ALL REDIRECTION WORK END ABOVE


      //DOUBLE REDIRECTION STARTED


      int flag_doubleredirection=0;
      for(int j=0;argv[j]!=NULL;j++)
        {
          if(*argv[j]=='>' && *argv[j+1]=='>') 
          {
          cout<<"\n doubleREDIRECTION FOUND \n";
          flag_doubleredirection=1;
          break;
          }  

          //printf("%s%s",argv[0],argv[2]);
        }

        if(flag_doubleredirection==1)
        {
          doubleredirection(argv);
          continue;
        }



      int flag_redirection=0;
      for(int j=0;argv[j]!=NULL;j++)
        {
          if(*argv[j]=='>') 
          {
            
            /*if(*argv[j+1]=='>'){

              cout<<"\n DOUBLEREDIRECTION FOUND \n";
              doubleredirection(argv);
              break;

            }////////////*/
          cout<<"\n REDIRECTION FOUND \n";
          flag_redirection=1;
          break;
          }  

          //printf("%s%s",argv[0],argv[2]);
        }

        if(flag_redirection==1)
        {
          redirection(argv);
          continue;
        }



      //DOUBLE REDIRECTION ENDED















        
        
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
