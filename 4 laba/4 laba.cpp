#include<iostream>

using namespace std;

int arithm_tail_recursion(int a, int d, int n, int current = 0) {
    if (n == 0) {
        return current;
    }
    return arithm_tail_recursion(a + d, d, n - 1, current + a);
}

int arithm_linear_recursion(int a, int d, int n) {
    if (n == 1) {
        return a;
    }
    return a + (n - 1) * d + arithm_linear_recursion(a, d, n - 1);
}

int binary_search(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    else if (arr[mid] > target) {
        return binary_search(arr, low, mid - 1, target);
    }
    else {
        return binary_search(arr, mid + 1, high, target);
    }
}


int main() {
    setlocale(LC_ALL, "Ukrainian");
    int n, d, S = 0;
    cout << "Enter the number of progression elements: ";
    cin >> n;
    int* A = new int[n];
    int target;
    cout << "The first term of an arithmetic progression: ";
    cin >> A[1];
    cout << "Enter the progression difference";
    cin >> d;
    cout << "Tail recursion" << endl;
    for (int i = 1; i < n + 1; i++) {
        A[i] = arithm_tail_recursion(A[1], d, i);
        S += A[i];
        cout << A[i] << " ";
    }

    cout << endl << "Linear recursion" << endl;
    S = 0;
    for (int i = 1; i < n + 1; i++) {
        A[i] = arithm_linear_recursion(A[1], d, i);
        S += A[i];
        cout << A[i] << " ";
    }
    cout << "Task 2: " << endl << endl;
    cout << "Enter the number you want to find: ";
    cin >> target;

    int result = binary_search(A, 0, n, target);
    cout << "Position of the desired number: " << result;

    system("pause");
    return 0;
}

