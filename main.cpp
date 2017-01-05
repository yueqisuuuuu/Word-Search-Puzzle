#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>

using namespace std;

void horizontal(const vector<vector<char> > & v, const unordered_set<string> & d){
    int row_size=v[0].size();
    int col_size=v.size();
    for (int length=6; length<=row_size;length++){
    for (int col=0; col<col_size; col++){
        for(int row=0; row<row_size; row++){
            if(row+length<=row_size){
            string word;
            for(int k=0; k<length; k++){
                word+=v[col][row+k];}
            if(d.find(word)!=d.end())
                cout<<word << " from (" <<col<<", "<<row<<") to (" << col << ", "<<row+length-1 <<")"<<endl;
            }
        }
    }}
    }

void reverse_horizontal(const vector<vector<char> > & v, const unordered_set<string> & d){
    int row_size=v[0].size();
    int col_size=v.size();
    for (int length=6; length<=row_size;length++){
    for (int col=0; col<col_size; col++){
        for(int row=row_size-1; row>=0; row--){
            if(row-length>=-1){
            string word;
            for(int k=0; k<length; k++){
                word+=v[col][row-k];}
            if(d.find(word)!=d.end())
                cout<<word << " from (" <<col<<", "<<row<<") to (" << col << ", "<<row-length+1 <<")"<<endl;
            }
        }
    }}
    }

void vertical(const vector<vector<char> > & v, const unordered_set<string> & d){
    int row_size=v[0].size();
    int col_size=v.size();
    for (int length=6; length<=col_size;length++){
    for (int row=0; row<row_size; row++){
        for(int col=0; col<col_size; col++){
            if(col+length<=col_size){
            string word;
            for(int k=0; k<length; k++){
                word+=v[col+k][row];}
            if(d.find(word)!=d.end())
                cout<<word << " from (" <<col<<", "<<row<<") to (" << col+length-1 << ", "<<row<<")"<<endl;
            }
        }
    }}
    }

void reverse_vertical(const vector<vector<char> > & v, const unordered_set<string> & d){
    int row_size=v[0].size();
    int col_size=v.size();
    for (int length=6; length<=col_size;length++){
    for (int row=0; row<row_size; row++){
        for(int col=col_size-1; col>=0; col--){
            if(col-length>=-1){
            string word;
            for(int k=0; k<length; k++){
                word+=v[col-k][row];}
            if(d.find(word)!=d.end())
                cout<<word << " from (" <<col<<", "<<row<<") to (" << col-length+1 << ", "<<row<<")"<<endl;
            }
        }
    }}
    }

void left_diagonal(const vector<vector<char> > & v, const unordered_set<string> & d){
    int row_size=v[0].size();
    int col_size=v.size();
    for (int length=6; length<=col_size;length++){
    for (int row=0; row<row_size; row++){
        for(int col=0; col<col_size; col++){
            if(col+length<=col_size && row+length<=row_size){
            string word;
            for(int k=0; k<length; k++){
                word+=v[col+k][row+k];}
            if(d.find(word)!=d.end())
                cout<<word << " from (" <<col<<", "<<row<<") to (" << col+length-1 << ", "<<row+length-1<<")"<<endl;
            }
        }
    }}
    }

void reverse_left_diagonal(const vector<vector<char> > & v, const unordered_set<string> & d){
    int row_size=v[0].size();
    int col_size=v.size();
    for (int length=6; length<=col_size;length++){
    for(int row=row_size-1; row>=0; row--){
        for(int col=col_size-1; col>=0; col--){
            if(col-length>=-1 && row-length>=-1){
            string word;
            for(int k=0; k<length; k++){
                word+=v[col-k][row-k];}
            if(d.find(word)!=d.end())
                cout<<word << " from (" <<col<<", "<<row<<") to (" << col-length+1 << ", "<<row-length+1<<")"<<endl;
            }
        }
    }}
    }

void right_diagonal(const vector<vector<char> > & v, const unordered_set<string> & d){
    int row_size=v[0].size();
    int col_size=v.size();
    for (int length=6; length<=col_size;length++){
    for(int row=row_size-1; row>=0; row--){
        for(int col=0; col<col_size; col++){
            if(col+length<=col_size && row-length>=-1){
            string word;
            for(int k=0; k<length; k++){
                word+=v[col+k][row-k];}
            if(d.find(word)!=d.end())
                cout<<word << " from (" <<col<<", "<<row<<") to (" << col+length-1 << ", "<<row-length+1<<")"<<endl;
            }
        }
    }}
    }

void reverse_right_diagonal(const vector<vector<char> > & v, const unordered_set<string> & d){
    int row_size=v[0].size();
    int col_size=v.size();
    for (int length=6; length<=col_size;length++){
    for(int row=0; row<row_size; row++){
        for(int col=col_size-1; col>=0; col--){
            if(row+length<=row_size && col-length>=-1){
            string word;
            for(int k=0; k<length; k++){
                word+=v[col-k][row+k];}
            if(d.find(word)!=d.end())
                cout<<word << " from (" <<col<<", "<<row<<") to (" << col-length+1 << ", "<<row+length-1<<")"<<endl;
            }
        }
    }}
    }


void word_search(const vector<vector<char> > & v, const unordered_set<string> & d){
    horizontal(v,d);
    reverse_horizontal(v,d);
    vertical(v,d);
    reverse_vertical(v,d);
    left_diagonal(v,d);
    reverse_left_diagonal(v,d);
    right_diagonal(v,d);
    reverse_right_diagonal(v,d);
}

int main()
{
    vector<vector<char> > v;
    ifstream pz("/Users/yueqisu/Dropbox/SCU/2016-17/FALL 16/CSCI 61/HW/HW4/puzzle.txt");
    if (pz.fail()){
        cout<<"Can't open puzzle!"<<endl;
        exit(1);
    }

    string s;
    while (getline(pz, s)){
        vector<char> v1;
        for(int i = 0; i < s.size(); ++i)
            if(s[i]!=' '){
                v1.push_back(s[i]);}

        v.push_back(v1);
    }
    pz.close();

    unordered_set<string> dictionary;
    ifstream ds("/Users/yueqisu/Dropbox/SCU/2016-17/FALL 16/CSCI 61/HW/HW4/words.txt");
    if (ds.fail()){
        cout<<"Can't open dictionary!"<<endl;
        exit(1);
    }

   string s2;
   while (ds>>s2)
       dictionary.insert(s2);

    ds.close();



    word_search(v, dictionary);

    return 0;
}
