class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> tmp;
        
        for(int i=0; i<tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" ||tokens[i] == "*" ||tokens[i] == "/") {
                int s = tmp.top();
                tmp.pop();
                int f = tmp.top();
                tmp.pop();
                if(tokens[i] == "+")
                    tmp.push(f+s);
                else if(tokens[i] == "-")
                    tmp.push(f-s);
                else if(tokens[i] == "*")
                    tmp.push(f*s);
                else
                    tmp.push(f/s);
            } else {
                tmp.push(atoi(tokens[i].c_str()));
            }
        }
        return tmp.top();
    }
};