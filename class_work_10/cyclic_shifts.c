/* Left and right cyclic shifts in a given value by a given number of bit positions */

#include <stdio.h>

int cyclic_left_shift (int value, int bits_num);
int cyclic_right_shift (int value, int bits_num);
void displayBits( unsigned value );

void main()
{
	int shift, result, value, bits_num;
	int (*pfun_shift[2]) (int , int) = {cyclic_left_shift, cyclic_right_shift};

	while (1)
	{
		printf ("\nEnter the shift direction (0 - left, 1 - right, more 1 - exit)  ");
		scanf ("%d", &shift);
		if (shift > 1)
			break;
		printf ("Enter the value  ");
		scanf ("%d", &value);
		printf ("Enter the number of bits for shift  ");
		scanf ("%d", &bits_num);

		printf( "\nBefore cyclic shifting\n" );
		displayBits( value );

		result = (*pfun_shift[shift]) (value, bits_num);

		printf( "After cyclic shifting\n" );
		displayBits( result );
	}

	puts("");
}


int cyclic_left_shift (int value, int bits_num)
{
	int i, left_bit, mask = 1 << 31;
	for (i=1; i<=bits_num; i++)
	{
		left_bit = value & mask;
		value <<= 1;
		if (left_bit)
			value ^= 1; // new right bit:  0 XOR 1 = 1
	}
	return value;
}


int cyclic_right_shift (int value, int bits_num)
{
	int i, right_bit, left_bit, mask = 1 << 31;
	for (i=1; i<=bits_num; i++)
	{
		right_bit = value & 1;
		value >>= 1;
		left_bit = (value & mask) != 0;
		if (left_bit != right_bit) 
			value ^= mask; // new left bit:  1 XOR 1 = 0;  0 XOR 1 = 1
	}
	return value;
}


void displayBits( unsigned value )
{ 
   unsigned c; /* counter */
   
   /* declare displayMask and left shift 31 bits */
   unsigned displayMask = 1 << 31;

   printf( "%7u = ", value );

   /* loop through bits */
   for ( c = 1; c <= 32; c++ ) { 
      putchar( value & displayMask ? '1' : '0' );
      value <<= 1; /* shift value left by 1 */

      if ( c % 8 == 0 ) { /* output a space after 8 bits */
         putchar( ' ' );
      } /* end if */

   } /* end for */

   putchar( '\n' );
} /* end function displayBits */