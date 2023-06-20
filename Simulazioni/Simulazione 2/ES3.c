/*
Il Quicksort è un algoritmo di ordinamento crescente ricorsivo di un array di
valori .L'algoritmo si basa su una suddivisione ed ordimanto del vettore
attraverso la partition e la richiamata ricorsiva della quicksort . Il
funzionamento dell'algoritmo è il seguente: la qicksort riceve il vettore in
ingresso in la posizione di testa e di coda, una volta cicevuto, attraverso la
partition (il nucleo di questo sistema di ordinazione) va a suddividere il
vettore in due sottovettori senza prima averi ordinati. L'ordinamento avviene
prendendo un valore casuale nel vettore e mettendo tutti quelli minori di esso a
destra e maggiori a sinistra, tenendo conto della posizione in cui ci sono i
valori minori e quelli maggiori, e restituendo poi la appena citata posizione.
Viene ripetuto questo procedimento fino a che il vettore non sarà composto ta
tanti vetori singoli (a una cella) che poi saranno riuniti ricorsivamente
ordinati.

Parlando invece di complessità di tempo e spazio esse variano in base al contenuto del vettore, poichè essendo che il valore da confrontare è scelto casualmente, può succedere che si prenda il valore maggiore pi volte facendo così accadere una situazione in cui avremo chiamate ricorsive solo da una parte dell' albero e amentando esponenzialmente la complessità generale, quindi illustriamo i 2 casi più estremi:
Caso Migliore 
  Coplessità Tempo: O(nlog2(n)) con n numero di nodi nella lista
  Coplessità Spazio: O(log2(n)) con n numero di nodi nella lista
Caso Peggiore 
  Coplessità Tempo: O(n2) con n numero di nodi nella lista
  Coplessità Spazio: O(n) con n numero di nodi nella lista
*/
void swap(int v[], int x, int y) {
  int temp = v[x];
  v[x] = v[y];
  v[y] = temp;
}

int partition(int v[], int p, int r) {
  int i, pivot, pivotpos;
  swap(v, (p + r) / 2, p);
  pivot = v[p];
  pivotpos = p;
  for (i = p + 1; i <= r; i++) {
    if (v[i] < pivot) {
      pivotpos++;
      swap(v, i, pivotpos);
    }
  }
  swap(v, p, pivotpos);

  return pivotpos;
}
void quicksort(int v[], int p, int r) {
  int q;
  if (p < r) {
    q = partition(v, p, r);
    quicksort(v, p, q - 1);
    quicksort(v, q + 1, r);
  }
}
int main(void) {
  int v[10] = {1, 3, 2, 5, 9, 7, 8, 18, 15, 6};
  for (int i = 0; i < 10; i++) {
    printf("%d\t", v[i]);
  }
  printf("\n");
  quicksort(v, 0, 9);
  for (int i = 0; i < 10; i++) {
    printf("%d\t", v[i]);
  }
}
