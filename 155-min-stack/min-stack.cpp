class MinStack {
public:
    map<int, int> m;
    vector <int> arr;

    MinStack() {
        m.clear();
    }
    
    void push(int value) {
        m[value]++;
        arr.push_back(value);
    }
    
    void pop() {
        int value = arr.back();
        m[value]--;
        if(!m[value]) m.erase(value);
        arr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        auto it = m.begin();
        return it->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */