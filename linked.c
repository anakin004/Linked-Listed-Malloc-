#include <stdio.h>
#include <stdlib.h>


//making struct for node 

struct node {
    int value;
    struct node *next;
};

//define a type so we can pass into function
typedef struct node node_t;


void printlist(node_t *head) {
    node_t *temporary = head;

    while(temporary!=NULL){

        // value where temp is poitning to then move temp to next node 
        printf("Value of %p is %d\n", temporary, temporary -> value);
        temporary = temporary->next;
    }

    printf("\n");

}

void insert_element(node_t *head, int index, int num){
    // Allocate memory for the new node
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->value = num;
    new_node->next = NULL;  // Initialize next pointer to NULL
    
    node_t *temphead = head;

    // Traverse to the node before the desired index
    for(int i = 0; i < index-1; i++) {
        if (temphead == NULL) {
            printf("Index out of bounds\n");
            free(new_node);  // Free the allocated memory - memory is unallocated
            return;
        }
        temphead = temphead->next;
    }
    //update pointers to insert new node
    new_node->next = temphead->next;
    temphead->next = new_node;


}

int main(void){

    // linked list //
    
    node_t n1, n2, n3;
    node_t *head;


    n1.value = 2;
    n2.value = 5;
    n3.value = 786;

    //linking

    // 2 -> 786 -> 5

    head = &n1;
    n1.next = &n3;
    n3.next = &n2;
    n2.next = NULL; //stopping point

    insert_element(head,2,9898);
    printlist(head);


    return 0;
}