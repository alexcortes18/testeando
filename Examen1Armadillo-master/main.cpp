#include <iostream>
#include <fstream>
#include <math.h>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Instancia un nuevo espacio de memoria en el heap y le asigna a (dado), luego devuelve su direccion de memoria.
int* instanciarEnHeap(int a)
{
    int *ptr = new int(0);
    *ptr= a;
    return ptr;
}

//Asigna b (dado) a la direccion de memoria donde apunta a (dado)
void asignar(int* a, int b)
{
    *a= b;
}

//Escribe valor (dado) en un archivo con nombre nombre_archivo (dado)
template<typename T>
void escribir(string nombre_archivo,T valor)
{
    ofstream mi_archivo(nombre_archivo.c_str()); // c_str convierte un String a un char apuntador
    mi_archivo<<valor;
}

//Devuelve el valor almacenado en el archivo con nombre nombre_archivo (dado)
template<typename T>
T leer(string nombre_archivo)
{
    T t;
    ifstream mi_archivo(nombre_archivo.c_str());
    mi_archivo>>t;
    return t;
}

//Devuelve un arreglo que contenga todo el contenido de lista (dado).
//Nota: Los elementos tienen que estar el mismo orden.
int* convertirAArreglo(list<int>lista)
{
    int *arreglo= new int[lista.size()];
    //copy(lista.begin(),lista.end(),arreglo);
    int curr=0;
    for(list<int>::iterator i= lista.begin(); i!=lista.end();i++)
    {
        arreglo[curr]= *i;
        curr++;
    }
    return arreglo;
}

//Devuelve un vector ordenado de menor a mayor que contenga todo el contenido de v1 (dado) y v2 (dado).
//Nota: Asuma que v1 y v2 estan ordenados.
vector<int> mezclarOrdenadamente(vector<int>v1,vector<int>v2)
{
    vector<int>respuesta;
    respuesta.insert(respuesta.end(), v1.begin(), v1.end());
    respuesta.insert(respuesta.end(), v2.begin(), v2.end());
    sort(respuesta.begin(), respuesta.end());

//    int i=0;
//    int j=0;
//    while(i<v1.size() && j<v2.size())
//    {
//        if(v1<v1.size)
//    }
//
    return respuesta;
}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las clases Operador, Sumar y Restar descritas en el diagrama UML adjunto

//**Operador**
//Constructor vacio: no hace nada
//getTipo(): devuelve "Operador"
//operator==: Compara si el operador que viene de parametro tiene los mismos atributos (numero1 y numero2) y es del mismo tipo (con ayuda de getTipo())

//**Sumar**
//Constructor: inicializa los atributos de clase dados los parametros
//operar(): devuelve la suma de numero1 y numero2
//getTipo(): devuelve "Sumar"

//**Restar**
//Constructor: inicializa los atributos de clase dados los parametros
//operar(): devuelve la resta de numero1 y numero2
//getTipo(): devuelve "Restar"


class Operador
{
public:
    int numero1, numero2;

    Operador()
    {
    }
    virtual string getTipo()
    {
        return "Operador";
    }
    virtual int operar() =0;
    bool operator==(Operador* operador)
    {
        if(operador->numero1== numero1 &&
            operador->numero2== numero2 &&
            operador->getTipo()== getTipo()
           )
        return true;
        return false;
    }

};

class Sumar : public Operador
{
public:
    Sumar(int numero1, int numero2) :Operador ()
    {
        this->numero1= numero1;
        this->numero2= numero2;
    }
    int operar()
    {
        return numero1+numero2;
    }
    string getTipo()
    {
        return "Sumar";
    }

};
class Restar : public Operador
{
public:
    Restar(int numero1, int numero2)
    {
        this->numero1= numero1;
        this->numero2= numero2;
    }
    int operar()
    {
        return numero1-numero2;
    }
    string getTipo()
    {
        return "Restar";
    }

};


///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////

void evaluar();
void evaluar2();

int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();

    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////

void evaluar()
{
    double nota = 0;

    cout<<"instanciarEnHeap():\t";
    if(instanciarEnHeap(543)!=NULL
        &&*instanciarEnHeap(543)==543
        && *instanciarEnHeap(23)==23
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    int* as1 = new int;
    asignar(as1,10);
    int* as2 = new int;
    asignar(as2,30);
    int* as3 = new int;
    asignar(as3,50);

    cout<<"asignar():\t\t";
    if(*as1==10
        && *as2==30
        && *as3==50
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    list<int>l2;
    l2.push_back(0);
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(7);

    list<int>l3;

    int*a1=convertirAArreglo(l1);
    int*a2=convertirAArreglo(l2);
    int*a3=convertirAArreglo(l3);

    cout<<"convertirAArreglo():\t";
    if(a1!=NULL
        &&a1[0]==10
        && a1[1]==20
        && a1[2]==30
        && a2[0]==0
        && a2[1]==1
        && a2[2]==2
        && a2[3]==3
        && a2[4]==4
        && a2[5]==5
        && a2[6]==6
        && a2[7]==7
        )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    escribir("archivo",10);
    int t2 = leer<int>("archivo");

    escribir("archivo",43.4);
    double t3 = leer<double>("archivo");

    escribir("archivo","test");
    string t1 = leer<string>("archivo");

    cout<<"leer() y escribir():\t";
    if(t1=="test"
        && t2==10
        && t3==43.4
        )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    vector<int>v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int>v2;
    v2.push_back(5);
    v2.push_back(25);
    v2.push_back(100);
    v2.push_back(105);

    vector<int>res1 = mezclarOrdenadamente(v1,v2);

    cout<<"mezclarOrdenadamente():\t";
    if(res1.size()==7
        && res1[0]==5
        && res1[1]==10
        && res1[2]==20
        && res1[3]==25
        && res1[4]==30
        && res1[5]==100
        && res1[6]==105
        )
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/12"<<endl<<endl;
}

void evaluar2()
{
    double nota = 0;

    cout<<"**Clase Sumar**"<<endl;
    cout<<"Test constructor:\t\t";
    Sumar s1(10,20);
    Sumar s2(4,3);
    Sumar s3(10,20);

    if(s1.numero1 == 10
        && s1.numero2 == 20
        && s2.numero1 == 4
        && s2.numero2 == 3
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test getTipo():\t\t\t";

    if(s1.getTipo() == "Sumar"
        && s2.getTipo() == "Sumar"
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test operar():\t\t\t";

    if(s1.operar() == 30
        && s2.operar() == 7
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test operator==():\t\t";
    if(s1==&s3
        &&!(s1==&s2)
        &&!(s2==&s3)
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<"**Clase Restar**"<<endl;
    cout<<"Test constructor:\t\t";
    Restar r1(10,20);
    Restar r2(4,3);
    Restar r3(10,20);

    if(r1.numero1 == 10
        && r1.numero2 == 20
        && r2.numero1 == 4
        && r2.numero2 == 3
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test getTipo():\t\t\t";

    if(r1.getTipo() == "Restar"
        && r2.getTipo() == "Restar"
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test operar():\t\t\t";

    if(r1.operar() == -10
        && r2.operar() == 1
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test operator==():\t\t";
    if(r1==&r3
        &&!(r1==&r2)
        &&!(r2==&r3)
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/8"<<endl;
}
