#include <stdio.h>

/*
  BÀI TOÁN "FLOOR VÀ CEIL CỦA MỘT SỐ TRONG MẢNG SẮP XẾP"
  -----------------------------------------------------
  - Cho một mảng nums[] đã sắp xếp tăng dần gồm n phần tử.
  - Nhiệm vụ: tìm ceil và floor của một số nguyên x:
      + Ceil của x: phần tử nhỏ nhất trong mảng lớn hơn hoặc bằng x.
      + Floor của x: phần tử lớn nhất trong mảng nhỏ hơn hoặc bằng x.
  - Nếu không tìm được, trả về giá trị mặc định -1.

  Ý TƯỞNG (BINARY SEARCH)
  -----------------------------------------------------
  - Sử dụng thuật toán Binary Search (tìm kiếm nhị phân) để tìm kiếm hiệu quả:
      + Tìm Ceil:
          * Nếu nums[mid] == x: Ceil là chính x.
          * Nếu nums[mid] > x: cập nhật ceil và tìm tiếp ở mảng bên trái.
          * Nếu nums[mid] < x: tìm tiếp ở mảng bên phải.
      + Tìm Floor:
          * Nếu nums[mid] == x: Floor là chính x.
          * Nếu nums[mid] < x: cập nhật floor và tìm tiếp ở mảng bên phải.
          * Nếu nums[mid] > x: tìm tiếp ở mảng bên trái.
  - Độ phức tạp: O(log n) cho mỗi lần tìm kiếm.
*/

/*
  Hàm getCeil:
  -----------------
  - Tìm ceil của x trong mảng đã sắp xếp nums[].
  - Ceil là phần tử nhỏ nhất trong mảng lớn hơn hoặc bằng x.
*/
int getCeil(int nums[], int n, int x)
{
    int low = 0, high = n - 1, mid;

    // Khởi tạo giá trị mặc định của ceil là -1
    int ceil = -1;

    // Lặp đến khi khoảng tìm kiếm được thu hẹp
    while (low <= high)
    {
        mid = (low + high) / 2;

        // Nếu tìm thấy x, trả về chính x (ceil là chính nó)
        if (nums[mid] == x) {
            return nums[mid];
        }

        // Nếu phần tử giữa lớn hơn x, cập nhật ceil và thu hẹp tìm kiếm
        // về phía trái
        else if (x < nums[mid]) {
            ceil = nums[mid];
            high = mid - 1;
        }

        // Nếu phần tử giữa nhỏ hơn x, thu hẹp tìm kiếm về phía phải
        else {
            low = mid + 1;
        }
    }

    return ceil;
}

/*
  Hàm getFloor:
  -----------------
  - Tìm floor của x trong mảng đã sắp xếp nums[].
  - Floor là phần tử lớn nhất trong mảng nhỏ hơn hoặc bằng x.
*/
int getFloor(int nums[], int n, int x)
{
    int low = 0, high = n - 1, mid;

    // Khởi tạo giá trị mặc định của floor là -1
    int floor = -1;

    // Lặp đến khi khoảng tìm kiếm được thu hẹp
    while (low <= high)
    {
        mid = (low + high) / 2;

        // Nếu tìm thấy x, trả về chính x (floor là chính nó)
        if (nums[mid] == x) {
            return nums[mid];
        }

        // Nếu phần tử giữa nhỏ hơn x, cập nhật floor và thu hẹp tìm kiếm
        // về phía phải
        else if (x > nums[mid]) {
            floor = nums[mid];
            low = mid + 1;
        }

        // Nếu phần tử giữa lớn hơn x, thu hẹp tìm kiếm về phía trái
        else {
            high = mid - 1;
        }
    }

    return floor;
}

/*
  Hàm main:
  -----------------
  - Kiểm tra ceil và floor của các giá trị từ 0 đến 10 trong mảng đã sắp xếp.
  - Sử dụng hàm getCeil() và getFloor() để tìm kiếm.
  - In kết quả ra màn hình.
*/
int main(void)
{
    int nums[] = { 1, 4, 6, 8, 9 };
    int n = sizeof(nums) / sizeof(nums[0]);

    // Duyệt qua các giá trị từ 0 đến 10 để kiểm tra ceil và floor
    for (int i = 0; i <= 10; i++)
    {
        printf("Number %d —> ", i);
        printf("ceil is %d, ", getCeil(nums, n, i));
        printf("floor is %d\n", getFloor(nums, n, i));
    }

    return 0;
}
