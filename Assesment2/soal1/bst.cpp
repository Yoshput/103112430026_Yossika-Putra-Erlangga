#include "bst.h"

void createTree(adrNode &root) {
    root = NULL;
}

bool isEmpty(adrNode root) {
    return root == NULL;
}

adrNode newNode(string nama, float berat, string tier) {
    adrNode P = new Node;
    P->namaMember = nama;
    P->beratBadan = berat;
    P->tierMember = tier;
    P->left = NULL;
    P->right = NULL;
    return P;
}

void insertNode(adrNode &root, adrNode P) {
    if (isEmpty(root)) {
        root = P;
    } else {
        if (P->beratBadan < root->beratBadan) {
            insertNode(root->left, P);
        } else if (P->beratBadan > root->beratBadan) {
            insertNode(root->right, P);
        }
    }
}

adrNode searchByBeratBadan(adrNode root, float berat) {
    if (root == NULL || root->beratBadan == berat) {
        return root;
    }
    if (berat < root->beratBadan) {
        return searchByBeratBadan(root->left, berat);
    }
    return searchByBeratBadan(root->right, berat);
}

adrNode findParent(adrNode root, float berat) {
    if (root == NULL || root->beratBadan == berat) return NULL;
    
    if ((root->left != NULL && root->left->beratBadan == berat) || 
        (root->right != NULL && root->right->beratBadan == berat)) {
        return root;
    }
    
    if (berat < root->beratBadan) {
        return findParent(root->left, berat);
    } else {
        return findParent(root->right, berat);
    }
}

adrNode mostLeft(adrNode root) {
    if (root == NULL) return NULL;
    adrNode temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

adrNode mostRight(adrNode root) {
    if (root == NULL) return NULL;
    adrNode temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

void inOrder(adrNode root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}