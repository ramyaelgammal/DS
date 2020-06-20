/*
 * Input: N rows of seats ABC DEFG HJK
 * Ex     1A 1F 1C, N=1
 *        ABC DEFG HJK
 *        #0# 00#0 000
 * Res:   0 4-seating-groups
 * 
 * Ex     1A 2F 1C, N=2
 *        ABC DEFG HJK
 *        #0# 0000 000
 *        ABC DEFG HJK
 *        000 00#0 000*        
 * Res:   2 4-seating-groups
 *        DEFG in 1st
 *        BCDE in 2nd 
 */

#include <bits/stdc++.h> 
#include <algorithm>

using namespace std;
int solution(int N, string &S) {
    int seatGrp = 0;
    stringstream ss(S);
    vector<string> rsrvd;
    string temp;
    int i = 0;
    while(ss >> temp)
    {
        rsrvd.push_back(temp);
       i++;
    }
    cout << endl;
    vector<char> v[N]; // each element represent one row
    

    for (i=0; i<N; i++)
    {
        for(char c = 'B'; c <= 'I'; c++) v[i].push_back(c);
    }

    for(i=0; i<rsrvd.size(); i++)
    {
        stringstream ss2(rsrvd[i]);
        map<char, bool> m;
        int no;
        char  c;
        if (ss2 >> no)
        {
           ss2 >> c;
           if(c == 'A' || c == 'K') continue;
           if(c=='J') c='I'; // to maintain pattern of each letter > prev letter by 1
           if(no <= N && no != 0)
           {
               // remove this from the vector repr. the row seats
               v[no-1].erase(remove(v[no-1].begin(), v[no-1].end(), c), v[no-1].end());
           }
        }
    }
    // [Debug only]
    for (i=0; i< N; i++)
    {
        for(int j=0; j<v[i].size(); j++) cout << v[i][j]<< " ";
        cout << endl;
    }
    
    // Display the new input reformatting (rearrangement)
    int seats = 0; // should be 3 to add 1 to seatGrp
     
    for (i=0; i< N; i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            if(v[i][j+1]-v[i][j] == 1){
                seats++;
                if(seats == 3) // 3 because there are 3 spaces between 4 seats
                {
                     seatGrp++;
                     seats = 0;
                }
            }
            else
            {
                seats = 0;
            }
        }
    }
    

    return seatGrp;
}

};
int main(){
    string s ("1A 2F 1C");
    cout<< "Num of seats " << solution(2,s)<<endl;
    
    string s1 ("");
    cout<< "Num of seats " << solution(2,s1)<<endl;
   
    string s2 ("1C 2C 1F 2F");
    cout<< "Num of seats " << solution(2,s2)<<endl;

    return 0;
}

