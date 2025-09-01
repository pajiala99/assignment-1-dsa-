#include <iostream>
using namespace std;
 
#define MAX 100
 
int arr[MAX];
int n = 0; // Current number of elements
 
 
void createArray() {
   cout << "Enter number of elements: ";
   cin >> n;
   if (n > MAX) {
       cout << "Array size exceeds maximum limit.\n";
       n = 0;
       return;
   }
   cout << "Enter " << n << " elements:\n";
   for (int i = 0; i < n; i++) {
       cin >> arr[i];
   }
   cout << "Array created successfully.\n";
}
 
 
void displayArray() {
   if (n == 0) {
       cout << "Array is empty.\n";
       return;
   }
   cout << "Array elements: ";
   for (int i = 0; i < n; i++) {
       cout << arr[i] << " ";
   }
   cout << "\n";
}
 
 
void insertElement() {
   if (n == MAX) {
       cout << "Array is full. Cannot insert.\n";
       return;
   }
   int pos, val;
   cout << "Enter position to insert (1 to " << n + 1 << "): ";
   cin >> pos;
   if (pos < 1 || pos > n + 1) {
       cout << "Invalid position.\n";
       return;
   }
   cout << "Enter value to insert: ";
   cin >> val;
   for (int i = n; i >= pos; i--) {
       arr[i] = arr[i - 1];
   }
   arr[pos - 1] = val;
   n++;
   cout << "Element inserted successfully.\n";
}
 
 
void deleteElement() {
   if (n == 0) {
       cout << "Array is empty. Cannot delete.\n";
       return;
   }
   int pos;
   cout << "Enter position to delete (1 to " << n << "): ";
   cin >> pos;
   if (pos < 1 || pos > n) {
       cout << "Invalid position.\n";
       return;
   }
   cout << "Deleted element: " << arr[pos - 1] << "\n";
   for (int i = pos - 1; i < n - 1; i++) {
       arr[i] = arr[i + 1];
   }
   n--;
   cout << "Element deleted successfully.\n";
}
 
 
void linearSearch() {
   if (n == 0) {
       cout << "Array is empty.\n";
       return;
   }
   int val, found = 0;
   cout << "Enter value to search: ";
   cin >> val;
   for (int i = 0; i < n; i++) {
       if (arr[i] == val) {
           cout << "Element found at position " << i + 1 << ".\n";
           found = 1;
           break;
       }
   }
   if (!found) {
       cout << "Element not found.\n";
   }
}
 
int main() {
   int choice;
   while (true) {
       cout << "\n--- Array Operations Menu ---\n";
       cout << "1. Create\n";
       cout << "2. Display\n";
       cout << "3. Insert\n";
       cout << "4. Delete\n";
       cout << "5. Linear Search\n";
       cout << "6. Exit\n";
       cout << "Enter your choice: ";
       cin >> choice;
 
       switch (choice) {
           case 1: createArray(); break;
           case 2: displayArray(); break;
           case 3: insertElement(); break;
           case 4: deleteElement(); break;
           case 5: linearSearch(); break;
           case 6: cout << "Exiting program.\n"; return 0;
           default: cout << "Invalid choice. Try again.\n";
       }
   }
}
 
 
 