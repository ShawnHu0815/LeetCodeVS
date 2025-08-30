int happyTriangle(vector<int>& length) {
    int n = length.size();
    int ans = 0;
    sort(length.begin(), length.end());
    int a,b,c;
    for(int i = 0; i < n-2; i++) {
        a = length[i];
        for(int j = i+1; j < n-1; j++) {
            b = length[j];
            for(int k = j+1; k < n; k++) {
                c = length[k];
                if(a + b > c) {
                    if( a == b && b == c) {
                        continue;
                    }
                    if(pow(a, 2) + pow(b, 2) == pow(c, 2)) {
                        continue;
                    }
                    ans++;
                }
            }
        }
    }
    return ans;
}