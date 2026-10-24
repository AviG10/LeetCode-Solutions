class Solution {
private:
    int daysinmonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int getdays(string s){
        int month = (s[0]-'0')*10 + (s[1]-'0');
        int days = (s[3]-'0')*10 + (s[4]-'0');
        
        month--;
        
        int ans = 0;
        while(month >= 0){
            ans += daysinmonth[month];
            month--;
        }
        
        ans += days;
        return ans;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aa = getdays(arriveAlice), al = getdays(leaveAlice), ba = getdays(arriveBob), bl = getdays(leaveBob);
        
        int ans = 0;
        for(int i = 0;i < 367;i++)
            if(aa <= i && i <= al && ba <= i && i <= bl) ans++;
        
        return ans;
    }
};