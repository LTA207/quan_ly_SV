#include "CTDL.h"
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
			if (svDK->huy == 0)
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
		fileoutput << dsLTC.ds[i]->min << endl;
		fileoutput << dsLTC.ds[i]->max << endl;
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
int read_data(MonHoc*& MH, ifstream& fileinput, string maMon) {
	if (maMon == "=====================") return 0;
	if (MH == NULL) {
		MH = new MonHoc();
		MH->MaMon = maMon;
		//cout << "ma mon la: " << MH->MaMon << " ";
		getline(fileinput, MH->TenMH);
		//cout << "ten mon la: " << MH->TenMH << " ";
		fileinput >> MH->STCLT;
		//cout << "STCLT la: " << MH->STCLT << " ";
		fileinput >> MH->STCTH;
		//cout << "STCTH la: " << MH->STCTH << endl;
		MH->pleft = NULL;
		MH->pright = NULL;
		fileinput.ignore();
		return 1;
	}
	else if (MH->MaMon == maMon) {
		cout << "mon hoc da ton tai";
		return 0;
	}
	else if (maMon > MH->MaMon) {
		int result = read_data(MH->pright, fileinput, maMon);
		return result;
	}
	else if (maMon < MH->MaMon) {
		int result = read_data(MH->pleft, fileinput, maMon);
		return result;
	}
	can_bang(MH);
	return 0;
}
void readfile_dsMH(string str, dsMonHoc& dsMH) {
	string maMon;
	ifstream fileinput(str);
	if (!fileinput.is_open()) {
		cout << "khong the mo file" << endl;
		return;
	}
	while (getline(fileinput, maMon)) {
		if (read_data(dsMH.ds, fileinput, maMon)) dsMH.sl++;
	}
	fileinput.close();
	return;
}
void write_Data(MonHoc*& MH, ofstream& fileoutput) {
	if (MH != NULL) {
		write_Data(MH->pleft, fileoutput);
		fileoutput << MH->MaMon << endl;
		fileoutput << MH->TenMH << endl;
		fileoutput << MH->STCLT << endl;
		fileoutput << MH->STCTH << endl;
		fileoutput << "=====================" << endl;
		write_Data(MH->pright, fileoutput);
	}
}
void writefile_dsMH(string str, dsMonHoc& dsMH) {
	ofstream fileoutput(str);
	if (!fileoutput.is_open()) {
		cout << "khong the mo file de ghi" << endl;
		return;
	}
	write_Data(dsMH.ds, fileoutput);
	fileoutput.close();
}
#pragma once
