package endterm;

import java.util.Objects;


public class Buyer extends Person implements Comparable<Buyer>{
	
	private String name;
	private int age;
	private String city;
	boolean register = false;

	public Buyer(String name, int age, String city) {
		this.name = name;
		this.age = age; 
		this.city = city;
	}
	

	public String getCity() {
		return city;
	}
	
	public void setCity(String city) {
		this.city = city;
	}
	
	public int getAge() {
		return age;
	}
	
	public void setAge(int age) {
		this.age = age;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	
	public void registerForFlight(){
		 register = true;
	}
	
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o != null || !(o instanceof Buyer)) return false;
		Buyer other = (Buyer) o;
		return this.name.equals(other.name)
				&& Objects.equals(city, other.city);
	}


	public String toString() {
		return "Buyer [name=" + name + ", age=" + age + ", city=" + city + "]";
	}
	
	public Object clone() throws CloneNotSupportedException {
		Buyer b = (Buyer)super.clone();
		return b;

	}


	@Override
	public int compareTo(Buyer o) {
		// TODO Auto-generated method stub
		if (this.age > o.age) return 1;
		if (this.age < o.age) return -1;
		return 0;
	}


	@Override
	public boolean canBuyTicket() {
		// TODO Auto-generated method stub
		return true;
	}
	
}
