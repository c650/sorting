import java.util.ArrayList;
import java.util.Collections;

public class SortingTest {
	private static final int SIZE = 10;

	public static void
	main(String[] args) {

		ArrayList<Integer> arr = new ArrayList<>();
		for (int i = 0 ; i < SIZE ; i++)
			arr.add( (int)(Math.random() * SIZE) );

		System.out.println(arr);

		Collections.sort(arr);
		System.out.println(arr);
		shuf(arr);

		Sorting.bubblesort(arr);
		System.out.println(arr);
		shuf(arr);

		Sorting.insertionsort(arr);
		System.out.println(arr);
		shuf(arr);

		Sorting.selectionsort(arr);
		System.out.println(arr);
		shuf(arr);

		Sorting.mergesort(arr);
		System.out.println(arr);
		shuf(arr);

		Sorting.insertionsort(arr);
		System.out.println(arr);
		shuf(arr);
	}


	private static void shuf(ArrayList<Integer> arr) {
		Integer tmp;
		int rand_idx;
		for (int i = arr.size() - 1 ; i >= 0 ; i--) {
			rand_idx = (int)(Math.random() * arr.size());
			tmp = arr.get(i);
			arr.set(i , arr.get(rand_idx));
			arr.set(rand_idx, tmp);
		}
	}
}
