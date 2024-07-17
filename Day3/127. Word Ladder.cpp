// https://leetcode.com/problems/word-ladder/description/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto it: wordList)
        {
            st.insert(it);
        }
        if(st.find(endWord)==st.end())
            return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        if(st.find(beginWord)!=st.end())
            st.erase(beginWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int level = q.front().second;
            if(word==endWord)
                return level;
            q.pop();
            for(int j = 0;j<word.length();j++)
            {
                for(char i = 'a'; i<='z';i++)
                {   
                    if(i==word[j])
                        continue;
                    string newWord = word;
                    newWord[j] = i;
                    if(st.find(newWord)!=st.end())
                    {   
                        q.push({newWord,level+1});
                        st.erase(newWord);
                    }
                }
            }
        }
        return 0;
    }
};