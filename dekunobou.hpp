/*#pragma GCC target("avx512f,avx512dq,avx512cd,avx512bw,avx512vl")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")*/
#include<bits/stdc++.h>
/*#include<algorithm>
#include<chrono>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<stdio.h>
#include<time.h>
#include<vector>*/
using namespace std;

extern int node,depth,node_all;
extern double elapsed_all;
extern vector<int>hantei1,side_pattern;
extern vector<vector<int>>stone,out_indx,corner;
extern vector<vector<vector<int>>>r_diff;

#pragma once

//othello3.cpp
vector<vector<int>> row_init();
vector<vector<int>> nyuryoku(vector<vector<int>> row,int basyo[65][2],int soutesu,int sente,int teban);
void hyouji(vector<vector<int>>& row);
void hyouji_teban(vector<vector<int>>& row,int basyo[65][2]);
vector<vector<int>> kaesi(vector<vector<int>> row,int basyo[2],int soutesu,int sente);
vector<int> kazu_count(vector<vector<int>>& row);

//sagasu.cpp
void sagasu(vector<vector<int>>& row,int basyo[65][2], int soutesu, int sente);
void basyo_hyouji(int basyo[65][2]);
void basyo_print(int basyo[65][2]);

//vector_operation.cpp
bool search_vector(vector<vector<int>> list, vector<int> element);
bool search_zahyou(vector<vector<int>> list,int x,int y);
bool basyo_search(int L[65][2],int x,int y);
bool compare(vector<int>a,vector<int>b);
bool search_element(vector<int> list,int element);
vector<vector<int>> append(vector<vector<int>> list);

//hantei.cpp
vector<int> hantei(vector<vector<int>> row,int basyo[65][2],int soutesu,int sente,int add1,int add2);


//others.cpp
void time_print(double elapsed);
void disp_nowtime();