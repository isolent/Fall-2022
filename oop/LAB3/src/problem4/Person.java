package problem4;

public class Person {
	private String name;
	
	public Person (String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public boolean equals(Object other){
		if (other == this) return true;
		if (other == null || !(other instanceof Person))return false; 
		Person otherPerson = (Person)other; 
		return (this.name.equals(otherPerson.name));
               
	}
	
	@Override
	public String toString() {
		return "name=" + name + "]";
	}	
}
