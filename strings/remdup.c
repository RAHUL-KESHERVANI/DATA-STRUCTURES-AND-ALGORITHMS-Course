#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
int removeduplicate(double a[], int n) {
	int i, j, p;
	for(i = 0;i < n-1;i++) {
		for(j = i+1;j < n;j++) {
			if(a[j] == a[i]){
				for(p = j;p < (n - 1);p++)
					a[p] = a[p+1];
				n--;
			}
		}
	} 
	return n;
}

int main(int argc, char *argv[]) {
	int fd, n;
	double arr[100];
	if(argc < 2) {
		errno = EINVAL;
		printf("INVALID ARGUMENTS\n");
		return errno;
	}
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("OPEN FAILED:\n");
		return errno;
	}
	n = 0;
	while(read(fd, &arr[n], sizeof(arr[n])))
	n++;
	printf("File '%s' now has %d numbers\n", argv[1], removeduplicate(arr, n));
	close(fd);
	return 0;
}
