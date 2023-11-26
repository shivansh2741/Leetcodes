class Solution {
public:
    string removeDuplicateLetters(string str) {
        stack<char> st;
        vector<int> vis(26,0);
        map<int,int> mp;

        for(auto it:str){
            mp[it]++;
        }

        for(int i=0;i<str.size();i++){
            mp[str[i]]--;

            if(vis[str[i] - 'a'] == 1)continue;

            while(st.size() > 0 && mp[st.top()] > 0 && st.top() >= str[i]){
                vis[st.top() - 'a'] = 0;
                st.pop();
            }

            vis[str[i] - 'a'] = 1;
            st.push(str[i]);
        }

        string res;
        while(st.size() > 0){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin() , res.end());
        return res;
    }
};