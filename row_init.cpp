#include "dekunobou.hpp"
using namespace std;

vector<vector<int>> init(){
    vector<vector<int>> row(8,vector<int>(8));
    row[3][3]=-1;
    row[3][4]=1;
    row[4][3]=1;
    row[4][4]=-1;
    return row;
};