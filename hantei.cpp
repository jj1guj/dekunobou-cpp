#include "dekunobou.hpp"

int node;
vector<int>hantei1;
vector<vector<int>>stone{{1,-1},{-1,1}};
vector<vector<int>>out_indx{{0,1},{1,0}};
vector<vector<vector<int>>>r_diff{{{0,1},{1,1},{1,0}},
                                    {{0,-1},{1,-1},{1,0}},
                                    {{0,1},{-1,1},{-1,0}},
                                    {{0,-1},{-1,-1},{-1,0}}};
vector<vector<int>>corner{{0,0},{0,7},{7,0},{7,7}};
vector<int>side_pattern(3);


vector<int>set_param(int soutesu,int sente){
    //{jibun,aite,a,b}
    vector<int>out(4);
    if(soutesu%2==sente)out={1,2,0,1};
    if(soutesu%2!=sente)out={2,1,1,0};
    return out;
}

int getmax(vector<int>&A,int pn){
	int i,out;
	out=A[0];
	for(i=0;i<pn;i++)out=max(out,A[i]);
    return out;
}

vector<int>val_board(vector<vector<int>>row,int add1,int add2){
    int i,j,k;
    vector<int>out=kazu_count(row);
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            //盤面の辺の形をとってくる
            side_pattern={row[corner[i][0]][corner[i][1]],row[corner[i][0]+r_diff[i][j][0]][corner[i][1]+r_diff[i][j][1]],row[corner[i][0]+2*r_diff[i][j][0]][corner[i][1]+2*r_diff[i][j][1]]};
            /*cout<<out[0]<<" "<<out[1]<<" ";
            cout<<side_pattern[0]<<" "<<side_pattern[1]<<" "<<side_pattern[2]<<" ";*/
            //先手と後手でそれぞれ判定
            for(k=0;k<2;k++){
                if(compare(side_pattern,{0,0,stone[k][0]})){
                    out[out_indx[k][0]]+=add2;
                    out[out_indx[k][1]]-=add2;
                }else if(compare(side_pattern,{0,stone[k][0],0})){
                    out[out_indx[k][0]]-=add2;
                    out[out_indx[k][1]]+=add2;
                }else if(compare(side_pattern,{0,stone[k][0],stone[k][0]})){
                    out[out_indx[k][0]]-=2*add2;
                    out[out_indx[k][1]]+=2*add2;
                }else if(compare(side_pattern,{0,stone[k][0],stone[k][1]})){
                    out[out_indx[k][0]]-=2*add2;
                    out[out_indx[k][1]]+=2*add2;
                }else if(compare(side_pattern,{stone[k][0],0,0})){
                    out[out_indx[k][0]]+=add1;
                    out[out_indx[k][1]]-=add1;
                }else if(compare(side_pattern,{stone[k][0],0,stone[k][0]})){
                    out[out_indx[k][0]]+=add1-add2;
                    out[out_indx[k][1]]-=add1-add2;
                }else if(compare(side_pattern,{stone[k][0],0,stone[k][1]})){
                    out[out_indx[k][0]]+=add1-add2;
                    out[out_indx[k][1]]-=add1-add2;
                }else if(compare(side_pattern,{stone[k][0],stone[k][0],0})){
                    out[out_indx[k][0]]+=add1+add2;
                    out[out_indx[k][1]]-=add1+add2;
                }else if(compare(side_pattern,{stone[k][0],stone[k][0],stone[k][0]})){
                    out[out_indx[k][0]]+=add1+2*add2;
                    out[out_indx[k][1]]-=add1+2*add2;
                }else if(compare(side_pattern,{stone[k][0],stone[k][0],stone[k][1]})){
                    out[out_indx[k][0]]+=add1+add2;
                    out[out_indx[k][1]]-=add1+add2;
                }else if(compare(side_pattern,{stone[k][0],stone[k][1],0})){
                    out[out_indx[k][0]]+=add1+add2;
                    out[out_indx[k][1]]-=add1+add2;
                }else if(compare(side_pattern,{stone[k][0],stone[k][1],stone[k][0]})){
                    out[out_indx[k][0]]+=add1-add2;
                    out[out_indx[k][1]]+=add2;
                }else if(compare(side_pattern,{stone[k][0],stone[k][1],stone[k][1]})){
                    out[out_indx[k][0]]+=add1+add2;
                    out[out_indx[k][1]]-=add1+add2;
                }
            }
            //cout<<out[0]<<" "<<out[1]<<"\n";
        }
    }
    return out;
}

