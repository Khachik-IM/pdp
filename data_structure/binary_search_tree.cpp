#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node *insert(Node *root, int data) {
        if (!root) {
            return new Node(data);
        }

        if (data > root->data) {
            root->right = insert(root->right, data);
        }
        else {
            root->left = insert(root->left, data);
        }
        return root;
    }

    // Top -> left child -> right child
    void preOrder(Node *root) {
        if (root == NULL) {
            return;
        }

        std::cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }

    // left child -> right child -> Top
    void postOrder(Node *root) {
        if (root->left) {
            postOrder(root->left);
            if (root->right) {
                postOrder(root->right);
            }
            std::cout << root->data << " ";
        }
        else if (root->right) {
            postOrder(root->right);
            std::cout << root->data << " ";
        }
        else {
            std::cout << root->data << " ";
        }
    }

    // Left child -> top -> right child
    void inOrder(Node *root) {
        if(!root) {
            return;
        }
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }
    
    int height(Node* root) {
        return findHeight(root) - 1;
    }

    Node *lca(Node *root, int v1, int v2) {
        if (root == nullptr)
            return nullptr;

        if (root->data > max(v1, v2))
            return lca(root->left, v1, v2);

        else  if (root->data < min(v1, v2))
            return lca(root->right, v1, v2);

        return root;
    }
    
private: 
    int findMax(int a, int b){
        if(a >= b) {
            return a;
        } else {
            return b;
        }
    }

    int findHeight(Node* root){
        if(root == NULL) {
            return 0;
        }

        return findMax(findHeight(root->left), findHeight(root->right)) + 1;
    }
};

int main() {
    Tree tree;
    Node *root = NULL;

    root = tree.insert(root, 5);
    root = tree.insert(root, 10);
    root = tree.insert(root, 7);
    root = tree.insert(root, 90);
    root = tree.insert(root, 55);
    root = tree.insert(root, 12);
    root = tree.insert(root, 5);
    root = tree.insert(root, 0);

    tree.preOrder(root);
    std::cout << std::endl;
    tree.postOrder(root);
    std::cout << std::endl;
    tree.inOrder(root);
    std::cout << std::endl;
    std::cout << "height > " << tree.height(root) << std::endl;
    std::cout << "lca - " << tree.lca(root, 7, 0)->data << std::endl;

    return 0;
}
