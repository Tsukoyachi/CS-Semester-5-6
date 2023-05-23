package graphs.roadApplication;

import graphs.tools.ORIGIN.ConnectedComponents;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

class CityParserTest {

    String path = "resources/";


    @Test
    void readAllAndRemove() {
        //UnDiGraph.LOGGER.setLevel(java.util.logging.Level.FINE);
        CityParser cp = new CityParser(path + "fr.txt");
        List<City> cities = new ArrayList<>();
        cp.readAll(cities);

        List<City> afterRemoving = CityParser.removeDuplicates(cities);

        //Testing reading the cities
        assertTrue(afterRemoving.stream().anyMatch(city -> city.getNom().equals("Nice")));
        assertTrue(afterRemoving.stream().anyMatch(city -> city.getNom().equals("Valbonne")));
        assertTrue(afterRemoving.stream().anyMatch(city -> city.getNom().equals("Biot")));
        assertFalse(afterRemoving.stream().anyMatch(city -> city.getNom().equals("Sophia Antipolis")));
        assertTrue(afterRemoving.stream().anyMatch(city -> city.getNom().equals("Antibes")));

        City nice = getCity(afterRemoving, "Nice");
        City cagnes = getCity(afterRemoving, "Cagnes-sur-Mer");
        City villeneuve = getCity(afterRemoving, "Villeneuve-Loubet");
        City valbonne = getCity(afterRemoving, "Valbonne");
        City biot = getCity(afterRemoving, "Biot");
        City antibes = getCity(afterRemoving, "Antibes");
        City paris = getCity(afterRemoving, "Paris");
        City sainte_foy = getCity(afterRemoving, "Saint-Foy");
        City laMadeleine = getCity(afterRemoving, "La Madeleine");
        City Laroque = getCity(afterRemoving, "Laroque");
        City saintJean = getCity(afterRemoving, "Saint-Jean");
        City marseille = getCity(afterRemoving, "Marseille");
        City saint_raphael = getCity(afterRemoving, "Saint-Raphael");
        City toulon = getCity(afterRemoving, "Toulon");
        //   System.out.println("Saint-Philippe :" + saint_philippe);
        System.out.println("------------- VILLES --------------");
        System.out.println("Nice:" + nice);
        assertEquals(43.5, nice.getLatitude(),0.5);
        assertEquals(7.25, nice.getLongitude(),0.5);
        System.out.println("Cagnes:" + cagnes);
        System.out.println("Villeneuve:" + villeneuve);
        System.out.println("Biot:" + biot);
        System.out.println("Valbonne:" + valbonne);
        System.out.println("Antibes:" + antibes);
        System.out.println("Paris:" + paris);
        System.out.println("La Madeleine :" + sainte_foy);
        System.out.println("Laroque :" + Laroque);
        System.out.println("Saint-Jean (Roquette sur Siagnes!:" + saintJean);
        System.out.println("Saint-Foy :" + sainte_foy);
        System.out.println("Marseille :" + marseille);
        assertEquals(43, marseille.getLatitude(),0.5);
        assertEquals(5, marseille.getLongitude(),0.5);
        System.out.println("Saint-Raphael :" + saint_raphael);
        assertEquals(43, saint_raphael.getLatitude(),0.5);
        assertEquals(6.9, saint_raphael.getLongitude(),0.5);
        System.out.println("Toulon :" + toulon);
        assertEquals(43.1, toulon.getLatitude(),0.5);
        assertEquals(5.9, toulon.getLongitude(),0.5);
        System.out.println("------------- Distances --------------");
        assertEquals(0, nice.distance(nice),0.5);
        double distance = nice.distance(cagnes);
        System.out.println("De Nice à Cagnes :" + distance);
        assertEquals(11, distance/1000,2);
        distance = cagnes.distance(villeneuve);
        System.out.println("De Cagnes à Villeneuve :" + distance);
        assertEquals(5, distance/1000,2);
        System.out.println("De Villeneuve à Antibes :" + villeneuve.distance(antibes));
        System.out.println("De Antibes à Biot :" + antibes.distance(biot));
        System.out.println("De Biot à Valbonne :" + biot.distance(valbonne));
        System.out.println("De Valbonne à Biot :" + valbonne.distance(biot));
        distance = nice.distance(toulon);
        System.out.println("De Nice à Toulon :" + distance);
        //Too much.... perhaps problem with the data
        assertEquals(150, distance/1000,20);

        System.out.println("De Nice à Marseille :" + nice.distance(marseille));

        System.out.println("De Nice à Saint-Foy :" + nice.distance(sainte_foy));
        System.out.println("De Nice à Valbonne :" + nice.distance(valbonne));
        System.out.println("De Biot à Valbonne :" + biot.distance(valbonne));
        System.out.println("De Nice à Biot :" + nice.distance(biot));
        System.out.println("De Nice à La Madeleine :" + nice.distance(laMadeleine));
        System.out.println("De La Madeleine à Laroque :" + laMadeleine.distance(Laroque));

        System.out.println("De Valbonne à Paris :" + valbonne.distance(paris));
        System.out.println("De Nice à Paris :" + nice.distance(paris));
        System.out.println("De Nice à Marseille :" + nice.distance(marseille));
        assertTrue(nice.distance(marseille) < 220000);
        System.out.println("De Marseille à Saint-Raphael :" + marseille.distance(saint_raphael));
        System.out.println("De Saint-Raphael à Saint-Jean :" + saint_raphael.distance(saintJean));

    }

