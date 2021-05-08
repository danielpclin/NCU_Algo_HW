#include <iostream>
int temp[100000];
long int merge(int A[], int left, int mid, int right){
    long int swaps = 0;

    int i = left, j = mid, k = left;

    while (i < mid && j <= right) {

        if (A[i] <= A[j]) {
            temp[k] = A[i];
            k++, i++;
        }
        else {
            temp[k] = A[j];
            k++, j++;
            swaps += mid - i;
        }
    }
    while (i < mid) {
        temp[k] = A[i];
        k++, i++;
    }

    while (j <= right) {
        temp[k] = A[j];
        k++, j++;
    }

    while (left <= right) {
        A[left] = temp[left];
        left++;
    }

    return swaps;
}

long int mergeSwap(int A[], int left, int right){
    long int swaps = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        swaps += mergeSwap(A, left, mid);
        swaps += mergeSwap(A, mid + 1, right);
        swaps += merge(A, left, mid + 1, right);
    }
    return swaps;
}
int main()
{
    int T;
    while (true){
        std::cin >> T;
        if (T != 0){
            int A[T];
            for (int i = 0; i < T; ++i) {
                std::cin >> A[i];
            }
            std::cout << "Optimal swapping takes " << mergeSwap(A, 0, T - 1) << " swaps.\n";
        }else{
            break;
        }
    }
    return 0;
}
