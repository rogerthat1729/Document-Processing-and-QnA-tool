// Do NOT add any other includes
#include "dict.h"
const int md = 200003;

Dict::Dict(){
    // Implement your function here    
}

Dict::~Dict(){
    // Implement your function here    
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here  
    return;
}

int Dict::get_word_count(string word){
    return -1;
}

void Dict::dump_dictionary(string filename){
    // Implement your function here  
    return;
}

int hash(string s){
    int h = 5381;
    int n = s.length();
    for(int i = 0 ; i < n ; ++i)
    {
        h = (33*h + s[i])%md;
    }   
    return h;
}