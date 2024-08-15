#include<iostream.h>
#include<conio.h>
const int MAX_HEAP_SIZE = 100;
int heapArray[MAX_HEAP_SIZE];
int heapSize = 0;
int getParentIndex(int childIndex) {
    return (childIndex - 1) / 2;
}
int getLeftChildIndex(int parentIndex) {
    return 2 * parentIndex + 1;
}
int getRightChildIndex(int parentIndex) {
    return 2 * parentIndex + 2;
}
void heapifyUp(int index) {
    int temp = heapArray[index];
    while (index > 0 && temp > heapArray[getParentIndex(index)]) {
        heapArray[index] = heapArray[getParentIndex(index)];
        index = getParentIndex(index);
    }
    heapArray[index] = temp;
}
void heapifyDown(int index) {
    int childIndex;
    int temp = heapArray[index];
    while (getLeftChildIndex(index) < heapSize) {
        childIndex = getLeftChildIndex(index);
        if (getRightChildIndex(index) < heapSize && heapArray[getRightChildIndex(index)] > heapArray[childIndex]) {
            childIndex = getRightChildIndex(index);
        }
        if (temp >= heapArray[childIndex]) {
            break;
        }
        heapArray[index] = heapArray[childIndex];
        index = childIndex;
    }
    heapArray[index] = temp;
}
void insert(int element) {
    if (heapSize == MAX_HEAP_SIZE) {
        cout << "Heap is full. Cannot insert element.\n";
        return;
    }
    heapArray[heapSize] = element;
    heapifyUp(heapSize);
    heapSize++;
    cout << "Element " << element << " inserted into the heap.\n";
}
void removeMax() {
    if (heapSize == 0) {
        cout << "Heap is empty. Cannot remove maximum element.\n";
        return;
    }
    int maxElement = heapArray[0];
    heapArray[0] = heapArray[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    cout << "Removed maximum element: " << maxElement << endl;
}

void display() {
    if (heapSize == 0) {
        cout << "Heap is empty.\n";
        return;
    }
    cout << "Heap elements: ";
    for (int i = 0; i < heapSize; i++) {
        cout << heapArray[i] << " ";
    }
    cout << endl;
}
int main() {
    clrscr();
    int choice, element;
    do {
        cout << "\n1. Insert\n2. Remove Max\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                insert(element);
                break;

            case 2:
                removeMax();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    getch();
    return 0;
}
