import java.util.*;


public class CC_51_Same_Digit_Less_Number {

	public static void sol(String t){
		int len=t.length();
		
		// Find exchange digit position
		int exchg= _Find_Exc_Digit(t);
		if(exchg==-1) System.out.print("No Answer.");
		
		// Pick the least one after that position
		char least_great='9';
		int lg=-1;
		for(int i=exchg+1; i<len; i++){
			if(t.charAt(i)>t.charAt(exchg)){
				//System.out.println(t.charAt(i));
				if(t.charAt(i)<least_great){
					//System.out.println("123");
					least_great=t.charAt(i);
					lg=i;
				}
			}
		}
		//System.out.println("Find least great digit is:"+least_great +" at: " +lg);
		//System.out.println("Exchange it to digit:"+t.charAt(exchg) +" at: "+exchg);
		
		// Exchange digit and sort them
		char tmp=t.charAt(lg);
		char[] ta=t.toCharArray();
		ta[lg]=t.charAt(exchg);
		ta[exchg]=tmp;
		//Arrays.sort(a, fromIndex, toIndex, c)
		Arrays.sort(ta, exchg+1, len);

		System.out.println((ta));
		
	}
	
	public static int _Find_Exc_Digit(String t){
		int a=t.length()-1;
		
		for(int i=a; i>0; i--){
			if(t.charAt(i-1)<t.charAt(i))
				return i-1;
		}
		return -1;
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String test="34722641";
		sol(test);
		/*
		char[] a = test.toCharArray();
		for(int i=0; i<a.length; i++)
			System.out.print(a[i]);
		*/


	}

}
