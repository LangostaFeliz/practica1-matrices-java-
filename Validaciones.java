public class Validaciones{

	public static boolean validarCuadratura(MatrizDouble m1, MatrizDouble m2){
		if((m1.getRenglones()==m2.getRenglones()) && (m1.getColumnas()==m2.getColumnas()))
			return true;
			else return false;
	}
	
	public static boolean validarMultiplicabilidad(MatrizDouble m1, MatrizDouble m2){
		if(m1.getColumnas()==m2.getRenglones())
		return true;
		else return false;
	}
} // Fin clase Validaciones