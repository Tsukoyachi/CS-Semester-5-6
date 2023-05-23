package graph.tools.ORIGIN;

import graph.AbstractGraph;
import graph.Vertex;

import java.util.*;

public class GraphTraversal {

    /* -------------------- DFS ---------------------- */

    /**
     * Returns the list of vertices of 'graph' in DFS order
     *
     * @param graph
     * @param start
     * @return
     */
    public static List<Vertex> dfs(AbstractGraph graph, Vertex start) {
        List<Vertex> visited = new ArrayList<>(graph.nbVertices());
        Deque<Vertex> toVisit = new ArrayDeque<>();
        toVisit.push(start);
        while (!toVisit.isEmpty()) {
            Vertex current = toVisit.pop();
            if (!visited.contains(current)) {
                visited.add(current);
                for (Vertex v : graph.adjacents(current)) {
                    toVisit.push(v);
                }
            }
        }
        return visited;
    }



    /* -------------------- BFS ---------------------- */

    /**
     * Returns the list of vertices of 'graph' in BFS order
     *
     * @param graph
     * @param start
     * @return
     */
    public static List<Vertex> bfs(AbstractGraph graph, Vertex start) {
        List<Vertex> visited = new ArrayList<>(graph.nbVertices());
        List<Vertex> toVisit = new ArrayList<>();
        toVisit.add(start);
        while (!toVisit.isEmpty()) {
            Vertex current = toVisit.get(0);
            toVisit.remove(0);
            if (!visited.contains(current)) {
                visited.add(current);
                for (Vertex v : graph.adjacents(current)) {
                    toVisit.add(v);
                }
            }
        }
        return visited;
    }


    /* -------------------- Dijkstra ---------------------- */

    public static List<Vertex> dijkstra(AbstractGraph graph, Vertex start, Vertex end) {
        PriorityQueue<Vertex> queue = new PriorityQueue<>(Comparator.comparingDouble(Vertex::getWeight));
        start.setWeight(0);
        queue.add(start);


        Map<Vertex,Vertex> precedence = new HashMap<>(graph.nbVertices());

        while (!queue.isEmpty()) {
            Vertex current = queue.poll();

            if (current.equals(end)) {
                break;
            }

            for (Vertex next : graph.adjacents(current)) {
                double newWeight = current.getWeight() + graph.findEdge(current, next).weight();
                if(!precedence.containsKey(next) || newWeight < next.getWeight()) {
                    next.setWeight(newWeight);
                    precedence.put(next,current);
                    queue.add(next);
                }
            }
        }

        List<Vertex> res = new ArrayList<>();

        Vertex tmp = end;
        while(tmp != start){
            res.add(tmp);
            tmp = precedence.get(tmp);
        }
        res.add(start);
        Collections.reverse(res);
        return res;
    }
}
