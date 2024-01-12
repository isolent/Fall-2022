package streams;
import java.util.*;
public class StringTokenizerExample {

	public static void main(String[] args) {
		 StringTokenizer st = new StringTokenizer("1+2*45","+*/", true);
		 //3rd parameter of tokenizer indicated whether or not we need to 
		 //consider delimeters as tokens. Default: false
	     while (st.hasMoreTokens()) {
	         System.out.println(st.nextToken());
	     }

	     System.out.println();
	     StringTokenizer st2 = new StringTokenizer("A*B*Cc|cc", "*|");
	     while (st2.hasMoreTokens()) {
	         System.out.println(st2.nextToken());
	     }

	}

}
