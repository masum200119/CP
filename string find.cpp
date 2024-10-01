class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        unordered_map<string,bool>existsinwords;
        for(auto j:words)
        {
            existsinwords[j]=true;
        }
        vector<string>ans;
        for(int i=0;i<words.size();i++)
        {
            bool partitionreachedend=false;
            //string: cat, partitions:|c|a|t|
            queue<int>checkfor;
            unordered_set<int>alreadypushedinqueue;
            checkfor.push(-1);
            while(!checkfor.empty())
            {
                int indexofword=checkfor.front();
                checkfor.pop();
                if(indexofword==(words[i].size()-1))
                {
                    partitionreachedend=true;
                    break;
                }
                string str;
                for(int j=indexofword+1;j<words[i].size();j++)
                {
                    str.push_back(words[i][j]);
                    if(existsinwords[str] && (j-indexofword)!=words[i].size())
                    {
                        if(alreadypushedinqueue.count(j)==0)
                        {
                            checkfor.push(j);
                            alreadypushedinqueue.insert(j);
                        }
                    }
                }
            }
            if(partitionreachedend)
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
