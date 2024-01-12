package problem5;

public class Chocolate implements Comparable <Chocolate>{
	private double weight;
	private String name;
	
	public Chocolate(double w, String n) {
		this.weight = w;
		this.name = n;
	}
	public double getWeight() {
		return weight;
	}

	public void setWeight(double weight) {
		this.weight = weight;
	}
	
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	@Override
	public int compareTo(Chocolate o) {
		// TODO Auto-generated method stub
		if (this.weight > o.weight) return 1;
		if (this.weight < o.weight) return -1;
		if (this.weight == o.weight) {
			return this.getName().compareTo(o.getName());
		}
		return 0;
	}
	
	@Override
	public String toString() {
		return "Chocolate [weight = " + weight + ", name = " + name + "]";
	}

	

}
