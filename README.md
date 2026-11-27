# Data Structures & Algorithms — Coursework & Lab Implementations

![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)
![Compiler](https://img.shields.io/badge/Compiler-GCC%20%2F%20g%2B%2B-475569?style=flat-square)
![Course](https://img.shields.io/badge/Course-Data%20Structures%20%26%20Algorithms-1e40af?style=flat-square)

This repository contains my university **Data Structures & Algorithms** coursework, weekly lab implementations, assignments, practice code, and reference notes completed at **Air University, Islamabad**. Each implementation focuses on core data structure design in C++ using arrays, pointers, structs, and object-oriented classes applied to practical problem scenarios.

---

## 🛠️ Tech Stack & Environment

- **Language:** C++ (`C++11` / `C++17`)
- **Compiler:** GCC (`g++` / MinGW-w64)
- **Standard Libraries Used:** `<iostream>`, `<string>`, `<queue>`, `<vector>`, `<algorithm>`
- **Core Concepts:** Dynamic Memory Allocation, Pointers, Object-Oriented Programming (Classes & Encapsulation), Recursion, Tree Rotations, and Heapify Operations

---

## 📂 Directory Structure

```text
data_structure/
├── Lab_03/                         # Multi-Dimensional Arrays (2D & 3D) and Linear Search
│   ├── Task1_StudentMarks
│   ├── Task2_ParkingManagement.cpp
│   ├── Task3_MatrixOutput.cpp
│   ├── Task4_HospitalBedManagement.cpp
│   ├── Task5_ComputerLabManagement.cpp
│   └── Task6_3DArraySearch.cpp
├── Lab_04/                         # Singly Linked Lists
│   ├── Task_01.cpp
│   ├── Task_02.cpp
│   └── Task_03.cpp
├── Lab_05_Doubly_LinkedList/       # Doubly & Circular Linked Lists
│   ├── Task_1_Browser_History.cpp
│   ├── Task _2_Image_Gallery.cpp
│   ├── Task _3_Game_Player_Turns.cpp
│   └── Task _4_Music Playlist.cpp
├── Lab_06_Stacks/                  # Stack (LIFO) Implementations & Assignments
│   ├── assiginment.cpp
│   ├── Browser_Back_History.cpp
│   ├── Hospital_Patient_Emergency_Requests.cpp
│   ├── Restaurant_Order_Processing.cpp
│   └── Undo_Operation_Text_Editor.cpp
├── Lab_07_Queue/                   # Linear, Circular, Priority Queues & Deques
│   ├── BankCustomerServiceSystem.cpp
│   ├── HospitalEmergencyDepartmentPriorityQueue.cpp
│   ├── Network DataPacketManagementCircularQueue.cpp
│   ├── TrainStationPassengerManagement _Deque.cpp
│   └── Practise/
│       └── queue.cpp
├── Lab_08_Tree/                    # General Trees, Binary Search Trees (BST) & AVL Trees
│   ├── Task_1_University_Department_Hierarchy.cpp
│   ├── Task_2_Online_Shopping_Categories.cpp
│   ├── task_3_computer_file_explorer_dfs.cpp
│   ├── task_4_hospital_appointment_avl.cpp
│   ├── Task1_Staff_Management.cpp
│   ├── Task2_Hospital_Inventory.cpp
│   ├── flight_BST.cpp
│   └── emergency_avl.cpp
├── Lab_09_Heap/                    # Max Heap, Min Heap & Heap Sort (Pointer-Based)
│   ├── Task_1_Student_Merit_Ranking.cpp
│   ├── Task_2_Hospital_Emergency_Management.cpp
│   ├── Task_3_Online_Shopping_Order_Sorting.cpp
│   └── Task_4_Hospital_Medicine_Expiry_Management.cpp
├── Theoritical Notes DS/           # Lecture Slides & Reference PDFs
│   ├── Binary_Search_Tree.pdf
│   ├── Chapter 8_DS.pdf
│   └── Tree_01.pdf
├── .gitignore
└── README.md
```

---

## 📑 Data Structures & Algorithms Index

### 1. Arrays & Matrices ([`Lab_03`](./Lab_03))
| File | Data Structure / Concept | Problem Scenario |
| :--- | :--- | :--- |
| [`Task1_StudentMarks`](./Lab_03/Task1_StudentMarks) | 2D Arrays | Student marks storage, total calculation, and averaging |
| [`Task2_ParkingManagement.cpp`](./Lab_03/Task2_ParkingManagement.cpp) | 2D Grid Array | Parking lot slot occupancy tracking and search |
| [`Task3_MatrixOutput.cpp`](./Lab_03/Task3_MatrixOutput.cpp) | 2D Matrix | Matrix input, traversal, and formatted output |
| [`Task4_HospitalBedManagement.cpp`](./Lab_03/Task4_HospitalBedManagement.cpp) | 2D Array | Hospital ward and bed availability management |
| [`Task5_ComputerLabManagement.cpp`](./Lab_03/Task5_ComputerLabManagement.cpp) | 2D Array | Computer lab workstation status tracking |
| [`Task6_3DArraySearch.cpp`](./Lab_03/Task6_3DArraySearch.cpp) | 3D Array & Linear Search | Multi-layer 3D array traversal and element lookup |

### 2. Singly Linked Lists ([`Lab_04`](./Lab_04))
| File | Data Structure / Concept | Problem Scenario |
| :--- | :--- | :--- |
| [`Task_01.cpp`](./Lab_04/Task_01.cpp) | Singly Linked List | Student roll number registration, traversal, and search |
| [`Task_02.cpp`](./Lab_04/Task_02.cpp) | Singly Linked List | Workspace file for linked list operations |
| [`Task_03.cpp`](./Lab_04/Task_03.cpp) | Singly Linked List (OOP) | E-commerce shopping cart with dynamic product insertion and removal |

### 3. Doubly & Circular Linked Lists ([`Lab_05_Doubly_LinkedList`](./Lab_05_Doubly_LinkedList))
| File | Data Structure / Concept | Problem Scenario |
| :--- | :--- | :--- |
| [`Task_1_Browser_History.cpp`](./Lab_05_Doubly_LinkedList/Task_1_Browser_History.cpp) | Doubly Linked List | Web browser forward and backward page history navigation |
| [`Task _2_Image_Gallery.cpp`](./Lab_05_Doubly_LinkedList/Task%20_2_Image_Gallery.cpp) | Doubly Linked List | Bidirectional image gallery viewer (next/previous slide) |
| [`Task _3_Game_Player_Turns.cpp`](./Lab_05_Doubly_LinkedList/Task%20_3_Game_Player_Turns.cpp) | Circular / Doubly Linked List | Multiplayer turn rotation system |
| [`Task _4_Music Playlist.cpp`](./Lab_05_Doubly_LinkedList/Task%20_4_Music%20Playlist.cpp) | Doubly Linked List | Music playlist controller supporting bidirectional track traversal |

### 4. Stacks — LIFO ([`Lab_06_Stacks`](./Lab_06_Stacks))
| File | Data Structure / Concept | Problem Scenario |
| :--- | :--- | :--- |
| [`assiginment.cpp`](./Lab_06_Stacks/assiginment.cpp) | Array-Based Stack | Interactive menu-driven stack (`push`, `pop`, `peek`, `display`) |
| [`Browser_Back_History.cpp`](./Lab_06_Stacks/Browser_Back_History.cpp) | Stack (LIFO) | Browser back-button navigation stack |
| [`Hospital_Patient_Emergency_Requests.cpp`](./Lab_06_Stacks/Hospital_Patient_Emergency_Requests.cpp) | Stack (LIFO) | Handling most recent emergency requests |
| [`Restaurant_Order_Processing.cpp`](./Lab_06_Stacks/Restaurant_Order_Processing.cpp) | Stack (LIFO) | Restaurant order tracking and fulfillment |
| [`Undo_Operation_Text_Editor.cpp`](./Lab_06_Stacks/Undo_Operation_Text_Editor.cpp) | Stack (LIFO) | Text editor undo action history |

### 5. Queues — FIFO, Circular, Priority & Deque ([`Lab_07_Queue`](./Lab_07_Queue))
| File | Data Structure / Concept | Problem Scenario |
| :--- | :--- | :--- |
| [`BankCustomerServiceSystem.cpp`](./Lab_07_Queue/BankCustomerServiceSystem.cpp) | Linear Queue (FIFO) | Bank customer service ticketing queue |
| [`HospitalEmergencyDepartmentPriorityQueue.cpp`](./Lab_07_Queue/HospitalEmergencyDepartmentPriorityQueue.cpp) | Priority Queue | Emergency department patient triage based on severity |
| [`Network DataPacketManagementCircularQueue.cpp`](./Lab_07_Queue/Network%20DataPacketManagementCircularQueue.cpp) | Circular Queue | Network data packet buffering and wrap-around routing |
| [`TrainStationPassengerManagement _Deque.cpp`](./Lab_07_Queue/TrainStationPassengerManagement%20_Deque.cpp) | Double-Ended Queue (Deque) | Train station passenger entry/exit from both ends |
| [`Practise/queue.cpp`](./Lab_07_Queue/Practise/queue.cpp) | Array Queue Practice | Basic `enqueue`, `dequeue`, and `display` class practice |

### 6. Trees — Binary Trees, BST & Self-Balancing AVL Trees ([`Lab_08_Tree`](./Lab_08_Tree))
| File | Data Structure / Concept | Problem Scenario |
| :--- | :--- | :--- |
| [`Task_1_University_Department_Hierarchy.cpp`](./Lab_08_Tree/Task_1_University_Department_Hierarchy.cpp) | General Binary Tree | University department leadership and faculty hierarchy |
| [`Task_2_Online_Shopping_Categories.cpp`](./Lab_08_Tree/Task_2_Online_Shopping_Categories.cpp) | Binary Tree | E-commerce product category tree representation |
| [`task_3_computer_file_explorer_dfs.cpp`](./Lab_08_Tree/task_3_computer_file_explorer_dfs.cpp) | Tree Traversal (DFS) | File explorer directory structure traversal using Depth-First Search |
| [`task_4_hospital_appointment_avl.cpp`](./Lab_08_Tree/task_4_hospital_appointment_avl.cpp) | AVL Tree | Self-balancing hospital appointment tree with LL, RR, LR, RL rotations |
| [`Task1_Staff_Management.cpp`](./Lab_08_Tree/Task1_Staff_Management.cpp) | Binary Tree & BST | University staff hierarchy and Binary Search Tree ID lookup/deletion |
| [`Task2_Hospital_Inventory.cpp`](./Lab_08_Tree/Task2_Hospital_Inventory.cpp) | Binary Search Tree (BST) | Hospital inventory management with BST insertion, search, and traversal |
| [`flight_BST.cpp`](./Lab_08_Tree/flight_BST.cpp) | Binary Search Tree (BST) | Flight scheduling and search system using BST |
| [`emergency_avl.cpp`](./Lab_08_Tree/emergency_avl.cpp) | AVL Tree | Self-balancing emergency record tree with height balancing |

### 7. Heaps & Heap Sort ([`Lab_09_Heap`](./Lab_09_Heap))
| File | Data Structure / Concept | Problem Scenario |
| :--- | :--- | :--- |
| [`Task_1_Student_Merit_Ranking.cpp`](./Lab_09_Heap/Task_1_Student_Merit_Ranking.cpp) | Pointer-Based Max Heap | University student merit ranking with `heapifyUp`, Level-Order Traversal, and `heapifyDown` |
| [`Task_2_Hospital_Emergency_Management.cpp`](./Lab_09_Heap/Task_2_Hospital_Emergency_Management.cpp) | Pointer-Based Max Heap | Hospital emergency patient triage prioritized by urgency level |
| [`Task_3_Online_Shopping_Order_Sorting.cpp`](./Lab_09_Heap/Task_3_Online_Shopping_Order_Sorting.cpp) | Max Heap & Heap Sort | Sorting customer orders in ascending order via repeated root extraction |
| [`Task_4_Hospital_Medicine_Expiry_Management.cpp`](./Lab_09_Heap/Task_4_Hospital_Medicine_Expiry_Management.cpp) | Pointer-Based Min Heap | Tracking medicines by `YYYYMMDD` expiry date to surface nearest-expiry stock first |

### 8. Theoretical Reference Notes ([`Theoritical Notes DS`](./Theoritical%20Notes%20DS))
- [`Binary_Search_Tree.pdf`](./Theoritical%20Notes%20DS/Binary_Search_Tree.pdf) — BST properties, searching, insertion, and deletion cases
- [`Chapter 8_DS.pdf`](./Theoritical%20Notes%20DS/Chapter%208_DS.pdf) — Trees and hierarchical data structures reference
- [`Tree_01.pdf`](./Theoritical%20Notes%20DS/Tree_01.pdf) — Introduction to tree terminology and traversals

---

## ⚙️ How to Compile and Run Locally

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Shehbaz-Makhmoor-Ali/data_structure.git
   cd data_structure
   ```

2. **Compile any C++ source file with `g++`:**
   ```bash
   g++ "Lab_09_Heap/Task_1_Student_Merit_Ranking.cpp" -o main
   ```

3. **Run the executable:**
   - **Windows (PowerShell / CMD):**
     ```powershell
     .\main.exe
     ```
   - **Linux / macOS:**
     ```bash
     ./main
     ```
