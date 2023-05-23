package graphs.roadApplication;

import graphs.UnDiGraph;

import java.util.List;

public interface MapOfCitiesInterface {
    public List<City> getCities();
    public City getCity(String name);
    public List<City> shortestPath(City from, City to);
    public UnDiGraph buildMap(List<City> cities, double precision);
}
