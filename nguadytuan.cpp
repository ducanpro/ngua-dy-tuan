#include <stdio.h>
int dx[] = {2, 1, -2, -1, 2, 1, -2, -1};
int dy[] = {1, 2, -1, -2, -1, -2, 1, 2};
int found = 0;

void khoitaomatran(int a[][100], int n){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = 0;
	 	}	
	}
}

void xuatmatran(int a[][100],int n){
	printf("\t\t\t\t\tBAN CO MA DI TUAN\n");
	for(int i = 1; i <= n; i++){
		printf("\t\t\t\t\t");
		for(int j = 1; j <= n; j++ ){
			printf("%2d ", a[i][j]);
		}
	printf("\n");	
	}
}
void dituan(int x, int y, int n, int dem, int a[][100]){
	if(found){
		return;
	}
	if(dem == n*n){
		xuatmatran(a, n);
		found = 1; //da tim thay
		return;
	}
	for(int i = 0; i < 8; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx <= n && yy <= n && xx >= 1 && yy >= 1 && a[xx][yy] == 0){
			a[xx][yy] = dem + 1;
			dituan(xx, yy, n, dem +1, a);
						
			if(!found){
				a[xx][yy]= 0;
			}
		}
	}

	
}
int main(){
	int a[100][100], n = 5 ;
	int x , y;
//	printf("Nhap kich thuoc ban co(n x n): ");
//	scanf("%d", &n);
	khoitaomatran(a, n);
	printf("Nhap vi tri quan ma (hang x cot(tu 1->5)): ");// 5x5 
	scanf("%d %d", &x, &y);
	
	if(x <= n && y <= n && x >= 1 && y >= 1){
		a[x][y] = 1;
		dituan(x, y, n, 1, a);
		if(!found){
			printf("khong tim thay loi giai");
		}
	} else{
		printf("vi tri ban nhap khong nam trong ban co");
	}
	

	return 0;
}



