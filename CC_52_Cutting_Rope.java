
public class CC_52_Cutting_Rope {
	static int[] answer=new int[100];

	public static int sol1(int rope){
		answer[0]=0;
		answer[1]=1;
		answer[2]=2;
		answer[3]=3;
	
		for(int i=4; i<=(rope); i++){
			int max=0;
			for(int j=2; j<=i-j; j++){
				int tmp=answer[i-j]*j;
				max=Math.max(max,tmp);
			}
			answer[i]=max;
		}
		
		return answer[rope];
	}
	
	public static int sol2(int rope){
		if(rope==0) return 0;
		else if(rope==1) return 1;
		else if(rope==2) return 2;
		else if(rope==3) return 3;
		else{
			if(rope%3==1)
				return (int) ( Math.pow(2,2) * Math.pow(3,(rope/3-1)));
			else if(rope%3==2)
				return (int) (2 * Math.pow(3, (rope/3)));
			else
				return (int) Math.pow(3, (rope/3));
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int rope=9;
		sol1(rope);
		System.out.println("Solution1: "+answer[rope]);
		System.out.println("Solution2: "+sol2(rope));
		
	}

}
