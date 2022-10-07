/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the 
 *     previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++ ), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two. You can also try clang.
 * At the end the source code  should compile without warnings to the variant 
 *     selected (you can remove/change instructions).
 */

/**
 * REGLAS ROTAS
 * ARR01-C (linea 70): No se aplica sizeof() para calcular la longitud del array
 * MSC34-C (lineas 40, 88, 106, 107): Se utilizan funciones deprecadas
 * STR31-C (lineas 79-80): No se garantiza el almacenamiento necesario para los arrays
 * STR32-C (linea 81): No se reserva espacio para para el caracter /0
 * STR35-C (lineas 88): Se copia informacion de la variable key, que esta vacia
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar"; // 
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };
 
const char* s1 = R"foo( 
Hello
World
)foo"; // ERROR: R solo se admite en versiones de C++11 o mas recientes
const char* s2 = "\nHello\nWorld\n";

void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) { // WARNING: fgets es una funcion deprecada
        return 1; // ERROR: Una funcion vacia no puede retornar un valor
  }
  buf[strlen(buf) - 1] = '\0';
}

const char *get_dirname(const char *pathname) {
  char *slash;
  slash = strrchr(pathname, '/'); // ERROR: Se asigna un char * a un const char * (Valores incompatibles)
  if (slash) {
    *slash = '\0'; /* Undefined behavior */
  }
  return pathname;
}
 

void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");  
	gets(response);

	if (response[0] == 'n') 
		exit(0);  

	return;
}

 
int main(int argc, char *argv[])
{
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char *ptr_char  = "new string literal"; // WARNING: Las versiones C++11 o mas antiguas no admiten la conversion de String literal a char *
    int size_array1 = strlen("аналитик"); 
    int size_array2 = 100;
    
   // char analitic1[size_array1]="аналитик"; // ERROR: String no inicializada
   // char analitic2[size_array2]="аналитик"; // ERROR: String no inicializada
    char analitic3[100]="аналитик";

    puts(get_dirname(__FILE__));

        
    strcpy(key, argv[1]); // WARNING: Funcion deprecada
    strcat(key, " = ");  
    strcat(key, argv[2]);


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3)); // WARNING: Funcion deprecada
    strncpy(array4, array3, strlen(array3)); // WARNING: Funcion deprecada
    
    array5 [0] = 'M';
    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}