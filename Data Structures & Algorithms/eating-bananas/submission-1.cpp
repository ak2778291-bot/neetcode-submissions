class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = 1;

        // Find the largest pile
        for (int pile : piles) {
            right = max(right, pile);
        }

        int answer = right;

        while (left <= right) {

            int k = (left + right) / 2;

            long long hours = 0;

            // Calculate how many hours Koko needs at speed k
            for (int pile : piles) {

                hours += (pile + k - 1) / k;
            }

            if (hours <= h) {
                // k works, so try a smaller speed
                answer = k;
                right = k - 1;
            }
            else {
                // k is too slow, so try a larger speed
                left = k + 1;
            }
        }

        return answer;
    }
};