// Do NOT add any other includes
#include "dict.h"
const int md = 200003;

int hash(string s)
{
    int h = 5381;
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        h = (33 * h + s[i]) % md;
    }
    return h;
}

struct DictNode
{
    int count = 0;
    string word;
};

Dict::Dict()
{
    vector<vector<DictNode>> make(200003);
    words = make;
    size = 0;
}

Dict::~Dict()
{
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    // Implement your function here
    return;
}

int Dict::get_word_count(string word)
{
    int h = hash(word);
    int n = words[h].size();
    for (int i = 0; i < n; ++i)
    {
        if (word == words[h][i].word)
            return words[h][i].count;
    }
    return 0;
    return -1;
}

void Dict::dump_dictionary(string filename)
{
    std::ofstream f;
    f.open(filename);
    for(auto &x : words){
        int n = x.size();
        for(int i = 0 ; i < n ; ++i)
        {
            f << x[i].word << ", " << x[i].count << endl;
        }
    }
    f.close();
    return;
}
