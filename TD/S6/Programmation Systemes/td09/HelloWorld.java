/**
 * Created by lavirott on 13/05/2017, modified 27/04/2023.
 */
import java.util.Scanner;

public class HelloWorld {
    private int entier = 1;

    // Méthodes natives fournies grâce à une bibliothèque
    public static native void printCpp();
    public static native void printStringToCpp(String str);
    public native String stringFromCpp();
    public native void callJavaMethod();
    public native String toString();
    public static native int fib(int n);

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
        HelloWorld hello = new HelloWorld();
        String generated = hello.stringFromCpp();
        printStringToCpp(generated);

        System.out.println("\nNow let's call a java method directly inside c code :");
        hello.callJavaMethod();

        System.out.println("\nNow let's access, print and modify object field inside c code :");
        //Ici on l'incrémente également de 1 même si c'est pas conventionnel, le but étant de voir comment on fait les 2
        printStringToCpp(hello.toString());

        System.out.println("\nLet's try implementing fibonacci in C :");
        printStringToCpp("Result of fibonacci with n = 5 : "+fib(5));

        Scanner sc = new Scanner(System.in);
        System.out.println("Veuillez appuyer sur Entrée pour terminer le programme...");
        sc.nextLine();
        sc.close();
    }
}
