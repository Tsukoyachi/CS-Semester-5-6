public class Exo1 {
    static {
        System.out.print("Loading Hello World native library...");
        System.loadLibrary("HelloWorld");
        System.out.println("done.");
    }
}