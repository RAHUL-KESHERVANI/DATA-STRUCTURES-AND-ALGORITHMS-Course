#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{	
	struct d{
		long int n;
		char m[28];
		short int v;
	};
	d t;
	int fp;
	fp = open(argv[1],O_RDONLY, S_IRUSR | S_IWUSR);
	if(fp == -1){
		perror("open failed:");
		return errno;
	}
	t.n = 0;
	while(read(fp,&(t.n),sizeof(t.n))){
	printf("%ld\n", t.n);
	read(fp,m,sizeof(t.m));
	printf("%s\n", t.m);
	}	
	return 0;
}
