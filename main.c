/*
 * Project 1
 * Cindy Han & Jung Hyun (Cathrine) Seo
 * Fall 2014
 * COSC 301
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "list.h"



void process_data(FILE *input_file) {
    // !! your code should start here.  the input_file parameter
    // is an already-open file.  you can read data from it using
    // the fgets() C library function.  close it with the fclose()
    // built-in function
	char string[100];
	struct node *head = NULL;
	while(!feof(input_file)){
		// get the line of code 
		fgets(string, 100, input_file);
		// read each line
		if (fgets(string,100, input_file)){
			tokenify(string, &head);
			printf("%s\n", string);
		}
	}
	fclose();
	// print out the sorted linked list
	printf("*** List Contents Begin ***");
	print_list(&head);
	printf("*** List Contents End ***");
	// free the memory
	free_mem(&head);
	



}


void usage(char *program) {
    fprintf(stderr, "usage: %s [<datafile>]\n", program);
    exit(1);
}

#ifndef AUTOTEST
int main(int argc, char **argv) {
    FILE *datafile = NULL;

    /* find out how we got invoked and deal with it */
    switch (argc) {
        case 1:
            /* only one program argument (the program name) */ 
            /* just equate stdin with our datafile */
            datafile = stdin;        
            break;

        case 2:
            /* two arguments: program name and input file */
            /* open the file, assign to datafile */
            datafile = fopen(argv[1], "r");
            if (datafile == NULL) {
                printf("Unable to open file %s: %s\n", argv[1], strerror(errno));
                exit(-1);
            }
            break;

        default:
            /* more than two arguments?  throw hands up in resignation */
            usage(argv[0]);
    }

    /* 
     * you should be able to just read from datafile regardless 
     * whether it's stdin or a "real" file.
     */
    process_data(datafile);
    fclose(datafile);
    return 0;
}
#endif
