#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>
#include <ctype.h>

// Names: Cindy Han & Jung Hyun (Catherine) Seo

/* your list function definitions */


void free_mem(struct node** head){
	// free all the malloced memory 
	struct node *current = *head;
	while (current != NULL){
		struct node* temp = current;
		current = current->next;
		free(temp);
	}

}

int prefix(const char *pre, const char *string){
	// checks if the input starts the prefix given
	return (strncmp(pre, string, strlen(pre)));

}	

int is_int(const char *s){
	// checks if the input is an integer
	int i = 0;
	if (s[0] == '-'){
		i = 1;
	}
	for (i; i < strlen(s); i++){
		if (!isdigit(s[i])){
		// if the number is not an int return -1
		 	return -1;
		}
	
	}
	return 1;
}


struct node **tokenify(const char *s, struct node **head) {
	char *s_copy = strdup(s); // make a copy of the string 
    char *token = strtok(s_copy, " \t\n"); // get tokens from the string
    while (token != NULL){
    
    	// check if the line has a "#" if it does ignore the rest of the line
    	if (prefix("#", token) == 0){
    		break;
    	}
    	// check if the number is integer
    	if (is_int(token) == 1){
    	// add the int to the list
    		insert_node(atoi(token), head);
    	}
    	token = strtok(NULL, " \t\n");
    	
    }
    return head;
}


//function to insert a node into a linked list whilst sorting it
void insert_node (const int n, struct node **head){
	//create a new node with the given int
	struct node *new = malloc(sizeof(struct node));
	new->value = n;
	new->next = NULL;
	//make a copy of the head node
	struct node *copy = *head;
	
	//if there is no linked list, start a new list by making the new node the head
	if (*head == NULL){
		*head = new;
	}
	//else if there is only one node in the linked list
	else if ((*head)->next == NULL){
		//if the value of the new node is larger than the value of the head node
		if ((*head)->value < n){
			(*head)->next = new;
		}
		//if the value of the new node is smaller than the value of the head node
		else{
			new->next = *head;
			*head = new;
		}
	}
	//else, if there are more than two nodes already in the linked list
	else{
		//use copy of the head instead of the real head node
		while (copy->next!= NULL){
			//if the value of the new node is smaller than the value of the current node
			if (n >= copy->value && n < copy->next->value){
				new->next = copy->next;
				copy->next = new;
				break;
			}
		
			//keep going through the linked list until the new node satisfies either the if or else if statement
			copy = copy->next;
		}
		copy->next = new;
		
	}
}


//function to print the linked list
void print_list (struct node **head){
	struct node* temp = *head;
	while (temp != NULL){
		printf ("%d\n", temp->value);
		temp = temp->next;
	}
}

