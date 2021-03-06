/*
 * Graph is Bipartite, if it does not contain odd length cycle.
 * This algorithm is used to check whether a graph contain odd length cycle.
 * 
 * Time Complexity: O(V+E))
 */
 
#include <iostream>
#include <queue>
#include <string.h>

const int N = 2000;
std::vector < int > v[N];
int color[N];
bool flag;

bool bfs(int s)  
{
    std::queue < int > q;
    q.push(s);
    color[s] = 1;
    bool flag = 0;
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(auto x : v[p]) {
            if(color[x] == 0 and color[x] != color[p]) {
                color[x] = 3 - color[p];
                q.push(x);
            }
            else if(color[x] == color[p]) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) {
            break;
        }
    }
    return flag;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    
    memset(color, 0, sizeof(color));
    
    for(int i = 0; i < m; i ++) {
        int x, y;
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i ++) {
        if(color[i] == 0) {
            bool f = bfs(i);
            flag = std::max(f, flag);
        }
    }
    
    if(flag) {
        std::cout << "Graph is not Bipartite";
    }
    else {
        std::cout << "Graph is Bipartite";
    }
    
    std::cout << "\n";
    return 0;
}
