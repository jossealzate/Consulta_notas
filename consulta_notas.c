#include <stdio.h>

typedef struct {
    char nombre[50];
    float nota1, nota2, nota3;
} Estudiante;

void consultarNotas(Estudiante estudiante) {
    printf("Notas de %s:\n", estudiante.nombre);
    printf("Nota 1: %.2f\n", estudiante.nota1);
    printf("Nota 2: %.2f\n", estudiante.nota2);
    printf("Nota 3: %.2f\n", estudiante.nota3);
}

float calcularPromedio(Estudiante estudiante) {
    return (estudiante.nota1 + estudiante.nota2 + estudiante.nota3) / 3.0;
}

int main() {
    Estudiante estudiantes[4] = {
        {"Estudiante1", 4.5, 4.0, 0},
        {"Estudiante2", 3.0, 5.0, 1.0},
        {"Estudiante3", 2.7, 3.0, 5.0},
        {"Estudiante4", 0, 4.8, 4.0}
    };

    int opcion;
    int estudianteIndex;

    while (1) {
        printf("\nSeleccione un estudiante (1-4) o 0 para salir: ");
        scanf("%d", &estudianteIndex);

        if (estudianteIndex == 0) {
            printf("Saliendo...\n");
            break;
        } else if (estudianteIndex < 1 || estudianteIndex > 4) {
            printf("Estudiante no válido. Inténtelo de nuevo.\n");
            continue;
        }

        estudianteIndex--;

        printf("\nBienvenido, %s\n", estudiantes[estudianteIndex].nombre);

        do {
            printf("Seleccione una opción:\n");
            printf("1. Consultar notas\n");
            printf("2. Conocer promedio\n");
            printf("0. Salir\n");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    consultarNotas(estudiantes[estudianteIndex]);
                    break;
                case 2:
                    printf("Promedio: %.2f\n", calcularPromedio(estudiantes[estudianteIndex]));
                    break;
                case 0:
                    printf("Saliendo...\n");
                    break;
                default:
                    printf("Opción no válida. Inténtelo de nuevo.\n");
            }
        } while (opcion != 0);
    }

    return 0; 
}


