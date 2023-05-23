package graph.tools.ORIGIN;

import graph.*;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Optional;

/**
 * A class to find cycles in undirected and directed graphs
 */
public class GraphHelper {

    private Graph aGraph;


    /////////////// Cycle detection for undirected graphs

    public GraphHelper() {
        //TO IMPLEMENT
    }

    /**
     * Returns true if the graph 'G' is cyclic
     * false otherwise
     */
    public boolean hasCycle(UnDiGraph unDiGraph) {
        for (Vertex vertex : unDiGraph.vertices()) {
            ArrayList<Vertex> tmp = new ArrayList<>();
            tmp.add(vertex);
            if (!checkCycleUnDiGraph(tmp, unDiGraph).isEmpty()) {
                return true;
            }
        }
        return false;
    }

    /**
     * Return an empty list if no cycle beginning with index 0 of visited can be found,
     * if a cycle exist it'll return the path to do that cycle
     * @param visited An arraylist that possess at index 0 the beginning of the cycle
     * @param unDiGraph The undirectionnal graph we go through
     * @return Empty arrayList if no cycle, else the complete path.
     */
    private ArrayList<Vertex> checkCycleUnDiGraph(ArrayList<Vertex> visited, UnDiGraph unDiGraph) {
        Vertex current = visited.get(visited.size() - 1);
        for (Vertex next : unDiGraph.adjacents(current)) {
            if (!visited.contains(next)) {
                visited.add(next);
                ArrayList<Vertex> potentialRes = checkCycleUnDiGraph(visited, unDiGraph);
                if (potentialRes.isEmpty()) {
                    visited.remove(visited.size() - 1);
                } else {
                    return potentialRes;
                }
            }
            if(visited.size()>2 && next.equals(visited.get(0))){
                visited.add(next);
                return visited;
            }
        }
        return new ArrayList<>();
    }

    /////////////// Cycle detection for directed graphs

    private enum Status {UN_DISCOVERED, IN_PROGRESS, COMPLETED} // status of vertex

    /**
     * Returns true if the graph 'G' is cyclic
     * false otherwise
     */
    public boolean hasCycle(DiGraph diGraph) {
        for (Vertex vertex : diGraph.vertices()) {
            ArrayList<Vertex> tmp = new ArrayList<>();
            tmp.add(vertex);
            if (!checkCycleDiGraph(tmp, diGraph).isEmpty()) {
                return true;
            }
        }
        return false;
    }

    /**
     * Return an empty list if no cycle beginning with index 0 of visited can be found,
     * if a cycle exist it'll return the path to do that cycle
     * @param visited An arraylist that possess at index 0 the beginning of the cycle
     * @param diGraph The directionnal graph we go through
     * @return Empty arrayList if no cycle, else the complete path.
     */
    private ArrayList<Vertex> checkCycleDiGraph(ArrayList<Vertex> visited, DiGraph diGraph) {
        Vertex current = visited.get(visited.size() - 1);
        for (Vertex next : diGraph.adjacents(current)) {
            if (!visited.contains(next)) {
                visited.add(next);
                ArrayList<Vertex> potentialRes = checkCycleDiGraph(visited, diGraph);
                if (potentialRes.isEmpty()) {
                    visited.remove(visited.size() - 1);
                } else {
                    return potentialRes;
                }
            }
            if(next.equals(visited.get(0))){
                visited.add(next);
                return visited;
            }
        }
        return new ArrayList<>();
    }



    /* ------------------- Path finding ------------------- */

    /**
     * Returns a path as from vertex 'u' to vertex 'v' in the graph 'G'
     * as a list of vertices if such a path exists, the empty list otherwise
     */
    public List<Vertex> findPath(Graph graph, Vertex u, Vertex v) {
        LinkedList<Vertex> path = new LinkedList<>();
        path.add(u);
        if(findPath(graph,u,v,path))
            return path;
        return new LinkedList<>();
    }

    private boolean findPath(Graph graph, Vertex u, Vertex v,LinkedList<Vertex> list){
        if(u.equals(v))
            return true;
        for(Vertex vertex : graph.adjacents(u)){
            if(list.contains(vertex))
                continue;
            list.add(vertex);
            if(findPath(graph, vertex, v, list))
                return true;
            list.removeLast();
        }
        return false;
    }

    /* ------------------- Root finding ------------------- */

    /**
     * Returns a root of the graph 'G' if
     * such root exists, null otherwise
     */
    public Optional<Vertex> findRoot(DiGraph diGraph) {
        for(Vertex vertex : diGraph.vertices()){
            boolean res = true;
            for(Vertex other : diGraph.vertices()){
                if(!other.equals(vertex) && (!findPath(diGraph,other,vertex).isEmpty() || findPath(diGraph,vertex,other).isEmpty())) {
                    res = false;
                    break;
                }
            }
            if(res) {
                return Optional.of(vertex);
            }
        }
        return Optional.empty();
    }


    public double computeDistanceOfPath(List<Vertex> path, AbstractGraph graph) {
        double res = 0;
        for(int i = 0; i < path.size()-1;i++){
            res += graph.findEdge(path.get(i),path.get(i+1)).weight();
        }
        return res;
    }

    ///////////////

}
