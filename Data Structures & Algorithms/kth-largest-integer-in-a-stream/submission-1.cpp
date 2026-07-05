class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int size;
    KthLargest(int k, vector<int>& nums) {
       size = k;
       for (int num : nums) {
        if (min_heap.size() < size) {
            min_heap.push(num);
        } else if (num > min_heap.top()) {
            min_heap.pop();
            min_heap.push(num);
        }
       }
    }
    
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > size) {
            min_heap.pop();
        }
        return min_heap.top();
    }
};
