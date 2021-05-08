#include <iostream>

void print_array(int arr[], int size){
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void quicksort(int arr[], int lb, int rb, int size){
    if (lb >= rb) return;
    int pivot = arr[lb];
    int l = lb+1;
    int r = rb;
    while (true){
        while (l <= rb && arr[l] <= pivot) l++;
        while (r >= lb && arr[r] > pivot) r--;
        if (l < r){
            std::swap(arr[l], arr[r]);
            print_array(arr, size);
        } else {
            break;
        }
    }
    std::swap(arr[lb], arr[r]);
    print_array(arr, size);
    quicksort(arr, lb, r-1, size);
    quicksort(arr, r+1, rb, size);
}

int main()
{
    int N;
    std::cin >> N;
    int arr[N];
    for (int n = 0; n < N; n++){
        std::cin >> arr[n];
    }
    print_array(arr, N);
    quicksort(arr, 0, N-1, N);
    return 0;
}
