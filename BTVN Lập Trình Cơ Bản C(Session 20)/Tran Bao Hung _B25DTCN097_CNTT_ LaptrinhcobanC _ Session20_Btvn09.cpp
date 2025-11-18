#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_MENU 100
#define NAME_LEN 50

struct Dish {
    int id;
    char name[NAME_LEN];
    double price;
};

struct Dish menu[MAX_MENU];
int sizeMenu = 0;

void inputDish(struct Dish *d) {
    printf("Nhap id: ");
    scanf("%d", &d->id);
    getchar();
    printf("Nhap ten mon: ");
    fgets(d->name, NAME_LEN, stdin);
    d->name[strcspn(d->name, "\n")] = 0;
    printf("Nhap gia: ");
    scanf("%lf", &d->price);
}

void printMenu() {
    printf("Danh sach menu:\n");
    for(int i = 0; i < sizeMenu; i++) {
        printf("%d. id: %d, name: %s, price: %.2f\n",
               i+1, menu[i].id, menu[i].name, menu[i].price);
    }
}

void addDish() {
    if(sizeMenu >= MAX_MENU) {
        printf("Menu full!\n");
        return;
    }
    int pos;
    printf("Nhap vi tri can them (1-%d): ", sizeMenu+1);
    scanf("%d", &pos);
    if(pos < 1 || pos > sizeMenu+1) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    struct Dish newDish;
    inputDish(&newDish);
    for(int i = sizeMenu; i >= pos; i--) {
        menu[i] = menu[i-1];
    }
    menu[pos-1] = newDish;
    sizeMenu++;
}

void editDish() {
    int pos;
    printf("Nhap vi tri can sua (1-%d): ", sizeMenu);
    scanf("%d", &pos);
    if(pos < 1 || pos > sizeMenu) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    inputDish(&menu[pos-1]);
}

void deleteDish() {
    int pos;
    printf("Nhap vi tri can xoa (1-%d): ", sizeMenu);
    scanf("%d", &pos);
    if(pos < 1 || pos > sizeMenu) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for(int i = pos-1; i < sizeMenu-1; i++) {
        menu[i] = menu[i+1];
    }
    sizeMenu--;
}

int comparePriceAsc(const void *a, const void *b) {
    double diff = ((struct Dish*)a)->price - ((struct Dish*)b)->price;
    if(diff > 0) return 1;
    else if(diff < 0) return -1;
    return 0;
}

int comparePriceDesc(const void *a, const void *b) {
    double diff = ((struct Dish*)b)->price - ((struct Dish*)a)->price;
    if(diff > 0) return 1;
    else if(diff < 0) return -1;
    return 0;
}

void sortMenu() {
    int choice;
    printf("1. Giam dan theo price\n2. Tang dan theo price\nChon: ");
    scanf("%d", &choice);
    if(choice == 1) qsort(menu, sizeMenu, sizeof(struct Dish), comparePriceDesc);
    else if(choice == 2) qsort(menu, sizeMenu, sizeof(struct Dish), comparePriceAsc);
    else printf("Lua chon khong hop le!\n");
}

void linearSearch() {
    char key[NAME_LEN];
    getchar();
    printf("Nhap ten mon can tim: ");
    fgets(key, NAME_LEN, stdin);
    key[strcspn(key, "\n")] = 0;
    int found = 0;
    for(int i = 0; i < sizeMenu; i++) {
        if(strcmp(menu[i].name, key) == 0) {
            printf("Tim thay o vi tri %d: id=%d, name=%s, price=%.2f\n",
                   i+1, menu[i].id, menu[i].name, menu[i].price);
found = 1;
        }
    }
    if(!found) printf("Khong tim thay!\n");
}

void binarySearch() {
    char key[NAME_LEN];
    getchar();
    printf("Nhap ten mon can tim: ");
    fgets(key, NAME_LEN, stdin);
    key[strcspn(key, "\n")] = 0;
    qsort(menu, sizeMenu, sizeof(struct Dish), 
          (int (*)(const void*, const void*)) strcmp);

    int left = 0, right = sizeMenu-1;
    int found = 0;
    while(left <= right) {
        int mid = (left + right)/2;
        int cmp = strcmp(menu[mid].name, key);
        if(cmp == 0) {
            printf("Tim thay o vi tri %d: id=%d, name=%s, price=%.2f\n",
                   mid+1, menu[mid].id, menu[mid].name, menu[mid].price);
            found = 1;
            break;
        } else if(cmp < 0) left = mid+1;
        else right = mid-1;
    }
    if(!found) printf("Khong tim thay!\n");
}

int main() {
    printf("Nhap so luong mon an ban dau (toi da 5): ");
    scanf("%d", &sizeMenu);
    if(sizeMenu > 5) sizeMenu = 5;
    getchar();
    for(int i=0; i<sizeMenu; i++) {
        printf("Nhap thong tin mon %d:\n", i+1);
        inputDish(&menu[i]);
    }

    int choice;
    do {
        printf("\nMENU\n");
        printf("1. In menu\n");
        printf("2. Them mon\n");
        printf("3. Sua mon\n");
        printf("4. Xoa mon\n");
        printf("5. Sap xep\n");
        printf("6. Tim kiem\n");
        printf("7. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printMenu(); break;
            case 2: addDish(); break;
            case 3: editDish(); break;
            case 4: deleteDish(); break;
            case 5: sortMenu(); break;
            case 6: {
                int sub;
                printf("1. Tim tuyen tinh\n2. Tim nhi phan\nChon: ");
                scanf("%d", &sub);
                if(sub == 1) linearSearch();
                else if(sub == 2) binarySearch();
                else printf("Lua chon khong hop le!\n");
                break;
            }
            case 7: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while(choice != 7);
    return 0;
}
