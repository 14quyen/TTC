#include<iostream>

void NhapMang(float a[], int n);
void XuatMang(float a[], int n);

int main() {
    int  n, val, pos;
    float a[100];
    printf(" Nhap so phan tu mang A: ");
    scanf_s("%d", &n);
    printf(" Nhap cac phan tu mang A:\n");
    NhapMang(a, n);
    printf(" Mang A: ");
    XuatMang(a, n);
    int maxsum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += a[k];
            if (sum > maxsum)
                maxsum = sum;

        }

    }
    printf("\t%d", maxsum);
}


void NhapMang(float a[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" Phan tu thu %d: ", i);
        scanf_s("%f", &a[i]);
    }
}
void XuatMang(float a[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %1.0f ", a[i]);
    }
}