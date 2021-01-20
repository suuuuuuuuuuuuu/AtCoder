#include <iostream>

using namespace std;

using ll = long long;
struct edge {ll from, to, cost;};
const ll INF = __LONG_LONG_MAX__;

class Bellman_Ford
{
public:
    ll *d;
    edge *es;
    ll V,E;
    Bellman_Ford(ll v, ll e);
    void set_edge(ll e, ll t, ll f, ll c);
    void shortest_path(ll s);
    bool find_negative_loop();
};

Bellman_Ford::Bellman_Ford(ll v, ll e){
    V = v ; 
    E = e ;
    d = new ll[V];
    es = new edge[E];
    for (int i = 0; i < V; i++) d[i] = INF;
}

void Bellman_Ford::set_edge(ll e, ll t, ll f, ll c){
    es[e].to = t;
    es[e].from = f;
    es[e].cost = c;
}

void Bellman_Ford::shortest_path(ll s){
    for (int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;
    while(true){
        bool update = false;
        for (int i = 0; i < E; i++){
            if (d[es[i].from] != INF && d[es[i].to] > d[es[i].from] + es[i].cost){
                d[es[i].to] = d[es[i].from] + es[i].cost;
                update = true;
            }
        }
        if (!update) break;
    }
}

int main(){
  Bellman_Ford bf(100 * 2, (100 + 99 * 2 + 99 * 2)*2);
  ll x, y, a, b;
  x = 1; y = 5; a = 2; b = 1;
  int c = 0;
  for (int i = 0; i < 100; i++){
    bf.set_edge(c++, i, i + 100, x);
    bf.set_edge(c++, i + 100, i, x);
  }
  for (int i = 0; i < 99; i++){
    bf.set_edge(c++, i, i + 101, x);
    bf.set_edge(c++, i + 101, i, x);

    bf.set_edge(c++, i + 1, i + 100, x);
    bf.set_edge(c++, i + 100, i + 1, x);

    bf.set_edge(c++, i, i + 1, y);
    bf.set_edge(c++, i + 1, i, y);

    bf.set_edge(c++, i + 100, i + 101, y);
    bf.set_edge(c++, i + 101, i + 100, y);
  }
  bf.shortest_path(a);
  for (int i = 0; i < bf.V; i++) cout<<i<<"\n";
}