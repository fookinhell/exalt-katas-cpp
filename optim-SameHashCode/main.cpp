#include <iostream>
#include <map>
#include <string>


using namespace std;

int main()
{
    // using the Birthday Paradox :
    // storing the tested values in a map,
    // and wait for another value to have the same hashcode

    map<int, string> words; 

    int i = 0;
    string testString;

    while (true) 
    {
        i++;
        testString = to_string(i);
        auto hashedStr = hash<string>{}(testString);
        auto ret = words.insert(make_pair(hashedStr, testString));
        if (ret.second == false) {
            cout << words[hashedStr] << " and " << testString << " have the same hashcode : " << hashedStr;
            break;
        }
    }

    return 0;
}