#include "CTDL.h"
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define Backspc 8
#define TAB 9
#define F1 59
#define F2 60
#define F3 61
#define F4 62
void khung_bao_loi(string bao_loi, int x, int y, int w, int h) {
	for (int i = x; i <= x + w; ++i) {
		for (int iy = y; iy <= y + h; ++iy) {
			SetBGColor(8);
			gotoxy(i, iy);
			cout << " ";
			gotoxy(x + w, iy);
			cout << " ";
		}
	}
	for (int ix = x; ix <= x + w; ++ix) {
		SetBGColor(8);
		gotoxy(ix, y);
		cout << " ";
		gotoxy(ix, y);
		cout << " ";
		gotoxy(ix, y + h);
		cout << " ";
	}
	gotoxy(x + 2, y + h / 2); SetColor(10); cout << bao_loi;
	Sleep(1500); 
	for (int i = x; i <= x + w; ++i) {
		for (int iy = y; iy <= y + h; ++iy) {
			SetBGColor(0);
			gotoxy(i, iy);
			cout << " ";
			gotoxy(x + w, iy);
			cout << " ";
		}
	}
	for (int ix = x; ix <= x + w; ++ix) {
		SetBGColor(0);
		gotoxy(ix, y);
		cout << " ";
		gotoxy(ix, y);
		cout << " ";
		gotoxy(ix, y + h);
		cout << " ";
	}
}
void khung_lua_chon(int x, int y, int w, int h) {
	for (int i = x; i <= x + w; ++i) {
		for (int iy = y; iy <= y + h; ++iy) {
			//SetBGColor(8);
			gotoxy(x, iy);
			//cout << " ";
			cout << char(179);
			gotoxy(x+w, iy);
			//cout << " ";
			cout << char(179);
		}
	}
	for (int ix = x; ix <= x + w; ++ix) {
		//SetBGColor(8);
		gotoxy(ix, y);
		//cout << " ";
		cout << char(196);
		gotoxy(ix, y);
		//cout << " ";
		cout << char(196);
		gotoxy(ix, y + h);
		//cout << " ";
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
}
void khung_giao_dien_chinh() {
	int x = 0, y = 0, w = 132, h = 5, col = 1, line = 30;
	for (int i = 0; i <= w;) {
		for (int iy = y; iy <= y + line; ++iy) {
			SetBGColor(3);
			//if (iy >= h) gotoxy(i, iy); cout << " ";
			gotoxy(x, iy);
			//cout << char(179);
			cout << " ";
			if (i == 45) {
				if (iy >= h) gotoxy(i, iy);
				else continue;
			}
			else gotoxy(i, iy);
			///cout << char(179);
			cout << " ";
		}
		if (i == 0) i += 45;
		else i += w - 45;
	}
	for (int ix = x; ix <= x + w; ++ix) {
		gotoxy(ix, y);
		//cout << char(196);
		cout << " ";
		gotoxy(ix, y + h);
		//cout << char(196);
		cout << " ";
		gotoxy(ix, y + line);
		//cout << char(196);
		cout << " ";
	}
}
void nhap_thong_tin_in_diem(int x, int y, int w, int h, int line, int col) {
	SetColor(3);
	for (int i = x; i <= x + w; i += w / col) {
		for (int iy = y; iy < y + line; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
	}
	for (int ix = x + 1; ix < x + w; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + line);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + line); cout << char(192);
	gotoxy(x + w, y + line); cout << char(217);
	gotoxy(x += 5, y += 1); cout << "NIEN KHOA";
	gotoxy(x += 20, y); cout << "HK";
	gotoxy(x += w / col, y); cout << "NHOM";
	gotoxy(x += w / col, y); cout << "MA MON";
}
int khung_xac_nhan(string str1, int x, int y) {
	SetColor(3);
	bool check = 1;
	int choice = 0;
	gotoxy(x, y); cout << str1;
	khung_lua_chon(x + 2, y + 3, 7, 2);
	khung_lua_chon(x + 36, y + 3, 7, 2);
	while (1) {
		for (int i = 0; i < 2; ++i) {
			if (i == choice) SetColor(20);
			else SetColor(7);
			switch (i) {
			case 0: {
				gotoxy(x + 5, y + 4); cout << "co";
				break;
			}
			case 1: {
				gotoxy(x + 37, y + 4); cout << "khong";
				break;
			}
			}
		}
		char key = _getch();
		if (key == 13) return check;
		switch (key) {
		case LEFT: {
			--choice;
			if (choice < 0) choice = 0;
			check = 1;
			break;
		}
		case RIGHT: {
			++choice;
			if (choice > 1) choice = 1;
			check = 0;
			break;
		}
		}
	}
}
void khung_LTC(int x, int y, int w, int h, int col = 8, int line = 25, int check = 0) {
	SetColor(3);
	for (int i = x; i <= x + w - w / col; i += w / col) {
		for (int iy = y; iy < y + line; ++iy) {
			gotoxy(x + w - w / col, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
	}
	for (int ix = x; ix < x + w - w/col; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + line);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w - w / col, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w - w / col, y + h); cout << char(217);
	gotoxy(x + w - w / col, y + line); cout << char(217);
	gotoxy(x, y + line); cout << char(192);
	gotoxy(x += 2, y += 1); cout << "MA LOP TC";
	gotoxy(x += w / col, y); cout << "MA MH";
	gotoxy(x += w / col, y); cout << "NIEN KHOA";
	gotoxy(x += w / col, y); cout << "HOC KI";
	gotoxy(x += w / col, y); cout << "NHOM";
	gotoxy(x += w / col, y); cout << "SO SV MAX";
	gotoxy(x += w / col, y); cout << "SO SV MIN";
	if (check) {
		gotoxy(107, 7); cout << "F1:Them SV";
		gotoxy(120, 7); cout << "F2: Hieu chinh";
		gotoxy(107, 13); cout << "F3: Xoa SV";
		gotoxy(120, 13); cout << "ESC: Thoat";
		gotoxy(114, 10); cout << "F4 : SAVE";
		gotoxy(117, 1); cout << "UP";
		gotoxy(117, 2); cout << char(94);
		gotoxy(116, 5); cout << "DOWN";
		gotoxy(117, 4); cout << "v";
		gotoxy(119, 3); cout << "> RIGHT";
		gotoxy(110, 3); cout << "LEFT <";
	}
}
void khung_dk_LTC(string str, int x, int y, int w, int h) {
	SetColor(3);
	gotoxy(40, y - 1); cout << str;
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
	gotoxy(124, 13); cout << "UP";
	gotoxy(124, 14); cout << char(94);
	gotoxy(123, 17); cout << "DOWN";
	gotoxy(124, 16); cout << "v";
	gotoxy(126, 15); cout << "> RIGHT";
	gotoxy(117, 15); cout << "LEFT <";
}
void khung_bang_diem_tong_ket(int x, int y, int w, int h, int col) {
	SetColor(3);
	for (int i = 0; i <= w;) {
		for (int iy = y; iy < y + 26; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
		if (i == 0) i += 5;
		else if (i == 5) i += 12;
		else if (i == 17) i += 25;
		else if (i > 17) i += (w - 42) / col;
	}
	for (int ix = 1; ix < x + w; ++ix) {
		for (int iy = y; iy <= y + 26; iy += 2) {
			gotoxy(ix, iy);
			cout << char(196);
		}
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + 26); cout << char(217);
	gotoxy(x, y + 26); cout << char(192);
	gotoxy(x += 1, y += 1); cout << "STT";
	gotoxy(x += 8, y); cout << "MSV";
	gotoxy(x += 16, y); cout << "HO TEN";
	gotoxy(124, 13); cout << "UP";
	gotoxy(124, 14); cout << char(94);
	gotoxy(123, 17); cout << "DOWN";
	gotoxy(124, 16); cout << "v";
	gotoxy(126, 15); cout << "> RIGHT";
	gotoxy(117, 15); cout << "LEFT <";
}
void khung_ds_SV(int x, int y, int w, int h, int line = 25, bool check = 1) {
	SetColor(3);
	for (int i = 0; i <= w;) {
		for (int iy = y; iy <= y + line; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
		if (i == 14) i += 20;
		else if (i == 34) i += 8;
		else i += 14;
	}
	for (int ix = x + 1; ix < x + w; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + line);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + line); cout << char(192);
	gotoxy(x + w, y + line); cout << char(217);
	gotoxy(x += 7, y += 1); cout << "MSV";
	gotoxy(x += 14, y); cout << "HO";
	gotoxy(x += 15, y); cout << "TEN";
	gotoxy(x += 10, y); cout << "GIOI TINH";
	gotoxy(x += 14, y); cout << "SDT";
	gotoxy(124, 1); cout << "UP";
	gotoxy(124, 2); cout << char(94);
	gotoxy(123, 5); cout << "DOWN";
	gotoxy(124, 4); cout << "v";
	gotoxy(126, 3); cout << "> RIGHT";
	gotoxy(117, 3); cout << "LEFT <";
	gotoxy(90, 5); cout << "ESC: Thoat";
	if (check) {
		gotoxy(80, 1); cout << "F1:Them SV";
		gotoxy(95, 1); cout << "F2: Hieu chinh";
		gotoxy(75, 5); cout << "F3: Xoa SV";
		gotoxy(105, 5); cout << "F4 : SAVE";
		x = 72;
		y = 8;
		for (int iy = y; iy < y + 17; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(x + 50, iy);
			cout << char(179);
		}
		for (int ix = x; ix < x + 50; ++ix) {
			gotoxy(ix, y);
			cout << char(196);
			gotoxy(ix, y);
			cout << char(196);
			gotoxy(ix, y + 17);
			cout << char(196);
		}
		gotoxy(x, y); cout << char(218);
		gotoxy(x + 50, y); cout << char(191);
		gotoxy(x, y + 17); cout << char(192);
		gotoxy(x + 50, y + 17); cout << char(217);
	}
}
void khung_ds_MH(int x, int y, int w, int h, int col = 4, int line = 25, bool check = 1) {
	SetColor(3);
	for (int i = x; i <= x + w;) {
		for (int iy = y; iy < y + line; ++iy) {
			gotoxy(x + w, iy);
			cout << char(179);
			gotoxy(i, iy);
			cout << char(179);
		}
		if (i == 0) i += w / col;
		else if (i == 18) i += 36;
		else i += 9;
	}
	for (int ix = x; ix < x + w; ++ix) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
		gotoxy(ix, y + line);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + line); cout << char(217);
	gotoxy(x, y + line); cout << char(192);
	gotoxy(x += 5, y += 1); cout << "MA MH";
	gotoxy(x += 23, y); cout << "TEN MH";
	gotoxy(x += 27, y); cout << "STCLT";
	gotoxy(x += 9, y); cout << "STCTH";
	if (check) {
		gotoxy(80, 1); cout << "F1:Them MH";
		gotoxy(95, 1); cout << "F2: Hieu chinh";
		gotoxy(75, 5); cout << "F3: Xoa MH";
		gotoxy(90, 5); cout << "ESC: Thoat";
		gotoxy(105, 5); cout << "F4: SAVE";
		gotoxy(124, 1); cout << "UP";
		gotoxy(124, 2); cout << char(94);
		gotoxy(123, 5); cout << "DOWN";
		gotoxy(124, 4); cout << "v";
		gotoxy(126, 3); cout << "> RIGHT";
		gotoxy(117, 3); cout << "LEFT <";
		x = 74;
		y = 10;
		for (int iy = y; iy < y + 15; ++iy) {
			gotoxy(x, iy);
			cout << char(179);
			gotoxy(x + 50, iy);
			cout << char(179);
		}
		for (int ix = x; ix < x + 50; ++ix) {
			gotoxy(ix, y);
			cout << char(196);
			gotoxy(ix, y);
			cout << char(196);
			gotoxy(ix, y + 15);
			cout << char(196);
		}
		gotoxy(x, y); cout << char(218);
		gotoxy(x + 50, y); cout << char(191);
		gotoxy(x, y + 15); cout << char(192);
		gotoxy(x + 50, y + 15); cout << char(217);
	}
}
void khung_ds_lop(int x, int y, int w, int h, int col = 8, int line = 25) {
	SetColor(3);
	for (int i = x; i <= x + w; i += w / col) {
		for (int iy = y; iy < y + line; ++iy) {
			gotoxy(x + w, iy);
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
		gotoxy(ix, y + line);
		cout << char(196);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	gotoxy(x + w, y + line); cout << char(217);
	gotoxy(x, y + line); cout << char(192);
	gotoxy(x += 15, y += 1); cout << "MA LOP";
}


// ====================================================================== NHAP VA BAT LOI ======================================================
int nhap_ma_SV(string& maSV, dsLop& dslop, bool key = 0) {
	char c;
	string tmp;
	bool check = 0;
	int count = 1;
	cout << maSV;
	while (1) {
		c = _getch();
		if (c == 0 || c == -32) {
			c = _getch();
			continue;
		}
		if (c == ESC) return 1;
		if (c == Enter) {
			if (key) {
				for (int i = 0; i < dslop.soluong; ++i) {
					Sinhvien* sv = dslop.ds_lop[i].pdsSV.phead;
					while (sv != NULL) {
						if (sv->MaSV == tmp) {
							khung_bao_loi("MA SINH VIEN DA TON TAI", 80, 12, 30, 4);
							check = 1;
							break;
						}
						sv = sv->pnext;
					}
					if (check == 1) break;
				}
				if (check) return 0;
				else {
					maSV = tmp;
					return 1;
				}
			}
			maSV = tmp;
			return 1;
		}
		if (c == Backspc) {
			if (tmp.empty()) continue;
			else {
				--count;
				tmp.pop_back();
				cout << "\b \b";
				continue;
			}
		}


		if (tmp.length() > 9 && c != Backspc && c != Enter) continue;
		if (!isalpha(c) && c != 8 && !isalnum(c)) continue;

		if (count == 1 || count == 4 || count == 5 || count == 6 || count == 7) {
			if (isalpha(c)) {
				c = toupper(c);
				++count;
			}
			else continue;
		}
		else {
			if (c < '0' || c > '9') continue;
			else ++count;
		}
		cout << c;
		tmp += c;
	}
}
int nhap_ho_SV(string& hoSV) {
	char c;
	cout << hoSV;

	while (true) {
		c = _getch();

		if (c == 0 || c == -32) {
			c = _getch();
			continue;
		}

		if (c == ESC) return 0;

		if (c == '\r') {
			if (hoSV.empty()) continue;
			break;
		}
		if (hoSV.length() > 21 && c != Backspc) continue;
		if (!isalpha(c) && c != ' ' && c != 8) continue;
		if (c == ' ' || isalpha(c)) {
			if ((hoSV.empty() && c == ' ') || (!hoSV.empty() && hoSV[hoSV.length() - 1] == ' ' && c == ' ')) {
				continue;
			}
			if ('a' <= c && c <= 'z') {
				c = toupper(c);
			}
		}
		if (c == Backspc) {
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
	if (hoSV[hoSV.length() - 1] != ' ') hoSV += ' ';
	return 1;
}
int nhap_ten_SV(string& tenSV) {
	char c;
	cout << tenSV;
	while (1) {
		c = _getch();
		if (c == 0 || c == -32) {
			c = _getch();
			continue;
		}
		if (c == ESC) return 0;
		if (c == '\r') {
			if (tenSV.empty()) continue;
			break;
		}
		if (c == Backspc) {
			if (!tenSV.empty()) {
				tenSV.pop_back();
				cout << "\b \b";
			}
		}
		if (tenSV.length() >10) continue;
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
string nhap_nien_khoa(string& nien_khoa) {
	char c;
	cout << nien_khoa;
	while (true) {
		c = _getch();
		if (c == 0 || c == -32) {
			c = _getch();
			continue;
		}
		if (c == Enter) {
			if (nien_khoa.empty()) continue;
			return nien_khoa;
		}
		if (c == ESC) {
			nien_khoa = "";
			return nien_khoa;
		}
		if ((c != '-' && c != 8 && !isalnum(c)) || isalpha(c)) continue;
		if (c == Backspc) {
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
		if (key == 0 || key == -32) {
			key = _getch();
			continue;
		}
		if (key == ESC) return 0;
		if (key == Enter) {
			if (phai.empty()) continue;
			return 1;
		}
		if (key == Backspc) {
			if (!phai.empty()) {
				phai.pop_back();
				cout << "\b \b";
			}
		}
		if (key == '0') {
			phai = "NU ";
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
	cout << sdt;
	while (1) {
		char c;
		c = _getch();
		if (c == 0 || c == -32) {
			c = _getch();
			continue;
		}
		if (c == ESC) return 0;
		if (c == Enter) {
			if (sdt.empty() || sdt.length() < 10) continue;
			return 1;
		}
		if (c == Backspc) {
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
double nhap_diem(double diem) {
	string tmp;
	cout << diem;
	tmp = to_string(diem);
	while (1) {
		char c;
		c = _getch();
		if (c == 0 || c == -32) {
			c = _getch();
			continue;
		}
		if (c == ESC) return -1;
		if (c == Enter) {
			if (tmp.empty()) continue;
			if (tmp == to_string(diem))
				return -2;
			else return stod(tmp);
		}
		if (c == Backspc) {
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
int nhap_diem(int diem) {
	string tmp;
	cout << diem;
	tmp = to_string(diem);
	while (1) {
		char c;
		c = _getch();
		if (c == 0 || c == -32) {
			c = _getch();
			continue;
		}
		if (c == ESC) return -1;
		if (c == Enter) {
			if (tmp.empty()) continue;
			if (tmp == to_string(diem))
				return -2;
			else return stoi(tmp);
		}
		if (c == Backspc) {
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
int nhap_ma_lop(string& malop) {
	SetColor(7);
	char c;
	int count = 1;
	cout << malop;
	while (1) {
		c = _getch();
		if (c == 0 || c == -32) {
			c = _getch();
			continue;
		}
		if (c == ESC) {
			return 0;
		}
		if (c == TAB) return -1;
		if (c == '\r') {
			if (malop.empty()) continue;
			return 1;
		}
		if (c == Backspc) {
			if (malop.empty()) continue;
			else {
				malop.pop_back();
				cout << "\b \b";
				--count;
				continue;
			}
		}


		if (malop.length() > 8 && c != Backspc && c != TAB) continue;
		if (!isalpha(c) && c != Backspc && c != TAB && !isalnum(c)) continue;
		if (count == 1 || count == 4 || count == 5 || count == 6 || count == 7) {
			if (isalpha(c)) {
				c = toupper(c);
				++count;
			}
			else continue;
		}
		else if (count == 2 || count == 3 || count == 8 || count == 9) {
			if (c < '0' || c >'9') continue;
			else ++count;
		}

		cout << c;
		malop += c;
	}
}
string nhap_ten_MH(string& tenMH) {
	char c;
	cout << tenMH;
	while (true) {
		c = _getch();
		if (c == 0 || c == -32) {
			c = _getch();
			continue;
		}
		if (c == ESC) return "";
		if (c == Enter) {
			if (tenMH.empty()) continue;
			return tenMH;
		}
		if (tenMH.length() > 15 && c != Backspc && c != Enter) continue;
		if (!isalpha(c) && c != ' ' && c != Backspc && !isalnum(c)) continue;
		if (c == ' ' || isalpha(c) || isalnum(c) || c == 17) {
			if ((tenMH.empty() && c == ' ') || (!tenMH.empty() && tenMH[tenMH.length() - 1] == ' ' && c == ' ')) {
				continue;
			}
			if ('a' <= c && c <= 'z') {
				c = toupper(c);
			}
		}
		if (c == Backspc) {
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


// ====================================================================== DANH SACH SINH VIEN ======================================================
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
		if (SV.phead->highlight == 1) {
			SetColor(20);
			SV.phead->highlight = 0;
		}
		else SetColor(3);
		int i = 1;
		gotoxy(i, j);
		cout << SV.phead->MaSV << endl;
		gotoxy(i += 14, j);
		cout << SV.phead->ho << endl;
		gotoxy(i += 21, j);
		cout << SV.phead->ten << endl;
		gotoxy(i += 9, j);
		cout << SV.phead->phai << endl;
		gotoxy(i += 14, j);
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
	gotoxy(i += 14, j);
	cout << sv->ho << ' ';
	gotoxy(i += 21, j);
	cout << sv->ten << ' ';
	gotoxy(i += 8, j);
	cout << sv->phai << ' ';
	gotoxy(i += 14, j);
	cout << sv->SDT << ' ';
}
void in_thong_tin_lop(Lop lop, int j) {
	int i = 31;
	gotoxy(i, j);
	cout << lop.MALOP;
	gotoxy(i += 35, j);
	cout << lop.TENLOP;
}
/*Sinhvien* tim_sinh_vien(dsLop& dsl, string maSV) {
	for (int i = 0; i < dsl.soluong; ++i) {
		Sinhvien* SV = dsl.ds_lop[i].pdsSV.phead;
		while (SV != NULL) {
			if (SV->MaSV == maSV) {
				return SV;
			}
			SV = SV->pnext;
		}
	}
}*/
void nhap_SV(dsSV& dssv, dsLop& dslop) {
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
			khung_ds_SV(0, 0, 70, 2);
			j = 3;
			SetColor(7);
		}
		string maSV;
		SV = new Sinhvien();
		while (1) {
			gotoxy(i, j);
			cout << "           "; 
			gotoxy(i, j);
			if (nhap_ma_SV(maSV, dslop, 1)) break;
		}
		if (maSV.empty()) {
			break;
		}
		SV->MaSV = maSV;
		SV->pnext = NULL;
		gotoxy(i += 14, j);
		if (nhap_ho_SV(SV->ho) == 0) break;
		gotoxy(i += 20, j);
		if (nhap_ten_SV(SV->ten) == 0) break;
		gotoxy(i += 8, j);
		if (nhap_gioi_tinh(SV->phai) == 0) break;
		gotoxy(i += 14, j);
		if (nhap_SDT(SV->SDT) == 0) break;
		SV->highlight = 1;
		j += 2;
		++count;
		if (current == NULL || (SV->ten + SV->ho < current->ten + current->ho)) {
			SV->pnext = current;
			if (prevSV != NULL) {
				prevSV->pnext = SV;
			}
			else {
				dssv.phead = SV;
			}
		}
		else {
			while (current != NULL && (current->ten + current->ho < SV->ten + SV->ho)) {
				prevSV = current;
				current = current->pnext;
			}
			SV->pnext = current;
			prevSV->pnext = SV;
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
	khung_ds_SV(0, 0, 70, 2);
	do {
		int count = 0;
		int jy = 3;
		Sinhvien* SV = dssv.phead;
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
		if (key == ESC) return NULL;
		switch (key) {
		case UP: {
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
		case DOWN: {
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
		case Enter: {
			SV = dssv.phead;
			for (int i = 0; i < choice && SV != NULL; ++i) {
				SV = SV->pnext;
			}
			return SV;
		}
		case LEFT: {
			if (page > 1) {
				page--;
				choice = page * 11 - 11;
				system("cls");
				khung_ds_SV(0, 0, 70, 2);
			}
			break;
		}
		case RIGHT: {
			if (page * 11 < option) {
				page++;
				choice = page * 11 - 11;
				system("cls");
				khung_ds_SV(0, 0, 70, 2);
			}
			break;
		}
		}
	} while (1);
}
int menu_ds_Lop(dsLop& dslop, int page) {
	int choice = page * 11 - 11;
	int maxpage;
	int option = dslop.soluong;
	if (dslop.soluong % 11 != 0) maxpage = dslop.soluong / 11 + 1;
	else maxpage = dslop.soluong / 11;
	khung_ds_lop(30, 0, 40, 2, 1, 25);
	do {
		int count = 0;
		int jy = 3;
		for (int i = page * 11 - 11; i < 11 * page && (page - 1) <= i; ++i) {
			if (choice == i) {
				highlight(i);
			}
			else {
				normal(i);
			}
			in_thong_tin_lop(dslop.ds_lop[i], jy);
			jy += 2;
		}
		char key;
		key = _getch();
		if (key == ESC) return -1;
		switch (key) {
		case UP: {
			--choice;
			if (choice < page * 11 - 11) {
				if (page < maxpage) {
					choice = page * 11 - 1;
				}
				else {
					choice = dslop.soluong - 1;
				}
				highlight(choice);
			}
			else {
				normal(choice);
			}
			break;
		}
		case DOWN: {
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
		case Enter: {
			return choice;
		}
		case LEFT: {
			if (page > 1) {
				page--;
				choice = page * 11 - 11;
				system("cls");
				khung_ds_lop(0, 0, 70, 2, 2, 25);
			}
			break;
		}
		case RIGHT: {
			if (page * 11 < option) {
				page++;
				choice = page * 11 - 11;
				system("cls");
				khung_ds_lop(0, 0, 70, 2, 2, 25);
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
	SetColor(15);
	Sinhvien* tmp = dssv.phead;
	Sinhvien* prevtmp = NULL;
	if (sv == NULL) return;
	while (tmp != NULL) {
		if (tmp->MaSV == sv->MaSV) {
			string ho, ten, phai, SDT;
			ho = tmp->ho;
			ten = tmp->ten;
			phai = tmp->phai;
			SDT = tmp->SDT;

			//in lai thong tin
			gotoxy(73, 10); cout << "Nhap ho sinh vien: " << tmp->ho << endl;
			gotoxy(73, 12); cout << "Nhap ten sinh vien: " << tmp->ten << endl;
			gotoxy(73, 14); cout << "Nhap gioi tinh: " << tmp->phai << endl;
			gotoxy(73, 16); cout << "Nhap so dien thoai: " << tmp->SDT << endl;

			//chinh sua thong tin
			gotoxy(73, 10);
			cout << "Nhap ho sinh vien: ";
			if (nhap_ho_SV(ho) == 0) return;
			else tmp->ho = ho;
			gotoxy(73, 12);
			cout << "nhap ten sinh vien: ";
			if (nhap_ten_SV(ten) == 0) return;
			else tmp->ten = ten;
			gotoxy(87, 21);
			cout << "NU : 0                    NAM : 1";
			gotoxy(73, 14);
			cout << "nhap gioi tinh: ";
			if (nhap_gioi_tinh(phai) == 0) return;
			else tmp->phai = phai;
			gotoxy(87, 21);
			cout << "                                 ";
			gotoxy(73, 16);
			cout << "nhap so dien thoai: ";
			if (nhap_SDT(SDT) == 0) return;
			else tmp->SDT = SDT;
			tmp->highlight = 1;
			break;
		}
		prevtmp = tmp;
		tmp = tmp->pnext;
	}
	if (tmp == NULL) {
		cout << "Khong tim thay sinh vien co MaSV = " << sv->MaSV << endl;
		return;
	}
	// tim vi tri thich hop de chen sau khi sua thong tin
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
	int check;
	int checkSave = 1;
	while (1) {
		for (int iy = 10; iy < 15; ++iy) {
			gotoxy(40, iy);
			cout << char(179);
			gotoxy(70, iy);
			cout << char(179);
		}
		for (int ix = 40; ix < 70; ++ix) {
			gotoxy(ix, 10);
			cout << char(196);
			gotoxy(ix, 0 + 14);
			cout << char(196);
			gotoxy(ix, 0 + 14);
			cout << char(196);
		}
		gotoxy(40, 10); cout << char(218);
		gotoxy(70, 10); cout << char(191);
		gotoxy(70, 14); cout << char(217);
		gotoxy(40, 14); cout << char(192);
		gotoxy(49, 11); cout << "Nhap ma lop: ";
		gotoxy(41, 15); cout << "ESC : THOAT";
		gotoxy(58, 15); cout << "ENTER : CHON";
		gotoxy(47, 17); cout << "TAB : XEM DS LOP";
		gotoxy(30, 19); cout << "MA LOP CHUAN : (KY TU + 2 SO + 3 KY TU + N + 2 SO) E22CQCN01";
		gotoxy(49, 12); check = nhap_ma_lop(malop);
		if (check == 1) break;
		if (check == -1) {
			system("cls");
			int i = menu_ds_Lop(dslop, 1);
			if (i == -1) return;
			malop = dslop.ds_lop[i].MALOP;
			system("cls");
		}
		else if (check == 0) return;
	}
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
				khung_ds_SV(0, 0, 70, 2);
				in_ds_SV(dslop.ds_lop[i].pdsSV, curpage);
				gotoxy(74, 1); cout << curpage << "/" << page;
				c = _getch();
				if (c == ESC) {
					if (!checkSave) {
						if (khung_xac_nhan("Danh sach chua duoc luu ban co muon luu khong!", 74, 12) == 1) {
							writefile_dsLop("C:/Users/84773/OneDrive/Máy tính/dsLop.txt", dslop);
							khung_bao_loi("Da luu thanh cong", 82, 20, 20, 3);
						}
						else khung_bao_loi("khong luu thanh cong", 90, 20, 20, 4);
						return;
					}
					return;
				}
				switch (c) {
				case F1: {
					system("cls");
					khung_ds_SV(0, 0, 70, 2);
					SetColor(15);
					nhap_SV(dslop.ds_lop[i].pdsSV, dslop);
					checkSave = 0;
					break;
				}
				case F2: {
					system("cls");
					khung_ds_SV(0, 0, 70, 2);
					hieu_chinh_SV(dslop.ds_lop[i].pdsSV, menu_ds_SV(dslop.ds_lop[i].pdsSV, curpage, page));
					checkSave = 0;
					break;
				}
				case F3: {
					system("cls");
					khung_ds_SV(0, 0, 70, 2);
					Sinhvien* tmp = menu_ds_SV(dslop.ds_lop[i].pdsSV, curpage, page);
					if (tmp == NULL) break;
					if (khung_xac_nhan("Ban co chac chan muon xoa sinh vien nay khong!", 74, 12)  == 1) {
						checkSave = 0;
						xoa_SV(dslop.ds_lop[i].pdsSV, tmp);
						khung_bao_loi("Da xoa thanh cong 1 sinh vien", 82, 20, 30, 4);
					}
					break;
				}
				case F4: {
					checkSave = 1;
					writefile_dsLop("C:/Users/84773/OneDrive/Máy tính/dsLop.txt", dslop);
					khung_bao_loi("Da luu thanh cong", 87, 15, 30, 4);
					break;
				}
				case LEFT: {
					if (curpage > 1)
						--curpage;
					break;
				}
				case RIGHT: {
					if (curpage < page)
						++curpage;
					break;
				}
				}
			}
		}
	}
	if (dslop.soluong < 2000) {
		dslop.ds_lop[dslop.soluong].MALOP = malop;
		++dslop.soluong;
		while (1) {
			int page = 1;
			if (dslop.ds_lop[dslop.soluong].pdsSV.sl == 0) page = 1;
			else if (dslop.ds_lop[dslop.soluong].pdsSV.sl % 11 != 0) {
				page = dslop.ds_lop[dslop.soluong].pdsSV.sl / 11 + 1;
			}
			else page = dslop.ds_lop[dslop.soluong].pdsSV.sl / 11;
			system("cls");
			khung_ds_SV(0, 0, 70, 2);
			gotoxy(120, 0); cout << curpage << "/" << page;
			in_ds_SV(dslop.ds_lop[dslop.soluong].pdsSV, curpage);
			c = _getch();
			if (c == ESC) {
				if (!checkSave) {
					if (khung_xac_nhan("Danh sach chua duoc luu ban co muon luu khong!", 74, 12) == 1) {
						writefile_dsLop("C:/Users/84773/OneDrive/Máy tính/dsLop.txt", dslop);
						khung_bao_loi("Da luu thanh cong", 82, 20, 20, 3);
						Sleep(1500);
					}
					return;
				}
				return;
			}
			switch (c) {
			case F1: {
				system("cls");
				checkSave = 0;
				khung_ds_SV(0, 0, 70, 2);
				nhap_SV(dslop.ds_lop[dslop.soluong].pdsSV, dslop);
				break;
			}
			case F2: {
				system("cls");
				checkSave = 0;
				khung_ds_SV(0, 0, 70, 2);
				hieu_chinh_SV(dslop.ds_lop[dslop.soluong].pdsSV, menu_ds_SV(dslop.ds_lop[dslop.soluong].pdsSV, curpage, page));
				break;
			}
			case F3: {
				system("cls");
				khung_ds_SV(0, 0, 70, 2);
				Sinhvien* tmp = menu_ds_SV(dslop.ds_lop[dslop.soluong].pdsSV, curpage, page);
				if (tmp == NULL) break;
				if (khung_xac_nhan("Ban co chac chan muon xoa sinh vien nay khong!", 74, 12) == 1) {
					checkSave = 0;
					xoa_SV(dslop.ds_lop[dslop.soluong].pdsSV, tmp);
					khung_bao_loi("Da xoa thanh cong 1 sinh vien", 82, 20, 30, 4);
					Sleep(1500);
				}
				break;
			}
			case F4: {
				writefile_dsLop("C:/Users/84773/OneDrive/Máy tính/dsLop.txt", dslop);
				gotoxy(87, 15); cout << "Da luu thanh cong";
				Sleep(1500);
				break;
			}
			case LEFT: {
				if (curpage > 1)
					--curpage;
				break;
			}
			case RIGHT: {
				if (curpage < page)
					++curpage;
				break;
			}
			}
		}
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
	khung_ds_SV(0, 0, 70, 2);
	for (int i = 0; i < dsLop.soluong; ++i) {
		if (dsLop.ds_lop[i].MALOP == lop.MALOP) {
			in_ds_SV(dsLop.ds_lop[i].pdsSV, 1);
			break;
		}
	}
}


// ====================================================== DANH SACH MON HOC ======================================================================
int MA_MON = 0; 
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
int nhap_ma_mon(string& maMH, MonHoc*& dsMH, int check = 1) {
	SetColor(15);
	char c;
	int count = 1;
	cout << maMH;
	if (!maMH.empty()) count = 8;
	while (1) {
		c = _getch();
		if (c == 0 || c == -32) {
			c = _getch();
			continue;
		}
		if (c == ESC) {
			maMH = "";
			return 1;
		}
		if (c == '\r') {
			if (maMH.empty()) continue;
			if (maMH.length() < 7) continue;
			if (check) {
				if (tim_MH(dsMH, maMH) && check == 1) {
					khung_bao_loi("MA MON HOC DA TON TAI", 84, 14, 30, 4);
					return 0;
				}
				else return 1;
			}
			return 1;
		}

		if (c == Backspc) {
			if (maMH.empty()) continue;
			else {
				--count;
				maMH.pop_back();
				cout << "\b \b";
				continue;
			}
		}

		if (maMH.length() > 6 && c != Backspc && c != TAB) continue;
		if (c == TAB) return -1;
		if (!isalpha(c) && c != Backspc && c != TAB && !isalnum(c)) continue;
		if (count <= 3) {
			if (isalpha(c)) c = toupper(c);
			else continue;
		}
		else if (count > 3) {
			if ('0' > c || c > '9') continue;
		}
		cout << c;
		maMH += c;
		if(count <= 7) ++count;
	}
}
void xoay_trai(MonHoc*& MH) {
	MonHoc* tmp;
	if (MH == NULL) return;
	if (MH->pright == NULL) return;
	else {
		tmp = MH->pright;
		MH->pright = tmp->pleft;
		tmp->pleft = MH;
		MH = tmp;
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
		MH = tmp;
	}
}
int chieu_cao(MonHoc* MH) {
	if (MH == NULL) return 0;
	int left = chieu_cao(MH->pleft);
	int right = chieu_cao(MH->pright);
	return max(left, right) + 1;
}
int check_can_bang(MonHoc*& MH) {
	if (MH == NULL) return 1;
	int lh = chieu_cao(MH->pleft);
	int rh = chieu_cao(MH->pright);
	if (abs(lh - rh) > 1) return 0;
	return check_can_bang(MH->pleft) && check_can_bang(MH->pright);
}
int bf(MonHoc* MH) {
	if (MH == NULL) return 0;
	return chieu_cao(MH->pleft) - chieu_cao(MH->pright) + 1;
}
void can_bang(MonHoc*& MH) {
	if (MH == NULL) return;
	int balance = chieu_cao(MH->pleft) - chieu_cao(MH->pright);
	if (!check_can_bang(MH)) {
		if (balance > 1) {
			if (chieu_cao(MH->pleft->pleft) >= chieu_cao(MH->pleft->pright)) {
				xoay_phai(MH);
			}
			else {
				xoay_trai(MH->pleft);
				xoay_phai(MH);
			}
		}
		else if(balance < -1) {
			if (chieu_cao(MH->pright->pright) >= chieu_cao(MH->pright->pleft)) {
				xoay_trai(MH);
			}
			else {
				xoay_phai(MH->pright);
				xoay_trai(MH);
			}
		}
	}
	if (MH->pleft != NULL) can_bang(MH->pleft);
	if (MH->pright != NULL) can_bang(MH->pright);
}
// =================================================== DOC VA GHI FILE DANH SACH MH =====================================
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
		MH->dadk = 0;
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
		if (read_data(dsMH.ds, fileinput, maMon)) {
			dsMH.sl++;
			can_bang(dsMH.ds);
		}
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
// ================================================ THEM MH ==============================================================
int them_MH(MonHoc*& dsMH, string maMH, int y, bool check = 0, string tenMH = "", int STCLT = 0, int STCTH = 0) {
	SetColor(15);
	int x = 76;
	if (!check) {
		int tmp1, tmp2;
		gotoxy(x, y += 2);
		cout << "Nhap ten mon hoc: ";
		if (nhap_ten_MH(tenMH) == "") return 0;
		gotoxy(x, y += 2);
		cout << "Nhap so tin chi ly thuyet: ";
		tmp1 = nhap_diem(STCLT);
		if (tmp1 == -1) return 0;
		else if (tmp1 != -2) STCLT = tmp1;
		gotoxy(x, y += 2);
		cout << "Nhap so tin chi thuc hanh: ";
		tmp2 = nhap_diem(STCTH);
		if (tmp2 == -1) return 0;
		else if (tmp2 != -2) STCTH = tmp2;
		check = 1;
	}
	if (dsMH == NULL) {
		dsMH = new MonHoc();
		dsMH->MaMon = maMH;
		dsMH->TenMH = tenMH;
		dsMH->STCLT = STCLT;
		dsMH->STCTH = STCTH;
		dsMH->hightlight = 1;
		dsMH->pleft = NULL;
		dsMH->pright = NULL;
		return 1;
	}
	else if (maMH > dsMH->MaMon) {
		int result = them_MH(dsMH->pright, maMH, y, check, tenMH, STCLT, STCTH);
		return result;
	}
	else if (maMH < dsMH->MaMon) {
		int result = them_MH(dsMH->pleft, maMH, y, check, tenMH, STCLT, STCTH);
		return result;
	}
	return 0;
}
// ================================================= XOA VA HIEU CHINH MH ================================================
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
int xoa_MH(MonHoc*& dsMH, string maMH) {
	if (dsMH == NULL) return 0;
	if (dsMH->MaMon < maMH) xoa_MH(dsMH->pright, maMH);
	else if (dsMH->MaMon > maMH) xoa_MH(dsMH->pleft, maMH);
	else {
		MonHoc* tmp = dsMH;
		if (tmp->pleft == NULL) dsMH = tmp->pright;
		else if (tmp->pright == NULL) dsMH = tmp->pleft;
		else {
			thay_the(tmp, tmp->pright);
		}
		//delete tmp;
		return 1;
		//[tenMH.length() - 1] = "";
	}
}
void hieu_chinh_MH(MonHoc*& dsMH, string maMH) {
	SetColor(15);
	int x = 76;
	int y = 12;
	if (dsMH == NULL) return;
	MonHoc* tmp = dsMH;
	MonHoc* MH = tim_MH(dsMH, maMH);
	while (tmp != NULL && tmp->MaMon != maMH) {
		if (tmp->MaMon > maMH) tmp = tmp->pleft;
		else if (tmp->MaMon < maMH) tmp = tmp->pright;
	}
	string newMaMH = MH->MaMon;
	gotoxy(x, y);
	cout << "Nhap ma mon hoc: " << MH->MaMon;
	gotoxy(x, y + 2);
	cout << "Nhap ten mon hoc: " << MH->TenMH;
	gotoxy(x, y + 4);
	cout << "Nhap so tin chi ly thuyet: " << MH->STCLT;
	gotoxy(x, y + 6);
	cout << "Nhap so tin chi thuc hanh: " << MH->STCTH;
	gotoxy(x, y);
	cout << "Nhap ma mon hoc: "; nhap_ma_mon(newMaMH, dsMH, 0);
	if (newMaMH == "") return;
	string tenMH = MH->TenMH;
	int STCLT = MH->STCLT, STCTH = MH->STCTH;
	if (newMaMH == maMH) {
		gotoxy(x, y += 2);
		cout << "Nhap ten mon hoc: ";
		string str = nhap_ten_MH(tenMH);
		if (str == "" || (str == "" && tenMH == MH->TenMH)) return;
		gotoxy(x, y += 2);
		cout << "Nhap so tin chi ly thuyet: ";
		STCLT = nhap_diem(STCLT);
		if (STCLT == -1) return;
		else if (STCLT == -2) STCLT = MH->STCLT;
		gotoxy(x, y += 2);
		cout << "Nhap so tin chi thuc hanh: ";
		STCTH = nhap_diem(STCTH);
		if (STCTH == -1) return;
		else if (STCTH == -2) STCTH = MH->STCTH;
		MH->TenMH = tenMH;
		MH->STCLT = STCLT;
		MH->STCTH = STCTH;
		MH->hightlight = 1;
		return;
	}
	int check = them_MH(dsMH, newMaMH, y, 0, tenMH, STCLT, STCTH);
	if (check) xoa_MH(dsMH, maMH);
}
// ================================================ IN THONG TIN MH KEM DO HOA =========================================
void in_ds_MH_1(MonHoc*& MH, int& y, int& count, int page) {
	int x = 1;
	if (MH != NULL) {
		in_ds_MH_1(MH->pleft, y, count, page);
		++count;
		if (page > 1) {
			if ((page - 1) * 22 < count && count < page * 22) {
				if (MH->hightlight == 1) {
					SetColor(20);
					MH->hightlight = 0;
				}
				else SetColor(3);
				gotoxy(x, y);
				cout << MH->MaMon;
				gotoxy(x += 18, y);
				cout << MH->TenMH;
				gotoxy(x += 36, y);
				cout << MH->STCLT;
				gotoxy(x += 9, y);
				cout << MH->STCTH;
				y += 1;
			}
		}
		else if (count <= 22) {
			if (MH->hightlight == 1) {
				SetColor(20);
				MH->hightlight = 0;
			}
			else SetColor(3);
			gotoxy(x, y);
			cout << MH->MaMon;
			gotoxy(x += 18, y);
			cout << MH->TenMH;
			gotoxy(x += 36, y);
			cout << MH->STCLT;
			gotoxy(x += 9, y);
			cout << MH->STCTH;
			y += 1;
		}
		in_ds_MH_1(MH->pright, y, count, page);
	}
}
void in_ds_MH(MonHoc*& MH, int choice, int& count, int& y, int page) {
	int x = 1;
	if (MH != NULL) {
		in_ds_MH(MH->pleft, choice, count, y, page);
		count++;
		if ((page - 1) * 22 < count && count <= page * 22) {
			if (choice == count - 1) SetColor(9);
			else SetColor(7);
			gotoxy(x, y);
			cout << MH->MaMon;
			gotoxy(x += 18, y);
			cout << MH->TenMH;
			gotoxy(x += 36, y);
			cout << MH->STCLT;
			gotoxy(x += 9, y);
			cout << MH->STCTH;
			y += 1;
		}
		in_ds_MH(MH->pright, choice, count, y, page);
	}
}
// =============================================== CHEN VA IN MH THEO TEN ===============================================
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
	khung_ds_MH(0, 0, 72, 2, 4, 25, 0);
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
			gotoxy(x += 18, y);
			cout << mang_MH[j]->TenMH;
			gotoxy(x += 36, y);
			cout << mang_MH[j]->STCLT;
			gotoxy(x += 9, y);
			cout << mang_MH[j]->STCTH;
			y += 1;
		}
		char key = _getch();
		if (key == ESC) break;
		switch (key) {
		case LEFT: {
			if (page > 1) 
				--page;
			system("cls");
			khung_ds_MH(0, 0, 72, 2, 4, 25, 0);
			break;
		}
		case RIGHT: {
			if (page < maxpage)
				++page;
			system("cls");
			khung_ds_MH(0, 0, 72, 2, 4, 25, 0);
			break; 
		}
		}
	}
}
//================================================ MENU VA CAP NHAT MH ====================================================
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
string menu_ds_MH(dsMonHoc& dsMH, int page, int maxpage, string& selected) {
	int choice = page * 22 - 22;
	int option = dsMH.sl;
	khung_ds_MH(0, 0, 72, 2);
	while (1) {
		int count = 0;
		int y = 3;
		in_ds_MH(dsMH.ds, choice, count, y, page);
		char key;
		key = _getch();
		if (key == ESC) return "";
		if (key == Enter) {
			count = 0;
			selected = tim_ma_MH(dsMH.ds, choice, count);
			return selected;
		}
		switch (key) {
		case UP: {
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
		case DOWN: {
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
		case LEFT: {
			if (page > 1) {
				page--;
				choice = page * 22 - 22;
				system("cls");
				khung_ds_MH(0, 0, 72, 2);
			}
			break;
		}
		case RIGHT: {
			if (page * 22 < option) {
				page++;
				choice = page * 22 - 22;
				system("cls");
				khung_ds_MH(0, 0, 72, 2);
			}
			break;
		}
		}
	}
}
void ds_MH(dsMonHoc& dsMH, dsLopTc& dsltc) {
	int maxpage;
	int page = 1;
	int checkSave = 1;
	char c;
	while (1) {
		int count = 0;
		int y = 3;
		if (dsMH.sl == 0) maxpage = 1;
		else if (dsMH.sl % 22 != 0)
			maxpage = dsMH.sl / 22 + 1;
		else maxpage = 1;
		system("cls");
		khung_ds_MH(0, 0, 72, 2);
		gotoxy(74, 1);
		cout << page << '/' << maxpage;
		in_ds_MH_1(dsMH.ds, y, count, page);
		//in_ds_MH_theo_ten(dsMH, y, page, maxpage);
		c = _getch();
		if (c == ESC) {
			if (!checkSave) {
				if (khung_xac_nhan("Danh sach chua duoc luu ban co muon luu vao file khong!", 76, 14) == 1) {
					writefile_dsMH("C:/Users/84773/OneDrive/Máy tính/dsMonHoc.txt", dsMH);
					khung_bao_loi("da luu thanh cong", 90, 20, 20, 4);
				}
				else khung_bao_loi("khong luu", 90, 20, 20, 4);
				return;
			}
			return;
		}
		switch (c) {
		case F1: {
			string maMH;
			while (1) {
				SetColor(15);
				gotoxy(76, 12);
				cout << "Nhap ma mon hoc: ";
				if (nhap_ma_mon(maMH, dsMH.ds, 1)) break;
			}
			if (maMH == "") break;
			if (them_MH(dsMH.ds, maMH, 12)) {
				checkSave = 0;
				dsMH.sl++;
				++y;
			}
			break;
		}
		case F2: {
			string selected;
			if (menu_ds_MH(dsMH, page, maxpage, selected) == "") break;
			hieu_chinh_MH(dsMH.ds, selected);
			checkSave = 0;
			can_bang(dsMH.ds);
			break;
		}
		case F3: {
			system("cls");
			string selected;
			if(menu_ds_MH(dsMH, page, maxpage, selected) == "") break;
			bool check = 1;
			int choice = 0;
			for(int i=0;i<dsltc.damo;++i) {
				if (dsltc.ds[i]->MaMH == selected) khung_bao_loi("khong the xoa mon hoc nay", 78, 13, 30, 4);
				else if (khung_xac_nhan("Ban co chac chan muon xoa mon hoc nay khong!", 78, 13) == 1) {
					checkSave = 0;
					xoa_MH(dsMH.ds, selected);
					dsMH.sl--;
					--y;
					can_bang(dsMH.ds);
				}
				break;
			}
			break;
		}
		case F4: {
			checkSave = 1;
			writefile_dsMH("C:/Users/84773/OneDrive/Máy tính/dsMonHoc.txt", dsMH);
			khung_bao_loi("da luu thanh cong", 87, 15, 20, 4);
			break;
		}
		case LEFT: {
			if (page > 1)
				--page;
			break;
		}
		case RIGHT: {
			if (page < maxpage)
				++page;
			break;
		}
		}
	}
}


//========================================================= CAC THAO TAC LIEN QUAN TOI LOP TC ===========================================================================
int MaLTC(string MaMH) {
	int MaLTC = ++MA;
	return MaLTC;
}
void in_lop_tc(dsLopTc& DSLTC, int i, int y) {
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
	int x = 1;
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
	cout << DSLTC.ds[i]->max;
	gotoxy(x += 15, y);
	cout << DSLTC.ds[i]->min;
	cout << endl;
}
void in_ds_lop_tc(dsLopTc& DSLTC, int page, int maxpage) {
	int y = 3;
	if (DSLTC.damo == 0) return;
	int i = page * 11 - 11;
	if (page > 1) {
		while (i < page * 11 && i >= (page - 1) * 11 && i < DSLTC.damo) {
			int x = 1;
			if (DSLTC.ds[i]->hightlight == 1) {
				DSLTC.ds[i]->hightlight = 0;
				SetColor(20);
			}
			else SetColor(3);
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
			cout << DSLTC.ds[i]->max;
			gotoxy(x += 15, y);
			cout << DSLTC.ds[i]->min;
			++y;
			++i;
		}
	}
	else {
		while (i < 11 && i < DSLTC.damo) {
			if (DSLTC.ds[i]->hightlight == 1) {
				DSLTC.ds[i]->hightlight = 0;
				SetColor(20);
			}
			else SetColor(3);
			int x = 1;
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
			cout << DSLTC.ds[i]->max;
			gotoxy(x += 15, y);
			cout << DSLTC.ds[i]->min;
			++y;
			++i;
		}
	}
	return;
}
LopTC* tim_lopTC(dsLopTc& DSLTC, string maMH) {
	int page = 1;
	int count = 0;
	for (int i = 0; i < DSLTC.damo; ++i) {
		if (DSLTC.ds[i]->MaMH == maMH) ++count;
	}
	if (count == 0) {
		khung_bao_loi("KHONG CO LOP TC NAO DUOC MO", 80, 15, 30, 4);
		return NULL;
	}
	int choice = page * 11 - 11;
	int option = count;
	int maxpage;
	if (count % 11 == 0) maxpage = count / 11;
	else maxpage = count / 11 + 1;
	system("cls");
	khung_LTC(0, 0, 120, 2);
	while (true) {
		int jy = 3;
		count = 0;
		int selected = 0;
		for (int i = 0; i < DSLTC.damo; ++i) {
			if (count == page * 11) break;
			if (DSLTC.ds[i]->MaMH == maMH && (page - 1) * 11 <= count && count < page * 11) {
				if (choice == count) {
					SetColor(3);
					selected = i;
				}
				else {
					SetColor(7);
				}
				in_lop_tc(DSLTC, i, jy);
				++jy;
				++count;
			}
		}
		char key;
		key = _getch();
		if (key == ESC) return NULL;
		switch (key) {
		case UP: {
			--choice;
			if (choice < page * 11 - 11) {
				if (page < maxpage) choice = page * 11 - 1;
				else choice = option - 1;
			}
			break;
		}
		case DOWN: {
			++choice;
			if (choice > option - 1)  choice = maxpage * 11 - 11;
			else if (choice > page * 11 - 1) choice = page * 11 - 11;
			break;
		}
		case Enter: {
			if (selected >= 0 && selected < DSLTC.damo) {
				return DSLTC.ds[selected];
			}
		}
		case LEFT: {
			if (page > 1) {
				page--;
				choice = page * 11 - 11;
				highlight(choice);
				system("cls");
				khung_LTC(0, 0, 120, 2);
			}
			break;
		}
		case RIGHT: {
			if (page * 11 < option) {
				page++;
				choice = page * 11 - 11;
				highlight(choice);
				system("cls");
				khung_LTC(0, 0, 120, 2);
			}
			break;
		}
		}
	}
}
int kiem_tra_lopTC(dsLopTc& DSLTC, LopTC* ltc) {
	for (int i = 0; i < DSLTC.damo; ++i) {
		if (DSLTC.ds[i]->MaMH == ltc->MaMH && DSLTC.ds[i]->nien_khoa == ltc->nien_khoa && DSLTC.ds[i]->HK == ltc->HK && DSLTC.ds[i]->Nhom == ltc->Nhom) {
			khung_bao_loi("Lop TC ban vua nhap da ton tai", 40, 15, 35, 4);
			return 1;
		}
	}
	return 0;
}
DangKy* tim_sv_dk_lop_TC(LopTC*& ltc, string maSV) {
	DangKy* tmp = ltc->pdssvdk.phead;
	while (tmp != NULL) {
		if (tmp->MSV == maSV) {
			return tmp;
		}
		tmp = tmp->pnext;
	}
	return NULL;
}
//============================================== THEM LOP TC ==============================================================
int them_lop_TC(dsLopTc& DSLTC, dsMonHoc& dsMH) {
	LopTC* p = new LopTC();
	string MaMH;
	int y = 13;
	int x = 20;
	int check;
	while (1) {
		gotoxy(x, y);
		check = nhap_ma_mon(p->MaMH, dsMH.ds, 0);
		if (check == -1) {
			system("cls");
			if (menu_ds_MH(dsMH, 1, 1, p->MaMH) == "") {
				system("cls");
				khung_LTC(4, 10, 120, 2, 8, 4); 
				continue;
			}
		}
		if (p->MaMH == "") return 0;
		else {
			SetColor(7);
			gotoxy(x, y); cout << p->MaMH;
			break;
		}
	}
	p->MaLopTc = MaLTC(p->MaMH);
	while (1) {
		SetColor(7);
		gotoxy(x = 35, y);
		nhap_nien_khoa(p->nien_khoa);
		if (stoi(p->nien_khoa) < 2000 || stoi(p->nien_khoa) > 2024) {
			khung_bao_loi("Nien khoa ban vua nhap khong hop le", 40, 18, 38, 4);
			continue;
		}
		if (p->nien_khoa == "") return 0;
		break;
	}
	while (1) {
		SetColor(7);
		gotoxy(x = 50, y);
		p->HK = nhap_diem(p->HK);
		if (p->HK > 4) {
			khung_bao_loi("Hoc ki ban vua nhap khong hop le", 40, 18, 38, 4);
			continue;
		}
		if (p->HK == -1) return 0;
		else if (p->HK == -2) p->HK = 1;
		break;
	}
	gotoxy(x += 15, y);
	p->Nhom = nhap_diem(p->Nhom);
	if (p->Nhom == -1) return 0;
	else if (p->Nhom == -2) p->Nhom = 1;
	while (1) {
		SetColor(7);
		int max = p->max, min = p->min;
		gotoxy(x += 15, y);
		p->max = nhap_diem(p->max);
		if (p->max == -1) return 0;
		else if (p->max == -2) p->max = max;

		gotoxy(x += 15, y);
		p->min = nhap_diem(p->min);
		if (p->min == -1) return 0;
		else if (p->min == -2) p->min = min;

		if (p->min < p->max) break;
		else {
			khung_bao_loi("thong tin ban vua nhap khong hop le", 50, 20, 40, 4);
			x -= 30;
		}
	}
	if (!kiem_tra_lopTC(DSLTC, p)) {
		p->huylop = 1;
		p->hightlight = 1;
		MonHoc* MH = dsMH.ds;
		DSLTC.ds[DSLTC.damo] = p;
		++DSLTC.damo;
		return 1;
	}
}
// ============================================= XOA VA HIEU CHINH LOP TC =================================================
void xoa_lop_TC(dsLopTc& DSLTC, LopTC* lop) {
	if (lop == NULL) return;
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
int hieu_chinh_lop_TC(dsLopTc& DSLTC, LopTC* lop, dsMonHoc& dsMH) {
	system("cls");
	int x = 20, y = 13;
	string maMH = lop->MaMH, nien_khoa = lop->nien_khoa;
	int hk = lop->HK, nhom = lop->Nhom, min = lop->min, max = lop->max;
	if (lop == NULL) return 0;
	khung_LTC(4, 10, 120, 2, 8, 4);
	SetColor(15);
	for (int i = 0; i < DSLTC.damo; ++i) {
		if (lop->MaLopTc == DSLTC.ds[i]->MaLopTc) {
			maMH = DSLTC.ds[i]->MaMH;
			nien_khoa = DSLTC.ds[i]->nien_khoa;
			hk = DSLTC.ds[i]->HK;
			nhom = DSLTC.ds[i]->Nhom;
			max = DSLTC.ds[i]->max;
			min = DSLTC.ds[i]->min;

			gotoxy(x, y); cout << DSLTC.ds[i]->MaMH;
			gotoxy(x += 15, y); cout << DSLTC.ds[i]->nien_khoa;
			gotoxy(x += 15, y); cout << DSLTC.ds[i]->HK;
			gotoxy(x += 15, y); cout << DSLTC.ds[i]->Nhom;
			gotoxy(x += 15, y); cout << DSLTC.ds[i]->max;
			gotoxy(x += 15, y); cout << DSLTC.ds[i]->min;
			x = 20;
			gotoxy(x, y);
			if (nhap_ma_mon(maMH, dsMH.ds, 0) == -1) {
				system("cls");
				menu_ds_MH(dsMH, 1, 1, DSLTC.ds[i]->MaMH);
				system("cls");
				khung_LTC(4, 10, 120, 2, 8, 4);
				gotoxy(x, y);
				cout << DSLTC.ds[i]->MaMH;
			}
			else if (maMH == "") return 0;
			else DSLTC.ds[i]->MaMH = maMH;

			gotoxy(x += 15, y);
			nhap_nien_khoa(nien_khoa);
			if (nien_khoa == "") return 0;
			else DSLTC.ds[i]->nien_khoa = nien_khoa;

			gotoxy(x += 15, y);
			hk = nhap_diem(DSLTC.ds[i]->HK);
			if (hk == -1) return 0;
			else if (hk != -2) DSLTC.ds[i]->HK = hk;

			gotoxy(x += 15, y);
			nhom = nhap_diem(DSLTC.ds[i]->Nhom);
			if (nhom == -1) return 0;
			else if (nhom!= -2) DSLTC.ds[i]->Nhom = nhom;

			while (1) {
				max = DSLTC.ds[i]->max, min = DSLTC.ds[i]->min;
				gotoxy(x += 15, y);
				DSLTC.ds[i]->max = nhap_diem(DSLTC.ds[i]->max);
				if (DSLTC.ds[i]->max == -1) return 0;
				else if (DSLTC.ds[i]->max == -2) DSLTC.ds[i]->max = max;

				gotoxy(x += 15, y);
				DSLTC.ds[i]->min = nhap_diem(DSLTC.ds[i]->min);
				if (DSLTC.ds[i]->min == -1) return 0;
				else if (DSLTC.ds[i]->min == -2) DSLTC.ds[i]->min = min;


				if (DSLTC.ds[i]->min < DSLTC.ds[i]->max) {
					DSLTC.ds[i]->hightlight = 1;
					break;
				}
				else {
					khung_bao_loi("thong tin ban vua nhap khong hop le", 50, 20, 40, 4);
					x -= 30;
				}
			}
		}
	}
	return 1;
}
// ============================================= MENU VA CAP NHAT LOP TC ==================================================
LopTC* menu_Mo_Lop_TC(dsLopTc& DSLTC, int& page, int maxpage) {
	int choice = page * 11 - 11;
	int option = DSLTC.damo;
	int count = 0;
	system("cls");
	khung_LTC(0, 0, 120, 2, 8, 16, 1);
	gotoxy(52, 17);
	cout << "<" << page << '/' << maxpage << ">";
	while (true) {
		int jy = 3;
		for (int i = page * 11 - 11; i < page * 11; ++i) {
			if (page == 1 || page == maxpage) {
				if (i >= DSLTC.damo)
					break;
			}
			if (choice == i) {
				SetColor(9);
			}
			else {
				SetColor(7);
			}
			in_lop_tc(DSLTC, i, jy);
			++jy;
		}
		char key;
		key = _getch();
		if (key == ESC) return NULL;
		switch (key) {
		case UP: {
			--choice;
			if (choice < page * 11 - 11) {
				if (page < maxpage) choice = page * 11 - 1;
				else choice = DSLTC.damo - 1;
			}
			break;
		}
		case DOWN: {
			++choice;
			if (choice > option - 1) {
				choice = maxpage * 11 - 11;
			}
			else if (choice > page * 11 - 1) {
				choice = page * 11 - 11;
			}
			break;
		}
		case Enter: {
			if (choice >= 0 && choice < DSLTC.damo) {
				return DSLTC.ds[choice];
			}
		}
		case LEFT: {
			if (page > 1) {
				page--;
				choice = page * 11 - 11;
				highlight(choice);
				system("cls");
				khung_LTC(0, 0, 120, 2, 8, 16, 1);
				gotoxy(52, 17);
				cout << "<" << page << '/' << maxpage << ">";
			}
			break;
		}
		case RIGHT: {
			if (page * 11 < option) {
				page++;
				choice = page * 11 - 11;
				highlight(choice);
				system("cls");
				khung_LTC(0, 0, 120, 2, 8, 16, 1);
				gotoxy(52, 17);
				cout << "<" << page << '/' << maxpage << ">";
			}
			break;
		}
		}
	}
}
void cap_nhat_lop_TC(dsLopTc& dsLTC, dsMonHoc& dsMH) {
	int page = 1;
	int maxpage;
	char c;
	int checkSave = 1;
	khung_LTC(0, 0, 120, 2, 8, 16, 1);
	while (1) {
		if (dsLTC.damo == 0) maxpage = 1;
		else if (dsLTC.damo % 11 != 0) maxpage = dsLTC.damo / 11 + 1;
		else maxpage = dsLTC.damo / 11;
		gotoxy(52, 17);
		cout << "<" << page << '/' << maxpage << ">";
		in_ds_lop_tc(dsLTC, page, maxpage);
		c = _getch();
		if (c == ESC) {
			if (!checkSave) {
				if (khung_xac_nhan("Danh sach chua duoc luu ban co muon luu khong!", 30, 18) == 1) {
					writefile_dsMH("C:/Users/84773/OneDrive/Máy tính/dsMonHoc.txt", dsMH);
					khung_bao_loi("da luu thanh cong", 42, 24, 20, 4);
				}
				return;;
			}
			return;
		}
		switch (c) {
		case F1: {
			system("cls");
			khung_LTC(4, 10, 120, 2, 8, 4);
			gotoxy(30, 16); cout << "ENTER : CHON";
			gotoxy(50, 16); cout << "TAB : XEM DS MH";
			gotoxy(70, 16); cout << "ESC : THOAT";
			if (them_lop_TC(dsLTC, dsMH)) checkSave = 0;
			system("Cls");
			khung_LTC(0, 0, 120, 2, 8, 16, 1);
			break;
		}
		case F2: {
			system("cls");
			LopTC* loptc = menu_Mo_Lop_TC(dsLTC, page, maxpage);
			if (loptc == NULL) break;
			if (hieu_chinh_lop_TC(dsLTC, loptc, dsMH)) checkSave = 0;
			system("cls");
			khung_LTC(0, 0, 120, 2, 8, 16, 1);
			break;
		}
		case F3: {
			system("cls");
			bool check = 1;
			int choice = 0;
			LopTC* loptc = new LopTC();
			loptc = menu_Mo_Lop_TC(dsLTC, page, maxpage);
			if (loptc == NULL) break;
			/*gotoxy(74, 12); cout << "Ban co chac chan muon xoa sinh vien nay khong!";
			khung_lua_chon(76, 15, 7, 2);
			khung_lua_chon(110, 15, 7, 2);
			while (1) {
				for (int i = 0; i < 2; ++i) {
					if (i == choice) SetColor(20);
					else SetColor(7);
					switch (i) {
					case 0: {
						gotoxy(79, 16); cout << "co";
						break;
					}
					case 1: {
						gotoxy(111, 16); cout << "khong";
						break;
					}
					}
				}
				char key = _getch();
				if (key == 13) break;
				switch (key) {
				case LEFT: {
					--choice;
					if (choice < 0) choice = 0;
					check = 1;
					break;
				}
				case RIGHT: {
					++choice;
					if (choice > 1) choice = 1;
					check = 0;
					break;
				}
				}
			}*/
			if (loptc->pdssvdk.sl >= loptc->min) khung_bao_loi("Khong the xoa lop TC nay", 40, 20, 30, 4);
			else
				if (khung_xac_nhan("Ban co chac chan muon xoa lop TC nay khong!", 35, 18) == 1) {
				//if (check) {
				checkSave = 0;
				xoa_lop_TC(dsLTC, loptc);
				khung_bao_loi("Da xoa thanh cong 1 lop TC", 40, 24, 30, 4);
				Sleep(1500);
				//}
			}
			system("cls");
			khung_LTC(0, 0, 120, 2, 8, 16, 1);
			break;
		}
		case F4: {
			checkSave = 1;
			writefile_dsLTC("C:/Users/84773/OneDrive/Máy tính/dsLTC.txt", dsLTC);
			khung_bao_loi("da luu thanh cong", 45, 20, 20, 4);
			system("cls");
			khung_LTC(0, 0, 120, 2, 8, 16, 1);
			break;
		}
		case LEFT: {
			if (page > 1) {
				--page;
				system("cls");
				khung_LTC(0, 0, 120, 2, 8, 16, 1);
			}
			break;
		}
		case RIGHT: {
			if (page < maxpage) {
				++page;
				system("cls");
				khung_LTC(0, 0, 120, 2, 8, 16, 1);
			}
			break;
		}
		}
	}
}
// ============================================= IN DS DK LOP TC ==========================================================
void in_ds_SV_DK(dsLopTc& dsLTC, dsLop& dslop, dsMonHoc& dsMH) {
	int page = 1;
	int maxpage;
	string nien_khoa;
	string maMH;
	int hk;
	int nhom;
	LopTC* loptc = new LopTC();
	while (1) {
		SetColor(3);
		for (int iy = 10; iy < 15; ++iy) {
			gotoxy(40, iy);
			cout << char(179);
			gotoxy(70, iy);
			cout << char(179);
		}
		for (int ix = 40; ix < 70; ++ix) {
			gotoxy(ix, 10);
			cout << char(196);
			gotoxy(ix, 0 + 14);
			cout << char(196);
			gotoxy(ix, 0 + 14);
			cout << char(196);
		}
		gotoxy(40, 10); cout << char(218);
		gotoxy(70, 10); cout << char(191);
		gotoxy(70, 14); cout << char(217);
		gotoxy(40, 14); cout << char(192);
		gotoxy(49, 11); cout << "Nhap ma mon hoc: ";
		gotoxy(41, 15); cout << "ESC : THOAT";
		gotoxy(58, 15); cout << "ENTER : CHON";
		gotoxy(45, 17); cout << "TAB : XEM DS MON HOC";
		gotoxy(49, 12);
		if (nhap_ma_mon(maMH, dsMH.ds, 0) == -1) {
			system("cls");
			menu_ds_MH(dsMH, 1, 1, maMH);
			if (maMH == "") {
				system("cls");
				continue;
			}
			loptc = tim_lopTC(dsLTC, maMH);
			if (loptc == NULL) {
				system("cls");
				continue;
			}
			break;
		}
		else if (maMH != "") {
			system("cls");
			if (tim_MH(dsMH.ds, maMH) == NULL) {
				khung_bao_loi("KHONG TIM THAY MA MON HOC", 59, 14, 30, 4);
				continue;
			}
			loptc = tim_lopTC(dsLTC, maMH);
			if (loptc == NULL) {
				system("cls");
				continue;
			}
			break;
		}
		else return;
	}
	system("cls");
	khung_ds_SV(0, 0, 70, 2, 25, 0);
	if (loptc->pdssvdk.sl % 11 != 0)
		maxpage = loptc->pdssvdk.sl / 11 + 1;
	else maxpage = loptc->pdssvdk.sl / 11;
	while (1) {
		int count = 0;
		int jy = 3;
		bool check = 0;
		DangKy* dk = loptc->pdssvdk.phead;
		while (dk != NULL && !dk->huy) {
			for (int i = 0; i < dslop.soluong; ++i) {
				Sinhvien* sv = dslop.ds_lop[i].pdsSV.phead;
				while (sv != NULL) {
					if (dk->MSV == sv->MaSV && dk->huy == 0) {
						if (count >= 11 * page - 11 && count < 11 * page) {
							in_thong_tin_SV(sv, jy);
							jy += 2;
							++count;
							break;
						}
						else {
							++count;
							break;
						}
					}
					else sv = sv->pnext;
				}
			}
			dk = dk->pnext;
		}
		char key = _getch();
		if (key == ESC) return;
		switch (key) {
		case LEFT: {
			if (page > 1) {
				--page;
				system("cls");
				khung_ds_SV(0, 0, 70, 2, 25, 0);
			}
			break;
		}
		case RIGHT: {
			if (page < maxpage) {
				system("cls");
				++page;
				khung_ds_SV(0, 0, 70, 2, 25, 0);
			}
			break;
		}
		}
	}
	delete loptc;
}


// ============================================= DK VA HUY LOP TC ==========================================================
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
	khung_dk_LTC("CAC LOP TIN CHI DA MO:", 0, 4, 90, 12);
	khung_dk_LTC("CAC LOP TIN CHI DA DANG KY", 0, 18, 90, 12);
	while (1) {
		int count = 0;
		int mark = 0;
		int iy = 6;
		int jy = 20;
		for (int i = 0; i < dsltc.damo; ++i) {
			if (mode == F1) {
				if (kiem_tra_svDK(dsltc.ds[i], maSV) && dsltc.ds[i]->nien_khoa == nien_khoa && dsltc.ds[i]->HK == hk) {
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
			if (mode == F3) {
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
		if (key == ESC) return -1;
		switch (key) {
		case UP: {
			--choice;
			if (choice < 0) {
				choice = count - 1;
			}
			break;
		case DOWN: {
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
		case Enter: {
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
int them_SV_DK(dsLopTc& dsltc, LopTC* LTC, dsLop& dslop, string maSV) {
	//system("cls");
	SetColor(7);
	DangKy* svDK = LTC->pdssvdk.phead;
	for (int i = 0; i < dsltc.damo; ++i) {
		if (dsltc.ds[i]->MaMH == LTC->MaMH && dsltc.ds[i]->nien_khoa == LTC->nien_khoa) {
			DangKy* SVcheck = dsltc.ds[i]->pdssvdk.phead;
			while (SVcheck != NULL) {
				if (SVcheck->MSV == maSV) {
					khung_bao_loi("BAN DA DK LTC NAY", 95, 14, 30, 4);
					return 0;
				}
				SVcheck = SVcheck->pnext;
			}
		}
	}
	DangKy* tmp = new DangKy();
	tmp->MSV = maSV;
	tmp->huy = 0;
	if (svDK == NULL) {
		LTC->pdssvdk.phead = tmp;
		//SV = tim_sinh_vien(dslop, svDK->MSV);
		//++SV->daDK;
		return 1;
	}
	else {
		while (svDK != NULL) {
			if (svDK->MSV == maSV) {
				svDK->huy = 0; 
				//SV = tim_sinh_vien(dslop, svDK->MSV);
				//++SV->daDK;
				return 1;
			}
			svDK = svDK->pnext;
		}
		svDK = tmp;
		//SV = tim_sinh_vien(dslop, svDK->MSV);
		//++SV->daDK;
		return 1;
	}
	return 0;
}
int HUY_DK_LOP_TC(LopTC*& LTC, dsLop& dslop, string maSV) {
	system("cls");
	SetColor(7);
	DangKy* svDK = LTC->pdssvdk.phead;
	while (svDK != NULL) {
		if (maSV == svDK->MSV) {
			//Sinhvien* tmp = tim_sinh_vien(dslop, maSV);
			svDK->huy = 1;
			//--tmp->daDK;
			return 1;
		}
		svDK = svDK->pnext;
	}
	return 0;
}
void DK_LOP_TC(dsLopTc& dsltc, dsLop& dslop, dsMonHoc& dsMH) {
	string maSV;
	string nien_khoa;
	int hk = 0;
	int check = 0;
	int mode;
	int page = 1;
	int maxpage;
	dsSV dssv; 
	Sinhvien* tmp = new Sinhvien();
	for (int iy = 8; iy < 13; ++iy) {
		gotoxy(30, iy);
		cout << char(179);
		gotoxy(60, iy);
		cout << char(179);
	}
	for (int ix = 30; ix < 60; ++ix) {
		gotoxy(ix, 8);
		cout << char(196);
		gotoxy(ix, 0 + 12);
		cout << char(196);
		gotoxy(ix, 0 + 12);
		cout << char(196);
	}
	gotoxy(30, 8); cout << char(218);
	gotoxy(60, 8); cout << char(191);
	gotoxy(60, 12); cout << char(217);
	gotoxy(30, 12); cout << char(192);
	gotoxy(37, 9); cout << "NHAP MA SINH VIEN";
	gotoxy(37, 10); nhap_ma_SV(maSV, dslop);
	if (maSV == "") return;
	for (int i = 0; i < dslop.soluong; ++i) {
		dssv = dslop.ds_lop[i].pdsSV;
		while (dssv.phead != NULL) {
			if (maSV == dssv.phead->MaSV) {
				system("cls");
				tmp = dssv.phead;
				check = 1;
				break;
			}
			dssv.phead = dssv.phead->pnext;
		}
		if (check) break;
	}
	gotoxy(1, 1); cout << "HO: " << tmp->ho;
	gotoxy(25, 2); cout << "TEN: " << tmp->ten;
	gotoxy(40, 1); cout << "SDT: " << tmp->SDT;
	gotoxy(65, 2); cout << "GIOI TINH: " << tmp->phai;
	gotoxy(90, 1); cout << "NIEN KHOA: ";
	while (1) {
		SetColor(7);
		nhap_nien_khoa(nien_khoa);
		if (stoi(nien_khoa) < 2000 || stoi(nien_khoa) > 2024) {
			khung_bao_loi("Nien khoa ban vua nhap khong hop le", 40, 18, 38, 4);
			continue;
		}
		if (nien_khoa == "") return;
		break;
	}
	gotoxy(115, 2); cout << "HOC KI: ";
	int x = wherex(), y = wherey();
	while (1) {
		SetColor(7);
		gotoxy(x, y);
		hk = nhap_diem(hk);
		if (hk > 4) {
			khung_bao_loi("Hoc ki ban vua nhap khong hop le", 40, 18, 38, 4);
			continue;
		}
		if (hk == -1) return;
		else if (hk == -2) hk = 1;
		break;
	}
	while (1) {
		gotoxy(1, 1); cout << "HO: " << tmp->ho;
		gotoxy(25, 2); cout << "TEN: " << tmp->ten;
		gotoxy(40, 1); cout << "SDT: " << tmp->SDT;
		gotoxy(65, 2); cout << "GIOI TINH: " << tmp->phai;
		gotoxy(90, 1); cout << "NIEN KHOA: " << nien_khoa;
		gotoxy(115, 2); cout << "HOC KI: " << hk;
		khung_dk_LTC("CAC LOP TIN CHI DA MO:", 0, 4, 90, 12);
		khung_dk_LTC("CAC LOP TIN CHI DA DK:", 0, 18, 90, 12);
		int iy = 6;
		int jy = 20;
		for (int i = 0; i < dsltc.damo; ++i) {
			if (kiem_tra_svDK(dsltc.ds[i], maSV) && dsltc.ds[i]->nien_khoa == nien_khoa && dsltc.ds[i]->HK == hk) {
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
		if (key == ESC) return;
		switch (key) {
		case F1: {
			mode = F1;
			int i = menu_dk_lop_TC(dsltc, dsMH, maSV, nien_khoa, hk, mode);
			if (i != -1) {
				if (them_SV_DK(dsltc, dsltc.ds[i], dslop, maSV)) ++dsltc.ds[i]->pdssvdk.sl;
				if (dsltc.ds[i]->pdssvdk.sl >= dsltc.ds[i]->min) dsltc.ds[i]->huylop = 0;
				break;
			}
			break;
		}
		case F3: {
			mode = F3;
			int i = menu_dk_lop_TC(dsltc, dsMH, maSV, nien_khoa, hk, mode);
			if (i != -1) {
				if (khung_xac_nhan("Ban co chac chan muon huy lop TC nay khong!", 74, 12) == 1) {
					if (HUY_DK_LOP_TC(dsltc.ds[i], dslop, maSV))
						if (dsltc.ds[i]->pdssvdk.sl > 0) --dsltc.ds[i]->pdssvdk.sl;
					if (dsltc.ds[i]->pdssvdk.sl < dsltc.ds[i]->min) dsltc.ds[i]->huylop = 1;
				}
				break;
			}
			break;
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
			in_thong_tin_nhap_diem(dslop, dk, iy, count);
			++count;
			iy += 2;
			dk = dk->pnext;
		}
		char key = _getch();
		if (key == ESC) return -1;
		if (key == Enter) {
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
			double check = nhap_diem(0);
			if(check != -1)
			tmp->Diem = check;
		}
		switch (key) {
		case UP: {
			--choice;
			if (choice < 0) choice = option - 1;
			break;
		}
		case DOWN: {
			++choice;
			if (choice > option - 1) choice = 0;
			break;
		}
		}
	}
}
void Nhap_diem(dsLopTc& dsltc, dsLop& dslop, dsMonHoc& dsMH) {
	string nien_khoa;
	string maMH;
	int hk;
	int nhom; 
	/*nhap_thong_tin_in_diem(30, 9, 72, 2, 4, 4);
	gotoxy(34, 12); nhap_nien_khoa(nien_khoa);
	if (nien_khoa == "") return;
	gotoxy(55, 12); hk = nhap_diem(0);
	if (hk == -1) return;
	gotoxy(73, 12); nhom = nhap_diem(0);
	if (nhom == -1) return;
	gotoxy(91, 12);
	while (1) {
		if (nhap_ma_mon(maMH, dsMH.ds, 0) == -1) {
			system("cls");
			menu_ds_MH(dsMH, 1, 1, maMH);
			break;
		}
		else {
			system("cls");
			break;
		}
	}
	nhap_thong_tin_in_diem(30, 9, 72, 2, 4, 4);
	gotoxy(34, 12); cout << nien_khoa;
	gotoxy(55, 12); cout << hk;
	gotoxy(73, 12); cout << nhom;
	gotoxy(91, 12); cout << maMH;
	if (maMH == "") return;*/
	LopTC* loptc = new LopTC();
	while (1) {
		SetColor(3);
		for (int iy = 10; iy < 15; ++iy) {
			gotoxy(40, iy);
			cout << char(179);
			gotoxy(70, iy);
			cout << char(179);
		}
		for (int ix = 40; ix < 70; ++ix) {
			gotoxy(ix, 10);
			cout << char(196);
			gotoxy(ix, 0 + 14);
			cout << char(196);
			gotoxy(ix, 0 + 14);
			cout << char(196);
		}
		gotoxy(40, 10); cout << char(218);
		gotoxy(70, 10); cout << char(191);
		gotoxy(70, 14); cout << char(217);
		gotoxy(40, 14); cout << char(192);
		gotoxy(49, 11); cout << "Nhap ma mon hoc: ";
		gotoxy(41, 15); cout << "ESC : THOAT";
		gotoxy(58, 15); cout << "ENTER : CHON";
		gotoxy(45, 17); cout << "TAB : XEM DS MON HOC";
		gotoxy(49, 12);
		if (nhap_ma_mon(maMH, dsMH.ds, 0) == -1) {
			system("cls");
			menu_ds_MH(dsMH, 1, 1, maMH);
			if (maMH == "") {
				system("cls");
				continue;
			}
			loptc = tim_lopTC(dsltc, maMH);
			if (loptc == NULL) {
				system("cls");
				continue;
			}
			break;
		}
		else if (maMH != "") {
			system("cls");
			if (tim_MH(dsMH.ds, maMH) == NULL) {
				khung_bao_loi("KHONG TIM THAY MA MON HOC", 59, 14, 30, 4);
				continue;
			}
			loptc = tim_lopTC(dsltc, maMH);
			if (loptc == NULL) {
				system("cls");
				continue;
			}
			break;
		}
		else return;
	}
	/*for (int i = 0; i < dsltc.damo; ++i) {
		if (dsltc.ds[i]->nien_khoa == nien_khoa && dsltc.ds[i]->HK == hk && dsltc.ds[i]->Nhom == nhom && dsltc.ds[i]->MaMH == maMH) {
			system("cls");
			khung_nhap_diem(0, 0, 90, 2);
			int selected = menu_nhap_diem(dsltc.ds[i], dslop);
			if (selected == -1) return;
		}
	}*/
	system("cls");
	khung_nhap_diem(0, 0, 90, 2);
	int selected = menu_nhap_diem(loptc, dslop);
	if (selected == -1) return;
	delete loptc;
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
	int soTC = 0;
	int check = 0;
	for (int i = 0; i < dsltc.damo; ++i) {
		DangKy* dk = dsltc.ds[i]->pdssvdk.phead;
		while (dk != NULL) {
			if (maSV == dk->MSV) {
				check = 1;
				MonHoc* tmp = tim_MH(dsMH.ds, dsltc.ds[i]->MaMH);
				if (tmp != NULL) {
					soTC += tmp->STCLT + tmp->STCTH;
					diemTB += (tmp->STCLT + tmp->STCTH) * dk->Diem;
					break;
				}
			}
			dk = dk->pnext;
		}
		if (!check) return 0;
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
		for (int i = 1; i <= 12 * (page - 1); ++i) {
			SV = SV->pnext;
			++count;
		}
	}
	while (SV != NULL && count < page * 12) {
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

double is_max_score(dsLopTc& dsLTC, string ma_mon, string maSV, double score, int index) {
	double maxScore = score;
	for (int i = index; i < dsLTC.damo; ++i) {
		if (dsLTC.ds[i]->MaMH == ma_mon) {
			DangKy* dk = dsLTC.ds[i]->pdssvdk.phead;
			while (dk != NULL && dk->MSV == maSV) {
				if (maxScore < dk->Diem) maxScore = dk->Diem;
				dk = dk->pnext;
			}
		}
	}
	return maxScore;
}
void in_diem_tong_ket(dsLopTc& dsltc, dsMonHoc& dsMH, string maSV, int y, int w, int col) {
	int x = 43;
	for (int i = 0; i < dsltc.damo; ++i) {
		int check = 0;
		DangKy* dk = dsltc.ds[i]->pdssvdk.phead;
		MonHoc* MH = tim_MH(dsMH.ds, dsltc.ds[i]->MaMH);
		if (MH != NULL && MH->dadk == 1 && MH->freq == 0) {
			MH->freq = 1;
			while (dk != NULL) {
				if (dk->MSV == maSV) {
					if (dk->huy == 0) {
						gotoxy(x, y); cout << is_max_score(dsltc, MH->MaMon, maSV, dk->Diem, i + 1);
						x += (w - 42) / col;
						check = 1;
						break;
					}
					else if (dk->huy == 1) {
						gotoxy(x, y); cout << 0;
						x += (w - 42) / col;
						check = 1;
						return;
					}
				}
				dk = dk->pnext;
			}
			if (!check)
			{
				gotoxy(x, y); cout << 0;
				x += (w - 42) / col;
			}
		}
	}
}
void in_bang_diem_tong_ket(dsLopTc& dsltc, dsMonHoc& dsMH, Lop lop, int page, int w, int col) {
	int count = 0;
	int y = 6;
	Sinhvien* sv = lop.pdsSV.phead;
	if (page > 1) {
		for (int i = 1; i <= 12 * (page - 1); ++i) {
			sv = sv->pnext;
			++count;
		}
	}
	while (sv != NULL && count < page * 12) {
		int x = 1;
		++count;
		for (int j = 0; j < dsltc.damo; ++j) {
			MonHoc* MH = tim_MH(dsMH.ds, dsltc.ds[j]->MaMH);
			if (MH != NULL && MH->dadk) MH->freq = 0;
		}
		gotoxy(x, y); cout << count;
		gotoxy(x += 5, y); cout << sv->MaSV;
		gotoxy(x += 12, y); cout << sv->ho << sv->ten;
		in_diem_tong_ket(dsltc, dsMH, sv->MaSV, y, w, col);
		y += 2;
		sv = sv->pnext;
	}
}
void in_bang_diem(dsLopTc& dsltc, dsMonHoc& dsMH, dsLop& dslop) {
	int choice = 0;
	int option = 3;
	int x = 40, y = 6;
	int check;
	while (1) {
		SetColor(3);
		gotoxy(45, 7); cout << "Chon Bang Diem Ban Muon Xem";
		for (int ix = 40; ix < 85; ix += 45) {
			for (int iy = y; iy <= y + 10; ++iy) {
				gotoxy(ix, iy);
				cout << char(179);
				gotoxy(85, iy);
				cout << char(179);
			}
		}
		for (int ix = 41; ix < 85; ++ix) {
			gotoxy(ix, y);
			cout << char(196);
			gotoxy(ix, y + 10);
			cout << char(196);
			gotoxy(ix, y + 2);
			cout << char(196);
		}
		gotoxy(x, y); cout << char(218);
		gotoxy(85, y); cout << char(191);
		gotoxy(x, y + 2); cout << char(192);
		gotoxy(x + 45, y + 2); cout << char(217);
		gotoxy(x + 45, y + 10); cout << char(217);
		gotoxy(x, y + 10); cout << char(192);
		gotoxy(x + 5, y + 12); cout << "ENTER : CHON";
		gotoxy(x + 30, y + 12); cout << "ESC : THOAT";
		clrscr();
		for (int i = 0; i < option; ++i) {
			if (choice == i) {
				SetColor(9);
			}
			else SetColor(7);
			switch (i) {
			case 0: {
				gotoxy(45, 10);
				cout << "In bang diem mon hoc cua lop TC" << endl;
				break;
			}
			case 1: {
				gotoxy(45, 12);
				cout << "In bang diem trung binh ket thuc mon" << endl;
				break;
			}
			case 2: {
				gotoxy(45, 14);
				cout << "In bang diem tong ket cac mon" << endl;
				break;
			}
			}
		}
		char key = _getch();
		if (key == ESC) return;
		switch (key) {
		case Enter: {
			if (choice == 0) {
				system("cls");
				string maMH;
				LopTC* loptc = new LopTC();
				// nhập mã môn và tìm lớp tín chỉ 
				while (1) {
					SetColor(3);
					for (int iy = 10; iy < 15; ++iy) {
						gotoxy(40, iy);
						cout << char(179);
						gotoxy(70, iy);
						cout << char(179);
					}
					for (int ix = 40; ix < 70; ++ix) {
						gotoxy(ix, 10);
						cout << char(196);
						gotoxy(ix, 0 + 14);
						cout << char(196);
						gotoxy(ix, 0 + 14);
						cout << char(196);
					}
					gotoxy(40, 10); cout << char(218);
					gotoxy(70, 10); cout << char(191);
					gotoxy(70, 14); cout << char(217);
					gotoxy(40, 14); cout << char(192);
					gotoxy(49, 11); cout << "Nhap ma mon hoc: ";
					gotoxy(41, 15); cout << "ESC : THOAT";
					gotoxy(58, 15); cout << "ENTER : CHON";
					gotoxy(45, 17); cout << "TAB : XEM DS MON HOC";
					gotoxy(49, 12);
					if (nhap_ma_mon(maMH, dsMH.ds, 0) == -1) {
						system("cls");
						menu_ds_MH(dsMH, 1, 1, maMH);
						if (maMH == "") {
							system("cls");
							continue;
						}
						loptc = tim_lopTC(dsltc, maMH);
						if (loptc == NULL) {
							system("cls");
							continue;
						}
						break;
					}
					else if (maMH != "") {
						//system("cls");
						if (tim_MH(dsMH.ds, maMH) == NULL) {
							khung_bao_loi("KHONG TIM THAY MA MON HOC", 40, 19, 30, 4);
							continue;
						}
						loptc = tim_lopTC(dsltc, maMH);
						if (loptc == NULL) {
							system("cls");
							continue;
						}
						break;
					}
					else break;
				}
				if (maMH == "") {
					system("cls");
					break;
				}
				system("cls");
				khung_nhap_diem(0, 3, 90, 2);
				// in bảng điểm của môn học và các thao tác liên quan
				while (1) {
					int page = 1;
					string tenMH = tim_ten_MH(dsMH.ds, loptc->MaMH);
					in_bang_diem_MH(loptc, dslop, page, tenMH);
					key = _getch();
					if (key == ESC) {
						system("cls");
						break;
					}
					switch (key) {
					case LEFT: {
						if (page > 1) {
							page--;
						}
						break;
					}
					case RIGHT: {
						if (page * 11 < loptc->pdssvdk.sl) {
							page++;
						}
						break;
					}
					}
				}
			}
			else if (choice == 1) {
				string malop;
CASE_1:		    system("cls");
				SetColor(3);
				for (int iy = 10; iy < 15; ++iy) {
					gotoxy(40, iy);
					cout << char(179);
					gotoxy(70, iy);
					cout << char(179);
				}
				for (int ix = 40; ix < 70; ++ix) {
					gotoxy(ix, 10);
					cout << char(196);
					gotoxy(ix, 0 + 14);
					cout << char(196);
					gotoxy(ix, 0 + 14);
					cout << char(196);
				}
				gotoxy(40, 10); cout << char(218);
				gotoxy(70, 10); cout << char(191);
				gotoxy(70, 14); cout << char(217);
				gotoxy(40, 14); cout << char(192);
				gotoxy(49, 11); cout << "Nhap ma lop: ";
				gotoxy(41, 15); cout << "ESC : THOAT";
				gotoxy(58, 15); cout << "ENTER : CHON";
				gotoxy(45, 17); cout << "TAB : XEM DS LOP";
				gotoxy(49, 12);
      			check = nhap_ma_lop(malop);
				// nhập hoặc chọn mã lớp từ danh sách lớp
				if (check == -1) {
					system("cls");
					int i = menu_ds_Lop(dslop, 1);
					if (i == -1) return;
					malop = dslop.ds_lop[i].MALOP;
					system("cls");
				}
				else if (!check) {
					system("cls");
					break;
				}
				for (int i = 0; i < dslop.soluong; ++i) {
					if (dslop.ds_lop[i].MALOP == malop) {
						system("cls");
						khung_nhap_diem(0, 3, 90, 2);
						int page = 1;
						// in bảng điểm TB và các thao tác liên quan
						while (1) {
							in_bang_diem_TB(dsltc, dslop.ds_lop[i], dsMH, page);
							key = _getch();
							if (key == ESC) {
								system("cls");
								break;
							}
							switch (key) {
							case LEFT: {
								if (page > 1) {
									page--;
									system("cls"); 
									khung_nhap_diem(0, 3, 90, 2);
								}
								break;
							}
							case RIGHT: {
								if (page * 12 < dslop.ds_lop[i].pdsSV.sl) {
									page++;
									system("cls");
									khung_nhap_diem(0, 3, 90, 2);
								}
								break;
							}
							}
						}
						break;
					}
					else {
						khung_bao_loi("KHONG THE TIM THAY MA LOP", 40, 20, 30, 4);
						goto CASE_1;
					}
				}
			}
			else if (choice == 2) {
				string malop;
CASE_2:			system("cls");
				SetColor(3);
				for (int iy = 10; iy < 15; ++iy) {
					gotoxy(40, iy);
					cout << char(179);
					gotoxy(70, iy);
					cout << char(179);
				}
				for (int ix = 40; ix < 70; ++ix) {
					gotoxy(ix, 10);
					cout << char(196);
					gotoxy(ix, 0 + 14);
					cout << char(196);
					gotoxy(ix, 0 + 14);
					cout << char(196);
				}
				gotoxy(40, 10); cout << char(218);
				gotoxy(70, 10); cout << char(191);
				gotoxy(70, 14); cout << char(217);
				gotoxy(40, 14); cout << char(192);
				gotoxy(49, 11); cout << "Nhap ma lop: ";
				gotoxy(41, 15); cout << "ESC : THOAT";
				gotoxy(58, 15); cout << "ENTER : CHON";
				gotoxy(45, 17); cout << "TAB : XEM DS LOP";
				gotoxy(49, 12);
				check = nhap_ma_lop(malop);
				// chọn lớp từ danh sách lớp
				if (check == -1) {
					system("cls");
					int i = menu_ds_Lop(dslop, 1);
					if (i == -1) return;
					malop = dslop.ds_lop[i].MALOP;
					system("cls");
				}
				else if (check == 0) {
					system("cls");
					break;
				}
				for (int i = 0; i < dslop.soluong; ++i) {
					if (malop == dslop.ds_lop[i].MALOP) {
						int count = 0;
						Sinhvien* SV = dslop.ds_lop[i].pdsSV.phead;
						// tìm và đánh dấu những môn có sinh viên của lớp đang ký
						while (SV != NULL) {
							for (int i = 0; i < dsltc.damo; ++i) {
								DangKy* tmp = dsltc.ds[i]->pdssvdk.phead;
								while (tmp != NULL) {
									if (tmp->MSV == SV->MaSV) {
										MonHoc* MH = tim_MH(dsMH.ds, dsltc.ds[i]->MaMH);
										if (MH->dadk == 0) {
											MH->dadk = 1;
											++count;
										}
										break;
									}
									tmp = tmp->pnext;
								}
							}
							SV = SV->pnext;
						}
						system("cls");
						int col = count;
						int w = 122;
						int x = 43;
						int page = 1;
						khung_bang_diem_tong_ket(0, 3, w, 2, col);
						// in danh sách và các thao tác với danh sách
						while (1) {
							int col = count;
							int w = 122;
							int x = 43;
							// reset tần suất
							for (int j = 0; j < dsltc.damo; ++j) {
								MonHoc* MH = tim_MH(dsMH.ds, dsltc.ds[j]->MaMH);
								if (MH != NULL && MH->dadk) MH->freq = 0;
							}
							// đánh dấu môn học đã in
							for (int j = 0; j < dsltc.damo; ++j) {
								MonHoc* MH = tim_MH(dsMH.ds, dsltc.ds[j]->MaMH);
								if (MH != NULL && MH->dadk && MH->freq == 0) {
									MH->freq = 1;
									gotoxy(x, 4); cout << MH->TenMH;
									x += (w - 42) / col;
								}
							}
							// in danh sách điểm
							in_bang_diem_tong_ket(dsltc, dsMH, dslop.ds_lop[i], page, w, col);
							key = _getch();
							if (key == ESC) {
								system("cls");
								break;
							}
							switch (key) {
							case LEFT: {
								if (page > 1) {
									page--;
									system("cls");
									khung_bang_diem_tong_ket(0, 3, w, 2, col);
								}
								break;
							}
							case RIGHT: {
								if (page * 11 < dsltc.ds[i]->pdssvdk.sl) {
									page++;
									system("cls");
									khung_bang_diem_tong_ket(0, 3, w, 2, col);
								}
								break;
							}
							}
						}
					}
					else {
						khung_bao_loi("KHONG THE TIM THAY MA LOP", 40, 20, 30, 4);
						goto CASE_2;
					}
					break;
				}
			}
		}
		case UP: {
			--choice;
			if (choice < 0) choice = option - 1;
			break;
		}
		case DOWN: {
			++choice;
			if (choice > option - 1) choice = 0;
			break;
		}
		}
	}
}

// ================================================================= DOC FILE ASCII ART ================================================================================
void readfile(string str, int x = 50 , int y = 8) {
	SetColor(20);
	SetBGColor(0);
	ifstream fileinput(str, ios::app);
	if (fileinput.fail()) {
		cout << "khong the mo file" << endl;
	}
	while (!fileinput.eof()) {
		string s;
		gotoxy(x, y);
		getline(fileinput, s);
		cout << s;
		++y;
	}
}

// ================================================================= DOC FILE VA THAO TAC VOI THREAD ===================================================================
void readfile1(string str, int i, int x = 50, int y = 8) {
	SetColor(20);
	string s;
	ifstream fileinput(str);
	if (fileinput.fail()) {
		cout << "khong the mo file" << endl;
	}
	while (getline(fileinput, s)) {
		gotoxy(x, y);
		if (i < 130) {
			cout << string(130 - i, ' ') << s.substr(0, i);
		}
		else {
			cout << s.substr(i - 130, s.length());
		}
		++y;
	}
}
void giao_dien_chinh() {
	while (1) {
		SetBGColor(0);
		for (int i = 0; i < 130 + 83; ++i) {
			readfile1("C:/Users/84773/OneDrive/Máy tính/Quan_ly_SV.txt", i, 1, 1);
			Sleep(25);
		}
	}
	system("cls");
}


int main() {
	fullscreen();
	//SetColor(4);
	//system("pause");
// ========================================== ds lop ==================================
	dsLopTc dsLTC;
	dsLop dslop;
	dsMonHoc dsMH;
	int choice = 0;
	int option = 9;
	int px = 3;
	readfile_dsLop("C:/Users/84773/OneDrive/Máy tính/dsLop.txt", dslop);
	readfile_dsLTC("C:/Users/84773/OneDrive/Máy tính/dsLTC.txt", dsLTC);
	readfile_dsMH("C:/Users/84773/OneDrive/Máy tính/dsMonHoc.txt", dsMH);
	khung_giao_dien_chinh();
	readfile("C:/Users/84773/OneDrive/Máy tính/test.txt");
	readfile("C:/Users/84773/OneDrive/Máy tính/Quan_ly_SV.txt", 20, 1);
	//thread giao_dien(giao_dien_chinh);
	while (1) {
		int py = 8;
		clrscr();
		SetBGColor(0);
		SetColor(7);
		for (int i = 0; i < option; ++i) {
			if (choice == i) {
				highlight(i);
			}
			else {
				normal(i);
			}
			switch (i) {
			case 0: {
				gotoxy(px, py);
				cout << "1. Cap nhat sinh vien cua lop";
				break;
			}
			case 1: {
				gotoxy(px, py += 2);
				cout << "2. Cap nhat danh sach mon hoc";
				break;
			}
			case 2: {
				gotoxy(px, py += 2);
				cout << "3. In danh sach mon hoc";
				break;
			}
			case 3: {
				gotoxy(px, py += 2);
				cout << "4. Mo lop tin chi";
				break;
			}
			case 4: {
				gotoxy(px, py += 2);
				cout << "5. Dang ky lop tin chi";
				break;
			}
			case 5: {
				gotoxy(px, py += 2);
				cout << "6. In danh sach sinh vien dang ky";
				break;
			}
			case 6: {
				gotoxy(px, py += 2);
				cout << "7. Nhap diem";
				break;
			}
			case 7: {
				gotoxy(px, py += 2);
				cout << "8. In bang diem";
				break;
			}
			case 8: {
				gotoxy(px, py += 2);
				cout << "9. thoat";
				break;
			}
			}
		}
		char key;
		key = _getch();
		switch (key)
		{
		case UP: {
			--choice;
			if (choice < 0) choice = option - 1;
			break;
		}
		case DOWN: {
			++choice;
			if (choice > option - 1) choice = 0;
			break;
		}
		case Enter: {
			system("cls");
			switch (choice) {
			case 0: {
				kiem_tra_ds_SV(dslop);
				system("cls");
				khung_giao_dien_chinh();
				readfile("C:/Users/84773/OneDrive/Máy tính/test.txt");
				readfile("C:/Users/84773/OneDrive/Máy tính/Quan_ly_SV.txt", 20, 1);
				break;
			}
			case 1: {
				ds_MH(dsMH, dsLTC);
				system("cls");
				khung_giao_dien_chinh();
				readfile("C:/Users/84773/OneDrive/Máy tính/test.txt");
				readfile("C:/Users/84773/OneDrive/Máy tính/Quan_ly_SV.txt", 20, 1);
				break;
			}
			case 2: {
				system("cls");
				in_ds_MH_theo_ten(dsMH);
				system("cls");
				khung_giao_dien_chinh();
				readfile("C:/Users/84773/OneDrive/Máy tính/test.txt");
				readfile("C:/Users/84773/OneDrive/Máy tính/Quan_ly_SV.txt", 20, 1);
				break;
			}
			case 3: {
				system("cls");
				cap_nhat_lop_TC(dsLTC, dsMH);
				system("cls");
				khung_giao_dien_chinh();
				readfile("C:/Users/84773/OneDrive/Máy tính/test.txt");
				readfile("C:/Users/84773/OneDrive/Máy tính/Quan_ly_SV.txt", 20, 1);
				break;
			}
			case 4: {
				system("cls");
				DK_LOP_TC(dsLTC, dslop, dsMH);
				writefile_dsLTC("C:/Users/84773/OneDrive/Máy tính/dsLTC.txt", dsLTC);
				system("cls");
				khung_giao_dien_chinh();
				readfile("C:/Users/84773/OneDrive/Máy tính/test.txt");
				readfile("C:/Users/84773/OneDrive/Máy tính/Quan_ly_SV.txt", 20, 1);
				break;
			}
			case 5: {
				system("cls");
				in_ds_SV_DK(dsLTC, dslop, dsMH);
				system("cls");
				khung_giao_dien_chinh();
				readfile("C:/Users/84773/OneDrive/Máy tính/test.txt");
				readfile("C:/Users/84773/OneDrive/Máy tính/Quan_ly_SV.txt", 20, 1);
				break;
			}
			case 6: {
				system("cls");
				Nhap_diem(dsLTC, dslop, dsMH);
				writefile_dsLTC("C:/Users/84773/OneDrive/Máy tính/dsLTC.txt", dsLTC);
				system("cls");
				khung_giao_dien_chinh();
				readfile("C:/Users/84773/OneDrive/Máy tính/test.txt");
				readfile("C:/Users/84773/OneDrive/Máy tính/Quan_ly_SV.txt", 20, 1);
				break;
			}
			case 7: {
				in_bang_diem(dsLTC, dsMH, dslop);
				system("cls");
				khung_giao_dien_chinh();
				readfile("C:/Users/84773/OneDrive/Máy tính/test.txt");
				readfile("C:/Users/84773/OneDrive/Máy tính/Quan_ly_SV.txt", 20, 1);
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
}