package serieFibonacci;

public class serieFibonacci {

	public static long fibonacci(long numero) {
		if (numero==0 || numero==1) {
			return numero;
		}
		else {
			return fibonacci(numero-1)+fibonacci(numero-2);
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for(int i=0;i<3;i++) {
			System.out.print(fibonacci(i)+", ");
		}
	}

}
