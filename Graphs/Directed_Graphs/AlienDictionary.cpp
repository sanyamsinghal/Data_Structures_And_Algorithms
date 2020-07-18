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


class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    int find_diff(string &a, string &b) {
        for(int i=0; i<min(a.size(), b.size()); i++) {
            if(a[i]!=b[i])
                return i;
        }
        return -1;
    } 
    
    bool dfs(vector<int>adj[], int node, bool vis[], string &ans, bool instack[]) {
        vis[node] = true;
        instack[node] = true;
        for(int child : adj[node]) {
            if(!vis[child]) {
                if(dfs(adj, child, vis, ans, instack))
                    return true;
            }
            else if(instack[child]==true)
                return true;
        }
        // cout<<((char)(node + 'a'))<<endl;
        ans += (char)(node + 'a');
        instack[node] = false;
        return false;
    }
     
    string alienOrder(vector<string> &words) {
        // Write your code here
        int n = words.size();
        vector<int>adj[26];
        set<char>s;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++){
                string w1 = words[i];
                string w2 = words[j];
                
                int id = find_diff(w1, w2);
                if(id==-1)  continue;
                adj[w1[id]-'a'].push_back(w2[id]-'a');
                
            }
        }
        
        for(int i=0; i<n; i++) {
            string w1 = words[i];
            for(int l=0; l<w1.size(); l++)
                s.insert(w1[l]);
        }
        
        // for(int i=0; i<26; i++) {
        //     if(adj[i].size()!=0) {
        //         cout<<((char)('a'+i))<<"->";
        //         for(int j=0; j<adj[i].size(); j++) {
        //             cout<<((char)('a'+adj[i][j]))<<" ";
        //         }
        //         cout<<endl;
        //     }
        // }
        
        string ans = "";
        bool vis[26] = {false};
        bool instack[26] = {false};
        for(int i=0; i<26; i++) {
            if(!vis[i] && adj[i].size()>0) {
                if(dfs(adj, i, vis, ans, instack))
                    return "";
            }
        }
        reverse(ans.begin(), ans.end());
        
        for(char c : ans) {
            s.erase(s.find(c));
        }
        
        vector<int>curr_ans;
        int i=0;
        set<char> :: iterator it = s.begin();
        while(i<ans.size() && it!=s.end()) {
            if(ans[i] < *it){
                curr_ans.push_back(ans[i]);
                i++;
            }
            else {
                curr_ans.push_back(*it);
                it++;
            }
        }
        
        while(i<ans.size()){
            curr_ans.push_back(ans[i++]);
        }
        while(it!=s.end()) {
            curr_ans.push_back(*it);
            it++;
        }
        
        ans="";
        for(int i=0; i<curr_ans.size(); i++) {
            ans += curr_ans[i];
        }
        
        
        return ans;
    }
};