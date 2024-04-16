package PROG3.questao3;

public class Carta {
	private String naipe;
	private String face;
	
	public String getNaipe() {
		return this.naipe;
	}
	public void setNaipe(String naipe) {
		this.naipe = naipe;
	}
	public String getFace() {
		return this.face;
	}
	public void setFace(String face) {
		this.face = face;
	}
	
	public int valorNumerico(String face) {
		if (face.equalsIgnoreCase("A")) {
			return 1;
		}else if (face.equalsIgnoreCase("J")) {
			return 11;
		}else if (face.equalsIgnoreCase("Q")) {
			return 12;
		}else if (face.equalsIgnoreCase("K")) {
			return 13;
		}else {
			return Integer.parseInt(face);
		}
	}
	
	public String toString() {
		String retorno = "";
		retorno += getFace() + " de " + getNaipe();
		//retorno += "\nFace: " + 
		//retorno += "\nValor: " + valorNumerico(getFace());
		return retorno;
	}
	
	public Carta(String naipe, String face) {
		setNaipe(naipe);
		setFace(face);
	}
	
	

}
