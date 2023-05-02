import java.lang.management.ManagementFactory;
import java.lang.management.RuntimeMXBean;

public class exo1 {
    public native static int getPid();

    static {
        System.out.print("Loading Pid native library...");
        System.loadLibrary("PidLibrary");
        System.out.println("done.");
    }

    public static void main(String args[]) {
        //First Method
        RuntimeMXBean runtimeBean = ManagementFactory.getRuntimeMXBean();
        String jvmName = runtimeBean.getName();
        long pid1 = Long.valueOf(jvmName.split("@")[0]);
        System.out.println("First method PID : "+pid1);
        //Second Method
        long pid2 = ProcessHandle.current().pid();
        System.out.println("Second method PID : "+pid2);
        //Our library
        long pid3 = getPid();
        System.out.println("Third method PID :"+pid3);
    }
}