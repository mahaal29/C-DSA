#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("queue overflow\n");
    } else {
        temp->data = value;
        temp->next = NULL;
        if (front == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        printf("enqueued %d into the queue\n", value);
    }
}

int dequeue() {
    if (front == NULL) {
        printf("queue is empty\n");
        return -1;
    } else {
        struct node *temp = front;
        front = front->next;
        int val = temp->data;
        free(temp);
        if (front == NULL) {
            rear = NULL;
        }
        return val;
    }
}

int peek() {
    if (front == NULL) {
        printf("queue is empty\n");
        return -1;
    } else {
        return front->data;
    }
}

int show() {
    if (front == NULL) {
        printf("queue is empty\n");
    } else {
        printf("queue elements are: \n");
        struct node *temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.peek\n");
        printf("4.show\n");
        printf("5.exit\n");
        int choice, val, res;
        printf("enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("enter element: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                res = dequeue();
                if (res != -1) {
                    printf("dequeued element is %d\n", res);
                }
                break;
            case 3:
                res = peek();
                if (res != -1) {
                    printf("front element is %d\n", res);
                }
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("invalid choice\n");
                break;
        }
    }
    return 0;
}