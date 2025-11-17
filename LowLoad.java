public class LowLoad {

    public static void main(String[] args) {

        long sum = 0;
        long n = 984600000L;

        System.out.println("Program starting...");
        
        long start = System.nanoTime();
        System.out.printf("Start time: %.3f\n", start / 1_000_000_000.0);

        for (long i = 1; i <= n; i++) {
            sum += i;
        }

        long end = System.nanoTime();

        System.out.printf("End time: %.3f\n", end / 1_000_000_000.0);

        double elapsedSeconds = (end - start) / 1_000_000_000.0;
        System.out.printf("Time elapsed: %.8f seconds\n", elapsedSeconds);
        System.out.printf("Sum: %d", sum);
        System.out.flush();
    }
}
