#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char digits[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int n01=0;

void print(int number[],char output[],int start,int end)
{
	static int next;
	int len,i;
	if(start==end)
	{
		printf("%s\n",output);
		return ;
	}

	len = strlen(digits[number[start]]);

	if(number[start]==0 || number[start]==1)
	{
		print(number,output,start+1,end);
		return ;
	}
	for(i=0;i<len;i++)
	{
		output[next] = digits[number[start]][i];
		next++;
		print(number,output,start+1,end);
		next--;
	}
	
	return ;
}

void printAllWords(int number[],int n)
{
	int i;
	char output[n+1];

	for(i=0;i<n;i++)
		if(number[i]==0 || number[i]==1)
			n01++;

	output[n-n01] = '\0';

	print(number,output,0,n);
}

int main(void)
{
  int number[] = {2,3,4};
	int n = sizeof(number)/sizeof(number[0]);

	printAllWords(number,n);
	
	return 0;
}
