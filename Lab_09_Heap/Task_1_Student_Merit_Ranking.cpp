#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

// Requirement 1: Create a Student Node containing student name, roll number, marks, and left/right pointers.
class Student {
public:
    string name;
    int rollNumber;
    double marks;
    Student* left;
    Student* right;

    Student(string studentName, int roll, double obtainedMarks) {
        name = studentName;
        rollNumber = roll;
        marks = obtainedMarks;
        left = NULL;
        right = NULL;
    }
};

class MaxHeap {
private:
    Student* root;

    void swapStudentData(Student* a, Student* b) {
        swap(a->name, b->name);
        swap(a->rollNumber, b->rollNumber);
        swap(a->marks, b->marks);
    }

    // Helper to find the parent of a given target node using Level Order Traversal
    Student* findParent(Student* target) {
        if (root == NULL || root == target) {
            return NULL;
        }
        queue<Student*> q;
        q.push(root);
        while (!q.empty()) {
            Student* curr = q.front();
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

    // Requirement 3: Apply Heapify Up after every insertion.
    void heapifyUp(Student* node) {
        if (node == NULL || node == root) {
            return;
        }
        Student* parent = findParent(node);
        if (parent != NULL && node->marks > parent->marks) {
            swapStudentData(node, parent);
            heapifyUp(parent);
        }
    }

    // Requirement 6: Apply Heapify Down after root deletion.
    void heapifyDown(Student* node) {
        if (node == NULL) {
            return;
        }
        Student* largest = node;

        if (node->left != NULL && node->left->marks > largest->marks) {
            largest = node->left;
        }
        if (node->right != NULL && node->right->marks > largest->marks) {
            largest = node->right;
        }

        if (largest != node) {
            swapStudentData(node, largest);
            heapifyDown(largest);
        }
    }

    void destroyTree(Student* node) {
        if (node == NULL) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    MaxHeap() {
        root = NULL;
    }

    ~MaxHeap() {
        destroyTree(root);
    }

    // Insert a student into the complete binary tree and apply Heapify Up
    void insertStudent(string name, int rollNumber, double marks) {
        Student* newNode = new Student(name, rollNumber, marks);
        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<Student*> q;
        q.push(root);
        while (!q.empty()) {
            Student* curr = q.front();
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
            cout << "Heap is empty." << endl;
            return;
        }

        queue<Student*> q;
        q.push(root);
        int position = 1;

        cout << "---------------------------------------------------------" << endl;
        cout << "Pos\tRoll No\t\tName\t\tMarks" << endl;
        cout << "---------------------------------------------------------" << endl;

        while (!q.empty()) {
            Student* curr = q.front();
            q.pop();

            cout << position++ << "\t" << curr->rollNumber << "\t\t"
                 << curr->name << "\t\t" << curr->marks << endl;

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        cout << "---------------------------------------------------------" << endl;
    }

    // Requirement 5 & 6: Delete the student with the highest marks and apply Heapify Down.
    void deleteHighestMeritStudent() {
        if (root == NULL) {
            cout << "Heap is empty. Nothing to delete." << endl;
            return;
        }

        cout << "\nDeleting Student with Highest Marks (Root):" << endl;
        cout << "Name: " << root->name << " | Roll No: " << root->rollNumber
             << " | Marks: " << root->marks << endl;

        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return;
        }

        // Find the last node in Level Order Traversal
        queue<Student*> q;
        q.push(root);
        Student* lastNode = NULL;

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

        Student* parentOfLast = findParent(lastNode);

        // Copy last node data to root
        root->name = lastNode->name;
        root->rollNumber = lastNode->rollNumber;
        root->marks = lastNode->marks;

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
    MaxHeap meritList;

    cout << "=== Task 1: University Student Merit Ranking (Max Heap) ===" << endl;

    // Requirement 2: Insert at least six students into a Max Heap according to their marks.
    meritList.insertStudent("Ali", 101, 85.5);
    meritList.insertStudent("Sara", 102, 92.0);
    meritList.insertStudent("Bilal", 103, 78.0);
    meritList.insertStudent("Ayesha", 104, 96.5);
    meritList.insertStudent("Usman", 105, 88.0);
    meritList.insertStudent("Fatima", 106, 94.0);

    // Requirement 4: Display the Heap using Level Order Traversal.
    cout << "\nMax Heap of Students (Level Order Traversal):" << endl;
    meritList.displayLevelOrder();

    // Requirement 5: Delete the student with the highest marks.
    meritList.deleteHighestMeritStudent();

    // Requirement 6: Apply Heapify Down and display the updated Heap.
    cout << "\nUpdated Max Heap after deleting Top Student & applying Heapify Down:" << endl;
    meritList.displayLevelOrder();

    return 0;
}
