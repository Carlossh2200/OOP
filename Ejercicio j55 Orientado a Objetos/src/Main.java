//CuatroCero
//Ejercicio 55
//Tiempo=01:00
import java.util.Scanner;

public class Main {
	
	static final int MAX_MATERIAS=10;
	static final int MAX_PRERREQUISITOS=3;
	public static int cuentaMaterias=MAX_MATERIAS;
	static Materia[] materias=new Materia[MAX_MATERIAS];
	static Scanner consola=new Scanner(System.in);
	
	
	
	
	
	
	
	
	
	
	
	static void pausar() {
		System.out.println("Presiona entrar para continuar.");
		consola.nextLine();
	}
	
	static int menu() {
		int opcion;
		System.out.println("MENU");
		System.out.println("1. Alta de materia");
		System.out.println("2. Baja de materia");
		System.out.println("3. Consulta de materia");
		System.out.println("4. Listado de materias");
		System.out.println("5. Salir");
		System.out.print("Opcion: ");
		opcion=consola.nextInt();
		consola.nextLine();
		return opcion;
	}
	
	public static void inicializar() {
		for(int i=0;i<MAX_MATERIAS;i++) {
			materias[i]=new Materia();
			materias[i].nombre="";
			materias[i].clave="";
		}
		cargarDatos();
	}
	
	public static void cargarDatos() {
		materias[0].clave="I5247";
		materias[0].nombre="Lógica Matemática";
		materias[0].prerrequisitos[0]="(Español)";
		materias[0].prerrequisitos[1]="(Álgebra)";
		materias[1].clave="IL352";
		materias[1].nombre="Programación Estructurada";
		materias[1].prerrequisitos[0]="I5247";
		materias[2].clave="IL345";
		materias[2].nombre="Matemáticas Discretas";
		materias[2].prerrequisitos[0]="(Aritmética)";
		materias[2].prerrequisitos[1]="(Trigonometría)";
		materias[2].prerrequisitos[2]="I5247";
		materias[3].clave="IL5289";
		materias[3].nombre="Programación Orientada a Objetos";
		materias[3].prerrequisitos[0]="IL352";
		materias[4].clave="IL354";
		materias[4].nombre="Estructuras de Datos";
		materias[4].prerrequisitos[0]="I5289";
		materias[4].prerrequisitos[1]="IL345";
		materias[5].clave="I5890";
		materias[5].nombre="Bases de Datos";
		materias[5].prerrequisitos[0]="IL354";
		materias[6].clave="I5898";
		materias[6].nombre="Ingenieria de Software I";
		materias[6].prerrequisitos[0]="I5890";
		materias[7].clave="I5909";
		materias[7].nombre="Programación para Internet";
		materias[7].prerrequisitos[0]="I5890";
		materias[8].clave="I7029";
		materias[8].nombre="Sistemas Operativos";
		materias[8].prerrequisitos[0]="IL354";
		materias[9].clave="I7029";
		materias[9].nombre="Programación Concurrente y Paralela";
		materias[9].prerrequisitos[0]="I7029";
		materias[9].prerrequisitos[1]="I5898";
	}
	
	static void altaMateria() {
		int cantPrerreq;
		System.out.println("ALTA DE MATERIA");
		if (cuentaMaterias<MAX_MATERIAS) {
			System.out.print("Dame el nombre de la materia: ");
			materias[cuentaMaterias].nombre=consola.nextLine();
			System.out.print("Dame la clave de la materia: ");
			materias[cuentaMaterias].clave=consola.nextLine();
			System.out.println("Cuántos prerrequisitos tiene la materia (0 a 3): ");
			cantPrerreq=consola.nextInt();
			if (cantPrerreq >= 0 && cantPrerreq <=3) {
				for(int i=0;i<cantPrerreq;i++) {
					System.out.print("Dame el prerrequisito: ");
					materias[cuentaMaterias].prerrequisitos[i]=consola.nextLine();
				}
			}
			else {
				System.out.println("Inicializando materia sin ningún prerrequisito.");
			}
			cuentaMaterias++;
		}
		else {
			System.out.println("No hay espacio para captura.");
		}
		pausar();
	}
	
	static void bajaMateria() {
		int i;
		System.out.println("BAJA DE MATERIA");
		if (cuentaMaterias>0) {
			System.out.print("Que registro quieres borrar? (1 a " + cuentaMaterias + ") :");
			i=consola.nextInt();
			i--;
			for(cuentaMaterias--;i<cuentaMaterias;i++) {
				materias[i]=materias[i+1];
			}
			System.out.println("Hecho.");
		}
		else {
			System.out.println("No hay registros que eliminar.");
		}
		pausar();
	}

	static void listarMaterias() {
		for(int i=0;i<cuentaMaterias;i++) {
			materias[i].dameInfoMateria();
		}
	}
	
	static void consultarMateria() {
		int i;
		System.out.println("CONSULTA MATERIA");
		if (cuentaMaterias>0) {
			System.out.print("Que materia quieres consultar (1 a " + cuentaMaterias + ") :");
			i=consola.nextInt();
			materias[i].dameInfoMateria();
		}
		else {
			System.out.println("No hay registros que consultar");
		}
		pausar();
	}
	
	public static void main(String[] args) {
		boolean seguirEjecutandoPrograma=true;
		inicializar();
		do {
			switch(menu()) {
			case 1:
				altaMateria();
				break;
			case 2:
				bajaMateria();
				break;
			case 3:
				consultarMateria();
				break;
			case 4:
				listarMaterias();
				break;
			case 5:
				System.out.println("Haz salido del programa...");
				seguirEjecutandoPrograma=false;
				break;
			default:
				System.out.println("Opcion no valida");
			}
		}while(seguirEjecutandoPrograma);
		consola.close();
	}

}
