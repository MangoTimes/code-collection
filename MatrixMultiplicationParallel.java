
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Random;

class ParallelThreadsCreator {
    private int threads;
    public ParallelThreadsCreator(int threads){
        this.threads = threads;
    }

    // creating 10 threads and waiting for them to complete then again repeat steps.
    public void multiply(int[][] matrix1, int[][] matrix2, int[][] result) {
        ArrayList threads = new ArrayList<Thread>();
        int rows1 = matrix1.length;
        for (int i = 0; i < rows1; i++) {
            RowMultiplyWorker task = new RowMultiplyWorker(result, matrix1, matrix2, i);
            Thread thread = new Thread(task);
            thread.start();
            threads.add(thread);
            if (threads.size() % this.threads == 0) {
                waitForThreads(threads);
            }
        }
    }


    private static void waitForThreads(ArrayList<Thread> threads) {
        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        threads.clear();
    }
}
class RowMultiplyWorker implements Runnable {

    private final int[][] result;
    private int[][] matrix1;
    private int[][] matrix2;
    private final int row;

    public RowMultiplyWorker(int[][] result, int[][] matrix1, int[][] matrix2, int row) {
        this.result = result;
        this.matrix1 = matrix1;
        this.matrix2 = matrix2;
        this.row = row;
    }

    @Override
    public void run() {

        for (int i = 0; i < matrix2[0].length; i++) {
            result[row][i] = 0;
            for (int j = 0; j < matrix1[row].length; j++) {
                result[row][i] += matrix1[row][j] * matrix2[j][i];

            }

        }

    }

}

public class MatrixMultiplicationParallel {

    public static void main(String[] args) {

        for (int i = 1; i <= 10; i++) {

            Date start = new Date();

            int[][] m1 = generateMatrix(10*i);
            int[][] m2 = generateMatrix(10*i);

            int[][] result = new int[m1.length][m2[0].length];
            ParallelThreadsCreator parallelThreadsCreator = new ParallelThreadsCreator(i*2);
            parallelThreadsCreator.multiply(m1, m2, result);

            Date end = new Date();
            System.out.println("\nTime taken in milli seconds: " + (end.getTime() - start.getTime()) + " For "+(10*i)+"x"+(10*i)+" threads : "+(5));
        }
    }

    private static int[][] generateMatrix(int n){
        int[][] m = new int[n][n];
        Random rand = new Random();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j]=rand.nextInt(100);
            }
        }
        return m;
    }

}
