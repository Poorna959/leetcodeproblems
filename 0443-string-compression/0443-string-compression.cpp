class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int ind=0;
        for(int i=0;i<n;i++){
            char ch=chars[i];
            int count=0;
        
            while(i<n && ch==chars[i]){
                count++;i++;
            }
            if(count==1){chars[ind++]=ch;}
            else{
                chars[ind++]=ch;
                string str = to_string(count);
                for(auto dig:str){
                    chars[ind++]=dig;
                }
            }
i--;
        }
    return ind;    
    }
};