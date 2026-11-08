class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        vector<int> s(n,0);
        int curr=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(operations[i]=="C"){
                ans-=s[curr-1];
                s[curr-1]=0;
                curr--; 
            }
            else if(operations[i]=="+"){
                s[curr]=s[curr-1]+s[curr-2];
                ans+=s[curr];
                curr++;
            }
            else if(operations[i]=="D"){
                s[curr]=s[curr-1]*2;
                ans+=s[curr];
                curr++;
            }
            else{
                s[curr]=stoi(operations[i]);
                ans+=s[curr];
                curr++;
            }
        }
        return ans;
    }
};