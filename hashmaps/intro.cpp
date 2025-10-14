#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // creation
    unordered_map<string, int> m;

    // 1st method
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // 2nd method
    pair<string, int> p2("love", 2);
    m.insert(p2);

    // 3rd method
    m["mera"] = 1;

    // print to confirm
    for (auto i : m) {
        cout << i.first << " : " << i.second << endl;
    }


    //searching
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;

   // cout<<m.at("unknown")<<endl;
     cout<<m["unknown"]<<endl;
     cout<<m.at("unknown")<<endl;

    // //check size
     cout<<m.size()<<endl;

    // //to check presence of key
    cout<<m.count("hello")<<endl;  //1 present nad 0 absent

    //erase
    m.erase("love");
    cout<<m.size()<<endl;

    for(auto i:m)
    {
       cout<<i.first << " " << i.second<<endl; 
    }

    //iterator
    unordered_map<string,int> :: iterator it= m.begin();

    while(it!=m.end())
    {
       cout<<it->first << " " << it->second<<endl;
       it++; 
    }

    return 0;
}
