bool compare(vector<int>& v1,vector<int>& v2){
    return abs(v1[0] - v1[1])>abs(v2[0] - v2[1]);
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(),costs.end(),compare);
        for(int i=0;i<n;i++){
            cout<<costs[i][0]<<" "<<costs[i][1]<<endl;
        }
        int countA = 0;
        int countB = 0;
        int cost = 0;
        for(int i=0;i<n;i++){
            if(countB==n/2 || (costs[i][0]<=costs[i][1] && countA<n/2)){
                countA++;
                cost = cost + costs[i][0];
            }else{
                countB++;
                cost = cost + costs[i][1];
            }
        }
        return cost;
    }
};
