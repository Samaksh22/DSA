#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<string> getHTMLTags()
{
    vector<string> tags;
    while (cin)
    {
        string line;
        getline(cin, line);

        int pos = 0;
        int tagStart = line.find("<", pos);

        while (tagStart != string::npos)
        {
            int tagEnd = line.find(">", tagStart + 1);
            tags.push_back(line.substr(tagStart, tagEnd - tagStart + 1));
            pos = tagEnd + 1;
            tagStart = line.find("<", pos);
        }
    }

    return tags;
}

bool isHTMLmatched(const vector<string> &tags)
{
    stack<string> s;
    for (const auto &p : tags)
    {
        if (p.at(1) != '/')
            s.push(p);
        else
        {
            if (s.empty())
                return false;

            string open = s.top().substr(1);
            string close = p.substr(2);

            if (open.compare(close) != 0)
                return false;
            else
                s.pop();
        }
    }

    return s.empty();
}

int main()
{
    if (isHTMLmatched(getHTMLTags()))
        cout << "The input file is a matched HTML document." << endl;
    else
        cout << "The input file is not a matched HTML document." << endl;

    return 0;
}