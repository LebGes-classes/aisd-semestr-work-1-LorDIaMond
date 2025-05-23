#pragma once

class Treap {
private:
    struct Node {
        int key;
        int priority;
        Node* left;
        Node* right;

        Node(int k);
    };

    Node* root;

    void merge(Node* left, Node* right, Node*& result);
    void split(Node* node, int key, Node*& left, Node*& right);
    void clear(Node* node);

public:
    Treap();
    ~Treap();

    void insert(int key);
    void remove(int key);
    bool find(int key);
    void preOrder();

private:
    void preOrder(Node* node);
};
