#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
void finite_automaton_matcher(const string &text, const string &pattern, const vector<vector<int>> &transition_table)
{
   int n = text.length();
   int m    = pattern.length();
    int q = 0;


    for(int i=0;i<n;i++){
        
        char curr_char;
        int ci=-1;
        for(int j=0;j<m;j++){
            if(text[i] == pattern[j]){
                curr_char = text[i];
                ci = j;
                break;
            }
        }
        
        if(ci == -1){
            q = 0;
            continue;
        }
       else{
        q = transition_table[q][ci];
       }


        if(q == m){
            cout<<"pattern found at shift: "<<i-m+1<<"\n";
        }
    }
}

int main()
{
    // int s, n;
    // cout << "Enter no of states and no of unique char in string" << endl;
    // cin >> s >> n;
    // string text, pattern;
    // // cout << "Enter text: " << endl;
    // getline(cin >> ws, text);
    // // cout << "Enter pattern: " << endl;
    // getline(cin >> ws, pattern);

    // vector<vector<int>> mat(s, vector<int>(n));
    // for (int i = 0; i < s; i++)
    //     for (int j = 0; j < n; j++)
    //         cin >> mat[i][j];
    // finite_automaton_matcher(text, pattern, mat);

    int s,n;
    cin>>s>>n;

    string text,pattern;

    cin>>text>>pattern;

    vvi automaton(s,vi(n));

    for(int i=0;i<s;i++){
        for(int j=0;j<n;j++){
            cin>>automaton[i][j];
        }
    }

    finite_automaton_matcher(text,pattern,automaton);
}