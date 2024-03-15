#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {} 
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(NULL), tail(NULL) {} 

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Node* getHead() {
        return head;
    }

    int sum() {
        int sum = 0;
        Node* current = head;
        while (current) {
            sum += current->data;
            current = current->next;
        }
        return sum;
    }

    int findMax() {
        int max = head->data;
        Node* current = head->next;
        while (current) {
            if (current->data > max)
                max = current->data;
            current = current->next;
        }
        return max;
    }

    int findMin() {
        int min = head->data;
        Node* current = head->next;
        while (current) {
            if (current->data < min)
                min = current->data;
            current = current->next;
        }
        return min;
    }

    void bubbleSort() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            while (nextNode) {
                if (current->data > nextNode->data)
                    swap(current->data, nextNode->data);
                nextNode = nextNode->next;
            }
            current = current->next;
        }
    }

    bool search(int target) {
        Node* current = head;
        while (current) {
            if (current->data == target)
                return true;
            current = current->next;
        }
        return false;
    }


    pair<bool, int> binarySearch(int target) {
        Node* left = head;
        Node* right = tail;
        int position = 1;
        while (left <= right) {
            Node* mid = left;
            int midIndex = 0;

            while (mid != NULL && mid != right && mid->next != right) {
                mid = mid->next;
                midIndex++;
            }

            if (mid->data == target)
                return {true, position + midIndex};
            else if (mid->data < target) {
                left = mid->next;
                position += midIndex + 1;
            }
            else
                right = mid;
        }
        return {false, -1};
    }
};

void printDoublyLinkedList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    DoublyLinkedList numbers;
    vector<int> sortedNumbers;
    int num;

    cout << "Ingrese los numeros (Ingrese '0' para terminar): " << endl;
    while (true) {
        cin >> num;
        if (num == 0)
            break;
        numbers.insert(num);
        sortedNumbers.push_back(num);
    }

    numbers.bubbleSort();

    cout << "Lista ingresada: ";
    printDoublyLinkedList(numbers.getHead());

    cout << "Suma de los numeros: " << numbers.sum() << endl;
    cout << "Maximo valor: " << numbers.findMax() << endl;
    cout << "Minimo valor: " << numbers.findMin() << endl;


cout << endl;

    int target;
    cout << "Ingrese el numero que desea buscar: ";
    cin >> target;
    pair<bool, int> result = numbers.binarySearch(target);
    if (result.first)
        cout << "El numero " << target << " se encuentra en la posicion " << result.second << " en la lista ordenada." << endl;
    else
        cout << "El numero " << target << " no se encuentra en la lista." << endl;

    return 0;
}
