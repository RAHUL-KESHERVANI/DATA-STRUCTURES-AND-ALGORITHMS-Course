#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
struct info { 
	int id;  
	char name[16]; 
	double score; 
}s[100]; 
int main(int argc, char const *argv[])
{
	int fd;
	int n,i;
	if(argc < 3) {
		errno = EINVAL;
		printf("Invalid Arguments\n");
		return errno;
	}	
	fd = open("f",O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		perror("");
		return errno;
	}
	printf("Enter the number of the structure you want to Enter\n");
	scanf("%d", &n);
	for(i = 0;i < n;i ++) {
		printf("\n-----------Structure1--------\n");
		printf("Enter id:");
		scanf("%d",&s[i].id);
		printf("Enter Name:");
		scanf("%s", s[i].name);
		printf("Enter Score:");
		scanf("%lf", &s[i].score);
	}
	write(fd,&n,sizeof(n));	
	for (int i = 0; i < n; ++i)
	{
		write(fd,&s[i],sizeof(s[i]));		
	}
	return 0;
}
