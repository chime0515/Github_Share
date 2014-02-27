public class dp {
	public static void main(String arg[]){
		int num;
		int value;
		num = 11;
		value = maxNumberOfCut(num);
		System.out.println(value);
		int value1 = trickyMaxProduct(num);
		System.out.println(value1);
	}
	//solution of recursion
	static int maxNumberOfCut(int num) {
		if (num < 4)
			return num;
		int [] arr = new int [num+1];
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 3;
		for (int i = 4;i <= num; i++){
			int max = 0;
			for (int j = 1; j <= i/2; j++){
				int product;
				product = arr[j]*arr[i-j];
				if (max < product)
					max = product;
			}
			arr[i] = max;
		}
		return arr[num];
	}
	//Tricky solution
	static int trickyMaxProduct(int num){
		if (num < 4)
			return num;
		int numOf3 = num/3;
		if (num % 3 == 1)
			numOf3 -= 1;
		int numOf2 = (num-3*numOf3)/2;
		int maxProd = (int) (Math.pow(3, numOf3) * Math.pow(2, numOf2));
		return maxProd;
	}
}
