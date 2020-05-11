#include <iostream>
#include "Tree.hpp"

TreeNode* newTreeNode(int d) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = d;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}


/*
 *  To insert, recurse down the tree until we reach the place we want to insert,
 *  then construct the new node and return it.
 *
 *  This means we have to reassign the left and right children as we recurse down the tree so we don't lose them
 */
TreeNode* insert(TreeNode *root, int data) {
    if (root == nullptr) {
        return newTreeNode(data);
    }
    else if (root->data < data) {
        root->right = insert(root->right, data);
    }
    else {
        root->left = insert(root->left, data);
    }
    return root;
}


/*
 * There are two successors: rightmost of left branch or leftmost of the right branch
 * Here we find the rightmost of the left branch
 */
TreeNode* findSuccessor(TreeNode* node) {
    node = node->left;
    while(node->right != nullptr)
        node = node->right;
    return node;
}


/*
 * Three cases to consider when deleting a node
 * 1. when the node has only a left child, save the right child, and delete the node
 * 2. when the node has only a right child, save the left child, and delete the node
 * 3. when the node has both children, then you need to find a successor
 */
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == nullptr)
        return root;

    TreeNode* temp;

    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if(root->left == nullptr) {
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == nullptr) {
            temp = root->left;
            free(root);
            return temp;
        }
        else {
            temp = findSuccessor(root);
            root->data = temp->data;
            root->left = deleteNode(root->left, root->data);
        }
    }
    return root;
}


void inorder(TreeNode *node) {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

