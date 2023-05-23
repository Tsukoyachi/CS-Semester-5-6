package graphs.roadApplication;

import graphs.DuplicateTagException;
import graphs.UnDiGraph;
import graphs.Vertex;
import graphs.tools.ORIGIN.GraphTraversal;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class RoadMap implements MapOfCitiesInterface {

    public static String basePath = "resources/";
    public static double baseDistance = 12000;
    private UnDiGraph map;
    private List<City> cities = new ArrayList<>();

    /**
     * Build a RoadMap by using the file fr.txt
     */
    public RoadMap(String path, double distance) {
        CityParser cp = new CityParser(path + "fr.txt");
        cp.readAll(cities);
        this.cities = CityParser.removeDuplicates(cities);
        this.map = this.buildMap(cities, distance);
    }

    public RoadMap(int distance) {
        this(basePath, distance);
    }

    public RoadMap(String path) {
        this(path, baseDistance);
    }

    public RoadMap() {
        this(basePath, baseDistance);
    }

    @Override
    public List<City> getCities() {
        return cities;
    }

    @Override
    public City getCity(String name) {
        return cities
                .stream()
                .filter(e -> e.getNom().equals(name)).findFirst().orElse(null);
    }

    @Override
    public List<City> shortestPath(City from, City to) {
        return GraphTraversal.dijkstra(this.map, this.map.getVertex(from.getNom()), this.map.getVertex(to.getNom()))
                .stream()
                .map(e -> this.getCity(e.getTag()))
                .toList();
    }

    public UnDiGraph getMap(){
        return this.map;
    }

    @Override
    public UnDiGraph buildMap(List<City> cities, double precision) {
        UnDiGraph graph = new UnDiGraph();
        List<City> added = new ArrayList<>(this.cities.size());
        for (City city : cities) {
            try {
                graph.addVertex(city.getNom());
                if(city.getNom().equals("Marseille")){
                    System.out.println("Added !!!!!!");
                }
                for(City tmp : added){
                    double distance = tmp.distance(city);
                    if(distance<=precision){
                        graph.addEdge(graph.getVertex(city.getNom()),graph.getVertex(tmp.getNom()),distance);
                    }
                }
                added.add(city);
            } catch (DuplicateTagException ignored) {
                /* Do Nothing */
            }

        }
        return graph;
    }
}
