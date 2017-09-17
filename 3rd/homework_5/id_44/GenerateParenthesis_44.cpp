class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str(2*n, ' ');
        help(0, 0, n, res, str);
        return res;
    }
    void help(int idx, int cnt, int left, vector<string>& res, string& str) {
        if (!cnt && !left) {
            res.push_back(str);
            return;
        }
        auto& curr = str[idx++];
        if (!cnt) {
            curr = '(';
            help(idx, cnt+1, left-1, res, str);
        }
        else if (!left) {
            curr = ')';
            help(idx, cnt-1, left, res, str);
        }
        else {
            curr = ')';
            help(idx, cnt-1, left, res, str);
            curr = '(';
            help(idx, cnt+1, left-1, res, str);
        }
    }
};
