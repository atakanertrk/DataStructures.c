#include <stdio.h>
#include <stdlib.h>

/* BinarySearchTree : K�k -> (2�ocuk) -> Sa�D���m > SolD���m

    K�K D���M YAPRAK -ROOT NODE LEAF-

    A�ac�n derinli�i ( height ) = h ise (2^(h+1))-1 max d���m say�s�

    NOT: Binary Search Tree'lerde eleman ekleme i�leminin ne zaman yap�ld��� a�ac�n durumunu de�i�tirir.(durumdan kas�t kimin �ocu�u oldu�u de�i�ebilir. Bu de�i�imi
                                                                                                            �nmelek i�in araya ekleme fonksiyonu kullanabiliriz

         -DOLA�MA �EK�LLER�-
    INFIX = LeftNodeRight, RightNodeLeft
    PREFIX = NLR,NRL
    POSTFIX = LRN,RLN
*/

struct n{
    int data;
    n *sol;
    n *sag;
};
typedef n node;

node *ekle(node *agac,int x){                            // BURADAK� �RNEK LND �eklindeydi
    if(agac==NULL){
        node *root = (node*)malloc(sizeof(node));
        root->sol = NULL;
        root->sag = NULL;
        root->data = x;
        return root;
    }
    if(agac->data<x){
        agac->sag = ekle(agac->sag,x);
        return agac;
    }
    agac->sol = ekle(agac->sol,x);
    return agac;
}

void dolas(node *agac){
    if(agac==NULL)
        return;
    dolas(agac->sol);
    printf("%d",agac->data);
    dolas(agac->sag);

}

int main()
{
    node *agac = NULL;
    agac = ekle(agac,12);
    agac = ekle(agac,200);
    agac = ekle(agac,190);
    agac = ekle(agac,213);
    agac = ekle(agac,56);
    agac = ekle(agac,24);
    agac = ekle(agac,18);
    agac = ekle(agac,27);
    agac = ekle(agac,28);
    dolas(agac);

    return 0;
}
