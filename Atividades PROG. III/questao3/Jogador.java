package PROG3.questao3;

public class Jogador {
	private String nome;
	private Carta mao[];
	private int quantidadeCartas;
	private int contadorCartasMao;

	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public Carta[] getMao() {
		return mao;
	}
	public void setMao(Carta[] mao) {
		this.mao = mao;
	}
	public int getQuantidadeCartas() {
		return quantidadeCartas;
	}
	public void setQuantidadeCartas(int quantidadeCartas) {
		this.quantidadeCartas = quantidadeCartas;
	}

	public int getContadorCartasMao() {
		return contadorCartasMao;
	}

	public Jogador(String nome, int quantidadeCartas) {
		setNome(nome);
		setQuantidadeCartas(quantidadeCartas);
		this.mao = new Carta[quantidadeCartas];
	}

	public void comprarCarta(Baralho baralho) {
		if (baralho.checarBaralho())
			if (getContadorCartasMao() < getQuantidadeCartas()) {
				mao[contadorCartasMao++] = baralho.comprarCarta();
			}else {
				System.out.println("Limite máximo de "+getQuantidadeCartas()+" cartas");
			}
		else{
			System.out.println("Baralho acabou");
		}
	}

	public void comprarCarta(Baralho baralho, int quantidadeCartasComprar) {
		if (baralho.checarBaralho()) {
			for (int i=0; i < quantidadeCartasComprar; i++) {
				if (getContadorCartasMao() < getQuantidadeCartas()) {
					mao[contadorCartasMao++] = baralho.comprarCarta();
				}else {
					System.out.println("Limite máximo de "+getQuantidadeCartas()+" cartas");
					break;
				}
			}
		}else{
			System.out.println("Baralho acabou");
		}
	}

	public int calcularPontuacao() {
		int soma = 0;
		for (int i = 0; i < contadorCartasMao; i++) {
			soma += mao[i].valorNumerico(mao[i].getFace());
		}
		return soma;
	}

	public String toString() {
		String retorno = "";
		retorno += "Jogador: "+this.getNome();
		retorno += "\nMão";
		for(int i = 0; i < contadorCartasMao ; i++) {
			retorno += "\nCarta " +  (i+1) + ": "+ this.getMao()[i].toString();
		}
		retorno += "\nPontuação: " + this.calcularPontuacao();
		return retorno;
	}




}
