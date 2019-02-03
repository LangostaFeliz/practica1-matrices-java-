public class Matriz{
	int columnas;
	int renglones;
	
	public Matriz(int renglones, int columnas){
		setRenglones(renglones);
		setColumnas(columnas);
	}
	
	public void setRenglones(int renglones){
		this.renglones = renglones;
	}
	
	public void setColumnas(int columnas){
		this.columnas = columnas;
	}
	
	public int getRenglones(){
		return renglones;
	}
	
	public int getColumnas(){
		return columnas;
	}
}