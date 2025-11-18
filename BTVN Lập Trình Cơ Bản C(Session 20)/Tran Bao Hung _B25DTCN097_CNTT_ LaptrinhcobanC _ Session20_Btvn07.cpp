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
    int size;
    do {
        printf("Nhap so luong sinh vien (toi da 50): ");
        scanf("%d", &size);
    } while (size < 1 || size > MAX);
    for (int i = 0; i < size; i++) {
        printf("\n=== Sinh vien %d ===\n", i + 1);

        printf("Nhap ID: ");
        scanf("%s", students[i].id);

        printf("Nhap ten: ");
        scanf(" %[^\n]", students[i].name);

        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);

        printf("Nhap so dien thoai: ");
        scanf("%s", students[i].phoneNumber);
    }
    char deleteId[20];
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%s", deleteId);
    int found = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].id, deleteId) == 0) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Sinh vien co ID %s khong ton tai!\n", deleteId);
    } else {
        for (int i = found; i < size - 1; i++) {
            students[i] = students[i + 1];
        }
        size--;
        printf("Da xoa sinh vien co ID %s thanh cong!\n", deleteId);
    }
    printf("\n=== DANH SACH SINH VIEN SAU KHI XOA ===\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %s | Name: %s | Age: %d | Phone: %s\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].phoneNumber);
    }
    return 0;
}
