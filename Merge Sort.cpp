#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15 // Kích thước mảng

/*
  BÀI TOÁN "MERGE SORT"
  ---------------------
  - Cho một mảng nums[] gồm N phần tử (ở đây N = 15).
  - Nhiệm vụ: Sắp xếp mảng nums[] theo thứ tự tăng dần bằng thuật toán Merge Sort.

  Ý TƯỞNG (MERGE SORT)
  ---------------------
  1. Merge Sort là thuật toán chia để trị (divide-and-conquer):
     - Chia (Divide): Chia mảng thành hai nửa bằng nhau tại vị trí giữa.
     - Gộp (Merge): Gộp hai mảng con đã được sắp xếp thành một mảng lớn hơn đã sắp xếp.
     - Kết hợp (Combine): Sau khi gộp xong từng mảng con, trả kết quả lên các lời gọi đệ quy.
  
  2. Quy trình tổng quan:
     - Hàm mergesort():
       + Chia mảng tại chỉ số giữa (mid).
       + Gọi đệ quy sắp xếp từng nửa.
       + Gộp hai nửa đã sắp xếp bằng hàm Merge().
     - Hàm Merge():
       + Gộp hai mảng con đã sắp xếp.
       + Dùng mảng phụ aux[] để lưu tạm thời các phần tử đã sắp xếp.
  
  3. Độ phức tạp:
     - Thời gian: O(n log n).
     - Không gian: O(n) do sử dụng mảng phụ aux[].
*/

/*
  Hàm Merge:
  -----------------
  - Gộp hai mảng con đã được sắp xếp `arr[low…mid]` và `arr[mid+1…high]`.
  - Sử dụng mảng phụ aux[] để lưu tạm thời các phần tử đã được gộp.
*/
void Merge(int arr[], int aux[], int low, int mid, int high) {
    int k = low, i = low, j = mid + 1;

    // Gộp hai mảng con
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        } else {
            aux[k++] = arr[j++];
        }
    }

    // Sao chép phần còn lại của mảng bên trái (nếu còn)
    while (i <= mid) {
        aux[k++] = arr[i++];
    }

    // Sao chép từ mảng phụ aux[] trở lại arr[]
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
}

/*
  Hàm mergesort:
  -----------------
  - Hàm đệ quy sắp xếp mảng arr[low…high] sử dụng mảng phụ aux[].
  - Chia mảng thành hai nửa, sắp xếp từng nửa, và gộp lại bằng hàm Merge().
*/
void mergesort(int arr[], int aux[], int low, int high) {
    // Trường hợp cơ sở: nếu mảng có một phần tử
    if (high <= low) {
        return;
    }

    // Tìm vị trí giữa
    int mid = (low + high) / 2;

    // Đệ quy sắp xếp hai nửa
    mergesort(arr, aux, low, mid);       // Nửa trái
    mergesort(arr, aux, mid + 1, high); // Nửa phải

    // Gộp hai nửa đã sắp xếp
    Merge(arr, aux, low, mid, high);
}

/*
  Hàm isSorted:
  -----------------
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
  -----------------
  - Sinh ngẫu nhiên một mảng nums[] gồm N phần tử với giá trị từ [-50, 49].
  - Gọi hàm mergesort() để sắp xếp mảng.
  - Kiểm tra và in mảng sau khi sắp xếp.
*/
int main(void) {
    int arr[N], aux[N];
    srand(time(NULL));

    // Sinh mảng ngẫu nhiên
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
