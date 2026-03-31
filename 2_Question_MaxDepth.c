#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * QUESTION: Maximum Depth (or Height) of a Binary Tree
 * ============================================================================
 * 
 * Problem Statement:
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path 
 * from the root node down to the farthest leaf node.
 * 
 * For example:
 * Given binary tree:
 * 
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 * 
 * Return its depth = 3.
 * ============================================================================
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*
 * Function: maxDepth
 * ------------------
 * Logic:
 * We can solve this using recursion (Depth-First Search).
 * The maximum depth of a tree rooted at node X is:
 * 1 + maximum(depth of left subtree, depth of right subtree)
 * 
 * Base case: If the node is NULL, its depth is 0.
 */
int maxDepth(struct TreeNode* root) {
    // Base condition: an empty tree has a depth of 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursively find the depth of the left subtree
    int leftDepth = maxDepth(root->left);
    
    // Recursively find the depth of the right subtree
    int rightDepth = maxDepth(root->right);
    
    // The total height is 1 (for the current root) plus the maximum of the two subtrees
    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
}

// Driver Code
int main() {
    // Constructing the tree from the example:
    //      3
    //     / \
    //    9  20
    //      /  \
    //     15   7
    
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
    
    printf("The maximum depth of the given binary tree is: %d\n", maxDepth(root));
    
    // Clean up memory (Important practice in C!)
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);
    
    return 0;
}
