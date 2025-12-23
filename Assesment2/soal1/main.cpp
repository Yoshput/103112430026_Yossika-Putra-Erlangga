#include "bst.h"

int main() {
    adrNode root;
    createTree(root);

    insertNode(root, newNode("Rizkina Azizah", 60, "Basic"));
    insertNode(root, newNode("Hakan Ismail", 50, "Bronze"));
    insertNode(root, newNode("Olivia Saevali", 65, "Silver"));
    insertNode(root, newNode("Felix Pedrosa", 47, "Gold"));
    insertNode(root, newNode("Gamel Al Ghifari", 56, "Platinum"));
    insertNode(root, newNode("Hanif Al Faiz", 70, "Basic"));
    insertNode(root, newNode("Mutiara Fauziah", 52, "Bronze"));
    insertNode(root, newNode("Davi Ilyas", 68, "Silver"));
    insertNode(root, newNode("Abdad Mubarok", 81, "Gold"));

    cout << "=== Traversal InOrder ===" << endl;
    inOrder(root);
    cout << endl << endl;

    cout << "Node MostLeft  : " << mostLeft(root)->beratBadan << endl;
    cout << "Node MostRight : " << mostRight(root)->beratBadan << endl << endl;

    float target = 70;
    adrNode found = searchByBeratBadan(root, target);
    
    if (found != NULL) {
        cout << "Data ditemukan didalam BST!" << endl;
        cout << "--- Data Node Yang Dicari ---" << endl;
        cout << "Nama Member : " << found->namaMember << endl;
        cout << "Berat Badan : " << found->beratBadan << endl;
        cout << "Tier Member : " << found->tierMember << endl;
        cout << "-----------------------------" << endl;

        adrNode parent = findParent(root, target);
        if (parent != NULL) {
            cout << "--- Data Parent ---" << endl;
            cout << "Nama Member : " << parent->namaMember << endl;
            cout << "Berat Badan : " << parent->beratBadan << endl;
            cout << "Tier Member : " << parent->tierMember << endl;
            cout << "-----------------------------" << endl;
            
            if (parent->left == found && parent->right == NULL) cout << "Tidak Memiliki Sibling" << endl;
            else if (parent->right == found && parent->left == NULL) cout << "Tidak Memiliki Sibling" << endl;
          
            cout << "-----------------------------" << endl;
        }

        if (found->left != NULL) {
            cout << "--- Data Child Kiri ---" << endl;
            cout << "Nama Member : " << found->left->namaMember << endl;
            cout << "Berat Badan : " << found->left->beratBadan << endl;
            cout << "Tier Member : " << found->left->tierMember << endl;
        }
        cout << "-----------------------------" << endl;

        if (found->right != NULL) {
            cout << "--- Data Child Kanan ---" << endl;
            cout << "Nama Member : " << found->right->namaMember << endl;
            cout << "Berat Badan : " << found->right->beratBadan << endl;
            cout << "Tier Member : " << found->right->tierMember << endl;
        }
        cout << "-----------------------------" << endl;
    }

    return 0;
}