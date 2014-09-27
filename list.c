#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// Names: Cindy Han & Jung Hyun (Catherine) Seo
/* your list function definitions */
<<<<<<< HEAD

struct node {
	int value;
	struct node *next;
}

/* your list function definitions */
=======
>>>>>>> d54a865467c4728b40860c879f6548d00b02e639




void free_mem(struct node** head){
	// free all the malloced memory 
	struct node current = *head;
	while (current != NULL){
		struct node* temp = current;
		current = current->next;
		free(temp);
	}

}

int prefix(const char *pre, const char *string){
	// checks if the input starts the prefix given
	return (strncmp(pre, str, strlen(pre)));

}	



struct node** tokenify(const char *s) {
	char *s_copy = strdup(s); // make a copy of the string 
    char *token = strtok(s_copy, " \t\n"); // get tokens from the string
    struct node *head = NULL; // head of the list
    while (token != NULL){
    	// check if the line has a "#" if it does ignore the rest of the line
    	if (prefix("#", token)){
    		break;
    	}
    	// check if the number is integer
    	if (isdigit(token)){
    	// add the int to the list
    		insert_node(atoi(token), &head);
    	}
    }
    return *head;
}


void insert_node (const int n, struct node **head){
	struct node *new = malloc(sizeof(struct node));
	new->value = n
	new->next = NULL;
	struct node *copy = *head;
	
	if (*head == NULL){
		*head = new;
	}
	
	else if ((*head)->next == NULL){
		if ((*head)->value < n){
			(*head)->next = new;
		}
		else{
			(*new)->next = head;
			*head = new;
		}
	}
	else{
		while ((*copy)->next != NULL){
			if (n < (*copy)->value){
				(*new)->next = copy;
				*copy = new;
				break;
			}
			else if (n >= (*copy)->value && i <= (*copy)->next->value){
				new->next = copy->next;
				copy->next = new;
				break;
			}
			copy = copy->next;
		}
		
	}
}
<<<<<<< HEAD
=======

void print_list (struct node **head){
	while (head != NULL){
		printf ("%d\n", head->value);
		head = head->next;
	}
}


>>>>>>> d54a865467c4728b40860c879f6548d00b02e639
