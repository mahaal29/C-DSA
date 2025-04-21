#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {  // Fixed: changed = to ==
        printf("Stack overflow\n");
        return;
    }
    temp->data = value;
    temp->next = top;
    top = temp;
    printf("Pushed %d into the stack\n", value);
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void show() {  // Changed return type from int to void
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        struct node *temp = top;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        
        int choice, val, res;
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                res = pop();
                if (res != -1) {
                    printf("Popped element: %d\n", res);
                }
                break;
            case 3:
                res = peek();
                if (res != -1) {
                    printf("Top element: %d\n", res);
                }
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}