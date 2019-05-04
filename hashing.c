#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct dugum{
  int key;
  int data;
 }dugum;

dugum* hashTable[SIZE];

int hashCode(int key){
  return key % SIZE;
}




void ekle(int key, int data){

  struct dugum* tmp = (dugum*)malloc(sizeof(dugum));
  tmp->data=data;
  tmp->key=key;

  int indeks = hashCode(key);

  while (hashTable[indeks]!=NULL) {
    ++indeks;
    indeks %= SIZE;
  }

  hashTable[indeks]=tmp;
}



dugum* ara(int key){

  int homeAdress = hashCode(key);
  int  indeks = homeAdress;



  if (hashTable[indeks]!=NULL){

    if( hashTable[indeks]->key == key)
       return hashTable[indeks];
    else{
        ++indeks;
        while(hashTable[indeks]!=NULL && indeks!= homeAdress)
            {
             if(hashTable[indeks]->key == key)
               return hashTable[indeks];
              ++indeks;
              indeks %=SIZE;
           } //end while
     }// end else

  }//end if

   return NULL;
}


void display(){

  int i = 0;
  for (i;i <= SIZE;i++){
    if (hashTable[i]!=NULL) {
      printf("%d-%d\n", hashTable[i]->key,hashTable[i]->data);
    }else{
      printf("-------\n");
    }

  }

}


int main(int argc, char const *argv[]) {


  ekle(1, 20);
  ekle(2, 70);
  ekle(42, 80);
  ekle(4, 25);
  ekle(12, 44);
  ekle(14, 32);
  ekle(17, 11);
  ekle(13, 78);
  ekle(37, 97);
  ekle(82, 55);

  display();

  dugum* item;

  item = ara(82);

  if (item){
    printf("\n%d", item->data);

  }else{
    printf("Bulunamadi\n");
  }
  return 0;
}
