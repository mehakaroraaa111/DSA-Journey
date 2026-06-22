# Minimum Number of Days to Make m Bouquets

## Problem
Given an array `bloomDay`, where `bloomDay[i]` represents the day a flower blooms, find the minimum number of days needed to make `m` bouquets, each consisting of `k` adjacent flowers.

## Approach
- Use Binary Search on the number of days.
- For a given day, count how many bouquets can be formed using flowers that have bloomed by that day.
- If at least `m` bouquets can be made, try a smaller day.
- Otherwise, increase the number of days.

## Complexity
- **Time Complexity:** `O(n log(maxDay - minDay))`
- **Space Complexity:** `O(1)`

## Key Learning
- Applying Binary Search on the answer space.
- Checking feasibility using a helper function.
- Solving optimization problems efficiently.

class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int cnt = 0;

        for (int x : bloomDay) {
            if (x <= day) {
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * m * k;
        if (total > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
