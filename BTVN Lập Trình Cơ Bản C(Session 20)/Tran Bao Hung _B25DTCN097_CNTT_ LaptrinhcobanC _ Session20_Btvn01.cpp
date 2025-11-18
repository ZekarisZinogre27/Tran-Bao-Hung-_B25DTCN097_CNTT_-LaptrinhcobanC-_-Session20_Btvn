#include<stdio.h>
struct Student {
    char name[50];
    int age;
    int phoneNumber;
};

int main(){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin hoc sinh thu %d:\n", i + 1);

        printf("Nhap ten hoc sinh: ");
        getchar();
        fgets(students[i].name, sizeof(students[i].name), stdin);

        printf("Nhap tuoi hoc sinh: ");
        scanf("%d", &students[i].age);

        printf("Nhap so dien thoai cua hoc sinh: ");
        scanf("%d", &students[i].phoneNumber);
    }
    printf("\n===== DANH SACH SINH VIEN =====\n");
    for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("Ten: %s", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %d\n", students[i].phoneNumber);
    }
    return 0;
}
