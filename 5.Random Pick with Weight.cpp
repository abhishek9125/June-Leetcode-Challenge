class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
        int n = w.size();
        v.push_back(w[0]);
        for(int i=1;i<n;i++){
            v.push_back(v[i-1] + w[i]);
        }
    }
    
    int pickIndex() {
        double target = rand()%v[v.size()-1];
        for(int i=0;i<v.size();i++){
            if(target<v[i]){
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 
    Suppose w[] = {2, 5, 3} then it means that we have to pick an index from {0, 1, 2} eaning
    probability of picking 0 is 2 / (2 + 5 + 3) = 20 percent,
    probability of picking 1 is 5 / (2 + 5 + 3) = 50 percent ,
    probability of picking 2 is 3 / (2 + 5 + 3) = 30 percent.
    Think about this array [0, 0, 1, 1, 1, 1, 1, 2, 2, 2] -> from this array we have to pick a number randomly
    In order to do it we can generate an array like v[] = {2, 7, 10}, which consists of the cumulative sum 
    of the w[] array. After this simply generate a random number using rand%v[v.size()-1].

    random number in [0,1] -> 0
    random number in [2,6] -> 1
    random number in [7,9] -> 2
    here target is random number generated
    if(target<2){
        we return index 0(target = 1 and 1<2 on iterating in v and random number in [0,1] -> 0)
    }else if(target>=2 and target<7){
        we return index 1(target = 4 and 4<7 on iterating in v and random number in [2,6] -> 1)
    }else{
        we return index 2(target = 7 and 7<10 on iterating in v and random number in [7,9] -> 2)
    }

 */
