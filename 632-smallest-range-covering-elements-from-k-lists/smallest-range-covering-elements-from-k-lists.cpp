class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& arr) {
        vector<int> res = {-10000000,10000000};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int maxi = INT_MIN;
        
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i][0] , i , 0});
            maxi = max(maxi , arr[i][0]);
        }
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int num = it[0] , list = it[1] , index = it[2];
            
            if((res[1] - res[0]) > (maxi - num)){
                res = {num , maxi};
            }
            
            if(index == arr[list].size()-1)break;
            
            pq.push({arr[list][index+1] , list , index+1});
            maxi = max(maxi , arr[list][index+1]);
        }
            
        return res;   
    }
};