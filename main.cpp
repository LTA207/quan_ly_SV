#include "CTDL.h"
#include <sstream>
#include <iomanip>
#include "SupProcess.h"
// ====================================================================== DANH SACH SINH VIEN ======================================================
int nhap_ho_SV(string& hoSV) {
	char c;
	cout << hoSV;

	while (true) {
		c = _getch();
		if (c == 27) return 0;
		if (c == '\r') {
			break;
		}
		if (hoSV.length() > 21) continue;
		if (!isalpha(c) && c != ' ' && c != 8) continue;
		if (c == ' ' || isalpha(c)) {
			if ((hoSV.empty() && c == ' ') || (!hoSV.empty() && hoSV[hoSV.length() - 1] == ' ' && c == ' ')) {
				continue;
			}
			if ('a' <= c && c <= 'z') {
				c = toupper(c);
			}
		}
		if (c == 8) {
			if (hoSV.empty()) continue;
			else {
				hoSV.pop_back();
				cout << "\b \b";
				continue;
			}
		}
		cout << c;
		hoSV += c;
	}
	return 1;
}
int nhap_ten_SV(string& tenSV) {
	char c;
	cout << tenSV;
	while (1) {
		c = _getch();
		if (c == 27) return 0;
		if (c == '\r') {
			break;
		}
		if (c == 8) {
			if (!tenSV.empty()) {
				tenSV.pop_back();
				cout << "\b \b";
			}
		}
		if (tenSV.length() > 10) continue;
		if (c == ' ' || !isalpha(c)) {
			continue;
		}
		if (c >= 'a' && c <= 'z') {
			c = toupper(c);
		}
		cout << c;
		tenSV += c;
	}
	return 1;
}
void nhap_nien_khoa(string& nien_khoa) {
	char c;
	cout << nien_khoa;
	while (true) {
		c = _getch();
		if (c == 13) {
			break;
		}
		if ((c != '-' && c != 8 && !isalnum(c)) || isalpha(c)) continue;
		if (c == 8) {
			if (nien_khoa.empty()) continue;
			else {
				nien_khoa.pop_back();
				cout << "\b \b";
				continue;
			}
		}
		cout << c;
		nien_khoa += c;
	}
}
int nhap_gioi_tinh(string& phai) {
	while (1)
	{
		char key;
		key = _getch();
		if (key == 27) return 0;
		if (key == 8) {
			if (!phai.empty()) {
				phai.pop_back();
				cout << "\b \b";
			}
		}
		if (key == '0') {
			phai = "NU";
			cout << phai;
			break;
		}
		else if (key == '1') {
			phai = "NAM";
			cout << phai;
			break;
		}
		else continue;
	}
	return 1;
}
int nhap_SDT(string& sdt) {
	while (1) {
		char c;
		c = _getch();
		if (c == 27) return 0;
		if (c == 13) return 1;
		if (c == 8) {
			if (!sdt.empty()) {
				sdt.pop_back();
				cout << "\b \b";
			}
		}
		if (sdt.length() > 10) continue;
		if ('0' <= c && c <= '9') {
			cout << c;
			sdt += c;
		}
	}
	return 1;
}
int nhap_diem() {
	string tmp;
	while (1) {
		char c;
		c = _getch();
		if (c == 27) return 0;
		if (c == 13) {
			if (tmp.empty())
				return 0;
			else return stoi(tmp);
		}
		if (c == 8) {
			if (!tmp.empty()) {
				tmp.pop_back();
				cout << "\b \b";
			}
		}
		//if (sdt.length() > 10) continue;
		if ('0' <= c && c <= '9') {
			cout << c;
			tmp += c;
		}
	}
}
void khung_ds_SV(int x, int y, int w, int h) {
	SetColor(3);
	for (int i = 0; i <= w; i += 23) {
		for (int iy = y; iy < y + 25; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
	}
	for (int ix = x; ix < x + w; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + 25);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + 25); cout << char(217);
	gotoxy(x, y + 25); cout << char(192);
	gotoxy(x += 10, y += 1); cout << "MSV";
	gotoxy(x += 23, y); cout << "HO";
	gotoxy(x += 23, y); cout << "TEN";
	gotoxy(x += 20, y); cout << "GIOI TINH";
	gotoxy(x += 26, y); cout << "SDT";
	gotoxy(0, 27); cout << "A:Them SV";
	gotoxy(15, 27); cout << "E: Hieu chinh";
	gotoxy(35, 27); cout << "D: Xoa SV";
	gotoxy(55, 27); cout << "ESC: Thoat";
	gotoxy(124, 13); cout << "UP";
	gotoxy(124, 14); cout << char(94);
	gotoxy(123, 17); cout << "DOWN";
	gotoxy(124, 16); cout << "v";
	gotoxy(126, 15); cout << "> RIGHT";
	gotoxy(117, 15); cout << "LEFT <";
}
void in_ds_SV(dsSV& ds, int page) {
	dsSV SV = ds;
	int i = 1;
	int j = 3;
	int count = 0;
	if (page > 1) {
		for (int h = 1; h <= 11 * (page - 1); ++h) {
			SV.phead = SV.phead->pnext;
			++count;
		}
	}
	while (SV.phead != NULL && count < 11 * page) {
		int i = 1;
		gotoxy(i, j);
		cout << SV.phead->MaSV << endl;
		gotoxy(i += 23, j);
		cout << SV.phead->ho << endl;
		gotoxy(i += 23, j);
		cout << SV.phead->ten << endl;
		gotoxy(i += 23, j);
		cout << SV.phead->phai << endl;
		gotoxy(i += 23, j);
		cout << SV.phead->SDT << endl;
		SV.phead = SV.phead->pnext;
		j += 2;
		++count;
	}
}
void in_thong_tin_SV(Sinhvien* sv, int j) {
	int i = 1;
	gotoxy(i, j);
	cout << sv->MaSV << ' ';
	gotoxy(i += 23, j);
	cout << sv->ho << ' ';
	gotoxy(i += 23, j);
	cout << sv->ten << ' ';
	gotoxy(i += 23, j);
	cout << sv->phai << ' ';
	gotoxy(i += 23, j);
	cout << sv->SDT << ' ';
}
void nhap_SV(dsSV& dssv) {
	Sinhvien* SV;
	Sinhvien* current = dssv.phead;
	Sinhvien* prevSV = NULL;
	int i;
	int j = 3;
	int count = 0;
	do {
		i = 1;
		if (count == 11) {
			system("cls");
			count = 0;
			khung_ds_SV(0, 0, 115, 2);
			j = 3;
		}
		gotoxy(i, j);
		string maSV;
		SV = new Sinhvien();
		getline(cin, maSV);
		if (maSV.empty()) {
			break;
		}
		SV->MaSV = maSV;
		SV->pnext = NULL;
		gotoxy(i += 23, j);
		if (nhap_ho_SV(SV->ho) == 0) break;
		gotoxy(i += 23, j);
		if (nhap_ten_SV(SV->ten) == 0) break;
		gotoxy(i += 23, j);
		if (nhap_gioi_tinh(SV->phai) == 0) break;
		gotoxy(i += 23, j);
		if (nhap_SDT(SV->SDT) == 0) break;
		j += 2;
		++count;
		if (current == NULL || (SV->ho + SV->ten < current->ho + current->ten)) {
			SV->pnext = current;
			if (prevSV != NULL) {
				prevSV->pnext = SV;
			}
			else {
				dssv.phead = SV;
			}
		}
		else {
			while (current->pnext != NULL && (current->ho + current->pnext->ten < SV->ho + SV->ten)) {
				current = current->pnext;
			}
			SV->pnext = current->pnext;
			current->pnext = SV;
		}
		dssv.sl++;
		prevSV = NULL;
		current = dssv.phead;
	} while (true);
}
Sinhvien* menu_ds_SV(dsSV& dssv, int& page, int maxpage) {
	int choice = page * 11 - 11;
	int option = dssv.sl;
	Sinhvien* SV = dssv.phead;
	do {
		int count = 0;
		int jy = 3;
		Sinhvien* SV = dssv.phead;
		system("cls");
		khung_ds_SV(0, 0, 115, 2);
		if (page > 1) {
			for (int h = 1; h <= 11 * (page - 1); ++h) {
				SV = SV->pnext;
				++count;
			}
		}
		for (int i = page * 11 - 11; i < 11 * page && SV != NULL; ++i) {
			if (choice == i) {
				highlight(i);
			}
			else {
				normal(i);
			}
			in_thong_tin_SV(SV, jy);
			SV = SV->pnext;
			jy += 2;
		}
		char key;
		key = _getch();
		if (key == 27) return NULL;
		switch (key) {
		case 72: {
			--choice;
			if (choice < page * 11 - 11) {
				if (page < maxpage) {
					choice = page * 11 - 1;
				}
				else {
					choice = dssv.sl - 1;
				}
				highlight(choice);
			}
			else {
				normal(choice);
			}
			break;
		}
		case 80: {
			++choice;
			if (choice > option - 1) {
				choice = maxpage * 11 - 11;
				highlight(choice);
			}
			else if (choice > page * 11 - 1) {
				choice = page * 11 - 11;
				highlight(choice);
			}
			else {
				highlight(choice);
			}
			break;
		}
		case 13: {
			SV = dssv.phead;
			for (int i = 0; i < choice && SV != NULL; ++i) {
				SV = SV->pnext;
			}
			return SV;
		}
		case 75: {
			if (page > 1) {
				page--;
				choice = page * 11 - 11;
				highlight(choice);
			}
			break;
		}
		case 77: {
			if (page * 11 < option) {
				page++;
				choice = page * 11 - 11;
				highlight(choice);
			}
			break;
		}
		}
	} while (1);
}
void xoa_SV(dsSV& dssv, Sinhvien* sv) {
	Sinhvien* current = dssv.phead;
	Sinhvien* prev = nullptr;
	if (sv == NULL) return;
	if (current == nullptr) {
		cout << "Danh sach rong." << endl;
		return;
	}
	if (current != nullptr && current->MaSV == sv->MaSV) {
		dssv.phead = current->pnext;
		delete current;
		dssv.sl--;
		return;
	}
	while (current != nullptr && current->MaSV != sv->MaSV) {
		prev = current;
		current = current->pnext;
	}
	if (current == nullptr) {
		cout << "Khong tim thay sinh vien can xoa." << endl;
		return;
	}
	prev->pnext = current->pnext;
	delete current;
	dssv.sl--;
}
void hieu_chinh_SV(dsSV& dssv, Sinhvien* sv) {
	system("cls");
	Sinhvien* tmp = dssv.phead;
	Sinhvien* prevtmp = NULL;
	if (sv == NULL) return;
	while (tmp != NULL) {
		if (tmp->MaSV == sv->MaSV) {
			cout << "Nhap ho sinh vien:";
			nhap_ho_SV(tmp->ho);
			cout << "\nnhap ten sinh vien:";
			nhap_ten_SV(tmp->ten);
			cout << "\nnhap gioi tinh: ";
			nhap_gioi_tinh(tmp->phai);
			cout << "\nnhap so dien thoai: ";
			nhap_SDT(tmp->SDT);
			break;
		}
		prevtmp = tmp;
		tmp = tmp->pnext;
	}
	if (tmp == NULL) {
		cout << "Khong tim thay sinh vien co MaSV = " << sv->MaSV << endl;
		return;
	}
	if (prevtmp != NULL) {
		prevtmp->pnext = tmp->pnext;
	}
	else {
		dssv.phead = tmp->pnext;
	}
	Sinhvien* cur = dssv.phead;
	Sinhvien* prevcur = NULL;

	while (cur != NULL && (cur->ten < tmp->ten || (cur->ten == tmp->ten && cur->ho < tmp->ho))) {
		prevcur = cur;
		cur = cur->pnext;
	}
	if (prevcur != NULL) {
		tmp->pnext = cur;
		prevcur->pnext = tmp;
	}
	else {
		tmp->pnext = dssv.phead;
		dssv.phead = tmp;
	}
}
void kiem_tra_ds_SV(dsLop& dslop) {
	string malop;
	char c;
	int curpage = 1;
	cout << "nhap ma lop: ";
	getline(cin, malop);
	for (int i = 0; i < dslop.soluong; ++i) {
		if (malop == dslop.ds_lop[i].MALOP) {
			while (1) {
				int page = 0;
				if (dslop.ds_lop[i].pdsSV.sl == 0) page = 1;
				else if (dslop.ds_lop[i].pdsSV.sl % 11 != 0) {
					page = dslop.ds_lop[i].pdsSV.sl / 11 + 1;
				}
				else page = dslop.ds_lop[dslop.soluong].pdsSV.sl / 11;
				system("cls");
				khung_ds_SV(0, 0, 115, 2);
				in_ds_SV(dslop.ds_lop[i].pdsSV, curpage);
				gotoxy(120, 0); cout << curpage << "/" << page;
				c = _getch();
				if (c == 27) return;
				switch (c) {
				case 'a': {
					system("cls");
					khung_ds_SV(0, 0, 115, 2);
					nhap_SV(dslop.ds_lop[i].pdsSV);
					break;
				}
				case 'e': {
					system("cls");
					khung_ds_SV(0, 0, 115, 2);
					hieu_chinh_SV(dslop.ds_lop[i].pdsSV, menu_ds_SV(dslop.ds_lop[i].pdsSV, curpage, page));
					break;
				}
				case 'd': {
					system("cls");
					khung_ds_SV(0, 0, 115, 2);
					xoa_SV(dslop.ds_lop[i].pdsSV, menu_ds_SV(dslop.ds_lop[i].pdsSV, curpage, page));
					break;
				}
				case 75: {
					if (curpage > 1)
						curpage--;
				}
				case 77: {
					if (curpage < page)
						curpage++;
				}
				}
			}
		}
		else continue;
	}
	if (dslop.soluong < 2000) {
		dslop.ds_lop[dslop.soluong].MALOP = malop;
		while (1) {
			int page;
			if (dslop.ds_lop[dslop.soluong].pdsSV.sl == 0) page = 1;
			else if (dslop.ds_lop[dslop.soluong].pdsSV.sl % 11 != 0) {
				page = dslop.ds_lop[dslop.soluong].pdsSV.sl / 11 + 1;
			}
			else page = dslop.ds_lop[dslop.soluong].pdsSV.sl / 11;
			system("cls");
			khung_ds_SV(0, 0, 115, 2);
			gotoxy(120, 0); cout << curpage << "/" << page;
			gotoxy(120, 2); cout << dslop.ds_lop[dslop.soluong].MALOP;
			in_ds_SV(dslop.ds_lop[dslop.soluong].pdsSV, curpage);
			c = _getch();
			if (c == 27) break;
			switch (c) {
			case 'a': {
				system("cls");
				khung_ds_SV(0, 0, 115, 2);
				nhap_SV(dslop.ds_lop[dslop.soluong].pdsSV);
				break;
			}
			case 'e': {
				system("cls");
				khung_ds_SV(0, 0, 115, 2);
				hieu_chinh_SV(dslop.ds_lop[dslop.soluong].pdsSV, menu_ds_SV(dslop.ds_lop[dslop.soluong].pdsSV, curpage, page));
				break;
			}
			case 'd': {
				system("cls");
				khung_ds_SV(0, 0, 115, 2);
				xoa_SV(dslop.ds_lop[dslop.soluong].pdsSV, menu_ds_SV(dslop.ds_lop[dslop.soluong].pdsSV, curpage, page));
				break;
			}
			case 75: {
				if (curpage > 1)
					--curpage;
				break;
			}
			case 77: {
				if (curpage < page)
					++curpage;
				break;
			}
			}
		}
		dslop.soluong++;
	}
	else {
		cout << "danh sach lop da day!";
	}
}
void In_ds_SV_cua_lop(dsLop& dsLop) {
	Lop lop;
	cout << "nhap ma lop:";
	cin.ignore();
	getline(cin, lop.MALOP);
	system("cls");
	khung_ds_SV(0, 0, 112, 2);
	for (int i = 0; i < dsLop.soluong; ++i) {
		if (dsLop.ds_lop[i].MALOP == lop.MALOP) {
			in_ds_SV(dsLop.ds_lop[i].pdsSV, 1);
			break;
		}
	}
}


