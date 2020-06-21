class Solution {
public:
    void setPermutation(vector<int>& v,string& result,int n,int k,vector<int>& factorials){
        if(n==1) {result += to_string(v.back()); return;}
        int index = k/factorials[n-1];
        if(k%factorials[n-1]==0) {index--;}
        result += to_string(v[index]);
        v.erase(v.begin()+ index);
        k = k - factorials[n-1]*index;
        setPermutation(v,result,n-1,k,factorials);
    }
    
    string getPermutation(int n, int k){
        if(n==1) {return "1";}
        vector<int> factorials = {1,1,2,6,24,120,720,5040,40320,362880};
        string result = "";
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.emplace_back(i);
        }
        setPermutation(v,result,n,k,factorials);
        return result;
    }
};
