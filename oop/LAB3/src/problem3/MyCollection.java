package problem3;

public interface MyCollection {
	  public boolean isEmpty();
	  public void remove(Object o);
	  public void push(Object o);  
	  public void pushAll(MyCollection o);
	  public void removeAll(Object o);
	  public boolean contains(Object o);
	  public boolean equals(Object o);
	  public int hashCode();
	  public int size();
	  public void clear();
}
