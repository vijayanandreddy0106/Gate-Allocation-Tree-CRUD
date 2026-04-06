#include <stdio.h>
#include <stdlib.h>

// Structure
struct Node {
    int gateNo;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* createNode(int gateNo) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->gateNo = gateNo;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert (CREATE)
struct Node* insert(struct Node* root, int gateNo) {
    if (root == NULL)
        return createNode(gateNo);

    if (gateNo < root->gateNo)
        root->left = insert(root->left, gateNo);
    else if (gateNo > root->gateNo)
        root->right = insert(root->right, gateNo);
    else
        printf("Gate already exists!\n");

    return root;
}

// Find Minimum
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

// Delete (DELETE)
struct Node* deleteNode(struct Node* root, int gateNo) {
    if (root == NULL) {
        printf("Gate not found!\n");
        return root;
    }

    if (gateNo < root->gateNo)
        root->left = deleteNode(root->left, gateNo);
    else if (gateNo > root->gateNo)
        root->right = deleteNode(root->right, gateNo);
    else {
        // Node found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            printf("Gate deleted!\n");
            return NULL;
        }

        // Case 2: One child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            printf("Gate deleted!\n");
            return temp;
        }

        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            printf("Gate deleted!\n");
            return temp;
        }

        // Case 3: Two children
        struct Node* temp = findMin(root->right);
        root->gateNo = temp->gateNo;
        root->right = deleteNode(root->right, temp->gateNo);
    }

    return root;
}

// Search (READ)
void search(struct Node* root, int gateNo) {
    if (root == NULL) {
        printf("Gate not found!\n");
        return;
    }

    if (gateNo == root->gateNo) {
        printf("Gate %d found!\n", gateNo);
    } else if (gateNo < root->gateNo) {
        search(root->left, gateNo);
    } else {
        search(root->right, gateNo);
    }
}

// Display (READ)
void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("Gate %d  ", root->gateNo);
        display(root->right);
    }
}

// Update
struct Node* update(struct Node* root, int oldGate, int newGate) {
    // Check if old gate exists
    struct Node* temp = root;
    int found = 0;

    while (temp != NULL) {
        if (oldGate == temp->gateNo) {
            found = 1;
            break;
        } else if (oldGate < temp->gateNo) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    if (!found) {
        printf("Old gate not found!\n");
        return root;
    }

    root = deleteNode(root, oldGate);
    root = insert(root, newGate);

    printf("Gate updated successfully!\n");
    return root;
}

// Main
int main() {
    struct Node* root = NULL;
    int choice, gateNo, oldGate, newGate;

    while (1) {
        printf("\n--- AIRPORT GATE MENU ---\n");
        printf("1. Add Gate\n");
        printf("2. Delete Gate\n");
        printf("3. Update Gate\n");
        printf("4. Search Gate\n");
        printf("5. Display Gates\n");
        printf("6. Exit\n");

        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 0;
        }

        switch (choice) {
            case 1:
                printf("Enter gate number: ");
                scanf("%d", &gateNo);
                root = insert(root, gateNo);
                break;

            case 2:
                printf("Enter gate to delete: ");
                scanf("%d", &gateNo);
                root = deleteNode(root, gateNo);
                break;

            case 3:
                printf("Enter old gate: ");
                scanf("%d", &oldGate);
                printf("Enter new gate: ");
                scanf("%d", &newGate);
                root = update(root, oldGate, newGate);
                break;

            case 4:
                printf("Enter gate to search: ");
                scanf("%d", &gateNo);
                search(root, gateNo);
                break;

            case 5:
                if (root == NULL)
                    printf("No gates available!\n");
                else {
                    printf("Gates: ");
                    display(root);
                    printf("\n");
                }
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}