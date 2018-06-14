#include<stdio.h>
#include<string.h>
int stringreplace(char *text, char *orig, char *new) {
	int lt, lo, ln, i, j, temp, temp2, count;
	lt = strlen(text);
	lo = strlen(orig);
	ln = strlen(new);
	i  = 0;
	j = 0;
	while(text[i]) {
		temp = 0;

		//FINDING THE ORIGINAL SUBSTRING IN TEXT
		if(text[i] == orig[0]){
			for(j = 0;orig[j];j++, i++){
				if(text[i] == orig[j]){
					temp =1;
				}
				else {
					//RESETTING i BACK IF NOT MATCHED
					i = i - j;
					temp = 0;
					break;
				}
			}
		
			if(temp == 1){
			i -= j; //i now is the index of the occurence of orig in text
			j = ln - lo;
			count++;

			//REPLACEMENT OF ORGINAL BY NEW SUBSTRING
			if(j > 0){
				for(temp = lt + (j*count);temp >= (i + lo)-1;temp--)
					text[temp +j] = text[temp];
				for(temp = ln - 1; temp >= 0;temp--)
				text[temp + i] = new[temp];
				

			}
			else{
				for(temp = i + ln ;temp <  lt;temp++)
					text[temp + j] = text[temp];	
				for(temp = 0; temp < ln;temp++)
				text[temp + i] = new[temp];
				text[lt + (j*count)] = '\0';
				}
			}
		
		}
		i++;
	}
	return count;
}

int main() {
    char text[128], orig[128], new[128]; // don't assume size of 128 in the function stringreplace, it is not available in the function!
    int count;
    while(scanf("%s%s%s", text, orig, new) != -1) {
       count = stringreplace(text, orig, new);
       printf("%d %s\n", count, text);
    }
    return 0;
}


