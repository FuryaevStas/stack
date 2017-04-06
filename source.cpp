#include	<stdio.h>
#include	<stdlib.h>

#include	"stack.h"

int main(){
	stack<int> intStack;
	printf ("%lu\n", intStack.getSize());
	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	printf ("%lu\n", intStack.getSize());
	printf ("%d\n", intStack[3]);

	return 0;
}