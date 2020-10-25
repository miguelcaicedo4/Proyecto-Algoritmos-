#ifndef _arbol_hpp_
#define _arbol_hpp_

template <typename dataType>
class Arbol{
public:
    Arbol();
    ~Arbol();

private:
    dataType struct nodo{
        dataType data;
        struct nodo *rama[hijos]
    };
    dataType nodo *arbol *pNodo;
   
}
