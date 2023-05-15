#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000000;

int min(int a, int b) {
    if (a >= b)
        return b;
    return a;
}

void zapoln_graph_for_deikstra(vector < vector < pair<int, int> > > &g) {
    g[0].push_back({ rand() % 50, rand() % 50 });
    g[0].push_back({ rand() % 50, rand() % 50 });
    
    g[1].push_back({ rand() % 50 , rand() % 50 });
    g[1].push_back({ rand() % 50, rand() % 50 });
    g[1].push_back({ rand() % 50, rand() % 50 });
    
    g[2].push_back({ rand() % 50, rand() % 50 });
    g[2].push_back({ rand() % 50, rand() % 50 });
    
    g[3].push_back({ rand() % 50, rand() % 50 });
    g[3].push_back({ rand() % 50, rand() % 50 });
    g[3].push_back({ rand() % 50, rand() % 50 });
    
    g[4].push_back({ rand() % 50, rand() % 50 });
    g[4].push_back({ rand() % 50, rand() % 50 });
    g[4].push_back({ rand() % 50, rand() % 50 });
    
    g[5].push_back({ rand() % 50, rand() % 50 });
    g[5].push_back({ rand() % 50, rand() % 50 });
    g[5].push_back({ rand() % 50, rand() % 50 });
    
    g[6].push_back({ rand() % 50, rand() % 50 });
    g[6].push_back({ rand() % 50, rand() % 50 });
    
    g[7].push_back({ rand() % 50, rand() % 50 });
    g[7].push_back({ rand() % 50, rand() % 50 });
    g[7].push_back({ rand() % 50, rand() % 50 });
    
    g[8].push_back({ rand() % 50, rand() % 50 });
    g[8].push_back({ rand() % 50, rand() % 50 });
    g[8].push_back({ rand() % 50, rand() % 50 });
}

void zapoln_greaph_for_floid(vector <vector <int>> &g) {
    g[0] = { rand() % 50, rand() % 50, INF, rand() % 50, INF, INF, INF, INF, INF };
    g[1] = { rand() % 50, rand() % 50, rand() % 50, INF, rand() % 50, INF, INF, INF, INF };
    g[2] = { INF, rand() % 50, rand() % 50, INF, INF, INF, INF, INF, rand() % 50 };
    g[3] = { rand() % 50, INF, INF, rand() % 50, rand() % 50, INF, rand() % 50, INF, INF };
    g[4] = { INF, rand() % 50, INF, rand() % 50, rand() % 50, rand() % 50, INF, INF, INF };
    g[5] = { INF, INF, INF, INF, rand() % 50, rand() % 50, INF, rand() % 50, rand() % 50 };
    g[6] = { INF, INF, INF, rand() % 50, INF, INF, rand() % 50, rand() % 50, INF };
    g[7] = { INF, INF, INF, INF, INF, rand() % 50, rand() % 50, rand() % 50, rand() % 50 };
    g[8] = { INF, INF, rand() % 50, INF, INF, rand() % 50, INF, rand() % 50, rand() % 50 };
    
}

int deikstra(int n, vector < vector < pair<int, int> > > g) {
    int s = 0;
    int chet = 0;
    vector<int> d(n, INF), p(n);
    d[s] = 0;
    vector<char> u(n);
    for (int i = 0; i < n; ++i) {
        chet++;
        int v = -1;
        for (int j = 0; j < n; ++j) {
            chet++;
            if (!u[j] && (v == -1 || d[j] < d[v])) {
                chet++;
                v = j;
            }
        }
        if (d[v] == INF) {
            chet++;
            break;
        }
        u[v] = true;
        
        for (size_t j = 0; j < g[v].size(); ++j) {
            chet++;
            int to = g[v][j].first,
            len = g[v][j].second;
            if (d[v] + len < d[to]) {
                chet++;
                d[to] = d[v] + len;
                p[to] = v; }
        }
    }
    
    //derivation of shortest paths
    /*for (int i = 0; i < n; i++) {
     cout << i << ": " << d[i] << endl;
     }*/
    
    return chet;
}

int floid(int n, vector <vector <int>> g) {
    int chet = 0;
    for (int k = 0; k < n; ++k) {
        chet++;
        for (int i = 0; i < n; ++i) {
            chet++;
            for (int j = 0; j < n; ++j) {
                chet++;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    return chet;}


int main() {
    int n = 9;
    
    for (int i = 0; i < 10; i++) {
        vector < vector < pair<int, int> > > g_for_deikstra(n);
        zapoln_graph_for_deikstra(g_for_deikstra);
        
        
        vector <vector <int>> g_for_floid(n);
        zapoln_greaph_for_floid(g_for_floid);
        
        cout << "Dijkstra's algorithm was developed for " << deikstra(n, g_for_deikstra) << " steps" << endl;
        cout << "Floyd's algorithm was worked out for " << floid(n, g_for_floid) << " steps" << endl;
        cout << "\n\n";
    }
    system("pause");
    return 0; 
}
