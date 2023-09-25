//beautifulDays
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

//saveThePrisoner
#include <iostream>
using namespace std;

int saveThePrisoner(int n, int m, int s) {
    int result = (m + s - 1) % n;
    if (result == 0) {
        result = n;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, m, s;
        cin >> n >> m >> s;
        int prisonerToWarn = saveThePrisoner(n, m, s);
        cout << prisonerToWarn << endl;
    }

    return 0;
}

//viralAdvertising
#include <iostream>
using namespace std;

int viralAdvertising(int n) {
    int shared = 5;
    int liked = shared / 2;
    int cumulativeLikes = liked;

    for (int day = 2; day <= n; day++) {
        shared = liked * 3; // Each person shares with 3 friends
        liked = shared / 2;
        cumulativeLikes += liked;
    }

    return cumulativeLikes;
}

int main() {
    int dayNumber = 3;
    int result = viralAdvertising(dayNumber);
    cout << result << endl; // Output: 9

    return 0;
}

//jumpingOnClouds
#include <iostream>
#include <vector>

int jumpingOnClouds(std::vector<int>& c, int k) {
    int energy = 100;
    int currentPosition = 0;
    const int n = c.size();

    do {
        currentPosition = (currentPosition + k) % n;
        energy -= c[currentPosition] * 2 + 1;
    } while (currentPosition != 0);

    return energy;
}

int main() {
    // Example usage
    std::vector<int> clouds = {0, 0, 1, 0, 0, 1, 1, 0};
    int jumpDistance = 2;
    int finalEnergy = jumpingOnClouds(clouds, jumpDistance);

    std::cout << finalEnergy << std::endl; // Output: 92

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

//appendAndDelete
string appendAndDelete(string s, string t, int k) {
    int commonLength = 0;

    // Find the length of the common prefix
    for (int i = 0; i < min(s.length(), t.length()); i++) {
        if (s[i] == t[i]) {
            commonLength++;
        } else {
            break;
        }
    }

    // Calculate the total operations needed
    int totalOperations = s.length() + t.length() - 2 * commonLength;

    // Check if it's possible
    if (totalOperations <= k && (totalOperations - k) % 2 == 0 || k >= s.length() + t.length()) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    // Example usage
    cout << appendAndDelete("hackerhappy", "hackerrank", 9) << endl; // Output: Yes
    cout << appendAndDelete("aba", "aba", 7) << endl; // Output: Yes

    return 0;
}

//queensAttack
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int up = n - r_q;
    int down = r_q - 1;
    int left = c_q - 1;
    int right = n - c_q;
    int up_left = min(up, left);
    int up_right = min(up, right);
    int down_left = min(down, left);
    int down_right = min(down, right);

    for (int i = 0; i < k; i++) {
        int r_obs = obstacles[i][0];
        int c_obs = obstacles[i][1];

        if (r_obs == r_q) {
            if (c_obs < c_q) {
                left = min(left, c_q - c_obs - 1);
            } else {
                right = min(right, c_obs - c_q - 1);
            }
        } else if (c_obs == c_q) {
            if (r_obs < r_q) {
                down = min(down, r_q - r_obs - 1);
            } else {
                up = min(up, r_obs - r_q - 1);
            }
        } else if (abs(r_obs - r_q) == abs(c_obs - c_q)) {
            if (r_obs < r_q) {
                if (c_obs < c_q) {
                    down_left = min(down_left, min(r_q - r_obs - 1, c_q - c_obs - 1));
                } else {
                    down_right = min(down_right, min(r_q - r_obs - 1, c_obs - c_q - 1));
                }
            } else {
                if (c_obs < c_q) {
                    up_left = min(up_left, min(r_obs - r_q - 1, c_q - c_obs - 1));
                } else {
                    up_right = min(up_right, min(r_obs - r_q - 1, c_obs - c_q - 1));
                }
            }
        }
    }

    return up + down + left + right + up_left + up_right + down_left + down_right;
}

int main() {
    int n, k, r_q, c_q;
    cin >> n >> k >> r_q >> c_q;
    vector<vector<int>> obstacles(k, vector<int>(2));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);
    cout << result << endl;

    return 0;
}


