#include "header.h"
const int MAX_LTC = 10000;
const int MAX_LOP = 2000;
// ========================= Danh sach sinh vien dang ky ==============================
struct DangKy {
	//data
	string MSV;
	double Diem = 0;
	bool huy = 0;
	//pointer
	DangKy* pnext = NULL;
};
struct dsDk {
	DangKy* phead = NULL;
	int sl = 0;
};
// ========================= Danh sach sinh vien ==============================
struct Sinhvien {
	//data
	string MaSV;
	string ho;
	string ten;
	string phai;
	string SDT;
	int daDK = 0;
	bool highlight = 0;
	//pointer
	Sinhvien* pnext = NULL;
};
struct dsSV {
	Sinhvien* phead = NULL;
	int sl = 0;
};
// ========================= Danh sach lop ================================
struct Lop {
	string MALOP;
	string TENLOP;
	dsSV pdsSV;
};
struct dsLop {
	Lop ds_lop[MAX_LOP];
	int soluong = 0;
};
// ========================= Danh sach mon hoc ==============================
struct MonHoc {
	//data
	string MaMon;
	string TenMH;
	double STCLT;
	double STCTH;
	bool dadk = 0;
	int freq = 0;
	bool hightlight = 0;
	//pointer
	MonHoc* pleft = NULL;
	MonHoc* pright = NULL;
};
struct dsMonHoc {
	MonHoc* ds = NULL;
	int sl = 0;
};
//===================== Danh sach lop TC =======================
struct LopTC {
	string MaMH;
	string nien_khoa;
	int MaLopTc; // so nguyen tu dong tang
	int Nhom = 1;
	int HK = 1;
	int min;
	int max;
	bool huylop = true;
	bool hightlight = 0;
	dsDk pdssvdk;
};
struct dsLopTc {
	LopTC* ds[MAX_LTC];
	int damo = 0;
};
int MA = 0;
void readfile_dsLop(string str, dsLop& dslop) {
	ifstream fileinput(str);
	if (!fileinput.is_open()) {
		cout << "Khong the mo file" << endl;
		return;
	}
	while (getline(fileinput, dslop.ds_lop[dslop.soluong].MALOP)) {
		while (true) {
			Sinhvien* sv = new Sinhvien();
			getline(fileinput, sv->MaSV);
			if (sv->MaSV == "###########") {
				delete sv;
				break;
			}
			getline(fileinput, sv->ho);
			getline(fileinput, sv->ten);
			getline(fileinput, sv->phai);
			getline(fileinput, sv->SDT);
			fileinput >> sv->daDK;
			fileinput.ignore();
			sv->pnext = NULL;
			if (dslop.ds_lop[dslop.soluong].pdsSV.phead == NULL) {
				dslop.ds_lop[dslop.soluong].pdsSV.phead = sv;
			}
			else {
				Sinhvien* tempSV = dslop.ds_lop[dslop.soluong].pdsSV.phead;
				while (tempSV->pnext != NULL) {
					tempSV = tempSV->pnext;
				}
				tempSV->pnext = sv;
			}

			dslop.ds_lop[dslop.soluong].pdsSV.sl++;
		}
		dslop.soluong++;
	}

	fileinput.close();
	return;
}
void writefile_dsLop(string str, dsLop& dslop) {
	ofstream fileoutput(str);
	if (fileoutput.is_open()) {
		//fileoutput << dslop.soluong << endl;
		for (int i = 0; i < dslop.soluong; i++) {
			Sinhvien* sv = dslop.ds_lop[i].pdsSV.phead;
			fileoutput << dslop.ds_lop[i].MALOP << endl;
			while (sv != NULL) {
				fileoutput << sv->MaSV << endl;
				fileoutput << sv->ho << endl;
				fileoutput << sv->ten << endl;
				fileoutput << sv->phai << endl;
				fileoutput << sv->SDT << endl;
				fileoutput << sv->daDK << endl;
				sv = sv->pnext;
			}
			fileoutput << "###########" << endl;
		}
		fileoutput.close();
	}
}
void readfile_dsLTC(string str, dsLopTc& dsLTC) {
	ifstream fileinput(str);
	if (!fileinput.is_open()) {
		cout << "Khong the mo file" << endl;
		return;
	}
	while (fileinput.peek() != EOF) {
		LopTC* LTC = new LopTC();
		if (!(fileinput >> LTC->MaLopTc)) {
			cout << "Loi khi doc MaLopTc";
			delete LTC;
			break;
		}
		++MA;
		fileinput.ignore();
		getline(fileinput, LTC->MaMH);
		getline(fileinput, LTC->nien_khoa);
		if (!(fileinput >> LTC->HK >> LTC->Nhom >> LTC->max >> LTC->min >> LTC->huylop)) {
			cout << "Loi khi doc thong tin LopTC" << endl;
			delete LTC;
			break;
		}
		//fileinput.ignore();
		while (1) {
			fileinput.ignore();
			DangKy* svDK = new DangKy();
			getline(fileinput, svDK->MSV);
			//cout << svDK->MSV;
			if (svDK->MSV == "======================") {
				delete svDK;
				break;
			}
			if (!(fileinput >> svDK->Diem >> svDK->huy)) {
				cout << "Loi khi doc thong tin DangKy" << endl;
				delete svDK;
				break;
			}
			svDK->pnext = NULL;
			if (LTC->pdssvdk.phead == NULL) {
				LTC->pdssvdk.phead = svDK;
			}
			else {
				DangKy* temp = LTC->pdssvdk.phead;
				while (temp->pnext != NULL) {
					temp = temp->pnext;
				}
				temp->pnext = svDK;
			}
			if(svDK->huy == 0)
			++LTC->pdssvdk.sl;
		}

		dsLTC.ds[dsLTC.damo] = LTC;
		++dsLTC.damo;
	}

	fileinput.close();
}
void writefile_dsLTC(string str, dsLopTc& dsLTC) {
	ofstream fileoutput(str);
	if (!fileoutput.is_open()) {
		cout << "Khong the mo file de ghi" << endl;
		return;
	}
	for (int i = 0; i < dsLTC.damo; ++i) {
		DangKy* svDK = dsLTC.ds[i]->pdssvdk.phead;
		fileoutput << dsLTC.ds[i]->MaLopTc << endl;
		fileoutput << dsLTC.ds[i]->MaMH << endl;
		fileoutput << dsLTC.ds[i]->nien_khoa << endl;
		fileoutput << dsLTC.ds[i]->HK << endl;
		fileoutput << dsLTC.ds[i]->Nhom << endl;
		fileoutput << dsLTC.ds[i]->max << endl;
		fileoutput << dsLTC.ds[i]->min << endl;
		fileoutput << dsLTC.ds[i]->huylop << endl;
		while (svDK != NULL) {
			fileoutput << svDK->MSV << endl;
			fileoutput << svDK->Diem << endl;
			fileoutput << svDK->huy << endl;
			svDK = svDK->pnext;
		}
		fileoutput << "======================" << endl;
	}
	fileoutput.close();
}
#pragma once