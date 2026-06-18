# Binary Search on Answer - LeetCode Problems

This repository contains optimized solutions to classical Binary Search on Answer problems.

## 📌 Problems Solved
- Koko Eating Bananas
- Smallest Divisor
- Minimum Days to Make M Bouquets
- Ship Capacity (optional)

## 🧠 Concept
These problems are solved using:
- Binary Search on the answer space
- Greedy feasibility checks

## ⚙️ Approach
1. Define search space (low → high)
2. Use binary search to test mid value
3. Validate using a greedy helper function
4. Adjust search range accordingly

## 🚀 Complexity
- Time: O(n log maxValue)
- Space: O(1)


  class Solution {
public:
    long long calculateTotalHours(vector<int>& piles, int speed) {
        long long totalH = 0;

        for (int pile : piles) {
            totalH += (pile + speed - 1) / speed;
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = maxPile;
        int ans = maxPile;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
## 📚 Key Learning
All problems follow the same pattern:
"If a condition is monotonic, we can binary search the answer."
