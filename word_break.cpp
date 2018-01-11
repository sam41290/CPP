
/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    map<string,int> dp;
    
    bool check_dict(string s,vector<string>& wordDict)
    {
        //cout<<"checking dictionary"<<wordDict.size() <<"\n";
        for(int i=0;i<wordDict.size();i++)
        {
            //cout<<s<<wordDict[i]<<s.compare(wordDict[i])<<"\n";
            if(s.compare(wordDict[i])==0)
            {
                dp.insert(pair<string,int>(s,1));
                return true;
            }
        }
        dp.insert(pair<string,int>(s,0));
        //cout<<"not found in dictionary\n";
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0)
            return false;
        map<string,int> :: iterator itr;
        itr=dp.find(s);
        if(itr!=dp.end())
        {
            if(itr->second == 1)
                return true;
            else
                return false;
        }
        else{
            if(check_dict(s,wordDict))
            {
                return true;
            }
            
            if(s.length() == 1)
                return false;
            int n = s.length();
            for(int i=0;i<n;i++)
            {
                string s1(s,0,i+1);
                string s2(s,i+1,n-i-1);
                if(wordBreak(s1,wordDict) && wordBreak(s2,wordDict))
                {
                    dp.insert(pair<string,int>(s,1));
                    return true;
                }
            }
        }
        return false;
    }
};
