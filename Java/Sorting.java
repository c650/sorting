import java.util.ArrayList;

public class Sorting<T extends Comparable<T>> {
	public static <T extends Comparable<T>> void
	bubblesort(ArrayList<T> arr) {
		boolean c = true;
		while ( c && !(c = false))
			for (int j = 0 ; j < arr.size()-1 ; j++)
				if ( arr.get(j).compareTo( arr.get(j+1) ) > 0 && (c = true))
					arr.set(j, swap( arr.get(j+1), arr.set(j+1, arr.get(j)) ));
	}

	public static <T extends Comparable<T>> void
	insertionsort(ArrayList<T> arr) {
		for (int j = 1 ; j < arr.size() ; j++) {
			if (arr.get(j).compareTo(arr.get(j-1)) < 0) {
				T hold = arr.get(j);
				int k = j;
				while(k > 0 && arr.get(k-1).compareTo(hold) > 0)
					arr.set(k, arr.get(--k));

				arr.set(k, hold);
			} /* end if */
		} /* end for */
	}

	public static <T extends Comparable<T>> void
	selectionsort(ArrayList<T> arr) {
		for (int i = 0 ; i < arr.size() ; i++) {
			int min_pos = i;
			for (int j = i+1 ; j < arr.size() ; j++)
				min_pos = arr.get(j).compareTo(arr.get(min_pos)) < 0 ? j : min_pos;

			if (min_pos != i)
				arr.set(i, swap( arr.get(min_pos), arr.set(min_pos, arr.get(i)) ));

		} /* end for */
	}

	public static <T extends Comparable<T>> void
	mergesort(ArrayList<T> arr) {
		if (arr.size() == 2) {
			if (arr.get(0).compareTo(arr.get(1)) > 0)
				arr.set(0, swap( arr.get(1), arr.set(1, arr.get(0)) ));
		}
		if (arr.size() <= 2) return;

		ArrayList<T> left,right;
		left = new ArrayList<T>();
		right = new ArrayList<T>();

		for (int i = 0; i < arr.size()/2; i++)
			left.add(arr.get(i));
		for (int i = arr.size()/2; i < arr.size(); i++)
			right.add(arr.get(i));

		mergesort(left); mergesort(right);

		arr.clear();
		while (!left.isEmpty() && !right.isEmpty())
			if (left.get(0).compareTo(right.get(0)) < 0)
				arr.add(left.remove(0));
			else
				arr.add(right.remove(0));

		if (!left.isEmpty())
			arr.addAll(left);
		else if (!right.isEmpty())
			arr.addAll(right);

	}

	public static <T extends Comparable<T>> void
	quicksort(ArrayList<T> arr) {
		quicksort(arr, 0 , arr.size());
	}

	private static <T extends Comparable<T>> void
	quicksort(ArrayList<T> arr, int begin, int end) {
		if (end <= begin) return;

		T pivot = arr.get(end-1);
		int a = begin, b = end-1;

		while(b > a) {
			if ( arr.get(b-1).compareTo(pivot) > 0 ) {
				arr.set(b , arr.get(--b));
			} else {
				arr.set(a , swap(arr.get(b-1) , arr.set(b-1 , arr.get(a) ) ));
			}
		}

		arr.set(b, pivot);
		quicksort(arr , begin , b);
		quicksort(arr , b + 1 , end);
	}

	public static <T> T
	swap(T a, T b) {
		/*
			https://stackoverflow.com/questions/2393906/how-do-i-make-my-swap-function-in-java/20600020#20600020
			AND THEY SAID IT COULDN'T BE DONE.
		*/
		return a;
	}
}
