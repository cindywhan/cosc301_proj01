#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// Names: Cindy Han & Jung Hyun (Catherine) Seo
/* your list function definitions */
/* your list function definitions */

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


