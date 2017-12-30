#include <signal.h>
#include <stdio.h>

void myprint() {
	printf("I get signal ctrl+c\n");
}
int main() {
	if (SIG_ERR == signal(SIGINT, myprint)) {
		printf("error!!!\n");
		return 1;
	}
	while (1) {
		sleep(1);
		printf("hello world!\n");
	}
	return 0;
}
