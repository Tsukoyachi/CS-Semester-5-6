package main.poo2.lab5.mcDo;

import main.poo2.lab5.restaurant.Restaurant;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

public class McDoReaderToFillTest {
    McDoReaderToFill mcDoReaderToFill;

    @BeforeEach
    void setup() throws IOException {
        mcDoReaderToFill = new McDoReaderToFill();
    }

    @Test
    void nbCitiesHaveMcDo() {
        assertEquals(4926,mcDoReaderToFill.nbCitiesHaveMcDo());
    }

    @Test
    void restaurantsInACity() {
        String[] mcdoNameExcepted = new String[]{"McDonalds-Oxford in AL", "McDonalds-Oxford in AL", "McDonalds-Oxford in MA", "McDonalds-Oxford in MI", "McDonalds-Oxford in MS", "McDonalds-Oxford in MS", "McDonalds-Oxford in NC", "McDonalds-Oxford in OH"};
        List<Restaurant> mcdoName = mcDoReaderToFill.restaurantsInACity("Oxford");
        List<String> mcdoNameExceptedList = Arrays.stream(mcdoNameExcepted).toList();

        assertEquals(mcdoNameExcepted.length,mcdoName.stream().filter(e-> mcdoNameExceptedList.contains(e.name())).count());
    }

    @Test
    void nbOfMcDoInACity() {
        assertEquals(135,mcDoReaderToFill.nbOfMcDoInACity("Houston"));
        assertEquals(124,mcDoReaderToFill.nbOfMcDoInACity("Chicago"));
        assertEquals(80,mcDoReaderToFill.nbOfMcDoInACity("Los Angeles"));
    }

    @Test
    void nbOfMcDoInState() {
        assertEquals(25,mcDoReaderToFill.nbOfMcDoInState("AK"));
    }

    @Test
    void cityHasMostMcDo() {
        assertEquals("Houston", mcDoReaderToFill.cityHasMostMcDo());
    }

    @Test
    void cityWithFewestMcDo() {
        assertEquals("Coshocton", mcDoReaderToFill.cityWithFewestMcDo());
    }

    @Test
    void cityListWithOneMcDo() {
        String[] citiesName = new String[]{"zionsville", "zion", "zillah", "zeeland", "zebulon", "zapata", "zachary", "yucaipa", "yreka", "york county", "yerington", "yemassee", "yelm", "yazoo city", "yarmouth"};
        List<String> exceptedCities = Arrays.asList(citiesName);
        List<String> cities = mcDoReaderToFill.cityListWithOneMcDo();
        assertArrayEquals(exceptedCities.toArray(), cities.toArray());
    }

    @Test
    void fourCitiesWithMostMcDo() {
        List<Map.Entry<String,Long>> entries = mcDoReaderToFill.fourCitiesWithMostMcDo();

        assertTrue(entries.stream().anyMatch(e -> e.getKey().equals("Houston") && e.getValue() == 135));
        assertTrue(entries.stream().anyMatch(e -> e.getKey().equals("Chicago") && e.getValue() == 124));
        assertTrue(entries.stream().anyMatch(e -> e.getKey().equals("Las Vegas") && e.getValue() == 84));
        assertTrue(entries.stream().anyMatch(e -> e.getKey().equals("Los Angeles") && e.getValue() == 80));
    }
}