// ====================================================== DANH SACH MON HOC ======================================================================
int MA_MON = 0;
void nhap_ten_MH(string& tenMH) {
	char c;
	cout << tenMH;
	while (true) {
		c = _getch();
		if (c == 13) {
			break;
		}
		if (tenMH.length() > 15) continue;
		if (!isalpha(c) && c != ' ' && c != 8 && !isalnum(c)) continue;
		if (c == ' ' || isalpha(c) || isalnum(c)) {
			if ((tenMH.empty() && c == ' ') || (!tenMH.empty() && tenMH[tenMH.length() - 1] == ' ' && c == ' ')) {
				continue;
			}
			if ('a' <= c && c <= 'z') {
				c = toupper(c);
			}
		}
		if (c == 8) {
			if (tenMH.empty()) continue;
			else {
				tenMH.pop_back();
				cout << "\b \b";
				continue;
			}
		}
		cout << c;
		tenMH += c;
	}
}
void nhap_ma_mon(string& maMH) {
	char c;
	cout << maMH;
	while (1) {
		c = _getch();
		if (c == 27) return;
		if (c == '\r') {
			break;
		}
		if (maMH.length() > 10) continue;
		if (!isalpha(c) && c != 8 && !isalnum(c)) continue;
		if (c >= 'a' && c <= 'z') {
			c = toupper(c);
		}
		if (c == 8) {
			if (maMH.empty()) continue;
			else {
				maMH.pop_back();
				cout << "\b \b";
				continue;
			}
		}
		cout << c;
		maMH += c;
	}
}
void khung_ds_MH(int x, int y, int w, int h) {
	SetColor(3);
	for (int i = 0; i <= w; i += 29) {
		for (int iy = y; iy < y + 25; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
	}
	for (int ix = x; ix < x + w; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + 25);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + 25); cout << char(217);
	gotoxy(x, y + 25); cout << char(192);
	gotoxy(x += 10, y += 1); cout << "MA MH";
	gotoxy(x += 29, y); cout << "TEN MH";
	gotoxy(x += 29, y); cout << "STCLT";
	gotoxy(x += 29, y); cout << "STCTH";
	gotoxy(0, 27); cout << "A:Them SV";
	gotoxy(15, 27); cout << "E: Hieu chinh";
	gotoxy(35, 27); cout << "D: Xoa SV";
	gotoxy(55, 27); cout << "ESC: Thoat";
	gotoxy(124, 13); cout << "UP";
	gotoxy(124, 14); cout << char(94);
	gotoxy(123, 17); cout << "DOWN";
	gotoxy(124, 16); cout << "v";
	gotoxy(126, 15); cout << "> RIGHT";
	gotoxy(117, 15); cout << "LEFT <";
}
void xoay_trai(MonHoc*& MH) {
	MonHoc* tmp;
	if (MH == NULL) return;
	if (MH->pright == NULL) return;
	else {
		tmp = MH->pright;
		MH->pright = tmp->pleft;
		tmp->pleft = MH;
	}
}
void xoay_phai(MonHoc*& MH) {
	MonHoc* tmp;
	if (MH == NULL) return;
	if (MH->pleft == NULL) return;
	else {
		tmp = MH->pleft;
		MH->pleft = tmp->pright;
		tmp->pright = MH;
	}
}
int chieu_cao(MonHoc* MH) {
	if (MH == NULL) return 0;
	int left = chieu_cao(MH->pleft);
	int right = chieu_cao(MH->pright);
	return max(left, right) + 1;
}
int check_can_bang(MonHoc* MH) {
	if (MH == NULL) return 1;
	int lh = chieu_cao(MH->pleft);
	int rh = chieu_cao(MH->pright);
	if (abs(lh - rh) > 1) return 0;
	return check_can_bang(MH->pleft) && check_can_bang(MH->pright);
}
int bf(MonHoc* MH) {
	return chieu_cao(MH->pleft) - chieu_cao(MH->pright);
}
void can_bang(MonHoc*& MH) {
	if (!check_can_bang(MH)) {
		if (chieu_cao(MH->pleft) > chieu_cao(MH->pright)) {
			MonHoc* tmp = MH->pleft;
			if (chieu_cao(tmp->pleft) >= chieu_cao(tmp->pright)) {
				xoay_phai(MH);
			}
			else {
				xoay_trai(MH->pleft);
				xoay_phai(MH);
			}
		}
		else {
			MonHoc* tmp = MH->pright;
			if (chieu_cao(tmp->pright) >= chieu_cao(tmp->pleft)) {
				xoay_trai(tmp);
			}
			else {
				xoay_phai(tmp->pright);
				xoay_trai(tmp);
			}
		}
	}
	if (MH->pleft != NULL) can_bang(MH->pleft);
	if (MH->pright != NULL) can_bang(MH->pright);
}
int them_MH(MonHoc*& dsMH, string maMH, int& y) {
	int x = 30;
	if (dsMH == NULL) {
		gotoxy(x, y);
		dsMH = new MonHoc();
		nhap_ten_MH(dsMH->TenMH);
		gotoxy(x += 29, y);
		cout << "Enter STCLT: ";
		cin >> dsMH->STCLT;
		gotoxy(x += 29, y);
		cout << "Enter STCTH: ";
		cin >> dsMH->STCTH;
		dsMH->MaMon = maMH;
		dsMH->pleft = NULL;
		dsMH->pright = NULL;
		return 1;
	}
	else if (dsMH->MaMon == maMH) {
		cout << "Mon hoc da ton tai!" << endl;
		return 0;
	}
	else if (maMH > dsMH->MaMon) {
		int result = them_MH(dsMH->pright, maMH, y);
		return result;
	}
	else if (maMH < dsMH->MaMon) {
		int result = them_MH(dsMH->pleft, maMH, y);
		return result;
	}
	can_bang(dsMH);
	//ten_MH[MA_MON] = tenMH;
	return 0;
}
void thay_the(MonHoc*& tmp, MonHoc*& MH) {
	if (MH->pleft != NULL) thay_the(tmp, MH->pleft);
	else {
		tmp->MaMon = MH->MaMon;
		tmp->TenMH = MH->TenMH;
		tmp->STCLT = MH->STCLT;
		tmp->STCTH = MH->STCTH;
		MonHoc* rightChild = MH->pright;
		delete MH;
		MH = rightChild;
	}
}
void xoa_MH(MonHoc*& dsMH, string maMH) {
	if (dsMH == NULL) return;
	if (dsMH->MaMon < maMH) xoa_MH(dsMH->pright, maMH);
	else if (dsMH->MaMon > maMH) xoa_MH(dsMH->pleft, maMH);
	else {
		MonHoc* tmp = dsMH;
		if (tmp->pleft == NULL) dsMH = tmp->pright;
		else if (tmp->pright == NULL) dsMH = tmp->pleft;
		else {
			thay_the(tmp, tmp->pright);
		}
		delete tmp;
		//[tenMH.length() - 1] = "";
	}
}
void hieu_chinh_MH(MonHoc*& dsMH, string maMH) {
	system("cls");
	int y = 3;
	if (dsMH == NULL) return;
	MonHoc* tmp = dsMH;
	while (tmp != NULL && tmp->MaMon != maMH) {
		if (tmp->MaMon > maMH) tmp = tmp->pleft;
		else if (tmp->MaMon < maMH) tmp = tmp->pright;
	}
	cout << "nhap ma mon hoc: ";
	string newMaMH;
	//nhap_ten_MH(newTenMH);
	getline(cin, newMaMH);
	them_MH(dsMH, newMaMH, y);
	xoa_MH(dsMH, maMH);
}
void in_ds_MH(MonHoc*& MH, int& y, int& count, int page) {
	int x = 1;
	if (MH != NULL) {
		in_ds_MH(MH->pleft, y, count, page);
		++count;
		if (page > 1) {
			if ((page - 1) * 22 <= count && count < page * 22) {
				gotoxy(x, y);
				cout << MH->MaMon;
				gotoxy(x += 29, y);
				cout << MH->TenMH;
				gotoxy(x += 29, y);
				cout << MH->STCLT;
				gotoxy(x += 29, y);
				cout << MH->STCTH;
				y += 1;
			}
		}
		else if (count <= 22) {
			gotoxy(x, y);
			cout << MH->MaMon;
			gotoxy(x += 29, y);
			cout << MH->TenMH;
			gotoxy(x += 29, y);
			cout << MH->STCLT;
			gotoxy(x += 29, y);
			cout << MH->STCTH;
			y += 1;
		}
		in_ds_MH(MH->pright, y, count, page);
	}
}
void in_ds_MH(MonHoc*& MH, int choice, int& count, int& y, int page) {
	int x = 1;
	if (MH != NULL) {
		in_ds_MH(MH->pleft, choice, count, y, page);
		count++;
		if ((page - 1) * 22 < count && count < page * 22) {
			if (choice == count - 1) SetColor(9);
			else SetColor(7);
			gotoxy(x, y);
			cout << MH->MaMon;
			gotoxy(x += 29, y);
			cout << MH->TenMH;
			gotoxy(x += 29, y);
			cout << MH->STCLT;
			gotoxy(x += 29, y);
			cout << MH->STCTH;
			y += 1;
		}
		in_ds_MH(MH->pright, choice, count, y, page);
	}
}
void chen_MH_theo_ten(MonHoc* MH, MonHoc** MHarr, int& i) {
	if (MH != NULL) {
		chen_MH_theo_ten(MH->pleft, MHarr, i);
		int j = i - 1;
		while (j >= 0 && MHarr[j]->TenMH > MH->TenMH) {
			MHarr[j + 1] = MHarr[j];
			--j;
		}
		MHarr[j + 1] = MH;
		++i;
		chen_MH_theo_ten(MH->pright, MHarr, i);
	}
}
MonHoc* mang_MH[100];
void in_ds_MH_theo_ten(dsMonHoc& dsMH) {
	int size = 0;
	int page = 1;
	int maxpage;
	chen_MH_theo_ten(dsMH.ds, mang_MH, size);
	khung_ds_MH(0, 0, 116, 2);
	while (1) {
		int y = 3;
		if (dsMH.sl == 0) maxpage = 1;
		else if (dsMH.sl % 22 != 0)
			maxpage = dsMH.sl / 22 + 1;
		else maxpage = 1;
		for (int j = page * 22 - 22; j < page * 22 && mang_MH[j] != NULL; ++j) {
			int x = 1;
			gotoxy(x, y);
			cout << mang_MH[j]->MaMon;
			gotoxy(x += 29, y);
			cout << mang_MH[j]->TenMH;
			gotoxy(x += 29, y);
			cout << mang_MH[j]->STCLT;
			gotoxy(x += 29, y);
			cout << mang_MH[j]->STCTH;
			y += 1;
		}
		char key = _getch();
		if (key == 27) break;
		switch (key) {
		case 75: {
			if (page > 1) 
				--page;
			break;
		}
		case 77: {
			if (page < maxpage)
				++page;
			break; 
		}
		}
	}
}
string tim_ma_MH(MonHoc*& dsMH, int choice, int& count) {
	if (dsMH != NULL) {
		string leftResult = tim_ma_MH(dsMH->pleft, choice, count);
		++count;
		if (choice == count - 1) {
			return dsMH->MaMon;
		}
		string rightResult = tim_ma_MH(dsMH->pright, choice, count);
		if (leftResult != "") {
			return leftResult;
		}
		else {
			return rightResult;
		}
	}
	return "";
}
string tim_ten_MH(MonHoc*& dsMH, string maMon) {
	if (dsMH != NULL) {
		string leftResult = tim_ten_MH(dsMH->pleft, maMon);
		if (dsMH->MaMon == maMon) {
			return dsMH->TenMH;
		}
		string rightResult = tim_ten_MH(dsMH->pright, maMon);
		if (leftResult != "") {
			return leftResult;
		}
		else {
			return rightResult;
		}
	}
	return "";
}
MonHoc* tim_MH(MonHoc*& dsMH, string maMon) {
	if (dsMH != NULL) {
		MonHoc* leftResult = tim_MH(dsMH->pleft, maMon);
		if (dsMH->MaMon == maMon) {
			return dsMH;
		}
		MonHoc* rightResult = tim_MH(dsMH->pright, maMon);
		if (leftResult != NULL) {
			return leftResult;
		}
		else {
			return rightResult;
		}
	}
	return NULL;
}
string menu_ds_MH(dsMonHoc& dsMH, int page, int maxpage, string& selected) {
	int choice = page * 22 - 22;
	int option = dsMH.sl;
	while (1) {
		int count = 0;
		int y = 3;
		system("cls");
		khung_ds_MH(0, 0, 116, 2);
		in_ds_MH(dsMH.ds, choice, count, y, page);
		char key;
		key = _getch();
		if (key == 27) break;
		if (key == 13) {
			count = 0;
			selected = tim_ma_MH(dsMH.ds, choice, count);
			return selected;
		}
		switch (key) {
		case 72: {
			--choice;
			if (choice < page * 22 - 22) {
				if (page < maxpage) {
					choice = page * 22 - 1;
				}
				else {
					choice = dsMH.sl - 1;
				}
			}
			//if (choice < 0) choice = option - 1;
			break;
		}
		case 80: {
			++choice;
			if (choice > option - 1) {
				choice = maxpage * 22 - 22;
			}
			else if (choice > page * 22 - 1) {
				choice = page * 22 - 22;
			}
			//if (choice > option - 1) choice = 0;
			break;
		}
		case 75: {
			if (page > 1) {
				page--;
				choice = page * 22 - 22;
				//highlight(choice);
			}
			break;
		}
		case 77: {
			if (page * 22 < option) {
				page++;
				choice = page * 22 - 22;
				//highlight(choice);
			}
			break;
		}
		}
	}
}
void ds_MH(dsMonHoc& dsMH) {
	int maxpage;
	int page = 1;
	char c;
	while (1) {
		int count = 0;
		int y = 3;
		if (dsMH.sl == 0) maxpage = 1;
		else if (dsMH.sl % 22 != 0)
			maxpage = dsMH.sl / 22 + 1;
		else maxpage = 1;
		system("cls");
		khung_ds_MH(0, 0, 116, 2);
		in_ds_MH(dsMH.ds, y, count, page);
		//in_ds_MH_theo_ten(dsMH, y, page, maxpage);
		gotoxy(120, 3);
		cout << page << '/' << maxpage;
		c = _getch();
		if (c == 27) break;
		switch (c) {
		case 'a': {
			while (1) {
				if (y == 25) {
					y = 3;
					system("cls");
					khung_ds_MH(0, 0, 116, 2);
				}
				gotoxy(1, y);
				string maMH;
				nhap_ma_mon(maMH);
				//nhap_ten_MH(tenMH);
				if (maMH == "") break;
				if (them_MH(dsMH.ds, maMH, y)) {
					dsMH.sl++;
					++y;
				}
			}
			break;
		}
		case 'e': {
			string selected;
			menu_ds_MH(dsMH, page, maxpage, selected);
			hieu_chinh_MH(dsMH.ds, selected);
			break;
		}
		case 'd': {
			system("cls");
			string selected;
			menu_ds_MH(dsMH, page, maxpage, selected);
			xoa_MH(dsMH.ds, selected);
			dsMH.sl--;
			--y;
			break;
		}
		case 75: {
			if (page > 1)
				--page;
			break;
		}
		case 77: {
			if (page < maxpage)
				++page;
			break;
		}
		}
	}
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


//========================================================= Mo lop TC ===========================================================================
int MA = 0;
void khung_LTC(int x, int y, int w, int h) {
	SetColor(3);
	for (int i = 0; i <= w; i += 15) {
		for (int iy = y; iy < y + 25; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
	}
	for (int ix = x; ix < x + w; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + 25);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + 25); cout << char(217);
	gotoxy(x, y + 25); cout << char(192);
	gotoxy(x += 2, y += 1); cout << "MA LOP TC";
	gotoxy(x += 15, y); cout << "MA MH";
	gotoxy(x += 15, y); cout << "NIEN KHOA";
	gotoxy(x += 15, y); cout << "HOC KI";
	gotoxy(x += 15, y); cout << "NHOM";
	gotoxy(x += 15, y); cout << "SO SV MAX";
	gotoxy(x += 15, y); cout << "SO SV MIN";
	gotoxy(x += 15, y); cout << "TRANG THAI";
}
void khung_dk_LTC(int x, int y, int w, int h) {
	SetColor(3);
	gotoxy(40, y - 1); cout << "CAC LOP TC DA MO";
	for (int i = 0; i <= w; i += 15) {
		for (int iy = y; iy < y + 12; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
	}
	for (int ix = x; ix < x + w; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + 12);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + 12); cout << char(217);
	gotoxy(x, y + 12); cout << char(192);
	gotoxy(x += 2, y += 1); cout << "MA MON";
	gotoxy(x += 15, y); cout << "TEN MON";
	gotoxy(x += 15, y); cout << "NHOM";
	gotoxy(x += 15, y); cout << "SO SV DA DK";
	gotoxy(x += 15, y); cout << "SO SLOT TRONG";
	gotoxy(x += 15, y); cout << "TRANG THAI";
}
void khung_nhap_diem(int x, int y, int w, int h) {
	SetColor(3);
	for (int i = 0; i <= w; i += 18) {
		for (int iy = y; iy < y + 26; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
	}
	for (int ix = 1; ix < x + w; ++ix) {
		for (int iy = y; iy <= y + 26; iy += 2) {
			gotoxy(ix, iy);
			cout << char(196);
			//gotoxy(ix, y + h);
			//cout << char(196);
			//gotoxy(ix, y + 25);
			//cout << char(196);
		}
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + 26); cout << char(217);
	gotoxy(x, y + 26); cout << char(192);
	gotoxy(x += 10, y += 1); cout << "STT";
	gotoxy(x += 18, y); cout << "MSV";
	gotoxy(x += 18, y); cout << "HO";
	gotoxy(x += 18, y); cout << "TEN";
	gotoxy(x += 18, y); cout << "DIEM";
	//gotoxy(0, 27); cout << "A:Them SV";
	//gotoxy(15, 27); cout << "E: Hieu chinh";
	//gotoxy(35, 27); cout << "D: Xoa SV";
	//gotoxy(55, 27); cout << "ESC: Thoat";
	gotoxy(124, 13); cout << "UP";
	gotoxy(124, 14); cout << char(94);
	gotoxy(123, 17); cout << "DOWN";
	gotoxy(124, 16); cout << "v";
	gotoxy(126, 15); cout << "> RIGHT";
	gotoxy(117, 15); cout << "LEFT <";
}
int MaLTC(string MaMH) {
	int MaLTC = ++MA;
	return MaLTC;
}
void them_lop_TC(dsLopTc& DSLTC) {
	int y = 3;
	string MaMH;
	while (1) {
		int x = 16;
		gotoxy(x, y);
		getline(cin, MaMH);
		if (MaMH == "") break;
		LopTC* p = new LopTC();
		p->MaMH = MaMH;
		p->MaLopTc = MaLTC(p->MaMH);
		gotoxy(x += 15, y);
		getline(cin, p->nien_khoa);
		gotoxy(x += 15, y);
		cin >> p->HK;
		gotoxy(x += 15, y);
		cin >> p->Nhom;
		gotoxy(x += 15, y);
		cin >> p->max;
		gotoxy(x += 15, y);
		cin >> p->min;
		p->huylop = 1;
		cin.ignore();
		DSLTC.ds[DSLTC.damo] = p;
		++DSLTC.damo;
		++y;
	}
}
void in_lop_tc(dsLopTc& DSLTC, int i) {
	/*for (int i = 0; i < DSLTC.damo; ++i) {
		cout << "ma lop TC:";
		cout << DSLTC.ds[i]->MaLopTc;
		cout << "ma mon hoc:";
		cout << DSLTC.ds[i]->MaMH;
		cout << "Nien khoa:";
		cout << DSLTC.ds[i]->nien_khoa;
		cout << "Hoc ky:";
		cout << DSLTC.ds[i]->HK;
		cout << "nhom:";
		cout << DSLTC.ds[i]->Nhom;
		cout << "so sinh vien min:";
		cout << DSLTC.ds[i]->min;
		cout << "so sinh vien max:";
		cout << DSLTC.ds[i]->max;
		cout << endl;
	}*/
	cout << "ma lop TC:";
	cout << DSLTC.ds[i]->MaLopTc;
	cout << "ma mon hoc:";
	cout << DSLTC.ds[i]->MaMH;
	cout << "Nien khoa:";
	cout << DSLTC.ds[i]->nien_khoa;
	cout << "Hoc ky:";
	cout << DSLTC.ds[i]->HK;
	cout << "nhom:";
	cout << DSLTC.ds[i]->Nhom;
	cout << "so sinh vien min:";
	cout << DSLTC.ds[i]->min;
	cout << "so sinh vien max:";
	cout << DSLTC.ds[i]->max;
	cout << endl;
}
void in_ds_lop_tc(dsLopTc& DSLTC, int page, int maxpage) {
	int y = 3;
	if (DSLTC.damo == 0) return;
	for (int i = page * 11 - 11;; ++i) {
		int x = 1;
		if (page == 1 || page == maxpage) {
			if (i >= DSLTC.damo)
				break;
		}
		gotoxy(x, y);
		cout << DSLTC.ds[i]->MaLopTc;
		gotoxy(x += 15, y);
		cout << DSLTC.ds[i]->MaMH;
		gotoxy(x += 15, y);
		cout << DSLTC.ds[i]->nien_khoa;
		gotoxy(x += 15, y);
		cout << DSLTC.ds[i]->HK;
		gotoxy(x += 15, y);
		cout << DSLTC.ds[i]->Nhom;
		gotoxy(x += 15, y);
		cout << DSLTC.ds[i]->min;
		gotoxy(x += 15, y);
		cout << DSLTC.ds[i]->max;
		++y;
	}
	return;
}
void xoa_lop_TC(dsLopTc& DSLTC, LopTC* lop) {
	for (int i = 0; i < DSLTC.damo; ++i) {
		if (lop->MaLopTc == DSLTC.ds[i]->MaLopTc) {
			delete DSLTC.ds[i];
			for (int j = i; j < DSLTC.damo; ++j) {
				DSLTC.ds[j] = DSLTC.ds[j + 1];
			}
			--DSLTC.damo;
		}
	}
}
void hieu_chinh_lop_TC(dsLopTc& DSLTC, LopTC* lop) {
	for (int i = 0; i < DSLTC.damo; ++i) {
		if (lop->MaLopTc == DSLTC.ds[i]->MaLopTc) {
			cout << "Nhap ma mon hoc: ";
			cin.ignore();
			getline(cin, DSLTC.ds[i]->MaMH);

			cout << "Nhap nien khoa: ";
			getline(cin, DSLTC.ds[i]->nien_khoa);

			cout << "Nhap hoc ky: ";
			cin >> DSLTC.ds[i]->HK;

			cout << "Nhap nhom: ";
			cin >> DSLTC.ds[i]->Nhom;

			cout << "Nhap so sinh vien min: ";
			cin >> DSLTC.ds[i]->min;

			cout << "Nhap so sinh vien max: ";
			cin >> DSLTC.ds[i]->max;

			//cout << "Trang thai huy lop (1: Da huy, 0: Chua huy): ";
			//cin >> DSLTC.ds[i]->huylop;
		}
		break;
	}
}
LopTC* menu_Mo_Lop_TC(dsLopTc& DSLTC, int& page, int maxpage) {
	int choice = page * 11 - 11;
	int option = DSLTC.damo;
	while (true) {
		int count = 0;
		int jy = 3;
		clrscr();
		for (int i = page * 11 - 11; i < page * 11; ++i) {
			if (page == 1 || page == maxpage) {
				if (i >= DSLTC.damo)
					break;
			}
			if (choice == i) {
				SetColor(3);
			}
			else {
				SetColor(7);
			}
			in_lop_tc(DSLTC, i);
			jy += 2;
		}
		char key;
		key = _getch();
		switch (key) {
		case 72: {
			--choice;
			if (choice < page * 11 - 11) {
				if (page < maxpage) {
					choice = page * 11 - 1;
				}
				else {
					choice = DSLTC.damo - 1;
				}
				highlight(choice);
			}
			else {
				normal(choice);
			}
			break; 
		}
		case 80: {
			++choice;
			if (choice > option - 1) {
				choice = maxpage * 11 - 11;
				highlight(choice);
			}
			else if (choice > page * 11 - 1) {
				choice = page * 11 - 11;
				highlight(choice);
			}
			else {
				highlight(choice);
			}
			break;
		}
		case 13: {
			if (choice >= 0 && choice < DSLTC.damo) {
				return DSLTC.ds[choice];
			}
		}
		case 75: {
			if (page > 1) {
				page--;
				choice = page * 11 - 11;
				highlight(choice);
			}
			break;
		}
		case 77: {
			if (page * 11 < option) {
				page++;
				choice = page * 11 - 11;
				highlight(choice);
			}
			break;
		}
		}
		}
	}
void cap_nhat_lop_TC(dsLopTc& dsLTC) {
	int page = 1;
	int maxpage;
	char c;
	while (1) {
		if (dsLTC.damo == 0) maxpage = 1;
		else if (dsLTC.damo % 11 != 0) maxpage = dsLTC.damo / 11 + 1;
		else maxpage = dsLTC.damo / 11;
		system("cls");
		khung_LTC(0, 0, 120, 2);
		gotoxy(123, 1);
		cout << page << '/' << maxpage;
		in_ds_lop_tc(dsLTC, page, maxpage);
		c = _getch();
		if (c == 27) return;
		switch (c) {
		case 'a': {
			system("cls");
			khung_LTC(0, 0, 120, 2);
			them_lop_TC(dsLTC);
			break;
		}
		case'd': {
			system("cls");
			//khung_LTC(0, 0, 120, 2);
			xoa_lop_TC(dsLTC, menu_Mo_Lop_TC(dsLTC, page, maxpage));
			break;
		}
		case 'e': {
			system("cls");
			//khung_LTC(0, 0, 120, 2);
			hieu_chinh_lop_TC(dsLTC, menu_Mo_Lop_TC(dsLTC, page, maxpage));
			break;
		}
		case 75: {
			if (page > 1) --page;
			break;
		}
		case 77: {
			if (page < maxpage) ++page;
			break;
		}
		}
	}
}
void in_ds_SV_DK(dsLopTc& dsLTC, dsLop& dslop) {
	LopTC* ltc = new LopTC();
	int jy = 3;
	cout << "nhap nien khoa:";
	cin >> ltc->nien_khoa;
	cout << "nhap hoc ky:";
	cin >> ltc->HK;
	cout << "nhap ma mon:";
	cin >> ltc->MaMH;
	cout << "nhap nhom:";
	cin >> ltc->Nhom;
	//khung_ds_SV(0, 0, 115, 2);
	for (int i = 0; i < dsLTC.damo; ++i) {
		if (ltc->MaMH == dsLTC.ds[i]->MaMH && ltc->nien_khoa == dsLTC.ds[i]->nien_khoa && ltc->HK == dsLTC.ds[i]->HK && ltc->Nhom == dsLTC.ds[i]->Nhom) {
			DangKy* dk = dsLTC.ds[i]->pdssvdk.phead;
			while (dk != NULL && !dk->huy) {
				for (int i = 0; i < dslop.soluong; ++i) {
					Sinhvien* sv = dslop.ds_lop[i].pdsSV.phead;
					while (sv != NULL) {
						if (dk->MSV == sv->MaSV && dk->huy == 0) {
							in_thong_tin_SV(sv, jy);
							jy += 2;
							break;
						}
						else sv = sv->pnext;
					}
				}
				dk = dk->pnext;
			}
		}
	}
	delete ltc;
}
// chua hoan thien
void in_lop_TC_DK(LopTC* LTC, dsMonHoc& dsMH, int y) {
	int x = 1;
	gotoxy(x, y); cout << LTC->MaMH;
	gotoxy(x += 15, y); cout << tim_ten_MH(dsMH.ds, LTC->MaMH);
	gotoxy(x += 15, y); cout << LTC->Nhom;
	gotoxy(x += 15, y); cout << LTC->pdssvdk.sl;
	gotoxy(x += 15, y); cout << LTC->max - LTC->pdssvdk.sl;
}
int kiem_tra_svDK(LopTC*& ltc, string maSV) {
	DangKy* tmp = ltc->pdssvdk.phead;
	if (tmp == NULL) return 0;
	else {
		while (tmp != NULL) {
			if (tmp->MSV == maSV && tmp->huy == 0) return 1;
			tmp = tmp->pnext;
		}
	}
	return 0;
}
int menu_dk_lop_TC(dsLopTc& dsltc, dsMonHoc& dsMH, string maSV, string nien_khoa, int hk, int mode){
	int choice = 0;
	int option = dsltc.damo;
	khung_dk_LTC(0, 3, 90, 12);
	khung_dk_LTC(0, 18, 90, 12);
	while (1) {
		int count = 0;
		int mark = 0;
		int iy = 5;
		int jy = 20;
		for (int i = 0; i < dsltc.damo; ++i) {
			if (mode == 'a') {
				if (kiem_tra_svDK(dsltc.ds[i], maSV)) {
					SetColor(7);
					in_lop_TC_DK(dsltc.ds[i], dsMH, jy);
					jy += 1;
				}
				else if (dsltc.ds[i]->nien_khoa == nien_khoa && dsltc.ds[i]->HK == hk) {
					if (choice == count) {
						SetColor(17);
						mark = i;
					}
					else SetColor(7);
					++count;
					in_lop_TC_DK(dsltc.ds[i], dsMH, iy);
					iy += 1;
				}
			}
			if (mode == 'd') {
				if (dsltc.ds[i]->nien_khoa == nien_khoa && dsltc.ds[i]->HK == hk && !kiem_tra_svDK(dsltc.ds[i], maSV)) {
					SetColor(7);
					in_lop_TC_DK(dsltc.ds[i], dsMH, iy);
					++iy;
				}
				else if (kiem_tra_svDK(dsltc.ds[i], maSV)) {
					if (choice == count) {
						SetColor(17);
						mark = i;
					}
					else SetColor(7);
					in_lop_TC_DK(dsltc.ds[i], dsMH, jy);
					++count;
					++jy;
				}
			}
		}
		char key;
		key = _getch();
		if (key == 27) return -1;
		switch (key) {
		case 72: {
			--choice;
			if (choice < 0) {
				choice = count - 1;
			}
			break;
		case 80: {
			++choice;
			if (choice > count - 1) {
				choice = 0;
			}
			break;
		}
		/*case 72: {
			--choice;
			if (choice < page * 11 - 11) {
				if (page < maxpage) {
					choice = page * 11 - 1;
				}
				else {
					choice = count;
				}
				highlight(choice);
			}
			else {
				normal(choice);
			}
			break;
		case 80: {
			++choice;
			if (choice > count - 1) {
				choice = maxpage * 11 - 11;
				highlight(choice);
			}
			else if (choice > page * 11 - 1) {
				choice = page * 11 - 11;
				highlight(choice);
			}
			else {
				highlight(choice);
			}
			break;
		}*/
		case 13: {
			return mark;
			break;
		}
		/*case 75: {
			if (page > 1) {
				page--;
				choice = page * 11 - 11;
				highlight(choice);
			}
			break;
		}
		/*case 77: {
			if (page * 11 < option) {
				page++;
				choice = page * 11 - 11;
				highlight(choice);
			}
			break;
		}*/
		}
		}
	}
}
int them_SV_DK(LopTC*& LTC, string maSV) {
	system("cls");
	SetColor(7);
	DangKy* svDK = LTC->pdssvdk.phead;
	DangKy* tmp = new DangKy();
	tmp->MSV = maSV;
	tmp->huy = 0;
	if (svDK == NULL) {
		LTC->pdssvdk.phead = tmp;
		return 1;
	}
	else {
		while (svDK != NULL) {
			if (svDK->MSV == maSV) {
				svDK->huy = 0;
				return 1;
			}
			svDK = svDK->pnext;
		}
		svDK->pnext = tmp;
		return 1;
	}
	return 0;
}
int HUY_DK_LOP_TC(LopTC*& LTC, string maSV) {
	system("cls");
	SetColor(7);
	DangKy* svDK = LTC->pdssvdk.phead;
	while (svDK != NULL) {
		if (maSV == svDK->MSV) {
			svDK->huy = 1;
			return 1;
		}
		svDK = svDK->pnext;
	}
	return 0;
}
void DK_LOP_TC(dsLopTc& dsltc, dsLop& dslop, dsMonHoc& dsMH) {
	string maSV;
	string nien_khoa;
	int check;
	nhap_ma_mon(maSV);
	int mode;
	for (int i = 0; i < dslop.soluong; ++i) {
		dsSV dssv = dslop.ds_lop[i].pdsSV;
		while (dssv.phead != NULL) {
			if (maSV == dssv.phead->MaSV) {
				system("cls");
				in_thong_tin_SV(dssv.phead, 0);
				check = 1;
				break;
			}
		}
		if (check) break;
	}
	cout << "nhap nien khoa:";
	nhap_nien_khoa(nien_khoa);
	int hk;
	cout << "nhap hoc ki:";
	cin >> hk;
	while (1) {
		khung_dk_LTC(0, 3, 90, 12);
		khung_dk_LTC(0, 18, 90, 12);
		int iy = 5;
		int jy = 20;
		for (int i = 0; i < dsltc.damo; ++i) {
			if (kiem_tra_svDK(dsltc.ds[i], maSV)) {
				in_lop_TC_DK(dsltc.ds[i], dsMH, jy);
				++jy;
			}
			else {
				if (!kiem_tra_svDK(dsltc.ds[i], maSV) && dsltc.ds[i]->nien_khoa == nien_khoa && dsltc.ds[i]->HK == hk) {
					in_lop_TC_DK(dsltc.ds[i], dsMH, iy);
					++iy;
				}
			}
		}
		char key = _getch();
		if (key == 27) return;
		switch (key) {
		case 'a': {
			mode = 'a';
			int i = menu_dk_lop_TC(dsltc, dsMH, maSV, nien_khoa, hk, mode);
			if (i != -1) {
				if (them_SV_DK(dsltc.ds[i], maSV)) ++dsltc.ds[i]->pdssvdk.sl;
				if (dsltc.ds[i]->pdssvdk.sl >= dsltc.ds[i]->min) dsltc.ds[i]->huylop = 0;
				break;
			}
		}
		case 'd': {
			mode = 'd';
			int i = menu_dk_lop_TC(dsltc, dsMH, maSV, nien_khoa, hk, mode);
			if (i != -1) {
				if(HUY_DK_LOP_TC(dsltc.ds[i], maSV)) 
					if(dsltc.ds[i]->pdssvdk.sl>0) --dsltc.ds[i]->pdssvdk.sl;
				if (dsltc.ds[i]->pdssvdk.sl < dsltc.ds[i]->min) dsltc.ds[i]->huylop = 1;
				break;
			}
		}
		}
	}
}


// ======================================================== NHAP VA IN BANG DIEM ================================================================
void in_thong_tin_nhap_diem(dsLop& dslop, DangKy* svdk, int y, int count = 0) {
	int x = 1;
	for (int i = 0; i < dslop.soluong; ++i) {
		Sinhvien* tmp = dslop.ds_lop[i].pdsSV.phead;
		while (tmp != NULL) {
			if (tmp->MaSV == svdk->MSV) {
				gotoxy(x, y);
				cout << count;
				gotoxy(x += 18, y);
				cout << tmp->MaSV;
				gotoxy(x += 18, y);
				cout << tmp->ho;
				gotoxy(x += 18, y);
				cout << tmp->ten;
				gotoxy(x += 18, y);
				cout << svdk->Diem;
				return;
			}
			tmp = tmp->pnext;
		}
	}
}
int menu_nhap_diem(LopTC*& lopTC, dsLop& dslop) {
	int choice = 0;
	int option = lopTC->pdssvdk.sl;
	while (1) {
		int count = 0;
		int iy = 3;
		DangKy* dk = lopTC->pdssvdk.phead;
		while (dk != NULL) {
			if (choice == count) SetColor(17);
			else SetColor(7);
			in_thong_tin_nhap_diem(dslop, dk, iy);
			++count;
			iy += 2;
			dk = dk->pnext;
		}
		char key = _getch();
		if (key == 27) return -1;
		if (key == 13) {
			int j = 3;
			DangKy* tmp = lopTC->pdssvdk.phead;
			for (int i = 0; i < choice; ++i) {
				tmp = tmp->pnext;
				j += 2;
			}
			gotoxy(73, j);
			cout << "   ";
			gotoxy(73, j);
			SetColor(7);
			int check = nhap_diem();
			if(check != 0)
			tmp->Diem = check;
		}
		switch (key) {
		case 72: {
			--choice;
			if (choice < 0) choice = option - 1;
			break;
		}
		case 80: {
			++choice;
			if (choice > option - 1) choice = 0;
			break;
		}
		}
	}
}
void Nhap_diem(dsLopTc& dsltc, dsLop& dslop) {
	string nien_khoa;
	string maMH;
	int hk;
	int nhom;
	cout << "nhap nien khoa:";
	nhap_ma_mon(nien_khoa);
	cout << "\nnhap hoc ky:";
	cin >> hk;
	cout << "nhap nhom:";
	cin >> nhom;
	cout << "nhap ma mon:";
	nhap_ma_mon(maMH);
	for (int i = 0; i < dsltc.damo; ++i) {
		if (dsltc.ds[i]->nien_khoa == nien_khoa && dsltc.ds[i]->HK == hk && dsltc.ds[i]->Nhom == nhom && dsltc.ds[i]->MaMH == maMH) {
			system("cls");
			khung_nhap_diem(0, 0, 90, 2);
			int selected = menu_nhap_diem(dsltc.ds[i], dslop);
			if (selected == -1) return;
		}
	}
}
void in_bang_diem_MH(LopTC* ltc, dsLop& dslop, int page, string tenMH){
	int count = 0;
	gotoxy(58, 0); cout << "BANG DIEM MON HOC " << tenMH;
	gotoxy(58, 1); cout << "Nien khoa: " << ltc->nien_khoa << " " << "Hoc ky: " << ltc->HK << " " << "Nhom: " << ltc->Nhom;
	int iy = 6;
	DangKy* dk = ltc->pdssvdk.phead;
	if (page > 1) {
		for (int i = 1; i <= 11 * (page - 1); ++i) {
			dk = dk->pnext;
			++count;
		}
	}
	while (dk != NULL && count < 11 * page) {
		++count;
		in_thong_tin_nhap_diem(dslop, dk, iy, count);
		iy += 2;
		dk = dk->pnext;
	}
}
double tinh_diem_TB(dsLopTc& dsltc, string maSV, dsMonHoc& dsMH) {
	double diemTB = 0;
	double soTC = 0;
	for (int i = 0; i < dsltc.damo; ++i) {
		DangKy* dk = dsltc.ds[i]->pdssvdk.phead;
		while (dk != NULL) {
			if (maSV == dk->MSV) {
				MonHoc* tmp = tim_MH(dsMH.ds, dsltc.ds[i]->MaMH);
				if (tmp != NULL) {
					soTC += tmp->STCLT + tmp->STCTH;
					diemTB += (tmp->STCLT + tmp->STCTH) * dk->Diem;
					break;
				}
			}
			dk = dk->pnext;
		}
	}
	return diemTB / soTC;
}
void in_bang_diem_TB(dsLopTc& dsltc, Lop& lop, dsMonHoc& dsMH, int page) {
	int count = 0;
	int iy = 6;
	gotoxy(28, 0); cout << "BANG THONG KE DIEM TRUNG BINH KHOA HOC";
	gotoxy(40, 1); cout << "Lop: <" << lop.MALOP << ">";
	Sinhvien* SV = lop.pdsSV.phead;
	if (page > 1) {
		for (int i = 1; i <= 11 * (page - 1); ++i) {
			SV = SV->pnext;
			++count;
		}
	}
	while (SV != NULL && count < page * 11) {
		int x = 1;
		++count;
		gotoxy(x, iy);
		cout << count;
		gotoxy(x += 18, iy);
		cout << SV->MaSV;
		gotoxy(x += 18, iy);
		cout << SV->ho;
		gotoxy(x += 18, iy);
		cout << SV->ten;
		gotoxy(x += 18, iy);
		cout << setprecision(2) << fixed << tinh_diem_TB(dsltc, SV->MaSV, dsMH);
		iy += 2;
		SV = SV->pnext;
	}
}
void in_bang_diem(dsLopTc& dsltc, dsMonHoc& dsMH, dsLop& dslop) {
	int choice = 0;
	int option = 3;
	while (1) {
		clrscr();
		for (int i = 0; i < option; ++i) {
			if (choice == i) {
				SetColor(13);
			}
			else SetColor(7);
			switch (i) {
			case 0: {
				cout << "In bang diem mon hoc cua lop TC" << endl;
				break;
			}
			case 1: {
				cout << "In bang diem trung binh ket thuc mon" << endl;
				break;
			}
			case 2: {
				cout << "In bang diem tong ket cac mon" << endl;
				break;
			}
			}
		}
		char key = _getch();
		switch (key) {
		case 13: {
			if (choice == 0) {
				system("cls");
				string nien_khoa;
				string maMH;
				int hk;
				int nhom;
				cout << "nhap nien khoa:";
				nhap_ma_mon(nien_khoa);
				cout << "\nnhap hoc ky:";
				cin >> hk;
				cout << "nhap nhom:";
				cin >> nhom;
				cout << "nhap ma mon:";
				nhap_ma_mon(maMH);
				for (int i = 0; i < dsltc.damo; ++i) {
					if (dsltc.ds[i]->nien_khoa == nien_khoa && dsltc.ds[i]->HK == hk && dsltc.ds[i]->Nhom == nhom && dsltc.ds[i]->MaMH == maMH) {
						system("cls");
						khung_nhap_diem(0, 3, 90, 2);
						while (1) {
							int page = 1;
							string tenMH = tim_ten_MH(dsMH.ds, dsltc.ds[i]->MaMH);
							in_bang_diem_MH(dsltc.ds[i], dslop, page, tenMH);
							key = _getch();
							if (key == 27) break;
							switch (key) {
							case 75: {
								if (page > 1) {
									page--;
								}
								break;
							}
							case 77: {
								if (page * 11 < dsltc.ds[i]->pdssvdk.sl) {
									page++;
								}
								break;
							}
							}
						}
						break;
					}
				}
			}
			else if (choice == 1) {
				system("cls");
				string malop;
				cout << "nhap ma lop: ";
				nhap_ma_mon(malop);
				for (int i = 0; i < dslop.soluong; ++i) {
					if (dslop.ds_lop[i].MALOP == malop) {
						system("cls");
						khung_nhap_diem(0, 3, 90, 2);
						while (1) {
							int page = 1;
							in_bang_diem_TB(dsltc, dslop.ds_lop[i], dsMH, page);
							key = _getch();
							if (key == 27) break;
							switch (key) {
							case 75: {
								if (page > 1) {
									page--;
								}
								break;
							}
							case 77: {
								if (page * 11 < dslop.ds_lop[i].pdsSV.sl) {
									page++;
								}
								break;
							}
							}
						}
						break;
					}
				}
			}
		}
		case 72: {
			--choice;
			if (choice < 0) choice = option - 1;
			break;
		}
		case 80: {
			++choice;
			if (choice > option - 1) choice = 0;
			break;
		}
		}
	}
}
int main() {
	fullscreen();
	//SetColor(4);
	//readfile("graph.txt");
	//system("pause");
// ========================================== ds lop ==================================
	dsLopTc dsLTC;
	dsLop dslop;
	dsMonHoc dsMH;
	int choice = 0;
	int option = 9;
	readfile_dsLop("C:/Users/84773/OneDrive/Máy tính/dsLop.txt", dslop);
	readfile_dsLTC("C:/Users/84773/source/repos/testproject/testproject/dsLTC.txt", dsLTC);
	readfile_dsMH("C:/Users/84773/OneDrive/Máy tính/dsMonHoc.txt", dsMH);
	//khung_nhap_diem(0, 0, 115, 2);
	while (1) {
		clrscr();
		gotoxy(20, 0);
		SetColor(7);
		cout << "MENU" << endl;
		for (int i = 0; i < option; ++i) {
			if (choice == i) {
				highlight(i);
			}
			else {
				normal(i);
			}
			switch (i) {
			case 0: {
				cout << "1. Cap nhat sinh vien cua lop";
				break;
			}
			case 1: {
				cout << "2. Mo lop TC";
				break;
			}
			case 2: {
				cout << "3. Dang ky lop TC";
				break;
			}
			case 3: {
				cout << "4. Cap nhat danh sach mon hoc";
				break;
			}
			case 4: {
				cout << "5. In danh sach mon hoc";
				break;
			}
			case 5: {
				cout << "6. In danh sach sinh vien dang ky";
				break;
			}
			case 6: {
				cout << "7. Nhap diem";
				break;
			}
			case 7: {
				cout << "8. In bang diem";
				break;
			}
			case 8: {
				cout << "9. thoat";
				break;
			}
			}
		}
		char key;
		key = _getch();
		switch (key)
		{
		case 72: {
			--choice;
			if (choice < 0) choice = option - 1;
			break;
		}
		case 80: {
			++choice;
			if (choice > option - 1) choice = 0;
			break;
		}
		case 13: {
			system("cls");
			switch (choice) {
			case 0: {
				kiem_tra_ds_SV(dslop);
				system("cls");
				writefile_dsLop("C:/Users/84773/OneDrive/Máy tính/dsLop.txt", dslop);
				break;
			}
			case 1: {
				system("cls");
				cap_nhat_lop_TC(dsLTC);
				writefile_dsLTC("C:/Users/84773/source/repos/testproject/testproject/dsLTC.txt", dsLTC);
				break;
			}
			case 2: {
				system("cls");
				DK_LOP_TC(dsLTC, dslop, dsMH);
				writefile_dsLTC("C:/Users/84773/source/repos/testproject/testproject/dsLTC.txt", dsLTC);
				break;
			}
			case 3: {
				ds_MH(dsMH);
				writefile_dsMH("C:/Users/84773/OneDrive/Máy tính/dsMonHoc.txt", dsMH);
				break;
			}
			case 4: {
				system("cls");
				in_ds_MH_theo_ten(dsMH);
				break;
			}
			case 5: {
				system("cls");
				DK_LOP_TC(dsLTC, dslop, dsMH);
				writefile_dsLTC("C:/Users/84773/source/repos/testproject/testproject/dsLTC.txt", dsLTC);
				break;
			}
			case 6: {
				system("cls");
				Nhap_diem(dsLTC, dslop);
				system("cls");
				break;
			}
			case 7: {
				in_bang_diem(dsLTC, dsMH, dslop);
				system("cls");
				break;
			}
			case 8: {
				system("cls");
				return 0;
			}
			}
		}
		}
	}
	// ========================================= ds lop TC =======================================
	//khung_dk_LTC(0, 3, 90, 12);
	//khung_dk_LTC(0, 18, 90, 12);
}
