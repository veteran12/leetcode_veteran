class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string,int>> bfs;
        bfs.push(make_pair(start, 1));
        
        while(!bfs.empty()) {
            pair<string, int> front = bfs.front();
            bfs.pop();
            string word = front.first;
            for(int i=0; i<start.size(); i++) {
                char origin = word[i];
                for(char j='a'; j<'z'; j++) {
                    word[i] = j;
                    if (word == end)
                        return front.second + 1;
                    if(dict.find(word) != dict.end()) {
                        bfs.push(make_pair(word,front.second + 1));
                        dict.erase(word); //important!
                    }
                }
                word[i] = origin;
            }
        }
        return 0;
    }
};