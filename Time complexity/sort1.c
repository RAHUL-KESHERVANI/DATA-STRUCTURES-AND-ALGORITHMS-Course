#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include<time.h>

void sort(int a[], int size){
int i, j, num; 
//Bubble Sort Starts
for(i = 0;i < size - 1;i++){
                for(j = 0;j < size - 1;j++){
                        if(a[j] > a[j+1]){
                                num = a[j];
                                a[j] = a[j+1];
                                a[j+1] = num;
                        }
                }
        }
//Sort Ends
//printing the sorted array
for(i = 0;i < size;i++)
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
