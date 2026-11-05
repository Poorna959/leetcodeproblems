class Solution { 
public:     
    int largestRectangleArea(vector<int>& heights) {         
        int n = heights.size();         
        int ans = 0;         
        vector<int> left(n, 0);         
        vector<int> right(n, 0);         
        stack<int> s;          

        // 1. Find the next smaller element to the right
        for(int i = n - 1; i >= 0; i--) { // Fixed: i++ changed to i--
            while(s.size() > 0 && heights[s.top()] >= heights[i]){                 
                s.pop();             
            }             
            if(s.empty()){                 
                right[i] = n; 
            }             
            else{                 
                right[i] = s.top();             
            }             
            s.push(i); 
        }         

        
        while (!s.empty()) {         
            s.pop();  
        }         

        // 2. Find the next smaller element to the left
        for(int i = 0; i < n; i++){             
            while(s.size() > 0 && heights[s.top()] >= heights[i]){                 
                s.pop();             
            }             
            if(s.empty()){                 
                left[i] = -1; 
            }             
            else{                 
                left[i] = s.top();             
            }             
            s.push(i); 
        }         

        // 3. Calculate max area
        for(int i = 0; i < n; i++){             
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }         

        return ans;     
    } 
};
