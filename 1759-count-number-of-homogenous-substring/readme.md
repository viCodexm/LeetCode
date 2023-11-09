Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.<br\ >

A string is homogenous if all the characters of the string are the same.<br\ >

A substring is a contiguous sequence of characters within a string.<br\ >
<br\ >
 <br\ >
<br\ >
Example 1:<br\ >
<br\ >
Input: s = "abbcccaa"<br\ >
Output: 13<br\ >
Explanation: The homogenous substrings are listed as below:<br\ >
"a"   appears 3 times.<br\ >
"aa"  appears 1 time.<br\ >
"b"   appears 2 times.<br\ >
"bb"  appears 1 time.<br\ >
"c"   appears 3 times.<br\ >
"cc"  appears 2 times.<br\ >
"ccc" appears 1 time.<br\ >
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.<br\ >
Example 2:<br\ >
<br\ >
Input: s = "xy"<br\ >
Output: 2<br\ >
Explanation: The homogenous substrings are "x" and "y".<br\ >
Example 3:<br\ >
<br\ >
Input: s = "zzzzz"<br\ >
Output: 15<br\ >
<br\ >
<br\ >
Constraints:<br\ >
<br\ >
1 <= s.length <= 105<br\ >
s consists of lowercase letters.<br\ >