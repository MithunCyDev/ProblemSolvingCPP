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


//hourglassSum
#include <iostream>
#include <vector>

int hourglassSum(std::vector<std::vector<int>>& arr) {
    int maxSum = -INT_MAX;

    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            int currentSum = 
                arr[i][j] + arr[i][j+1] + arr[i][j+2] +
                            arr[i+1][j+1] +
                arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}

int main() {
    std::vector<std::vector<int>> arr = {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 2, 4, 4, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 1, 2, 4, 0}
    };

    int maxHourglassSum = hourglassSum(arr);
    std::cout << maxHourglassSum << std::endl; // Output: 19

    return 0;
}
