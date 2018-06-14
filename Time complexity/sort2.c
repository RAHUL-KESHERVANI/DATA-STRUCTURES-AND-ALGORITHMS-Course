#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
void sort(int a[], int size){
	int num, i, j; 
	//Seletion Sort
	for(i = 0;i < size - 1;i++)			
                for(j = i+1;j < size;j++)
                        if(a[i] > a[j]) {
                                num = a[i];
                                a[i] = a[j];
                                a[j] = num;
                        }
	//Sort ends
	//printing the Sorted array 
        for(i =0 ;i < size;i++)
                printf("%d\n", a[i]);
}
int main() {
	int *a, i, n, count = 0, num, size = 1024; 
	 struct timeval te; 
	a = (int *)malloc(sizeof(int) * size);
	/* Do "man scanf". Scanf returns -1 when there is "no input" 
	 * To tell scanf that there is no input, you can press "control-d" 
	 * in stdio.h EOF is #defined to be -1 */
	while(scanf("%d", &num) != EOF) {
		a[count] = num;
		count++;
		if(count == size) {
			size *= 2;
			a = (int *)realloc(a, sizeof(int) * size);
			if(a == NULL) {
				printf("Failed for %d\n", size);
				exit(1);
			}
		}
	}
	gettimeofday(&te, NULL); // get current time
    	long long milliseconds1 = te.tv_sec*1000LL + te.tv_usec/1000;	//getting time before the sort() function is called
	sort(a, size);
	gettimeofday(&te, NULL); // get current time
    	long long milliseconds2 = te.tv_sec*1000LL + te.tv_usec/1000;	//getting time after the sort() function is called	
	long timetaken = milliseconds2 - milliseconds1;			//getting the timetaken i.e. the difference between
	printf("%lf", (double)timetaken/1000);	
	free(a);
	return 0;
}
