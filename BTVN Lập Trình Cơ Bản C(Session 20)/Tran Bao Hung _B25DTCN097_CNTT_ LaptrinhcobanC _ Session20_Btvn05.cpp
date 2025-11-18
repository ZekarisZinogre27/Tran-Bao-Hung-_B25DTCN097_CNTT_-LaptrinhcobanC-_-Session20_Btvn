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
    printf("=== Nhap thong tin 5 sinh vien ban dau ===\n");
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

    int searchId;
    printf("\nNhap ID sinh vien can sua: ");
    scanf("%d", &searchId);

    int found = -1;
    for (int i = 0; i < size; i++) {
        if (students[i].id == searchId) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Khong tim thay sinh vien co ID %d!\n", searchId);
    } else {
        printf("Nhap thong tin moi cho sinh vien ID %d:\n", searchId);

        printf("Nhap ten moi: ");
        scanf(" %[^\n]", students[found].name);

        printf("Nhap tuoi moi: ");
        scanf("%d", &students[found].age);

        printf("Da sua thong tin sinh vien ID %d thanh cong!\n", searchId);
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
