#include<iostream.h>
#include<conio.h>

const int MAX_SIZE = 100;

void push(char stackArray[], char ch, int &top) {
    if (top < MAX_SIZE - 1) {
        stackArray[++top] = ch;
    } else {
        cout << "Stack overflow!\n";
    }
}

char pop(char stackArray[], int &top) {
    if (top >= 0) {
        return stackArray[top--];
    } else {
        cout << "Stack underflow!\n";
        return '\0'; // Return null character for an empty stack
    }
}

char peek(char stackArray[], int top) {
    if (top >= 0) {
        return stackArray[top];
    } else {
        cout << "Stack is empty!\n";
        return '\0'; // Return null character for an empty stack
    }
}

int isEmpty(int top) {
    return top == -1;
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int isBalancedExpression(char expression[]) {
    char stackArray[MAX_SIZE];
    int top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char currentChar = expression[i];
        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            push(stackArray, currentChar, top);
        } else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {
            if (isEmpty(top) || !isMatchingPair(pop(stackArray, top), currentChar)) {
                return 0; // Replace false with 0
            }
        }
    }

    return isEmpty(top) ? 1 : 0; // Replace true with 1
}

void main() {
    clrscr();

    char expression[MAX_SIZE];
    cout<<"Balancing of Parenthesis"<<endl;
    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalancedExpression(expression)) {
        cout << "The expression is balanced.\n";
    } else {
        cout << "The expression is not balanced.\n";
    }

    getch();
}
