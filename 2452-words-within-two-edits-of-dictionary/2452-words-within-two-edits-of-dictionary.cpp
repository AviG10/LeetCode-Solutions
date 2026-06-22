class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int q_size = queries.size(),d_size = dictionary.size();
        vector<string> ans;

        for(int i = 0;i < q_size;i++){
            string q_word = queries[i];

            for(int j = 0;j < d_size;j++){
                string d_word = dictionary[j];
                int n = q_word.length(), diff = 0;

                for(int k = 0;k < n;k++){
                    if(q_word[k] != d_word[k]) diff++;
                    if(diff > 2) break;
                }

                if(diff <= 2){
                    ans.push_back(q_word);
                    break;
                } 
            }
        }

        return ans;
    }
};