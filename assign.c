#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 6
#define MAX_COMPONENT_NAME 20

// Queue implementation for Load Request System
typedef struct {
    char items[100][MAX_COMPONENT_NAME];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return (q->front == -1);
}

void enqueue(Queue *q, char *item) {
    if (q->rear == 99) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    strcpy(q->items[q->rear], item);
    printf("Enqueued: %s\n", item);
}

char* dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    char *item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s ", q->items[i]);
    }
    printf("\n");
}

// Stack implementation for Stress Alert System
typedef struct {
    char items[100][MAX_COMPONENT_NAME];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, char *item) {
    if (s->top == 99) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    strcpy(s->items[s->top], item);
    printf("Pushed to stack: %s\n", item);
}

char* pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return s->items[s->top--];
}

void displayStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%s ", s->items[i]);
    }
    printf("\n");
}

// Array implementation for Load History Unit
typedef struct {
    char items[MAX_ARRAY_SIZE][MAX_COMPONENT_NAME];
    int count;
} LoadHistoryArray;

void initArray(LoadHistoryArray *arr) {
    arr->count = 0;
}

void insertResult(LoadHistoryArray *arr, char *result) {
    if (arr->count < MAX_ARRAY_SIZE) {
        strcpy(arr->items[arr->count], result);
        printf("Inserted result '%s' at position %d\n", result, arr->count);
        arr->count++;
    } else {
        // Archive oldest entry and shift
        printf("Archiving oldest result: %s\n", arr->items[0]);
        for (int i = 0; i < MAX_ARRAY_SIZE - 1; i++) {
            strcpy(arr->items[i], arr->items[i + 1]);
        }
        strcpy(arr->items[MAX_ARRAY_SIZE - 1], result);
        printf("Inserted result '%s' at position %d\n", result, MAX_ARRAY_SIZE - 1);
    }
}

void displayArray(LoadHistoryArray *arr) {
    printf("Load History Array: ");
    for (int i = 0; i < arr->count; i++) {
        printf("%s ", arr->items[i]);
    }
    printf("\n");
}

// Linked List implementations for Maintenance Tracker
typedef struct SinglyNode {
    char component[MAX_COMPONENT_NAME];
    struct SinglyNode *next;
} SinglyNode;

typedef struct DoublyNode {
    char component[MAX_COMPONENT_NAME];
    struct DoublyNode *prev;
    struct DoublyNode *next;
} DoublyNode;

typedef struct CircularNode {
    char component[MAX_COMPONENT_NAME];
    struct CircularNode *next;
} CircularNode;

SinglyNode* createSinglyNode(char *component) {
    SinglyNode *newNode = (SinglyNode*)malloc(sizeof(SinglyNode));
    strcpy(newNode->component, component);
    newNode->next = NULL;
    return newNode;
}

DoublyNode* createDoublyNode(char *component) {
    DoublyNode *newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    strcpy(newNode->component, component);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

CircularNode* createCircularNode(char *component) {
    CircularNode *newNode = (CircularNode*)malloc(sizeof(CircularNode));
    strcpy(newNode->component, component);
    newNode->next = NULL;
    return newNode;
}

void insertSinglyLinkedList(SinglyNode **head, char *component) {
    SinglyNode *newNode = createSinglyNode(component);
    if (*head == NULL) {
        *head = newNode;
    } else {
        SinglyNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %s into Singly Linked List (Stressed Components)\n", component);
}

void displaySinglyLinkedList(SinglyNode *head) {
    printf("Stressed Components (Singly Linked List): ");
    SinglyNode *temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->component);
        temp = temp->next;
    }
    printf("NULL\n");
}

SinglyNode* deleteSinglyNode(SinglyNode *head, char *component) {
    SinglyNode *temp = head, *prev = NULL;
   
    // If head node itself holds the component to be deleted
    if (temp != NULL && strcmp(temp->component, component) == 0) {
        head = temp->next;
        free(temp);
        printf("Deleted %s from Singly Linked List\n", component);
        return head;
    }
   
    // Search for the component to be deleted
    while (temp != NULL && strcmp(temp->component, component) != 0) {
        prev = temp;
        temp = temp->next;
    }
   
    // If component not found
    if (temp == NULL) {
        printf("%s not found in the list\n", component);
        return head;
    }
   
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("Deleted %s from Singly Linked List\n", component);
   
    return head;
}

