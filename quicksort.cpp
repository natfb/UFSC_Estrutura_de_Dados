//include
#include <iostream>
#include <vector>
using namespace std;

void exchange(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            exchange(A[i], A[j]);
        }
    }

    exchange(A[i + 1], A[r]);
    return i + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main() {
    int A[] = {3, 6, 8, 10, 1, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout <<  endl;

    quicksort(A, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout <<  endl;

    return 0;
}