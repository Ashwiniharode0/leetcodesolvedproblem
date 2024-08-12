class KthLargest {
public:
    int K;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto &num:nums){
            pq.push(num);
            if(pq.size()>K){
                pq.pop(); //min element will be popped
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() >K){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */