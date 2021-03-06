#include "dekunobou.hpp"

void row_migi(vector<vector<int>>& row, int x, int y, int b, int basyo[65][2]) {
	int i;
    for (i = 2; i < 8 - y; i++) {
        if (row[x][y + i] == b && !basyo_search(basyo,x,y)) {
			basyo[0][0]++;
			basyo[basyo[0][0]][0]=x;
			basyo[basyo[0][0]][1]=y;
        	break;
        }else if(row[x][y+i]==0){
        	break;
        }
    }
};

void row_hidari(vector<vector<int>>& row, int x, int y, int b, int basyo[65][2]) {
    int i;
	for (i = 2; i < y+1; i++) {
        if (row[x][y - i] == b && !basyo_search(basyo,x,y)) {
        	basyo[0][0]++;
			basyo[basyo[0][0]][0]=x;
			basyo[basyo[0][0]][1]=y;
        	break;
        }else if(row[x][y-i]==0){
        	break;
        }
    }
};

void clm_ue(vector<vector<int>>& row, int x, int y, int b, int basyo[65][2]) {
    int i;
	for (i = 2; i < 8 - x; i++) {
        if (row[x+i][y] == b &&  !basyo_search(basyo,x,y)) {
        	basyo[0][0]++;
			basyo[basyo[0][0]][0]=x;
			basyo[basyo[0][0]][1]=y;
        	break;
        }else if(row[x+i][y]==0){
        	break;
        }
    }
};

void clm_sita(vector<vector<int>>& row, int x, int y, int b, int basyo[65][2]) {
	int i;
    for (i = 2; i < x+1; i++) {
        if (row[x-i][y] == b && !basyo_search(basyo,x,y)) {
        	basyo[0][0]++;
			basyo[basyo[0][0]][0]=x;
			basyo[basyo[0][0]][1]=y;
        	break;
        }else if(row[x-i][y]==0){
        	break;
        }
    }
};

void miginaname_ue(vector<vector<int>>& row, int x, int y, int b, int basyo[65][2]) {
	int i;
    for (i = 2; i < min(8-x,8-y); i++) {
        if (row[x+i][y+i] == b && !basyo_search(basyo,x,y)) {
        	basyo[0][0]++;
			basyo[basyo[0][0]][0]=x;
			basyo[basyo[0][0]][1]=y;
        	break;
        }else if(row[x+i][y+i]==0){
        	break;
        }
    }
};

void miginaname_sita(vector<vector<int>>& row, int x, int y, int b, int basyo[65][2]) {
    int i;
	for (i = 2; i < min(x+1,y+1); i++) {
        if (row[x-i][y-i] == b && !basyo_search(basyo,x,y)) {
        	basyo[0][0]++;
			basyo[basyo[0][0]][0]=x;
			basyo[basyo[0][0]][1]=y;
        	break;
        }else if(row[x-i][y-i]==0){
        	break;
        }
    }
};

void hidarinaname_ue(vector<vector<int>>& row,int x,int y,int b,int basyo[65][2]){
	int i;
	for(i=2;i<min(8-x,y+1);i++){
		if(row[x+i][y-i]==b && !basyo_search(basyo,x,y)) {
        	basyo[0][0]++;
			basyo[basyo[0][0]][0]=x;
			basyo[basyo[0][0]][1]=y;
			break;
		}else if(row[x+i][y-i]==0){
			break;
		}
	}
};

void hidarinaname_sita(vector<vector<int>>& row,int x,int y,int b,int basyo[65][2]){
	int i;
	for(i=2;i<min(x+1,8-y);i++){
		if(row[x-i][y+i]==b && !basyo_search(basyo,x,y)) {
        	basyo[0][0]++;
			basyo[basyo[0][0]][0]=x;
			basyo[basyo[0][0]][1]=y;
			break;
		}else if(row[x-i][y+i]==0){
			break;
		}
	}
};

void basyo_hyouji(int basyo[65][2]){
	int i;
	for(i=1;i<=basyo[0][0];i++){
		basyo[i][0]+=1;
		basyo[i][1]+=1;
	}
};

void basyo_print(int basyo[65][2]){
	int i;
	for(i=1;i<=basyo[0][0];i++){
		cout<<"["<<i<<"] "<<basyo[i][0]+1<<" "<<basyo[i][1]+1<<endl;
	}
};

void sagasu(vector<vector<int>>& row,int basyo[65][2], int soutesu, int sente) {
	int a, b, i, j, k;
	basyo[0][0]=0;
	if(soutesu%2==sente){
		a=-1;
		b=1;
	}else{
		a=1;
		b=-1;
	}

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){

			//行方向
			if(j<=6){
				if(row[i][j]==0 && row[i][j+1]==a){
					row_migi(row,i,j,b,basyo);
				}else if(row[i][j]==a && row[i][j+1]==0){
					row_hidari(row,i,j+1,b,basyo);
				}
			}

			//列方向
			if(i<=6){
				if(row[i][j]==0 && row[i+1][j]==a){
					clm_ue(row,i,j,b,basyo);
				}else if(row[i][j]==a && row[i+1][j]==0){
					clm_sita(row,i+1,j,b,basyo);
				}
			}

			//斜め方向
			for(k=0;k<7;k++){
				if(j<=6-k){
					//盤面下部
					//右斜め方向
					if(row[j+k][j]==0 && row[j+k+1][j+1]==a){
						miginaname_ue(row,j+k,j,b,basyo);
					}else if(row[j+k][j]==a && row[j+k+1][j+1]==0){
						miginaname_sita(row,j+k+1,j+1,b,basyo);
					}

					//左斜め方向
					if(row[j+k][7-j]==0 && row[j+k+1][7-(j+1)]==a){
						hidarinaname_ue(row,j+k,7-j,b,basyo);
					}else if(row[j+k][7-j]==a && row[j+k+1][7-(j+1)]==0){
						hidarinaname_sita(row,j+k+1,7-(j+1),b,basyo);
					}

					//盤面上部
					if(k!=0){
						//右斜め方向
						if(row[j][j+k]==0 && row[j+1][j+k+1]==a){
							miginaname_ue(row,j,j+k,b,basyo);
						}else if(row[j][j+k]==a && row[j+1][j+k+1]==0){
							miginaname_sita(row,j+1,j+k+1,b,basyo);
						}

						//左斜め方向
						if(row[j][7-(j+k)]==0 && row[j+1][7-(j+k+1)]==a){
							hidarinaname_ue(row,j,7-(j+k),b,basyo);
						}else if(row[j][7-(j+k)]==a && row[j+1][7-(j+k+1)]==0){
							hidarinaname_sita(row,j+1,7-(j+k+1),b,basyo);
						}
					}
				}
			}
		}
	}
};