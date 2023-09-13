
public class Materia {
	private final int MAX_PRERREQUISITOS=3;
	String clave;
	String nombre;
	String[] prerrequisitos=new String[MAX_PRERREQUISITOS];
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	public boolean fijaClave(String c) {
		if (c.length()>0) {
			clave=c;
			return true;
		}
		else {
			return false;
		}
	}
	
	public boolean fijaNombre(String n) {
		if (n.length()>0) {
			nombre=n;
			return true;
		}
		else {
			return true;
		}
	}
	
	public boolean fijaPrerrequisito(String p,int i) {
		if (p.length()>0) {
			prerrequisitos[i]=p;
			return true;
		}
		else {
			return false;
		}
	}
	
	public String dameClave(){
		return clave;
	}
	
	public String dameNombre() {
		return nombre;
	}
	
	public String damePrerrequisitoUno() {
		String prerreq = null;
		if (prerrequisitos[0]!=null) {
			prerreq=prerrequisitos[0];
		}
		else {
			prerreq="";
		}
		return prerreq;
	}
	public String damePrerrequisitoDos() {
		String prerreq = null;
		if (prerrequisitos[1]!=null) {
			prerreq=prerrequisitos[1];
		}
		else {
			prerreq="";
		}
		return prerreq;
	}
	public String damePrerrequisitoTres() {
		String prerreq = null;
		if (prerrequisitos[2]!=null) {
			prerreq=prerrequisitos[2];
		}
		else {
			prerreq="";
		}
		return prerreq;
	}
	
	public void dameInfoMateria() {
		System.out.print("Clave: " + dameClave() + "\n" + "Nombre: " + dameNombre() + "\nPrerrequisito(s): " +damePrerrequisitoUno() + " "+
				         damePrerrequisitoDos()+" "+damePrerrequisitoTres()+"\n");
	}
}
