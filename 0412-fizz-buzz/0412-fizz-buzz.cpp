class Solution {
public:
    vector<string> fizzBuzz(int n) {
        string a = "FizzBuzz";
        string b = "Fizz";
        string c = "Buzz";
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0){
                ans.push_back(a);
            }
            else if(i%3==0){
                ans.push_back(b);
            }
            else if(i%5==0){
                ans.push_back(c);
            }
            else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};