// implementation of queue datarstructure

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

struct Queue {
    int items[SIZE];
    int rear;
    int front;
    int count;
};

typedef struct Queue* QUEUE;

void initialize(QUEUE q) {
    q->rear = -1;
    q->front = 0;
    q->count = 0;
} 

bool isFull(QUEUE q) {
    return(q->count == SIZE);
}

bool isEmpty(QUEUE q) {
    return (q->count == 0);
}

void enqueue(QUEUE q , int data) {
    if(isFull(q)) {
        printf(" cannot perform enqueue operation\n");
        return;
    } else {
        q->rear=(q->rear+1)%SIZE;
        q->items[q->rear] = data;
        q->count+=1;
    }
}

int dequeue(QUEUE q) {
    if(isEmpty(q)) {
        printf(" cannot perfom dequeue operation\n");
        return -1;
    } else {
        int data = q->items[q->front];
        q->front = (q->front+1)%SIZE;
        q->count-=1;
        return data;
    }
}

void print(QUEUE q) {
    for(int i=q->front;i<=q->rear;i++) {
        printf("%d ",q->items[i]);
    }   
    printf("\n");
}

int main() {
    QUEUE q = (QUEUE)malloc(sizeof(struct Queue));
    if(q == NULL) {
        printf(" memory allocation failed\n");
        return 0;
    }
    initialize(q);
    enqueue(q , 2);
    enqueue(q , 4);                                                           
    enqueue(q , 5);
    enqueue(q , 6);
    enqueue(q , 7);
    print(q);
    int data = dequeue(q);
    if(data != -1) {
        printf("dequeued element: %d\n",data);
    }
    data = dequeue(q);
    if(data != -1) {
        printf("dequeued element: %d\n",data);
    }
    enqueue(q , 6);
    enqueue(q , 7);
    data = dequeue(q);
    if(data != -1) {
        printf("dequeued element: %d\n",data);
    }
    print(q);
    return 0;
}