// Kristin Lin
// Systems pd10
// Work 02: If you're feeling rusty, apply eul
// 2017-09-19


/* 
PROBLEM ONE
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <stdio.h>

int mult35(int limit) {

  //set aside memory for sum and counter
  int sum = 0;
  int i = 1;

  //gather multiples of 5, including multiples of 15
  while (i * 5 < limit) {
    sum += i++ * 5;
  }
  //reset counter
  i = 1;
  //gather multiples of 3, but not including multiples of 15
  while (i * 3 < limit) {
    if (i % 5 != 0) {
      sum += i++ * 3;
    } else {
      i++;
    }
  }

  //return sum
  return sum;
}

//------------------------------------------------------------

/* PROBLEM FIVE
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

//here's a gcd function
int gcd(int a, int b) {
  if (b < a) { return gcd(b, a); }
  else if (a == 1) { return 1; }
  else if (a == 0) { return b; }
  else {
    return gcd(b%a, a);
  }
}

/*idea: int answer. loop from lower to higher, as the counter increases, get the gcd of counter and answer. if the gcd is the counter, then don't multiply to answer. Otherwise, multiply counter / gcd to answer
 */
int leastMult(int lower, int higher) {
  int answer = 1;
  int factor;
  for (lower; lower <= higher; lower++) {
    factor = gcd(answer, lower);
    if (factor != lower) {
      answer *= lower / factor;
    }
  }
  return answer;
}

//------------------------------------------------------------
/* PROBLEM FOUR
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
 */

/*
//helper to check reversal
int cheqRev(int num) {
  int tnum = num;
  int rev = 0;
  while (tnum != 0) {
    rev = 10 * rev + tnum % 10;
    tnum /= 10;
  }

  // if equal, returns 0, otherwise some other number
  return num - rev;
}


//useful power
int power (int a, int b) {
  int count;
  int total = 1;
  for (count = 0; count < b; count++) {
    total *= a;
  }
  return total;
}

int palin(int digits) {
  int big = power(10, digits) - 1;
  int small = big;
  while (cheqRev(big * small) != 0) {
    if ( (big*(small-1)) < ((big-1) * (big-1)) ) {
      big = big -1;
      small = big;
    } else {
      small -= 1;
    }
  }
  return big * small;
}
*/

/*
NOTE: doesn't work because you can't just change big each time you realize there's a larger number when you do big-1 * big-1. You're neglecting paths.
 */

//===================================

int main() {
  printf("The sum of multiples of 3 and 5 under %d is %d\n",
	 10, mult35(10));
  printf("The sum of multiples of 3 and 5 under %d is %d\n",
	 1000, mult35(1000));
  printf("\n");

  printf("Least Common Multiple of %d to %d is %d\n",
	 1, 10, leastMult(1, 10) );
  printf("Least Common Multiple of %d to %d is %d\n",
	 1, 20, leastMult(1, 20) );


  //  printf("%d", palin(2));
  return 0;
}


