#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class solution
{
  public:
    string removeDuplicateLetters(const string & str) {
        map<char, vector<size_t>> my_map;
        for (size_t i = 0; i < str.size(); ++i) {
            if (my_map.find(str[i]) == my_map.end())
                my_map[str[i]] = {i};
            else
                my_map[str[i]].push_back(i);
        }

        // for (auto it = my_map.begin(); it != my_map.end(); ++it) {
        //     cout << it->first << ": ";
        //     for (auto i : it->second)
        //         cout << i << " ";
        //     cout << endl;
        // }

        auto it = my_map.begin();
        auto prev = it;
        it->second.resize(1);
        ++it;
        while (it != my_map.end()) {
            auto jt = lower_bound(it->second.begin(), it->second.end(), prev->second.back());
            if (jt != it->second.end()) {
                size_t tmp = *jt;
                it->second.clear();
                it->second.push_back(tmp);
            }
            else
                it->second.resize(1);
            prev = it;
            ++it;
        }

        map<size_t, char> sorted;
        for (auto it = my_map.begin(); it != my_map.end(); ++it) {
            sorted[it->second.back()] = it->first;
            // cout << it->first << ": ";
            // for (auto i : it->second)
            //     cout << i << " ";
            // cout << endl;
        }

        string rtn;
        for (auto it = sorted.begin(); it != sorted.end(); ++it)
            rtn.append(1, it->second);

        return rtn;
    }
    
};

int main() {
    string strWithDups{"bcabc"};
    // string strWithDups{"cbacdcbc"};
    solution soln;
    string strWithoutDups = soln.removeDuplicateLetters(strWithDups);

    cout << "String without duplicate letters is:\n" << strWithoutDups << endl;

    return 0;
}
