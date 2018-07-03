#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.

void dfsMoon(vector<int> adj[],int n,int u,vector<bool> &visited,int &cnt){
    visited[u]=true;
    for(int i=0;i<adj[u].size();i++){
        if(!visited[adj[u][i]]){
            cnt++;
            dfsMoon(adj,n,adj[u][i],visited,cnt);
        }
    }
}

long journeyToMoon(int n, vector<vector<int>> astronaut) {
    
    vector<int> adj[n];
    for(int i=0;i<astronaut.size();i++){
        adj[astronaut[i][0]].push_back(astronaut[i][1]);
        adj[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    long long ans = 0;
    vector<bool> visited(n,false);
    long long x = n;
    ans = x*(x-1)/2;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            int count = 1;
            dfsMoon(adj,n,i,visited,count);
            ans -= (count*(count-1)/2);
        }
    }
    return ans;

}

int main()
{
    int n,p;
    cin >> n >> p;
    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }
    }

    long long result = journeyToMoon(n, astronaut);

    cout << result << "\n";

    return 0;
}