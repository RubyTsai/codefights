// https://codefights.com/interview-practice/task/rFeSD5rNy9RxfLcqg/description

string minSubstringWithAllChars(string s, string t) {
    if (s.empty() || t.empty()) return "";
    unordered_map<char, vector<int>> m;
    for (auto c: t) {
        int find = s.find(c);;
        while (find != string::npos) {
            m[c].emplace_back(find);
            find = s.find(c, find+1);
        }
    }
    
    unordered_map<char, int> itor;
    for (auto c: t) itor[c] = 0;
    
    int maxCurr = 0, minCurr = s.size();
    int maxPos = s.size(), minPos = 0, pos;
    char startC;
    while (1) {
        for (auto& kv:m) {
            pos = kv.second[itor[kv.first]];
            maxCurr = max(maxCurr, pos);
            if (pos < minCurr) {
                minCurr = pos;
                startC = kv.first;
            }
        }
        if (maxCurr - minCurr < maxPos - minPos) {
            maxPos = maxCurr;
            minPos = minCurr;
        }
        itor[startC] += 1;
        if (itor[startC] == m[startC].size()) break;
        minCurr = maxCurr;
    }
    return move(s.substr(minPos, maxPos-minPos+1));
}
