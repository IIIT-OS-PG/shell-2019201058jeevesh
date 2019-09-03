#include<iostream>
#include"cppheader.h"
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#include<string>
#include<cstring>


char *history[500];






int  main()
{
    
    
  //  string buff;
    char buff[1000];
char *argv[64];
int h=0;

    while(1)
{  
        
        promptcall();
        string str;
        getline(cin,str);
        int l=str.size();
        int i;
        for(i=0;i<l;i++)
        buff[i]=str[i];
        buff[i]='\0';
        
      //cin.get(buff);
       //fgets(buff);
     jai(buff, argv);                     
      
     // printf("\t %s jai \t",*argv);
      
      
      
      //printf("\n %s",history[h]);
      //printf("\n history demo :buff=%s %d %s %s",buff,h,history[0],history[1]);
      
      
      
      




      //implementing history command
    
       //  if(strcmp(argv[0], "history")==0)
       // {printf("history called");
        // jaihistory(history,h);
         //continue;
       //}
      
      
      
      if(strcmp(argv[0], "exit") == 0) 
     { exit(0); }           
      
      jaiexecute(argv); 
     // free(temp);

 

}
return 0;
}
