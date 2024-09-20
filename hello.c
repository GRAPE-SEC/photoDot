// gcc -o hello hello.c -fno-stack-protector -no-pie

#include <stdio.h>

void hidden(){
    printf("THIS SHOULD NOT BE ACCESSED!!!\n");
	fflush(stdout);
}

int main(){
    char buffer[10];

    printf("hello, input : ");
    scanf("%s", buffer);
	printf("your input : %s\n",buffer);

    return 0;
}
