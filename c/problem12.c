#include <stdio.h>
#include <stdlib.h>

#define MAX_DIVISORS 500
static int count_divisors(long triangle);

/**
 * The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * Let us list the factors of the first seven triangle numbers:
 * 1: 1
 * 3: 1,3
 * 6: 1,2,3,6
 * 10: 1,2,5,10
 * 15: 1,3,5,15
 * 21: 1,3,7,21
 * 28: 1,2,4,7,14,28
 *
 * We can see that 28 is the first triangle number to have over five divisors.
 * What is the value of the first triangle number to have over five hundred divisors?
 **/
void main(void) {
	long triangle, n = 1;
	while (count_divisors(triangle) < MAX_DIVISORS) {
		triangle += n++;
	}
	printf("answer: %lu \n", triangle);
}

/**
 * Any integer can be expressed as
 * N = p1^a1 * p2^a2 * p3^a3... 
 * where p is a distinct prime number and a is its exponent. The count of divisors D(N) can then be found by the formula
 * D(N) = (a1 + 1) * (a2 + 1) * (a3 + 1)...
 *
 * For example:
 * N = 36 = 3^2 * 2^2 = 9 * 4
 * D(32) = (2 + 1) * (2 + 1) = 9
 **/
int count_divisors(long triangle) {
	int div_cnt = 1;
	for (long n = 2; n <= triangle; n++) {
		int cnt = 0;
		while (triangle % n == 0) {
			cnt++;
			triangle /= n;
		}
		div_cnt *= cnt + 1;
	}
	return div_cnt;
}
