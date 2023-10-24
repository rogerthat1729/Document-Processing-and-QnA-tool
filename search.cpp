// Do NOT add any other includes
#include "search.h"

SearchEngine::SearchEngine(){
    // Implement your function here  
}

SearchEngine::~SearchEngine(){
    // Implement your function here  
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here  
    return;
}

vector<int> KMPTable(string s){
    vector<int> t(s.size());
    int pos=1; int cnd=0;
    while(pos<s.size()){
        if(s[pos]==s[cnd]){
            t[pos]=t[cnd];
        }
        else{
            t[pos]=cnd;
            while(cnd>=0 && s[pos]!=s[cnd]){
                cnd=t[cnd];
            }
        }
        pos++;
        cnd++
    }
    t[pos]=cnd;
    return t;
}

Node* SearchEngine::search(string pattern, int& n_matches){
    // Implement your function here  
    return nullptr;
}