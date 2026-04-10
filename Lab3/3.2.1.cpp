class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i) {
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            int st = i + 1, dr = nums.size() - 1;
            int target = -nums[i];
            while(st < dr) {
                int s = nums[st] + nums[dr];
                if(s == target) {
                    vector<int> tmp{nums[i], nums[st], nums[dr]};
                    ans.push_back(tmp);
                    while(st < dr && nums[st] == nums[st + 1]) {
                        st++;
                    }
                    st++;
                    while(st < dr && nums[dr] == nums[dr - 1]) {
                        dr--;
                    }
                    dr--;
                }  
                if(s < target) st++;
                if(s > target) dr--;
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/3sum/post-solution/?submissionId=1961153488