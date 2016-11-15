#include<stdio.h>
#include<stdlib.h>

#include "variable.h"

char ***array(char *filename)
{
 int i,j;
 
 FILE *fp=fopen(filename,"r");

 char ***temp1;
 
 temp1 = (char***)malloc(NUM_LISTS*sizeof(char**));

 for(i=0;i<NUM_LISTS;i++)
    {
     temp1[i] = (char**)malloc((NUM_ELEMENTS)*sizeof(char*));

     for(j=0;j<NUM_ELEMENTS;j++)
        temp1[i][j]=(char*)malloc(MAX_SIZE*sizeof(char));

    }
     
 for(i=0;i<NUM_LISTS;i++)
    {
	for(j=0;j<NUM_ELEMENTS;j++)
	   {
	    fscanf(fp,"%s",temp1[i][j]);
           }

             

    } 

 fclose(fp);
 return(temp1);
}
