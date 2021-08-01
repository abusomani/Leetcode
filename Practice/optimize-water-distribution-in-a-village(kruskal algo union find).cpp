class UnionFind {
public:
  UnionFind(int N) : unionFind(N) {
    for (int i = 0; i < N; ++i)
      unionFind[i] = i;
  }

  void merge(int key1, int key2) {
    key1 = get(key1);
    key2 = get(key2);
    if (key1 == key2) return;
    unionFind[key2] = key1;
  }
  
  int get(int key) {
    while (key != unionFind[key])
      key = unionFind[key] = unionFind[unionFind[key]];
    return key;
  }
  
private:
  vector<int> unionFind;
};
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // Represent the wells as additional pipes to a water-source node 0
      for (int i = 1; i <= n; ++i)
        pipes.push_back({0, i, wells[i-1]});

      // Kruskal's algorithm
      UnionFind uf(n+1);
      sort(pipes.begin(), pipes.end(), [](auto& a, auto& b){ return a[2] < b[2]; });
      int result = 0;
      for (auto& pipe : pipes) {
        if (uf.get(pipe[0]) != uf.get(pipe[1])) {
          result += pipe[2];
          uf.merge(pipe[0], pipe[1]);
        }
      }

      return result;
    }
};
