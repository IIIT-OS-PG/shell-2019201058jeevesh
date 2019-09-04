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


void history_call()
{
  list<string>:: iterator it;
  for(it=history.end();it!=history.begin();it--)
  cout<<*it<<endl;
  cout<<*it<<endl;
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
      
     
     
     
     
      
      
      
      
      
      




      //implementing history command
    
        if(strcmp(argv[0], "history")==0)
       {
         history_call();
         continue;
       }
      
      
      
      if(strcmp(argv[0], "exit") == 0) 
     { exit(0); }           
      
      jaiexecute(argv); 
     // free(temp);

      

}

return 0;
}
