package PROG3.questao3;

public class JogoApp {

	public static void main(String[] args) {
		Baralho baralho = new Baralho();
		Jogador jogador1 = new Jogador("Fernanda",3);
		Jogador jogador2 = new Jogador("Fabrício",3);
	
		jogador1.comprarCarta(baralho,4);
		
		
		jogador2.comprarCarta(baralho);
		jogador2.comprarCarta(baralho);
		jogador2.comprarCarta(baralho);
		
		System.out.println(jogador1.toString());
		System.out.println("-------------------");
		System.out.println(jogador2.toString());
		
		for(int i=0; i<= baralho.getPosicaoCarta(); i++) {
			System.out.println(baralho.getBaralho()[i].toString());
		}
		
		

	}

}
