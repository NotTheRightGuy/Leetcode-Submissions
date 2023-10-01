class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> allWords;
        string currWord = "";
        for (auto i : s)
        {
            if (i == ' ')
            {
                allWords.push_back(currWord);
                currWord = "";
            }
            else
            {
                currWord += i;
            }
        }
        if (currWord != "")
            allWords.push_back(currWord);
        vector<string> reverseWords;
        for (auto word : allWords)
        {
            string temp = word;
            reverse(temp.begin(), temp.end());
            reverseWords.push_back(temp);
        }
        string final = "";
        for (auto word : reverseWords)
        {
            final += word;
            final += " ";
        }
        final.pop_back();
        return final;
    }
};