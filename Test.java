import java.util.Random;
import java.util.Scanner;

;// The main public class that contains psvm. Both threads must be created and run from he

public class Test {
	public static int n;

	public static void main (String args[]) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter N");
		n = scanner.nextInt();
		Plate p = new Plate();
		Tom t = new Tom(p);
		Jerry j = new Jerry(p);

		t.start();
		j.start();
	}
	
}

class Plate {

	String [] s = {"KitKat","Mars","DailyMilk","Twix","Toblerone"};
	String n;
	private static Random rand;
	public Plate(){
		Plate.rand = new Random();
	}
	
	boolean avail=false;

	void waitForEmptyPlate(){
		while (avail) {
				
		};
	}	

	void waitForChocolate() throws InterruptedException {
		while (!avail) {
			Thread.sleep(100);
		};
	}
	
	 void eatChoco(int i) throws InterruptedException {
		waitForChocolate();
		// Once avail is true
		// wait a random amount of time (< 2 seconds) and then eat the new choco...
		if(avail) {
			Thread.sleep(2000);
			System.out.println(i+": Jerry: eats up the "+n);
			avail = false;
			System.out.println(i+": Jerry: slips back into the hole...");
			synchronized (n){
				n.notify();
			}
		}

		// Inform (notify) the other thread that you're done
	}

	void placeChoco(int i) throws InterruptedException {

		if(!avail) {
			int chocIndex = rand.nextInt(s.length);
			System.out.println(i + ": Tom: puts a " + s[chocIndex] + " on the table and turns back...");
			n=s[chocIndex];
//			waitForEmptyPlate();
			avail = true;

			synchronized (n){
				n.wait();
			}
			Thread.sleep(1000);
			// Wait a random amount of time (< 2 seconds) before putting another choco on the table...
			// Choose a random chocolate to put on the plate...

			System.out.println(i + ": Tom: closes the fridge door, turns and sees the empty plate...");
			// Inform (notify) the other thread that you're done
			synchronized (n){
				n.notifyAll();
			}
		}
	}

}

class Tom extends Thread {
	Plate p;

	public Tom(Plate p) {
		this.p=p;

	}
	// Your implementation of public void run()
	public void run () {
	// repeat N times:
	// Any other code
		for (int i = 0; i < eem514_1801656_05a.n; i++) {
			try {
				System.out.println(i+": Tom: opens the fridge door");
				p.placeChoco(i);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	// Any other code
	}
}

class Jerry extends Thread {
	// Similar to Tom above
         Plate p;

	public Jerry(Plate p) {
		this.p=p;
	}

	// Your implementation of public void run()
	public void run () {
	// repeat N times:
	// Any other code
		for (int i = 0; i < n; i++) {
			try {
				System.out.println(i+": Jerry: peeks out of the hole");
				p.eatChoco(i);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	// Any other code
	}
}