    @Test
    void readAllAndTestFromRoadMap() {
        RoadMap road = new RoadMap(path,12000);

        //Testing reading the cities
        assertNotNull(road.getCity("Nice"));
        assertNotNull(road.getCity("Valbonne"));
        assertNotNull(road.getCity("Biot"));
        assertNotNull(road.getCity("Biot"));
        assertNull(road.getCity("Sophia Antipolis"));
        assertNotNull(road.getCity("Antibes"));

        City nice = road.getCity("Nice");
        City cagnes = road.getCity( "Cagnes-sur-Mer");
        City villeneuve = road.getCity( "Villeneuve-Loubet");
        City valbonne = road.getCity( "Valbonne");
        City biot = road.getCity( "Biot");
        City antibes = road.getCity("Antibes");
        City paris = road.getCity("Paris");
        City sainte_foy = road.getCity("Saint-Foy");
        City laMadeleine = road.getCity("La Madeleine");
        City Laroque = road.getCity("Laroque");
        City saintJean = road.getCity("Saint-Jean");
        City marseille = road.getCity("Marseille");
        City saint_raphael = road.getCity("Saint-Raphael");
        City toulon = road.getCity("Toulon");
        //   System.out.println("Saint-Philippe :" + saint_philippe);
        System.out.println("------------- VILLES --------------");
        System.out.println("Nice:" + nice);
        assertEquals(43.5, nice.getLatitude(),0.5);
        assertEquals(7.25, nice.getLongitude(),0.5);
        System.out.println("Cagnes:" + cagnes);
        System.out.println("Villeneuve:" + villeneuve);
        System.out.println("Biot:" + biot);
        System.out.println("Valbonne:" + valbonne);
        System.out.println("Antibes:" + antibes);
        System.out.println("Paris:" + paris);
        System.out.println("La Madeleine :" + sainte_foy);
        System.out.println("Laroque :" + Laroque);
        System.out.println("Saint-Jean (Roquette sur Siagnes!:" + saintJean);
        System.out.println("Saint-Foy :" + sainte_foy);
        System.out.println("Marseille :" + marseille);
        assertEquals(43, marseille.getLatitude(),0.5);
        assertEquals(5, marseille.getLongitude(),0.5);
        System.out.println("Saint-Raphael :" + saint_raphael);
        assertEquals(43, saint_raphael.getLatitude(),0.5);
        assertEquals(6.9, saint_raphael.getLongitude(),0.5);
        System.out.println("Toulon :" + toulon);
        assertEquals(43.1, toulon.getLatitude(),0.5);
        assertEquals(5.9, toulon.getLongitude(),0.5);
        System.out.println("------------- Distances --------------");
        assertEquals(0, nice.distance(nice),0.5);
        double distance = nice.distance(cagnes);
        System.out.println("De Nice à Cagnes :" + distance);
        assertEquals(11, distance/1000,2);
        distance = cagnes.distance(villeneuve);
        System.out.println("De Cagnes à Villeneuve :" + distance);
        assertEquals(5, distance/1000,2);
        System.out.println("De Villeneuve à Antibes :" + villeneuve.distance(antibes));
        System.out.println("De Antibes à Biot :" + antibes.distance(biot));
        System.out.println("De Biot à Valbonne :" + biot.distance(valbonne));
        System.out.println("De Valbonne à Biot :" + valbonne.distance(biot));
        distance = nice.distance(toulon);
        System.out.println("De Nice à Toulon :" + distance);
        //Too much.... perhaps problem with the data
        assertEquals(150, distance/1000,20);

        System.out.println("De Nice à Marseille :" + nice.distance(marseille));

        System.out.println("De Nice à Saint-Foy :" + nice.distance(sainte_foy));
        System.out.println("De Nice à Valbonne :" + nice.distance(valbonne));
        System.out.println("De Biot à Valbonne :" + biot.distance(valbonne));
        System.out.println("De Nice à Biot :" + nice.distance(biot));
        System.out.println("De Nice à La Madeleine :" + nice.distance(laMadeleine));
        System.out.println("De La Madeleine à Laroque :" + laMadeleine.distance(Laroque));

        System.out.println("De Valbonne à Paris :" + valbonne.distance(paris));
        System.out.println("De Nice à Paris :" + nice.distance(paris));
        System.out.println("De Nice à Marseille :" + nice.distance(marseille));
        assertTrue(nice.distance(marseille) < 220000);
        System.out.println("De Marseille à Saint-Raphael :" + marseille.distance(saint_raphael));
        System.out.println("De Saint-Raphael à Saint-Jean :" + saint_raphael.distance(saintJean));

        assertNotNull(road.shortestPath(road.getCity("Marseille"),road.getCity("Nice")));
        System.out.println("Marseil->Nice : "+road.shortestPath(road.getCity("Marseille"),road.getCity("Nice")));

        ConnectedComponents connectedComponents = new ConnectedComponents(road.getMap());
        int numberOfSubGraph = connectedComponents.find().values().stream().max(Comparator.naturalOrder()).get();
        assertEquals(12,numberOfSubGraph);
        System.out.println("Number of subgraph : "+numberOfSubGraph);
    }

    private static City getCity(List<City> cities, String Biot) {
        return cities.stream().filter(city -> city.getNom().equals(Biot)).findFirst().orElse(null);
    }

}