#include <stdio.h>

/*
Giải Thích Bài Toán:
--------------------
- Cho một mảng số nguyên `arr` gồm `n` phần tử, nhiệm vụ là tìm tích lớn nhất 
  của một dãy con liên tiếp trong mảng. Một dãy con là một phần liên tiếp của mảng.
- Đặc điểm:
    + Phần tử có thể là số âm, dương hoặc 0.
    + Số âm có thể đảo dấu tích, tạo ra giá trị lớn hơn khi kết hợp với số âm khác.
    + Số 0 sẽ làm tích bằng 0 và ngắt dãy liên tiếp.
- Mục tiêu: Tìm tích lớn nhất của dãy con liên tiếp trong mảng.

Ý tưởng Giải Thuật:
-------------------
1. Duyệt qua từng phần tử trong mảng:
    - Với mỗi phần tử, giữ lại hai giá trị:
        + `max_ending`: Tích lớn nhất của dãy con kết thúc tại chỉ số hiện tại.
        + `min_ending`: Tích nhỏ nhất của dãy con kết thúc tại chỉ số hiện tại (để xử lý số âm).
    - Cập nhật `max_ending` và `min_ending` dựa trên:
        + Giá trị hiện tại.
        + Tích của giá trị hiện tại với `max_ending`.
        + Tích của giá trị hiện tại với `min_ending`.
2. Theo dõi giá trị lớn nhất toàn cục (`max_so_far`) trong quá trình duyệt.
3. Trả về `max_so_far` sau khi duyệt hết mảng.

Mô tả các hàm:
--------------
- min(...): Tìm giá trị nhỏ nhất giữa hai số nguyên.
- max(...): Tìm giá trị lớn nhất giữa hai số nguyên.
- findMaxProduct(...): Trả về tích lớn nhất của dãy con liên tiếp trong mảng.
- main(...): Khởi tạo mảng, gọi hàm xử lý và in kết quả.
*/

/* Hàm tiện ích để tìm giá trị nhỏ nhất giữa hai số nguyên */
int min(int x, int y) {
    return (x < y) ? x : y;
}

/* Hàm tiện ích để tìm giá trị lớn nhất giữa hai số nguyên */
int max(int x, int y) {
    return (x > y) ? x : y;
}

/* Hàm trả về tích lớn nhất của một dãy con liên tiếp trong mảng */
int findMaxProduct(int arr[], int n)
{
    /*
    max_ending: Tích lớn nhất của dãy con kết thúc tại phần tử hiện tại.
    min_ending: Tích nhỏ nhất của dãy con kết thúc tại phần tử hiện tại (để xử lý số âm).
    max_so_far: Tích lớn nhất của toàn bộ dãy con đã gặp.
    */
    if (n == 0) { // Trường hợp mảng rỗng
        return 0;
    }

    int max_ending = arr[0], min_ending = arr[0];
    int max_so_far = arr[0];

    // Duyệt qua từng phần tử trong mảng
    for (int i = 1; i < n; i++)
    {
        int temp = max_ending; // Lưu giá trị cũ của max_ending

        // Cập nhật max_ending
        max_ending = max(arr[i], max(arr[i] * max_ending, arr[i] * min_ending));

        // Cập nhật min_ending
        min_ending = min(arr[i], min(arr[i] * temp, arr[i] * min_ending));

        // Cập nhật max_so_far (tích lớn nhất toàn cục)
        max_so_far = max(max_so_far, max_ending);
    }

    return max_so_far; // Trả về kết quả
}

int main(void)
{
    /*
    Mảng đầu vào: arr[] = { -6, 4, -5, 8, -10, 0, 8 }
    Kích thước mảng: n = 7
    */
    int arr[] = { -6, 4, -5, 8, -10, 0, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Tìm và in kết quả
    printf("Tích lớn nhất của một dãy con liên tiếp là %d", findMaxProduct(arr, n));

    return 0;
}
