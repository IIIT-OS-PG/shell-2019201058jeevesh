
#include"header.h"
#include<stdio.h>


char *history[500];






void main()
{
    
    
    char buff[1000];
char *argv[64];
int h=0;

    while(1)
{  
        
        promptcall();
       
       gets(buff);
     jai(buff, argv);                     
      
     // printf("\t %s jai \t",*argv);
      
      
      
      char *temp=(char *)calloc(32,sizeof(char));
      strcpy(temp,buff);
      history[h]=temp;
      printf("\n %s",history[h]);
      printf("\n history demo :buff=%s %d %s %s",buff,h,history[0],history[1]);
      h++;
      
      
      




      //implementing history command
    
       //  if(strcmp(argv[0], "history")==0)
       // {printf("history called");
        // jaihistory(history,h);
         //continue;
       //}
      
      
      
      if(strcmp(argv[0], "exit") == 0) 
     { exit(0); }           
      
      jaiexecute(argv); 
      free(temp);

 

}
}
