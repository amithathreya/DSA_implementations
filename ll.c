#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};
typedef struct node* NODE;

NODE get_node() {
    NODE new_node = (NODE)malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf(" mem-alloc failed\n");
    }
    return new_node;
}

void insert(NODE *header , int value) {
    NODE new_node = get_node();
    new_node->data = value;
    new_node->link = *header;
    *header = new_node;
}

void insert_at_end(NODE *header , int value) {
    NODE new_node = get_node();
    new_node->data = value;
    new_node->link = NULL;
    if(*header == NULL) {
        *header = new_node;
    } else {
        NODE temp = *header;
        while(temp->link!=NULL) {
            temp = temp->link;
        }
        temp->link = new_node;
    }
}

void print(NODE header) {
    NODE temp = header;
    while(temp!=NULL) {
        printf("%d->",temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void del(NODE *header) {
    if(*header == NULL) {
        printf(" linked list is empty\n");
        return;
    } else {
        NODE temp = *header;
        *header = (*header)->link;
        free(temp);
    }
}

void insert_after_element(NODE *header , int target , int value) {
    NODE new_node = get_node();
    new_node->data = value ; 
    NODE temp = *header;
    while(temp!=NULL && temp->data!=target) {
        temp = temp->link;
    }
    if(temp == NULL) {
        printf("element not found in the list\n");
        return;
    }
         new_node->link = temp->link; 
    temp->link = new_node;

}

int main() {
    NODE header = NULL;
    insert(&header , 5);
    insert(&header , 10);
    insert_at_end(&header , 2);
    print(header);
    print(header);
    insert_after_element(&header , 10 ,11);
    print(header);
    return 0;
}