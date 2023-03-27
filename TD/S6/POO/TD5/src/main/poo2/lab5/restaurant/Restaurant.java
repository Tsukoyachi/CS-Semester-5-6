package main.poo2.lab5.restaurant;

public class Restaurant {
    private double latitude;
    private double longitude;
    private String name;
    private String address;
    private String city;
    private String state;
    private String phone;

    public Restaurant(double latitude, double longitude, String name, String address, String city, String state, String phone) {
        this.latitude = latitude;
        this.longitude = longitude;
        this.name = name;
        this.address = address;
        this.city = city;
        this.state = state;
        this.phone = phone;
    }

    public Restaurant() {
    }

    public double latitude() {
        return latitude;
    }

    public void setLatitude(double latitude) {
        this.latitude = latitude;
    }

    public double longitude() {
        return longitude;
    }

    public void setLongitude(double longitude) {
        this.longitude = longitude;
    }

    public String name() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String address() {
        return address;
    }

    public void setAddress(String adress) {
        this.address = adress;
    }

    public String city() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String state() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public String phone() {
        return phone;
    }

    public void setPhone(String phoneNumber) {
        this.phone = phoneNumber;
    }

    @Override
    public String toString() {
        return "Restaurant{latitude="+latitude+",longitude="+longitude+
                ",name="+name+",address="+address+",city="+city+",state="+state+
        ",phone="+phone+"}";
    }
}
