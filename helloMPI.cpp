#include <stdio.h>
#include <mpi.h>
using namespace std;
//using namespace MPI;

int main(int argc, char **argv) {
	int rank, size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	printf("Hello world. I am %d out of %d.\n",rank,size);
	
	cout << size << endl;
	cout << 1%4 << endl;
	
	MPI_Finalize();
	
	return 0;
	
}

// No tuve que instalar nada de OpenMPI (ya venía instalado, o bien, indirectamente lo instalé en algún momento) (para saber lo instalado, poner en terminal dpkg -l | grep openmpi
// NO usar using namespace MPI;
// Es MPI_, no MPI-
// Lo que agregue en Opciones > Parámetros extras de compilación, es lo que aparece cuando en terminal se coloca mpicxx -show (hasta -pthread inclusive)
// Lo que agregué en Opciones > Parámetros extras de enlazado, es lo que aparece cuando en terminal se coloca mpicxx -show (después de -pthread, eliminando -lmpi)
// De igual forma, si lo ejecuto desde acá, se ejecuta un solo proceso (para que se ejecuten varios procesos, ejecutarlo desde la terminal con mpiexec -n 4 ./MiProyecto.bin (está en la carpeta Debug del proyecto)
// Sino, se puede compilar directamente en terminal con mpicxx helloMPI.cpp -o helloMPI (ya no es un proyecto), y luego, ejecutarlo con mpiexec -n 4 ./helloMPI
