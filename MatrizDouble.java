import java.util.*;
import java.text.*;
import javax.swing.*;
public class MatrizDouble extends Matriz{
	
	double array[][];
	
	public MatrizDouble(int renglones, int columnas){
		super(renglones,columnas);
		array = new double[renglones][columnas];
	}
	
	public void iniciarMatDouble(){
		Random gen = new Random();
		for(int i=0;i<this.renglones;i++)
			for(int j=0; j<this.columnas; j++)
				this.array[i][j] = (gen.nextDouble()*(10));
	}

	public void imprimirMatDouble(){
		for(int i=0; i<this.renglones; i++){
			for(int j=0; j<this.columnas; j++){
				System.out.print(this.array[i][j]+"\t");
			}
			System.out.println();
		}
	}

	public void imprimirMatDoubleG(){
		DecimalFormat df = new DecimalFormat("#00");
		String cadena="";
		for(int i=0;i<this.renglones;i++){
			for(int j=0; j<this.columnas;j++){
				cadena+=df.format(array[i][j])+"\t\t";
			}
			cadena+="\n";
		}
		JOptionPane.showMessageDialog(null,cadena);
	}
}

