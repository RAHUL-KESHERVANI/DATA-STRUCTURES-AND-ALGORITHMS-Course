#include<stdio.h>
#include <unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int argc, char const *argv[]){
	struct data {         
	int age;         
	char name[16]; 
	}data;	
	int fd, n, m, p, i = 0,j;
	int num;
	char str[100];
	fd = open(argv[1], O_RDONLY,S_IRUSR | S_IWUSR );
	read(fd, &n, sizeof(n));
	while(i < n) {
		read(fd, &num, sizeof(num));
		printf("%d\n", num);
		i++;
	}
	i = 0;
	read(fd, &m, sizeof(m));
	while(i < m) {
		read(fd, &data, sizeof(data));
		printf("%d ", data.age);
		printf("%s\n", data.name);		
		i++;
	}
	i = j = 0;
	read(fd, &p, sizeof(p));
	while(i < p) {
		while(read(fd, &str[j], 1) && str[j] != '\0'){ 
		printf("%c", str[j]);		
		j++;
		}
		printf("\n");	
		i++;
		j++;
	}
	return 0;
}
