// class ProductOfNumbers {
// public:

//     // First Appraoch
//     stack<int>st;

//     ProductOfNumbers() {
       
//     }
    
//     void add(int num) {
        
//         st.push(num);
//     }
    
//     int getProduct(int k) {
        
//         int prod = 1;

//         stack<int> temp;

//         while(!st.empty() && k--){

//             prod *= st.top();
//             temp.push(st.top());
//             st.pop();

//         }

//         while(!temp.empty()){

//            st.push(temp.top());
//            temp.pop();
//         }

//         return prod;
//     }
// };

                           // second Appraoch


// class ProductOfNumbers {
// public:

//     vector<int> nums;

//     ProductOfNumbers() {
        
//     }
    
//     void add(int num) {

//         nums.push_back(num);
//     }
    
//     int getProduct(int k) {

//        int n = nums.size();

//        int ans = 1;

//        for(int i=n-1; i>=n-k; i--){

//             ans *= nums[i];
//        }

//        return ans; 
//     }
// };

                    // Third Appraoch using prefix sum

class ProductOfNumbers {
public:

    vector<int> nums;

    ProductOfNumbers() {
        nums = {1};
    }
    
    void add(int num) {

        if(num == 0){

            nums = {1};
        }
        
       else{

         nums.push_back(nums.back() * num);
       } 
    }
    
    int getProduct(int k) {
        
        int n = nums.size();

        if( k >= n) return 0;

        return nums[n-1] / nums[n-k-1];

    }
};                   

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */