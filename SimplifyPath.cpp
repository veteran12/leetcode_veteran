class Solution {
public:
    string simplifyPath(string path) {
        string res;
        path += "/";
        size_t pos = path.find_first_of("/"), last = 0;
        while (pos != string::npos)
        {
            string s = path.substr(last, pos - last);
            if (s == "..") 
            {
                if (!res.empty())
                    res.resize(res.find_last_of("/"));
            }
            else if (!s.empty() && s != ".")
            {
                res += "/";
                res += s;
            }
            last = pos + 1;
            pos = path.find_first_of("/", last);
        }
        return res.empty() ? "/" : res;
    }
};