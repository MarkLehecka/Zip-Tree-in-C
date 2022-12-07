
#include <stdio.h>
#include <stdlib.h>




int randomRank(){
    int count = 0;
    int coin = 0;
    while(coin != 1){
        coin = rand()/(RAND_MAX/3); 
        count++;

    }
    return count;

}



int main(void){
    srand(1);
   int countNum = 0;

   for(int i = 0; i < 15; i++){
    countNum = randomRank();

    printf("Here is how many times: %d\n", countNum);
   }

   return 0; 

}