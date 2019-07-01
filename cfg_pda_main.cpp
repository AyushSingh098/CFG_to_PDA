#include "CFG_PDA.cpp"
int main()
{
    string start_state = "";
    finput.open("input.txt");
    FileRead(finput, start_state);
    CFG_to_PDA(Grammer,Non_Term_States,Term_states,start_state);
    return 0;
}
