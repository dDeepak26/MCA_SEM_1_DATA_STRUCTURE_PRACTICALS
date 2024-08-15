#include<iostream.h>
#include<conio.h>

int max(int m, int n);

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

typedef struct Node* Polynomial;

Polynomial createNode(int coeff, int exp) {
    Polynomial newNode = new Node;
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

Polynomial insertTerm(Polynomial poly, int coeff, int exp) {
    Polynomial newNode = createNode(coeff, exp);
    if (poly == NULL) {
        poly = newNode;
    } else {
        Polynomial temp = poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return poly;
}

Polynomial addPolynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coeff1 = (poly1 != NULL) ? poly1->coeff : 0;
        int exp1 = (poly1 != NULL) ? poly1->exp : 0;
        int coeff2 = (poly2 != NULL) ? poly2->coeff : 0;
        int exp2 = (poly2 != NULL) ? poly2->exp : 0;
        int sumCoeff = coeff1 + coeff2;
        int sumExp = max(exp1, exp2);
        result = insertTerm(result, sumCoeff, sumExp);
        if (poly1 != NULL) poly1 = poly1->next;
        if (poly2 != NULL) poly2 = poly2->next;
    }
    return result;
}

void printPolynomial(Polynomial poly) {
    while (poly != NULL) {
        cout << poly->coeff << "x^" << poly->exp;
        if (poly->next != NULL) {
            cout << " + ";
        }
        poly = poly->next;
    }
}

int main() {
    clrscr();
	cout<<"\n Pravin Patil \n";
    Polynomial poly1 = NULL;
    Polynomial poly2 = NULL; 
    poly1 = insertTerm(poly1, 6, 3);
    poly1 = insertTerm(poly1, 1, 2);
    poly1 = insertTerm(poly1, 7, 2);
    poly1 = insertTerm(poly1, 6, 0);
    poly2 = insertTerm(poly2, 5, 2);
    poly2 = insertTerm(poly2, 2, 1);
    poly2 = insertTerm(poly2, 4, 2);
    cout << "First polynomial is ";
    printPolynomial(poly1);
    cout << "\nSecond polynomial is ";
    printPolynomial(poly2);
    Polynomial sum = addPolynomials(poly1, poly2);

	cout << "\nSum of polynomials is ";
    printPolynomial(sum);
    getch();
    return 0;
}

int max(int m, int n) {
    return (m > n) ? m : n;
}
