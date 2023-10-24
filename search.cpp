// Do NOT add any other includes
#include "search.h"

SearchEngine::SearchEngine()
{
}

SearchEngine::~SearchEngine()
{
}

vector<int> KMP(string s ,vector<int> table)
{
    int i = 0, j = 0;
    while(i < s.length()){
        
    }
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    sentences.push_back(sentence);
    data.push_back({book_code, page, paragraph, sentence_no});
    return;
}

Node *SearchEngine::search(string pattern, int &n_matches)
{
    Node* head = new Node(0, 0, 0, 0, 0);
    Node* curr = head;
    for (string s : sentences)
    {
        
    }
    return nullptr;
}