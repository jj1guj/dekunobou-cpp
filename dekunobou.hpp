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

extern int node,depth;
extern double elapsed_all;
extern vector<int>hantei1,side_pattern;
extern vector<vector<int>>stone,out_indx,corner;
extern vector<vector<vector<int>>>r_diff;

#pragma once

//othello3.cpp
vector<vector<int>> row_init();
vector<vector<int>> nyuryoku(vector<vector<int>> row,vector<vector<int>> basyo,int soutesu,int sente,int teban);
int hyouji(vector<vector<int>> row);
int hyouji_teban(vector<vector<int>> row,vector<vector<int>> basyo);
vector<vector<int>> kaesi(vector<vector<int>> row,vector<int> basyo,int soutesu,int sente);
vector<int> kazu_count(vector<vector<int>>& row);

//sagasu.cpp
vector<vector<int>> sagasu(vector<vector<int>>& row, int soutesu, int sente);
vector<vector<int>> basyo_hyouji(vector<vector<int>> basyo);
int basyo_print(vector<vector<int>> basyo);

//vector_operation.cpp
bool search_vector(vector<vector<int>> list, vector<int> element);
bool search_zahyou(vector<vector<int>> list,int x,int y);
bool compare(vector<int>a,vector<int>b);
bool search_element(vector<int> list,int element);
vector<vector<int>> append(vector<vector<int>> list);

//hantei5.cpp
vector<int> hantei5(vector<vector<int>> row,vector<vector<int>> basyo,int soutesu,int sente,int add1,int add2);


//others.cpp
void time_print(double elapsed);
void disp_nowtime();