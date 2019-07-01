#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

//Dynamic array to store the Non Terminal States
vector<string> Non_Term_States;

//Dynamic array to store the Terminal States
vector<string> Term_states;

//Dynamic array for storing the production rule
//It is a vector in which each entry is a pair of string (LHS) and a vector(RHS) of
//a respective production rule
vector<pair<string,vector<string> > > Grammer;

//File Open
ifstream finput;

void FileRead(ifstream &, string &);
void CFG_to_PDA(vector<pair<string,vector<string> > > &, vector<string> &, vector<string> &, string);
