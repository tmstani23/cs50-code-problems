#include <cs50.h>
#include <stdio.h>
#include <unistd.h>



int main(void) {
    // Check if height is between 1 and 8 and if not reprompt the user and store the variable
    int height; 
    do {
        height = get_int("Enter height between 1 and 8 (inclusive)");

        
    }
    while (height < 1 || height > 8);
  
    // Loop from 0 to input height
   for (int i = 0; i <= height -1; i++)
    {
        //Loop backwards starting at height
        for (int j = height - 1; j > i; j--) {
            //print a space until current iteration is > i iteration
            printf(" ");
        }
        //Loop forwards until current iteration reaches = i
       for (int k = 0; k <= i; k++) {
            //Print a hash for each iteration
            printf("#");
        }
        //Add a new line after each iteration
        printf("\n");
        
    } 
          
}
//Output should be (if height is 8):
//        #
//       ##
//      ###
//     ####
//    #####
//   ######
//  #######
// ########