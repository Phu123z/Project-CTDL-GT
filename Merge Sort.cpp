#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15 // Array size

/*
  Hàm Merge:
  - Gộp hai mảng con đã được sắp xếp `arr[low…mid]` và `arr[mid+1…high]`.
  - Sử dụng mảng phụ `aux[]` để lưu các phần tử đã được sắp xếp tạm thời.
  - So sánh phần tử từ hai mảng con và gán giá trị nhỏ hơn vào `aux[]`.
  - Sao chép kết quả từ `aux[]` trở lại `arr[]`.
*/
void Merge(int arr[], int aux[], int low, int mid, int high) {
    int k = low, i = low, j = mid + 1;

    // So sánh và gộp hai mảng con
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        } else {
            aux[k++] = arr[j++];
        }
    }

    // Sao chép phần còn lại của mảng bên trái (nếu có)
    while (i <= mid) {
        aux[k++] = arr[i++];
    }

    // Sao chép từ `aux[]` về `arr[]`
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
}

/*
  Hàm mergesort:
  - Hàm đệ quy sắp xếp mảng `arr[low…high]` sử dụng mảng phụ `aux[]`.
  - Chia mảng thành hai nửa, sắp xếp từng nửa, và gộp lại bằng hàm `Merge`.
*/
void mergesort(int arr[], int aux[], int low, int high) {
    // Base case: nếu mảng chỉ có 1 phần tử, không cần sắp xếp
    if (high <= low) {
        return;
    }

    // Chia mảng tại vị trí giữa
    int mid = (low + high) / 2;

    // Đệ quy sắp xếp hai nửa
    mergesort(arr, aux, low, mid);       // Nửa trái
    mergesort(arr, aux, mid + 1, high); // Nửa phải

    // Gộp hai nửa đã sắp xếp
    Merge(arr, aux, low, mid, high);
}

/*
  Hàm isSorted:
  - Kiểm tra xem mảng đã được sắp xếp theo thứ tự tăng dần chưa.
  - Nếu không đúng, in thông báo lỗi.
*/
int isSorted(int arr[]) {
    for (int i = 1; i < N; i++) {
        if (arr[i - 1] > arr[i]) {
            printf("MergeSort Fails!!\n");
            return 0;
        }
    }
    return 1;
}

/*
  Hàm main:
  - Sinh ngẫu nhiên một mảng `arr[]` gồm `N` phần tử với giá trị trong khoảng [-50, 49].
  - Gọi hàm `mergesort()` để sắp xếp mảng.
  - Kiểm tra và in kết quả.
*/
int main(void) {
    int arr[N], aux[N];
    srand(time(NULL));

    // Sinh ngẫu nhiên mảng số nguyên
    for (int i = 0; i < N; i++) {
        aux[i] = arr[i] = (rand() % 100) - 50;
    }

    // In mảng ban đầu
    printf("Initial array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sắp xếp mảng bằng Merge Sort
    mergesort(arr, aux, 0, N - 1);

    // Kiểm tra và in mảng đã sắp xếp
    if (isSorted(arr)) {
        printf("Sorted array: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
