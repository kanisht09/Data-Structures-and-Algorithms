import math

class LCA:
    def __init__(self, N):
        self.N = N
        self.adj = [[] for _ in range(N)]
        self.LOGN = int(math.log2(self.N)) + 1
        self.up = [[-1 for _ in range(self.LOGN)] for _ in range(self.N)]
        self.depth = [0 for _ in range(self.N)]

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def build(self):
        self.dfs(0, -1)

    def dfs(self, node, par):
        self.up[node][0] = par
        if par != -1:
            self.depth[node] = self.depth[par] + 1

        for i in range(1, self.LOGN):
            if self.up[node][i - 1] == -1:
                break
            self.up[node][i] = self.up[self.up[node][i - 1]][i - 1]

        for child in self.adj[node]:
            if child != par:
                self.dfs(child, node)

    '''
    Returns the LCA between two nodes u and v in O(logN)
    '''

    def get_lca(self, u, v):
        if self.depth[u] < self.depth[v]:
            u, v = v, u

        k = self.depth[u] - self.depth[v]

        for i in range(self.LOGN - 1, -1, -1):
            if k >= (1 << i):
                u = self.up[u][i]
                k -= (1 << i)

        if u == v:
            return u

        for i in range(self.LOGN - 1, -1, -1):
            if self.up[u][i] != self.up[v][i]:
                u = self.up[u][i]
                v = self.up[v][i]
        return self.up[u][0]
    