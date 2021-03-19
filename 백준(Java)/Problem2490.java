import java.util.Scanner;

public class Problem2490 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int i, j;
		int sum;
		
		for (i = 0; i < 3; i++) {
			sum = 0;
			for (j = 0; j < 4; j++)
				sum = sum + input.nextInt();
			
			switch(sum) {
			case 0:
				System.out.println("D");
				break;
			case 1:
				System.out.println("C");
				break;
			case 2:
				System.out.println("B");
				break;
			case 3:
				System.out.println("A");
				break;
			case 4:
				System.out.println("E");
				break;
			}
			
		}

	}

}
