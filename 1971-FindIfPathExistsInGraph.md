# [1971. Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/description/)

- The Algorithm first creates an ***Adjacency List*** in O(V) time. The Adjacency List is a dictionary (*hashmap*) which uses O(V+E) space complexity.
- The path is going to be checked by using **Depth First Search**. So *explored* list is created which takes O(V) space complexity.
- The function *dfs* performs the depth first algorithm with O(V) function call stack during recursion. 

```python3

from typing import List

class Solution:
    def dfs(self, tree, explored, source, destination):
        explored[source] = True

        for edge in tree[source]:
            if False == explored[edge]:
                if edge == destination:
                    return True
                if self.dfs(tree, explored, edge, destination):
                    return True
        return False

    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:

        if 0 == len(edges):
            return True
        if source == destination:
            return True

        explored: List[bool] = [0] * n
        tree = {}

        for i in edges:
            if i[0] in tree:
                tree[i[0]].append(i[1])
            else:
                tree[i[0]] = [i[1]]

            if i[1] in tree:
                tree[i[1]].append(i[0])
            else:
                tree[i[1]] = [i[0]]

        return self.dfs(tree, explored, source, destination)

def main() -> None:
    sol = Solution()

    n: int = 3
    edges = [[0,1],[1,2],[2,0]]
    source = 0
    dest = 2

    print(sol.validPath(n, edges, source, dest))

if __name__ == '__main__':
    main()

```

## Time Complexity

- Building the adjacency list representation of the graph: This involves iterating through all edges, and for each edge, potentially adding two vertices to the adjacency list. So, it takes O(E) time, where E is the number of edges.
- Depth-First Search (DFS): In the worst case, if the graph is a complete graph, each node could be connected to every other node. So, the DFS traversal could potentially visit all nodes. In the worst case, the time complexity of DFS is O(V + E), where V is the number of vertices and E is the number of edges. However, in practice, it depends on the structure of the graph.
- Overall, the time complexity is dominated by the DFS traversal in the worst case: O(V + E).

## Space Complexity

- The space complexity mainly comes from the adjacency list representation of the graph (tree) and the explored list used for DFS.
- The tree dictionary stores the adjacency list representation of the graph, which takes O(V + E) space, where V is the number of vertices and E is the number of edges.
- The explored list stores whether each node has been visited during the DFS traversal. It takes O(V) space.
- Apart from these, there's additional space usage for function call stack during the DFS recursion, which depends on the depth of the recursion tree, but it's at most O(V) in this case.
- So, the overall space complexity is O(V + E).
