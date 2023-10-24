// Do NOT add any other includes
#include "search.h"

SearchEngine::SearchEngine()
{
}

SearchEngine::~SearchEngine(){
    // Implement your function here  
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    for(int i = 0; i < sentence.length(); i++)
    {
        if (int(sentence[i]) <= 90 && int(sentence[i]) >= 65)
        {
            sentence[i] += 32;
        }
    }
    sentences.push_back(sentence);
    data.push_back({book_code, page, paragraph, sentence_no});
    return;
}

vector<int> KMPTable(string s)
{
    vector<int> t(s.size());
    int pos = 1;
    int cnd = 0;
    while (pos < s.size())
    {
        if (s[pos] == s[cnd])
        {
            t[pos] = t[cnd];
        }
        else
        {
            t[pos] = cnd;
            while (cnd >= 0 && s[pos] != s[cnd])
            {
                cnd = t[cnd];
            }
        }
        pos++;
        cnd++
    }
    t[pos] = cnd;
    return t;
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