#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct Node {
    int data;               // Data part of the node
    struct Node* next;      // Pointer to the next node
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {  // Check if memory allocation was successful
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;   // Set the data part
    newNode->next = NULL;   // Set the next part to NULL initially
    return newNode;         // Return the newly created node
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a node in the linked list
struct Node* search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;    // Return the node if data matches the key
        }
        temp = temp->next;
    }
    return NULL;            // Return NULL if the key is not found
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;  // Link the new node to the old head
    *head = newNode;        // Update head to the new node
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;    // If the list is empty, make the new node the head
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;  // Traverse to the last node
    }
    temp->next = newNode;   // Link the last node to the new node
}

// Function to delete a node with a given key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {  // If head node itself holds the key
        *head = temp->next;                   // Change head
        free(temp);                           // Free old head
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found\n");
        return;                               // Key was not present in the list
    }

    prev->next = temp->next;                  // Unlink the node from the list
    free(temp);                               // Free memory
}

// Main function with a menu-driven switch-case
int main() {
    struct Node* head = NULL;                 // Initialize an empty linked list
    int choice, value, key;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Search Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                printf("Node inserted at the beginning.\n");
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("Node inserted at the end.\n");
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &key);
                struct Node* found = search(head, key);
                if (found != NULL) {
                    printf("Node with value %d found.\n", key);
                } else {
                    printf("Node with value %d not found.\n", key);
                }
                break;

            case 5:
                printf("Linked List: ");
                display(head);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 6);

    return 0;
}