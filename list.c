#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// Names: Cindy Han & Jung Hyun (Catherine) Seo

/* your list function definitions */

//function to insert a node into a linked list whilst sorting it
void insert_node (const int n, struct node **head){
	//create a new node with the given int
	struct node *new = malloc(sizeof(struct node));
	new->value = n
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
			(*new)->next = head;
			*head = new;
		}
	}
	//else, if there are more than two nodes already in the linked list
	else{
		//use copy of the head instead of the real head node
		while ((*copy)->next != NULL){
			//if the value of the new node is smaller than the value of the head node
			if (n < (*copy)->value){
				(*new)->next = copy;
				*copy = new;
				break;
			}
			//if the value of the new node is larger than or equal to the value of the current head but smaller than or equal to the value of the next node after the head
			else if (n >= (*copy)->value && n <= (*copy)->next->value){
				new->next = copy->next;
				copy->next = new;
				break;
			}
			//keep going through the linked list until the new node satisfies either the if or else if statement
			copy = copy->next;
		}
		
	}
}

//function to print the linked list
void print_list (struct node **head){
	while (head != NULL){
		printf ("%d\n", head->value);
		head = head->next;
	}
}
