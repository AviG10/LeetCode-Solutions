// Binary Search on Answer + Circular Array + Greedy
class Solution {
private:
    // 8. Function to Flattening the 2D Points Array to 1D Array
    long long getFlattenedArray(int x, int y, int side){
        if(y == 0) return x;
        else if(x == side) return side + y;
        else if(y == side) return 3LL * side - x;
        else return 4LL * side - y;
    }
    
    bool isPossible(int mid, int &k, int &side, int &n, long long &perimeter, vector<long long> &doubledFlattenedArray){
        // 6. For All the points given in Points Array, take every point as starting point and try to find remaining (k-1) points
        for(int i = 0;i < n;i++){
            int idx = i;
            long long lastPos = doubledFlattenedArray[idx];
            int count = 1;

            for(int j = 2;j <= k;j++){
                long long target = lastPos + mid;
                // 9. Choosing Greedily 
                int nextElementIdx = lower_bound(doubledFlattenedArray.begin()+idx+1, doubledFlattenedArray.begin()+i+n,target)
                                        - doubledFlattenedArray.begin();

                if(nextElementIdx == i+n) break;
                
                idx = nextElementIdx;
                lastPos = doubledFlattenedArray[nextElementIdx];
                count++;
            }

            // 7. Corner Case
            if(count == k && (doubledFlattenedArray[i] + perimeter - lastPos) >= mid) return true;
        }

        return false;
    }
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        long long perimeter = 4LL * side;

        // 1. Flattening the 2D Points Array to 1D Array
        vector<long long> flattenedArray(n);
        for(int i = 0;i < n;i++){
            flattenedArray[i] = getFlattenedArray(points[i][0],points[i][1],side);
        }

        // 2. Sort Flattened 1D Array for the Ease of Searching 
        sort(flattenedArray.begin(),flattenedArray.end());

        // 3. Doubled the Flattened 1D Array to Circular Search efficiently in the Flattened 1D Array
        vector<long long> doubledFlattenedArray(2*n);
        for(int i = 0;i < n;i++){
            doubledFlattenedArray[i] = flattenedArray[i];
            doubledFlattenedArray[n+i] = flattenedArray[i] + perimeter;
        }

        // 4. Binary Search On Answer
        int low = 0, high = 2 * side;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(isPossible(mid,k,side,n,perimeter,doubledFlattenedArray)) low = mid+1;
            else high = mid-1;
        }

        return high;
    }
};