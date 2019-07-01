#include "CFG_PDA.h"
void FileRead(ifstream &finput, string &start_state)
{
  string line,ch,t,state;
  //If file doesnot exist or error in opening file
  if(!finput)
  {
      cerr<<"ERROR IN OPENING FILE\n";
      exit(1);
  }
  //Take each line in the input
  while(getline(finput,line))
  {
      istringstream ss(line);
      ss>>ch;
      //LINE 1 CONTAINIG THE NON TERMINALS
      //eg NT = S A B
      if(ch == "NT")
      {
          ss>>ch;
          while(ss >> ch)
          {
              Non_Term_States.push_back(ch);
          }
          //Assign the start state to first symbol of non terminals
          start_state = Non_Term_States[0];
      }
      //LINE 2 CONTAINIG THE TERMINALS
      //eg  = a b
      else if(ch == "T")
      {
          ss>>ch;
          while(ss >> ch)
          {
              Term_states.push_back(ch);
          }
      }
      // THE LHS AND RHS OF THE PRODUCTION RULES
      else
      {
          state = ch;
          ss>>ch;
          vector<string> temp;
          while(ss >> ch)
          {
              //If RHS not seperated by |, eg AB
              if(ch != "|")
              {
                  temp.push_back(ch);
              }
          }
          Grammer.push_back(make_pair<string,vector<string> >(state,temp));
      }
  }
}

void CFG_to_PDA(vector<pair<string,vector<string> > > &Grammer, vector<string> &Non_Term_States, vector<string> &Term_states, string start_state)
{
    int i,j;
    cout<<"___________________________________"<<endl;
    cout<<"NON TERMINAL STATES : \n";
    for(i=0 ; i<Non_Term_States.size() ; i++)
    {
        cout<<Non_Term_States[i]<<"  ";
    }
    cout<<endl;
    cout<<"TERMINAL STATES : \n";
    for(i=0 ; i<Term_states.size() ; i++)
    {
        cout<<Term_states[i]<<"  ";
    }
    cout<<endl;
    cout<<"START STATE : "<<start_state<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"PRODUCTION RULE :\n";
    //Temporary vector
    vector<string> t;
    for(i=0 ; i<Grammer.size() ; i++)
    {
        cout<<Grammer[i].first<<" -> ";
        t = Grammer[i].second;
        cout<<t[0];
        for(j=1 ; j<t.size() ; j++)
        {
            cout<<" | "<<t[j];
        }
        cout<<endl;
    }
    cout<<"___________________________________"<<endl;
    cout<<"\nCORRESPONDING PUSH DOWN AUTOMATA :\n";
    for(i=0 ; i<Grammer.size() ; i++)
    {
        cout<<"δ(q,ε,"<<Grammer[i].first<<") = { (q,";
        t = Grammer[i].second;
        cout<<t[0]<<")";;
        for(j=1 ; j<t.size() ; j++)
        {
            cout<<" , (q,"<<t[j]<<")";
        }
        cout<<" }"<<endl;
    }
    cout<<endl;
    for(i=0 ; i<Term_states.size() ; i++)
    {
        cout<<"δ(q,"<<Term_states[i]<<","<<Term_states[i]<<") = (q,ε)"<<endl;
    }
    cout<<"___________________________________"<<endl;
}
