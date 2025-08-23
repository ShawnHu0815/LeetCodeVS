#include <bits/stdc++.h>
using namespace std;

// 字符串里找没有重复字符的最长连续子串
string longestSubString(string s){
    string ans = "";
    vector<int> count(26);
    int left =0, right = 0;
    int n = s.length();
    while(right < n){
        char c = s[right];
        if(count[c-'a']==0){
            count[c-'a']=right;
            right++;
        }
        else if(count[c-'a']!=0){
            string cur = s.substr(left,right-left);
            if(cur.length() > ans.length()){
                ans = cur;
            }
            for(int i=left;i<count[c-'a'];i++){
                char temp = s[i];
                count[temp-'a'] = 0;
            }
            left = count[c-'a']+1;
            right++;
        }
    }
    string cur = s.substr(left,right-left);
    if(cur.length() > ans.length()){
        ans = cur;
    }
    return ans;
}


int main() {
    string s = "abcbdefg";
    string ans = longestSubString(s);
    cout << ans << endl;
    string s2 = "abcbdefa";
    string ans2 = longestSubString(s2);
    cout << ans2 << endl;
    return 0;
}