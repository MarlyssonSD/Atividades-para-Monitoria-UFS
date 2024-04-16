package PROG3.questao3;

import java.util.Random;

public class Baralho {
	private Carta baralho[];
	private int posicaoCarta;

	public Carta[] getBaralho() {
		return baralho;
	}

	public void setBaralho(Carta[] baralho) {
		this.baralho = baralho;
	}

	public int getPosicaoCarta() {
		return posicaoCarta;
	}

	public void setPosicaoCarta(int posicaoCarta) {
		this.posicaoCarta = posicaoCarta;
	}

	public Baralho() {
		this.baralho = new Carta[52];
		this.posicaoCarta = 51;
		inicializarBaralho();
		embaralharBaralho();
	}

	private void inicializarBaralho() {
		String[] naipe = {"Paus","Copas","Ouros","Espadas"};
		String[] valor = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
		int contador = 0;

		for (int i = 0; i < naipe.length; i++) {
			for (int j = 0; j < valor.length; j++) {
				this.baralho[contador++] = new Carta(naipe[i], valor[j]);
			}
		}
	}

	public void embaralharBaralho() {
		Random random = new Random();
		for (int i = 0 ; i < baralho.length ; i++) {
			int posicao1 = random.nextInt(52);
			int posicao2 = random.nextInt(52);
			Carta cartaAux = baralho[posicao1];
			baralho[posicao1] = baralho[posicao2];
			baralho[posicao2] = cartaAux;
		}
	}
	public void embaralharBaralho(int quantidadeEmbaralhar) {
		Random random = new Random();
		for (int qtd = 0; qtd < quantidadeEmbaralhar; qtd++) {
			for (int i = 0 ; i < baralho.length ; i++) {
				int posicao1 = random.nextInt(52);
				int posicao2 = random.nextInt(52);
				Carta cartaAux = baralho[posicao1];
				baralho[posicao1] = baralho[posicao2];
				baralho[posicao2] = cartaAux;
			}
		}
	}

	protected boolean checarBaralho() {
		if (getPosicaoCarta() > 0) {
			return true;
		}else {
			return false;
		}
	}

	public Carta comprarCarta() {
		if (checarBaralho()) {
			Carta carta = baralho[getPosicaoCarta()];
			setPosicaoCarta(getPosicaoCarta()-1);
			return carta;
		}else {
			return null;
		}
	}
}
