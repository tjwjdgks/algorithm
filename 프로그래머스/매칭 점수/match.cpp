#include <string>
#include <vector>
#include <iostream>
using namespace std;

void lower(string& a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if ('A' <= a[i] && a[i] <= 'Z')
        {
            a[i] = a[i] - 'A' + 'a';
        }
    }
}

int solution(string word, vector<string> pages)
{
    int stdScore[25] = { 0 };
    double result[25] = { 0 };
    vector<string> my_page[25];
    vector<string> out_page[25];

    for (int i = 0; i < pages.size(); i++)
    {

        int idx = 0;
        lower(pages[i]);
        lower(word);


        idx = pages[i].find("<meta property=\"og:url\"", idx);
        idx = pages[i].find("https://", idx);

        string my_url = "";
        for (int j = idx; pages[i][j] != '"'; j++)
        {
            my_url += pages[i][j];
        }
        my_page[i].push_back(my_url);

        
        while (pages[i].find("<a href=", idx) != string::npos)
        {
            idx = pages[i].find("<a href=", idx);
            idx = pages[i].find("https://", idx);

            string link_url = "";
            for (int j = idx; pages[i][j] != '"'; j++)
            {
                link_url += pages[i][j];
            }
            out_page[i].push_back(link_url);
        }

      
        idx = 0;
        int wordCnt = 0;
        while (pages[i].find(word, idx) != string::npos)
        {
            bool notWord = false;
            idx = pages[i].find(word, idx);


            if (0 <= idx - 1 && idx - 1 < pages[i].size() && 'a' <= pages[i][idx - 1] && pages[i][idx - 1] <= 'z')
            {
                notWord = true;
            }

            idx += word.size();


            while (0 <= idx && idx < pages[i].size() && 'a' <= pages[i][idx] && pages[i][idx] <= 'z')
            {
                notWord = true;
                idx++;
            }

            if (notWord == false)
            {
                wordCnt++;
            }
        }
        stdScore[i] = wordCnt;
    }

  
    for (int i = 0; i < pages.size(); i++)
    {
        int linkCnt = 0;
        vector<int> link;

        for (int j = 0; j < pages.size(); j++)
        {
            if (i == j)
            {
                continue;
            }

            for (int k = 0; k < out_page[j].size(); k++)
            {
                if (my_page[i][0] == out_page[j][k])
                {
                    link.push_back(j);
                }
            }
        }

        result[i] = stdScore[i];
        for (int j = 0; j < link.size(); j++)
        {
            if (stdScore[link[j]] == 0 || out_page[link[j]].size() == 0)
            {
                continue;
            }

            double linkScore = (double)stdScore[link[j]] / out_page[link[j]].size();
            result[i] += linkScore;
        }
    }

    double Max = -1;
    int MaxIdx = -1;
    for (int i = 0; i < pages.size(); i++)
    {
        if (Max < result[i])
        {
            Max = result[i];
            MaxIdx = i;
        }
    }

    return MaxIdx;
}