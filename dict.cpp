// Do NOT add any other includes
#include "dict.h"
const int md = 200003;


struct DictNode{
public:
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

vector<string> sent_to_words(string sentence){
    int i=0;
    vector<string> words;
    while(i<sentence.size()){
        string curword="";
        while(((int(sentence[i])<=122 && int(sentence[i])>=97) || (int(sentence[i])<=90 && int(sentence[i]>=65))) && i<sentence.size()){
            if(int(sentence[i])<=122 && int(sentence[i])>=97){
                curword+=sentence[i];
            }
            else{
                curword+=char(int(sentence[i])+32);
            }
            i++;
        }
        words.push_back(curword);
        i++;
    }
    return words;
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    vector<string> sent_words=sent_to_words(sentence);
    for(string curword: sent_words){
        if(curword!=""){
            int hashval=hash(curword);
            int probe=0;
            while(probe<words[hashval].size() && words[hashval][probe].word!=curword){
                probe++;
            }
            if(probe==words[hashval].size()){
                DictNode newword; 
                newword.word=curword;
                words[hashval].push_back(newword);
            }
            words[hashval][probe].count++;
        }
    }
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