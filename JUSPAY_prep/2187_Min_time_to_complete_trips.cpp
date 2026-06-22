

class Solution {
public:
    bool isPossible(long long m, vector<int>& time, int t) {
        long long sum = 0;

        for(int val : time) {
            sum += (m / val);
            if (sum >= t) return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int t) {
        long long i = 1;
        long long minTime = *min_element(time.begin(), time.end());

        long long j = minTime * t;

        while(i <= j) {
            long long m = i + (j-i)/2;

            if (isPossible(m, time, t)) j = m-1;
            else i = m+1;
        }

        return i;
    }
};