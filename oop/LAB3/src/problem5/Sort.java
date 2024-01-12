package problem5;

public class Sort {
	
	static <E> void swap(E [] arr, int i, int j) {
		E cur = arr[i - 1];
		arr[i - 1] = arr[i];
		arr[i] = cur;
	}
	
	static <E extends Comparable <E> > void bubbleSort(E [] arr){
		for (int i = arr.length; i > 1; i--) {
			for (int j = 1; j < i; j++) {
				if (arr[j-1].compareTo(arr[j]) > 0) {
					swap(arr, j, j - 1);
				}
			}
		}
	}
	
//  used when Java generics just don't let you do what you want to
	 @SuppressWarnings("unchecked")
	 
	
	static <E extends Comparable <E> > void merge(E [] arr, int l, int mid, int r) {
		
		E[] left  = (E[]) new Comparable[mid - l + 1]; // an array with size mid - l + 1
        E[] right = (E[]) new Comparable[r - mid]; // an array with size mid - r
	
//		filling an array left with elements of arr starting from l + i index        
       for (int i = 0; i < left.length; ++i) {
       		left[i] = arr[l + i];
       }
       
//		filling an array right with elements of arr starting from mid + 1 + i
       for (int i = 0; i < right.length; ++i) {
           right[i] = arr[mid + 1 + i];
       }
       
       int l_ind = 0, r_ind = 0;
       int cur = l;
       
       while (l_ind < left.length && r_ind < right.length) {
    	   
    	   if (left[l_ind].compareTo(right[r_ind]) <= 0) {
    		   arr[cur] = left[l_ind];
    		   l_ind++;
    	   } else {
    		   arr[cur] = right[r_ind];
    		   r_ind++;
    	   }
    	   cur++;
    	   
       }
//     adding the rest of elements after finishing going through one of arrays 
       
       while (l_ind < left.length) {
       	arr[cur] = left[l_ind];
       	cur++; l_ind++;
       }
       
       while (r_ind < right.length) {
       	arr[cur] = right[r_ind];
       	cur++; r_ind++;
       }
	}
	
		
	static <E extends Comparable <E> > void mergeSort(E [] arr, int l, int r) {
		if (l < r) {
			int mid = (l + r) / 2;
			mergeSort (arr, l, mid);
			mergeSort(arr, mid + 1, r);
			merge(arr, l, mid, r);
		}
	}
}
