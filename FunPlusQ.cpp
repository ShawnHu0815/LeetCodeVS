#include <bits/stdc++.h>
using namespace std;

bool SignUp(string username, string password){
    int n = username.size();
    if(n < 6 || n > 20) return false;
    if(username[0] >= '0' && username[0] <= '9') return false;
    if(username[0]=='.' || username[n-1]=='.' ) return false;
    for(int i=0;i<n;i++){
        if(!((username[i]>='a' && username[i]<='z') || (username[i]>='A' && username[i]<='Z') || (username[i]>='0' && username[i]<='9') || username[i]=='.')){
            return false;
        }
        if(i>0 && username[i]=='.' && username[i-1]=='.') return false;
    }
    string usernameWithoutDot = "";
    for(int i=0;i<n;i++){
        if(username[i]!='.') usernameWithoutDot += tolower(username[i]);
    }

    int m = password.size();
    if(m < 8 || m > 16) return false;
    int typeNum = 0;
    bool hasLower = false, hasUpper = false, hasDigit = false, hasOther = false;
    for(int i=0;i<m;i++){
        if(password[i]>='a' && password[i]<='z') hasLower = true;
        else if(password[i]>='A' && password[i]<='Z') hasUpper = true;
        else if(password[i]>='0' && password[i]<='9') hasDigit = true;
        else if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || password[i]=='~') hasOther = true;
        else return false;
    }
    string passwordLower = password;
    transform(passwordLower.begin(), passwordLower.end(), passwordLower.begin(), ::tolower);
    if(passwordLower.find(usernameWithoutDot) != string::npos) return false;
    typeNum += hasLower + hasUpper + hasDigit + hasOther;
    if(typeNum < 3) return false;
    
    return true;
}

int main() {
    cout << SignUp("funplus.com","AAA123456bbb") << endl;
    cout << SignUp("12345678","abcdefg123") << endl;
    return 0;
}