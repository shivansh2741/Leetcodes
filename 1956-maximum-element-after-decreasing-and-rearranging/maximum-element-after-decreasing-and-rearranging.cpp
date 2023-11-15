class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        map<int,int>mp;    

        for(auto it:arr){
            mp[it]++;
        }

        int curr = 1;
        while(mp.size() > 0){
            if(mp.find(curr) != mp.end()){
                mp.erase(curr);
                curr++;
            }
            else{
                auto it = mp.begin();
                mp[it->first]--;
                curr++;

                if(mp[it->first] == 0)
                    mp.erase(it->first);
            }
        }
        return curr-1;
    }
};