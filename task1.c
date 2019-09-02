
#include"header.h"
#include<stdio.h>











void main()
{
    
    
    char buff[1000];
char *argv[64];

    while(1)
{  
        
        promptcall();
       
       gets(buff);
      //fgets(buff,1024,stdin);
      printf("%s\n",buff);
      jai(buff, argv);                     
      if(strcmp(argv[0], "exit") == 0) 
      exit(0);            
      jaiexecute(argv); 

 

}
}