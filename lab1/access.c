#include<stdio.h>
#include<unistd.h>
int main(){

	printf("%d\n",access("foo.txt", R_OK));
	printf("%d\n",access("foo.txt", W_OK));
	printf("%d\n",access("foo.txt", X_OK));
}