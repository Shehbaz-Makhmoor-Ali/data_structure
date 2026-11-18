#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Node {
public:
    int id, height;
    string location, severity;
    Node *left, *right;
    Node(int i, string l, string s) {
        id = i; location = l; severity = s;
        height = 1;
        left = right = NULL;
    }
};
class EmergencyAVL {
public:
    Node* root;
    EmergencyAVL() { root = NULL; }
    int height(Node* node) { return node ? node->height : 0; }
    int balance(Node* node) { return node ? height(node->left) - height(node->right) : 0; }
    void update(Node* node) { node->height = 1 + max(height(node->left), height(node->right)); }
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;
        update(y);
        update(x);
        return x;
    }
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        update(x);
        update(y);
        return y;
    }
    Node* rebalance(Node* node) {
        update(node);
        int b = balance(node);
        if (b > 1) {
            if (balance(node->left) < 0) node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (b < -1) {
            if (balance(node->right) > 0) node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }
    Node* insert(Node* node, int i, string l, string s) {
        if (!node) return new Node(i, l, s);
        if (i < node->id) node->left = insert(node->left, i, l, s);
        else if (i > node->id) node->right = insert(node->right, i, l, s);
        else return node;
        return rebalance(node);
    }
    void insert(int i, string l, string s) { root = insert(root, i, l, s); }
    Node* search(int i) {
        Node* node = root;
        while (node && node->id != i)
            node = (i < node->id) ? node->left : node->right;
        return node;
    }
    Node* remove(Node* node, int i) {
        if (!node) return NULL;
        if (i < node->id) node->left = remove(node->left, i);
        else if (i > node->id) node->right = remove(node->right, i);
        else {
            if (!node->left) { Node* r = node->right; delete node; return r; }
            if (!node->right) { Node* l = node->left; delete node; return l; }
            Node* s = node->right;
            while (s->left) s = s->left;
            node->id = s->id;
            node->location = s->location;
            node->severity = s->severity;
            node->right = remove(node->right, s->id);
        }
        return rebalance(node);
    }
    void remove(int i) { root = remove(root, i); }
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->id << " " << node->location << " " << node->severity
                 << " | height: " << node->height << " | balance: " << balance(node) << endl;
            inorder(node->right);
        }
    }
    void levelOrder() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->id << " " << node->location << " " << node->severity << endl;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    void display(Node* node, int level = 0) {
        if (node) {
            display(node->right, level + 1);
            cout << string(level * 3, ' ') << node->id << endl;
            display(node->left, level + 1);
        }
    }
};
int main() {
    EmergencyAVL tree;
    tree.insert(10, "Islamabad", "High");
    tree.insert(20, "Lahore", "Medium");
    tree.insert(30, "Karachi", "High");
    tree.insert(40, "Quetta", "Low");
    tree.insert(50, "Peshawar", "High");
    tree.insert(25, "Multan", "Medium");
    tree.insert(5, "Swat", "Low");
    tree.insert(4, "Gilgit", "High");
    tree.insert(3, "Murree", "Medium");
    tree.insert(60, "Sukkur", "Low");
    tree.insert(55, "Hyderabad", "High");
    tree.insert(45, "Faisalabad", "Medium");
    cout << "Search 25:" << endl;
    Node* found = tree.search(25);
    if (found) cout << found->id << " " << found->location << " " << found->severity << endl;
    else cout << "Not found" << endl;
    cout << "Search 99: " << (tree.search(99) ? "Found" : "Not found") << endl;
    cout << "\nIn-order (ID, height, balance factor):" << endl;
    tree.inorder(tree.root);
    cout << "\nLevel-order:" << endl;
    tree.levelOrder();
    cout << "\nAll records by emergency ID:" << endl;
    tree.inorder(tree.root);
    cout << "\nBalanced structure:" << endl;
    tree.display(tree.root);
    cout << "\nDelete 3, 4, 5" << endl;
    tree.remove(3);
    tree.remove(4);
    tree.remove(5);
    cout << "\nStructure after deletion:" << endl;
    tree.display(tree.root);
    cout << "\nIn-order after deletion:" << endl;
    tree.inorder(tree.root);
    cout << "\nLevel-order after deletion:" << endl;
    tree.levelOrder();
    return 0;
}