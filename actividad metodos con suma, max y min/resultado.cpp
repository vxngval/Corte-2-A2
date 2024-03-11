#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers;
    int num;

    cout << "Ingrese los numeros (Ingrese '0' para terminar): " << endl;
    while (true) {
        cin >> num;
        if (num == 0)
            break;
        numbers.push_back(num);
    }

    int sum = 0;
    int max= numbers[0];
    int min = numbers[0];
    for (size_t i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) { 
            min = numbers[i];   
        }
    }
    cout << "La suma de los numeros ingresados es: " << sum << endl;
    cout << "El numero mayor es: " << max << endl;
    cout << "El numero minimo es: " << min << endl;

    vector<int> insertionSorted = numbers;
    int n = insertionSorted.size();
    for (int i = 1; i < n; i++) {
        int key = insertionSorted[i];
        int j = i - 1;
        while (j >= 0 && insertionSorted[j] > key) {
            insertionSorted[j + 1] = insertionSorted[j];
            j = j - 1;
        }
        insertionSorted[j + 1] = key;
    }

    cout << "Ordenado por insercion: ";
    for (size_t i = 0; i < insertionSorted.size(); i++) {
        cout << insertionSorted[i] << " ";
    }
    cout << endl;

    vector<int> bubbleSorted = numbers;
    int m = bubbleSorted.size();
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (bubbleSorted[j] > bubbleSorted[j + 1]) {
                int temp = bubbleSorted[j];
                bubbleSorted[j] = bubbleSorted[j + 1];
                bubbleSorted[j + 1] = temp;
            }
        }
    }

    cout << "Ordenado por metodo burbuja: ";
    for (size_t i = 0; i < bubbleSorted.size(); i++) {
        cout << bubbleSorted[i] << " ";
    }
    cout << endl;

    sort(numbers.begin(), numbers.end());
    int target;
    cout << "Ingrese el numero que desea buscar: ";
    cin >> target;
    int left = 0, right = numbers.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (numbers[mid] == target) {
            cout << "El numero " << target << " esta en la posicion " << mid + 1 << " en la lista ordenada." << endl;
            break;
        }
        if (numbers[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (left > right)
        cout << "El numero " << target << " no se encontro en la lista ordenada." << endl;

    return 0;
}
