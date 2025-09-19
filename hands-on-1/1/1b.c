/**
 * Program: 1b.c
 * Author: Aieshah Nasir
 * Description: Create the following types of files using (ii) system call
 * 		b. Hard Link ( link() Syscall )
 * Date: Aug 21 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
        if(argc != 3) {
                printf("Invalid syntax!\n");
                printf("Usage: ./1b source_name hard_link_name\n");
                exit(1);
        }
        // link() for hard link
        int lnk = link(argv[1], argv[2]);
        if(lnk == 0) {
                printf("Hard link created successfully\n");
        }
        else {
                printf("Error creating hard link\n");
                exit(1);
        }
        return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/hands-on-1/1$ ./a.out 1.txt hlnk
 * Hard link created successfully
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/hands-on-1/1$ ls -l 1.txt hlnk
 * -rw-rw-r-- 3 nasir nasir 35 Aug 14 11:04 1.txt
 * -rw-rw-r-- 3 nasir nasir 35 Aug 14 11:04 hlnk               
 */

