#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // need to use a do while loop to check if height is between 1 and 8
    int height = get_int("height?");
    
    if (height >= 1 && height <=8) {
        // Iteratively double i
        for (int i = 0; i <= height -1; i++)
        {
            for(int j=0;j<=i;j++) {
               printf("#");
            }
            printf("\n");
            
        }
    }
    else {  
        
        height = get_int("Enter height between 1 and 8 (inclusive)");
    }
}