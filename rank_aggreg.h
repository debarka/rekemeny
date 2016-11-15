#include<math.h>

double *rank_aggreg(char **rand_list,int m) // m = NUM_ELEMENTS
{
 //FOLLOWING PART CALCULATES THE KENDALL DISTRIBUTION AND THE KENDALL'S TAU DISTANCE    

  int *ken_distri;

  ken_distri = (int*)malloc(NUM_LISTS*sizeof(int));
  
  int i,j,k,l;

  for(i=0;i<NUM_LISTS;i++)
     {
      ken_distri[i]=0;
     }

  double kendall=0;
  
  
  for(i=0;i<(NUM_ELEMENTS-1);i++)  
     {
      for(j=i+1;j<NUM_ELEMENTS;j++)      // j>i
         {
          for(k=0;k<NUM_LISTS;k++)
             {
              for(l=0;l<NUM_ELEMENTS;l++)
                 {
                  if(!strcmp(comb_list[k][l],rand_list[j]))
                    {
                      kendall +=1;
                      ken_distri[k] +=1;
                      break;
                    }
                  if(!strcmp(comb_list[k][l],rand_list[i]))
                    {
                      kendall +=0;
                      ken_distri[k] +=0;
                      break;
                    }
                 
                 }
                
             }
              
        }
          
    }   


//FOLLOWING PART CALCULATES THE SHANNON ENTROPY

 double S_Ent=0;
  
 for(i=0;i<NUM_LISTS;i++)
    {
      if((ken_distri[i])==0)
         S_Ent -= 0;
      else
         S_Ent -= ((ken_distri[i]/kendall)*log(ken_distri[i]/kendall))/log(BASE);         
    }

  double *feature_vector;

  feature_vector = (double*)malloc(3*sizeof(double));

  feature_vector[0]=kendall;
  feature_vector[1]=S_Ent;
  feature_vector[2]=kendall/S_Ent;

  free((int*)ken_distri);
  
  return(feature_vector);

}
