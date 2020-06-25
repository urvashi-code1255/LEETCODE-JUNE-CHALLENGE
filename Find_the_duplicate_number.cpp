class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        for (auto i : nums) 
        {
            if (!s.count(i)) 
                s.insert(i); 
            else 
                return i;
        }
        return -1;
    }
};
