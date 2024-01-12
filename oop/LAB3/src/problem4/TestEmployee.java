package problem4;

import java.util.Collections;
import java.util.Vector;

public class TestEmployee {

	public static void main(String[] args) throws CloneNotSupportedException {
		// TODO Auto-generated method stub
		Manager m = new Manager("H", 420000, "1234", 1000);
		Manager m2 = new Manager("B", 450000, "1236", 1500);
		Manager m3 = new Manager("C", 420000, "1234", 1800);
		
//		System.out.print(m.toString());
		
		Vector<Employee> employees = new Vector<Employee>();
		
		employees.add(m);
		employees.add(m2);
		employees.add(m3);
		
		System.out.println(m.compareTo(m2));
 		
		Manager copy = m; // just reference
		copy.salary = 470000;
		
		//salary changes for both original object and copy
		System.out.println("OBJECT:"+m);
		System.out.println("COPY:"+m+"\n");

		for (Employee a : employees) {
			System.out.println(a.equals(copy) + "\n");
		}
		
		System.out.println("\n" + employees);
		
		Manager clone = (Manager)m.clone(); // clone
		clone.salary = 500000;
		
		//salary changes for clone only, because they are independent
		//reference types, e.g., date also will not be changed, because we did 
		//deep clone
		
		
		System.out.println(m.equals(copy) + "\n");
		System.out.println("OBJECT:"+m);
		System.out.println("CLONE:"+clone);

		Collections.sort(employees, new CompareByName());
		
		System.out.println("\n" + employees);
	}
}
