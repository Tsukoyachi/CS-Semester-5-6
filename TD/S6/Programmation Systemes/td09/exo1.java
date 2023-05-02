import java.lang.management.ManagementFactory;

public class Exo1 {
    static {
    }

    public static void main(String args[]) {
        //First Method
        RuntimeMXBean runtimeBean = ManagementFactory.getRuntimeMXBean();
        long pid1 = ManagementFac
        //Second Method
        long pid2 = ProcessHandle.current().pid();
        System.out.println();
    }
}