#include <cs50.h>
#include <stdio.h>
#include <math.h>

float userPaid;
int cents;
int total = 0;
//create an array containing these variables
int quarters = 25;
int dimes = 10;
int nickels = 5;
int pennies = 1;

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
    
    //Check how many quarters go into userPaid with no remainder
    float change = cents / quarters; 
    
    //create function to cycle through coin denominations
    
        //create function to check if denomination goes into cents with no remainder
            //If no remainder update total with amnt of quarters
        
        //create function to subtract out remaining change
            //Update remaining change variable
   
         //repeat steps for each denomination
   
    
    
    printf("change: %f\n", change);
}
