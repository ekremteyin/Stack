#include <stdio.h>
#include <stdlib.h>

struct Dugum {             // Ba�lang�� olarak bir structla d���m olu�turuldu
    int veri;
    struct Dugum* sonraki;
};

struct Dugum* top = NULL;    // D���m�n top de�eri ve i�i bo�a e�itlendi

void push(int deger) {
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum)); // Y���n�m�za eleman eklemek i�in ilk �nce memoryde haf�za a�t�k
    yeniDugum->veri = deger;
    yeniDugum->sonraki = top;
    top = yeniDugum;     // Y���n�m�zda ekledi�imiz her yeni de�er last in oldu�u i�in top de�erine e�itleniyor
    printf("\nEleman Eklendi: %d\n", deger);
}

void pop() {
    if (top == NULL) {
        printf("\nYigin Bos\n");
    } else {
        struct Dugum* temp = top;
        printf("\nSilinen Eleman: %d\n", temp->veri);
        top = temp->sonraki;
        free(temp);
    }
}

void peek() {
    if (top == NULL) {
        printf("\nYigin Bos\n");
    } else {
        printf("\nTepe Eleman: %d\n", top->veri);
    }
}

void yazdir() {
    if (top == NULL) {
        printf("\nYigin Bos\n");
    } else {
        struct Dugum* temp = top;
        printf("\nYigin Elemanlari: ");
        while (temp != NULL) {
            printf("%d ", temp->veri);
            temp = temp->sonraki;
        }
        printf("\n");
    }
}

void empty() {
    if (top == NULL) {
        printf("\nYigininiz bostur\n");
    } else {
        printf("\nYigininiz bos degildir\n");
    }
}

int main() {

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    int secim, eleman;

    while (1) {
        printf("\n1-Ekle\n2-Cikar\n3-Tepe Elemani Goster\n4-Yigindaki Elemanlari Goster\n5-Yigin Bos mu Kontrol Et\n");
        printf("Bir secenek girin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Yigina eklemek istediginiz elemani girin: ");
                scanf("%d", &eleman);
                push(eleman);
                yazdir();
                break;
            case 2:
                pop();
                yazdir();
                break;
            case 3:
                peek();
                break;
            case 4:
                yazdir();
                break;
            case 5:
                empty();
                break;

            default:
                printf("Yanlis secenek\n");
        }
    }

    return 0;
}
