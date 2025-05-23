#include <iostream>
#include <cstdlib>

using namespace std;

class Treap {

private:
    struct Node {
        int key;
        int priority;
        Node* left;
        Node* right;

        Node(int k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void merge(Node* left, Node* right, Node*& result) {
        if (!left) {
            result = right;
            return;
        }
        if (!right) {
            result = left;
            return;
        }

        if (left->priority > right->priority) {
            merge(left->right, right, left->right);
            result = left;
        }
        else {
            merge(left, right->left, right->left);
            result = right;
        }
    }

    void split(Node* node, int key, Node*& left, Node*& right) {
        if (!node) {
            left = right = nullptr;
            return;
        }

        if (node->key <= key) {
            split(node->right, key, node->right, right);
            left = node;
        }
        else {
            split(node->left, key, left, node->left);
            right = node;
        }
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    Treap() : root(nullptr) { srand(time(0)); }

    ~Treap() {
        clear(root);
    }

    void insert(int key) {
        Node* left = nullptr;
        Node* right = nullptr;
        split(root, key, left, right);

        Node* newNode = new Node(key);
        merge(left, newNode, left);
        merge(left, root, root);
    }

    void remove(int key) {
        Node* left = nullptr;
        Node* middle = nullptr;
        Node* right = nullptr;

        split(root, key - 1, left, middle);
        split(middle, key, middle, right);

        merge(left, right, root);
    }

    bool find(int key) {
        Node* left = nullptr;
        Node* midle = nullptr;
        Node* right = nullptr;

        split(root, key - 1, left, midle);
        split(midle, key, midle, right);

        bool found = (midle != nullptr);

        merge(left, midle, left);
        merge(left, right, root);

        return found;
    }

    void preOrder() {
        preOrder(root);
        cout << endl;
    }

private:
    void preOrder(Node* node) {
        if (!node) return;
        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
};