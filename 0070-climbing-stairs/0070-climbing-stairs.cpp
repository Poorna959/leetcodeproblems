class Solution {
public:
    int answer(int num, unordered_map<int, int> &memo)
{
    if (num == 1 || num == 0)
        return 1;
    if (num < 0)
        return 0;

    if (memo.find(num) != memo.end())
    {
        return memo[num];
    }

    memo[num] = answer(num - 1, memo) + answer(num - 2, memo);
    return memo[num];
}
int climbStairs(int n)
{
    unordered_map<int, int> table;
    return answer(n, table);
}
};