#include <cs50.h>
#include <stdio.h>
#include <math.h>

float changeOwed;
int cents;
int totalCoins = 0;
//create an array containing these variables
int denomArr[] = {25, 10, 5, 1};
//get length of the denomArr
int denomArrLength = sizeof(denomArr)/sizeof(denomArr[0]);
int evenChange;


int main(void)
{
    //Check user provided positive change
    do {
        //Initial money paid
        changeOwed = get_float("Enter amount of change?");
        //convert userPaid to cents
        cents = round(changeOwed * 100);
        
        printf("User change: %f\n", changeOwed);
        
    }
    while (changeOwed < 0);
    
    //loop through denominations
    for (int i = 0; i < denomArrLength; i++)
    {
        //if denomination goes into cents with no remainder
        if (cents % denomArr[i] == 0) {
           
            // update totalCoins with amnt
            totalCoins += cents / denomArr[i];
            break;
        }
        
        // save how much of denomination goes into cents evenly
        evenChange = cents / denomArr[i];
        // add saved even amount to total coins
        totalCoins += evenChange;
        
        // subtract even division from cents
        cents = cents - evenChange * denomArr[i];
        
        printf("remaining change: %i\n", cents);
            
        //repeat steps for each denomination
         
    }
        
    printf("total coins needed: %i\n", totalCoins);
}
