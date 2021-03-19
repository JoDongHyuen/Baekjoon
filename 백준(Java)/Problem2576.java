import java.util.Scanner;

public class Problem2576 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int i;
		int count = 0, sum = 0, num;
		int min = 101;
		for (i = 0; i < 7; i++)
		{
			num = sc.nextInt();
			if (num % 2 == 1) {
				count++;
				sum += num;
				if (min > num)
					min = num;
			}
		}
		
		if (count == 0)
			System.out.printf("%d%n", -1);
		else
			System.out.printf("%d%n%d%n", sum, min);

	}

}
