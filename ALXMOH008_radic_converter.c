#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Mohamed Althaf Ali"
#define YEAR 2022

int main() 
{
    char *border = "****************************";
    printf("%s \n", border);
    printf("%s \n" , TITLE);
    printf("%s %s \n" , "Written by:", AUTHOR);
    printf("%s %d \n" , "Date:", YEAR);
    printf("%s", border);
    

    int num;
    printf("\n%s", "Enter a decimal number: ");
    scanf("%d", &num);
    
    while(num>0){
   
   printf("\n%s %d", "The decimal number you have entered is", num);
    int rad;
    printf("\n%s", "Enter a radix for the converter between 2 and 16: ");
    scanf("%d", &rad);
    printf("\n%s %d", "The radix you have entered is", rad);
    printf("\nThe log2 of the number is %.2f", log2(num));
    printf("\nThe integer result of the number divided by %d is %d",rad ,(num/rad));
    printf("\nThe remainder is %d",(num%rad));
    Dec2RadixI(num, rad);
    printf("\n%s", "Enter a decimal number: ");
    scanf("%d", &num);
    
    }
    
    printf("%s", "EXIT");
    
    return 0;
}

void Dec2RadixI(int decValue, int radValue){     //function declaration
    
    char convertArr[10000];          //define array to store what is converted
    convertArr[0] = '0';            //initialise array    
    char keyStore[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B','C', 'D', 'E', 'F'};       //define and store array of possible values to be used in conversion
    
    
    int index = 0;          //initialise counter
    while (decValue>0){          //do while user inputs positive number
        int thisVal;
        thisVal = decValue%radValue;      //get modulus
        convertArr[index] = keyStore[thisVal];       //find modulus val in store array and place in conversion array
        decValue = decValue/radValue; //devides dec num to use for next iteration
        index++;   //increment counter
        }
        
        
        
    char tempStore[index+1];                //temporary array used in reversing array as we look to analyse from right to left
    for (int x=0; x<index; x++){
         tempStore[x] = convertArr[index-x-1];   
         
    }
    
    
    for (int x=0; x<index; x++){
         convertArr[x] = tempStore[x];    //store back in conversion array
    }
    
      printf("\nThe radix-%d value is %s", radValue, convertArr);