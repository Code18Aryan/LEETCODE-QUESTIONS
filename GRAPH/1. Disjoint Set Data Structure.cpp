//   DSU stands for disjoint set data structure, which is widely used in solving graph problems, mainly dealing with components 

class DSU{
    public:

    vector<int> parent,size;

    DSU(int n){

        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0; i<=n; i++){

            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){

        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){

        int up_u = findParent(u);
        int up_v = findParent(v);

        if(up_u == up_v) return;

        if(size[up_u] < size[up_v]){

            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }

        else{

           parent[up_v] = up_u;
           size[up_u] += size[up_v]; 
        }
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int extraEdge = 0;

        int component = 0;

        DSU disjoint(n);

        for(auto x : connections){

            int u = x[0];
            int v = x[1];

            if(disjoint.findParent(u) == disjoint.findParent(v)){

                extraEdge++;
            }

            else disjoint.unionBySize(u,v);

        }

        for(int i=0; i<n; i++){

            if(disjoint.findParent(i) == i) component++;
        }

        int requiredComp = component-1;

        if(extraEdge >= requiredComp){

            return requiredComp;
        }

       return -1;

    }

};
