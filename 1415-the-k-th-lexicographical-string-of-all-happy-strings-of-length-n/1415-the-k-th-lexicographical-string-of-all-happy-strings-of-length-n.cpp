class Solution {
private:
    void f(int ind,char c,string &temp,vector<string> &list){
        if(ind == 0){
            list.push_back(temp);
            return;
        }

        if(c == 'd' || c == 'b' || c == 'c'){
            temp += 'a';
            f(ind-1,'a',temp,list);
            temp.pop_back();
        }
        
        if(c == 'd' || c == 'a' || c == 'c'){
            temp += 'b';
            f(ind-1,'b',temp,list);
            temp.pop_back();
        }

        if(c == 'd' || c == 'a' || c == 'b'){
            temp += 'c';
            f(ind-1,'c',temp,list);
            temp.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> list;
        string temp = "";

        f(n,'d',temp,list);

        sort(list.begin(),list.end());
        
        if(k > list.size()) return "";
        else return list[k-1];
    }
};