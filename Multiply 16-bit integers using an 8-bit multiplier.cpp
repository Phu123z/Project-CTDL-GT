#include <iostream>
#include <bitset>
using namespace std;

/*
  BÀI TOÁN "MULTIPLY 16-BIT NUMBERS USING AN 8-BIT MULTIPLIER"
  -----------------------------------------------------------
  - Nhiệm vụ: Thực hiện phép nhân hai số nguyên 16-bit (m và n) bằng cách sử dụng
    một hàm nhân chỉ hỗ trợ nhân hai số 8-bit. Kết quả là một số nguyên 32-bit.
  - Giới hạn:
      + Sử dụng phép nhân 8-bit (multiply8bit) để nhân từng phần 8-bit của
        hai số 16-bit.
      + Kết hợp kết quả từ các phép nhân 8-bit để tạo ra kết quả 32-bit.

  Ý TƯỞNG
  -----------------------------------------------------------
  1. Chia nhỏ hai số 16-bit thành từng phần 8-bit:
      - Với số m:
          * mLow: 8 bit thấp nhất (least significant bits).
          * mHigh: 8 bit cao nhất (most significant bits).
      - Với số n:
          * nLow: 8 bit thấp nhất.
          * nHigh: 8 bit cao nhất.
  2. Nhân từng phần của m với từng phần của n (tổng cộng 4 phép nhân):
      - mLow × nLow
      - mHigh × nLow
      - mLow × nHigh
      - mHigh × nHigh
  3. Kết hợp các kết quả phép nhân bằng cách dịch bit tương ứng:
      - mLow × nLow: Giữ nguyên (0 byte shift).
      - mHigh × nLow và mLow × nHigh: Dịch 8 bit sang trái (1 byte).
      - mHigh × nHigh: Dịch 16 bit sang trái (2 byte).
  4. Cộng các kết quả lại để ra số 32-bit cuối cùng.

  Độ phức tạp:
      - Thời gian: O(1), thực hiện 4 phép nhân 8-bit và các phép dịch bit.
      - Không gian: O(1).
*/

/*
  Hàm multiply8bit:
  -----------------
  - Nhân hai số 8-bit (unsigned char) và trả về kết quả 16-bit (unsigned short).
*/
unsigned short multiply8bit(unsigned char m, unsigned char n) {
    return m * n;
}

/*
  Hàm multiply16bit:
  -----------------
  - Nhân hai số 16-bit (m, n) bằng cách sử dụng các phép nhân 8-bit.
  - Chia nhỏ m và n thành các phần 8-bit, thực hiện 4 phép nhân, và kết hợp kết quả.
*/
int multiply16bit(int m, int n)
{
    // Lấy 8 bit thấp nhất và 8 bit cao nhất của số m
    unsigned char mLow = (m & 0x00FF);              // Lưu 8 bit thấp nhất của m
    unsigned char mHigh = (m & 0xFF00) >> 8;        // Lưu 8 bit cao nhất của m
 
    // Lấy 8 bit thấp nhất và 8 bit cao nhất của số n
    unsigned char nLow = (n & 0x00FF);              // Lưu 8 bit thấp nhất của n
    unsigned char nHigh = (n & 0xFF00) >> 8;        // Lưu 8 bit cao nhất của n
 
    // Thực hiện 4 phép nhân 8-bit
    unsigned short mLow_nLow = multiply8bit(mLow, nLow);
    unsigned short mHigh_nLow = multiply8bit(mHigh, nLow);
    unsigned short mLow_nHigh = multiply8bit(mLow, nHigh);
    unsigned short mHigh_nHigh = multiply8bit(mHigh, nHigh);
 
    // Kết hợp kết quả bằng cách dịch bit và cộng lại
    return mLow_nLow + ((mHigh_nLow + mLow_nHigh) << 8) + (mHigh_nHigh << 16);
}

/*
  Hàm main:
  -----------------
  - Thực hiện nhân hai số nguyên 16-bit và so sánh kết quả giữa phép nhân thường
    và phép nhân sử dụng nhân 8-bit.
*/
int main()
{
    // Hai số nguyên 16-bit được lưu trong biến 32-bit
    int m = 23472, n = 2600;

    // In giá trị nhị phân của m và n
    cout << m << " in binary is " << bitset<16>(m) << endl;
    cout << n << " in binary is " << bitset<16>(n) << endl << endl;

    // Kết quả nhân thông thường
    cout << "Normal multiplication m × n = " << m * n << endl;

    // Kết quả nhân sử dụng hàm multiply16bit (dùng nhân 8-bit)
    cout << "Using 8–bit multiplier m × n = " << multiply16bit(m, n) << endl;

    return 0;
}
