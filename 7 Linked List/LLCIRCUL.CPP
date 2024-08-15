#include<iostream.h>
#include<conio.h>

struct CircularNode {
    int data;
    struct CircularNode* next;
};

typedef struct CircularNode* CircularLinkedList;

CircularNode* createCircularNode(int value) {
    CircularNode* newNode = new CircularNode;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

CircularLinkedList insertCircularNode(CircularLinkedList head, int value) {
    CircularNode* newNode = createCircularNode(value);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        CircularNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

void displayCircularList(CircularLinkedList head) {
    CircularNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    clrscr();
    CircularLinkedList circularHead = NULL;
    circularHead = insertCircularNode(circularHead, 5);
    circularHead = insertCircularNode(circularHead, 6);
    circularHead = insertCircularNode(circularHead, 7);
    cout<<"\n Deepak Durgam";
    cout << "\n Circular Linked List: ";
    displayCircularList(circularHead);
    getch();
    return 0;
}