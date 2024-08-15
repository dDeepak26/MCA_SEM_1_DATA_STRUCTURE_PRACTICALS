#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        cout << "Queue Overflow!" << endl;
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = item;
    cout << "Inserted " << item << endl;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow!" << endl;
        return;
    }
    cout << "Deleted " << queue[front] << endl;
    front++;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}

int main()
{
    int choice, item;
    while (1)
    {
        cout << "1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be inserted: ";
            cin >> item;
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}