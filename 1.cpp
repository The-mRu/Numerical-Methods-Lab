#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,ss="";
    int cnt=0;
    
    getline(cin, s);
    vector<int>v;
    
    for(int i=0; i<s.size();i++)
    {
        ss="";
        while( s[i]!=' ')
        {
            ss+=s[i];
            i++;
            if(i >= s.size() ) break;
        }
        int x = stoi(ss);
        v.push_back(x);
        cnt++;
    }
    cout<<"Total Number of int : "<<cnt<<endl;
    cout<<"Array : ";
    for (auto i : v)
    {
        cout << i << " "; 
    }
       
    return 0;
}
