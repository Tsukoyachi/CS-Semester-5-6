package graphs.roadApplication;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.*;



class CityParser {
  private int currentChar;
  private final StringBuilder buffer = new StringBuilder();
  private final BufferedReader b;

  public CityParser(String name) {
    try {
      if (name.startsWith("http://"))
        b = new BufferedReader(new InputStreamReader(
          new URL(name).openStream(), StandardCharsets.UTF_8));
      else
        b = new BufferedReader(new InputStreamReader(new FileInputStream(name),
                StandardCharsets.UTF_8));
    } catch (IOException e) {
      throw new IllegalArgumentException("unreadable file", e);
    }
  }

  public static List<City> removeDuplicates(List<City> cities) {
     HashMap<String, List<City> > map = new HashMap<>();

      for (City c : cities) {
          if (!map.containsKey(c.getNom())){
              map.put(c.getNom(), new ArrayList<>());
          }
          map.get(c.getNom()).add(c);
      }

      for (String key : map.keySet()) {
          List<City> list = map.get(key);
          if (list.size() > 1) {
              list.sort(Comparator.comparing(City::getDate).reversed());
              map.put(key,list.subList(0, 1));
          }
      }
      return map.values().stream().flatMap(Collection::stream).toList();
  }

  private void skipToEOL() throws IOException {
    while (currentChar != -1 && "\r\n".indexOf(currentChar) == -1) {
      currentChar = b.read();
    }
    while (currentChar != -1 && "\r\n".indexOf(currentChar) != -1)
      currentChar = b.read();
  }

  private void skipNextField() throws IOException {
    while ("\t\f".indexOf(currentChar) == -1) {
      currentChar = b.read();
    }
    currentChar = b.read();
  }

  private double readDouble() throws IOException {
    int d = 0;
    int sign = 1;
    if (currentChar == '-') {
      sign = -1;
      currentChar = b.read();
    }
    while (currentChar <= '9' && currentChar >= '0') {
      d = 10 * d + (currentChar - '0');
      currentChar = b.read();
    }
    if (currentChar != '.') {
      currentChar = b.read();
      return (double)sign * d;
    }
    currentChar = b.read();
    int dot = 1;
    while (currentChar <= '9' && currentChar >= '0') {
      d = 10 * d + (currentChar - '0');
      dot *= 10;
      currentChar = b.read();
    }
    currentChar = b.read();
    return sign * d / (double) dot;
  }

  private String readString() throws IOException {
    buffer.setLength(0);
    // On saute les espaces mais on a aussi besoin de garder les fins de ligne (nouveau)
    while ("\t\f\n".indexOf(currentChar) == -1) {
      buffer.append((char) currentChar);
      currentChar = b.read();
    }
    return buffer.toString();
  }

  public void readAll(Collection<City> cities) {
    try {
      skipToEOL(); // On saute la ligne d entete
      do {
        skipNextField(); // RC : Region font code
        skipNextField(); // UFI : Unique feature identifier
        // double id = readDouble(); //UNI : Unique name identifier
        readDouble(); // UNI : Unique name identifier
        double latitude = readDouble();
        double longitude = readDouble();
        skipNextField(); // DMS_LAT
        skipNextField(); // DMS_LONG
        skipNextField(); // UTM : Universal transverse Mercator
        skipNextField(); // JOG : Joint operations Graphic reference
        if (currentChar != 'P') {
          skipToEOL();
          continue;
        }
        skipNextField(); // FC : Feature classification
        skipNextField(); // DSG : Feature designation code
        skipNextField(); // PC : Populated place classification
        skipNextField(); // CC1 : Primary coutry code
        skipNextField(); // DSG : Feature designation code
        skipNextField(); // ADM1 : First order administrative division code
        skipNextField(); // ADM2
        skipNextField(); // DIM : Dimension
        skipNextField(); // CC2
        skipNextField(); // NT : Name type
        skipNextField(); // LC : Language code
        skipNextField(); // SHORT_FORM
        skipNextField(); // GENERIC NAME
        skipNextField(); // SHORT_NAME
        String nom = readString(); // FULL_NAME
        skipNextField(); //FULL_NAME_ND
        //Attention modification par rapport au fichier original pour gérer les dates
        String date = readString(); // MODIFY_DATE
        skipToEOL();
        cities.add(new City(nom, latitude, longitude, date));
      } while (currentChar != -1);
      b.close();
    } catch (IOException e) {
      System.out.println("Erreur de lecture");
      try {
        b.close();
      } catch (IOException e1) {/* nothing */
      }
      throw new IllegalArgumentException("invalid file", e);
    }
  }

}
