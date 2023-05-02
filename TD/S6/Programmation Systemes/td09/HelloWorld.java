/**
 * Created by lavirott on 13/05/2017, modified 27/04/2023.
 */
import java.util.Scanner;

public class HelloWorld {
    // Méthodes natives fournies grâce à une bibliothèque
    public static native void printCpp();
    public static native void printStringToCpp(String str);
    public static native String stringFromCpp();

    static {
        System.out.print("Loading Hello World native library...");
        System.loadLibrary("HelloWorld");
        System.out.println("done.");
    }

    public static void main(String args[]) {
        // Print from Java and from C/C++
        System.out.print("Hello ");
        HelloWorld.printCpp();

        System.out.println("\nLet's generate a string from c :");
        String generated = stringFromCpp();
        printStringToCpp(generated);

        Scanner sc = new Scanner(System.in);
        System.out.println("Veuillez appuyer sur Entrée pour terminer le programme...");
        sc.nextLine();
        sc.close();
    }
}
