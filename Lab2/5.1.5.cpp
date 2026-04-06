class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> S;
        S.push({s[0], 1});
        for(int i = 1; i < s.size(); ++i) {

            while(i < s.size() && !S.empty() && s[i] == S.top().first) {
                auto x = S.top();
                S.pop();

                if(x.second < k - 1) {
                    S.push({s[i], x.second + 1});
                }
                ++i;
            }
            if(i < s.size()) S.push({s[i], 1});
            
        }
        string ans;
        while(!S.empty()) {
            auto x = S.top();
            S.pop();
            for(int i = 0; i < x.second; ++i) ans.push_back(x.first);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

};

//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/solutions/7796552/sol-by-ung-ki55/