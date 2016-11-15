#include<math.h>
#include<stdlib.h>
#include<stdio.h>

#include "variable.h"
#include "rank_aggreg.h"
#include "perturb.h"

void assign_array(char **x, char **y, int size)                  // y assigned to x  i.e., x=y
{
  int i;

  for(i=0;i<size;i++)
     {

      strcpy(x[i],y[i]);

     }

  return;
}


double rand_gen()
{

 double dummy1,dummy2;

 unsigned long long int divisor;

 divisor = pow(10,2);   // RECONSIDER

 dummy1=rand()%divisor;

 dummy2=dummy1/divisor;

 return(dummy2);

}

void anneal(char **rand_list, int k)  // INIT_SOL = rand_list   ;  k = NUM_ELEMENTS
{
 double temp;

 int i,j;

 double measure_former,measure_later,measure_difference;

 double current_min_score, current_min_score_buffer; //CMU

 char **former_rand_list,**intermediate_rand_list,**later_rand_list,**current_min_list;

 former_rand_list = (char**)malloc(NUM_ELEMENTS*sizeof(char*));

 intermediate_rand_list = (char**)malloc(NUM_ELEMENTS*sizeof(char*));
 
 later_rand_list = (char**)malloc(NUM_ELEMENTS*sizeof(char*));

 current_min_list = (char**)malloc(NUM_ELEMENTS*sizeof(char*));//CMU

 for(i=0;i<NUM_ELEMENTS;i++)
     {
      former_rand_list[i] = (char*)malloc(MAX_SIZE*sizeof(char));

      intermediate_rand_list[i] = (char*)malloc(MAX_SIZE*sizeof(char));
 
      later_rand_list[i] = (char*)malloc(MAX_SIZE*sizeof(char));     

      current_min_list[i] = (char*)malloc(MAX_SIZE*sizeof(char));//CMU
     }

 double *feature_vector;
 
 temp = INIT_TEMP; //temp_init
 
 assign_array(former_rand_list,rand_list,NUM_ELEMENTS); //s_init 

 assign_array(current_min_list,rand_list,NUM_ELEMENTS);//CMU

 feature_vector = rank_aggreg(current_min_list,NUM_ELEMENTS);//CMU

 current_min_score = feature_vector[2];//CMU
 
 FILE *fp,*fs;

 fp = fopen("results.txt","w");
 fs = fopen("scores.txt","w");
 
 while(temp>FINAL_TEMP)
      {
       for(i=0;i<SPEND_TIME;i++)    
          {
           feature_vector = rank_aggreg(former_rand_list,NUM_ELEMENTS);

           measure_former = feature_vector[2]; 
           
           assign_array(intermediate_rand_list,former_rand_list,NUM_ELEMENTS);

           perturb(intermediate_rand_list,temp,NUM_ELEMENTS);

           assign_array(later_rand_list,intermediate_rand_list,NUM_ELEMENTS);  //s'
  
           feature_vector = rank_aggreg(later_rand_list,NUM_ELEMENTS);

           measure_later =  feature_vector[2];

           measure_difference = measure_later-measure_former;

           if(measure_difference<=0)
             {
               assign_array(former_rand_list,later_rand_list,NUM_ELEMENTS);    

               fprintf(fp,"TOWARDS MINIMA : \t%f\t%f\t%f\n",feature_vector[0],feature_vector[1],feature_vector[2]);    
             }

           else if(rand_gen()<exp(-measure_difference/temp))  
                  {
                   assign_array(former_rand_list,later_rand_list,NUM_ELEMENTS);

                   fprintf(fp,"HILL CLIMBING : \t%f\t%f\t%f\n",feature_vector[0],feature_vector[1],feature_vector[2]);
                  }

           feature_vector = rank_aggreg(former_rand_list,NUM_ELEMENTS);

           measure_former = feature_vector[2];
           
           current_min_score_buffer = current_min_score;
           
           if(measure_former<current_min_score)
             {

              current_min_score = measure_former;

              assign_array(current_min_list,former_rand_list,NUM_ELEMENTS);

             }
         
            }
        fprintf(fs,"%f\n",measure_former);    
                
        if(current_min_score == current_min_score_buffer)
           temp *= alpha;

       }

    fprintf(fp,"\n\n\n\n\n");

    fprintf(fp,"\nMEASURE : %f\n\n\n\nLIST :\n\n",current_min_score);
    
    for(j=0;j<NUM_ELEMENTS;j++)
       fprintf(fp,"%s\n",current_min_list[j]);    

    fclose(fs);
    fclose(fp);       
 
 return;

}
