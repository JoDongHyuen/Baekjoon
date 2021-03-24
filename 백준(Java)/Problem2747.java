import java.util.Scanner;

public class Problem2747 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[] arr = new int[46];
		int i, N;
		
		arr[0] = 0;
		arr[1] = 1;
		for (i = 2; i < 46; i++)
			arr[i] = arr[i - 2] + arr[i - 1];
		
		N = input.nextInt();
		System.out.printf("%d%n", arr[N]);
	}

}
