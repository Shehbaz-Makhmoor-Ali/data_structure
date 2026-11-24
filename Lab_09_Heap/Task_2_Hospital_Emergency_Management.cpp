#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

// Requirement 1: Create a Patient Node containing patient name, patient ID, priority level, and left/right pointers.
class Patient {
public:
    string name;
    int patientID;
    int priorityLevel;
    Patient* left;
    Patient* right;

    Patient(string patientName, int id, int priority) {
        name = patientName;
        patientID = id;
        priorityLevel = priority;
        left = NULL;
        right = NULL;
    }
};

class EmergencyMaxHeap {
private:
    Patient* root;

    void swapPatientData(Patient* a, Patient* b) {
        swap(a->name, b->name);
        swap(a->patientID, b->patientID);
        swap(a->priorityLevel, b->priorityLevel);
    }

    // Helper to find the parent of a given target node using Level Order Traversal
    Patient* findParent(Patient* target) {
        if (root == NULL || root == target) {
            return NULL;
        }
        queue<Patient*> q;
        q.push(root);
        while (!q.empty()) {
            Patient* curr = q.front();
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

    // Apply Heapify Up during insertion
    void heapifyUp(Patient* node) {
        if (node == NULL || node == root) {
            return;
        }
        Patient* parent = findParent(node);
        if (parent != NULL && node->priorityLevel > parent->priorityLevel) {
            swapPatientData(node, parent);
            heapifyUp(parent);
        }
    }

    // Apply Heapify Down during deletion
    void heapifyDown(Patient* node) {
        if (node == NULL) {
            return;
        }
        Patient* highest = node;

        if (node->left != NULL && node->left->priorityLevel > highest->priorityLevel) {
            highest = node->left;
        }
        if (node->right != NULL && node->right->priorityLevel > highest->priorityLevel) {
            highest = node->right;
        }

        if (highest != node) {
            swapPatientData(node, highest);
            heapifyDown(highest);
        }
    }

    void destroyTree(Patient* node) {
        if (node == NULL) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    EmergencyMaxHeap() {
        root = NULL;
    }

    ~EmergencyMaxHeap() {
        destroyTree(root);
    }

    // Requirement 2: Insert patients into a Max Heap according to their priority levels.
    void insertPatient(string name, int patientID, int priorityLevel) {
        Patient* newNode = new Patient(name, patientID, priorityLevel);
        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<Patient*> q;
        q.push(root);
        while (!q.empty()) {
            Patient* curr = q.front();
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

    // Requirement 3: Display all patients using Level Order Traversal.
    void displayLevelOrder() {
        if (root == NULL) {
            cout << "No patients in emergency queue." << endl;
            return;
        }

        queue<Patient*> q;
        q.push(root);
        int position = 1;

        cout << "---------------------------------------------------------" << endl;
        cout << "Pos\tPatient ID\tName\t\tPriority Level" << endl;
        cout << "---------------------------------------------------------" << endl;

        while (!q.empty()) {
            Patient* curr = q.front();
            q.pop();

            cout << position++ << "\t" << curr->patientID << "\t\t"
                 << curr->name << "\t\t" << curr->priorityLevel << endl;

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        cout << "---------------------------------------------------------" << endl;
    }

    // Requirement 4: Identify and display the patient with the highest priority.
    void displayHighestPriorityPatient() {
        if (root == NULL) {
            cout << "No patients waiting for treatment." << endl;
            return;
        }
        cout << "Patient ID: " << root->patientID
             << " | Name: " << root->name
             << " | Priority Level: " << root->priorityLevel << endl;
    }

    // Requirement 5 & 6: Delete the patient after treatment and apply Heapify Down.
    void deleteTreatedPatient() {
        if (root == NULL) {
            cout << "No patients to delete." << endl;
            return;
        }

        cout << "\nTreating and removing highest priority patient:" << endl;
        displayHighestPriorityPatient();

        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return;
        }

        // Find the last node in Level Order Traversal
        queue<Patient*> q;
        q.push(root);
        Patient* lastNode = NULL;

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

        Patient* parentOfLast = findParent(lastNode);

        // Copy last node data to root
        root->name = lastNode->name;
        root->patientID = lastNode->patientID;
        root->priorityLevel = lastNode->priorityLevel;

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
    EmergencyMaxHeap emergencyQueue;

    cout << "=== Task 2: Hospital Emergency Management System (Max Heap) ===" << endl;

    // Requirement 2: Insert at least six patients into a Max Heap according to their priority levels.
    emergencyQueue.insertPatient("Ahmed", 201, 5);
    emergencyQueue.insertPatient("Zainab", 202, 9);
    emergencyQueue.insertPatient("Hamza", 203, 3);
    emergencyQueue.insertPatient("Khadija", 204, 10);
    emergencyQueue.insertPatient("Omar", 205, 7);
    emergencyQueue.insertPatient("Mariam", 206, 8);

    // Requirement 3: Display all patients using Level Order Traversal.
    cout << "\nAll Emergency Patients (Level Order Traversal):" << endl;
    emergencyQueue.displayLevelOrder();

    // Requirement 4: Identify and display the patient with the highest priority.
    cout << "\nPatient with Highest Priority (Current Root):" << endl;
    emergencyQueue.displayHighestPriorityPatient();

    // Requirement 5: Delete the patient after treatment.
    emergencyQueue.deleteTreatedPatient();

    // Requirement 6: Apply Heapify Down and display the next patient who needs treatment.
    cout << "\nNext Patient Who Needs Treatment (After Heapify Down):" << endl;
    emergencyQueue.displayHighestPriorityPatient();

    cout << "\nUpdated Emergency Queue (Level Order Traversal):" << endl;
    emergencyQueue.displayLevelOrder();

    return 0;
}
