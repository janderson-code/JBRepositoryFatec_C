//#include <iostream>

//#include <locale.h>

//#include <stdlib.h>

//#include <string>

//

//using namespace std;

//

//

//int main() {

// setlocale(LC_ALL, "Portuguese");

//

//

// system("pause");

// return 0;

//}

//#include <iostream>

//#include <locale.h>

//#include <stdlib.h>

//#include <string>

//

//using namespace std;

//

//

//int main() {

// setlocale(LC_ALL, "Portuguese");

//

// int x, y;

//

//

// cout << "Alô Mundo" << endl << endl;

//

// x = 100;

// y = 200;

//

// cout << "Valor x: " << x << endl;

// cout << "Valor y: " << y << endl;

//

//

// system("pause");

// return 0;

//}

//#include <iostream>

//#include <locale.h>

//#include <stdlib.h>

//#include <string>

//

//using namespace std;

//

//

//int main() {

// setlocale(LC_ALL, "Portuguese");

//

// /*

// float x;

//

// cout << "Digite o valor de X: ";

// cin >> x;

//

// cout << "Valor x: " << x << endl;

// */

//

// string nome, sobrenome, nomeCompleto;

//

// nome = "Ricardo";

//

// cout << "Digite seu sobrenome: ";

// cin >> sobrenome;

//

// cout << "O nome é: " << nome << endl ;

// cout << "O sobrenome é: " << sobrenome << endl << endl << endl;

//

//

// nomeCompleto = nome + " *** " + sobrenome;

//

// cout << "Nome completo: " << nomeCompleto << endl;

//

//

// system("pause");

// return 0;

//}

//#include <iostream>

//#include <locale.h>

//#include <stdlib.h>

//#include <string>

//

//using namespace std;

//

//

//int main() {

// setlocale(LC_ALL, "Portuguese");

//

// int codigo;

// codigo = 5;

//

// if (codigo == 1) {

// cout << "Alimento não-perecível.";

// }

// else if (codigo == 2 || codigo == 3 || codigo == 4) {

// cout << "Alimento perecível.";

// }

// else if (codigo == 5 || codigo == 6 ) {

// cout << "Vestuário.";

// }

// else if (codigo == 7) {

// cout << "Higiene Pessoal.";

// }

// else if (codigo >= 8 && codigo <= 15) {

// cout << "Lipeza e utensílios doméstico.";

// }

// else {

// cout << "Código inválido.";

// }

//

// cout << endl << endl;

//

// system("pause");

// return 0;

//}

//#include <iostream>

//#include <locale.h>

//#include <stdlib.h>

//#include <string>

//

//using namespace std;

//

//

//int main() {

// setlocale(LC_ALL, "Portuguese");

//

// int x = 0;

//

// while (x <= 20) {

// cout << "X: " << x << endl;

//

// x += 2;

// }

//

// cout << endl << endl;

//

// //-------------------------------------------------

//

// /*x = 0;

//

// while (x <= 20) {

//

// if ((x % 4) == 0) {

// cout << "Números divisíveis por 4: " << x << endl;

// }

//

// x++;

//

// }*/

//

//

// //-------------------------------------------------

//

// x = 4;

//

// while (x <= 20) {

//

// cout << "Números divisíveis por 4: " << x << endl;

//

// x += 4;

// }

//

//

//

//

// cout << endl << endl;

//

// system("pause");

// return 0;

//}

//

//

//#include <iostream>

//#include <locale.h>

//#include <stdlib.h>

//#include <string>

//

//using namespace std;

//

//

//int main() {

// setlocale(LC_ALL, "Portuguese");

//

// string nome;

// nome = "Diego";

//

//

// cout << "Digite o nome:";

// cin >> nome;

//

// cout << "Nome: " << nome << endl << endl;

//

//

// system("pause");

// return 0;

//}

#include <iostream>

#include <locale.h>

#include <stdlib.h>

#include <string>

using namespace std;

void msgAloMundo();

int soma(int vlr1, int vlr2);

int subtracao(int vlr1, int vlr2);

int main()
{

    setlocale(LC_ALL, "Portuguese");

    //int x, y;

    //msgAloMundo();

    //----------------------------------------------

    //soma(10, 10);

    //x = 100;

    //y = 200;

    //soma(x,y);

    //----------------------------------------------

    int x, y;

    int k, j, conta;

    x = 50;

    y = 20;

    j = soma(50, 20);

    cout << "Resultado: " << j << endl
         << endl;

    k = subtracao(x, y);

    cout << "Resultado: " << k << endl
         << endl;

    conta = j + k;

    cout << "Total: " << conta << endl
         << endl;

    system("pause");

    return 0;
}

void msgAloMundo()
{

    cout << "Alô Mundo" << endl
         << endl;
}

int soma(int vlr1, int vlr2)
{

    int total;

    total = vlr1 + vlr2;

    return total;
}

//int subtracao(int vlr1, int vlr2) {

// int total;

//

// total = vlr1 - vlr2;

//

// return total;

//}

int subtracao(int vlr1, int vlr2)
{

    int total;

    total = vlr1 - vlr2;

    return total;
}