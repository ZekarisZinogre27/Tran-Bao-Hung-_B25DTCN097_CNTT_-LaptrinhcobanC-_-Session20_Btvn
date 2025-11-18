#include<stdio.h>
struct Student {
    char name[50];
    int age;
    int phoneNumber;
};

int main(){
    struct Student hehehe;
    printf("Nhap ten sinh vien: ");
    getchar();
    fgets(hehehe.name, sizeof(hehehe.name), stdin);

    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &hehehe.age);

    printf("Nhap so dien thoai sinh vien: ");
    scanf("%d", &hehehe.phoneNumber);

    printf("\n===== THONG TIN SINH VIEN =====\n");
    printf("Ten: %s", hehehe.name);
    printf("Tuoi: %d\n", hehehe.age);
    printf("So dien thoai: %d\n", hehehe.phoneNumber);
    return 0;
}
