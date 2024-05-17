#include <iostream>
#include <string>
#include <algorithm>
#include<vector>

using namespace std;

string findSum(string str1, string str2) {
    string str = "";

    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings 
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++) {
        if (str1[i] - '0' + str2[i] - '0' + carry < 10) {
            str += to_string(str1[i] - '0' + str2[i] - '0' + carry);
            carry = 0;
        }
        else {
            str += to_string(str1[i] - '0' + str2[i] - '0' + carry - 10);
            carry = 1;
        }
    }
    if (carry) {
        str += '1';
    }
    reverse(str.begin(), str.end());
    return str;
}

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}

// Function for find difference of larger numbers 
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result 
    string str = "";

    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings 
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of 
        // current digits 

        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);

        // If subtraction is less than zero 
        // we add then we add 10 into sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number 
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);

        // if the sub value is -ve, then make it positive 
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // reverse resultant string 
    reverse(str.begin(), str.end());

    return str;
}
//
//void try2RemoveSomeLine(string& a, string& b, string& c, int& count) {
//    string sum = findSum(a, b);
//    string different = findDiff(sum, c);
//    vector<int> num;
//    /*bool stop = 1;
//    for (int i = different.length() - 1; i >= 0; i--) {
//        if (different[i] != '0') {
//            stop = 0;
//            break;
//        }
//    }
//    if (stop) {
//        return;
//    }*/
//    for (int i = different.length() - 1; i >= 0; i--) {
//        if (different[i] != '0') {
//            num.push_back(i);
//            count++;
//        }
//    }
//    if (num.size() == 0&&num.size()==different.size()) return;
//    for (int i = 0; i < num.size(); i++) {
//        a.erase(num[i], 1);
//        b.erase(num[i], 1);
//        c.erase(num[i], 1);
//    }
//    try2RemoveSomeLine(a, b, c, count);
//}
void try2RemoveSomeLine(string& a, string& b, string& c, int& count) {
    // Calculate sum and difference outside the loop
    string sum = findSum(a, b);
    string different = findDiff(sum, c);
    bool stop = 1;
    for (int i = different.length() - 1; i >= 0; i--) {
                if (different[i] != '0') {
                    stop = 0;
                    break;
                }
            }
            if (stop) {
                return;
            }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    reverse(different.begin(), different.end());

    // Find the position of the last non-zero digit
    int i = 0;
    while (i <different.size()-1 && different[i] == '0') {
        i++;
        ++count; // Increment count for each removed zero
    }

    // Erase trailing zeros
    if (i >= 0) {
        a.erase(a.begin() + i + 1, a.end());
        b.erase(b.begin() + i + 1, b.end());
        c.erase(c.begin() + i + 1, c.end());
    }

    // Reverse the strings back
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    try2RemoveSomeLine(a, b, c, count);
}



//void try2RemoveSomeLine(string& a, string& b, string& c, int& count) {
//    string sum = findSum(a, b);
//    string different = findDiff(sum, c);
//    for (int i = different.length() - 1; i >= 0; i--) {
//        if (different[i] != '0') {
//            a.erase(i, 1);
//            b.erase(i, 1);
//            c.erase(i, 1);
//            count++;
//            sum = findSum(a, b);
//            different = findDiff(sum, c);
//            if (i == 0) {
//                i++;
//            }
//
//        }
//    }
//}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string output = "";
    int n;
    string a, b, c;
    cin >> n;
    while (n) {
        cin.ignore();
        getline(cin, a);
        getline(cin, b);
        getline(cin, c);
        int count = 0;
        try2RemoveSomeLine(a, b, c, count);
        output += to_string(count) + "\n";
        cin >> n;
    }
    output.erase(output.size() - 1, 1);
    cout << output;
    return 0;
}
