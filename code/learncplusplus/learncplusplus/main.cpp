#include <iostream>
#include "Log.h"
#include <stdint.h>
#include <limits.h>

using namespace std;

#define internal static
#define global static
#define local_persist static

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

typedef float f32;
typedef double f64;

typedef union v2 {
	struct {
		float x;
		float y;
	};
} v2;

struct apa
{
	u32 c;
	u32 a;
	f32 b;
};

typedef union apa1
{

		char a;
		int b;
		float c;
};

#define v2(x, y) v2_init(x,y)
v2 v2_init(float x, float y)
{
	v2 v = { x, y };
	return v;
}

internal
void PrintBits(size_t const size, void const* const ptr)
{
	unsigned char* b = (unsigned char*)ptr;
	unsigned char byte;

	for (int i = size -1; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte); // %u is unsigned integer. %d is a singed integer. Read printf.txt.
		}
		printf(" ");
	}
	printf("\n");
}

int main()
{
	local_persist u32 number = 54;

	apa1 apa;
	
	apa.a = 'A';
	printf("A: %c\n", apa.a);
	
	apa.b = 5;
	printf("B: %d\n", apa.b);
	
	apa.c = 4.5f;
	printf("C: %f\n", apa.c);

	printf("Struct: %u\n", sizeof(apa));
	printf("Union: %u\n", sizeof(apa1));

	// bit is either 0 or 1 and there is 8 bits in one byte.
	cout << "bool is " << sizeof(bool) << " bit." << endl;
	cout << "char is " << sizeof(char) << " byte." << endl;
	cout << "short is " << sizeof(short) << " bytes." << endl;
	cout << "int & float is " << sizeof(int) << " bytes." << endl;
	cout << "double is " << sizeof(double) << " bytes." << endl;

	// using printf instead of cout as its more condensed.
	printf("bool is %u bit.\n", sizeof(bool));
	printf("char is %u bytes.\n", sizeof(char));
	printf("short is %u bytes.\n", sizeof(short));
	printf("int & float is %u bytes.\n", sizeof(float));
	printf("double is %u bytes.\n", sizeof(double));

	// shift the bit until decimal value of max 1024
	// 1,2,4,8,16,32,64,128,256,512,1024
	for (int i = 1; i <= 1024; i *= 2)
	{
		PrintBits(sizeof(i), &i);
	}

	// using a headerfile for definition
	Log("Calling a function from Log.c but using a definition in Log.h");

	// shifting bits and displaying in decimal and binary numbers.
	// this is actually a Pow function with unsigned numbers :)
	//s32 value = 2147483647;
	s32 value = 1;
	printf("Startvalue: %d\n", value);
	printf("Binary #: ");
	PrintBits(sizeof(value), &value);
	value = value << 2;
	printf("Value after leftshift bits: %d\n", value);
	printf("Binary #: ");
	PrintBits(sizeof(value), &value);
	
	value = value >> 1;
	printf("Value after rightshift bits: %d\n", value);
	printf("Binary #: ");
	PrintBits(sizeof(value), &value);

	printf("Int Max: %d\n", INT_MAX);
	printf("Int Min: %d\n", INT_MIN);

	cin.get();

	return 0;
}