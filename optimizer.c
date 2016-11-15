#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "variable.h"
#include "array.h"
#include "simulated_annealing.h"

void shift_array_left(int i, char **list, int elements)
{
 int j;

 for(j=i+1;j<elements;j++)
    {
     strcpy(list[j-1],list[j]);
    } 

 return;

}

void schuffle(char **list)
{
 char **rand_list,**list_copy;

 rand_list = (char**)malloc(NUM_ELEMENTS*sizeof(char*)); 

 list_copy = (char**)malloc(NUM_ELEMENTS*sizeof(char*));

 int i;
 
 for(i=0;i<NUM_ELEMENTS;i++)
     {
      rand_list[i] = (char*)malloc(MAX_SIZE*sizeof(char));

      list_copy[i] = (char*)malloc(MAX_SIZE*sizeof(char));
     }
 
 assign_array(list_copy,list,NUM_ELEMENTS);
 
 int index;

 int size = NUM_ELEMENTS;
 
 for(i=0;i<NUM_ELEMENTS;i++)
    {

     index = rand()%size;

     strcpy(rand_list[i],list_copy[index]);

     shift_array_left(index,list_copy,size);

     size--;

    }


 assign_array(list,rand_list,NUM_ELEMENTS);
 
 return;

}

int main()
{
 clock_t start = clock();
 
 comb_list = (char***)malloc(NUM_LISTS*sizeof(char**));

 int i,j;
 
 for(i=0;i<NUM_LISTS;i++)
    {
     comb_list[i]=(char**)malloc(NUM_ELEMENTS*sizeof(char*));

     for(j=0;j<NUM_ELEMENTS;j++)
        comb_list[i][j]=(char*)malloc(MAX_SIZE*sizeof(char));
    }

  
  comb_list = array("input.txt"); 

  char **rand_list;

  int list_num,element;

  rand_list = (char**)malloc(NUM_ELEMENTS*sizeof(char*));  

  for(i=0;i<NUM_ELEMENTS;i++)
     {
      rand_list[i] = (char*)malloc(MAX_SIZE*sizeof(char));

      rand_list[i] = comb_list[0][i];
     }
 
  printf("RANKING PERFORMED ON LIST :-\n");

  srand(time(NULL));

  schuffle(rand_list);

  for(i=0;i<NUM_ELEMENTS;i++)
     {
      
       printf("%s\n",rand_list[i]);

     }

  srand(time(NULL));
  
  anneal(rand_list,NUM_ELEMENTS);

  printf("Took %f seconds\n", ((double)clock()-start)/CLOCKS_PER_SEC);
  
  return 0;

}
