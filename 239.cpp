class Solution {
public:
    struct node{
        int val;
        int idx;
        node(int val, int idx) {
            this->val = val;
            this->idx = idx;
        }
        bool operator < (const node & a) const{
            return val < a.val;
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<node>heap;
        for(int i=0; i<k-1;i++) heap.push(node{nums[i], i});
        for(int i = k-1; i<nums.size();i++){
            heap.push(node{nums[i], i});
            node tmp = heap.top();
            while(tmp.idx <= i - k){
                heap.pop();
                tmp = heap.top();
            }
            ans.push_back(tmp.val);
        }
        return ans;
    }
  
};
