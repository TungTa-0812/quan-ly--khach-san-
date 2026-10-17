#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <climits>
int tim_phong_trong(int a[], int sophong) {
	for (int i = 0; i < sophong; i++) {
		if (a[i] == 0) {
			a[i] = 1;
			return i;
		}
	}
	return -1;
}

void liet_ke_phongtrong(int a[], int sophong) {
	int dem = 0;
	for (int i = 0; i < sophong; i++) {
		if (a[i] == 0) {
			printf("<< Phong %d dang con trong >>\n", i+1);
			dem++;
		}
	}
	if (dem == 0) {
		printf("<< Khong phong nao con trong! >>\n");
	}
}

void liet_ke_phongdathue(int a[], int sophong) {
	int dem = 0;
	for (int i = 0; i < sophong; i++) {
		if (a[i] == 1) {
			printf("<< Phong %d dang duoc thue >>\n", i + 1);
			dem++;
		}
	}
	if (dem == 0) {
		printf("<< Khong co phong nao da thue! >>\n");
	}
}

int main(){
	int sophong;
	int lua_chon;
	printf("Nhap so luong phong: ");
	scanf("%d", &sophong);
	int a[100] = { 0 };
	do {
		printf("<< WELCOME TO INIEE'S HOTEL >>\n");
		printf("1. Find out an empty room\n");
		printf("2. Check out\n");
		printf("3. List empty room\n");
		printf("4. List rented room\n");
		printf("5. Quit\n");
		scanf("%d", &lua_chon);
		switch (lua_chon) {
		case 1: {
			int phongtrong = tim_phong_trong(a, sophong);
			if (phongtrong == -1) {
				printf("<< Khong phong nao con trong! >>\n");
			}
			else {
				printf("<< Dang ki thanh cong phong %d! >>\n", phongtrong + 1);
			}
			break;
		}
		case 2: {
			printf("Nhap phong muon checkout: ");
			int n; scanf("%d", &n);
			int dem = 0;
			if (n >= 1 && n <= sophong) {
				if (a[n - 1] == 0) {
					printf("Phong chua dat sao ma tra!\n");
				}
				else {
					printf("Tra phong thanh cong!\n");
					a[n - 1] = 0;
				}
			}
			else if (n<1 || n>sophong) {
				printf("Loi xac thuc!\n");
			}
			break;
		}
		case 3: {
			liet_ke_phongtrong(a, sophong);
			break;
		}
		case 4: {
			liet_ke_phongdathue(a, sophong);
			break;
		}
		case 5: {
			printf("Cam on quy khach da su dung dich vu !!!\n");
			break;
		}
	}
	} while (lua_chon != 5);
	return 0;
}


