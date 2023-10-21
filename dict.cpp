// Do NOT add any other includes
#include "dict.h"

struct DictNode{
    int count=0;
    string word;
};

Dict::Dict(){
    vector<vector<DictNode>> make(200003);
    words=make;
    size=0;
}

Dict::~Dict(){
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here  
    return;
}

int Dict::get_word_count(string word){
    // Implement your function here  
    return;
}

void Dict::dump_dictionary(string filename){
    // Implement your function here  
    return;
}