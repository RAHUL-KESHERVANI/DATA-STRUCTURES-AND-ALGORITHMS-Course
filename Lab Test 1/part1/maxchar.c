#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<limits.h>
int main(int argc, char *argv[]){
	int fd, i, MAX = 0, M;
	int a[200] = {0};
	char ch;
	if(argc != 2){			//arguments allowed are: "./program" & "textfile"
		errno = INT_MIN;
		printf("Enter Valid Arguments\n");
		return errno;
	}
	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror("");
		return errno;	
	}
	
	//actual code/logic
	while(read(fd, &ch, 1))
	{
		i = ch;            	//implicit conversion from character to integer
		a[i]++;	       	//array position based on ascii value of the read character 	
		if(a[i] > MAX){		//finding the maximum repeating character
		MAX = a[i];
		M = i;			//ascii value of the character stored
		}
	}
	//while loop ends
	
	printf("%c\n", (char)M);
	return 0;
}
