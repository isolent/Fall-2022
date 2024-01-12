package problem5;

public class TestSort {
	public static void main(String[] args) {
		
		Chocolate choco[] = new Chocolate[6];
		Time ttt[] = new Time[6];
		
		
		Chocolate a = new Chocolate(100, "SNICKERS");
		Chocolate b = new Chocolate(120, "KITKAT");
		Chocolate c = new Chocolate(110, "MARS");
		Chocolate d = new Chocolate(100, "RAFAELLO");
		Chocolate e = new Chocolate(115, "MERSI");
		Chocolate f = new Chocolate(140, "KINDER");
		
		Time g = new Time(12, 55);
		Time h = new Time(11, 45);
		Time m = new Time(10, 30);
		Time j = new Time(9, 50);
		Time k = new Time(13, 45);
		Time l = new Time(12, 30);
		
		ttt[0] = g;
		ttt[1] = h;
		ttt[2] = m;
		ttt[3] = j;
		ttt[4] = k;
		ttt[5] = l;

		choco[0] = a;
		choco[1] = b;
		choco[2] = c;
		choco[3] = d;
		choco[4] = e;
		choco[5] = f;
		
		Sort.bubbleSort(ttt);
		Sort.mergeSort(choco, 0, 5);

		for(int i = 0; i < choco.length; i++) {
			System.out.println(choco[i].toString());
		}
		
		System.out.print("\n");
		
		for(int i = 0; i < ttt.length; i++) {
			System.out.println(ttt[i].toString());
		}
	}
}
