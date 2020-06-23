class Solution {
public:
    int singleNumber(vector<int>& nums){
        int bitSum[32] = {0};
        for(auto i: nums){
            for(int j=0;j<32;j++){
                if(i&(1<<j)){
                    bitSum[j]++;
                }
            }
        }
        
        long long p = 1;
        int ans = 0;
        for(int i=0;i<32;i++){
            bitSum[i] = bitSum[i]%3;
            ans = ans + bitSum[i]*p;
            p=p*2;
        }
        return ans;
    }
};

