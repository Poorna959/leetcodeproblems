class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n=customers.size();
    int is = 0;
    for(int i=0;i<n;i++){
        if(grumpy[i]==0){
            is+=customers[i];
        }
    }
    int ans=0;
    int as = 0;
    for(int i=0;i<minutes;i++){
        if(grumpy[i]==1){
            as+=customers[i];
        }
    }
        int max_as = as;
    for(int i=minutes;i<n;i++){
        if(grumpy[i]==1){
            as+=customers[i];
        }
        if(grumpy[i-minutes]==1){
            as-=customers[i-minutes];
        }

        max_as = max(max_as,as);
    }
    return is+max_as;
    
    }
};