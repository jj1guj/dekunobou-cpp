#include "dekunobou.hpp"

bool search_vector(vector<vector<int>> list, vector<int> element){
	int i;
	bool contain=false;
	for(i=0;i<(int)list.size();i++){
		if(list[i]==element){
			contain=true;
			break;
		}
	}
	return contain;
};

bool search_zahyou(vector<vector<int>> list,int x,int y){
	int i;
	bool contain=false;
	for(i=0;i<(int)list.size();i++){
		if(list[i][0]==x && list[i][1]==y){
			contain=true;
			break;
		}
	}
	return contain;
};

bool basyo_search(int L[65][2],int x,int y){
	int i;
	for(i=1;i<=L[0][0];i++){
		if(L[i][0]==x&&L[i][1]==y){
			return true;
		}
	}
	return false;
}

bool compare(vector<int>a,vector<int>b){
    return a==b;
}

bool search_element(vector<int> list,int element){
	int i;
	bool contain=false;
	for(i=0;i<(int)list.size();i++){
		if(list[i]==element){
			contain=true;
			break;
		}
	}
	return contain;
};

vector<vector<int>> append(vector<vector<int>> list){
	vector<int> a={1,0};
	list.push_back(a);
	return list;
};