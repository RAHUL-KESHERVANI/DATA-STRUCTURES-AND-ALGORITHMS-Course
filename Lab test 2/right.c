#include "sll.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <error.h>
#include <limits.h>
#include<math.h>
int main(int argc, char *argv[]) {
	int fd, i, flag = 0;
	char c;
	long int num;
	data d;
	list l;
	if(argc != 4) {
		printf("Please enter required filename, name, number\n");
		return INT_MIN;
	}
	init(&l);
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("");
		return INT_MIN;
	}
	/*assuming the data in every line of the file to be in the order as specified in the question*/
	/*reading one character repeatdly from file, storing in structure d appropiately*/ 
	while(read(fd, &c, 1)) {
		d.n = 0;
		d.marks = 0.0;
		strcpy(d.name,"");
		d.grace = 0;
		
		i = 0;
		flag = 0;
		/*code for divding the whole line into 4 groups of data*/
		/*reading 1st entry in the line i.e. registration number*/
		while(c != '\t') {
			d.n = d.n * 10 + (c-'0');
			read(fd, &c, 1);
		}
		
		/*reading 2nd entry that should be the name*/
		read(fd, &c, 1);			//as c has tab, going 1 character forward 
		while(c != '\t') {
			d.name[i++] = c;
			read(fd, &c, 1);
		}
		d.name[i] = '\0';
		
		/*reading 3rd entry i.e. marks*/
		read(fd, &c, 1);
		flag = 0;		//as c has tab, going 1 character forward
		while(c != '\t') {
			if(c == '.') {
				flag = 1;		//flag used for comma
				break;
			}
			d.marks = d.marks * 10 + (c - '0');
			read(fd, &c, 1);
		}
		
		if(flag){					//if flag set then do the loop
			read(fd, &c, 1);				
			while(c != '\t') {
				d.marks = d.marks * 10 + (c - '0');
				d.marks = d.marks /10.0;
				read(fd, &c, 1);		//to get the decimals	
			}
		}
		/*for reading 4th entry penalty/grace*/
		read(fd, &c, 1);
		flag = 0;
		if(c == '-') {
			flag = 1;			//here flag is for negative numbers
			read(fd, &c, 1);		//as c has '-', going 1 character forward
		}
		while(c != '\n') {
			d.grace = d.grace * 10 + (c - '0');
			read(fd, &c, 1);
		}
		if(flag)
			d.grace = 0 - d.grace;
		
		append(&l, d);				//appending the read data
	}
	
	/*removing from the list the name argv[2]*/
	removel(&l, argv[2]);
	/*sorting the list on the basis of marks*/
	sort(&l);
	/*converting the string argv[3] into integer*/
	i = 0;
	num = 0;
	while(argv[3][i] != '\0') {
		num = num * 10 + (argv[3][i] - '0');
		i++;
	}
	/*rotating the list*/
	rotate(&l, num);
	/*printing the list*/
	printl(l);
}
