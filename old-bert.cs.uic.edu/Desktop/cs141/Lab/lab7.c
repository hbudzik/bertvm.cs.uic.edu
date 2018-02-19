#include <stdio.h>


int convertBinaryArrayToDecimal(int digits[], int i)
{
		int sequence[5] = {16,8,4,2,1};
	int decimal = 0;
	int sum;
	for (i=0; i<5; i++)
	{
	  	sum = sequence[i] * digits[i];
		decimal += sum;
	}
			return decimal;

	
}
int main()
{
	

	int binary[5];
	
	printf("\n");
	printf("Enter 5 digit binary code: ");
	scanf("%d %d %d %d %d", &binary[0], &binary[1], &binary[2], &binary[3], &binary[4]);
	printf("\n");

	
	int result = convertBinaryArrayToDecimal(binary, 5);
	printf("binary to decimal: conversion :>  %d", result);
	return 0;
}
