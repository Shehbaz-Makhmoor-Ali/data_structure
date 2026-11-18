#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    int number;
    string destination, time;
    Node *left, *right;
    Node(int n, string d, string t) {
        number = n; destination = d; time = t;
        left = right = NULL;
    }
};
class FlightBST {
public:
    Node *root;
    FlightBST() { root = NULL; }
    Node* insert(Node* node, int n, string d, string t) {
        if (!node) return new Node(n, d, t);
        if (n < node->number) node->left = insert(node->left, n, d, t);
        else if (n > node->number) node->right = insert(node->right, n, d, t);
        return node;
    }
    void insert(int n, string d, string t) { root = insert(root, n, d, t); }
    Node* search(int n) {
        Node* node = root;
        while (node && node->number != n)
            node = (n < node->number) ? node->left : node->right;
        return node;
    }
    Node* remove(Node* node, int n) {
        if (!node) return NULL;
        if (n < node->number) node->left = remove(node->left, n);
        else if (n > node->number) node->right = remove(node->right, n);
        else {
            if (!node->left) { Node* r = node->right; delete node; return r; }
            if (!node->right) { Node* l = node->left; delete node; return l; }
            Node* s = node->right;
            while (s->left) s = s->left;
            node->number = s->number;
            node->destination = s->destination;
            node->time = s->time;
            node->right = remove(node->right, s->number);
        }
        return node;
    }
    void remove(int n) { root = remove(root, n); }
    void print(Node* node) { cout << node->number << " " << node->destination << " " << node->time << endl; }
    void inorder(Node* node) {
        if (node) { inorder(node->left); print(node); inorder(node->right); }
    }
    void preorder(Node* node) {
        if (node) { print(node); preorder(node->left); preorder(node->right); }
    }
    void postorder(Node* node) {
        if (node) { postorder(node->left); postorder(node->right); print(node); }
    }
    Node* minimum() {
        Node* node = root;
        while (node->left) node = node->left;
        return node;
    }
    Node* maximum() {
        Node* node = root;
        while (node->right) node = node->right;
        return node;
    }
    int count(Node* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }
    int height(Node* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    void display(Node* node, int level = 0) {
        if (node) {
            display(node->right, level + 1);
            cout << string(level * 3, ' ') << node->number << endl;
            display(node->left, level + 1);
        }
    }
};
int main() {
    FlightBST tree;
    tree.insert(500, "Dubai", "08:00");
    tree.insert(300, "London", "09:30");
    tree.insert(700, "Doha", "10:15");
    tree.insert(200, "Paris", "11:00");
    tree.insert(400, "Istanbul", "12:45");
    tree.insert(600, "Riyadh", "13:20");
    tree.insert(800, "Karachi", "14:10");
    tree.insert(100, "Toronto", "15:00");
    tree.insert(250, "Berlin", "16:30");
    tree.insert(350, "Rome", "17:15");
    tree.insert(450, "Tokyo", "18:40");
    tree.insert(750, "Lahore", "19:25");
    cout << "Search 400:" << endl;
    Node* found = tree.search(400);
    if (found) tree.print(found); else cout << "Not found" << endl;
    cout << "Search 999: " << (tree.search(999) ? "Found" : "Not found") << endl;
    cout << "\nIn-order:" << endl;
    tree.inorder(tree.root);
    cout << "\nPre-order:" << endl;
    tree.preorder(tree.root);
    cout << "\nPost-order:" << endl;
    tree.postorder(tree.root);
    cout << "\nMinimum flight: " << tree.minimum()->number << endl;
    cout << "Maximum flight: " << tree.maximum()->number << endl;
    cout << "Total flights: " << tree.count(tree.root) << endl;
    cout << "Height: " << tree.height(tree.root) << endl;
    cout << "\nInitial structure:" << endl;
    tree.display(tree.root);
    cout << "\nDelete 100 (leaf)" << endl;
    tree.remove(100);
    cout << "Delete 200 (one child)" << endl;
    tree.remove(200);
    cout << "Delete 500 (two children)" << endl;
    tree.remove(500);
    cout << "\nFinal structure:" << endl;
    tree.display(tree.root);
    cout << "\nIn-order after deletion:" << endl;
    tree.inorder(tree.root);
    cout << "Total flights: " << tree.count(tree.root) << endl;
    cout << "Height: " << tree.height(tree.root) << endl;
    return 0;
}