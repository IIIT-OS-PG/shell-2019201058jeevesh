//       JEEVESH KATARIA  2019201058 
// History command implemented:   syntax::  history (without any arguments)s // checked 
//IMPLEMENT N pipelines
// REDIRECTIOn IMPLEMENTED >   >>
//support for alias command 
//bashrc file created
//support for INITIALIZING variables HOME,PATH,USER,HOSTNAME,PS1
//ASSOSIATION OF ~ WITH HOME VARIABLE
//LOOK OF PROMPT VIA PS1 TO BE HANDLED
//HANDLE SUPPORT FOR $$



#include<iostream>
#include"cppheader.h"
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#include<string>
#include<cstring>
#include<list>
#include<fcntl.h>
#include<unordered_map>
 unordered_map<string,string> um;
 //char *mapbuffer[20];
 //char mapbuffer2[255];
 char alb[10];
 char mapar[255];
 char albuff[255];


list<string> history;



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
  
                 ++r;++k;
            }
                 pi_jai[j][k]=NULL;  

         
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
  char mapar[255];
  char alb[10];
  char albuff[255];
  char mapbuffer2[255];
  //cout<<" PATH "<<getenv("PATH");
  history.clear();
  um.clear();
  char buff[1000];
  char *argv[64];
  char *mapbuffer[20];
  int h=0;
  signal(SIGINT, sigintHandler);
    while(1)
{  
         promptcall();
        string str;
        getline(cin,str);
        if(str[0]=='$' && str[1]=='$') {cout<<getppid();  continue;}
        if(str[0]=='$' && str[1]=='?') {cout<<ret;    continue;}
        history.push_back(str);// maintaining list for history
        int l=str.size();
        int i;
        for(i=0;i<l;i++)
        buff[i]=str[i];
        buff[i]='\0';


        char al[6]="alias";
        
        int x=strncmp(buff,al,5);
        if(x==0)
        {
           // char albuff[255];
            int j=0;
            for(int i=6;buff[i]!='\0';i++)
            {
                albuff[j]=buff[i];
                ++j;
            }
            albuff[j]='\0';
           
            int i;
            for( i=0;albuff[i]!='=';i++)
            {   alb[i]=albuff[i];}
            alb[i]='\0';
            string str1(alb);//first value
           
            i=i+1;
           
            int k=0;
            while(albuff[i]!='\0')
            {
                 mapar[k]=albuff[i];
                ++i;
                ++k;
            }
            mapar[k]='\0';
            string mapcommand(mapar);//second value
           
            //cout<<mapcommand;
             um[str1]=mapcommand;
            
          continue;
          }
      


      //alias

        jai(buff, argv);   



        //first check whether value exist in map or not
      string test(argv[0]);
        int mapflag=0;
      unordered_map<string,string> ::iterator itr;
      for(itr=um.begin();itr!=um.end();++itr)
      {
        //cout<<"iterate";
        string ss1=itr->first;
        //cout<<" itrrrrrrrr"<<sizeof(itr->first)<<" "<<itr->first[1]<<"h "<<test[1];
        if((test.compare(itr->first))==0)
        {
          mapflag=1;
          //cout<<"String matched , keep it up";
          //cout<<"second argument is:"<<itr->second<<" ";
          string strmap=itr->second;
          //cout<<"variable saved is : "<<strmap;
          int j=strmap.size();
          for(int i=0;strmap[i]!='\0';i++)
          mapbuffer2[i]=strmap[i];
          mapbuffer2[i]='\0';
          jai(mapbuffer2,mapbuffer);
         // for(int i=0;mapbuffer[i]!=NULL;i++)
          //printf("%s\n",mapbuffer[i]);
          //bccout<<"\n";
          jaiexecute(mapbuffer);
          break;
        
        }
        
      }
      if(mapflag==1) continue;


      
        char s2[6]="echo";
        int echo_flag=0;
        //pr();
        if((strcmp(argv[0],s2))==0)
        {
          //pr();
          //printf("INSERTED in ECHO");
          argv[1];
          //printf("%s",argv[1]);
          char temp1[6]="$USER";//printf("%s",temp1);
          char temp2[20]="$HOSTNAME";
          char temp3[10]="$HOME";
          char temp4[10]="$PATH";
          char temp5[10]="$PS1";
          if((strcmp(argv[1],temp1))==0)
          {printf("%s \n",USER);   echo_flag=1;}
          else if ((strcmp(argv[1],temp2))==0)
          {printf("%s \n",HOSTNAME);   echo_flag=1;}
          else if((strcmp(argv[1],temp3))==0)
          {printf("%s \n",HOME);   echo_flag=1;}
          else if((strcmp(argv[1],temp4))==0)
          {printf("%s \n",PATH);   echo_flag=1;}
          else if((strcmp(argv[1],temp5))==0)          
          {printf("%s \n",PS1);   echo_flag=1;}
        }
        if(echo_flag) continue;


        // N PIPE IMPLEMENTED
        
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

      
      int flag_redirection=0;
      for(int j=0;argv[j]!=NULL;j++)
        {
          
          string retest=argv[j];
          if(retest[0]=='>' && retest[1]=='>')
        {
              
              cout<<"\n DOUBLEREDIRECTION FOUND \n";
              doubleredirection(argv);
              break;

          }
          else if(*argv[j]=='>'){
          cout<<"\n REDIRECTION FOUND \n";
          flag_redirection=1;
          break;
          }  
        }
          
        

        if(flag_redirection==1)
        {
          redirection(argv);
          continue;
        }
        
        

     
     
  
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
