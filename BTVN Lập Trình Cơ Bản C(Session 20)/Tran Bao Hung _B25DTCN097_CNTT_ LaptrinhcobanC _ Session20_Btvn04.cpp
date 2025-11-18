#include<stdio.h>
#include<string.h>
#define MAX 50
struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};

int main() {
    struct Student students[MAX];
    int size = 5;
    printf("=== Nhap thong tin 5 sinh vien ===\n");
    for (int i = 0; i < size; i++) {
        students[i].id = i + 1;

        printf("\nSinh vien %d:\n", i + 1);

        printf("Nhap ten: ");
        scanf(" %[^\n]", students[i].name);

        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);

        printf("Nhap so dien thoai: ");
        scanf("%s", students[i].phoneNumber);
    }

    printf("\n=== DANH SACH SINH VIEN ===\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d | Name: %s | Age: %d | Phone: %s\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].phoneNumber);
    }
    return 0;
}
