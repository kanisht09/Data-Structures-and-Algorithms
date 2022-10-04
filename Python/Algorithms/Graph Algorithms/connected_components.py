class ConnectedComponent:
    def __init__(self, n):
        self.adj = [[] for _ in range(n)]
        self.n = n
        self.connected_components = []
        self.connected_component_nodes = []
        self.visited = [False for _ in range(n)]

    '''
    Adds bidirectional edge between nodes u and v
    '''

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def dfs(self, node, par):
        self.visited[node] = True
        self.connected_component_nodes.append(node)
        for child in self.adj[node]:
            if child != par and not self.visited[child]:
                self.dfs(child, node)

    def get_connected_components(self):
        for node in range(self.n):
            if not self.visited[node]:
                self.dfs(node, -1)
                self.connected_components.append([i for i in self.connected_component_nodes])
                self.connected_component_nodes.clear()
        return self.connected_components
      