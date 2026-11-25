#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

// Requirement 1: Create a Medicine Node containing medicine name, medicine ID, expiry date, and left/right pointers.
class Medicine {
public:
    string name;
    int medicineID;
    int expiryDate; // Format: YYYYMMDD
    Medicine* left;
    Medicine* right;

    Medicine(string medName, int id, int expDate) {
        name = medName;
        medicineID = id;
        expiryDate = expDate;
        left = NULL;
        right = NULL;
    }
};

class MedicineMinHeap {
private:
    Medicine* root;

    void swapMedicineData(Medicine* a, Medicine* b) {
        swap(a->name, b->name);
        swap(a->medicineID, b->medicineID);
        swap(a->expiryDate, b->expiryDate);
    }

    // Helper to find the parent of a given target node using Level Order Traversal
    Medicine* findParent(Medicine* target) {
        if (root == NULL || root == target) {
            return NULL;
        }
        queue<Medicine*> q;
        q.push(root);
        while (!q.empty()) {
            Medicine* curr = q.front();
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

    // Requirement 3: Apply Heapify Up after every insertion (Min Heap: smaller expiry date bubbles up).
    void heapifyUp(Medicine* node) {
        if (node == NULL || node == root) {
            return;
        }
        Medicine* parent = findParent(node);
        if (parent != NULL && node->expiryDate < parent->expiryDate) {
            swapMedicineData(node, parent);
            heapifyUp(parent);
        }
    }

    // Requirement 6: Apply Heapify Down after root deletion (Min Heap: smallest expiry date moves up).
    void heapifyDown(Medicine* node) {
        if (node == NULL) {
            return;
        }
        Medicine* nearest = node;

        if (node->left != NULL && node->left->expiryDate < nearest->expiryDate) {
            nearest = node->left;
        }
        if (node->right != NULL && node->right->expiryDate < nearest->expiryDate) {
            nearest = node->right;
        }

        if (nearest != node) {
            swapMedicineData(node, nearest);
            heapifyDown(nearest);
        }
    }

    void destroyTree(Medicine* node) {
        if (node == NULL) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    MedicineMinHeap() {
        root = NULL;
    }

    ~MedicineMinHeap() {
        destroyTree(root);
    }

    // Requirement 2: Insert medicines into a Min Heap using expiry dates in YYYYMMDD format.
    void insertMedicine(string name, int medicineID, int expiryDate) {
        Medicine* newNode = new Medicine(name, medicineID, expiryDate);
        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<Medicine*> q;
        q.push(root);
        while (!q.empty()) {
            Medicine* curr = q.front();
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

    // Requirement 4: Display the Heap using Level Order Traversal.
    void displayLevelOrder() {
        if (root == NULL) {
            cout << "Medicine inventory heap is empty." << endl;
            return;
        }

        queue<Medicine*> q;
        q.push(root);
        int position = 1;

        cout << "---------------------------------------------------------------" << endl;
        cout << "Pos\tMed ID\t\tMedicine Name\t\tExpiry (YYYYMMDD)" << endl;
        cout << "---------------------------------------------------------------" << endl;

        while (!q.empty()) {
            Medicine* curr = q.front();
            q.pop();

            cout << position++ << "\t" << curr->medicineID << "\t\t"
                 << curr->name << "\t\t" << curr->expiryDate << endl;

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        cout << "---------------------------------------------------------------" << endl;
    }

    // Requirement 5 & 6: Identify and delete the medicine with the nearest expiry date, then apply Heapify Down.
    void deleteNearestExpiryMedicine() {
        if (root == NULL) {
            cout << "No medicines in inventory to delete." << endl;
            return;
        }

        cout << "\nMedicine with Nearest Expiry Date (Root):" << endl;
        cout << "Medicine ID: " << root->medicineID
             << " | Name: " << root->name
             << " | Expiry Date: " << root->expiryDate << endl;
        cout << "Removing this medicine from inventory..." << endl;

        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return;
        }

        // Find the last node in Level Order Traversal
        queue<Medicine*> q;
        q.push(root);
        Medicine* lastNode = NULL;

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

        Medicine* parentOfLast = findParent(lastNode);

        // Copy last node data to root
        root->name = lastNode->name;
        root->medicineID = lastNode->medicineID;
        root->expiryDate = lastNode->expiryDate;

        // Disconnect and delete the last node
        if (parentOfLast->right == lastNode) {
            parentOfLast->right = NULL;
        } else if (parentOfLast->left == lastNode) {
            parentOfLast->left = NULL;
        }
        delete lastNode;

        // Apply Heapify Down from root
        heapifyDown(root);
    }
};

int main() {
    MedicineMinHeap medStore;

    cout << "=== Task 4: Hospital Medicine Expiry Management (Min Heap) ===" << endl;

    // Requirement 2: Insert at least six medicines into a Min Heap using expiry dates in YYYYMMDD format.
    medStore.insertMedicine("Paracetamol", 401, 20270515);
    medStore.insertMedicine("Amoxicillin", 402, 20261210);
    medStore.insertMedicine("Ibuprofen", 403, 20280120);
    medStore.insertMedicine("Insulin", 404, 20261130);
    medStore.insertMedicine("Cetirizine", 405, 20270805);
    medStore.insertMedicine("Aspirin", 406, 20270218);

    // Requirement 4: Display the Heap using Level Order Traversal.
    cout << "\nMin Heap of Medicines (Level Order Traversal):" << endl;
    medStore.displayLevelOrder();

    // Requirement 5: Identify and delete the medicine with the nearest expiry date.
    medStore.deleteNearestExpiryMedicine();

    // Requirement 6: Apply Heapify Down and display the updated Heap.
    cout << "\nUpdated Min Heap after deleting Nearest Expiry Medicine & applying Heapify Down:" << endl;
    medStore.displayLevelOrder();

    return 0;
}
