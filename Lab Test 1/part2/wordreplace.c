#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define MAX 32
int main(int argc, char *argv[]){
	int fdw, fdr, i, l1, l2, k;
	char ch;
	int flag;
	i = 0;
	l1 = strlen(argv[2]);
	l2 = strlen(argv[3]);
	fdr = open(argv[1], O_RDONLY);
	fdw = open("temp", O_WRONLY | O_TRUNC | O_CREAT);
	if(fdw == -1 || fdr == -1 || argc != 4){
		printf("error\n");
	}
	flag = 0;
	while(read(fdr, &ch, 1) == 1){
		if(flag ||(!i && ch == argv[2][0])){
			flag = 1;
			if(i != 0 && (ch == ' ' || ch == '\n')){
				//match is found
				for (int k = 0; k < l2; ++k)
				{
					write(fdw, &(argv[3][k]), 1);
				}
				i = 0;
				write(fdw, &ch, 1);
			}
			else if(argv[2][i] == ch) {
				i++;
				continue;
			}
			else if(argv[2][i] != ch && (ch != ' ' && ch != '\n' && ch !='\r')){
				for (k = 0; k < i; ++k)
				{
					write(fdw, &(argv[2][k]), 1);
				}
				flag = 0;
			}
		}
		if(!flag && ch !='\r'){
			write(fdw, &ch, 1);
		}
		if(!flag && (ch == ' ' || ch == '\n' || ch == '\r')){
			i = 0;
		}
	}
	//for the case where file ends with the "search" word without any spaces or return
	if(i == l1){
		for (int k = 0; k < l2; ++k)
		{
			write(fdw, &(argv[3][k]), 1);
		}
	}

	close(fdr);
	close(fdw);
	fdw = open("txt", O_TRUNC|O_WRONLY);
	fdr = open("temp", O_RDONLY);
	while(read(fdr, &ch, 1)){
		write(fdw, &ch, 1);
	}
	
	return 0;
}
