class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long MASS = mass;

        sort(asteroids.begin(),asteroids.end());
        
        for(int i = 0;i < n;i++){
            if(MASS < asteroids[i]) return false;
            else MASS += asteroids[i];
        }

        return true;
    }
};