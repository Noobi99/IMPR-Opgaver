#include <stdlib.h>
#include <stdio.h>

long fib(long n);
long Oldfib(int n);

int main(void){
  long i;

  for(i = 0; i < 100; i++)
    printf("Fib(%li) = %li\n", i, Oldfib(i));

}


long fib(long n){     /* working program: fib-memo.c - an exercise*/
  long result;
  
  static long memo[100];

  if (n == 0)
    result = 0;
  else if (n == 1)
    result = 1;
  else if (memo[n] != 0)
    result = memo[n];
  else {
    result = fib(n-1) + fib(n-2);
    memo[n] = result;
  }

  return result;
}

long Oldfib(int n){
  long result;

  if (n == 0)
    result = 0;
  else if (n == 1)
    result = 1;
  else
    result = fib(n-1) + fib(n-2);

  return result;
}