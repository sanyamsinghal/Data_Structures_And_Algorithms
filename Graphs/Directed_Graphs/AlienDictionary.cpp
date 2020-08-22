/*
  The problem is present at Lintcode with name as ALien Dictionary.

  It is a nice problem on Topological Sort.
  1) Here find we have to make a graph for every pair of adjacent words on basis of 
  different characters they have. like for "abc" and "abd" we have c->d.

  2) We also have to check if there is a cycle like a->b->a, then we have to return
  an empty string "".

  3) In case all the characters are not available in the final order, then the 
  remaining chars are added to answer lexicographically i.e. they are placed
  in way that the characters before it are less than it in the answer.
  i.e. merge the answer array and the array with remaining chars that are not their 
  in answer after applying topological sort.

*/

class Solution
{
public:
    vector<int> graph[26];
    unordered_map<int, bool> vis, instack;
    string res;

    bool prefix(string &s1, string &s2)
    {
        string curr = "";

        for (char c : s2)
        {
            curr += c;
            if (curr == s2)
                return false;
            if (curr == s1)
                return true;
        }

        return false;
    }

    bool dfs(int node)
    {
        vis[node] = true;
        instack[node] = true;

        for (auto child : graph[node])
        {
            if (!vis[child])
            {
                if (dfs(child))
                    return true;
            }
            else if (vis[child] && instack[child])
                return true;
        }
        res.push_back((char)(node + 'a'));
        return instack[node] = false;
    }

    int findDiff(string &s1, string &s2)
    {
        for (int i = 0; i < min(s1.size(), s2.size()); i++)
        {
            if (s1[i] != s2[i])
                return i;
        }

        return -1;
    }

    string alienOrder(vector<string> &words)
    {
        res = "";
        set<string> occured;

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {

                if (words[i].size() > words[j].size() && prefix(words[j], words[i])) //if the word as a prefix of other comes later
                    return "";

                int id = findDiff(words[i], words[j]);
                if (id != -1)
                    graph[words[i][id] - 'a'].push_back(words[j][id] - 'a');
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (!vis[i] && graph[i].size() > 0)
            {
                if (dfs(i))
                    return "";
            }
        }

        // if(res=="")
        //     return res;

        reverse(res.begin(), res.end());

        for (auto x : words)
        {
            for (auto y : x)
            {
                if (!vis[y - 'a'])
                {
                    res += y;
                    vis[y - 'a'] = true;
                }
            }
        }

        return res;
    }
};
