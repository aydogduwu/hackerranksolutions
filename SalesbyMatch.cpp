#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, vector<int> ar) {
    int ret = 0;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int temp = 1;
        if(find(vec.begin(), vec.end(), ar[i]) == vec.end()){
            for (int j = 0; j < n; ++j) {
                if(i != j && ar[i] == ar[j]){
                    temp++;
                }
            }
        }

        vec.push_back(ar[i]);
        ret += temp/2;
    }
    return ret;
}

int main()
{
    vector<int> v = {10,20,20,10,10,30,50,10,20};
    int n = 9;
    int ret = sockMerchant(n,v);
    cout << ret << endl;

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
