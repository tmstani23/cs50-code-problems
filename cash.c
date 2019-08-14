#include <cs50.h>
#include <stdio.h>
#include <math.h>

float userPaid;
int cents;
int total = 0;
//create an array containing these variables
int denomArr[] = {25, 10, 5, 1};
int denomArrLength = sizeof(denomArr)/sizeof(denomArr[0]);
float remainingChange;


int main(void)
{
    //Check user provided positive change
    do {
        //Initial money paid
        userPaid = get_float("How much do you pay?");
        //convert userPaid to cents
        cents = round(userPaid * 100);
        
        printf("User paid: %f\n", userPaid);
        
    }
    while (userPaid < 0);
    
    
    
    //loop through denominations
    for (int i = 0; i < denomArrLength; i++)
    {
        //if denomination goes into cents with no remainder
        if (cents % denomArr[0] == 0) {
            printf("No remainder\n");
            // Check how many quarters go into userPaid with no remainder
            // If no remainder update total with amnt of quarters
            total = cents / denomArr[0];
        }
        
            //float change = cents / quarters; 
            
        
        // subtract out remaining change
        remainingChange = cents / denomArr[i];
        printf("remaining change: %f\n", remainingChange);
            //Update remaining change variable
   
         //repeat steps for each denomination
        
        
    }
        
    printf("total coins needed: %i\n", total);
}
