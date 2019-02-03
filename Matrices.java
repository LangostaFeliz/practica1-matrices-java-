public class Matrices{
	
	public static void main(String args[]){
		MatrizDouble m1 =new MatrizDouble(CapturaEntrada.capturarEntero("Favor de introducir el numero de renglon para el matriz 1 "), CapturaEntrada.capturarEntero("Favor de introducir el numero de columna para el matriz 1 "));
		
		MatrizDouble m2 =new MatrizDouble(CapturaEntrada.capturarEntero("Favor de introducir el numero de renglon para el matriz 2  "), CapturaEntrada.capturarEntero("Favor de introducir el numero de columna para el matriz 2 "));
		
		MatrizDouble m3;
		MatrizDouble m4;
		MatrizDouble m5;

		m1.iniciarMatDouble();
		System.out.println("El valor de Matriz 1 es ");
		m1.imprimirMatDouble();
		
		m2.iniciarMatDouble();

		System.out.println("El valor de Matriz 2 es ");
		m2.imprimirMatDouble();	

		m4 = OperacionesMatrices.transponerMatDouble(m1);
		System.out.println("La Transpuesta Matriz 1 es siguiente :");
		m4.imprimirMatDouble();	
		

		if (Validaciones.validarCuadratura(m1,m2)){
			m3 = new MatrizDouble(m1.getRenglones(), m1.getColumnas());
			m3 = OperacionesMatrices.sumarMatDouble(m1,m2);
			System.out.println("El resultado de la operacion : Matriz 3 = Matriz 1 + Matriz 2");
			m3.imprimirMatDouble();

		}
		else System.out.println("No son cuadradas, no se puede realizar la suma");


		if (Validaciones.validarMultiplicabilidad(m1,m2)){
			m3 = new MatrizDouble(m1.getRenglones(), m2.getColumnas());
			m3 = OperacionesMatrices.multiplicarMatDouble(m1,m2);
			System.out.println("El resultado de la operacion : Matriz 3 = Matriz 1 * Matriz 2");
			m3.imprimirMatDouble();
			m3.imprimirMatDoubleG();
		}
		else System.out.println("No son multiplicables");
	}

}