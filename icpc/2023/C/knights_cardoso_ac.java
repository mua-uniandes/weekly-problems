// Autor: Rodrigo Cardoso - 2023.07.06
import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

// Dados: n : lado de un tablero de ajedrez
//        (a,b) : escaque de arranque del caballo KA
//        (c,d) : escaque de arranque del caballo KB
// Encontrar r, el mínimo número de saltos de caballo que hacen que KA y KB se encuentren
// o responder '*', si esto no puede pasar.
// Para visitas: color en la búsqueda BNF (Blanco -1: no explorado; Gris 0: descubierto; Negro 1: visitado)


class Vertex {
	private Point p;   	// coordenadas del cuadro
	private int d;     	// distancia a la fuente
	private Vertex q;  	// predecesor BNF

	public Vertex (Point p, int d) {
		this.p = p;
		this.d = d;
		this.q = null;
	}

	public Point getP() {
		return p;
	}

	public int getColor() {
		return (this.p.x + this.p.x)%2;
	}

	public void setD(int k) {
		this.d = k;
	}

	public int getD() {
		return d;
	}

	public void setPred(Vertex q) {
		this.q = q;
	}

	public Vertex getPred() {
		return this.q;
	}


	public boolean equalP (Vertex w) {
		if (this.getP().x == w.getP().x && this.getP().y == w.getP().y && this.getD() == w.getD()){
			return true;
		}
		else {
			return false;
		}
	}
}

public class knights_cardoso_ac {
	public static int n,a,b,c,d;			
	public static int r;
	public static boolean fin = false;
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in),1024);
	public static String lineain, data[];
	public static ArrayList<Vertex> cola = new ArrayList<>();
	public static int visitas [][];

	public static void main(String[] args) throws IOException {
		lectura();

		while (!fin){
			if ( (a%2 + b%2 - c%2 -d%2)%2 != 0) { // No hay encuentro
				System.out.println("*");
			}
			else {
				solve();
			}
			lectura();
		}
	}

	private static void solve(){
		visitas = new int[n][n];
		for (int i=0; i!=n; i++) {
			for (int j=0; j!=n; j++) {
				visitas[i][j] = -1;
			}
		}
		cola.clear();

		Vertex s,u;
		Point pA = new Point(a,b);
		s = new Vertex(pA,0);
		visitas[a][b] = 0;

		cola.add(s);
		u = s;

		boolean fin = false;
		
		while (!fin && !cola.isEmpty()) {
			u = cola.remove(0);
			
			if (sat(u)) {
				fin = true;
				System.out.println(u.getD()/2);
				
				// Impresion de camino encontrado

//				System.out.print(u.getP().x + " " + u.getP().y + " - ");
				while (u.getPred() != null) {
					u = u.getPred();
//					System.out.print(u.getP().x + " " + u.getP().y + " - ");
				}
//				System.out.println();
				return;
			}
			else {
				marcarSucesores(u,cola);
				visitas[u.getP().x][u.getP().y] = 1;
			}
		}
		System.out.println("*");
		
	}


	private static boolean sat (Vertex w) {
		return (w.getP().x == c && w.getP().y == d);
	}

	private static void marcarSucesores(Vertex u, ArrayList<Vertex> cola) { // define y marca sucesores del vertex u
		Vertex ecola;
		Vertex esuc;
		Point temp;
		int ns = 0;
		int i = 2;
		int j = 1;
		int d = u.getD()+1;
		int ibase = u.getP().x;
		int jbase = u.getP().y;

		while (ns!=8) {
			int i1 = ibase + i;
			int j1 = jbase + j;
			if (i1 >=0 && i1<n && j1 >=0 && j1<n) {
				if (visitas[i1][j1] == -1) {
					int e = 0;
					int ecent = cola.size();
					boolean esta = false;
					while (e != ecent) {
						ecola = cola.get(e);
						if (i1 == ecola.getP().x  &&  j1 == ecola.getP().y ) {
							ecent = e;
							esta = true;
						}
						else {
							e++;
						}
					}
					if (!esta) { // no lo incluye como sucesor si ya está en cola
						visitas[i1][j1] = 0;
						temp = new Point(i1,j1);
						esuc = new Vertex(temp,d);
						esuc.setPred(u);
						int ultimo = cola.size();
						cola.add(ultimo, esuc);
					}
				}
			}
			ns++;			
			switch (ns) {
			case(1): {
				i = 1;
				j = 2;
				break;
			}
			case(2): {
				i = -1;
				j = 2;
				break;
			}
			case(3): {
				i = -2;
				j = 1;
				break;
			}
			case(4): {
				i = -2;
				j = -1;
				break;
			}
			case(5): {
				i = -1;
				j = -2;
				break;
			}
			case(6): {
				i = 1;
				j = -2;
				break;
			}
			case(7): {
				i = 2;
				j = -1;
				break;
			}
			}

		}

		//		printAg();
	}



	private static void lectura () throws IOException{
		lineain = br.readLine();
		data = lineain.split(" ");
		n = Integer.parseInt(data[0]);
		a = Integer.parseInt(data[1]);
		b = Integer.parseInt(data[2]);
		c = Integer.parseInt(data[3]);
		d = Integer.parseInt(data[4]);

		if (n==0) {
			fin = true;
		}
	}

	private static void printCola() { // Imprime cola (debugging)
		for (int i = 0; i!= cola.size(); i++) {
			Vertex w = cola.get(i);
			int u = w.getP().x;
			int v = w.getP().y;
			int r = w.getD();
			System.out.print(r + ":" + u + " " + v + " - ");
		}
		System.out.println();
	}

}


