
// Same as aggressive cow, literally same code

class Solution {
public:
    bool canPlace(int m, int balls, vector<int>& position) {
        int placed = position[0];
        int cnt = 1;

        for(int i = 1; i < position.size(); i++) {
            if (position[i] - placed >= m) {
                cnt++; placed = position[i];
            }

            if (cnt >= balls) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));

        int i = 1, j = position.back() - position.front();

        while(i <= j) {
            int mid = i + (j-i)/2;
            if (canPlace(mid, m, position)) i = mid+1;
            else j = mid-1;
        }

        return j;
        
    }
};