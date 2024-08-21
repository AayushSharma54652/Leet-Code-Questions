class Solution {
public:
string gcdOfStrings(string str1, string str2) {
    // Check if str1 + str2 == str2 + str1
    if (str1 + str2 == str2 + str1) {
        // Return the substring of length gcd(str1.length(), str2.length())
        return str1.substr(0, __gcd(str1.length(), str2.length()));
    } else {
        return "";
    }
}
};