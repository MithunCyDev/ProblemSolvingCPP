#include <iostream>
#include <string>

int beautifulDays(int i, int j, int k) {
    int beautifulCount = 0;

    for (int day = i; day <= j; day++) {
        int reversed = 0;
        int temp = day;

        while (temp > 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }

        int difference = abs(day - reversed);
       
        if (difference % k == 0) {
            beautifulCount++;
        }
    }

    return beautifulCount;
}

int main() {
    int result = beautifulDays(20, 23, 6);
    std::cout << result << std::endl; // Output: 2

    return 0;
}
