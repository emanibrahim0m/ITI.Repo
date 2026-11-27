
// 9. Palindrome Number
/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
bool isPalindrome(int x) {
    // if num == 0 
    if (x == 0) return true;
    // if num is negative or end with 0
    if (x < 0 || x % 10 == 0) return false;

    // create rev (if x = 456321 then ref = 123)
    int rev = x % 10;
    x /= 10;

    // loop till rev >= x 
    while (rev <= x && rev != x)
    {
        //rev = rev + last num * 10 
        rev = (rev * 10) + (x % 10); 
        x /= 10;
    }
    // if rev == x or rev (rev = 258 and x = 25)
    if (rev == x || rev / 10 == x)
        return true;
    else return false;
}