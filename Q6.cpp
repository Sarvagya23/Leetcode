class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows == 1 || n <= numRows){
            return s;
        }
        int sp = (numRows-1)*2;
        int index = 0;
        string ans = "";
        
        for(int i = 0; i < numRows; i++){
            int j = i;
            ans += s[j];
            j += sp;
            if(i == numRows-1){
                index = 0;
            }
            while(j < n){
                if(index != 0){
                    ans += s[j-index];
                }
                ans += s[j];
                j += sp;
            }
            if(j >= n && j - index < n){
                ans += s[j-index];
            }
            index += 2;
        }
        return ans;
    }
};