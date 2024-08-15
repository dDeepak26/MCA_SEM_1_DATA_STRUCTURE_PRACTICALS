#include<iostream.h>
#include<conio.h>

struct Node {
    int row, col, value;
    struct Node* next;
};

typedef struct Node* SparseMatrix;

SparseMatrix createNode(int row, int col, int value) {
    SparseMatrix newNode = new Node;
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

SparseMatrix insertElement(SparseMatrix matrix, int row, int col, int value) {
    SparseMatrix newNode = createNode(row, col, value);

    if (matrix == NULL) {
        matrix = newNode;
    } else {
        SparseMatrix temp = matrix;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return matrix;
}

void displayMatrix(SparseMatrix matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int found = 0; 
            SparseMatrix temp = matrix;
            while (temp != NULL) {
                if (temp->row == i && temp->col == j) {
                    cout << temp->value << " ";
                    found = 1;
                    break;
                }
                temp = temp->next;
            }
            if (!found) {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    clrscr(); 

    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    SparseMatrix matrix = NULL;

    int row, col, value;
    cout << "Enter the elements of the matrix (row, column, value):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> value;
            if (value != 0) {
                matrix = insertElement(matrix, i, j, value);
            }
        }
    }

    cout << "\nSparse Matrix:\n";
    displayMatrix(matrix, rows, cols);

    getch(); 
    return 0;
}
