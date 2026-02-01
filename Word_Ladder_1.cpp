class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st = {wordList.begin(), wordList.end()};
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            pair node = q.front();
            if(node.first == endWord) return node.second;
            q.pop();
            string s = node.first;
            for(int i = 0 ; i < s.length() ; i++){
                char ch = s[i];
                string a = s;
                for(char c = 'a' ; c <= 'z' ; c++){
                    if(c == ch) continue;
                    a[i] = c;
                    if(st.find(a) != st.end()){
                        q.push({a, node.second + 1});
                        st.erase(a);
                    }
                }
            }
        }
        return 0;
    }
};
