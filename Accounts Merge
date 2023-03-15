class DisjointSet{
public:
	vector<int> parent,size;
	DisjointSet(int n){
		size.resize(n+1,1);
		parent.resize(n+1);
		for(int i=0;i<=n;i++) parent[i]=i;
	}
	
	int findUpar(int node){
		if(node==parent[node]) return node;
		return findUpar(parent[node]);
	}
	
	void UnionBySize(int u,int v){
		int Upar_u=findUpar(u);
		int Upar_v=findUpar(v);
		if(Upar_u==Upar_v) return;
		
		if(size[Upar_u]<size[Upar_v]){
			parent[Upar_u]=Upar_v;
			size[Upar_v]+=size[Upar_u];
		}
		else{
			parent[Upar_v]=Upar_u;
			size[Upar_u]+=size[Upar_v];
		}
	}
	
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
         int n = details.size();
        DisjointSet ds(n);
        sort(details.begin(), details.end());
        unordered_map<string, int> mailNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mailNode.find(mail) == mailNode.end()) {
                    mailNode[mail] = i;
                }
                else {
                    ds.UnionBySize(i, mailNode[mail]);
                }
            }
        }
        
        vector<string> mergedmail[n];
        for(auto it:mailNode){
            string mail=it.first;
            int node=ds.findUpar(it.second);
            mergedmail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedmail[i].size()==0) continue;
            sort(mergedmail[i].begin(),mergedmail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it:mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end(),greater<vector<string>>());
        return ans;
    }
};
