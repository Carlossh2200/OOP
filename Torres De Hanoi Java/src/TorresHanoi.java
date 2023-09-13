
public class TorresHanoi {
	public final static int CANTIDAD_TORRES=3;
	
	public static int torres[]=new int[CANTIDAD_TORRES];
	public static int totalDiscos;
	public static void cambiarDisco() {
		
	}
	
	//Mueve discos de una torre a otra, de manera recursiva
	public static void resolverTorres(int discos, int agujaOrigen, int agujaDestino,int agujaTemp) {
		//caso base -- solo hay que mover un disco
		if (discos==1) {
			System.out.println(agujaOrigen+" --> "+agujaDestino);
			return;
		}
		//paso recursivo -- mueve (disco-1) discos de agujaOrigen
		//a agujaTemp usando agujaDestino
		resolverTorres(discos-1,agujaOrigen,agujaTemp,agujaDestino);
		
		//Se mueve el ultimo disco de agujaOrigen a agujaDestino
		System.out.println(agujaOrigen+" --> "+agujaDestino);
		
		//Mueve (discos-1) discos a agujaTemp a agujaDestino
		resolverTorres(discos-1, agujaTemp,agujaDestino,agujaOrigen);
	}
	
	public static void main(String[] args) {
		int agujaInicial=1,agujaFinal=3,agujaTemp=2;
		totalDiscos=3;
		int[] arr= new int[3];
		arr[0]=agujaInicial;
		arr[1]=agujaTemp;
		arr[2]=agujaFinal;
		
		//llamada no recursiva inicial : mueve todos los discos
		resolverTorres(totalDiscos,agujaInicial,agujaFinal,agujaTemp);
	}

}//fin de torresDeHanoi