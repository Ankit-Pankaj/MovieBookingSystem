#include<bits/stdc++.h>

using namespace std;

#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")

#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"

#define pow2(x) ((x)*(x))
#define ll long long
#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front

#define mod 1000000007
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)

#define mp make_pair
#define ff first
#define ss second
#define null NULL

#define all(c) (c).begin(),(c).end()
#define nl "\n"

typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;

//{ Movie Ticket Reservation system }
// Use print seats function to get the idea of seats.

/*
9
add-screen Screen1 12 10 4 5 8 9
add-screen Screen2 20 25 3 4 12 13 17 18
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen2 13 4 5 6
get-unreserved-seats Screen2 13
suggest-contiguous-seats Screen1 3 3 4
suggest-contiguous-seats Screen2 4 12 4
suggest-contiguous-seats Screen2 4 10 3
*/

class screen {
    vector<vector<int>>seats;
public:
    screen(vector<int> &v)
//          : seats(v[0] + 1, vector<int>(v[1] + 1, 1))  We can use this function also.
    {
        seats.resize(v[0]+1,vector<int>(v[1]+1,1));

        // 1 means empty seats and 2 means occupied seats
        // -1 means empty aisle seats and similarly for -2
        for (int i = 2; i < v.size(); i++)
        {
            for (int j = 1; j < seats.size(); j++)
            {
                seats[j][v[i]] *= -1;
            }
        }
        cout << "success" << endl;
    }
    bool check_seat(vector<int>&v) // function to check if seats are available or not
    {

        int row=v[0];
        for(int i=1;i<v.size();i++)
        {
            if(abs(seats[row][v[i]])==2){return false;}
        }
        return true;
    }
    void print_seats()      // function to get live status of seats at any time. Will return the seats in form of 2D-array
    {
        for(int i=1;i<seats.size();i++,cout<<endl)
        {
            for(int j=1;j<seats[0].size();j++)
            {
                cout<<seats[i][j]<<" ";
            }
        }
    }
    void get_unreserved(int row)    // To get the status of all the unreserved seats
    {
//        print_seats();
        for(int i=1;i<seats[row].size();i++)
        {
            if(seats[row][i]==1||seats[row][i]==-1){cout<<i<<" ";}
        }
        cout<<endl;
    }
    void reserve(vector<int>&v) // function to reserve a seat if available
    {
//        print_seats();
        int row=v[0];
        if(check_seat(v))
        {
            for(int i=1;i<v.size();i++)
            {
                if(seats[row][v[i]]>0){ seats[row][v[i]] =2; }
                else{seats[row][v[i]]=-2;}
            }
            cout<<"success"<<endl;
//            print_seats();
        }
        else{cout<<"failure"<<endl;}
    }
    bool suggest_util(int left,int right,int row)   // utility function for suggestion
    {
        if(right>=seats[row].size()||left<1){return 0;}
        for(int i=left;i<=right;i++)
        {
            if(seats[row][i]==2||seats[row][i]==-2){return false;}
        }
        for(int i=left;i<right;i++)
        {
            if(seats[row][i]==-1&&seats[row][i+1]==-1){return false;}
        }
        return true;
    }
    void suggest_contigious(int n,int row,int index)  // function to suggest seats based on user preference
    {
//        print_seats();
        if(suggest_util(index,index+n-1,row)==1)
        {
            for(int i=index;i<=min(index+n,(int)seats[row].size())-1;i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
        if(suggest_util(index-n+1,index,row)==1)
        {
            for(int i=max(1,index-n+1);i<=index;i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
        cout<<"none"<<endl;
        return;
    }
};

vector<string> to_words(string s) {
    string temp = "";
    vector<string> res;
    int i = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            res.push_back(temp);
            temp = "";
        }
        else
        { temp += s[i]; }
    }
    res.push_back(temp);
    return res;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string input;
    getline(cin, input);
    int t = stoi(input);
    unordered_map<string, screen* > m;
    while (t--)
    {
        getline(cin, input);
        vector<string> query;
        query = to_words(input);

        if (query[0] == "add-screen")
        {
            vector<int> v;
            for (int i = 2; i < query.size(); i++)
            {
                v.pb(stoi(query[i]));
            }
            m[query[1]] = new screen(v);
        } else if (query[0] == "reserve-seat")
        {
            vector<int> v;
            for (int i = 2; i < query.size(); i++)
            {
                v.pb(stoi(query[i]));
            }
            m[query[1]]->reserve(v);

        } else if (query[0] == "get-unreserved-seats")
        {
            m[query[1]]->get_unreserved(stoi(query[2]));

        } else if (query[0] == "suggest-contiguous-seats")
        {
            m[query[1]]->suggest_contigious(stoi(query[2]),stoi(query[3]),stoi(query[4]));
        }

    }
    return 0;
}
