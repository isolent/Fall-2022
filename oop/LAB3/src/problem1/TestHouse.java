package problem1;
import java.util.Scanner;
public class TestHouse {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		House1 h1 = new House1(14, 10, 3.5);
		System.out.println(h1);
		double w = sc.nextInt();
		double l = sc.nextInt();
		double h = sc.nextInt();
		int  a = sc.nextInt();
		House2 h2 = new House2(w, l, h, a);
		System.out.println(h2.has());
		System.out.println(h2);
		sc.close();
	}
}