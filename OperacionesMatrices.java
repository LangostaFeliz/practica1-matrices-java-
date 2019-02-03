public class OperacionesMatrices{

    public static MatrizDouble transponerMatDouble(MatrizDouble m1){
	    MatrizDouble matTransp = new MatrizDouble(  m1.getColumnas(), m1.getRenglones()  );
		
		for(int i = 0; i<m1.renglones; i++){
		    for(int j = 0; j<m1.columnas; j++){
			    matTransp.array[j][i] = m1.array[i][j];
			}
		}
        return matTransp;
    }	

    public static MatrizDouble sumarMatDouble(MatrizDouble m1, MatrizDouble m2){
        MatrizDouble matResult = new MatrizDouble(m1.getRenglones(),m2.getColumnas());
        for( int i = 0; i<matResult.array.length; i++){
            for( int j = 0; j< matResult.array[i].length; j++){
                matResult.array[i][j] = m1.array[i][j] + m2.array[i][j];
            }
        }
        return matResult;
	}

    public static MatrizDouble multiplicarMatDouble(MatrizDouble m1, MatrizDouble m2){
        MatrizDouble matResult = new MatrizDouble(m1.getRenglones(), m2.getColumnas());
        for(int i = 0; i< m1.array.length; i++){
            for(int j = 0; j< m2.array[0].length; j++){
                for(int k = 0; k< m1.array[0].length; k++){
                    matResult.array[i][j]+= m1.array[i][k] * m2.array[k][j];
                }					
            }
		}
		return matResult;
	}
	
}