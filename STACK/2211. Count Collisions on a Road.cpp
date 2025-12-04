// Ques Link = https://leetcode.com/problems/count-collisions-on-a-road/description/?envType=daily-question&envId=2025-12-04
class Solution {
public:
    int countCollisions(string directions) {
        
        stack<char> st;

        int cnt = 0;

        for(auto &x : directions){

            if(x == 'R'){

                st.push(x);
            }

            else if(x == 'S'){

                while(!st.empty() && st.top() == 'R'){

                    cnt += 1;
                    st.pop();
                }

                st.push(x);
            }

            else{

                if(st.empty()) st.push(x);

                else if(st.top() == 'R'){

                    cnt += 2;
                    st.pop();

                    while(!st.empty() && st.top() == 'R'){

                        cnt += 1;
                        st.pop();
                    }

                    st.push('S');
                }

                else if(st.top() == 'S'){

                    cnt += 1;
                    st.push('S');
                }
            }
        }

        return cnt;
    }

};
