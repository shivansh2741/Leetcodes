class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long total = 0;
        priority_queue<long> pq;

        for(auto it:nums){
            pq.push(it);
            total += 1LL*it;
        }    

        if(total == target)return 0;
        if(total < target)return -1;

        int operations = 0;
        while(!pq.empty() && target > 0){
            auto it = pq.top();
            pq.pop();

            total -= it;
            if(total == target)return operations;

            if(total > target){
                continue;
            }
            else{
                if(target == it)return operations;
                if(target > it){
                    target -= it;
                    continue;
                }

                if(it/2 > target){
                    pq.push(it/2);
                    pq.push(it/2);
                    total += it;
                }
                else{
                    target -= it/2;
                    total += it/2;
                    pq.push(it/2);
                }
                operations++;
            }
        }
        if(target > 0)return -1;
        return operations;
    }
};