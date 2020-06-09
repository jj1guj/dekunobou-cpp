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