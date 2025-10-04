// Ques Link - https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
public:

    priority_queue<int> leftSide; // sorted from 0 to x where 0 < x and x at top 
    priority_queue<int,vector<int>,greater<int>> rightSide; // sortef from x to n-1 where x < n-1

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(leftSide.empty() || num < leftSide.top()){

            leftSide.push(num);
        }

        else rightSide.push(num);

        if(leftSide.size() < rightSide.size()){ // rightSide should be <= size of leftside

            leftSide.push(rightSide.top());
            rightSide.pop();
        }

        else if((leftSide.size() - rightSide.size()) > 1){ // leftside can have 1 more element than rightside beacause of that odd size we can direct return lefttop
                                                            
            rightSide.push(leftSide.top());
            leftSide.pop();
        }
    }
    
    double findMedian() {
        
        int size = leftSide.size() + rightSide.size();

        if(size % 2 == 1) return (double) leftSide.top();

        return (double) (leftSide.top() + rightSide.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();

 */
