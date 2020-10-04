#include <stdio.h>
#include <math.h>

/*
NAME: Patrick Tsai
CLASS: CSE 215 MWF 12:30 PM
DATE DUE: 3/09/2020 11:59 PM
ASSIGNMENT: PA2

SYNOPSIS - This program test's the Goldbach Conjecture. The user enters an even number (a start number), then the user enters another number, which is how many more even numbers to display. The program then displays every even number along with 2 prime numbers that sum to the even number displayed.
*/

void primeTime(int, int);

int main () {
  char usrIn[120];
  int strt, hwMny;

  printf("Enter a starting integer (even integer): ");
  fgets(usrIn,120,stdin);
  sscanf(usrIn,"%d",&strt);


  printf("Enter how many numbers to test (positive integer): ");
  fgets(usrIn,120,stdin);
  sscanf(usrIn,"%d",&hwMny);

  primeTime(strt,(hwMny-1));

return 0;
}

void primeTime(int strt, int hwMny) {
  int i=strt;
  int e=strt+(2*hwMny);
  int flag=0;
  int flag2=0;
  int p=3;

  while(i<=e) {
    int divisor=2;
    int test=i-p;

// testing the sart NUM minus the primes
    while (divisor<=(test/2)) {  // testing the resultant number [test] to see if it is prime
      if(test%divisor==0) {      // if test is divisible then it sets a flag
        flag=1;                  // which will initialize the section that searches for the 
        break;                   // next prime to test on the NUM
      }
      else {
        divisor++;
      }
    }

// PRINT OUT AND SET NEXT NUM
    if (flag==0) {                // if the test number passes through all the divisors
      int testPlusP=(test+p);     // then it is prime
      if (i==testPlusP) {         // if test and the initial prime equal the NUM in question then it prints out - sets the next NUM and resets p to 3
        printf("%d =  %3d + %8d\n",i,p,test);
        i=(i+2);              
        p=3;
      }
      else{                       // else we set the flag to 1 to search for the next prime
        flag=1;
      }
    }

// NEXT PRIME SECTION
    while(flag==1) {              // increment p and test if it's prime 
      p++;
      divisor=2;
      while (divisor<=(p/2)) {
        if (p%divisor==0) {
          flag=1;                 // if p is divisible set flag to 1 and break
          flag2=0;                // make sure to set flag2 to 0 so it doesn't break to start of function after the loop ends
          break;                  // this will continue the NEXT PRIME SECTION
        }                         // and p will be incremented again
        else {
          divisor++; 
          flag2=1;                // flag2 basically says we've ended the loop, and this NUM has no
        }                         // divisors, so send it as the next prime up to the top of 
      }                           // the function
      if (flag2==1) {
        flag=0;
        flag2=0;
        break;                    // it's a prime, break out of the NEXT PRIME loop
      }
    }
  }
  
return;
}
