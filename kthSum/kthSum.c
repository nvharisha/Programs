
#include <stdio.h>





int main() {

 int input[][2]= {{5, 11}, {10, 15}, {12, 20}};
 int rows = sizeof(input)/sizeof(input[0]); 

 int count=0;
 int nthVal=7;
 int cntVal=input[0][0];
 while (count < nthVal) {
   for (int i=0; i < rows; i++) {
     printf("Row [%d]\n", i);
     if ((cntVal <=input[i][1]) && (cntVal == input[i][0])) {
       input[i][0]=cntVal+1;
       count++;
       printf("Array[%d][0]=%d\n",i,cntVal);
     }
   }
   cntVal++;
 }

 printf("nth[%d] value=%d\n", nthVal, cntVal-1);

}
