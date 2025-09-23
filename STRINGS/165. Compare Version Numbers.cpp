class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i = 0, j = 0, n = version1.size(), m = version2.size();

        while( i < n || j < m){

            string str1 = "0", str2 = "0";

            while( i < n && version1[i] != '.'){

                str1.push_back(version1[i]);
                i++;
            }

            while( j < m && version2[j] != '.'){

                str2.push_back(version2[j]);
                j++;
            }

            int num1 = stoi(str1);
            int num2 = stoi(str2);

            if(num1 < num2) return -1;
            else if(num1 > num2) return 1;

            i++;  j++;

        }

        return 0;
    }
};