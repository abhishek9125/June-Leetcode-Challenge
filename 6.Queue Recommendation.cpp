bool compare(vector<int>& v1,vector<int>& v2){
        return (v1[0]>v2[0] || (v1[0]==v2[0] && v1[1]<v2[1]));
    }
    
class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),compare);
        vector<vector<int>> result;
        for(int i=0;i<v.size();i++){
            result.insert(result.begin()+v[i][1],v[i]);
        }
        return result;
    }
};
