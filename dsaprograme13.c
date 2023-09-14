#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 20

int queue[MAX_SIZE];
int front = -1, rear = -1;
int data;

void Enqueue(int x){
	
	if ((rear == MAX_SIZE - 1 && front == 0) || (front == rear + 1)) {
		printf("Queue is Overflow\n");
	}
	else{
		if (front == -1 && rear == -1) {
			front = rear = 0;
			queue[rear] = data;
	} else {
	
		rear =(rear+1)%MAX_SIZE;
		queue[rear] = data;
	    	printf("%d Enqueued successfully.\n", data);
	    	
	    }
    }
}


void Dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow\n");
    }

    printf("%d Dequeued successfully.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front=(front+1)%MAX_SIZE;
    }
}


void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow\n");
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main() {
    int choice;

    while (1) {
        printf("\n\n1. Enqueue \n2. Dequeue\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                Enqueue(data);
                break;            
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}




