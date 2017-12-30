#include <unistd.h>
#include <stdio.h>

int main(void) {
	unsigned int i;
	alarm(1);
	for (i = 0; 1; i++)
		printf("I=%d\n", i);
	return 0;

}
