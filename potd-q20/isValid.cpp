#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> st;
    for (unsigned i=0;i<input.size();i++){
        if (input[i]=='(')
            st.push(')');
        if (input[i]=='[')
            st.push(']');
        if (input[i]=='{')
            st.push('}');
        if (input[i]==')'||input[i]==']'||input[i]=='}'){
            if (st.empty())
                return false;
            if (input[i]!=st.top())
                return false;
            else
                st.pop();
        }
    }
    if (st.empty())
        return true;
    return false;    // modify this!
}
