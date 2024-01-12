package problem2;

public class TestMove {
	public static void main(String[] args) {
		
		Points p = new Points(2, 3);
		
		p.fastDown();
		System.out.println(p);

		p.fastLeft();
		System.out.println(p);
		
		p.fastUp();
		System.out.println(p);
		
		p.fastRight();
		System.out.println(p);
	}
}