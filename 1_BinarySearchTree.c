#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * TOPIC: Binary Search Tree (BST)
 * ============================================================================
 * 
 * What is a Tree?
 * A tree is a hierarchical data structure consisting of nodes. 
 * The topmost node is called the root. Nodes can have child nodes.
 * 
 * What is a Binary Search Tree (BST)?
 * A BST is a special type of binary tree with the following properties:
 * 1. The left subtree of a node contains only nodes with keys LESS than the node's key.
 * 2. The right subtree of a node contains only nodes with keys GREATER than the node's key.
 * 3. The left and right subtrees must also be binary search trees.
 * 4. There must be no duplicate nodes (usually, or handled specifically).
 * ============================================================================
 */

// Define the structure for a Tree Node
struct Node {
    int data;           // The value stored in the node
    struct Node* left;  // Pointer to the left child
    struct Node* right; // Pointer to the right child
};

/*
 * Function: createNode
 * --------------------
 * Allocates memory for a new node and initializes its data and children.
 * 
 *  value: The integer data to store in the node
 *  returns: A pointer to the newly created node
 */
struct Node* createNode(int value) {
    // Dynamically allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation failed
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    // Initialize the node's properties
    newNode->data = value;
    newNode->left = NULL;   // New nodes are always added as leaf nodes initially
    newNode->right = NULL;
    
    return newNode;
}

/*
 * Function: insert
 * ----------------
 * Inserts a new value into the Binary Search Tree.
 * 
 *  root: Pointer to the root of the tree
 *  value: The integer value to insert
 *  returns: The pointer to the root of the tree
 */
struct Node* insert(struct Node* root, int value) {
    // Base Case: If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(value);
    }
    
    // Recursive Case: Traverse down the tree to find the correct insertion point
    if (value < root->data) {
        // If the value is less than the current node's data, go left
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        // If the value is greater than the current node's data, go right
        root->right = insert(root->right, value);
    }
    
    // Return the unchanged root pointer
    return root;
}

/*
 * Function: inorderTraversal
 * --------------------------
 * Traverses the tree in 'Inorder' perfectly suited for BSTs because it 
 * visits nodes in ascending sorted order.
 * Order: Left Subtree -> Root Node -> Right Subtree
 */
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);       // Visit left subtree
        printf("%d ", root->data);          // Print the data
        inorderTraversal(root->right);      // Visit right subtree
    }
}

/*
 * Function: preorderTraversal
 * ---------------------------
 * Traverses the tree in 'Preorder'. Useful for creating a copy of the tree.
 * Order: Root Node -> Left Subtree -> Right Subtree
 */
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);          // Print the data
        preorderTraversal(root->left);      // Visit left subtree
        preorderTraversal(root->right);     // Visit right subtree
    }
}

/*
 * Function: postorderTraversal
 * ----------------------------
 * Traverses the tree in 'Postorder'. Useful for deleting a tree.
 * Order: Left Subtree -> Right Subtree -> Root Node
 */
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);     // Visit left subtree
        postorderTraversal(root->right);    // Visit right subtree
        printf("%d ", root->data);          // Print the data
    }
}

/*
 * Function: search
 * ----------------
 * Searches for a specific value in the BST.
 * 
 *  root: Pointer to the root node
 *  value: The value to search for
 *  returns: Pointer to the node if found, NULL otherwise
 */
struct Node* search(struct Node* root, int value) {
    // Base cases: root is null (not found) or key is present at root (found)
    if (root == NULL || root->data == value) {
        return root;
    }
    
    // Value is greater than root's key, search in the right subtree
    if (root->data < value) {
        return search(root->right, value);
    }
    
    // Value is smaller than root's key, search in the left subtree
    return search(root->left, value);
}

// Driver code to test the Binary Search Tree
int main() {
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    
    struct Node* root = NULL;
    
    // Inserting elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("Inorder traversal of the given tree (Should be sorted):\n");
    inorderTraversal(root);
    printf("\n\n");
    
    printf("Preorder traversal of the given tree:\n");
    preorderTraversal(root);
    printf("\n\n");
    
    printf("Postorder traversal of the given tree:\n");
    postorderTraversal(root);
    printf("\n\n");
    
    // Searching for an element
    int target = 60;
    struct Node* foundNode = search(root, target);
    if (foundNode != NULL) {
        printf("Element %d found in the BST.\n", target);
    } else {
        printf("Element %d not found in the BST.\n", target);
    }

    return 0;
}
