struct Node{
    Node* links[2];
    int ones = 0 , zeros = 0;

    bool containsKey(int key){
        return (links[key] != NULL);
    }

    void put(int key,Node* node){
        links[key] = node;
        addKey(key);
    }

    Node* get(int key){
        return links[key];
    }

    void addKey(int key){
        if(key == 1)ones++;
        else zeros++;
    }

    void removeKey(int key){
        if(key == 1)ones--;
        else zeros--;
    }

    int getKeys(int key){
        if(key == 1)return ones;
        else return zeros;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=20;i>=0;i--){
            bool key = num & (1 << i);

            if(!node->containsKey(key)){
                node->put(key , new Node());
            }
            node = node->get(key);
        }
    }

    void remove(int num){
        Node* node = root;
        for(int i=20;i>=0;i--){
            bool key = num & (1 << i);

            node->removeKey(key);
            node = node->get(key);
        }
    }

    int maxXor(int num){
        Node* node = root;
        int maxi = 0;

        for(int i=20;i>=0;i--){
            bool key = !(num & (1 << i));

            if(node->getKeys(key) > 0){
                maxi = maxi | (1 << i);
                node = node->get(key);
            }
            else node = node->get(!key);
        }

        return maxi;
    }
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin() , nums.end()); //nlogn
        int maxAns = 0;

        Trie* obj = new Trie();

        int i = 0, j = 0;

        while(i < n){ //n
            int index = upper_bound(nums.begin(),nums.end(),nums[i]*2) - nums.begin(); //logn

            index--;
            
            while(j <= index){  //--> O(n) overall
                obj->insert(nums[j]);  //O(m)  m = length of word
                j++;
            }

            maxAns = max(maxAns , obj->maxXor(nums[i]));
            obj->remove(nums[i]); // O(m)
            i++;
        }
        return maxAns;
    }
};
// TC - O(n*(logn + m) + n)