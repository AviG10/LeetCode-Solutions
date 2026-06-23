class Fancy {
private:
    long long MOD = 1e9+7;
    long long add = 0;
    long long multi = 1;
    vector<int> seq;

    // Binary Exponentiation
    long long power(long long val, long long n){
        long long ans = 1;

        while(n > 0){
            if(n%2 == 1){
                ans = (ans*val)%MOD;
                n = n-1;
            }
            else{
                n = n / 2;
                val = (val * val) % MOD;
            }
        }

        return ans;
    }

public:
    Fancy() {
        
    }
    
    void append(int val) {
        int ele = ((val-add+MOD)%MOD * power(multi,MOD-2)%MOD)%MOD; // Fermat's Little Theorem
        seq.push_back(ele);
    }
    
    void addAll(int inc) {
        add = (add + inc)%MOD;
    }
    
    void multAll(int m) {
        multi = (multi * m)%MOD;
        add = (add * m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size()) return -1;
        else return ((seq[idx] * multi)%MOD + add)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */