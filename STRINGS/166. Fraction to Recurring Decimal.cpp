class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if(numerator == 0) return "0";

        string result = "";

        if((long long) numerator * (long long)denominator < 0) result += '-';

        long long absNum = labs(numerator);
        long long absDeno = labs(denominator);

        long long integerDiv = absNum / absDeno;

        result += to_string(integerDiv);

        long long remain = absNum % absDeno;

        if(remain == 0) return result;

        result += '.';

        unordered_map<int,int> mpp;

        while(remain){

            if(mpp.find(remain) != mpp.end()){

                result.insert(mpp[remain], "(");
                result += ')';
                break;
            }

            mpp[remain] = result.length();

            remain *= 10;
            int digit = remain / absDeno;

            result += to_string(digit);

            remain = remain % absDeno;
        }

        return result;
    }
};