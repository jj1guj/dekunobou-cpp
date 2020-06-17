#include "dekunobou.hpp"
int depth,node_all=0;
double elapsed_all=0;

int main(int argv,char **argc){
    //depthの設定
    if(argv==1){
        depth=10;
    }else{
        depth=atoi(argc[1]);
    }

	int teban,teban_first;
    vector<vector<int>> row;
	vector<int> kazu,utu;
	chrono::system_clock::time_point start,end;
	int sente=1;
	int gote=0;
	int soutesu=1;
	int change_kaisu=0;
    int basyo[65][2],basyosu,utu_in[2];
	char change_char;
	
	srand(time(NULL));
    row=row_init();
    //hyouji(row);
    change_kaisu=0;
    soutesu=1;

    cout<<"Input which turn you want to play\n";
    cout<<"If you want to play sente, input 1, gote, input 0\n";
    cin>>teban_first;

    teban=teban_first;
    row=row_init();

    while(soutesu<60){
        kazu=kazu_count(row);
        soutesu=kazu[0]+kazu[1]-3;
        if(soutesu==1){
            printf("1st\n");
        }else{
            printf("%d turn\n",soutesu);
        }
        printf("sente:%d vs %d:gote\n",kazu[0],kazu[1]);
        sagasu(row,basyo,soutesu,sente);
        //sort(basyo+1,basyo+basyo[0][0]+1);
        basyosu=basyo[0][0];
        if(soutesu%2==teban){
            //basyo=sagasu(row,soutesu,sente);
            hyouji_teban(row,basyo);
            //hyouji(row);
            if (basyosu==0){
                scanf("Because there's not place you can put, move to CPU's turn[Y/n]%c",&change_char);
                change_kaisu+=1;
                if(sente==1){
                    sente=0;
                    gote=1;
                }else{
                    sente=1;
                    gote=0;
                }
            }else{
                change_kaisu=0;
                row=nyuryoku(row,basyo,soutesu,sente,teban);
            }
            
            if(change_kaisu>=2){
                break;
            }
        }else{
            //basyo=sagasu(row,soutesu,sente);
            hyouji_teban(row,basyo);
            if(basyosu==0){
                change_kaisu+=1;
                if(sente==1){
                    sente=0;
                    gote=1;
                }else{
                    sente=1;
                    gote=0;
                }
            }else{
                change_kaisu=0;
                if(teban==sente){
                    utu=hantei(row,basyo,soutesu,sente,73,27);
                }else{
                    utu=hantei(row,basyo,soutesu,sente,100,10);
                }
                node_all+=node;
                cout<<"["<<utu[0]+1<<", "<<utu[1]+1<<"]\n";
                utu_in[0]=utu[0];
                utu_in[1]=utu[1];
                row=kaesi(row,utu_in,soutesu,sente);
            }
        }

        if(teban_first==1){
            teban=sente;
        }else{
            teban=gote;
        }

        if(change_kaisu>=2){
            break;
        }
    }
    hyouji(row);
    kazu=kazu_count(row);
    printf("\nsente:%d vs %d:gote\n",kazu[0],kazu[1]);
    if(kazu[0]>kazu[1]){
        printf("sente won\n");
    }else if(kazu[0]<kazu[1]){
        printf("gote won\n");
    }else{
        printf("draw\n");
    }
    cout<<"elapsed_all: "<<elapsed_all<<"[sec]"<<"\n";
    cout<<"node_all: "<<node_all<<"\n";
	return 0;
}