void bfs(vector<vector<int>> row,int soutesu,int sente,int pn,int key,int depth,int add1,int add2){
    if(depth>=0 && soutesu<60 && (pn==0||(pn>=1 && hantei1[pn]>=getmax(hantei1,pn-1)))){
        int i;
        int flg=0,val,val_key,val_max,val_min,val_key_max,eval_count,imax;
        vector<vector<int>>simulate,eval_all,basyo;
        vector<int>vals(2);
        basyo=sagasu(row,soutesu,sente);
        int basyosu=basyo.size();
        if(basyosu==0){
            if(sente==1){
                basyo=sagasu(row,soutesu,0);
                sente=0;
            }else{
                basyo=sagasu(row,soutesu,1);
                sente=1;
            }
            basyosu=basyo.size();
            if(basyosu==0){
                flg=1;
                val_min=min(hantei1[pn],val_board(row,add1,add2)[key]);
                hantei1[pn]=val_min;
            }
        }

        if(flg==0){
            eval_all.resize(basyosu,vector<int>(4));
            for(i=0;i<basyosu;i++){
                node++;
                vals=val_board(kaesi(row,basyo[i],soutesu,sente),add1,add2);
                if(soutesu%2==sente){
                    val=vals[0];
                }else{
                    val=vals[1];
                }
                val_key=vals[key];
                eval_all[i]={val,basyo[i][0],basyo[i][1],val_key};
            }
            sort(eval_all.begin(),eval_all.end());
            reverse(eval_all.begin(),eval_all.end());
            val_max=eval_all[0][0];
            if(soutesu+1>=60||depth-1<0){
                val_key_max=eval_all[0][3];
                for(i=0;i<(int)eval_all.size();i++)val_key_max=max(val_key_max,eval_all[i][3]);
                val_min=min(hantei1[pn],val_key_max);
                hantei1[pn]=val_min;
            }else{
                eval_count=eval_all.size();
                imax=min(5,eval_count);
                for(i=0;i<imax;i++){
                    if((val_max>=0&&eval_all[i][0]<val_max/2+val_max%2)||(val_max<0&&eval_all[i][0]<2*val_max)){
                        break;
                    }else{
                        bfs(kaesi(row,{eval_all[i][1],eval_all[i][2]},soutesu,sente),soutesu+1,sente,pn,key,depth-1,add1,add2);
                    }
                }
            }
        }
    }
}

vector<int> hantei(vector<vector<int>> row,vector<vector<int>> basyo,
int soutesu,int sente,int add1,int add2){
    chrono::system_clock::time_point stime,etime;
    int i,key,tokuten_max;
    int basyosu=basyo.size();
    int max_basyosu=0;
    int utubasyo;
    vector<int>utu;
    vector<vector<int>> simulate,simulate2,basyo2;
    vector<vector<int>> max_basyo(basyosu,vector<int>(2));

    hantei1.resize(basyosu);
    for(i=0;i<basyosu;i++)hantei1[i]=1000000;
    node=0;

    if(soutesu%2==sente){
        key=0;
    }else{
        key=1;
    }

    cout<<"depth: "<<depth<<"\n";
    vector<vector<int>>basyo_order(basyosu,vector<int>(4));
    stime=chrono::system_clock::now();

    //探索
    tokuten_max=-100000000;
    for(i=0;i<basyosu;i++){
        bfs(kaesi(row,basyo[i],soutesu,sente),soutesu+1,sente,i,key,depth-1,add1,add2);
        if(hantei1[i]>tokuten_max){
            max_basyosu=0;
            tokuten_max=hantei1[i];
            max_basyo[0]=basyo[i];
            max_basyosu=1;
        }else if(hantei1[i]==tokuten_max){
            max_basyo[max_basyosu]=basyo[i];
            max_basyosu++;
        }
        cout<<i+1<<" "<<hantei1[i]<<"\n";
    }
    etime=chrono::system_clock::now();

    double elapsed=chrono::duration_cast<chrono::milliseconds>(etime-stime).count();
    elapsed/=1000;
    elapsed_all+=elapsed;
    cout<<"eval: "<<tokuten_max<<"\n";
    cout<<"node: "<<node<<"\n";
    cout<<"time: "<<elapsed<<"[sec]\n";
    cout<<"NPS: "<<(double)node/elapsed<<"\n";

    utubasyo=rand()%max_basyosu;
    utu=max_basyo[utubasyo];
    return utu;
}