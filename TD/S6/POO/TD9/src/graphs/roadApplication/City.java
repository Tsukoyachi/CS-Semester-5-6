package graphs.roadApplication;

import java.util.Objects;

public class City {

    private final String nom;

    public String getDate() {
        return date;
    }

    private final String date;

    // -180 < long < 180
    // -90 < lat < 90
    private final double latitude;
    private final double longitude;
    static int precision=2;

    public City(String s, double lat, double longi, String dateOfModification) {
        nom = s;
        latitude = lat;
        longitude = longi;
        date = dateOfModification;
    }
    public City(String s, double lat, double longi) {
        this(s,lat,longi,"0");
    }
    public String toString() {
        return nom+"\tLatitude: "+latitude+"\t"+"Longitude: "+longitude;
    }

    public String getNom() {
        return nom;
    }

    public double getLatitude() {
        return latitude;
    }

    public double getLongitude() {
        return longitude;
    }

    private long getRoundLatitude() {
        return Math.round(latitude*(Math.pow(10.,precision)));
    }

    private long getRoundLongitude() {
        return Math.round(longitude*(Math.pow(10.,precision)));
    }

    private int tLat(double latitude, double latmin, double latmax, int h) {
        return h-(int) ((latitude-latmin)/(latmax-latmin)*h);
    }
    private int tLong(double longitude, double lonmin, double lonmax, int w) {
        return (int) ((longitude-lonmin)/(lonmax-lonmin)*w);
    }


    private double sqr(double a) {
        return a*a;
    }

    // distance entre deux villes en mètres
    public double distance(City dest) {
        // utilise la distance ellipsoidale de vincenty
        double R = 6371000; // rayon de la terre
        return R*Math.sqrt(sqr((getLatitude()-dest.getLatitude()))+sqr((getLongitude()-dest.getLongitude())))/180.0*Math.PI;
    }



    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        City city = (City) o;
        return Double.compare(city.latitude, latitude) == 0 && Double.compare(city.longitude, longitude) == 0 && Objects.equals(nom, city.nom);
    }

    public int hashCode(){
        long x=getRoundLatitude();
        long y=getRoundLongitude();
        return (int) ((x*(29*(Math.pow(10.,precision)))+y)%Integer.MAX_VALUE);
    }
}

