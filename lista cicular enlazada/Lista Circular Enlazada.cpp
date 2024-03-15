#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(NULL) {}
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() : head(NULL), tail(NULL) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "La lista está vacía" << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    void sortList() {
        if (head == NULL || head == tail)
            return;

        Node* current = head;
        do {
            Node* innerCurrent = current->next;
            do {
                if (current->data > innerCurrent->data)
                    swap(current->data, innerCurrent->data);
                innerCurrent = innerCurrent->next;
            } while (innerCurrent != head);
            current = current->next;
        } while (current->next != head);
    }

    int search(int target) {
        if (head == NULL)
            return -1;

        Node* current = head;
        int position = 0;
        do {
            if (current->data == target)
                return position;
            current = current->next;
            position++;
        } while (current != head);
        
        return -1;
    }

    int calculateSum() {
        if (head == NULL)
            return 0;

        int sum = 0;
        Node* current = head;
        do {
            sum += current->data;
            current = current->next;
        } while (current != head);

        return sum;
    }

    int findMax() {
        if (head == NULL)
            return 0;

        int max = head->data;
        Node* current = head->next;
        do {
            if (current->data > max)
                max = current->data;
            current = current->next;
        } while (current != head);

        return max;
    }

    int findMin() {
        if (head == NULL)
            return 0;

        int min = head->data;
        Node* current = head->next;
        do {
            if (current->data < min)
                min = current->data;
            current = current->next;
        } while (current != head);

        return min;
    }
};

int main() {
    CircularLinkedList numbers;
    int num;

    cout << "Ingrese los numeros (Ingrese '0' para terminar): " << endl;
    while (true) {
        cin >> num;
        if (num == 0)
            break;
        numbers.insert(num);
    }

    cout << "La suma de los numeros ingresados es: " << numbers.calculateSum() << endl;
    cout << "El numero mayor es: " << numbers.findMax() << endl;
    cout << "El numero minimo es: " << numbers.findMin() << endl;

    numbers.sortList();

    cout << "Lista ordenada: ";
    numbers.display();

    int target;
    cout << "Ingrese el numero que desea buscar: ";
    cin >> target;
    int position = numbers.search(target);
    if (position != -1)
        cout << "El numero " << target << " está en la posición " << position +1 << " en la lista." << endl;
    else
        cout << "El numero " << target << " no se encontró en la lista." << endl;

    return 0;
}
