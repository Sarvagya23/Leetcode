class Solution {
public:
    char isAlphaNumeric(char c){
        if((c >= 97 && c <= 122) || c >= 65 && c <= 90){
            return tolower(c);
        }
        if(c >= 48 && c <= 57){
            return c;
        }
        return '-';
    }

    string removeSpecialCharacters(string s, int n){
        string p;
        for(int i = 0; i < n; i++){
            char temp = isAlphaNumeric(s[i]);
            if(temp != '-') p += temp;
        }
        return p;
    }

    bool isPalindrome(string s, int n){
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n-1-i]){
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {
        int n = s.length();
        s = removeSpecialCharacters(s,n);
        n = s.length();
        return isPalindrome(s,n);
    }
};