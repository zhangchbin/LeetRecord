/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while(l <= r){
            int mid = (0LL + l+r) / 2;
            if(guess(mid) < 0) r = mid-1;
            else if(guess(mid) > 0) l = mid+1;
            else return mid;
        }
        return 0;
    }
};
