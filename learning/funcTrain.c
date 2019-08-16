#include <stdio.h>
#include <stdbool.h> 

// //returnType funcName(type arg1, type arg2)

//Initialize functions
float multFloats(float num1, float num2);
int addInts(int num1, int num2);
int validTriangle(int sideA, int sideB, int sideC);
   


int main(void) {
   printf("%f\n", multFloats(23.3, 32.6));
   printf("%i\n", addInts(23, 32));
   printf("Is it a valid triangle? %i\n", validTriangle(5, 5, 7));
}

float multFloats(float num1, float num2) {
    return num1 * num2;
}

int addInts(int num1, int num2) {
    return num1 + num2;
}

int validTriangle(int sideA, int sideB, int sideC) {
    //Check if each side is positive
    if (sideA <= 0 || sideB <= 0 || sideC <= 0) {
        return false;
    }
    //Check if the sum of any two sides is greater than the third
    else if (sideA + sideB <= sideC) {
        return false;
    }
    else if (sideB + sideC <= sideA) {
        return false;
    }
    else if (sideC + sideA <= sideB) {
        return false;
    }
    else {
        return true;
    }
}