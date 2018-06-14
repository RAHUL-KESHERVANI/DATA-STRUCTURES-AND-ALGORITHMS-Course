#include<stdio.h>
#include <unistd.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
#include <errno.h>
struct info { 
	int id;  
	char name[16]; 
	double score; 
}s[100]; 
int main(int argc, char const *argv[])
{
	if(argc < 4) {
		errno = EINVAL;
		printf("Invalid Arguments");
		return errno;
	}
	int fd, n;
	double t;
	fd = open("f",O_RDONLY , S_IRUSR | S_IWUSR);
	if(fd == -1) {
		perror("");
		return errno;
	}
	read(fd, &n, sizeof(n));
	for(int i = 0;i < n;i++) {
		read(fd, &s[i], sizeof(s[i]));
	}
	t = atof(argv[2]);
	for(int i = 0;i < n;i++) {
		if(t == s[i].score) {
			printf("Matched Structure%d to the Entered Score:\n\n", i+1);
			printf("id = %d\n", s[i].id);
			printf("name = %s\n", s[i].name);
			printf("score = %lf\n\n", s[i].score);
		}
	}
	return 0;
}
