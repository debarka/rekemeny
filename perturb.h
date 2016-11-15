#include<time.h>
#include<math.h>

#include "variable.h"

void swap_elements(char *a, char *b)
{
 char dummy[MAX_SIZE];

 strcpy(dummy,a);
 strcpy(a,b);
 strcpy(b,dummy);

 return;

} 
 

void perturb(char **list, double temp, int j) // j = NUM_ELEMENTS
{

 double prob;

 prob =  PROB_UPPER - ((exp(-temp/SCALING_FACTOR))*(PROB_UPPER-PROB_LOWER));
 
 double dummy1,dummy2,dummy3,dummy4;

 unsigned long long int divisor;

 divisor = pow(10,1);   

 int i;
 
 for(i=0;i<NUM_ELEMENTS;i++)
    {
     dummy1=rand()%divisor;

     dummy2=dummy1/divisor;

     if(dummy2>=prob)       //element not to be perturbed
       continue;

     else                  //this element is to be perturbed
         {
          dummy3=rand()%divisor;

          dummy4=dummy3/divisor;

          if((dummy4>=0.5)&&(i!=NUM_ELEMENTS-1))  
             {
              //perturb right

              swap_elements(list[i],list[i+1]);  
             }
	  else if((dummy4<0.5)&&(i!=0))        
	         {
	          //perturb left

	          swap_elements(list[i],list[i-1]);
                 }               

           }   

      }
      
 return ;

}


