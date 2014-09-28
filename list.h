#ifndef __LIST_H__
#define __LIST_H__

/* your list data structure declarations */


void insert_node (const int n, struct node **head);
void print_list (struct node **head);
void free_mem(struct node** head);
int prefix(const char *pre, const char *string);
struct node **tokenify(const char *s, struct node **head);


/* your function declarations associated with the list */


#endif // __LIST_H__