void insertDoublyLinkedList(DoublyNode **head, char *component) {
    DoublyNode *newNode = createDoublyNode(component);
   
    if (*head == NULL) {
        *head = newNode;
    } else {
        DoublyNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %s into Doubly Linked List (Reinforced Components)\n", component);
}

void traverseDoublyLinkedListForward(DoublyNode *head) {
    printf("Reinforced Components (Forward Traversal): ");
    DoublyNode *temp = head;
    while (temp != NULL) {
        printf("%s <-> ", temp->component);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverseDoublyLinkedListBackward(DoublyNode *head) {
    printf("Reinforced Components (Backward Traversal): ");
   
    // Go to the last node
    DoublyNode *temp = head;
    if (temp == NULL) {
        printf("NULL\n");
        return;
    }
   
    while (temp->next != NULL) {
        temp = temp->next;
    }
   
    // Traverse backward
    while (temp != NULL) {
        printf("%s <-> ", temp->component);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void insertCircularLinkedList(CircularNode **head, char *component) {
    CircularNode *newNode = createCircularNode(component);
   
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Points to itself
    } else {
        CircularNode *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("Inserted %s into Circular Linked List (Priority Repairs)\n", component);
}



int getCircularLinkedListSize(CircularNode *head) {
    if (head == NULL) return 0;
   
    int count = 1;
    CircularNode *temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

void traverseCircularLinkedList(CircularNode *head, int cycles) {
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }
   
    printf("Priority Repairs (Circular Linked List - %d cycles): ", cycles);
    CircularNode *temp = head;
    int count = 0;
   
    do {
        printf("%s -> ", temp->component);
        temp = temp->next;
        count++;
       
        // Break after completing specified cycles
        if (temp == head) {
            printf("(cycle %d complete) ", (count / getCircularLinkedListSize(head)));
            if (--cycles == 0) break;
        }
    } while (temp != head || cycles > 0);
   
    printf("(back to start)\n");
}

void freeMemory(SinglyNode *stressedHead, DoublyNode *reinforcedHead, CircularNode *priorityHead) {
    // Free singly linked list
    SinglyNode *tempS = stressedHead, *nextS;
    while (tempS != NULL) {
        nextS = tempS->next;
        free(tempS);
        tempS = nextS;
    }
   
    // Free doubly linked list
    DoublyNode *tempD = reinforcedHead, *nextD;
    while (tempD != NULL) {
        nextD = tempD->next;
        free(tempD);
        tempD = nextD;
    }
   
    // Free circular linked list
    if (priorityHead != NULL) {
        CircularNode *current = priorityHead->next;
        CircularNode *temp;
        while (current != priorityHead) {
            temp = current;
            current = current->next;
            free(temp);
        }
        free(priorityHead);
    }
}

int main() {
    char componentName[MAX_COMPONENT_NAME];
    int choice, cycles;
   
    // Initialize data structures
    Queue loadQueue;
    initQueue(&loadQueue);
   
    Stack stressStack;
    initStack(&stressStack);
   
    LoadHistoryArray loadHistory;
    initArray(&loadHistory);
   
    SinglyNode *stressedComponents = NULL;
    DoublyNode *reinforcedComponents = NULL;
    CircularNode *priorityRepairs = NULL;
   
    do {
        printf("\nSMART BRIDGE LOAD MONITOR\n");
        printf("-------------------------\n");
        printf("1. Load and Stress Simulation\n");
        printf("2. Load History Unit Simulation\n");
        printf("3. Stressed Component Tracker\n");
        printf("4. Priority Repairs\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
       
        switch (choice) {
            case 1:
                printf("\n--- Load and Stress Simulation ---\n");
                printf("Adding 6 components to the queue\n");
               
                // Clear previous data
                initQueue(&loadQueue);
                initStack(&stressStack);
               
                for (int i = 0; i < 6; i++) {
                    printf("Enter component name %d: ", i + 1);
                    scanf("%s", componentName);
                    enqueue(&loadQueue, componentName);
                }
               
                displayQueue(&loadQueue);
               
                printf("\nDequeuing and pushing onto the stack\n");
                while (!isQueueEmpty(&loadQueue)) {
                    char *item = dequeue(&loadQueue);
                    if (item != NULL) {
                        push(&stressStack, item);
                    }
                }
               
                printf("\nPopping from stack to show check order\n");
                while (!isStackEmpty(&stressStack)) {
                    char *item = pop(&stressStack);
                    if (item != NULL) {
                        printf("Popped from stack: %s\n", item);
                    }
                }
                break;
               
            case 2:
                printf("\n--- Load History Unit Simulation ---\n");
               
                // Clear previous data
                initArray(&loadHistory);
               
                printf("Logging 8 test results into a 6-slot array\n");
                for (int i = 0; i < 8; i++) {
                    printf("Enter result %d: ", i + 1);
                    scanf("%s", componentName);
                    insertResult(&loadHistory, componentName);
                    displayArray(&loadHistory);
                }
               
                break;
               
            case 3:
                printf("\n--- Stressed Component Tracker ---\n");
               
                // Clear previous lists
                freeMemory(stressedComponents, reinforcedComponents, NULL);
                stressedComponents = NULL;
                reinforcedComponents = NULL;
               
                printf("Enter first stressed component: ");
                scanf("%s", componentName);
                insertSinglyLinkedList(&stressedComponents, componentName);
               
                printf("Enter second stressed component: ");
                scanf("%s", componentName);
                insertSinglyLinkedList(&stressedComponents, componentName);
               
                displaySinglyLinkedList(stressedComponents);
               
                printf("\nMoving first component to reinforced list after repair.\n");
                printf("Enter component to reinforce: ");
                scanf("%s", componentName);
               
                stressedComponents = deleteSinglyNode(stressedComponents, componentName);
                insertDoublyLinkedList(&reinforcedComponents, componentName);
               
                displaySinglyLinkedList(stressedComponents);
                traverseDoublyLinkedListForward(reinforcedComponents);
                traverseDoublyLinkedListBackward(reinforcedComponents);
               
                break;
               
            case 4:
                printf("\n--- Priority Repairs ---\n");
               
                // Clear previous circular list
                freeMemory(NULL, NULL, priorityRepairs);
                priorityRepairs = NULL;
               
                printf("Enter first component for urgent repair: ");
                scanf("%s", componentName);
                insertCircularLinkedList(&priorityRepairs, componentName);
               
                printf("Enter second component for urgent repair: ");
                scanf("%s", componentName);
                insertCircularLinkedList(&priorityRepairs, componentName);
               
                printf("Enter number of cycles to traverse: ");
                scanf("%d", &cycles);
                traverseCircularLinkedList(priorityRepairs, cycles);
               
                break;
               
            case 5:
                printf("\nExiting Smart Bridge Load Monitor System....\n");
                break;
               
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        printf("-----------------------------------------------------\n");
    } while (choice != 5);
   
    // Free all allocated memory
    freeMemory(stressedComponents, reinforcedComponents, priorityRepairs);
   
    return 0;
}
