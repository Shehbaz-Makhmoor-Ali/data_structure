#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// Requirement 1: Create an Order Node containing order ID, customer name, order amount, and left/right pointers.
class Order {
public:
    int orderID;
    string customerName;
    double orderAmount;
    Order* left;
    Order* right;

    Order(int id, string name, double amount) {
        orderID = id;
        customerName = name;
        orderAmount = amount;
        left = NULL;
        right = NULL;
    }
};

class OrderMaxHeap {
private:
    Order* root;

    void swapOrderData(Order* a, Order* b) {
        swap(a->orderID, b->orderID);
        swap(a->customerName, b->customerName);
        swap(a->orderAmount, b->orderAmount);
    }

    // Helper to find the parent of a given target node using Level Order Traversal
    Order* findParent(Order* target) {
        if (root == NULL || root == target) {
            return NULL;
        }
        queue<Order*> q;
        q.push(root);
        while (!q.empty()) {
            Order* curr = q.front();
            q.pop();

            if (curr->left == target || curr->right == target) {
                return curr;
            }
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        return NULL;
    }

    // Requirement 3: Apply Heapify Up during insertion.
    void heapifyUp(Order* node) {
        if (node == NULL || node == root) {
            return;
        }
        Order* parent = findParent(node);
        if (parent != NULL && node->orderAmount > parent->orderAmount) {
            swapOrderData(node, parent);
            heapifyUp(parent);
        }
    }

    // Apply Heapify Down during root deletion
    void heapifyDown(Order* node) {
        if (node == NULL) {
            return;
        }
        Order* largest = node;

        if (node->left != NULL && node->left->orderAmount > largest->orderAmount) {
            largest = node->left;
        }
        if (node->right != NULL && node->right->orderAmount > largest->orderAmount) {
            largest = node->right;
        }

        if (largest != node) {
            swapOrderData(node, largest);
            heapifyDown(largest);
        }
    }

    void destroyTree(Order* node) {
        if (node == NULL) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    OrderMaxHeap() {
        root = NULL;
    }

    ~OrderMaxHeap() {
        destroyTree(root);
    }

    bool isEmpty() {
        return root == NULL;
    }

    // Requirement 2: Insert orders into a Max Heap according to their order amounts.
    void insertOrder(int orderID, string customerName, double orderAmount) {
        Order* newNode = new Order(orderID, customerName, orderAmount);
        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<Order*> q;
        q.push(root);
        while (!q.empty()) {
            Order* curr = q.front();
            q.pop();

            if (curr->left == NULL) {
                curr->left = newNode;
                heapifyUp(newNode);
                return;
            } else {
                q.push(curr->left);
            }

            if (curr->right == NULL) {
                curr->right = newNode;
                heapifyUp(newNode);
                return;
            } else {
                q.push(curr->right);
            }
        }
    }

    void displayLevelOrder() {
        if (root == NULL) {
            cout << "Heap is empty." << endl;
            return;
        }

        queue<Order*> q;
        q.push(root);
        int position = 1;

        cout << "---------------------------------------------------------" << endl;
        cout << "Pos\tOrder ID\tCustomer\tOrder Amount" << endl;
        cout << "---------------------------------------------------------" << endl;

        while (!q.empty()) {
            Order* curr = q.front();
            q.pop();

            cout << position++ << "\t" << curr->orderID << "\t\t"
                 << curr->customerName << "\t\t$" << curr->orderAmount << endl;

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        cout << "---------------------------------------------------------" << endl;
    }

    // Delete the root order and return a copy of its data
    Order deleteRootOrder() {
        Order deletedOrder(root->orderID, root->customerName, root->orderAmount);

        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return deletedOrder;
        }

        // Find the last node in Level Order Traversal
        queue<Order*> q;
        q.push(root);
        Order* lastNode = NULL;

        while (!q.empty()) {
            lastNode = q.front();
            q.pop();

            if (lastNode->left != NULL) {
                q.push(lastNode->left);
            }
            if (lastNode->right != NULL) {
                q.push(lastNode->right);
            }
        }

        Order* parentOfLast = findParent(lastNode);

        // Copy last node data to root
        root->orderID = lastNode->orderID;
        root->customerName = lastNode->customerName;
        root->orderAmount = lastNode->orderAmount;

        // Disconnect and delete the last node
        if (parentOfLast->right == lastNode) {
            parentOfLast->right = NULL;
        } else if (parentOfLast->left == lastNode) {
            parentOfLast->left = NULL;
        }
        delete lastNode;

        // Apply Heapify Down from root
        heapifyDown(root);

        return deletedOrder;
    }

    // Requirement 4, 5 & 6: Implement Heap Sort using repeated root deletion, store deleted order amounts, and display in ascending order.
    void heapSortAndDisplay() {
        vector<Order> deletedOrders;

        while (!isEmpty()) {
            deletedOrders.push_back(deleteRootOrder());
        }

        // Since Max Heap deletes from largest to smallest, reverse to get ascending order (smallest to largest)
        reverse(deletedOrders.begin(), deletedOrders.end());

        cout << "\nSorted Customer Orders (Ascending Order - Smallest to Largest):" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Rank\tOrder ID\tCustomer\tOrder Amount" << endl;
        cout << "---------------------------------------------------------" << endl;
        for (size_t i = 0; i < deletedOrders.size(); i++) {
            cout << (i + 1) << "\t" << deletedOrders[i].orderID << "\t\t"
                 << deletedOrders[i].customerName << "\t\t$" << deletedOrders[i].orderAmount << endl;
        }
        cout << "---------------------------------------------------------" << endl;

        cout << "\nOrder Amounts in Ascending Order: ";
        for (size_t i = 0; i < deletedOrders.size(); i++) {
            cout << "$" << deletedOrders[i].orderAmount;
            if (i + 1 < deletedOrders.size()) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    OrderMaxHeap orderHeap;

    cout << "=== Task 3: Online Shopping Order Sorting (Heap Sort) ===" << endl;

    // Requirement 2: Insert at least six orders into a Max Heap according to their order amounts.
    orderHeap.insertOrder(301, "Ali", 250.50);
    orderHeap.insertOrder(302, "Sara", 120.00);
    orderHeap.insertOrder(303, "Bilal", 540.75);
    orderHeap.insertOrder(304, "Ayesha", 89.99);
    orderHeap.insertOrder(305, "Usman", 310.25);
    orderHeap.insertOrder(306, "Fatima", 430.00);

    cout << "\nInitial Max Heap of Customer Orders (Level Order Traversal):" << endl;
    orderHeap.displayLevelOrder();

    // Requirement 4, 5, 6: Perform Heap Sort by repeated root deletion and display in ascending order.
    orderHeap.heapSortAndDisplay();

    return 0;
}
