//TresSeis
//Practica 1 POO
//TiempoTraduccion=00:30
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//Declaracion y definicion de constantes
		final int C_100 = 100;
		final int IVA = 16;
		final int RETENCION_IVA = 10;
		final int RETENCION_ISR = 10;
		final int ISR = 11;
		//Declaracion de variables
		Scanner consola=new Scanner(System.in);
		float ingreso,calculoIva,calculoRetencionIva,calculoRetencionIsr,subtotal,total,gastoUsuario
		,gananciaBruta,gananciaNeta,calculoIsr,pagoIsr,gastoIva,pagoIva;
		System.out.println("CALCULO DE IMPUESTOS\n");
		System.out.print("Dame el ingreso: ");
		ingreso=consola.nextFloat();
		consola.nextLine();
		System.out.print("Dame el gasto: ");
		gastoUsuario=consola.nextFloat();
		consola.nextLine();
	    calculoIva=(IVA*ingreso)/C_100; //Calculo de impuestos
	    calculoRetencionIva=(ingreso*RETENCION_IVA)/C_100;
	    calculoRetencionIsr=(ingreso*RETENCION_ISR)/C_100;
	    subtotal=ingreso+calculoIva;
	    total=subtotal-calculoRetencionIsr-calculoRetencionIva;
	    gananciaBruta=ingreso-gastoUsuario;
	    calculoIsr=(gananciaBruta*ISR)/C_100;
	    gananciaNeta=gananciaBruta-calculoIsr;
	    pagoIsr=calculoIsr-calculoRetencionIsr;
	    gastoIva=(gastoUsuario*IVA)/C_100;
	    pagoIva=calculoIva-gastoIva-calculoRetencionIva;
	    System.out.println("CALCULO DE IMPUESTOS\n");
		System.out.println("***Tabla de recibo de honorarios***");
		System.out.printf("Ingresos	  %f\n",ingreso);
		System.out.printf("(+) IVA	          %f\n",calculoIva);
		System.out.printf("(=) Subtotal      %f\n",subtotal);
		System.out.printf("(-) Retencion ISR %f\n",calculoRetencionIsr);
		System.out.printf("(=) Total         %f\n",total);
		
		System.out.printf("TABLA GANANCIAS\n\n");
		System.out.printf("Ingresos          %f\n",ingreso);
		System.out.printf("(-) Gasto         %f\n",gastoUsuario);
		System.out.printf("Ganancia Bruta    %f\n",gananciaBruta);
		System.out.printf("(-) ISR           %f\n",calculoIsr);
		System.out.printf("Ganancia Neta     %f\n",gananciaNeta);
		
		System.out.printf("TABLA ISR         \n\n");
		System.out.printf("ISR               %f\n",calculoIsr);
		System.out.printf("(-) ISR Retenido  %f\n",calculoRetencionIsr);
		System.out.printf("(=) ISR a pagar   %f\n",pagoIsr);
		
		System.out.printf("TABLA IVA         \n\n");
		System.out.printf("IVA               %f\n",calculoIva);
		System.out.printf("(-) Gasto Iva     %f\n",gastoIva);
		System.out.printf("(-) Retencion IVA %f\n",calculoRetencionIva);
		System.out.printf("(=) IVA a Pagar   %f\n",pagoIva);
		
		System.out.printf("Presiona entrar para continuar...\n");
		consola.nextLine();
		consola.close();
		
	}

}
