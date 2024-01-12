package problem5;

public class Time implements Comparable<Time>{
	int hour, min;
	
	public Time() {
		
	}
	
	public Time(int hour, int min){
		this.hour = hour;
		this.min = min;
	}

	@Override
	public int compareTo(Time t) {
		// TODO Auto-generated method stub
		if (this.hour > t.hour) return 1;
		if (this.hour < t.hour) return -1;
		if (this.hour == t.hour) {
			if(this.min > t.min) return 1;
			if(this.min < this.min) return -1;
		}
		return 0;
	}
	
	public boolean equals(Time t) {
		return this.hour == t.hour && this.min == t.min;
	}

	@Override
	public String toString() {
		return "Time [hour = " + hour + ", min = " + min + "]";
	}
	
}
