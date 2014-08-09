class Solution {
public:
    bool isNumber(const char *s) {
        enum InputType {INVALID, SPACE, SIGN, DIGIT, DOT, EXPONENT};
        int transitionTable[][6] = 
        { /* 0   1   2   3   4   5  */
             0,  1,  2,  3,  4,  0, // 0: INVALID
             0,  1,  2,  3,  4,  0, // 1: SPACE
             0,  0,  0,  3,  4,  0, // 2: SIGN
             0,  6,  0,  3,  7,  5, // 3: DIGIT
             0,  0,  0,  7,  0,  0, // 4: DOT
             0,  0,  2,  8,  0,  0, // 5: EXPONENT
             0,  6,  0,  0,  0,  0, // 6: END WITH SPACE
             0,  6,  0,  7,  0,  5, // 7: DOT AND DIGIT
             0,  6,  0,  8,  0,  0, // 8: END WITH SPACE OR DIGIT
        };
        
        InputType last = INVALID;
        while (*s != '\0')
        {
            InputType state = INVALID;
            if (*s == ' ')
                state = SPACE;
            else if (isdigit(*s))
                state = DIGIT;
            else if (*s == '+' || *s == '-')
                state = SIGN;
            else if (*s == 'e')
                state = EXPONENT;
            else if (*s == '.')
                state = DOT;
            last = (InputType) transitionTable[last][state];
            if (last == INVALID) return false;
            s++;
        }
        bool validFinal[] = {0, 0, 0, 1, 0, 0, 1, 1, 1};
        return validFinal[last];
    }
};