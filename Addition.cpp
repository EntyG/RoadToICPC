#include "header.h"

//string findSum(string str1, string str2) {
//    string str = "";
//
//    // Calculate length of both string 
//    int n1 = str1.length(), n2 = str2.length();
//
//    // Reverse both of strings 
//    reverse(str1.begin(), str1.end());
//    reverse(str2.begin(), str2.end());
//
//    int carry = 0;
//    for (int i = 0; i < n1; i++) {
//        if (str1[i]-'0' + str2[i]-'0' + carry < 10) {
//            str += to_string(str1[i] - '0' + str2[i] - '0' + carry);
//            carry = 0;
//        }
//        else {
//            str += to_string(str1[i] - '0' + str2[i] - '0' + carry - 10);
//            carry = 1;
//        }
//    }
//    if (carry) {
//        str += "1";
//    }
//    reverse(str.begin(), str.end());
//    return str;
//}
//
//bool isSmaller(string str1, string str2)
//{
//    // Calculate lengths of both string 
//    int n1 = str1.length(), n2 = str2.length();
//
//    if (n1 < n2)
//        return true;
//    if (n2 < n1)
//        return false;
//
//    for (int i = 0; i < n1; i++)
//        if (str1[i] < str2[i])
//            return true;
//        else if (str1[i] > str2[i])
//            return false;
//
//    return false;
//}
//
//// Function for find difference of larger numbers 
//string findDiff(string str1, string str2)
//{
//    // Before proceeding further, make sure str1 
//    // is not smaller 
//    if (isSmaller(str1, str2))
//        swap(str1, str2);
//
//    // Take an empty string for storing result 
//    string str = "";
//
//    // Calculate length of both string 
//    int n1 = str1.length(), n2 = str2.length();
//
//    // Reverse both of strings 
//    reverse(str1.begin(), str1.end());
//    reverse(str2.begin(), str2.end());
//
//    int carry = 0;
//
//    // Run loop till small string length 
//    // and subtract digit of str1 to str2 
//    for (int i = 0; i < n2; i++) {
//        // Do school mathematics, compute difference of 
//        // current digits 
//
//        int sub
//            = ((str1[i] - '0') - (str2[i] - '0') - carry);
//
//        // If subtraction is less than zero 
//        // we add then we add 10 into sub and 
//        // take carry as 1 for calculating next step 
//        if (sub < 0) {
//            sub = sub + 10;
//            carry = 1;
//        }
//        else
//            carry = 0;
//
//        str.push_back(sub + '0');
//    }
//
//    // subtract remaining digits of larger number 
//    for (int i = n2; i < n1; i++) {
//        int sub = ((str1[i] - '0') - carry);
//
//        // if the sub value is -ve, then make it positive 
//        if (sub < 0) {
//            sub = sub + 10;
//            carry = 1;
//        }
//        else
//            carry = 0;
//
//        str.push_back(sub + '0');
//    }
//
//    // reverse resultant string 
//    reverse(str.begin(), str.end());
//
//    return str;
//}
//
//void try2RemoveSomeLine(string& a, string& b, string& c, int& count) {
//    string different = findDiff(findSum(a, b), c);
//    bool stop = 1;
//    for (int i = different.length() - 1 ; i >= 0; i--) {
//        if (different[i] != '0') {
//            stop = 0;
//        }
//    }
//    if (stop) {
//        return;
//    }
//    for (int i = different.length() - 1; i >= 0; i--) {
//        if (different[i] != '0') {
//            a.erase(i, 1);
//            b.erase(i, 1);
//            c.erase(i, 1);
//            count++;
//        }
//    }
//    try2RemoveSomeLine(a, b, c, count);
//}