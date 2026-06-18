# 📌 Smallest Divisor Given a Threshold

This repository contains an optimized solution to the problem **“Find the Smallest Divisor Given a Threshold”** using the **Binary Search on Answer** technique.

---

## 🚀 Problem Statement

Given an array of integers `nums` and an integer `threshold`, find the smallest integer divisor such that:

\[
\sum \lceil \frac{nums[i]}{divisor} \rceil \leq threshold
\]

Each division result is rounded up.

---

## 🧠 Approach

This problem is solved using:

### ✔ Binary Search on Answer
- Search space: `1 → max(nums)`
- Check if a divisor is valid using a helper function

### ✔ Greedy Validation
For a given divisor:
- Compute sum of `ceil(nums[i] / divisor)`
- Check if it is within threshold

---

## ⚙️ Algorithm Steps

1. Set `low = 1`, `high = max(nums)`
2. Perform binary search:
   - Compute `mid` as current divisor
   - Calculate required sum using greedy function
3. If valid:
   - Store answer
   - Move left (`high = mid - 1`)
4. Else:
   - Move right (`low = mid + 1`)
5. Return smallest valid divisor

---

## ⏱ Complexity Analysis

- **Time Complexity:** `O(n log max(nums))`
- **Space Complexity:** `O(1)`

---

## 💡 Key Idea

If a divisor works, all larger divisors will also work.

👉 This monotonic behavior allows Binary Search on Answer.

---

## 🧾 Code Snippet

```cpp
class Solution {
public:

    int sumByD(vector<int>& arr, int div) {
        int sum = 0;
        for (int num : arr) {
            sum += (num + div - 1) / div;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sumByD(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
