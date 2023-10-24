// Do NOT add any other includes
#include "dict.h"
#include <iostream>
using namespace std;
const int md = 200003;
const vector<int> sep{32, 46, 44, 45, 58, 33, 40, 41, 63, 8212, 91, 93, 8220, 8221, 8216, 8217, 729, 59, 64, 59};

bool find_in_sep(char c)
{
    int n = sep.size();
    for (int i = 0; i < n; ++i)
    {
        if ((int)c == sep[i]){
            return true;
        }
    }
    return false;
}

int hash_function(string s)
{
    int h = 5381;
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        h = (33 * h + s[i]) % md;
    }
    return h;
}

Dict::Dict()
{
    vector<vector<DictNode>> make(md);
    words = make;
    size = 0;
}

Dict::~Dict()
{
}

vector<string> sent_to_words(string sentence)
{
    int i = 0;
    vector<string> words;
    while (i < sentence.size())
    {
        string curword = "";
        while (i < sentence.size() && !find_in_sep(sentence[i]))
        {
            if (int(sentence[i]) <= 122 && int(sentence[i]) >= 97)
            {
                curword += sentence[i];
            }
            else if (int(sentence[i]) <= 90 && int(sentence[i]) >= 65)
            {
                curword += char(int(sentence[i]) + 32);
            }
            else
            {
                curword += sentence[i];
            }
            i++;
        }
        words.push_back(curword);
        i++;
    }
    return words;
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    vector<string> sent_words = sent_to_words(sentence);
    for (string curword : sent_words)
    {
        if (curword != "")
        {
            int hashval = hash_function(curword);
            int probe = 0;
            while (probe < words[hashval].size() && words[hashval][probe].word != curword)
            {
                probe++;
            }
            if (probe == words[hashval].size())
            {
                DictNode newword;
                newword.word = curword;
                words[hashval].push_back(newword);
            }
            words[hashval][probe].count++;
        }
    }
}

int Dict::get_word_count(string word)
{
    int h = hash_function(word);
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
    for (int j = 0; j < md; j++)
    {
        int n = words[j].size();
        for (int i = 0; i < n; ++i)
        {
            f << words[j][i].word << ", " << words[j][i].count << endl;
        }
    }
    f.close();
    return;
}

// int main()
// {
//     Dict d;
//     d.insert_sentence(1, 1, 1, 1, "The quick bro)wn fox ...jumped ov;;er the la345zy dog..!");
//     d.insert_sentence(1, 1, 1, 2, "The     fox Is la345zy brown jumper");
//     d.dump_dictionary("output.txt");
// }