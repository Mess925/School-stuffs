#include <unistd.h>
#include <stdio.h>
void print_bits(unsigned char octet)
{
	int i = 7;
	unsigned char 	bit;

    // printf("i is %d\n",i);
	while (i >= 0)
	{
        // printf("i is %d\n",i);
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
        i--;
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 7;
	unsigned char	res = 0;

	while (i >= 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int main (void)
{
    print_bits((unsigned char)8);
    printf("\n");
    print_bits(reverse_bits((unsigned char)8));
}