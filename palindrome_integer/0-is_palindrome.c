/*
 * ==========================================================================
 *
 *       Filename:  palindrome.h
 *
 *    Description: Write a function that checks whether or not a given
 *			unsigned integer is a palindrome 
 *
 *        Version:  1.0
 *        Created:  10.01.2025 15:06:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  
 *
 * ==========================================================================
 */

#include "palindrome.h"

int is_palindrome(unsigned long n)
{
	unsigned long n2 = n, reverse = 0;
	int last = 0;

	while (n2 != 0)
	{
		last = n2 % 10;
		reverse *= 10;
		reverse += last;
		n2 /= 10;
	}
	return (n == reverse);
}
