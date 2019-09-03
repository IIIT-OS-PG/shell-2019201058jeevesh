







#include<iostream>
#include<bits/stdc++.h>
#include"header.h"
//#include"cppheader.h"
#include<stdio.h>



using namespace std;












int main()
{
    
    
    
         
char buff[1000];
char *argv[64];
    while(1)
{  
     

     
     
     string in;
      //promptcall();
      getline(cin,in);
      stringstream  s(in);
      string word;
      //char **arg;//=new (char*)[64];
      int i=0;
      while(s >> word)
      {
        arg[i]=(char*)malloc(word.length()*sizeof(char));
        arg[i++]=(char*)word;
      }
      arg[i]=NULL;
      
      //cout<<in;
      
      
      //fgets(buff,512,stdin);
      //printf("%s\n",buff);
      //if(buff[0]);
         // jai(buff,argv);
      //if(strcmp(argv[0],"exit")==0)
        //exit(0);
       //jaiexecute(argv); 

}
}