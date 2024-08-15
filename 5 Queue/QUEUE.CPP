#include<iostream.h>
#include<conio.h>

const int MAX_SIZE = 5;

class Queue {
private:
    int front, rear;
    int elements[MAX_SIZE];

public:
    Queue() {
        front = rear = -1;
    }
	
    int isEmpty() {
        return front == -1;
    }
	
    int isFull() {
	return (front == 0 && rear == MAX_SIZE - 1) ||
	 (rear == (front - 1 + MAX_SIZE) % MAX_SIZE);
    }
	
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << item << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        elements[rear] = item;
        cout << item << " enqueued to queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << elements[front] << " dequeued from queue." << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        do {
            cout << elements[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);

        cout << endl;
    }
};  

int main() {
    Queue myQueue;
    int choice, item;
	clrscr();
	cout<<" \n Queue \n ";
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> item;
                myQueue.enqueue(item);
                break;
            case 2:
                myQueue.dequeue();
                break;
            case 3:
                myQueue.display();
                break;
            case 4:
                cout << "Exiting the program.";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.";
        }
    } while (choice != 4);
    getch();
    return 0;
}
