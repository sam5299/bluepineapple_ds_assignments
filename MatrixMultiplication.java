import java.util.*;
public class MatrixMultiplication{
public static void main(String args[]){
	Scanner s = new Scanner(System.in);
	int row1,row2,col1,col2;
	System.out.println("Enter how many rows in matrix 1:");
	row1 = s.nextInt();
	System.out.println("Enter how many columns in matrix 1:");
	col1 = s.nextInt();

	System.out.println("Enter how many rows in matrix 2:");
	row2 = s.nextInt();
	System.out.println("Enter how many columns in matrix 2:");
	col2 = s.nextInt();
	
	if(row1==row2 && col1==col2){
		int arr1[][] = new int[row1][col1];
		int arr2[][] = new int[row2][col2];
		int finalarr[][] = new int[row1][col2];
		
		System.out.println("Enter array elements of array 1:");
		for(int i=0;i<row1;i++){
			for(int j=0;j<col1;j++){
				arr1[i][j] = s.nextInt();
			}
		}

		
		System.out.println("Enter array elements of array 2:");
		for(int i=0;i<row2;i++){
			for(int j=0;j<col2;j++){
				arr2[i][j] = s.nextInt();
			}
		}

		System.out.println("Now multiplying:");

		
		for(int i=0;i<row1;i++){
			for(int j=0;j<col2;j++){
				int sum = 0;	
				for(int k=0;k<col2;k++){
					sum += arr1[i][k]*arr2[k][i];
				}
				finalarr[i][j] = sum;
			}
				
		}
		
		System.out.println("Now printing array:\n =========================================");
		for(int i=0;i<row1;i++){
			for(int j=0;j<col1;j++){
				System.out.print(""+finalarr[i][j]+" ");
			}
			System.out.println();
		}

		
			
	}
	else{
		System.out.println("Please enter correct rows and columns in both matrix");
	}
}
}