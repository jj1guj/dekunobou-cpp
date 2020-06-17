#include "dekunobou.hpp"

vector<vector<int>> row_init(){
    vector<vector<int>> row(8,vector<int>(8));
    row[3][3]=-1;
    row[3][4]=1;
    row[4][3]=1;
    row[4][4]=-1;
    return row;
};

vector<vector<int>> nyuryoku(vector<vector<int>> row,
int basyo[65][2],int soutesu,int sente,int teban){
	int basyosu=basyo[0][0];
	int basyo_utu;
	basyo_print(basyo);

	
	printf("Input number where you want to put: ");
	cin>>basyo_utu;

	while(basyo_utu==0 || basyo_utu>basyosu){
		printf("You CAN'T put here\n");
		printf("Input number where you want to put again: ");
		cin>>basyo_utu;
	}
	row=kaesi(row,basyo[basyo_utu],soutesu,sente);
	return row;
};

void hyouji(vector<vector<int>>& row){
    int i,j;

    for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(row[i][j]==0){
				printf("* ");
			}else if(row[i][j]==1){	
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("\n");
    }
    printf("\n");
}

void hyouji_teban(vector<vector<int>>& row,int basyo[65][2]){
    int i,j,k;
    int basyosu=basyo[0][0];
    int flg;

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
			flg=-1;
			for(k=1;k<=basyosu;k++){
				if(basyo[k][0]==i&&basyo[k][1]==j){
					flg=k;
					break;
				}
			}
            if(flg!=-1){
				printf("%02d",flg);
            }else if(row[i][j]==0){
                printf("* ");
            }else if(row[i][j]==1){
                printf("●");
            }else{
                printf("○");
            }
        }
		printf("\n");
    }

    printf("\n");
};

vector<vector<int>> kaesi(vector<vector<int>> row,int basyo[2],int soutesu,int sente){
    int a,i,j;
	int i_gyou_migi=10;
	int i_gyou_hidari=10;
	int i_retu_ue=10;
	int i_retu_sita=10;
	int i_miginaname_ue=10;
	int i_miginaname_sita=10;
	int i_hidarinaname_ue=10;
	int i_hidarinaname_sita=10;
	int gyou=basyo[0];
	int retu=basyo[1];

	if(soutesu%2==sente){
		a=1;
	}else{
		a=-1;
	}
    row[gyou][retu]=a;

    for(i=1;i<8;i++){
        if(i<8-retu && i<i_gyou_migi){
			if(row[gyou][retu+i]==a){
				for(j=0;j<i;j++){
					row[gyou][retu+j]=a;
				}
				i_gyou_migi=i;
			}else if(row[gyou][retu+i]==0){
				i_gyou_migi=i;
			}
		}

        if(i<retu+1 && i<i_gyou_hidari){
			if(row[gyou][retu-i]==a){
				for(j=0;j<i;j++){
					row[gyou][retu-j]=a;
				}
				i_gyou_hidari=i;
			}else if(row[gyou][retu-i]==0){
				i_gyou_hidari=i;
			}
		}

        if(i<8-gyou && i<i_retu_ue){
			if(row[gyou+i][retu]==a){
				for(j=0;j<i;j++){
					row[gyou+j][retu]=a;
				}
				i_retu_ue=i;
			}else if(row[gyou+i][retu]==0){
				i_retu_ue=i;
			}
		}

        if(i<gyou+1 && i<i_retu_sita){
			if(row[gyou-i][retu]==a){
				for(j=0;j<i;j++){
					row[gyou-j][retu]=a;
				}
				i_retu_sita=i;
			}else if(row[gyou-i][retu]==0){
				i_retu_sita=i;
			}
		}

        if(i<min(8-gyou,8-retu) && i<i_miginaname_ue){
			if(row[gyou+i][retu+i]==a){
				for(j=0;j<i;j++){
					row[gyou+j][retu+j]=a;
				}
				i_miginaname_ue=i;
			}else if(row[gyou+i][retu+i]==0){
				i_miginaname_ue=i;
			}
		}

        if(i<min(gyou+1,retu+1) && i<i_miginaname_sita){
			if(row[gyou-i][retu-i]==a){
				for(j=0;j<i;j++){
					row[gyou-j][retu-j]=a;
				}
				i_miginaname_sita=i;
			}else if(row[gyou-i][retu-i]==0){
				i_miginaname_sita=i;
			}
		}

        if(i<min(8-gyou,retu+1) && i<i_hidarinaname_ue){
			if(row[gyou+i][retu-i]==a){
				for(j=0;j<i;j++){
					row[gyou+j][retu-j]=a;
				}
				i_hidarinaname_ue=i;
			}else if(row[gyou+i][retu-i]==0){
				i_hidarinaname_ue=i;
			}
		}

        if(i<min(gyou+1,8-retu) && i<i_hidarinaname_sita){
			if(row[gyou-i][retu+i]==a){
				for(j=0;j<i;j++){
					row[gyou-j][retu+j]=a;
				}
				i_hidarinaname_sita=i;
			}else if(row[gyou-i][retu+i]==0){
				i_hidarinaname_sita=i;
			}
		}
    }

    return row;
};

vector<int> kazu_count(vector<vector<int>>& row){
    int i;
    vector<int> kazu(2);

    for(i=0;i<8;i++){
        kazu[0]+=count(row[i].begin(),row[i].end(),1);
        kazu[1]+=count(row[i].begin(),row[i].end(),-1);
    }
    return kazu;
};