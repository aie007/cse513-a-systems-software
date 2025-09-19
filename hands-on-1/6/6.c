/*
 * Program: 6.c
 * Author: Aieshah Nasir
 * Description: Program to take i/p from STDIN and display on STDOUT. 
 * 		Use only read/write system calls
 * Date: 01/09/2025
 */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(void) {
	char buff[30];
	char question[] = "who are you?\n";
	char hi[] = "hello ";
	write(1, question, strlen(question));
	int nread = read(0, buff, 25);
	write(1, hi, strlen(hi));
	write(1, buff, nread);
	return 0;
}

/*
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/6$ ./a.out
 * who are you?
 * aieshah
 * hello aieshah
 */
