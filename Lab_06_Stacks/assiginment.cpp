#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack is full.\n";
        return;
    }

    items[++top] = value;
    cout << value << " added to the stack.\n";
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << items[top--] << " removed from the stack.\n";
}

void peek() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Top item: " << items[top] << '\n';
}

void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack from top to bottom: ";
    for (int i = top; i >= 0; i--) {
        cout << items[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int choice;
    int value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a number: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 0:
            cout << "Program ended.\n";
            break;
        default:
            cout << "Please choose a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
