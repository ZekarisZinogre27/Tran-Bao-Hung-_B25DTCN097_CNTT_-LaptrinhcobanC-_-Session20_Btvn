#include<stdio.h>
#include<string.h>
#define MAX 50
struct Student {
    char id[20];
    char name[50];
    int age;
    char phoneNumber[20];
};

int main() {
    struct Student students[MAX];
    int size = 5;
    printf("=== Nhap 5 sinh vien ban dau ===\n");
    for (int i = 0; i < size; i++) {
        printf("\nSinh vien %d:\n", i + 1);

        printf("Nhap ID: ");
        scanf("%s", students[i].id);

        printf("Nhap ten: ");
        scanf(" %[^\n]", students[i].name);

        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);

        printf("Nhap so dien thoai: ");
        scanf("%s", students[i].phoneNumber);
    }
    if (size >= MAX) {
        printf("Mang sinh vien da day, khong the them moi.\n");
        return 0;
    }
    printf("\n=== Nhap sinh vien moi can them ===\n");

    printf("Nhap ID: ");
    scanf("%s", students[size].id);

    printf("Nhap ten: ");
    scanf(" %[^\n]", students[size].name);

    printf("Nhap tuoi: ");
    scanf("%d", &students[size].age);

    printf("Nhap so dien thoai: ");
    scanf("%s", students[size].phoneNumber);
    size++;
    printf("\n=== DANH SACH SINH VIEN SAU KHI THEM ===\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %s | Name: %s | Age: %d | Phone: %s\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].phoneNumber);
    }
    return 0;
}
