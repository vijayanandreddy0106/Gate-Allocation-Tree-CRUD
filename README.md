PROJECT TITLE:-
Gate-Allocation-Tree-CRUD


Team Members:-

 
 1. N Lakshmi Vijayanand Reddy  
 2. V Kiran Rathore


Problem Statement:-

 
  In many real-world applications, data needs to be dynamically added, updated, deleted, and displayed efficiently.  
  This project aims to implement a dynamic data management system using a Linked List in C to perform CRUD operations.



Data Structure Used:-
 This project uses a **Singly Linked List**.

 - Each node stores:
  - Data (integer)
  - Pointer to next node
 - Dynamic memory allocation is used (`malloc`, `free`)


Algorithm Explanation:-
Create (Add Node):-
 - Create a new node using `malloc`
 - Insert it at the end of the list

Read (Display):-
 - Traverse the list from head
 - Print each node value


Update:-
  - Search for a node with given value
  - Replace it with new value


Delete:-
  - Find the node
  - Adjust links of previous node
  - Free memory using `free()`


Search:-
  - Traverse list
  - Compare each node value
  - Return position if found


Compilation Instructions:-

  Step 1: Open terminal in project folder  

  Step 2: Compile the program  

  gcc main.c -o program


  Step 3: Run the program  

   ./a.exe



 Sample Output:-


  --- MENU ---

  1.Add Node
  
  2.Delete Node
  
  3.Update Node
  
  4.Search
  
  5.Display
  
  6.Exit

  Example:-

  1.Enter your choice: 1
  
    Enter data: 10
  
    Node added successfully!

  

  2.Enter your choice: 1
  
    Enter data: 20
  
    Node added successfully!
  
  

  3.Enter your choice: 5
  
  
    Linked List: 10 -> 20 -> NULL

sample output screenshots:-


<img width="895" height="520" alt="Screenshot (14)" src="https://github.com/user-attachments/assets/3aedde26-c682-4abb-9f73-6b4dc87c94e2" />

<img width="1100" height="572" alt="Screenshot (15)" src="https://github.com/user-attachments/assets/a21de048-c5b5-46c3-a0a7-88917db07492" />

<img width="1125" height="592" alt="Screenshot (16)" src="https://github.com/user-attachments/assets/7dba1326-9e39-4fb0-8a9b-3e4a7542e2b9" />

<img width="1174" height="662" alt="Screenshot (17)" src="https://github.com/user-attachments/assets/bc92ba44-2e84-477b-9944-a44eee1fa48a" />





