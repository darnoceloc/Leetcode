class Solution {
public:
    int trap(vector<int>& height) {
    //version1: Two pointers
        int ans = 0;
        int start = 0, end = height.size() - 1;
        int maxleft = 0, maxright = 0;
        while(start < end) {
            if(height[start] < height[end]) {
                maxleft = max(maxleft, height[start]);
                ans += maxleft - height[start++];                
            }
            else {
                maxright = max(maxright, height[end]);
                ans += maxright - height[end--];                   
            }
        }
        return ans;
    //version2: Use vector
        int len = height.size();
        int ans = 0;
        vector<int> left_high(len, 0);
        vector<int> right_high(len, 0);
        for(int i = 1; i < len; ++i) {
            left_high[i] = max(left_high[i - 1], height[i - 1]);
            right_high[len - i - 1] = max(right_high[len - i], height[len - i]);
        }
        for(int i = 1; i < len - 1; ++i) {
            int bound = min(left_high[i], right_high[i]);
            if(bound > height[i]) ans += bound - height[i];
        }
        return ans;
    //version3: using Stack
        stack<int> st;
        int ans = 0;
        int pos = 0;
        while(pos < height.size()) {
            if(st.empty() || height[pos] <= height[st.top()]) {
                st.push(pos);
                pos++;
            }
            else {
                int bottom = height[st.top()];
                st.pop();
                if(!st.empty()) {
                    int bar = min(height[st.top()], height[pos]);
                    ans += (bar - bottom) * (pos - st.top() - 1);
                }                
            }
        }
        return ans;
    }
};