#include"Do_Hoa.h"
#include<iostream>
#include<string>
#include<fstream>
#include<thread>
#include<mutex>
#include"xu_le_de.h"
#include<vector>
using namespace std;

mutex m;
int dung_intro = 0;
int toa_do_giao_dien_dong = 0;

// ================================ GIAO DIEN ===========================
void giao_dien_menu_chinh();
void xoa_giao_dien_ban_dau();
void giao_dien_tinh();
void giao_dien_dong();
void giao_dien();
void box(int x, int y, int w, int h, int t_color, int b_color, string nd);
void di_chuyen_trong_menu_chinh();

// =============================== MENU CON lỚP TÍN CHỈ =============================
void menu_con_nhap_lop_tin_chi(DS_LOP_TIN_CHI &ds_lop_tin_chi);

void xoa_giao_dien_mo_lop_tin_chi();
void giao_dien_mo_lop_tin_chi(int &cong_tac_dau_nhay, DS_LOP_TIN_CHI &ds_lop_tin_chi);
void giao_dien_xem_lop_tc(int &cong_tac_dau_nhay, DS_LOP_TIN_CHI ds_lop_tin_chi);
void giao_dien_xoa_lop_tc(DS_LOP_TIN_CHI &ds, int &cong_tac_dau_nhay);
void giao_dien_hieu_chinh_lop_tin_chi(DS_LOP_TIN_CHI &ds, int &cong_tac_dau_nhay);

// =============================== MENU CON MÔN HỌC =============================
void menu_con_nhap_mon_hoc(DANH_SACH_MON_HOC &ds_mh);
void giao_dien_them_mon_hoc(int &cong_tac_dau_nhay, DANH_SACH_MON_HOC &ds_mh);
void giao_dien_xem_ds_mon_hoc(DANH_SACH_MON_HOC ds_mh, int &cong_tac_dau_nhay);
void tao_mang_ds_mh(TREE t, MonHoc mang_mh[], int &sl_mh);
void giao_dien_xoa_moc_hoc(DANH_SACH_MON_HOC &ds, int &cong_tac_dau_nhay);
void giao_dien_hieu_chinh_moc_hoc(DANH_SACH_MON_HOC &ds, int &cong_tac_dau_nhay);

// =============================== MENU CON SINH VIÊN =============================
void menu_con_nhap_sinh_vien(Sinh_Vien ds[], int &sl_sv, set<string> &ds_ma_lop);
void giao_dien_them_sinh_vien(int &cong_tac_dau_nhay, Sinh_Vien ds_sv[], int &sl_sv, set<string> &ds_ma_lop);
void giao_dien_xem_sinh_vien(Sinh_Vien ds_sv[], int sl_sv, set<string> &ds_ma_lop, int &cong_tac_dau_nhay);
void giao_dien_xoa_sinh_vien(Sinh_Vien ds_sv[], int &sl_sv, int &cong_tac_dau_nhay);
void giao_dien_hieu_chinh_sinh_vien(Sinh_Vien ds_sv[], int sl_sv, int &cong_tac_dau_nhay);

// =============================== MENU CON ĐĂNG KÝ TÍN CHỈ =============================
void menu_con_dang_ky_tin_chi(Sinh_Vien ds[], int &sl_sv, DS_LOP_TIN_CHI &ds_lop_tc, DANH_SACH_MON_HOC &ds_mh);

void giao_dien_dang_ky_tin_chi_1_lop(int &cong_tac_dau_nhay, Sinh_Vien ds_sv[], int &sl_sv, DS_LOP_TIN_CHI &ds_lop_tc, DANH_SACH_MON_HOC &ds_mh);
void giao_dien_xuat_ds_lop_tc_theo_nk_hk(DS_LOP_TIN_CHI &ds_lop_tc, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh, vector<string> ds_ma_sv);
void xoa_mot_trang_dk_tin_chi();
int kt_lop_tc_sv_dk(DSSV_DANG_KY_TIN_CHI ds, string ma_sv);
void giao_dien_dang_ky_tin_chi_1_sinh_vien(int &cong_tac_dau_nhay, Sinh_Vien ds_sv[], int &sl_sv, DS_LOP_TIN_CHI &ds_lop_tc, DANH_SACH_MON_HOC &ds_mh);
void giao_dien_xuat_ds_lop_tc_theo_nk_hk_phien_ban_1_sv(DS_LOP_TIN_CHI &ds_lop_tc, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh, string ma_sv_dk);

void giao_dien_xem_ds_sv_con_dk_tin_chi_main(DANH_SACH_MON_HOC ds_mh, DS_LOP_TIN_CHI ds_ltc, Sinh_Vien ds_sv[], int sl_sv, int &cong_tac_dau_nhay);
void giao_dien_xem_ds_sv_con_dk_tin_chi_support(DANH_SACH_MON_HOC ds_mh, DS_LOP_TIN_CHI ds_lop_tc, Sinh_Vien ds_sv[], int sl_sv, int nien_khoa, int hoc_ky);
void xuat_ds_sv_trong_1_lop_tc_theo_ma_lop_tc(DS_LOP_TIN_CHI ds_lop_tc, int ma_lop_tc, Sinh_Vien ds[], int sl_sv, DANH_SACH_MON_HOC ds_mh);

void giao_dien_huy_dang_ky_1_lop(DS_LOP_TIN_CHI &ds_lop_tc, Sinh_Vien ds_sv[], int sl_sv, DANH_SACH_MON_HOC ds_mh, int &cong_tac_dau_nhay);
void xuat_ds_ket_qua_dky_hoc_phan_1_lop(int &g, DS_LOP_TIN_CHI ds_lop_tc, int &nien_khoa, int &hoc_ky, int &dem, string ds_ma_ltc[], int &sl_lop_tc_da_xuat, DANH_SACH_MON_HOC ds_mh, string ma_sv);
void huy_dang_ki_tin_chi_1_lop_new(vector<string> ds_ma_sv, DS_LOP_TIN_CHI &ds_ltc, int ma_lop_tc, int sl_sv);
void giao_dien_huy_dky_hoc_phan_1_sv(DS_LOP_TIN_CHI &ds_lop_tc, Sinh_Vien ds_sv[], int sl_sv, DANH_SACH_MON_HOC ds_mh, int &cong_tac_dau_nhay);
void xuat_ds_ket_qua_dky_hoc_phan_1_sv(int &g, DS_LOP_TIN_CHI ds_lop_tc, int &dem, string ds_ma_ltc[], int &sl_lop_tc_da_xuat, DANH_SACH_MON_HOC ds_mh, string ma_sv_input);

// ================================ LỌC LỚP TÍN CHỈ ================================
void loc_ds_lop_hoc_phan_new(DS_LOP_TIN_CHI &ds_lop_tc, DANH_SACH_MON_HOC ds_mh);
void in_ds_lop_bi_huy_new(DS_LOP_TIN_CHI &ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh);
void in_ds_lop_tc_sau_khi_loc_new(DS_LOP_TIN_CHI ds, DANH_SACH_MON_HOC ds_mh);

// ================================ NHẬP ĐIỂM ======================================
void menu_con_nhap_diem_sinh_vien(Sinh_Vien ds[], int sl_sv, DANH_SACH_MON_HOC ds_mh, DS_LOP_TIN_CHI &ds_lop_tc);
void giao_dien_nhap_diem_cho_sinh_vien(int &cong_tac_dau_nhay, Sinh_Vien ds[], int sl_sv, DANH_SACH_MON_HOC ds_mh, DS_LOP_TIN_CHI &ds_lop_tc);
int kt_lop_tc_ton_tai_theo_nk_nhom_hk_mamh(DS_LOP_TIN_CHI ds_ltc, int nk, int hk, int ma_mh, int nhom);
void in_ds_diem_cua_1_lop_tc(DSSV_DANG_KY_TIN_CHI &ds_sv_dk, Sinh_Vien ds_sv[], int sl_sv, int nk, int hk, int nhom, string ten_mh);
int kt_du_lieu_diem_input(string diem);
float to_Float(string diem);
string float_to_string(float a);

void in_ds_diem_cua_1_lop_tc_trong_che_do_xem(DSSV_DANG_KY_TIN_CHI &ds_sv_dk, Sinh_Vien ds_sv[], int sl_sv, int nk, int hk, int nhom, string ten_mh);
void giao_dien_xem_ds_diem_1_lop_tc_giao_dien_xem(int &cong_tac_dau_nhay, Sinh_Vien ds_sv[], int sl_sv, DANH_SACH_MON_HOC ds_mh, DS_LOP_TIN_CHI &ds_lop_tc);

// ======================================================================

void giao_dien_tinh()
{
	// doc file font chu quan li sinh vien
	ifstream Fi;
	Fi.open("font_chu_quan_li_sinh_vien.txt");
	string a;
	m.lock();
	gotoXY(6, 3);
	while (getline(Fi, a))
	{
		SetColor(12);
		cout << a << endl;
	}
	m.unlock();
	// doc file font chu huong dan
	ifstream Fi1;
	Fi1.open("font_chu_huong_dan.txt");
	string s;
	m.lock();
	gotoXY(7, 3);
	while (getline(Fi1, s))
	{
		SetColor(10);
		cout << s << endl;
	}
	// hướng dẫn 
	gotoXY(7, 8);
	cout << "Su dung 4 phim mui ten de di chuyen";
	gotoXY(7, 9);
	cout << "Enter: Chon \t\t Esc: Thoat";
	SetColor(5);
	// vẽ tường trên, dưới
	for (int i = 2; i <= 165; i++)
	{
		gotoXY(i, 2);
		cout << char(220);
		gotoXY(i, 43);
		cout << char(223);
	}
	// vẽ tường trái phải
	for (int i = 3; i <= 42; i++)
	{
		gotoXY(2, i);
		cout << char(219);
		gotoXY(165, i);
		cout << char(219);
	}


	// vẽ hộp phụ  trái bên trong
	for (int i = 0; i < 49; i++)
	{
		gotoXY(3 + i, 12);
		cout << char(219);
	}

	for (int i = 3; i <= 42; i++)
	{
		gotoXY(52, i);
		cout << char(219);
	}
	giao_dien_menu_chinh();
	m.unlock();
	Fi.close();
	Fi1.close();

	
	
}
// di chuyển trong menu chính
void di_chuyen_trong_menu_chinh()
{
	
	// ==================== di chuyển trong menu chính ======================
	set<string> ds_ma_lop;
	DS_LOP_TIN_CHI ds_lop_tin_chi;
	DANH_SACH_MON_HOC ds_mon_hoc;
	DANH_SACH_SINH_VIEN ds_sv;

	// load file
	load_file_ds_sv(ds_sv.ds, ds_sv.sl, ds_ma_lop);
	load_file_mon_hoc(ds_mon_hoc);
	load_file_ds_lop_tin_chi(ds_lop_tin_chi);
	load_file_ds_sv_dk_tin_chi(ds_lop_tin_chi);
	m.lock();
	
	int x_sang = 7;
	int y_sang = 15;
	gotoXY(x_sang, y_sang);
	textcolor(70);
	cout << "                   ";
	gotoXY(x_sang, y_sang);
	SetColor(11);
	cout << "1. Nhap lop tin chi";
	textcolor(0);
	m.unlock();
	int thoat_khoi_menu_con = 0;
	while (77)
	{
		dung_intro = 0;
		thread t(giao_dien_dong);
		char c = _getch();
		if (c == 13)
		{
			dung_intro = 1;
			// Mở ra menu con nhập lớp tín chỉ
			if (x_sang == 7 && y_sang == 15)
			{
				// xóa giao diên ban đầu
				xoa_giao_dien_ban_dau();
				// hiển thị ra menu con nhập lớp tín chỉ
				menu_con_nhap_lop_tin_chi(ds_lop_tin_chi);
				// sau khi kết thúc thao tác nhập tín chỉ
				dung_intro = 0;
				xoa_giao_dien_ban_dau();
				giao_dien_tinh();
				giao_dien_menu_chinh();
				x_sang = 7;
				y_sang = 15;
				gotoXY(x_sang, y_sang);
				textcolor(70);
				cout << "                   ";
				gotoXY(x_sang, y_sang);
				SetColor(11);
				cout << "1. Nhap lop tin chi";
				thoat_khoi_menu_con = 1;
				textcolor(0);
			} 
			// mở ra menu con nhập môn học
			else if (x_sang == 7 && y_sang == 16)
			{
				// xóa giao diên ban đầu
				xoa_giao_dien_ban_dau();
				// hiển thị ra menu con nhập môn học
				menu_con_nhap_mon_hoc(ds_mon_hoc);
				// sau khi kết thúc thao tác nhập tín chỉ
				dung_intro = 0;
				xoa_giao_dien_ban_dau();
				giao_dien_tinh();
				giao_dien_menu_chinh();
				x_sang = 7;
				y_sang = 15;
				gotoXY(x_sang, y_sang);
				textcolor(70);
				cout << "                   ";
				gotoXY(x_sang, y_sang);
				SetColor(11);
				cout << "1. Nhap lop tin chi";
				thoat_khoi_menu_con = 1;
				textcolor(0);
			}
			// nhập sinh viên
			else if (x_sang == 7 && y_sang == 17)
			{
				// xoá giao diện ban đầu
				xoa_giao_dien_ban_dau();
				// hiển thị ra menu con nhập sinh viên
				menu_con_nhap_sinh_vien(ds_sv.ds, ds_sv.sl,ds_ma_lop);
				// sau khi kết thúc thao tác nhập tín chỉ
				dung_intro = 0;
				xoa_giao_dien_ban_dau();
				giao_dien_tinh();
				giao_dien_menu_chinh();
				x_sang = 7;
				y_sang = 15;
				gotoXY(x_sang, y_sang);
				textcolor(70);
				cout << "                   ";
				gotoXY(x_sang, y_sang);
				SetColor(11);
				cout << "1. Nhap lop tin chi";
				thoat_khoi_menu_con = 1;
				textcolor(0);
			}
			else if (x_sang == 7 && y_sang == 18)
			{
				// xoá giao diện ban đầu
				xoa_giao_dien_ban_dau();
				// hiển thị ra menu con đăng kí tín chỉ
				menu_con_dang_ky_tin_chi(ds_sv.ds, ds_sv.sl, ds_lop_tin_chi, ds_mon_hoc);
				// sau khi kết thúc thao tác nhập tín chỉ
				dung_intro = 0;
				xoa_giao_dien_ban_dau();
				giao_dien_tinh();
				giao_dien_menu_chinh();
				x_sang = 7;
				y_sang = 15;
				gotoXY(x_sang, y_sang);
				textcolor(70);
				cout << "                   ";
				gotoXY(x_sang, y_sang);
				SetColor(11);
				cout << "1. Nhap lop tin chi";
				thoat_khoi_menu_con = 1;
				textcolor(0);
			}
			else if (x_sang == 7 && y_sang == 19)
			{
				// xoá giao diện ban đầu
				xoa_giao_dien_ban_dau();
				// hiển thị ra menu con đăng kí tín chỉ
				loc_ds_lop_hoc_phan_new(ds_lop_tin_chi, ds_mon_hoc);
				// sau khi kết thúc thao tác nhập tín chỉ
				dung_intro = 0;
				xoa_giao_dien_ban_dau();
				giao_dien_tinh();
				giao_dien_menu_chinh();
				x_sang = 7;
				y_sang = 15;
				gotoXY(x_sang, y_sang);
				textcolor(70);
				cout << "                   ";
				gotoXY(x_sang, y_sang);
				SetColor(11);
				cout << "1. Nhap lop tin chi";
				thoat_khoi_menu_con = 1;
				textcolor(0);
			}
			else if (x_sang == 7 && y_sang == 20)
			{
				// xoá giao diện ban đầu
				xoa_giao_dien_ban_dau();
				// hiển thị ra menu con đăng kí tín chỉ
				in_ds_lop_tc_sau_khi_loc_new(ds_lop_tin_chi, ds_mon_hoc);
				// sau khi kết thúc thao tác nhập tín chỉ
				dung_intro = 0;
				xoa_giao_dien_ban_dau();
				xoa_giao_dien_mo_lop_tin_chi();
				giao_dien_tinh();
				giao_dien_menu_chinh();
				x_sang = 7;
				y_sang = 15;
				gotoXY(x_sang, y_sang);
				textcolor(70);
				cout << "                   ";
				gotoXY(x_sang, y_sang);
				SetColor(11);
				cout << "1. Nhap lop tin chi";
				thoat_khoi_menu_con = 1;
				textcolor(0);
			}
			else if (x_sang == 7 && y_sang == 21)
			{
				// xoá giao diện ban đầu
				xoa_giao_dien_ban_dau();
				menu_con_nhap_diem_sinh_vien(ds_sv.ds, ds_sv.sl, ds_mon_hoc, ds_lop_tin_chi);
				dung_intro = 0;
				xoa_giao_dien_ban_dau();
				xoa_giao_dien_mo_lop_tin_chi();
				giao_dien_tinh();
				giao_dien_menu_chinh();
				x_sang = 7;
				y_sang = 15;
				gotoXY(x_sang, y_sang);
				textcolor(70);
				cout << "                   ";
				gotoXY(x_sang, y_sang);
				SetColor(11);
				cout << "1. Nhap lop tin chi";
				thoat_khoi_menu_con = 1;
				textcolor(0);
			}
		}
		if (c == -32)
		{
			dung_intro = 1;
			c = _getch();
			if (c == 72) // lên
			{
				
				if (y_sang > 15)
				{
					// tắt thanh sáng cũ
					if (x_sang == 7 && y_sang == 16)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(0);
						cout << "               ";
						SetColor(11);
						gotoXY(x_sang, y_sang);
						cout << "2. Nhap mon hoc";
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 17)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(0);
						cout << "                 ";
						SetColor(11);
						gotoXY(x_sang, y_sang);
						cout << "3. Nhap sinh vien";
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 18)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(0);
						cout << "                  ";
						SetColor(11);
						gotoXY(x_sang, y_sang);
						cout << "4. Dang ky tin chi";
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 19)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(0);
						cout << "                  ";
						SetColor(11);
						gotoXY(x_sang, y_sang);
						cout << "5. Loc lop hoc phan";
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 20)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(0);
						cout << "                                 ";
						SetColor(11);
						gotoXY(x_sang, y_sang);
						cout << "6. Danh sach lop hoc phan duoc mo";
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 21)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(0);
						cout << "            ";
						SetColor(11);
						gotoXY(x_sang, y_sang);
						cout << "7. Nhap diem";
						m.unlock();
					}
					y_sang--;
					// hiện thanh sáng mới
					if (x_sang == 7 && y_sang == 15)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "                   ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "1. Nhap lop tin chi";
						textcolor(0);
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 16)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "               ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "2. Nhap mon hoc";
						textcolor(0);
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 17)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "                 ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "3. Nhap sinh vien";
						textcolor(0);
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 18)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "                  ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "4. Dang ky tin chi";
						textcolor(0);
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 19)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "                   ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "5. Loc lop hoc phan";
						textcolor(0);
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 20)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "                                 ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "6. Danh sach lop hoc phan duoc mo";
						textcolor(0);
						m.unlock();
					}
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang < 21)
				{
					dung_intro = 1;
					int y_cu = y_sang;
					// xóa thanh sang sáng cũ
					if (x_sang == 7 && y_cu == 15)
					{
						m.lock();
						gotoXY(x_sang, y_cu);
						textcolor(0);
						cout << "                   ";
						gotoXY(x_sang, y_cu);
						SetColor(11);
						cout << "1. Nhap lop tin chi";
						m.unlock();
					}
					else if (x_sang == 7 && y_cu == 16)
					{
						m.lock();
						gotoXY(x_sang, y_cu);
						textcolor(0);
						cout << "               ";
						gotoXY(x_sang, y_cu);
						SetColor(11);
						cout << "2. Nhap mon hoc";
						m.unlock();
					}
					else if (x_sang == 7 && y_cu == 17)
					{
						m.lock();
						gotoXY(x_sang, y_cu);
						textcolor(0);
						cout << "                 ";
						gotoXY(x_sang, y_cu);
						SetColor(11);
						cout << "3. Nhap sinh vien";
						m.unlock();
					}
					else if (x_sang == 7 && y_cu == 18)
					{
						m.lock();
						gotoXY(x_sang, y_cu);
						textcolor(0);
						cout << "                  ";
						gotoXY(x_sang, y_cu);
						SetColor(11);
						cout << "4. Dang ky tin chi";
						m.unlock();
					}
					else if (x_sang == 7 && y_cu == 19)
					{
						m.lock();
						gotoXY(x_sang, y_cu);
						textcolor(0);
						cout << "                   ";
						gotoXY(x_sang, y_cu);
						SetColor(11);
						cout << "5. Loc lop hoc phan";
						m.unlock();
					}
					else if (x_sang == 7 && y_cu == 20)
					{
						m.lock();
						gotoXY(x_sang, y_cu);
						textcolor(0);
						cout << "                                 ";
						gotoXY(x_sang, y_cu);
						SetColor(11);
						cout << "6. Danh sach lop hoc phan duoc mo";
						m.unlock();
					}
					y_sang++;
					// hiện thanh sáng mới
					if (x_sang == 7 && y_sang == 16)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "               ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "2. Nhap mon hoc";
						textcolor(0);
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 17)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "                 ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "3. Nhap sinh vien";
						textcolor(0);
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 18)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "                  ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "4. Dang ky tin chi";
						textcolor(0);
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 19)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "                   ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "5. Loc lop hoc phan";
						textcolor(0);
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 20)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "                                 ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "6. Danh sach lop hoc phan duoc mo";
						textcolor(0);
						m.unlock();
					}
					else if (x_sang == 7 && y_sang == 21)
					{
						m.lock();
						gotoXY(x_sang, y_sang);
						textcolor(70);
						cout << "            ";
						gotoXY(x_sang, y_sang);
						SetColor(11);
						cout << "7. Nhap diem";
						textcolor(0);
						m.unlock();
					}
				}
			}
		}
		else
		{
			dung_intro = 1;
		}
		t.join();
		// xóa giao diện động
		
		for (int j = 37; j <= 41; j++)
		{
			for (int i = 50; i <= 164; i++)
			{
				gotoXY(i, j);
				cout << "   ";
			}
		}
		
	}
}

// xóa font chữ quản lí sinh viên
// xóa giao diện động
// xóa menu chính 
// fix tường 2 bên
void xoa_giao_dien_ban_dau()
{
	m.lock();
	textcolor(0);
	// xóa font chữ QLSV
	for (int j = 14; j <= 30; j++)
	{
		for (int i = 53; i < 160; i++)
		{
			gotoXY(i, j);
			cout << " ";
		}
	}

	// xóa giao diện động
	for (int j = 37; j <= 41; j++)
	{
		for (int i = 50; i <= 164; i++)
		{
			gotoXY(i, j);
			cout << "   ";
		}
	}

	// xóa menu chính
	for (int i = 15; i <= 24; i++)
	{
		gotoXY(7, i);
		cout << "                                      ";
	}

	// fix tường
	for (int j = 35; j <= 41; j++)
	{
		SetColor(5);
		gotoXY(165, j);
		cout << char(219);
	}
	for (int i = 35; i <= 41; i++)
	{
		gotoXY(52, i);
		cout << char(219);
	}
	m.unlock();
}

void giao_dien_dong()
{
	
	while (true)
	{
		if (dung_intro == 1)
		{
			break;
		}
		m.lock();
		// xoá toạ độ cũ
		if (toa_do_giao_dien_dong  > 1)
		{
			gotoXY(52 + toa_do_giao_dien_dong - 1, 37); cout << "                                                           ";
			gotoXY(52 + toa_do_giao_dien_dong - 1, 38); cout << "                                                                   ";
			gotoXY(52 + toa_do_giao_dien_dong - 1, 39); cout << "                                                                         ";
			gotoXY(52 + toa_do_giao_dien_dong - 1, 40); cout << "                                                                          ";
			gotoXY(52 + toa_do_giao_dien_dong - 1, 41); cout << "                                                                         ";
		}

		if (toa_do_giao_dien_dong == 108)
		{
			toa_do_giao_dien_dong = 0;
		}
		textcolor(0);
		gotoXY(52 + toa_do_giao_dien_dong, 37);
		SetColor(11);
		cout << " _____ _____ _____ ___ ___    _____                _____ _";

		gotoXY(52 + toa_do_giao_dien_dong, 38);
		cout << "| __  |   __|     |_  | | |  |     |___ ___ ___   |  |  |_|___ ___ " << endl;

		gotoXY(52 + toa_do_giao_dien_dong, 39);
		cout << "| __ -|   __|   --|  _|_  |  |   --| . |   | . |  |  |  | | -_|   |" << endl;

		gotoXY(52 + toa_do_giao_dien_dong, 40);
		cout << "|_____|_____|_____|___| |_|  |_____|___|_|_|_  |   " << char(92) << "___/|_|___|_|_|" << endl;

		gotoXY(52 + toa_do_giao_dien_dong, 41);
		cout << "                                           |___|                   " << endl;

		toa_do_giao_dien_dong++;

		// fix tuong phai
		for (int j = 35; j <= 41; j++)
		{
			SetColor(5);
			gotoXY(165, j);
			cout << char(219);
		}
		for (int i = 35; i <= 41; i++)
		{
			gotoXY(52, i);
			cout << char(219);
		}
		m.unlock();

		Sleep(50);
	}

}
void giao_dien_menu_chinh()
{
	SetColor(11);
	/*gotoXY(7, 15);
	cout << "1. Nhap lop tin chi";*/
	gotoXY(7, 16);
	cout << "2. Nhap mon hoc";
	gotoXY(7, 17);
	cout << "3. Nhap sinh vien";
	gotoXY(7, 18);
	cout << "4. Dang ky tin chi";
	gotoXY(7, 19);
	cout << "5. Loc lop hoc phan";
	gotoXY(7, 20);
	cout << "6. Danh sach lop hoc phan duoc mo";
	gotoXY(7, 21);
	cout << "7. Nhap diem";
}
// ----------------------------------------- XỬ LÍ CHÍNH ------------------------
void giao_dien()
{
	thread t1(giao_dien_tinh);
	
	di_chuyen_trong_menu_chinh();
	t1.join();
	

}



void box(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 1, y + 1);
	cout << nd;
	//============= ve vien =============
	textcolor(1);
	SetColor(t_color);//update
	if (h <= 1 || w <= 1)return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y + h); cout << char(217);

}

// ================================ MENU CON NHẬP LỚP TÍN CHỈ =============================

// -------- menu con nhập lớp tín chỉ
void menu_con_nhap_lop_tin_chi(DS_LOP_TIN_CHI &ds_lop_tin_chi)
{
	SetColor(11);
	gotoXY(7, 15);
	cout << "1. Them lop tin chi";
	gotoXY(7, 16);
	cout << "2. Xem lop tin chi";
	gotoXY(7, 17);
	cout << "3. Xoa lop tin chi";
	gotoXY(7, 18);
	cout << "3. Hieu chinh lop tin chi";
	gotoXY(7, 19);
	cout << "4. Thoat";

	int x_sang = 7;
	int y_sang = 15;
	// ------- hiện thanh sáng
	m.lock();
	gotoXY(x_sang, y_sang);
	textcolor(70);
	cout << "                   ";
	gotoXY(x_sang, y_sang);
	SetColor(11);
	cout << "1. Them lop tin chi";
	textcolor(0);
	m.unlock();
	// -------------- di chuyển của menu con
	int cong_tac_dau_nhay = 0; // CÔNG TẮC KHI NHẤN PHÍM ENTER
	
	while (77)
	{
			
			// ------------------ xử lí lệnh thêm
			if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 15 )
			{
				giao_dien_mo_lop_tin_chi(cong_tac_dau_nhay,ds_lop_tin_chi);
			}
			// ------------------ xử lí lệnh xem lớp tín chỉ
			else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 16 )
			{
				giao_dien_xem_lop_tc(cong_tac_dau_nhay, ds_lop_tin_chi);
			}
			// ------------------- xoá lớp tín chỉ
			else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 17)
			{
				giao_dien_xoa_lop_tc(ds_lop_tin_chi, cong_tac_dau_nhay);
			}
			// hiệu chỉnh lớp tín chỉ
			else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 18)
			{
				giao_dien_hieu_chinh_lop_tin_chi(ds_lop_tin_chi, cong_tac_dau_nhay);			
			}
			// ------------------- thoát
			else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 19)
			{
				
				break;
			}
			// menu nhỏ ======================= LUỒNG  CHÍNH CỦA MENU NHỎ
			char c = _getch();
			// đã nhấn phím enter
			if (c == 13)
			{
				// nhấp số lượng lớp tín chỉ cần thêm
				if (x_sang == 7 && y_sang == 15 && cong_tac_dau_nhay == 0)
				{
					cong_tac_dau_nhay = 1;
				}
				// xem lớp tín chỉ
				else if (x_sang == 7 && y_sang == 16 && cong_tac_dau_nhay == 0)
				{
					cong_tac_dau_nhay = 1;
				}
				else if (x_sang == 7 && y_sang == 17 && cong_tac_dau_nhay == 0)
				{
					cong_tac_dau_nhay = 1;
				}
				else if (x_sang == 7 && y_sang == 18 && cong_tac_dau_nhay == 0)
				{
					cong_tac_dau_nhay = 1;
				}
				else if (x_sang == 7 && y_sang == 19 && cong_tac_dau_nhay == 0)
				{
					cong_tac_dau_nhay = 1;
				}
			}
			if (cong_tac_dau_nhay == 0)
			{
				if (c == -32)
				{
					c = _getch();
					if (c == 72) // đi lên
					{
						if (y_sang > 15)
						{
							int y_cu = y_sang;

							// xóa thanh sang sáng cũ
							if (x_sang == 7 && y_cu == 16)
							{
								m.lock();
								gotoXY(x_sang, y_cu);
								textcolor(0);
								cout << "                  ";
								gotoXY(x_sang, y_cu);
								SetColor(11);
								cout << "2. Xem lop tin chi";
								m.unlock();
							}
							else if (x_sang == 7 && y_cu == 17)
							{
								m.lock();
								gotoXY(x_sang, y_cu);
								textcolor(0);
								cout << "                  ";
								gotoXY(x_sang, y_cu);
								SetColor(11);
								cout << "3. Xoa lop tin chi";
								m.unlock();
							}
							else if (x_sang == 7 && y_cu == 18)
							{
								m.lock();
								gotoXY(x_sang, y_cu);
								textcolor(0);
								cout << "                         ";
								gotoXY(x_sang, y_cu);
								SetColor(11);
								cout << "3. Hieu chinh lop tin chi";
								m.unlock();
							}
							else if (x_sang == 7 && y_cu == 19)
							{
								m.lock();
								gotoXY(x_sang, y_cu);
								textcolor(0);
								cout << "        ";
								gotoXY(x_sang, y_cu);
								SetColor(11);
								cout << "4. Thoat";
								m.unlock();
							}
							y_sang--;
							// hiển thị lại thanh sáng mới
							if (x_sang == 7 && y_sang == 15)
							{
								m.lock();
								gotoXY(x_sang, y_sang);
								textcolor(70);
								cout << "                   ";
								gotoXY(x_sang, y_sang);
								SetColor(11);
								cout << "1. Them lop tin chi";
								textcolor(0);
								m.unlock();
							}
							else if (x_sang == 7 && y_sang == 16)
							{
								m.lock();
								gotoXY(x_sang, y_sang);
								textcolor(70);
								cout << "                  ";
								gotoXY(x_sang, y_sang);
								SetColor(11);
								cout << "2. Xem lop tin chi";
								textcolor(0);
								m.unlock();
							}
							else if (x_sang == 7 && y_sang == 17)
							{
								m.lock();
								gotoXY(x_sang, y_sang);
								textcolor(70);
								cout << "                  ";
								gotoXY(x_sang, y_sang);
								SetColor(11);
								cout << "3. Xoa lop tin chi";
								textcolor(0);
								m.unlock();
							}
							else if (x_sang == 7 && y_sang == 18)
							{
								m.lock();
								gotoXY(x_sang, y_sang);
								textcolor(70);
								cout << "                         ";
								gotoXY(x_sang, y_sang);
								SetColor(11);
								cout << "4. Hieu chinh lop tin chi";
								textcolor(0);
								m.unlock();
							}
						}
					}
					else if (c == 80) // đi xuống
					{
						if (y_sang < 19)
						{
							int y_cu = y_sang;
							// xóa thanh sang sáng cũ
							if (x_sang == 7 && y_cu == 15)
							{
								m.lock();
								gotoXY(x_sang, y_cu);
								textcolor(0);
								cout << "                   ";
								gotoXY(x_sang, y_cu);
								SetColor(11);
								cout << "1. Them lop tin chi";
								m.unlock();
							}
							else if (x_sang == 7 && y_cu == 16)
							{
								m.lock();
								gotoXY(x_sang, y_cu);
								textcolor(0);
								cout << "                  ";
								gotoXY(x_sang, y_cu);
								SetColor(11);
								cout << "2. Xem lop tin chi";
								m.unlock();
							}
							else if (x_sang == 7 && y_cu == 17)
							{
								m.lock();
								gotoXY(x_sang, y_cu);
								textcolor(0);
								cout << "                  ";
								gotoXY(x_sang, y_cu);
								SetColor(11);
								cout << "3. Xoa lop tin chi";
								m.unlock();
							}
							else if (x_sang == 7 && y_cu == 18)
							{
								m.lock();
								gotoXY(x_sang, y_cu);
								textcolor(0);
								cout << "                         ";
								gotoXY(x_sang, y_cu);
								SetColor(11);
								cout << "3. Hieu chinh lop tin chi";
								m.unlock();
							}
							y_sang++;
							// hiện thanh sáng mới
							if (x_sang == 7 && y_sang == 16)
							{
								m.lock();
								gotoXY(x_sang, y_sang);
								textcolor(70);
								cout << "                  ";
								gotoXY(x_sang, y_sang);
								SetColor(11);
								cout << "2. Xem lop tin chi";
								textcolor(0);
								m.unlock();
							}
							else if (x_sang == 7 && y_sang == 17)
							{
								m.lock();
								gotoXY(x_sang, y_sang);
								textcolor(70);
								cout << "                  ";
								gotoXY(x_sang, y_sang);
								SetColor(11);
								cout << "3. Xoa lop tin chi";
								textcolor(0);
								m.unlock();
							}
							else if (x_sang == 7 && y_sang == 18)
							{
								m.lock();
								gotoXY(x_sang, y_sang);
								textcolor(70);
								cout << "                         ";
								gotoXY(x_sang, y_sang);
								SetColor(11);
								cout << "3. Hieu chinh lop tin chi";
								textcolor(0);
								m.unlock();
							}
							else if (x_sang == 7 && y_sang == 19)
							{
								m.lock();
								gotoXY(x_sang, y_sang);
								textcolor(70);
								cout << "        ";
								gotoXY(x_sang, y_sang);
								SetColor(11);
								cout << "4. Thoat";
								textcolor(0);
								m.unlock();
							}
						}
					}
				}
			}
		
	}
}

void giao_dien_mo_lop_tin_chi(int &cong_tac_dau_nhay,DS_LOP_TIN_CHI &ds_lop_tin_chi)
{
	// vẽ khung thêm lớp tín chỉ
	box(58, 5, 101, 36, 11, 11, "");
	gotoXY(95, 4);
	cout << "----- THEM LOP TIN CHI -----";
	// chữ tiêu đề
	gotoXY(75, 8);
	cout << "MA LOP TIN CHI: ";
	gotoXY(75, 12);
	cout << "TRANG THAI LOP: ";
	gotoXY(75, 16);
	cout << "MA MON HOC: ";
	gotoXY(75, 20);
	cout << "HOC KY: ";
	gotoXY(75, 24);
	cout << "NHOM: ";
	gotoXY(75, 28);
	cout << "SO SINH VIEN MIN: ";
	gotoXY(75, 32);
	cout << "SO SINH VIEN MAX: ";
	gotoXY(75, 36);
	cout << "NIEN KHOA: ";
	// box thêm
	box(75, 38, 5, 2, 11, 20, "THEM");
	// box huỷ
	box(124, 38, 4, 2, 11, 70, "HUY");
	// ô nhập dữ liệu
	box(111, 7, 30, 2, 11, 0, "");
	box(111, 11, 30, 2, 11, 0, "");
	box(111, 15, 30, 2, 14, 0, "");// ô sáng đầu tiên
	box(111, 19, 30, 2, 11, 0, "");
	box(111, 23, 30, 2, 11, 0, "");
	box(111, 27, 30, 2, 11, 0, "");
	box(111, 31, 30, 2, 11, 0, "");
	box(111, 35, 30, 2, 11, 0, "");

	int x_sang_mo_lop = 111;
	int y_sang_mo_lop = 15;
	int vt_nhap = 0;
	string tt_1_lop_tc[6];
	ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl] = new LOP_TIN_CHI;
	// tạo ra mã lớp tín chỉ
	ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->maLopTinCHi = tao_ma_tc(ds_lop_tin_chi);
	// tạo trạng thái lớp tín chỉ
	ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->trang_thai_lop = 1;
	string ma_lop_tc = to_string(ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->maLopTinCHi);
	box(111, 7, 30, 2, 11, 0, ma_lop_tc);
	if (ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->trang_thai_lop == 1)
	{
		box(111, 11, 30, 2, 11, 0, "Lop Duoc Mo");
	}
	bool kt_mo_lop_tin_chi = false; // điều kiện để thoát khỏi quá trình nhập
	while (kt_mo_lop_tin_chi == false)
	{

		char c_con = _getch();
		if (c_con >= 48 && c_con <= 57)
		{

			if (vt_nhap == 0 && y_sang_mo_lop != 38)
			{
				tt_1_lop_tc[vt_nhap].push_back(c_con);
				box(111, 15, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);

			}
			else if (vt_nhap == 1 && y_sang_mo_lop != 38)
			{
				tt_1_lop_tc[vt_nhap].push_back(c_con);
				box(111, 19, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
			else if (vt_nhap == 2 && y_sang_mo_lop != 38)
			{
				tt_1_lop_tc[vt_nhap].push_back(c_con);
				box(111, 23, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
			else if (vt_nhap == 3 && y_sang_mo_lop != 38)
			{
				tt_1_lop_tc[vt_nhap].push_back(c_con);
				box(111, 27, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
			else if (vt_nhap == 4 && y_sang_mo_lop != 38)
			{
				tt_1_lop_tc[vt_nhap].push_back(c_con);
				box(111, 31, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
			else if (vt_nhap == 5 && y_sang_mo_lop != 38)
			{
				tt_1_lop_tc[vt_nhap].push_back(c_con);
				box(111, 35, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
		}
		else if (c_con == 13) // enter
		{

			if (x_sang_mo_lop == 75 && y_sang_mo_lop == 38) // thêm vào danh sách lớp tín chỉ
			{
				int _kt = 0;
				// kiểm tra xe dữ liệu nhập vào có rỗng không
				for (int i = 0; i <= 5; i++)
				{
					if (tt_1_lop_tc[i].empty())
					{
						_kt = 1;
						// tô đỏ những ô chưa nhập dữ liệu
						if (i == 0)
						{
							box(111, 15, 30, 2, 12, 0, "");// ô sáng đầu tiên	
						}
						else if (i == 1)
						{
							box(111, 19, 30, 2, 12, 0, "");
						}
						else if (i == 2)
						{
							box(111, 23, 30, 2, 12, 0, "");
						}
						else if (i == 3)
						{
							box(111, 27, 30, 2, 12, 0, "");
						}
						else if (i == 4)
						{
							box(111, 31, 30, 2, 12, 0, "");
						}
						else if (i == 5)
						{
							box(111, 35, 30, 2, 12, 0, "");
						}
					}
				}
				if (_kt == 1)
				{
					gotoXY(85, 39);
					SetColor(12);
					cout << "Khong duoc de trong du lieu!";
				}
				else if (_kt == 0)
				{
					while (true)
					{
						SetColor(10);
						gotoXY(85, 39);
						cout << "Nhan enter de tiep tuc";
						gotoXY(85, 40);
						cout << "Nhan esc de huy thao tac";
						char c_con_con = _getch();
						if (c_con_con == 13) // tiếp tục
						{
							for (int g = 0; g <= 5; g++)
							{
								if (g == 0)
								{
									ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->ma_mh = atoi(tt_1_lop_tc[g].c_str());
								}
								else if (g == 1)
								{
									ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->hoc_ky = atoi(tt_1_lop_tc[g].c_str());
								}
								else if (g == 2)
								{
									ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->nhom = atoi(tt_1_lop_tc[g].c_str());
								}
								else if (g == 3)
								{
									ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->so_sv_min = atoi(tt_1_lop_tc[g].c_str());
								}
								else if (g == 4)
								{
									ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->so_sv_max = atoi(tt_1_lop_tc[g].c_str());
								}
								else if (g == 5)
								{
									ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->nien_khoa = atoi(tt_1_lop_tc[g].c_str());
								}
							}
							ds_lop_tin_chi.sl++;

							xoa_giao_dien_mo_lop_tin_chi();
							cong_tac_dau_nhay = 0;
							kt_mo_lop_tin_chi = true;
							break;
						}
						else if (c_con_con == 27) // huỷ thao tác
						{
							break;
						}
					}
				}
			}
			else if (x_sang_mo_lop == 124 && y_sang_mo_lop == 38)
			{

				while (true)
				{
					SetColor(10);
					gotoXY(85, 39);
					cout << "Nhan enter de tiep tuc";
					gotoXY(85, 40);
					cout << "Nhan esc de huy thao tac";
					char c_con_con = _getch();
					if (c_con_con == 27)
					{
						break;
					}
					else if (c_con_con == 13)
					{
						/*int vt_lop_tin_chi_xoa = kt_lop_tc(ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->maLopTinCHi, ds_lop_tin_chi);
						ds_lop_tin_chi.sl++;
						xoa_lop_tc(ds_lop_tin_chi, vt_lop_tin_chi_xoa);*/
						xoa_giao_dien_mo_lop_tin_chi();

						cong_tac_dau_nhay = 0;
						kt_mo_lop_tin_chi = true;
						break;
					}
				}

			}
		}
		else if (c_con == 8) // backspace
		{

			if (vt_nhap == 0 && y_sang_mo_lop != 38 && !tt_1_lop_tc[vt_nhap].empty())
			{
				tt_1_lop_tc[vt_nhap].pop_back();
				box(111, 15, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);

			}
			else if (vt_nhap == 1 && y_sang_mo_lop != 38 && !tt_1_lop_tc[vt_nhap].empty())
			{
				tt_1_lop_tc[vt_nhap].pop_back();
				box(111, 19, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
			else if (vt_nhap == 2 && y_sang_mo_lop != 38 && !tt_1_lop_tc[vt_nhap].empty())
			{
				tt_1_lop_tc[vt_nhap].pop_back();
				box(111, 23, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
			else if (vt_nhap == 3 && y_sang_mo_lop != 38 && !tt_1_lop_tc[vt_nhap].empty())
			{
				tt_1_lop_tc[vt_nhap].pop_back();
				box(111, 27, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
			else if (vt_nhap == 4 && y_sang_mo_lop != 38 && !tt_1_lop_tc[vt_nhap].empty())
			{
				tt_1_lop_tc[vt_nhap].pop_back();
				box(111, 31, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
			else if (vt_nhap == 5 && y_sang_mo_lop != 38 && !tt_1_lop_tc[vt_nhap].empty())
			{
				tt_1_lop_tc[vt_nhap].pop_back();
				box(111, 35, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
		}
		else if (c_con == 72) // đi lên
		{

			// xoá thông báo khi nhấn enter
			gotoXY(85, 39);
			cout << "                            ";
			gotoXY(85, 40);
			cout << "                            ";
			if (y_sang_mo_lop == 38)
			{
				// tắt thanh sáng ô sáng cũ
				int y_sang_cu = y_sang_mo_lop;
				box(75, y_sang_cu, 5, 2, 11, 20, "THEM");
				box(124, 38, 4, 2, 11, 70, "HUY");


				x_sang_mo_lop == 111;
				y_sang_mo_lop -= 3;

				// bật thanh sáng ô sáng mới
				box(111, y_sang_mo_lop, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
			else if (y_sang_mo_lop > 15 && y_sang_mo_lop <= 35)
			{
				// tắt thanh sáng ô sáng cũ
				int y_sang_cu = y_sang_mo_lop;
				box(111, y_sang_cu, 30, 2, 11, 0, tt_1_lop_tc[vt_nhap]);

				vt_nhap--;
				y_sang_mo_lop -= 4;
				// bật thanh sáng ô sáng mới
				box(111, y_sang_mo_lop, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
		}
		else if (c_con == 80) // đi xuống
		{

			if (y_sang_mo_lop < 35)
			{
				// tắt thanh sáng ô sáng cũ
				int y_sang_cu = y_sang_mo_lop;
				box(111, y_sang_cu, 30, 2, 11, 0, tt_1_lop_tc[vt_nhap]);

				y_sang_mo_lop += 4;
				vt_nhap++;
				// bật thanh sáng ô sáng mới
				box(111, y_sang_mo_lop, 30, 2, 14, 0, tt_1_lop_tc[vt_nhap]);
			}
			else if (y_sang_mo_lop == 35)
			{
				// tắt thanh sáng ô sáng cũ
				int y_sang_cu = y_sang_mo_lop;
				box(111, y_sang_cu, 30, 2, 11, 0, tt_1_lop_tc[vt_nhap]);

				y_sang_mo_lop += 3;

				// bật thanh sáng ô sáng mới
				x_sang_mo_lop = 75;
				box(x_sang_mo_lop, y_sang_mo_lop, 5, 2, 14, 20, "THEM");
			}
		}
		else if (c_con == 75) // sang trái
		{

			if (y_sang_mo_lop == 38 && x_sang_mo_lop == 124)
			{
				// tắt thanh sáng ô sáng cũ
				box(x_sang_mo_lop, 38, 4, 2, 11, 70, "HUY");

				x_sang_mo_lop -= 49;

				// bật thanh sáng ô sáng mới
				box(x_sang_mo_lop, y_sang_mo_lop, 5, 2, 14, 20, "THEM");
			}
		}
		else if (c_con == 77) // sang phải
		{

			if (y_sang_mo_lop == 38 && x_sang_mo_lop == 75)
			{
				// tắt thanh sáng ô sáng cũ
				box(x_sang_mo_lop, y_sang_mo_lop, 5, 2, 11, 20, "THEM");

				x_sang_mo_lop += 49;

				// bật thanh sáng ô sáng mới
				box(x_sang_mo_lop, 38, 4, 2, 14, 70, "HUY");
			}
		}
	}
}

void xoa_giao_dien_mo_lop_tin_chi()
{
	for (int y = 4; y <= 42; y++)
	{
		for (int x = 55; x <= 159; x++)
		{
			gotoXY(x, y);
			cout << " ";
		}
	}
}

void giao_dien_xem_lop_tc(int &cong_tac_dau_nhay,DS_LOP_TIN_CHI ds_lop_tin_chi)
{
	gotoXY(94, 5);
	textcolor(100);
	cout << "                       ";
	gotoXY(95, 5);
	SetColor(16);
	cout << "DANH SACH LOP TIN CHI";
	box(56, 7, 96,3  + ds_lop_tin_chi.sl * 2 , 11, 0, "");
	// xuất tiêu đề
	gotoXY(58, 8);
	SetColor(14); cout << setw(3) << "MA LOP TC";
	textcolor(0);
	SetColor(11); cout << "  " << char(222) << "  ";
	SetColor(14); cout << setw(3) << "MA MON HOC";
	SetColor(11); cout << "  " << char(222) << "  ";
	SetColor(14); cout << setw(4) << "NIEN KHOA";
	SetColor(11); cout << "  " << char(222) << "  ";
	SetColor(14); cout << setw(2) << "HOC KY";
	SetColor(11); cout << "  " << char(222) << "  ";
	SetColor(14); cout << setw(3) << "NHOM";
	SetColor(11); cout << "  " << char(222) << "  ";
	SetColor(14); cout << setw(2) << "MIN";
	SetColor(11); cout << "  " << char(222) << "  ";
	SetColor(14); cout << setw(3) << "MAX";
	SetColor(11); cout << "  " << char(222) << "  ";
	SetColor(14); cout << setw(14) << "TRANG THAI LOP" << endl;
	gotoXY(58, 9);
	SetColor(11);
	for (int j = 0; j < 93; j++)
	{
		gotoXY(58 + j, 9);
		cout << char(220);
	}

	// xuất thông tin
	while (!_kbhit())
	{
		int kc_dong = 0;
		for (int i = 0; i < ds_lop_tin_chi.sl; i++)
		{
			gotoXY(58, 10 + i + kc_dong);
			SetColor(15); cout << "      " << setw(3) << ds_lop_tin_chi.Lop_Tin_Chi[i]->maLopTinCHi;
			SetColor(11); cout << "  " << char(222) << "  ";
			SetColor(15); cout << "       " << setw(3) << ds_lop_tin_chi.Lop_Tin_Chi[i]->ma_mh;
			SetColor(11); cout << "  " << char(222) << "  ";
			SetColor(15); cout << "      " << setw(3) << ds_lop_tin_chi.Lop_Tin_Chi[i]->nien_khoa;
			SetColor(11); cout << " " << char(222) << "  ";
			SetColor(15); cout << "    " << setw(2) << ds_lop_tin_chi.Lop_Tin_Chi[i]->hoc_ky;
			SetColor(11); cout << "  " << char(222) << "  ";
			SetColor(15); cout << " " << setw(3) << ds_lop_tin_chi.Lop_Tin_Chi[i]->nhom;
			SetColor(11); cout << "  " << char(222) << "  ";
			SetColor(15); cout << " " << setw(2) << ds_lop_tin_chi.Lop_Tin_Chi[i]->so_sv_min;
			SetColor(11); cout << "  " << char(222) << "  ";
			SetColor(15); cout << setw(3) << ds_lop_tin_chi.Lop_Tin_Chi[i]->so_sv_max;
			SetColor(11); cout << "  " << char(222) << "  ";
			SetColor(15); cout << setw(14) << "Lop duoc mo";
			kc_dong++;
			SetColor(11);
			// vẽ đường kẻ
			if (i < ds_lop_tin_chi.sl - 1)
			{
				for (int j = 0; j < 93; j++)
				{
					gotoXY(58 + j, 10 + i + kc_dong);
					cout << char(220);
				}
			}	
		}
	}
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

void giao_dien_xoa_lop_tc(DS_LOP_TIN_CHI &ds,int &cong_tac_dau_nhay)
{
	gotoXY(80, 21);
	SetColor(11);
	cout << "NHAP MA LOP TIN CHI CAN XOA:";
	box(120, 20, 15, 2, 14, 0, "");
	cong_tac_dau_nhay = 0;
	string ma_tin_chi_muon_xoa;
	bool exit_ =  true;
	while (exit_)
	{
		char c = _getch();
		if (c >= 48 && c <= 57)
		{
			gotoXY(85, 22);
			cout << "                             ";
			ma_tin_chi_muon_xoa.push_back(c);
		}
		else if (c == 27) // esc
		{
			exit_ = false;
		}
		else if (c == 8) // backspace
		{
			if (!ma_tin_chi_muon_xoa.empty())
			{
				gotoXY(85, 22);
				cout << "                             ";
				box(120, 20, 15, 2, 14, 0, "");
				ma_tin_chi_muon_xoa.pop_back();
			}
		}
		else if (c == 13) // enter
		{
			int check_ = kt_lop_tc(atoi(ma_tin_chi_muon_xoa.c_str()), ds);
			// mã tín chỉ không tồn tại
			if (check_ == -1)
			{
				SetColor(12);
				gotoXY(85, 22);
				cout << "Ma lop tin chi khong ton tai!";
				
			}
			else
			{
				box(120, 20, 15, 2, 11, 0, ma_tin_chi_muon_xoa);
				// tắt ô sáng cũ
				int x_sang_con = 75;
				// ô sáng đầu tiên
				box(75, 30, 3, 2, 14, 70, "OK");
				// box huỷ
				box(124, 30, 7, 2, 11, 0, "CANCEL");
				while (true)
				{
					char c_con = _getch();
					if (c_con == -32)
					{
						char c_con_con = _getch();
						if (c_con_con == 75) // samg trái
						{
							if (x_sang_con > 75)
							{
								// tắt thanh sáng cũ
								box(124, 30, 7, 2, 11, 0, "CANCEL");
								x_sang_con -= 49;
								// bật thanh sáng mới
								box(75, 30, 3, 2, 14, 70, "OK");
							}
						}
						else if (c_con_con == 77) // sang phải
						{
							if (x_sang_con < 124)
							{
								// tắt thanh sáng cũ
								box(75, 30, 3, 2, 11, 70, "OK");
								x_sang_con += 49;
								// bật thanh sáng mới
								box(124, 30, 7, 2, 14, 0, "CANCEL");
							}
						}
					}
					else if (c_con == 13) // enter
					{
						if (x_sang_con == 124) // huỷ lênh xoá
						{
							exit_ = false;
							break;
						}
						else if (x_sang_con == 75) // thực hiện lệnh xoá
						{
							xoa_lop_tc(ds, check_);
							exit_ = false;
							break;
						}
					}
				}
			}
		}
		box(120, 20, 15, 2, 14, 0, ma_tin_chi_muon_xoa);
	}
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

void giao_dien_hieu_chinh_lop_tin_chi(DS_LOP_TIN_CHI &ds,int &cong_tac_dau_nhay)
{
	gotoXY(80, 21);
	SetColor(11);
	cout << "NHAP MA LOP TIN CHI MUON CAP NHAT:";
	box(120, 20, 15, 2, 14, 0, "");
	cong_tac_dau_nhay = 0;
	string ma_tin_chi_muon_cap_nhat;
	bool thoat = true;
	while (thoat)
	{
		char c = _getch();
		if (c >= 48 && c <= 57)
		{
			gotoXY(85, 22);
			cout << "                             ";
			ma_tin_chi_muon_cap_nhat.push_back(c);
		}
		else if (c == 27) // esc
		{
			break;
		}
		else if (c == 8) // backspace
		{
			if (!ma_tin_chi_muon_cap_nhat.empty())
			{
				gotoXY(85, 22);
				cout << "                             ";
				box(120, 20, 15, 2, 14, 0, "");
				ma_tin_chi_muon_cap_nhat.pop_back();
			}
		}
		else if (c == 13) // enter
		{
			int check_ = kt_lop_tc(atoi(ma_tin_chi_muon_cap_nhat.c_str()), ds);
			// mã tín chỉ không tồn tại
			if (check_ == -1)
			{
				SetColor(12);
				gotoXY(85, 22);
				cout << "Ma lop tin chi khong ton tai!";
			}
			else
			{
				// xoá dữ liêu cũ
				box(120, 20, 15, 2, 16, 0, "");
				// ============== cho xem thông tin cũ của lớp tín chỉ ===================
				gotoXY(94, 5);
				textcolor(100);
				cout << "                       ";
				gotoXY(95, 5);
				SetColor(16);
				cout << "THONG TIN LOP TIN CHI";
				box(56, 7, 96, 4, 11, 0, "");
				// xuất tiêu đề
				gotoXY(58, 8);
				SetColor(14); cout << setw(3) << "MA LOP TC";
				textcolor(0);
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(14); cout << setw(3) << "MA MON HOC";
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(14); cout << setw(4) << "NIEN KHOA";
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(14); cout << setw(2) << "HOC KY";
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(14); cout << setw(3) << "NHOM";
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(14); cout << setw(2) << "MIN";
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(14); cout << setw(3) << "MAX";
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(14); cout << setw(14) << "TRANG THAI LOP" << endl;
				gotoXY(58, 9);
				SetColor(11);
				for (int j = 0; j < 93; j++)
				{
					gotoXY(58 + j, 9);
					cout << char(220);
				}
				gotoXY(58, 10);
				SetColor(15); cout << "      " << setw(3) << ds.Lop_Tin_Chi[check_]->maLopTinCHi;
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(15); cout << "       " << setw(3) << ds.Lop_Tin_Chi[check_]->ma_mh;
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(15); cout << "      " << setw(3) << ds.Lop_Tin_Chi[check_]->nien_khoa;
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(15); cout << "    " << setw(2) << ds.Lop_Tin_Chi[check_]->hoc_ky;
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(15); cout << " " << setw(3) << ds.Lop_Tin_Chi[check_]->nhom;
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(15); cout << " " << setw(2) << ds.Lop_Tin_Chi[check_]->so_sv_min;
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(15); cout << setw(3) << ds.Lop_Tin_Chi[check_]->so_sv_max;
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(15); cout << setw(14) << "Lop duoc mo";
				SetColor(11);

				// ==============  hiệu chỉnh thông tin của lớp tín chỉ ===================
				box(56, 14, 96, 28, 11, 11, "");
				gotoXY(75, 16);
				cout << "MA MON HOC: ";
				gotoXY(75, 20);
				cout << "HOC KY: ";
				gotoXY(75, 24);
				cout << "NHOM: ";
				gotoXY(75, 28);
				cout << "SO SINH VIEN MIN: ";
				gotoXY(75, 32);
				cout << "SO SINH VIEN MAX: ";
				gotoXY(75, 36);
				cout << "NIEN KHOA: ";
				// box thêm
				box(75, 38, 3, 2, 11, 42, "OK");
				// box huỷ
				box(124, 38, 7, 2, 11, 64, "CANCLE");
				// ô nhập dữ liệu
				box(111, 15, 30, 2, 14, 0, "");// ô sáng đầu tiên
				box(111, 19, 30, 2, 11, 0, "");
				box(111, 23, 30, 2, 11, 0, "");
				box(111, 27, 30, 2, 11, 0, "");
				box(111, 31, 30, 2, 11, 0, "");
				box(111, 35, 30, 2, 11, 0, "");

				int x_sang = 111;
				int y_sang = 15;
				string tt_hieu_chinh[7];
				while (66)
				{
					char c_con = _getch();
					if (c_con == 13)
					{
						if (y_sang == 39 && x_sang == 111)
						{
							for (int g = 0; g <= 5; g++)
							{
								if (g == 0 && !tt_hieu_chinh[0].empty())
								{
									ds.Lop_Tin_Chi[check_]->ma_mh = atoi(tt_hieu_chinh[0].c_str());
								}
								else if (g == 1 && !tt_hieu_chinh[1].empty())
								{
									ds.Lop_Tin_Chi[check_]->hoc_ky = atoi(tt_hieu_chinh[1].c_str());
								}
								else if (g == 2 && !tt_hieu_chinh[2].empty())
								{
									ds.Lop_Tin_Chi[check_]->nhom = atoi(tt_hieu_chinh[2].c_str());
								}
								else if (g == 3 && !tt_hieu_chinh[3].empty())
								{
									ds.Lop_Tin_Chi[check_]->so_sv_min = atoi(tt_hieu_chinh[3].c_str());
								}
								else if (g == 4 && !tt_hieu_chinh[4].empty())
								{
									ds.Lop_Tin_Chi[check_]->so_sv_max = atoi(tt_hieu_chinh[4].c_str());
								}
								else if (g == 5 && !tt_hieu_chinh[5].empty())
								{
									ds.Lop_Tin_Chi[check_]->nien_khoa = atoi(tt_hieu_chinh[5].c_str());
								}
							}
							thoat = false;
							break;
						}
						else if (y_sang == 39 && x_sang == 115)
						{
							thoat = false;
							break;
						}
					}
					if (c_con == 8) // backspace
					{
						if (y_sang == 15 && !tt_hieu_chinh[0].empty())
						{
							tt_hieu_chinh[0].pop_back();
							box(111, 15, 30, 2, 14, 0, tt_hieu_chinh[0]);
						}
						else if (y_sang == 19 && !tt_hieu_chinh[1].empty())
						{
							tt_hieu_chinh[1].pop_back();
							box(111, 19, 30, 2, 14, 0, tt_hieu_chinh[1]);
						}
						else if (y_sang == 23 && !tt_hieu_chinh[2].empty())
						{
							tt_hieu_chinh[2].pop_back();
							box(111, 23, 30, 2, 14, 0, tt_hieu_chinh[2]);
						}
						else if (y_sang == 27 && !tt_hieu_chinh[3].empty())
						{
							tt_hieu_chinh[3].pop_back();
							box(111, 27, 30, 2, 14, 0, tt_hieu_chinh[3]);
						}
						else if (y_sang == 31 && !tt_hieu_chinh[4].empty())
						{
							tt_hieu_chinh[4].pop_back();
							box(111, 31, 30, 2, 14, 0, tt_hieu_chinh[4]);
						}
						else if (y_sang == 35 && !tt_hieu_chinh[5].empty())
						{
							tt_hieu_chinh[5].pop_back();
							box(111, 35, 30, 2, 14, 0, tt_hieu_chinh[5]);
						}
					}
					else if (c_con >= 48 && c_con <= 57)
					{
						if (y_sang == 15)
						{
							tt_hieu_chinh[0].push_back(c_con);
							box(111, 15, 30, 2, 14, 0, tt_hieu_chinh[0]);
						}
						else if (y_sang == 19)
						{
							tt_hieu_chinh[1].push_back(c_con);
							box(111, 19, 30, 2, 14, 0, tt_hieu_chinh[1]);
						}
						else if (y_sang == 23)
						{
							tt_hieu_chinh[2].push_back(c_con);
							box(111, 23, 30, 2, 14, 0, tt_hieu_chinh[2]);
						}
						else if (y_sang == 27)
						{
							tt_hieu_chinh[3].push_back(c_con);
							box(111, 27, 30, 2, 14, 0, tt_hieu_chinh[3]);
						}
						else if (y_sang == 31)
						{
							tt_hieu_chinh[4].push_back(c_con);
							box(111, 31, 30, 2, 14, 0, tt_hieu_chinh[4]);
						}
						else if (y_sang == 35)
						{
							tt_hieu_chinh[5].push_back(c_con);
							box(111, 35, 30, 2, 14, 0, tt_hieu_chinh[5]);
						}
					}
					else if (c_con == 72) // lên
					{
						if (y_sang > 15)
						{
							// tắt thanh sáng cũ
							if (y_sang == 39)
							{
								x_sang = 111;
								// box thêm
								box(75, 38, 3, 2, 11, 42, "OK");
								// box huỷ
								box(124, 38, 7, 2, 11, 64, "CANCLE");
							}
							else if (y_sang == 35)
							{
								box(111, 35, 30, 2, 11, 0, tt_hieu_chinh[5]);
							}
							else if (y_sang == 31)
							{
								box(111, 31, 30, 2, 11, 0, tt_hieu_chinh[4]);
							}
							else if (y_sang == 27)
							{
								box(111, 27, 30, 2, 11, 0, tt_hieu_chinh[3]);
							}
							else if (y_sang == 23)
							{
								box(111, 23, 30, 2, 11, 0, tt_hieu_chinh[2]);
							}
							else if (y_sang == 19)
							{
								box(111, 19, 30, 2, 11, 0, tt_hieu_chinh[1]);
							}

							y_sang -= 4;
							// bật thanh sáng mới
							if (y_sang == 35)
							{
								box(111, 35, 30, 2, 14, 0, tt_hieu_chinh[5]);
							}
							else if (y_sang == 31)
							{
								box(111, 31, 30, 2, 14, 0, tt_hieu_chinh[4]);
							}
							else if (y_sang == 27)
							{
								box(111, 27, 30, 2, 14, 0, tt_hieu_chinh[3]);
							}
							else if (y_sang == 23)
							{
								box(111, 23, 30, 2, 14, 0, tt_hieu_chinh[2]);
							}
							else if (y_sang == 19)
							{
								box(111, 19, 30, 2, 14, 0, tt_hieu_chinh[1]);
							}
							else if (y_sang == 15)
							{
								box(111, 15, 30, 2, 14, 0, tt_hieu_chinh[0]);
							}
						}
					}
					else if (c_con == 80) // xuống
					{
						if (y_sang < 39)
						{
							// tắt thanh sáng cũ
							if (y_sang == 35)
							{
								box(111, 35, 30, 2, 11, 0, tt_hieu_chinh[5]);
							}
							else if (y_sang == 31)
							{
								box(111, 31, 30, 2, 11, 0, tt_hieu_chinh[4]);
							}
							else if (y_sang == 27)
							{
								box(111, 27, 30, 2, 11, 0, tt_hieu_chinh[3]);
							}
							else if (y_sang == 23)
							{
								box(111, 23, 30, 2, 11, 0, tt_hieu_chinh[2]);
							}
							else if (y_sang == 19)
							{
								box(111, 19, 30, 2, 11, 0, tt_hieu_chinh[1]);
							}
							else if (y_sang == 15)
							{
								box(111, 15, 30, 2, 11, 0, tt_hieu_chinh[0]);
							}

							y_sang += 4;

							// bật thanh sáng mới
							if (y_sang == 39)
							{
								box(75, 38, 3, 2, 14, 42, "OK");
							}
							else if (y_sang == 35)
							{
								box(111, 35, 30, 2, 14, 0, tt_hieu_chinh[5]);
							}
							else if (y_sang == 31)
							{
								box(111, 31, 30, 2, 14, 0, tt_hieu_chinh[4]);
							}
							else if (y_sang == 27)
							{
								box(111, 27, 30, 2, 14, 0, tt_hieu_chinh[3]);
							}
							else if (y_sang == 23)
							{
								box(111, 23, 30, 2, 14, 0, tt_hieu_chinh[2]);
							}
							else if (y_sang == 19)
							{
								box(111, 19, 30, 2, 14, 0, tt_hieu_chinh[1]);
							}
						}
					}
					else if (c_con == 77) // sang phải
					{
						if (x_sang < 115 )
						{
							// xoá thanh sáng cũ
							box(75, 38, 3, 2, 11, 42, "OK");
							
							x_sang += 4;

							// bật thanh sáng mới
							box(124, 38, 7, 2, 14, 64, "CANCLE");
						}
					}
					else if (c_con == 75) // sang trái
					{
						if (x_sang > 111 )
						{
							// xoá thanh sáng cũ
							box(124, 38, 7, 2, 11, 64, "CANCLE");

							x_sang -= 4;

							// bật thanh sáng mới
							box(75, 38, 3, 2, 14, 42, "OK");
						}
					}
				}
			}
		}
		box(120, 20, 15, 2, 14, 0, ma_tin_chi_muon_cap_nhat);
	}
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

// ================================ MENU CON DANH SÁCH MÔN HỌC ================================
void menu_con_nhap_mon_hoc(DANH_SACH_MON_HOC &ds_mh)
{
	SetColor(11);
	gotoXY(7, 15);
	cout << "1. Them mon hoc";
	gotoXY(7, 16);
	cout << "2. Xem danh sach mon hoc";
	gotoXY(7, 17);
	cout << "3. Xoa mon hoc";
	gotoXY(7, 18);
	cout << "3. Hieu chinh moc hoc";
	gotoXY(7, 19);
	cout << "4. Thoat";

	int x_sang = 7;
	int y_sang = 15;
	// ------- hiện thanh sáng
	m.lock();
	gotoXY(x_sang, y_sang);
	textcolor(70);
	cout << "               ";
	gotoXY(x_sang, y_sang);
	SetColor(11);
	cout << "1. Them moc hoc";
	textcolor(0);
	m.unlock();
	// -------------- di chuyển của menu con
	int cong_tac_dau_nhay = 0; // CÔNG TẮC KHI NHẤN PHÍM ENTER

	while (77)
	{

		// ------------------ xử lí lệnh thêm môn học
		if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 15)
		{
			giao_dien_them_mon_hoc(cong_tac_dau_nhay, ds_mh);
		}
		// ------------------ xử lí lệnh xem danh sách môn học
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 16)
		{
			giao_dien_xem_ds_mon_hoc(ds_mh, cong_tac_dau_nhay);
		}
		// ------------------- xoá môn học
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 17)
		{
			giao_dien_xoa_moc_hoc(ds_mh, cong_tac_dau_nhay);
		}
		// hiệu chỉnh môn học
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 18)
		{
			giao_dien_hieu_chinh_moc_hoc(ds_mh, cong_tac_dau_nhay);
		}
		// ------------------- thoát
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 19)
		{
			break;
		}
		// menu nhỏ ======================= LUỒNG  CHÍNH CỦA MENU NHỎ
		char c = _getch();
		// đã nhấn phím enter
		if (c == 13)
		{
			// nhấp số lượng lớp tín chỉ cần thêm
			if (x_sang == 7 && y_sang == 15 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			// xem lớp tín chỉ
			else if (x_sang == 7 && y_sang == 16 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 17 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 18 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 19 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
		}
		if (cong_tac_dau_nhay == 0)
		{
			if (c == -32)
			{
				c = _getch();
				if (c == 72) // đi lên
				{
					if (y_sang > 15)
					{
						int y_cu = y_sang;

						// xóa thanh sang sáng cũ
						if (x_sang == 7 && y_cu == 16)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                        ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "2. Xem danh sach mon hoc";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 17)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "              ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "3. Xoa mon hoc";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 18)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                     ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "3. Hieu chinh mon hoc";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 19)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "        ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "4. Thoat";
							m.unlock();
						}
						y_sang--;
						// hiển thị lại thanh sáng mới
						if (x_sang == 7 && y_sang == 15)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "               ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "1. Them mon hoc";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 16)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                        ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "2. Xem danh sach mon hoc";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 17)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "              ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "3. Xoa mon hoc";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 18)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                     ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "4. Hieu chinh moc hoc";
							textcolor(0);
							m.unlock();
						}
					}
				}
				else if (c == 80) // đi xuống
				{
					if (y_sang < 19)
					{
						int y_cu = y_sang;
						// xóa thanh sang sáng cũ
						if (x_sang == 7 && y_cu == 15)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "               ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "1. Them moc hoc";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 16)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                        ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "2. Xem danh sach mon hoc";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 17)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "              ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "3. Xoa moc hoc";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 18)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                     ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "3. Hieu chinh mon hoc";
							m.unlock();
						}
						y_sang++;
						// hiện thanh sáng mới
						if (x_sang == 7 && y_sang == 16)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                        ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "2. Xem danh sach mon hoc";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 17)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "              ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "3. Xoa moc hoc";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 18)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                     ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "3. Hieu chinh moc hoc";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 19)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "        ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "4. Thoat";
							textcolor(0);
							m.unlock();
						}
					}
				}
			}
		}

	}
}

void giao_dien_them_mon_hoc(int &cong_tac_dau_nhay, DANH_SACH_MON_HOC &ds_mh)
{
	// khởi tạo node môn học
	Node_Mon_Hoc *p = new Node_Mon_Hoc;
	p->data.ma_mh = tao_ma_mon_hoc(ds_mh);
	// vẽ giao diênk
	textcolor(0);
	SetColor(14);
	gotoXY(76, 5);
	cout << " _____ _____ _____ _____    _____ _____ _____    _____ _____ _____ ";
	gotoXY(76, 6);
	cout << "|_   _|  |  |   __|     |  |     |     |   | |  |  |  |     |     |";
	gotoXY(76, 7);
	cout << "  | | |     |   __| | | |  | | | |  |  | | | |  |     |  |  |   --|";
	gotoXY(76, 8);
	cout << "  |_| |__|__|_____|_|_|_|  |_|_|_|_____|_|___|  |__|__|_____|_____|";
	textcolor(0);

	box(65, 12, 87, 25, 15, 0, "");
	SetColor(11);

	gotoXY(86, 15);
	cout << "MA MOC HOC:";
	box(110, 14, 20, 2, 11, 0, to_string(p->data.ma_mh));
	SetColor(11);

	gotoXY(86, 19);
	cout << "TEN MOC HOC:";
	box(110, 18, 30, 2, 14, 0, "");
	SetColor(11);

	gotoXY(86, 23);
	cout << "STCLT:";
	box(110, 22, 20, 2, 11, 0, "");
	SetColor(11);

	gotoXY(86, 27);
	cout << "STCTH:";
	box(110, 26, 20, 2, 11, 0, "");
	SetColor(11);

	// box ok
	box(87, 31, 3, 2, 11, 43, "OK");

	// box hủy
	box(116, 31, 7, 2, 11, 65, "CANCEL");

	// ------------------- biến xử lí đề -------------------
	int x_sang = 87;
	int y_sang = 18;
	string tt_1_mh[4];
	bool thoat = true;
	while (thoat)
	{
		char c = _getch();
		if (c == 13) // enter
		{
			if (y_sang == 30 && x_sang == 87) // ok
			{
				int kt_tt_de_trong = 0;
				// kiểm tra xem thông tin nhập đê trống
				if (tt_1_mh[0].empty())
				{
					box(110, 18, 30, 2, 12, 0, "");
					kt_tt_de_trong = 1;
				}
				if (tt_1_mh[1].empty())
				{
					box(110, 22, 20, 2, 12, 0, "");
					kt_tt_de_trong = 1;
				}
				if (tt_1_mh[2].empty())
				{
					box(110, 26, 20, 2, 12, 0, "");
					kt_tt_de_trong = 1;
				}
				if (kt_tt_de_trong == 1)
				{
					gotoXY(92, 34);
					SetColor(10);
					cout << "Khong duoc de trong du lieu!";
				}
				else if (kt_tt_de_trong == 0)
				{
					gotoXY(92, 34);
					SetColor(10);
					cout << "Nhan enter de them moc hoc";
					gotoXY(92, 35);
					cout << "Nhan esc de huy thao tac";
					while (77)
					{
						char c_con = _getch();
						if (c_con == 13)
						{
							// truyền thông tin cho node môn học
							chuan_hoa_chu(tt_1_mh[0]);
							p->data.ten_mh = tt_1_mh[0];
							p->data.STCLT = atoi(tt_1_mh[1].c_str());
							p->data.STCTH = atoi(tt_1_mh[2].c_str());
							them_mon_hoc(ds_mh.t, p);
							ds_mh.sl++;
							thoat = false;
							break;
						}
						else if (c_con == 27)
						{
							gotoXY(92, 34);
							cout << "                        ";
							gotoXY(92, 35);
							cout << "                          ";
							break;
						}
					}
				}
			}
			else if (y_sang == 30 && x_sang == 116) // cancle
			{
				gotoXY(92, 34);
				SetColor(10);
				cout << "Nhan enter de huy";
				gotoXY(92, 35);
				cout << "Nhan esc de huy thao tac";
				while (true)
				{
					char c_con = _getch();
					if (c_con == 13)
					{
						delete p; // giải phóng đi node môn học vừa khởi tạo khi không còn sử dụng
						thoat = false;
						break;
					}
					else if (c_con == 27)
					{
						gotoXY(92, 34);
						cout << "                       ";
						gotoXY(92, 35);
						cout << "                        ";
						break;
					}
				}
			}
		}
		else if (c == 8) // backspace
		{
			if (y_sang == 18 && !tt_1_mh[0].empty())
			{
				tt_1_mh[0].pop_back();
				box(110, 18, 30, 2, 14, 0, tt_1_mh[0]);
			}
			else if (y_sang == 22 && !tt_1_mh[1].empty())
			{
				tt_1_mh[1].pop_back();
				box(110, 22, 20, 2, 14, 0, tt_1_mh[1]);
			}
			else if (y_sang == 26 && !tt_1_mh[2].empty())
			{
				tt_1_mh[2].pop_back();
				box(110, 26, 20, 2, 14, 0, tt_1_mh[2]);
			}
		}
		else if ((c != -32))
		{
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 32)
			{
				if (y_sang == 18)
				{
					tt_1_mh[0].push_back(c);
					box(110, 18, 30, 2, 14, 0, tt_1_mh[0]);
				}
				else if (y_sang == 22)
				{
					tt_1_mh[1].push_back(c);
					box(110, 22, 20, 2, 14, 0, tt_1_mh[1]);
				}
				else if (y_sang == 26)
				{
					tt_1_mh[2].push_back(c);
					box(110, 26, 20, 2, 14, 0, tt_1_mh[2]);
				}
			}
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 72) // lên
			{
				if (y_sang > 18)
				{
					// xoá thông bão cũ
					gotoXY(92, 34);
					cout << "                               ";
					// tắt thanh sáng cũ
					if (y_sang == 22)
					{
						box(110, 22, 20, 2, 11, 0, tt_1_mh[1]);
					}
					else if (y_sang == 26)
					{
						box(110, 26, 20, 2, 11, 0, tt_1_mh[2]);
					}
					else if (y_sang == 30)
					{
						x_sang = 87;
						box(87, 31, 3, 2, 11, 43, "OK");
						box(116, 31, 7, 2, 11, 65, "CANCEL");
					}
					y_sang -= 4;
					// bật thanh sáng mới
					if (y_sang == 18)
					{
						box(110, 18, 30, 2, 14, 0, tt_1_mh[0]);
					}
					else if (y_sang == 22)
					{
						box(110, 22, 20, 2, 14, 0, tt_1_mh[1]);
					}
					else if (y_sang == 26)
					{
						box(110, 26, 20, 2, 14, 0, tt_1_mh[2]);
					}
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang < 30)
				{
					// tắt thanh sáng cũ
					if (y_sang == 18)
					{
						box(110, 18, 30, 2, 11, 0, tt_1_mh[0]);
					}
					else if (y_sang == 22)
					{
						box(110, 22, 20, 2, 11, 0, tt_1_mh[1]);
					}
					else if (y_sang == 26)
					{
						box(110, 26, 20, 2, 11, 0, tt_1_mh[2]);
					}
					y_sang += 4;
					// bật thanh sáng mới
					if (y_sang == 22)
					{
						box(110, 22, 20, 2, 14, 0, tt_1_mh[1]);
					}
					else if (y_sang == 26)
					{
						box(110, 26, 20, 2, 14, 0, tt_1_mh[2]);
					}
					else if (y_sang == 30)
					{
						box(87, 31, 3, 2, 14, 43, "OK");
					}
				}
			}
			else if (c == 77)
			{
				if (y_sang == 30)
				{
					// tắt thanh sáng cũ
					box(87, 31, 3, 2, 11, 43, "OK");
					x_sang += 29;
					// bật thanh sáng mới
					box(116, 31, 7, 2, 14, 65, "CANCEL");
				}
			}
			else if (c == 75)
			{
				if (y_sang == 30)
				{
					// tắt thanh sáng cũ
					box(116, 31, 7, 2, 11, 65, "CANCEL");
					x_sang -= 29;
					// bật thanh sáng mới
					box(87, 31, 3, 2, 14, 43, "OK");
				}
			}
		}	
	}
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

void giao_dien_xem_ds_mon_hoc(DANH_SACH_MON_HOC ds_mh,int &cong_tac_dau_nhay)
{
	if (ds_mh.sl == 0)
	{
		xoa_giao_dien_mo_lop_tin_chi();
		cong_tac_dau_nhay = 0;
		return;
	}
	// xuất tiêu đề danh sách môn học
	SetColor(14);
	gotoXY(78, 5);
	cout << ".__ .__..  ..  .   __..__. __ .  .  .  ..__..  .  .  ..__. __";
	gotoXY(78, 6);
	cout << "|  " << char(92) << "[__]|" << char(92) << " ||__|  (__ [__]/  `|__|  |" << char(92) << "/||  ||" << char(92) << " |  |__||  |/  `";
	gotoXY(78, 7);
	cout << "|__/|  || " << char(92) << "||  |  .__)|  |" << char(92) << "__.|  |  |  ||__|| " << char(92) << "|  |  ||__|" << char(92) << "__.";

	// vẽ hộp chứa
	box(76, 10, 63, 3 + ds_mh.sl * 2, 11, 0, "");

	// xuất tiêu đề
	gotoXY(78, 11);
	SetColor(14); cout << setw(3) << "MA MON HOC";
	textcolor(0);
	SetColor(11); cout << "  " << char(222);
	SetColor(14); cout << setw(20) << "TEN MON HOC" << "         ";
	SetColor(11); cout  << char(222) << "  ";
	SetColor(14); cout << setw(2) << "STCLT";
	SetColor(11); cout << "  " << char(222) << "  ";
	SetColor(14); cout << setw(3) << "STCTH" << endl;
	SetColor(11);
	for (int j = 0; j < 60; j++)
	{
		gotoXY(78 + j, 12);
		cout << char(220);
	}
	// xuất nội dung
	MonHoc *mang_mh = new MonHoc[ds_mh.sl];
	int sl_mh = 0;
	tao_mang_ds_mh(ds_mh.t, mang_mh, sl_mh);
	while (!_kbhit())
	{
		int kc_dong = 0;
		for (int i = 0; i < ds_mh.sl; i++)
		{
			gotoXY(78, 13 + i + kc_dong);
			SetColor(15); cout << "   " << setw(3) << mang_mh[i].ma_mh;
			SetColor(11); cout << "      " << char(222);
			SetColor(15); cout << "  "<< setw(26) << mang_mh[i].ten_mh;
			SetColor(11); cout << " " << char(222);
			SetColor(15); cout << "  " << setw(3) << mang_mh[i].STCLT;
			SetColor(11); cout << "    "<< char(222) << "  ";
			SetColor(15); cout << " " << setw(2) << mang_mh[i].STCTH;
			kc_dong++;
			SetColor(11);
			// vẽ đường kẻ
			if (i < ds_mh.sl - 1)
			{
				for (int g = 0; g < 60; g++)
				{
					gotoXY(78 + g, 13 + i + kc_dong);
					cout << char(220);
				}
			}
		}
	}
	delete[]mang_mh;
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}
// hàm con của giao diện xem danh sách môn học
void tao_mang_ds_mh(TREE t,MonHoc mang_mh[], int &sl_mh)
{
	if (t != NULL)
	{
		tao_mang_ds_mh(t->pLeft, mang_mh, sl_mh);
		mang_mh[sl_mh].ma_mh = t->data.ma_mh;
		mang_mh[sl_mh].ten_mh = t->data.ten_mh;
		mang_mh[sl_mh].STCLT = t->data.STCLT;
		mang_mh[sl_mh].STCTH = t->data.STCTH;
		sl_mh++;
		tao_mang_ds_mh(t->pRight, mang_mh, sl_mh);
	}
}

void giao_dien_xoa_moc_hoc(DANH_SACH_MON_HOC &ds, int &cong_tac_dau_nhay)
{
	gotoXY(80, 21);
	SetColor(11);
	cout << "NHAP MA MON HOC CAN XOA:";
	box(120, 20, 15, 2, 14, 0, "");
	cong_tac_dau_nhay = 0;
	string ma_mh_xoa;
	bool exit_ = true;
	while (exit_)
	{
		char c = _getch();
		if (c >= 48 && c <= 57)
		{
			gotoXY(85, 22);
			cout << "                             ";
			ma_mh_xoa.push_back(c);
		}
		else if (c == 27) // esc
		{
			exit_ = false;
		}
		else if (c == 8) // backspace
		{
			if (!ma_mh_xoa.empty())
			{
				gotoXY(85, 22);
				cout << "                             ";
				box(120, 20, 15, 2, 14, 0, "");
				ma_mh_xoa.pop_back();
			}
		}
		else if (c == 13) // enter
		{
			Node_Mon_Hoc *p = kt_trung_ma_mh(ds.t, atoi(ma_mh_xoa.c_str()));
			// mã tín chỉ không tồn tại
			if (p == NULL)
			{
				SetColor(12);
				gotoXY(85, 22);
				cout << "Ma mon hoc khong ton tai!";
				
			}
			else
			{
				box(120, 20, 15, 2, 11, 0, ma_mh_xoa);
				// tắt ô sáng cũ
				int x_sang_con = 75;
				// ô sáng đầu tiên
				box(75, 30, 3, 2, 14, 70, "OK");
				// box huỷ
				box(124, 30, 7, 2, 11, 0, "CANCEL");
				while (true)
				{
					char c_con = _getch();
					if (c_con == -32)
					{
						char c_con_con = _getch();
						if (c_con_con == 75) // samg trái
						{
							if (x_sang_con > 75)
							{
								// tắt thanh sáng cũ
								box(124, 30, 7, 2, 11, 0, "CANCEL");
								x_sang_con -= 49;
								// bật thanh sáng mới
								box(75, 30, 3, 2, 14, 70, "OK");
							}
						}
						else if (c_con_con == 77) // sang phải
						{
							if (x_sang_con < 124)
							{
								// tắt thanh sáng cũ
								box(75, 30, 3, 2, 11, 70, "OK");
								x_sang_con += 49;
								// bật thanh sáng mới
								box(124, 30, 7, 2, 14, 0, "CANCEL");
							}
						}
					}
					else if (c_con == 13) // enter
					{
						if (x_sang_con == 124) // huỷ lênh xoá
						{
							exit_ = false;
							break;
						}
						else if (x_sang_con == 75) // thực hiện lệnh xoá
						{
							int check = 0;
							Xoa_1_moc_hoc(ds.t, atoi(ma_mh_xoa.c_str()), check);
							ds.sl--;
							exit_ = false;
							break;
						}
					}
				}
			}
		}
		box(120, 20, 15, 2, 14, 0, ma_mh_xoa);
	}
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

void giao_dien_hieu_chinh_moc_hoc(DANH_SACH_MON_HOC &ds, int &cong_tac_dau_nhay)
{
	gotoXY(80, 21);
	SetColor(11);
	cout << "NHAP MA MON HOC MUON CAP NHAT:";
	
	box(120, 20, 15, 2, 14, 0, "");
	cong_tac_dau_nhay = 0;
	string ma_moc_hoc_muon_cap_nhat;
	bool thoat = true;
	while (thoat)
	{
		char c = _getch();
		if (c >= 48 && c <= 57)
		{
			gotoXY(85, 22);
			cout << "                             ";
			ma_moc_hoc_muon_cap_nhat.push_back(c);
		}
		else if (c == 27) // esc
		{
			break;
		}
		else if (c == 8) // backspace
		{
			if (!ma_moc_hoc_muon_cap_nhat.empty())
			{
				gotoXY(85, 22);
				cout << "                             ";
				box(120, 20, 15, 2, 14, 0, "");
				ma_moc_hoc_muon_cap_nhat.pop_back();
			}
		}
		else if (c == 13) // enter
		{
			Node_Mon_Hoc *p = kt_trung_ma_mh(ds.t, atoi(ma_moc_hoc_muon_cap_nhat.c_str()));
			// mã tín chỉ không tồn tại
			if (p == NULL)
			{
				SetColor(12);
				gotoXY(85, 22);
				cout << "Ma mon hoc khong ton tai!";
			}
			else
			{
				// xoá dữ liêu cũ
				box(120, 20, 15, 2, 16, 0, "");
				// ============== cho xem thông tin cũ của lớp tín chỉ ===================
				gotoXY(94, 5);
				textcolor(100);
				cout << "                  ";
				gotoXY(95, 5);
				SetColor(16);
				cout << "THONG TIN MOC HOC";
				// xuất tiêu đề
				box(76, 10, 63, 5, 11, 0, "");

				// xuất tiêu đề
				gotoXY(78, 11);
				SetColor(14); cout << setw(3) << "MA MON HOC";
				textcolor(0);
				SetColor(11); cout << "  " << char(222);
				SetColor(14); cout << setw(20) << "TEN MON HOC" << "         ";
				SetColor(11); cout << char(222) << "  ";
				SetColor(14); cout << setw(2) << "STCLT";
				SetColor(11); cout << "  " << char(222) << "  ";
				SetColor(14); cout << setw(3) << "STCTH" << endl;
				SetColor(11);
				for (int j = 0; j < 60; j++)
				{
					gotoXY(78 + j, 12);
					cout << char(220);
				}
				// xuất nội dung
				gotoXY(78, 13);
				SetColor(15); cout << "   " << setw(3) << p->data.ma_mh;
				SetColor(11); cout << "      " << char(222);
				SetColor(15); cout << "  " << setw(26) << p->data.ten_mh;
				SetColor(11); cout << " " << char(222);
				SetColor(15); cout << "  " << setw(3) << p->data.STCLT;
				SetColor(11); cout << "    " << char(222) << "  ";
				SetColor(15); cout << " " << setw(2) << p->data.STCTH;

				// ==============  hiệu chỉnh thông tin của lớp tín chỉ ===================

				// xoá tiêu đề
				gotoXY(80, 21);
				cout << "                               ";

				gotoXY(86, 19);
				cout << "TEN MOC HOC:";
				box(110, 18, 30, 2, 14, 0, "");
				SetColor(11);

				gotoXY(86, 23);
				cout << "STCLT:";
				box(110, 22, 20, 2, 11, 0, "");
				SetColor(11);

				gotoXY(86, 27);
				cout << "STCTH:";
				box(110, 26, 20, 2, 11, 0, "");
				SetColor(11);

				// box ok
				box(87, 31, 3, 2, 11, 43, "OK");

				// box hủy
				box(116, 31, 7, 2, 11, 65, "CANCEL");

				// ------------------- biến xử lí đề -------------------
				int x_sang = 87;
				int y_sang = 18;
				string tt_1_mh[3];
				while (77)
				{
					char c = _getch();
					if (c == 13) // enter
					{
						if (y_sang == 30 && x_sang == 87) // ok
						{
							int kt_tt_de_trong = 0;
							// kiểm tra xem thông tin nhập đê trống
							if (!tt_1_mh[0].empty())
							{
								chuan_hoa_chu(tt_1_mh[0]);
								p->data.ten_mh = tt_1_mh[0];
							}
							if (!tt_1_mh[1].empty())
							{
								p->data.STCLT = atoi(tt_1_mh[1].c_str());
							}
							if (!tt_1_mh[2].empty())
							{
								p->data.STCTH = atoi(tt_1_mh[2].c_str());
							}
							thoat = false;
							break;
						}
						else if (y_sang == 30 && x_sang == 116) // cancle
						{
							gotoXY(92, 34);
							SetColor(10);
							cout << "Nhan enter de huy";
							gotoXY(92, 35);
							cout << "Nhan esc de huy thao tac";
							while (true)
							{
								char c_con = _getch();
								if (c_con == 13)
								{
									delete p;
									thoat = false;
									break;
								}
								else if (c_con == 27)
								{
									gotoXY(92, 34);
									cout << "                       ";
									gotoXY(92, 35);
									cout << "                        ";
									break;
								}
							}
							if (thoat == false)
							{
								break;
							}
						}
					}
					else if (c == 8) // backspace
					{
						if (y_sang == 18 && !tt_1_mh[0].empty())
						{
							tt_1_mh[0].pop_back();
							box(110, 18, 30, 2, 14, 0, tt_1_mh[0]);
						}
						else if (y_sang == 22 && !tt_1_mh[1].empty())
						{
							tt_1_mh[1].pop_back();
							box(110, 22, 20, 2, 14, 0, tt_1_mh[1]);
						}
						else if (y_sang == 26 && !tt_1_mh[2].empty())
						{
							tt_1_mh[2].pop_back();
							box(110, 26, 20, 2, 14, 0, tt_1_mh[2]);
						}
					}
					else if ((c != -32))
					{
						if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 32)
						{
							if (y_sang == 18)
							{
								tt_1_mh[0].push_back(c);
								box(110, 18, 30, 2, 14, 0, tt_1_mh[0]);
							}
							else if (y_sang == 22)
							{
								tt_1_mh[1].push_back(c);
								box(110, 22, 20, 2, 14, 0, tt_1_mh[1]);
							}
							else if (y_sang == 26)
							{
								tt_1_mh[2].push_back(c);
								box(110, 26, 20, 2, 14, 0, tt_1_mh[2]);
							}
						}
					}
					else if (c == -32)
					{
						c = _getch();
						if (c == 72) // lên
						{
							if (y_sang > 18)
							{
								// xoá thông bão cũ
								gotoXY(92, 34);
								cout << "                               ";
								// tắt thanh sáng cũ
								if (y_sang == 22)
								{
									box(110, 22, 20, 2, 11, 0, tt_1_mh[1]);
								}
								else if (y_sang == 26)
								{
									box(110, 26, 20, 2, 11, 0, tt_1_mh[2]);
								}
								else if (y_sang == 30)
								{
									x_sang = 87;
									box(87, 31, 3, 2, 11, 43, "OK");
									box(116, 31, 7, 2, 11, 65, "CANCEL");
								}
								y_sang -= 4;
								// bật thanh sáng mới
								if (y_sang == 18)
								{
									box(110, 18, 30, 2, 14, 0, tt_1_mh[0]);
								}
								else if (y_sang == 22)
								{
									box(110, 22, 20, 2, 14, 0, tt_1_mh[1]);
								}
								else if (y_sang == 26)
								{
									box(110, 26, 20, 2, 14, 0, tt_1_mh[2]);
								}
							}
						}
						else if (c == 80) // xuống
						{
							if (y_sang < 30)
							{
								// tắt thanh sáng cũ
								if (y_sang == 18)
								{
									box(110, 18, 30, 2, 11, 0, tt_1_mh[0]);
								}
								else if (y_sang == 22)
								{
									box(110, 22, 20, 2, 11, 0, tt_1_mh[1]);
								}
								else if (y_sang == 26)
								{
									box(110, 26, 20, 2, 11, 0, tt_1_mh[2]);
								}
								y_sang += 4;
								// bật thanh sáng mới
								if (y_sang == 22)
								{
									box(110, 22, 20, 2, 14, 0, tt_1_mh[1]);
								}
								else if (y_sang == 26)
								{
									box(110, 26, 20, 2, 14, 0, tt_1_mh[2]);
								}
								else if (y_sang == 30)
								{
									box(87, 31, 3, 2, 14, 43, "OK");
								}
							}
						}
						else if (c == 77)
						{
							if (y_sang == 30)
							{
								// tắt thanh sáng cũ
								box(87, 31, 3, 2, 11, 43, "OK");
								x_sang += 29;
								// bật thanh sáng mới
								box(116, 31, 7, 2, 14, 65, "CANCEL");
							}
						}
						else if (c == 75)
						{
							if (y_sang == 30)
							{
								// tắt thanh sáng cũ
								box(116, 31, 7, 2, 11, 65, "CANCEL");
								x_sang -= 29;
								// bật thanh sáng mới
								box(87, 31, 3, 2, 14, 43, "OK");
							}
						}
					}
				}
			}
		}
		box(120, 20, 15, 2, 14, 0, ma_moc_hoc_muon_cap_nhat);
	}
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

// ================================ MENU CON DANH SÁCH SINH VIÊN ================================

void menu_con_nhap_sinh_vien(Sinh_Vien ds[],int &sl_sv,set<string> &ds_ma_lop)
{
	SetColor(11);
	gotoXY(7, 15);
	cout << "1. Them sinh vien";
	gotoXY(7, 16);
	cout << "2. Xem danh sach sinh vien";
	gotoXY(7, 17);
	cout << "3. Xoa sinh vien";
	gotoXY(7, 18);
	cout << "3. Hieu chinh sinh vien";
	gotoXY(7, 19);
	cout << "4. Thoat";

	int x_sang = 7;
	int y_sang = 15;
	// ------- hiện thanh sáng
	m.lock();
	gotoXY(x_sang, y_sang);
	textcolor(70);
	cout << "                 ";
	gotoXY(x_sang, y_sang);
	SetColor(11);
	cout << "1. Them sinh vien";
	textcolor(0);
	m.unlock();
	// -------------- di chuyển của menu con
	int cong_tac_dau_nhay = 0; // CÔNG TẮC KHI NHẤN PHÍM ENTER

	while (77)
	{

		// ------------------ xử lí lệnh thêm môn học
		if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 15)
		{
			giao_dien_them_sinh_vien(cong_tac_dau_nhay, ds, sl_sv, ds_ma_lop);
		}
		// ------------------ xử lí lệnh xem danh sách môn học
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 16)
		{
			giao_dien_xem_sinh_vien(ds, sl_sv, ds_ma_lop, cong_tac_dau_nhay);
		}
		// ------------------- xoá môn học
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 17)
		{
			giao_dien_xoa_sinh_vien(ds, sl_sv, cong_tac_dau_nhay);
		}
		// hiệu chỉnh môn học
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 18)
		{
			giao_dien_hieu_chinh_sinh_vien(ds, sl_sv, cong_tac_dau_nhay);
		}
		// ------------------- thoát
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 19)
		{
			break;
		}
		// menu nhỏ ======================= LUỒNG  CHÍNH CỦA MENU NHỎ
		char c = _getch();
		// đã nhấn phím enter
		if (c == 13)
		{
			// nhấp số lượng lớp tín chỉ cần thêm
			if (x_sang == 7 && y_sang == 15 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			// xem lớp tín chỉ
			else if (x_sang == 7 && y_sang == 16 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 17 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 18 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 19 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
		}
		if (cong_tac_dau_nhay == 0)
		{
			if (c == -32)
			{
				c = _getch();
				if (c == 72) // đi lên
				{
					if (y_sang > 15)
					{
						int y_cu = y_sang;

						// xóa thanh sang sáng cũ
						if (x_sang == 7 && y_cu == 16)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                          ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "2. Xem danh sach sinh vien";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 17)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "3. Xoa sinh vien";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 18)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                       ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "3. Hieu chinh sinh vien";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 19)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "        ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "4. Thoat";
							m.unlock();
						}
						y_sang--;
						// hiển thị lại thanh sáng mới
						if (x_sang == 7 && y_sang == 15)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                 ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "1. Them sinh vien";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 16)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                          ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "2. Xem danh sach sinh vien";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 17)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "3. Xoa sinh vien";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 18)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                       ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "4. Hieu chinh sinh vien";
							textcolor(0);
							m.unlock();
						}
					}
				}
				else if (c == 80) // đi xuống
				{
					if (y_sang < 19)
					{
						int y_cu = y_sang;
						// xóa thanh sang sáng cũ
						if (x_sang == 7 && y_cu == 15)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                 ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "1. Them sinh vien";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 16)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                          ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "2. Xem danh sach sinh vien";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 17)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "3. Xoa sinh vien";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 18)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                       ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "3. Hieu chinh sinh vien";
							m.unlock();
						}
						y_sang++;
						// hiện thanh sáng mới
						if (x_sang == 7 && y_sang == 16)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                          ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "2. Xem danh sach sinh vien";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 17)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "3. Xoa sinh vien";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 18)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                       ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "3. Hieu chinh sinh vien";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 19)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "        ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "4. Thoat";
							textcolor(0);
							m.unlock();
						}
					}
				}
			}
		}

	}
}

void giao_dien_them_sinh_vien(int &cong_tac_dau_nhay, Sinh_Vien ds_sv[],int &sl_sv,set<string> &ds_ma_lop)
{
	gotoXY(80, 21);
	SetColor(11);
	cout << "NHAP MA LOP CAN THEM SINH VIEN:";
	box(120, 20, 20, 2, 14, 0, "");
	string ma_lop_sv;
	// -------------------------- bước 1: nhập mã lớp sinh viên --------------------------
	while (77)
	{
		char c = _getch();
		if (c == 8 && !ma_lop_sv.empty()) // backspace
		{
			ma_lop_sv.pop_back();
		}
		else if (c == 13)
		{
			break;
		}
		if (c != -32 && c != 72 && c != 80 && c != 75 && c != 77)
		{
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 32)
			{
					ma_lop_sv.push_back(c);
			}
		}
		box(120, 20, 20, 2, 14, 0, ma_lop_sv);
	}
	viet_hoa_ma_lop(ma_lop_sv);
	
	box(120, 20, 20, 2, 11, 0, ma_lop_sv);

	// -------------------------- bước 2: nhập số lượng sinh viên cần thêm --------------------------
	gotoXY(80, 24);
	SetColor(11);
	cout << "NHAP SO LUONG SINH VIEN CAN THEM:";
	box(120, 23, 20, 2, 14, 0, "");
	string sl_sv_can_them;
	while (77)
	{
		char c = _getch();
		if (c == 13)
		{
			break;
		}
		else if (c == 8 && !sl_sv_can_them.empty()) // backspace
		{
			sl_sv_can_them.pop_back();
		}
		
		else if (c >= 48 && c <= 57)
		{
			sl_sv_can_them.push_back(c);
		}
		box(120, 23, 20, 2, 14, 0, sl_sv_can_them);
	}

	int sl_sv_them = atoi(sl_sv_can_them.c_str());
	
	xoa_giao_dien_mo_lop_tin_chi();
	// -------------------------- bước 3: thêm sinh viên vào danh sách --------------------------
	for (int i = 0; i < sl_sv_them; i++)
	{
		SetColor(14);
		// vẽ giao diện
		gotoXY(70, 5);
		cout << "______ __  __  ____ ___  ___     __  __ __  __ __  __    __ __ __  ____ __  __";
		gotoXY(70, 6);
		cout << "| || | ||  || ||    ||" << char(92) << char(92) << "//||    (( " << char(92) << " || ||" << char(92) << " || ||  ||    || || || ||    ||" << char(92) << " ||";
		gotoXY(70, 7);
		cout << "  ||   ||==|| ||==  || " << char(92) << "/ ||     " << char(92) << char(92) << "  || ||" << char(92) << char(92) << "|| ||==||    " << char(92) << char(92) << " // || ||==  ||" << char(92) << char(92) << "||";
		gotoXY(70, 8);
		cout << "  ||   ||  || ||___ ||    ||    " << char(92) << "_)) || || " << char(92) << "|| ||  ||     " << char(92) << "V/  || ||___ || " << char(92) << "||";

		//-------------------- vẽ hộp chứa
		box(69, 10, 79, 30, 11, 0, "");

		Sinh_Vien x; // -----------------tạo biến sinh viên để lưu dữ liệu

		SetColor(11);
		//-------------------vẽ khung tiêu đề
		gotoXY(85, 13);
		cout << "MA LOP:";
		box(100, 12, 29, 2, 11, 0, ma_lop_sv);

		tao_ma_sv(x.ma_sv, ds_sv, sl_sv);
		gotoXY(85, 17);
		cout << "MA SV:";
		box(100, 16, 29, 2, 11, 0, x.ma_sv);

		gotoXY(85, 21);
		cout << "HO:";                     // ô sáng đầu tiên
		box(100, 20, 29, 2, 14, 0, "");

		SetColor(11);
		gotoXY(85, 25);
		cout << "TEN:";                     
		box(100, 24, 29, 2, 11, 0, "");

		gotoXY(85, 29);
		cout << "PHAI:";                     
		box(100, 28, 29, 2, 11, 0, "");

		gotoXY(85, 33);
		cout << "SDT:";
		box(100, 32, 29, 2, 11, 0, "");

		box(84, 36, 5, 2, 11, 42, "THEM");

		box(125, 36, 4, 2, 11, 64, "HUY");

		int x_sang = 84, y_sang = 20; // toạ độ thanh sáng
		string tt_1_sv[4];
		bool thoat = true;
		while (thoat)
		{
			char c = _getch();
			if (c == 13) // enter
			{
				if (y_sang == 36 && x_sang == 84) // thêm
				{
					int check = 0;
					if (tt_1_sv[0].empty())
					{
						gotoXY(96, 37);
						SetColor(12);
						cout << "Khong duoc de trong du lieu!";
						box(100, 20, 29, 2, 12, 0, tt_1_sv[0]);
						check = 1;
					}
					else if (!tt_1_sv[0].empty())
					{
						for (int j = 0; j < tt_1_sv[0].length(); j++)
						{
							if (!((tt_1_sv[0].at(j) >= 65 && tt_1_sv[0].at(j) <= 90) || (tt_1_sv[0].at(j) >= 97 && tt_1_sv[0].at(j) <= 122) || tt_1_sv[1].at(j) == ' '))
							{
								gotoXY(100, 23);
								SetColor(12);
								cout << "Khong duoc nhap ki tu dac biet hoac so!";
								box(100, 20, 29, 2, 12, 0, tt_1_sv[0]);
								check = 1;
								break;
							}
						}
						
					}
					if (tt_1_sv[1].empty())
					{
						gotoXY(96, 37);
						SetColor(12);
						cout << "Khong duoc de trong du lieu!";
						box(100, 24, 29, 2, 12, 0, tt_1_sv[2]);
					}
					else if (!tt_1_sv[1].empty())
					{
						for (int j = 0; j < tt_1_sv[1].length(); j++)
						{
							if (!((tt_1_sv[1].at(j) >= 65 && tt_1_sv[1].at(j) <= 90) || (tt_1_sv[1].at(j) >= 97 && tt_1_sv[1].at(j) <= 122) || tt_1_sv[1].at(j) == ' '))
							{
								gotoXY(100, 27);
								SetColor(12);
								cout << "Khong duoc nhap ki tu dac biet hoac so!";
								box(100, 24, 29, 2, 12, 0, tt_1_sv[1]);
								check = 1;
								break;
							}
						}
						
					}
					if (tt_1_sv[2].empty())
					{
						gotoXY(96, 37);
						SetColor(12);
						cout << "Khong duoc de trong du lieu!";
						box(100, 28, 29, 2, 12, 0, tt_1_sv[2]);
						check = 1;
					}
					else if (!tt_1_sv[2].empty())
					{
						for (int j = 0; j < tt_1_sv[2].length(); j++)
						{
							if (!((tt_1_sv[2].at(j) >= 65 && tt_1_sv[2].at(j) <= 90) || (tt_1_sv[2].at(j) >= 97 && tt_1_sv[2].at(j) <= 122)))
							{
								gotoXY(100, 31);
								SetColor(12);
								cout << "Khong duoc nhap ki tu dac biet hoac so!";
								box(100, 28, 29, 2, 12, 0, tt_1_sv[2]);
								check = 1;
								break;
							}
						}
						
					}
					if (tt_1_sv[3].empty())
					{
						gotoXY(96, 37);
						SetColor(12);
						cout << "Khong duoc de trong du lieu!";
						box(100, 32, 29, 2, 12, 0, tt_1_sv[3]);
						check = 1;
					}
					else if (!tt_1_sv[3].empty())
					{
						for (int j = 0; j < tt_1_sv[3].length(); j++)
						{
							if ((tt_1_sv[3].at(j) >= 65 && tt_1_sv[3].at(j) <= 90) || (tt_1_sv[3].at(j) >= 97 && tt_1_sv[3].at(j) <= 122))
							{
								gotoXY(100, 35);
								SetColor(12);
								cout << "Khong duoc nhap ki tu o trong SDT!";
								box(100, 32, 29, 2, 12, 0, tt_1_sv[3]);
								check = 1;
								break;
							}
						}
					}
					if (check == 0)
					{
						gotoXY(96, 37);
						SetColor(10);
						cout << "Nhan enter de huy";
						gotoXY(96, 38);
						cout << "Nhan esc de huy thao tac";
						while (true)
						{
							c = _getch();
							if (c == 27)
							{
								break;
							}
							else if (c == 13)
							{
								chuan_hoa_chu(tt_1_sv[0]);
								chuan_hoa_chu(tt_1_sv[1]);
								x.ho = tt_1_sv[0];
								x.ten = tt_1_sv[1];
								x.Ma_Lop = ma_lop_sv;
								x.phai = tt_1_sv[2];
								x.SO_DT = tt_1_sv[3];
								ds_sv[sl_sv++] = x;
								thoat = false;
								break;
							}
						}
					}
				}
				else if (y_sang == 36 && x_sang == 125) // huỷ
				{
					gotoXY(96, 37);
					SetColor(10);
					cout << "Nhan enter de huy";
					gotoXY(96, 38);
					cout << "Nhan esc de huy thao tac";
					while (true)
					{
						c = _getch();
						if (c == 27)
						{
							break;
						}
						else if (c == 13)
						{
							ds_ma_lop.insert(ma_lop_sv); // thêm mã lớp sinh viên vào danh sách mã lớp
							thoat = false;
							break;
						}
					}
				}
			}
			else if (c == 8) // xoá kí tự
			{
				if (y_sang == 20 && !tt_1_sv[0].empty())
				{
					tt_1_sv[0].pop_back();
					box(100, 20, 29, 2, 14, 0, tt_1_sv[0]);
				}
				else if (y_sang == 24 && !tt_1_sv[1].empty())
				{
					tt_1_sv[1].pop_back();
					box(100, 24, 29, 2, 14, 0, tt_1_sv[1]);
				}
				else if (y_sang == 28 && !tt_1_sv[2].empty())
				{
					tt_1_sv[2].pop_back();
					box(100, 28, 29, 2, 14, 0, tt_1_sv[2]);
				}
				else if (y_sang == 32 && !tt_1_sv[3].empty())
				{
					tt_1_sv[3].pop_back();
					box(100, 32, 29, 2, 14, 0, tt_1_sv[3]);
				}
			}
			// nhập kí tự
			else if (c != -32 && c != 72 && c != 80 && c != 75 && c != 77 && c != 8)
			{
				if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 32)
				{
					if (y_sang == 20)
					{
						tt_1_sv[0].push_back(c);
						box(100, 20, 29, 2, 14, 0, tt_1_sv[0]);
					}
					else if (y_sang == 24)
					{
						tt_1_sv[1].push_back(c);
						box(100, 24, 29, 2, 14, 0, tt_1_sv[1]);
					}
					else if (y_sang == 28)
					{
						tt_1_sv[2].push_back(c);
						box(100, 28, 29, 2, 14, 0, tt_1_sv[2]);
					}
					else if (y_sang == 32)
					{
						tt_1_sv[3].push_back(c);
						box(100, 32, 29, 2, 14, 0, tt_1_sv[3]);
					}
				}
			}
			// di chuyển
			else if (c == -32)
			{
				c = _getch();
				if (c == 80) // xuống
				{
					if (y_sang < 36)
					{
						// tắt thanh sáng
						if (y_sang == 20)
						{
							box(100, 20, 29, 2, 11, 0, tt_1_sv[0]);
						}
						else if (y_sang == 24)
						{
							box(100, 24, 29, 2, 11, 0, tt_1_sv[1]);
						}
						else if (y_sang == 28)
						{
							box(100, 28, 29, 2, 11, 0, tt_1_sv[2]);
						}
						else if (y_sang == 32)
						{
							box(100, 32, 29, 2, 11, 0, tt_1_sv[3]);
						}
						y_sang += 4;
						// bật thanh sáng mới
						if (y_sang == 24)
						{
							box(100, 24, 29, 2, 14, 0, tt_1_sv[1]);
						}
						else if (y_sang == 28)
						{
							box(100, 28, 29, 2, 14, 0, tt_1_sv[2]);
						}
						else if (y_sang == 32)
						{
							box(100, 32, 29, 2, 14, 0, tt_1_sv[3]);
						}
						else if (y_sang == 36)
						{
							box(84, 36, 5, 2, 14, 42, "THEM");
						}
					}
				}
				else if (c == 72) // lên
				{
					if (y_sang > 20)
					{
						// tắt thanh sáng
						if (y_sang == 24)
						{
							box(100, 24, 29, 2, 11, 0, tt_1_sv[1]);
						}
						else if (y_sang == 28)
						{
							box(100, 28, 29, 2, 11, 0, tt_1_sv[2]);
						}
						else if (y_sang == 32)
						{
							box(100, 32, 29, 2, 11, 0, tt_1_sv[3]);
						}
						else if (y_sang == 36)
						{
							//                    ----------     xoá thông báo ----------
							gotoXY(96, 37);
							cout << "                             ";
							gotoXY(100, 23);
							cout << "                                       ";
							gotoXY(100, 27);
							cout << "                                        "; 
							gotoXY(100, 31);
							cout << "                                           ";
							gotoXY(100, 35);
							cout << "                                             ";

							// tắt thanh sáng cũ
							box(84, 36, 5, 2, 11, 42, "THEM");
							box(125, 36, 4, 2, 11, 64, "HUY");
							x_sang = 84;
						}
						y_sang -= 4;
						// bật thanh sáng mới
						if (y_sang == 20)
						{
							box(100, 20, 29, 2, 14, 0, tt_1_sv[0]);
						}
						if (y_sang == 24)
						{
							box(100, 24, 29, 2, 14, 0, tt_1_sv[1]);
						}
						else if (y_sang == 28)
						{
							box(100, 28, 29, 2, 14, 0, tt_1_sv[2]);
						}
						else if (y_sang == 32)
						{
							box(100, 32, 29, 2, 14, 0, tt_1_sv[3]);
						}
					}
				}
				else if (c == 77) // phải
				{
					if (y_sang == 36)
					{
						if (x_sang == 84)
						{
							// tắt thanh sáng cũ
							box(84, 36, 5, 2, 11, 42, "THEM");
							x_sang += 41;
							// bật thanh sáng mới
							box(125, 36, 4, 2, 14, 64, "HUY");
						}
					}
				}
				else if (c == 75) // trái
				{
					if (y_sang == 36)
					{
						if (x_sang == 125)
						{
							// tắt thanh sáng cũ
							box(125, 36, 4, 2, 11, 64, "HUY");
							x_sang -= 41;
							// bật thanh sáng mới
							box(84, 36, 5, 2, 14, 42, "THEM");
						}
					}
				}
			}
		}
	}
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

void giao_dien_xem_sinh_vien(Sinh_Vien ds_sv[], int sl_sv, set<string> &ds_ma_lop, int &cong_tac_dau_nhay)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoXY(90, 5);
	textcolor(70);
	SetConsoleTextAttribute(hConsoleColor, 62);

	cout << "=========== DANH SACH LOP ===========";
	SetConsoleTextAttribute(hConsoleColor, 11);
	gotoXY(90, 10);
	cout << setw(10) << "Ma Lop" << "\t\t" << setw(3) << "So luong";
	SetColor(9);
	gotoXY(93, 11);
	cout << "---------------------------";
	int kc_ = 0;
	string ma_lop_va_so_luong_sv[30];
	int count_ml_sl = 0;
	for (auto it = ds_ma_lop.begin(); it != ds_ma_lop.end(); ++it)
	{
		string _ml = *it;
		ma_lop_va_so_luong_sv[count_ml_sl++] = *it;
		int dem = 0;
		// tìm số lượng sinh viên từng lớp
		for (int i = 0; i < sl_sv; i++)
		{
			if (_stricmp(ds_sv[i].Ma_Lop.c_str(), _ml.c_str()) == 0)
			{
				dem++;
			}
		}
		ma_lop_va_so_luong_sv[count_ml_sl++] = to_string(dem);

		kc_++;
		SetColor(15);
		gotoXY(90, 11 + kc_);
		cout << setw(10) << *it << "\t\t" << setw(3) << dem;
		gotoXY(123, 11 + kc_);
		SetColor(10);
		cout << " XEM ";
		gotoXY(93, 11 + kc_ + 1);
		SetColor(11);
		cout << "---------------------------";
		kc_++;
	}

	// di chuyển thanh sáng
	if (kc_ != 0)
	{
		int x_sang = 123;
		int y_sang = 12;
		int vt_sang = 0;
		// bật thanh sáng đầu tiên
		SetConsoleTextAttribute(hConsoleColor, 74);
		gotoXY(x_sang, y_sang);
		cout << " XEM ";
		bool thoat = true;
		while (thoat)
		{
			char c = _getch();
			if (c == 72) // lên
			{
					if (vt_sang > 0)
					{
						// tắt thanh sáng cũ
						SetConsoleTextAttribute(hConsoleColor, 10);
						gotoXY(x_sang, y_sang + vt_sang);
						cout << " XEM ";
						vt_sang -= 2;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 74);
						gotoXY(x_sang, y_sang + vt_sang);
						cout << " XEM ";
					}	
			}
			else if (c == 80) // xuống
			{
				if (vt_sang < count_ml_sl - 2)
				{
					// tắt thanh sáng cũ
					SetConsoleTextAttribute(hConsoleColor, 10);
					gotoXY(x_sang, y_sang + vt_sang);
					cout << " XEM ";
					vt_sang += 2;
					// bật thanh sáng mới
					SetConsoleTextAttribute(hConsoleColor, 74);
					gotoXY(x_sang, y_sang + vt_sang);
					cout << " XEM ";
				}
			}
			else if (c == 13) // enter
			{
				
				// xuất danh sách sinh viên lớp đó
				string ma_lop_xuat_ds_lop = ma_lop_va_so_luong_sv[vt_sang];
				SetConsoleTextAttribute(hConsoleColor, 0);
				xoa_giao_dien_mo_lop_tin_chi();
				gotoXY(90, 5);
				SetColor(14);

				cout << "=========== DANH SACH SINH VIEN ===========";
				gotoXY(90, 6);
				cout << "            LOP: ";
				SetColor(11);
				cout << ma_lop_xuat_ds_lop;
				box(74, 8, 76, 3 + atoi(ma_lop_va_so_luong_sv[vt_sang + 1].c_str()) * 2, 11, 0, "");

				// xuất tiêu đề
				gotoXY(76, 9);
				SetColor(14); cout << setw(9) << "MA SINH VIEN";
				textcolor(0);
				SetColor(11); cout << "  " << char(222);
				SetColor(14); cout << setw(26) << "HO VA TEN" << "         ";
				SetColor(11); cout << char(222) << "  ";
				SetColor(14); cout << setw(3) << "PHAI";
				SetColor(11); cout << "  " << char(222);
				SetColor(14); cout << setw(9) << "SDT" << endl;
				SetColor(11);
				for (int j = 0; j < 73; j++)
				{
					gotoXY(76 + j, 10);
					cout << char(220);
				}
				int kc_dong = 0;
				int k = 0;
				// duyệt để xuất ra danh sách sinh viên của lớp đó
				for (int j = 0; j < sl_sv; j++)
				{
					if (_stricmp(ds_sv[j].Ma_Lop.c_str(), ma_lop_xuat_ds_lop.c_str()) == 0)
					{
						gotoXY(76, 11 + k + kc_dong);
						SetColor(15); cout << "  " << setw(9) << ds_sv[j].ma_sv;
						SetColor(11); cout << "   " << char(222);
						string hoten = ds_sv[j].ho + " " + ds_sv[j].ten;
						SetColor(15); cout << "  " << setw(26) << hoten;
						SetColor(11); cout << "       " << char(222);
						SetColor(15); cout << "  " << setw(3) << ds_sv[j].phai;
						SetColor(11); cout << "   " << char(222) << "  ";
						SetColor(15); cout << " " << setw(2) << ds_sv[j].SO_DT;
						kc_dong++;
						SetColor(11);

						// vẽ đường kẻ
						for (int g = 0; g < 73; g++)
						{
								gotoXY(76 + g, 11 + k + kc_dong);
								cout << char(220);
						}
						k++;
					}
				}
				// xoá dòng kẻ cuối
				for (int g = 0; g < 73; g++)
				{
					gotoXY(76 + g, 11 + k - 1 + kc_dong);
					cout << " ";
				}
			}
			else if (c == 27) //esc
			{
				SetConsoleTextAttribute(hConsoleColor, 0);
				break;
			}
		}
	}
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

void giao_dien_xoa_sinh_vien(Sinh_Vien ds_sv[],int &sl_sv, int &cong_tac_dau_nhay)
{
	gotoXY(80, 21);
	SetColor(11);
	cout << "NHAP MA SINH VIEN CAN XOA:";
	box(120, 20, 15, 2, 14, 0, "");
	cong_tac_dau_nhay = 0;
	string ma_sv_xoa;
	bool exit_ = true;
	while (exit_)
	{
		char c = _getch();
		if (c != -32 && c != 72 && c != 80 && c != 75 && c != 77 && c != 13 && c != 8 && c != 27)
		{
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 32)
			{
				gotoXY(85, 22);
				cout << "                         ";
				ma_sv_xoa.push_back(c);
			}
		}
		else if (c == 27) // esc
		{
			exit_ = false;
		}
		else if (c == 8) // backspace
		{
			if (!ma_sv_xoa.empty())
			{
				gotoXY(85, 22);
				cout << "                         ";
				ma_sv_xoa.pop_back();
			}
		}
		else if (c == 13) // enter
		{
			// mã sinh viên không tồn tại
			if (kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_xoa) == -1)
			{
				SetColor(12);
				gotoXY(85, 22);
				cout << "Ma mon hoc khong ton tai!";
			}
			else
			{
				box(120, 20, 15, 2, 11, 0, ma_sv_xoa);
				// tắt ô sáng cũ
				int x_sang_con = 75;
				// ô sáng đầu tiên
				box(75, 30, 3, 2, 14, 70, "OK");
				// box huỷ
				box(124, 30, 7, 2, 11, 0, "CANCEL");
				while (true)
				{
					char c_con = _getch();
					if (c_con == -32)
					{
						char c_con_con = _getch();
						if (c_con_con == 75) // samg trái
						{
							if (x_sang_con > 75)
							{
								// tắt thanh sáng cũ
								box(124, 30, 7, 2, 11, 0, "CANCEL");
								x_sang_con -= 49;
								// bật thanh sáng mới
								box(75, 30, 3, 2, 14, 70, "OK");
							}
						}
						else if (c_con_con == 77) // sang phải
						{
							if (x_sang_con < 124)
							{
								// tắt thanh sáng cũ
								box(75, 30, 3, 2, 11, 70, "OK");
								x_sang_con += 49;
								// bật thanh sáng mới
								box(124, 30, 7, 2, 14, 0, "CANCEL");
							}
						}
					}
					else if (c_con == 13) // enter
					{
						if (x_sang_con == 124) // huỷ lênh xoá
						{
							exit_ = false;
							break;
						}
						else if (x_sang_con == 75) // thực hiện lệnh xoá
						{
							
							if (sl_sv == 1)
							{
								sl_sv--;
								return;
							}
							else if(sl_sv > 1)
							{
								for (int i = kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_xoa); i < sl_sv - 1; i++)
								{
									ds_sv[i] = ds_sv[i + 1];
								}
								sl_sv--;
							}
							
							exit_ = false;
							break;
						}
					}
				}
			}
		}
		box(120, 20, 15, 2, 14, 0, ma_sv_xoa);
	}
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

void giao_dien_hieu_chinh_sinh_vien(Sinh_Vien ds_sv[],int sl_sv, int &cong_tac_dau_nhay)
{
	gotoXY(80, 21);
	SetColor(11);
	cout << "NHAP MA SINH VIEN MUON CAP NHAT:";

	box(120, 20, 15, 2, 14, 0, "");
	cong_tac_dau_nhay = 0;
	string ma_sv_cap_nhat;
	bool thoat = true;
	while (thoat)
	{
		char c = _getch();
		if (c != -32 && c != 72 && c != 80 && c != 75 && c != 77 && c != 13 && c != 8)
		{
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 32)
			{
				gotoXY(85, 22);
				cout << "                         ";
				ma_sv_cap_nhat.push_back(c);
			}
		}
		else if (c == 27) // esc
		{
			break;
		}
		else if (c == 8) // backspace
		{
			if (!ma_sv_cap_nhat.empty())
			{
				gotoXY(85, 22);
				cout << "                             ";
				ma_sv_cap_nhat.pop_back();
			}
		}
		else if (c == 13) // enter
		{
			if (kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_cap_nhat) == -1)
			{
				SetColor(12);
				gotoXY(85, 22);
				cout << "Ma mon hoc khong ton tai!";
			}
			else
			{
				// ------------------------ cho xem thông tin cũ của sinh viên ------------------------
				// xuất tiêu đề
				xoa_giao_dien_mo_lop_tin_chi();
				
				SetColor(14);
				box(74, 8, 76, 5, 11, 0, "");
				gotoXY(90, 5);
				cout << "=========== THONG TIN SINH VIEN ===========";

				gotoXY(76, 9);
				SetColor(14); cout << setw(9) << "MA SINH VIEN";
				textcolor(0);
				SetColor(11); cout << "  " << char(222);
				SetColor(14); cout << setw(26) << "HO VA TEN" << "         ";
				SetColor(11); cout << char(222) << "  ";
				SetColor(14); cout << setw(3) << "PHAI";
				SetColor(11); cout << "  " << char(222);
				SetColor(14); cout << setw(9) << "SDT" << endl;
				SetColor(11);
				for (int j = 0; j < 73; j++)
				{
					gotoXY(76 + j, 10);
					cout << char(220);
				}
				gotoXY(76, 11);
				SetColor(15); cout << "  " << setw(9) << ds_sv[kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_cap_nhat)].ma_sv;
				SetColor(11); cout << "   " << char(222);
				string hoten = ds_sv[kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_cap_nhat)].ho + " " + ds_sv[kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_cap_nhat)].ten;
				SetColor(15); cout << "  " << setw(26) << hoten;
				SetColor(11); cout << "       " << char(222);
				SetColor(15); cout << "  " << setw(3) << ds_sv[kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_cap_nhat)].phai;
				SetColor(11); cout << "   " << char(222) << "  ";
				SetColor(15); cout << " " << setw(2) << ds_sv[kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_cap_nhat)].SO_DT;

				// ----------------------------- hiệu chỉnh thônh tin sinh viên -----------------------------
				box(74, 14, 76, 27, 11, 0, "");

				SetColor(11);
				gotoXY(90, 15);
				cout << "=========== HIEU CHINH SINH VIEN ===========";

				SetColor(11);
				gotoXY(85, 21);
				cout << "HO:";                     // ô sáng đầu tiên
				box(100, 20, 29, 2, 14, 0, "");

				SetColor(11);
				gotoXY(85, 25);
				cout << "TEN:";
				box(100, 24, 29, 2, 11, 0, "");

				gotoXY(85, 29);
				cout << "PHAI:";
				box(100, 28, 29, 2, 11, 0, "");

				gotoXY(85, 33);
				cout << "SDT:";
				box(100, 32, 29, 2, 11, 0, "");

				box(84, 36, 5, 2, 11, 42, "THEM");

				box(125, 36, 4, 2, 11, 64, "HUY");

				int x_sang = 84, y_sang = 20; // toạ độ thanh sáng
				string tt_1_sv[4];
				bool thoat_trong = true;
				while (thoat_trong)
				{
					char c = _getch();
					if (c == 13) // enter
					{
						if (y_sang == 36 && x_sang == 84) // thêm
						{
							int check = 0;
							if (!tt_1_sv[0].empty())
							{
								for (int j = 0; j < tt_1_sv[0].length(); j++)
								{
									if (!((tt_1_sv[0].at(j) >= 65 && tt_1_sv[0].at(j) <= 90) || (tt_1_sv[0].at(j) >= 97 && tt_1_sv[0].at(j) <= 122) || tt_1_sv[0].at(j) == ' '))
									{
										gotoXY(100, 23);
										SetColor(12);
										cout << "Khong duoc nhap ki tu dac biet hoac so!";
										box(100, 20, 29, 2, 12, 0, tt_1_sv[0]);
										check = 1;
										break;
									}
								}

							}
							if (!tt_1_sv[1].empty())
							{
								for (int j = 0; j < tt_1_sv[1].length(); j++)
								{
									if (!((tt_1_sv[1].at(j) >= 65 && tt_1_sv[1].at(j) <= 90) || (tt_1_sv[1].at(j) >= 97 && tt_1_sv[1].at(j) <= 122) || tt_1_sv[1].at(j) == ' '))
									{
										gotoXY(100, 27);
										SetColor(12);
										cout << "Khong duoc nhap ki tu dac biet hoac so!";
										box(100, 24, 29, 2, 12, 0, tt_1_sv[1]);
										check = 1;
										break;
									}
								}

							}
							if (!tt_1_sv[2].empty())
							{
								for (int j = 0; j < tt_1_sv[2].length(); j++)
								{
									if (!((tt_1_sv[2].at(j) >= 65 && tt_1_sv[2].at(j) <= 90) || (tt_1_sv[2].at(j) >= 97 && tt_1_sv[2].at(j) <= 122)))
									{
										gotoXY(100, 31);
										SetColor(12);
										cout << "Khong duoc nhap ki tu dac biet hoac so!";
										box(100, 28, 29, 2, 12, 0, tt_1_sv[2]);
										check = 1;
										break;
									}
								}

							}
							
							if (!tt_1_sv[3].empty())
							{
								for (int j = 0; j < tt_1_sv[3].length(); j++)
								{
									if ((tt_1_sv[3].at(j) >= 65 && tt_1_sv[3].at(j) <= 90) || (tt_1_sv[3].at(j) >= 97 && tt_1_sv[3].at(j) <= 122))
									{
										gotoXY(100, 35);
										SetColor(12);
										cout << "Khong duoc nhap ki tu o trong SDT!";
										box(100, 32, 29, 2, 12, 0, tt_1_sv[3]);
										check = 1;
										break;
									}
								}
							}
							if (check == 0)
							{
								gotoXY(96, 37);
								SetColor(10);
								cout << "Nhan enter de huy";
								gotoXY(96, 38);
								cout << "Nhan esc de huy thao tac";
								while (true)
								{
									c = _getch();
									if (c == 27)
									{
										break;
									}
									else if (c == 13)
									{							
										if (!tt_1_sv[0].empty())
										{
											chuan_hoa_chu(tt_1_sv[0]);
											ds_sv[kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_cap_nhat)].ho = tt_1_sv[0];
										}
										if (!tt_1_sv[1].empty())
										{
											chuan_hoa_chu(tt_1_sv[1]);
											ds_sv[kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_cap_nhat)].ten = tt_1_sv[1];
										}
										if (!tt_1_sv[2].empty())
										{
											ds_sv[kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_cap_nhat)].phai = tt_1_sv[2];
										}
										if (!tt_1_sv[3].empty())
										{
											ds_sv[kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_cap_nhat)].SO_DT = tt_1_sv[3];
										}
										thoat = false;
										thoat_trong = false;
										break;
									}
								}
							}
						}
						else if (y_sang == 36 && x_sang == 125) // huỷ
						{
							gotoXY(96, 37);
							SetColor(10);
							cout << "Nhan enter de huy";
							gotoXY(96, 38);
							cout << "Nhan esc de huy thao tac";
							while (true)
							{
								c = _getch();
								if (c == 27)
								{
									break;
								}
								else if (c == 13)
								{
									thoat = false;
									thoat_trong = false;
									break;
								}
							}
						}
					}
					else if (c == 8) // xoá kí tự
					{
						if (y_sang == 20 && !tt_1_sv[0].empty())
						{
							tt_1_sv[0].pop_back();
							box(100, 20, 29, 2, 14, 0, tt_1_sv[0]);
						}
						else if (y_sang == 24 && !tt_1_sv[1].empty())
						{
							tt_1_sv[1].pop_back();
							box(100, 24, 29, 2, 14, 0, tt_1_sv[1]);
						}
						else if (y_sang == 28 && !tt_1_sv[2].empty())
						{
							tt_1_sv[2].pop_back();
							box(100, 28, 29, 2, 14, 0, tt_1_sv[2]);
						}
						else if (y_sang == 32 && !tt_1_sv[3].empty())
						{
							tt_1_sv[3].pop_back();
							box(100, 32, 29, 2, 14, 0, tt_1_sv[3]);
						}
					}
					// nhập kí tự
					else if (c != -32 && c != 72 && c != 80 && c != 75 && c != 77 && c != 8)
					{
						if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 32)
						{
							if (y_sang == 20)
							{
								tt_1_sv[0].push_back(c);
								box(100, 20, 29, 2, 14, 0, tt_1_sv[0]);
							}
							else if (y_sang == 24)
							{
								tt_1_sv[1].push_back(c);
								box(100, 24, 29, 2, 14, 0, tt_1_sv[1]);
							}
							else if (y_sang == 28)
							{
								tt_1_sv[2].push_back(c);
								box(100, 28, 29, 2, 14, 0, tt_1_sv[2]);
							}
							else if (y_sang == 32)
							{
								tt_1_sv[3].push_back(c);
								box(100, 32, 29, 2, 14, 0, tt_1_sv[3]);
							}
						}
					}
					// di chuyển
					else if (c == -32)
					{
						c = _getch();
						if (c == 80) // xuống
						{
							if (y_sang < 36)
							{
								// tắt thanh sáng
								if (y_sang == 20)
								{
									box(100, 20, 29, 2, 11, 0, tt_1_sv[0]);
								}
								else if (y_sang == 24)
								{
									box(100, 24, 29, 2, 11, 0, tt_1_sv[1]);
								}
								else if (y_sang == 28)
								{
									box(100, 28, 29, 2, 11, 0, tt_1_sv[2]);
								}
								else if (y_sang == 32)
								{
									box(100, 32, 29, 2, 11, 0, tt_1_sv[3]);
								}
								y_sang += 4;
								// bật thanh sáng mới
								if (y_sang == 24)
								{
									box(100, 24, 29, 2, 14, 0, tt_1_sv[1]);
								}
								else if (y_sang == 28)
								{
									box(100, 28, 29, 2, 14, 0, tt_1_sv[2]);
								}
								else if (y_sang == 32)
								{
									box(100, 32, 29, 2, 14, 0, tt_1_sv[3]);
								}
								else if (y_sang == 36)
								{
									box(84, 36, 5, 2, 14, 42, "THEM");
								}
							}
						}
						else if (c == 72) // lên
						{
							if (y_sang > 20)
							{
								// tắt thanh sáng
								if (y_sang == 24)
								{
									box(100, 24, 29, 2, 11, 0, tt_1_sv[1]);
								}
								else if (y_sang == 28)
								{
									box(100, 28, 29, 2, 11, 0, tt_1_sv[2]);
								}
								else if (y_sang == 32)
								{
									box(100, 32, 29, 2, 11, 0, tt_1_sv[3]);
								}
								else if (y_sang == 36)
								{
									//                    ----------     xoá thông báo ----------
									gotoXY(96, 37);
									cout << "                             ";
									gotoXY(100, 23);
									cout << "                                       ";
									gotoXY(100, 27);
									cout << "                                        ";
									gotoXY(100, 31);
									cout << "                                           ";
									gotoXY(100, 35);
									cout << "                                             ";

									// tắt thanh sáng cũ
									box(84, 36, 5, 2, 11, 42, "THEM");
									box(125, 36, 4, 2, 11, 64, "HUY");
									x_sang = 84;
								}
								y_sang -= 4;
								// bật thanh sáng mới
								if (y_sang == 20)
								{
									box(100, 20, 29, 2, 14, 0, tt_1_sv[0]);
								}
								if (y_sang == 24)
								{
									box(100, 24, 29, 2, 14, 0, tt_1_sv[1]);
								}
								else if (y_sang == 28)
								{
									box(100, 28, 29, 2, 14, 0, tt_1_sv[2]);
								}
								else if (y_sang == 32)
								{
									box(100, 32, 29, 2, 14, 0, tt_1_sv[3]);
								}
							}
						}
						else if (c == 77) // phải
						{
							if (y_sang == 36)
							{
								if (x_sang == 84)
								{
									// tắt thanh sáng cũ
									box(84, 36, 5, 2, 11, 42, "THEM");
									x_sang += 41;
									// bật thanh sáng mới
									box(125, 36, 4, 2, 14, 64, "HUY");
								}
							}
						}
						else if (c == 75) // trái
						{
							if (y_sang == 36)
							{
								if (x_sang == 125)
								{
									// tắt thanh sáng cũ
									box(125, 36, 4, 2, 11, 64, "HUY");
									x_sang -= 41;
									// bật thanh sáng mới
									box(84, 36, 5, 2, 14, 42, "THEM");
								}
							}
						}
					}
				}
			}
		}
		box(120, 20, 15, 2, 14, 0, ma_sv_cap_nhat);
	}
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

// ================================ MENU CON ĐĂNG KÝ TÍN CHỈ ================================
void menu_con_dang_ky_tin_chi(Sinh_Vien ds_sv[], int &sl_sv, DS_LOP_TIN_CHI &ds_lop_tc,DANH_SACH_MON_HOC &ds_mh)
{
	SetColor(11);
	gotoXY(7, 15);
	cout << "1. Dang ky tin chi mot lop";
	gotoXY(7, 16);
	cout << "2. Dang ky tin chi mot sinh vien";
	gotoXY(7, 17);
	cout << "3. Danh sach sinh vien dang ky tin chi";
	gotoXY(7, 18);
	cout << "4. Huy dang ky hoc phan mot lop";
	gotoXY(7, 19);
	cout << "5. Huy dang ky hoc phan mot sinh vien";
	gotoXY(7, 20);
	cout << "6. Thoat";

	int x_sang = 7;
	int y_sang = 15;
	// ------- hiện thanh sáng
	m.lock();
	gotoXY(x_sang, y_sang);
	textcolor(70);
	cout << "                          ";
	gotoXY(x_sang, y_sang);
	SetColor(11);
	cout << "1. Dang ky tin chi mot lop";
	textcolor(0);
	m.unlock();
	// -------------- di chuyển của menu con
	int cong_tac_dau_nhay = 0; // CÔNG TẮC KHI NHẤN PHÍM ENTER
	while (77)
	{
		// ============================ khi mà xử lí lệnh đăng kí tín chỉ 1 lớp thì không thể sử dụng tính năng đăng kí tín chỉ sinh viên và ngược lai ============================
		// ------------------ xử lí lệnh đăng kí tín chỉ 1 lớp
		if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 15)
		{
			giao_dien_dang_ky_tin_chi_1_lop(cong_tac_dau_nhay, ds_sv, sl_sv, ds_lop_tc, ds_mh);
		}
		// ------------------ xử lí lệnh đăng kí tín chỉ sinh viên
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 16)
		{
			giao_dien_dang_ky_tin_chi_1_sinh_vien(cong_tac_dau_nhay, ds_sv, sl_sv, ds_lop_tc, ds_mh);
		}
		// ------------------- Danh sach sinh vien dang ky tin chi
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 17)
		{
			giao_dien_xem_ds_sv_con_dk_tin_chi_main(ds_mh, ds_lop_tc, ds_sv, sl_sv, cong_tac_dau_nhay);
		}
		// ------------------- Huy dang ky hoc phan mot lop
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 18)
		{
			giao_dien_huy_dang_ky_1_lop(ds_lop_tc, ds_sv, sl_sv, ds_mh, cong_tac_dau_nhay);
		}
		// ------------------- Huy dang ky hoc phan mot sinh vien
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 19)
		{
			giao_dien_huy_dky_hoc_phan_1_sv(ds_lop_tc, ds_sv, sl_sv, ds_mh, cong_tac_dau_nhay);
		}
		// ------------------- Thoat
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 20)
		{
			break;
		}
		// menu nhỏ ======================= LUỒNG  CHÍNH CỦA MENU NHỎ
		char c = _getch();
		// đã nhấn phím enter
		if (c == 13)
		{
			
			if (x_sang == 7 && y_sang == 15 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			
			else if (x_sang == 7 && y_sang == 16 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 17 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 18 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 19 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 20 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
		}
		if (cong_tac_dau_nhay == 0)
		{
			if (c == -32)
			{
				c = _getch();
				if (c == 72) // đi lên
				{
					if (y_sang > 15)
					{
						int y_cu = y_sang;

						// xóa thanh sang sáng cũ
						if (x_sang == 7 && y_cu == 16)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(0);
							cout << "                                ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "2. Dang ky tin chi mot sinh vien";
							m.unlock();
						}
					
						else if (x_sang == 7 && y_cu == 17)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(0);
							cout << "                                      ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "3. Danh sach sinh vien dang ky tin chi";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 18)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(0);
							cout << "                               ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "4. Huy dang ky hoc phan mot lop";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 19)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(0);
							cout << "                                     ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "5. Huy dang ky hoc phan mot sinh vien";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 20)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(0);
							cout << "        ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "6. Thoat";
							m.unlock();
						}
						y_sang--;
						// hiển thị lại thanh sáng mới
						if (x_sang == 7 && y_sang == 15)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                          ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "1. Dang ky tin chi mot lop";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 16)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                                ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "2. Dang ky tin chi mot sinh vien";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 17)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                                      ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "3. Danh sach sinh vien dang ky tin chi";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 18)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                               ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "4. Huy dang ky hoc phan mot lop";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 19)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                                     ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "5. Huy dang ky hoc phan mot sinh vien";
							textcolor(0);
							m.unlock();
						}
					}
				}
				else if (c == 80) // đi xuống
				{
					if (y_sang < 20)
					{
						int y_cu = y_sang;
						// xóa thanh sang sáng cũ
						if (x_sang == 7 && y_cu == 15)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                          ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "1. Dang ky tin chi mot lop";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 16)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                                ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "2. Dang ky tin chi mot sinh vien";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 17)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                                      ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "3. Danh sach sinh vien dang ky tin chi";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 18)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                               ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "4. Huy dang ky hoc phan mot lop";
							
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 19)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                                     ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "5. Huy dang ky hoc phan mot sinh vien";
							
							m.unlock();
						}
						y_sang++;
						// hiện thanh sáng mới
						if (x_sang == 7 && y_sang == 16)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                                ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "2. Dang ky tin chi mot sinh vien";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 17)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                                      ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "3. Danh sach sinh vien dang ky tin chi";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 18)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                               ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "4. Huy dang ky hoc phan mot lop";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 19)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                                     ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "5. Huy dang ky hoc phan mot sinh vien";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 20)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "        ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "6. Thoat";
							textcolor(0);
							m.unlock();
						}
					}
				}
			}
		}

	}
}
// ------------------------------------ ĐĂNG KÝ TÍN CHỈ ------------------------------------
void giao_dien_dang_ky_tin_chi_1_lop(int &cong_tac_dau_nhay, Sinh_Vien ds_sv[], int &sl_sv, DS_LOP_TIN_CHI &ds_lop_tc, DANH_SACH_MON_HOC &ds_mh)
{
	// b1------------------- nhập mã lớp -------------------
	SetColor(11);
	gotoXY(81, 15);
	cout << "NHAP MA LOP:";
	box(100, 14, 18, 2, 14, 0, "");
	vector<string> ds_ma_sv;
	string ma_lop_input;
	while (77)
	{
		char c = _getch();
		if (c != -32 && c != 72 && c != 80 && c != 75 && c != 77 && c != 8 && c != 13 && c != 27)
		{
			gotoXY(84, 16);
			cout << "                     ";
			ma_lop_input.push_back(c);
		}
		else if (c == 27)
		{
			return;
		}
		else if (c == 8 && !ma_lop_input.empty())
		{
			gotoXY(84, 16);
			cout << "                     ";
			ma_lop_input.pop_back();
		}
		else if (c == 13)
		{
			// duyệt qua danh sách sinh viên kiểm tra mã lớp đó có tồn tại hay không
			
				int check_malop = 0;
				for(int i = 0; i < sl_sv;i++)
				{
					if(_stricmp(ds_sv[i].Ma_Lop.c_str(),ma_lop_input.c_str()) == 0)
					{
						check_malop = 1;
						ds_ma_sv.push_back(ds_sv[i].ma_sv);
					}
				}

				if(check_malop == 0)
				{
					gotoXY(84,16);
					SetColor(12);
					cout <<  "Ma lop khong ton tai!";
				}
				else
				{
					break;
				}
		}
		box(100, 14, 18, 2, 14, 0, ma_lop_input);
	}
	// lấy ra 1 mã sinh viên của lớp đó
	

	// b1------------------- nhập niên khoá học kỳ -------------------
	SetColor(11);
	gotoXY(81, 15); // --------------------- ô sáng đầu tiên ---------------------
	cout << "NHAP NIEN KHOA:";
	box(100, 14, 18, 2, 14, 0, "");

	SetColor(11);
	gotoXY(81, 19);
	cout << "NHAP HOC KY:";
	box(100, 18, 18, 2, 11, 0, "");

	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 177);
	gotoXY(95, 22);
	cout << "          ";
	gotoXY(95, 23);
	cout << " TRUY CAP ";
	gotoXY(95, 24);
	cout << "          ";

	string nk_hk[2];
	int y_sang_nk_hk = 14;

	while (77)
	{
		char c = _getch();
		if (c >= 47 && c <= 57)
		{
			if (y_sang_nk_hk == 14)
			{
				nk_hk[0].push_back(c);
				box(100, 14, 18, 2, 14, 0, nk_hk[0]);
			}
			else if (y_sang_nk_hk == 18)
			{
				nk_hk[1].push_back(c);
				box(100, 18, 18, 2, 14, 0, nk_hk[1]);
			}
		}
		else if (c == 13) // enter
		{
			if (y_sang_nk_hk == 22)
			{
				SetConsoleTextAttribute(hConsoleColor, 0);
				xoa_giao_dien_mo_lop_tin_chi();
				// in danh sách các lớp tín chỉ đuọc mở theo niên khoá và học kỳ
				break;
			}
		}
		else if (c == 8)
		{
			if (y_sang_nk_hk == 14 && !nk_hk[0].empty())
			{
				nk_hk[0].pop_back();
				box(100, 14, 18, 2, 14, 0, nk_hk[0]);
			}
			else if (y_sang_nk_hk == 18 && !nk_hk[1].empty())
			{
				nk_hk[1].pop_back();
				box(100, 18, 18, 2, 14, 0, nk_hk[1]);
			}
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 72) // lên
			{
				if (y_sang_nk_hk > 14)
				{
					if (y_sang_nk_hk == 18)
					{
						// tắt thanh sáng cũ
						box(100, 18, 18, 2, 11, 0, nk_hk[1]);
						y_sang_nk_hk -= 4;
						// bật thanh sáng mới
						box(100, 14, 18, 2, 14, 0, nk_hk[0]);
					}
					if (y_sang_nk_hk == 22)
					{
						// tắt thanh sáng cũ
						SetConsoleTextAttribute(hConsoleColor, 177);
						gotoXY(95, 22);
						cout << "          ";
						gotoXY(95, 23);
						cout << " TRUY CAP ";
						gotoXY(95, 24);
						cout << "          ";
						y_sang_nk_hk -= 4;
						// bật thanh sáng mới
						box(100, 18, 18, 2, 14, 0, nk_hk[1]);
					}
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang_nk_hk < 22)
				{
					// tắt thanh sáng cũ
					if (y_sang_nk_hk == 14)
					{
						box(100, 14, 18, 2, 11, 0, nk_hk[0]);
						y_sang_nk_hk += 4;
						// bật thanh sáng mới
						box(100, 18, 18, 2, 14, 0, nk_hk[1]);
					}
					else if (y_sang_nk_hk == 18)
					{
						// tắt thanh sáng cũ
						box(100, 18, 18, 2, 11, 0, nk_hk[1]);
						y_sang_nk_hk += 4;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 233);
						gotoXY(95, 22);
						cout << "          ";
						gotoXY(95, 23);
						cout << " TRUY CAP ";
						gotoXY(95, 24);
						cout << "          ";
					}
				}
			}
		}
	}
	// in danh sách các lớp tín chỉ đuọc mở theo niên khoá và học kỳ
	giao_dien_xuat_ds_lop_tc_theo_nk_hk(ds_lop_tc, atoi(nk_hk[0].c_str()), atoi(nk_hk[1].c_str()), ds_mh,ds_ma_sv);
	SetConsoleTextAttribute(hConsoleColor, 0);
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

void giao_dien_xuat_ds_lop_tc_theo_nk_hk(DS_LOP_TIN_CHI &ds_lop_tc, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh,vector<string> ds_ma_sv)
{
	gotoXY(93, 5);
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << char(17);
	SetConsoleTextAttribute(hConsoleColor, 225);
	cout << " " << "NIEN KHOA: " << nien_khoa << " - HOC KY: " << hoc_ky << " ";
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << char(16);
	SetConsoleTextAttribute(hConsoleColor, 9);
	gotoXY(87, 6);
	gotoXY(62, 8);
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << "Chon" << "     " << setw(2) << "Ma LTC " << "    " << setw(18) << "Ten mon hoc" << "              " << setw(2) << "Nhom" << "     " << setw(2) << "Si so da dang ky" << "     " << setw(2) << "Slot con trong";
	// vẽ đường kẻ
	for (int i = 0; i < 98; i++)
	{
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoXY(61 + i, 9);
		cout << char(196);
	}
	int g = 0;
	int sl_lop_tc_ = ds_lop_tc.sl; // biến dùng để đếm các lớp tín chỉ chưa đăng ký
	while (66)
	{
		// duyệt để xuất danh sách ra thông tin các lớp để đăng kí
		// tạo biến đếm để đếm xem bao nhiêu lớp học phần đã mở
		string ds_ma_ltc[15];
		int sl_lop_tc_da_xuat = 0;
		int dem = 0;
		for (; g < ds_lop_tc.sl; g++)
		{
			if (ds_lop_tc.Lop_Tin_Chi[g]->nien_khoa == nien_khoa && ds_lop_tc.Lop_Tin_Chi[g]->hoc_ky == hoc_ky && ds_lop_tc.Lop_Tin_Chi[g]->trang_thai_lop == 1 && kt_lop_tc_sv_dk(ds_lop_tc.Lop_Tin_Chi[g]->DS_SV_DANG_KY_TIN_CHI,ds_ma_sv[0]) != -1)
			{
				
				gotoXY(73, 11 + dem * 4);
				ds_ma_ltc[sl_lop_tc_da_xuat].insert(0, to_string(ds_lop_tc.Lop_Tin_Chi[g]->maLopTinCHi));
				sl_lop_tc_da_xuat++;

				SetConsoleTextAttribute(hConsoleColor, 11);
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->maLopTinCHi << "    ";
				Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds_lop_tc.Lop_Tin_Chi[g]->ma_mh);
				cout << setw(27) << p->data.ten_mh << "        ";
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->nhom << "            ";
				int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_lop_tc.Lop_Tin_Chi[g]->DS_SV_DANG_KY_TIN_CHI);
				cout << setw(2) << sl_sv_con_dang_ky << "                   ";
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->so_sv_max - sl_sv_con_dang_ky;

				// vẽ đường kẻ
				if (dem % 6 != 0 || dem == 0)
				{
					if (g != ds_lop_tc.sl - 1)
					{
						for (int j = 0; j < 98; j++)
						{
							SetConsoleTextAttribute(hConsoleColor, 7);
							gotoXY(61 + j, 13 + (dem * 4));
							cout << char(196);
						}
					}
				}	
				dem++;
				// --------------- nếu xuất đủ 7 lớp tín chỉ thì dừng
				if (dem % 7 == 0)
				{
					break;
				}
			}
		}

		// vẽ hộp chọn
		for (int j = 0; j < dem; j++)
		{
			if (j == 0)
			{
				SetConsoleTextAttribute(hConsoleColor, 172);
				gotoXY(63, 11);
				cout << char(2);
			}
			else
			{
				SetConsoleTextAttribute(hConsoleColor, 2);
				gotoXY(63, 11 + (j * 4));
				cout << char(1);
			}
		}
		// di chuyển
		int y_sang_chon_lop = 11;
		int vt_sang = 0;
		while (77)
		{
			char c = _getch();
			if (c == 27) // esc
			{
				return;
			}
			else if (c == 72) // lên
			{
				if (y_sang_chon_lop > 11)
				{
					// tắt thanh sáng cũ
					SetConsoleTextAttribute(hConsoleColor, 2);
					gotoXY(62, 39);
					cout << "                                             ";
					gotoXY(63, y_sang_chon_lop);
					cout << char(1);
					y_sang_chon_lop -= 4;
					vt_sang--;
					// bật thanh sáng mới
					SetConsoleTextAttribute(hConsoleColor, 172);
					gotoXY(63, y_sang_chon_lop);
					cout << char(2);
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang_chon_lop < 11 + (dem - 1) * 4)
				{
					
					// tắt thanh sáng cũ
					SetConsoleTextAttribute(hConsoleColor, 2);
					gotoXY(62, 39);
					cout << "                                             ";
					gotoXY(63, y_sang_chon_lop);
					cout << char(1);
					y_sang_chon_lop += 4;
					vt_sang++;
					// bật thanh sáng mới
					SetConsoleTextAttribute(hConsoleColor, 172);
					gotoXY(63, y_sang_chon_lop);
					cout << char(2);
				}
			}
			else if (c == 13) // enter
			{
						// lấy ra mã lớp tín chỉ đăng kí của lớp đó dựa vào vt_sang
						int ma_lop_dk = atoi(ds_ma_ltc[vt_sang].c_str());
						int vt = kt_ma_lop_tc_theo_hoc_ky_nien_khoa(ds_lop_tc, nien_khoa, hoc_ky, ma_lop_dk, ds_ma_sv[0]);
						if (so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_lop_tc.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI) == ds_lop_tc.Lop_Tin_Chi[vt]->so_sv_max)
						{
							SetConsoleTextAttribute(hConsoleColor, 12);
							gotoXY(62, 39);
							cout << "Lop nay da du sinh vien!";
						}
						else if (ds_ma_sv.size() > ds_lop_tc.Lop_Tin_Chi[vt]->so_sv_max || ds_lop_tc.Lop_Tin_Chi[vt]->so_sv_max - so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_lop_tc.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI) < ds_ma_sv.size())
						{
							SetConsoleTextAttribute(hConsoleColor, 12);
							gotoXY(62, 39);
							cout << "So luong sinh vien dang ky vuot qua gioi han!";
						}
						else
						{
							for (int k = 0; k < ds_ma_sv.size(); k++)
							{
								SINH_VIEN_DANG_KY_TIN_CHI x;
								viet_hoa_ma_lop(ds_ma_sv[k]);
								x.ma_sv = ds_ma_sv[k];
								x.trang_thai_dang_ky = 1;
								x.diem = NULL;
								NODE_SV_DANG_KY_TIN_CHI *p = khoiTaoNode_sv_dk_tin_chi(x);
								ThemNode_sv_dk_tin_chi(ds_lop_tc.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI, p);
								ds_lop_tc.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.sl++; // ghi bên file không chạm vào
							}
							SetConsoleTextAttribute(hConsoleColor, 10);
							gotoXY(62, 39);
							cout << "DA DANG KY";
							sl_lop_tc_--;
							g = 0;
							while (66)
							{
								SetConsoleTextAttribute(hConsoleColor, 9);
								gotoXY(62, 41);
								cout << "Nhan phim bat ky de refesh lai trang";
								char c_con = _getch();
								if (c_con)
								{
									break;
								}
							}
							xoa_mot_trang_dk_tin_chi();
							break;
						}
				///// ->  sai
				// xuất chữ đã đăng kí 
				/*gotoXY(56, y_sang_chon_lop);
				SetConsoleTextAttribute(hConsoleColor, 164);
				cout << " DK ";*/
			}
			else if (c == 77) // sang phải
			{
				// nếu  trang đã xuất đủ 7 tín chỉ thì sang trang 2
				if (dem % 7 == 0 && sl_lop_tc_ > 7)
				{
					g++;
					SetConsoleTextAttribute(hConsoleColor, 0);
					xoa_mot_trang_dk_tin_chi();
					break;
				}
			}
			else if (c == 75) // sang trái
			{
				// nếu  trang đã xuất đủ 7 tín chỉ thì sang trang 2
				if (dem < 7 || dem  % 7 == 0 && sl_lop_tc_ < 7)
				{
					SetConsoleTextAttribute(hConsoleColor, 0);
					xoa_mot_trang_dk_tin_chi();
					g = 0;
					break;
				}
			}
		}
	}
}

int kt_lop_tc_sv_dk(DSSV_DANG_KY_TIN_CHI ds, string ma_sv)
{
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds.pHead; k != NULL; k = k->pNext)
	{
		if (_stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0 && k->data.trang_thai_dang_ky == 1)
		{
			return -1;
		}
	}
	return 1;
}

void xoa_mot_trang_dk_tin_chi()
{
	for (int i = 11; i <= 41; i++)
	{
		for (int j = 61; j <= 159; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}

void giao_dien_dang_ky_tin_chi_1_sinh_vien(int &cong_tac_dau_nhay, Sinh_Vien ds_sv[], int &sl_sv, DS_LOP_TIN_CHI &ds_lop_tc, DANH_SACH_MON_HOC &ds_mh)
{
	// b1------------------- nhập mã lớp -------------------
	SetColor(11);
	gotoXY(81, 15);
	cout << "NHAP MA SINH VIEN:";
	box(100, 14, 18, 2, 14, 0, "");
	string ma_sv_input;
	while (77)
	{
		char c = _getch();
		if (c != -32 && c != 72 && c != 80 && c != 75 && c != 77 && c != 8 && c != 13 && c != 27)
		{
			gotoXY(84, 17);
			cout << "                           ";
			ma_sv_input.push_back(c);
		}
		else if (c == 8 && !ma_sv_input.empty())
		{
			gotoXY(84, 17);
			cout << "                           ";
			ma_sv_input.pop_back();
		}
		else if (c == 13)
		{
			// duyệt qua danh sách sinh viên kiểm tra mã lớp đó có tồn tại hay không
			if (kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_input) == -1)
			{
				gotoXY(84, 17);
				SetColor(12);
				cout << "Ma sinh vien khong ton tai!";
			}
			else
			{
				break;
			}
		}
		box(100, 14, 18, 2, 14, 0, ma_sv_input);
	}
	// lấy ra 1 mã sinh viên của lớp đó


	// b1------------------- nhập niên khoá học kỳ -------------------
	xoa_mot_trang_dk_tin_chi();
	SetColor(11);
	gotoXY(81, 15); // --------------------- ô sáng đầu tiên ---------------------
	cout << "NHAP NIEN KHOA:";
	box(100, 14, 18, 2, 14, 0, "");

	SetColor(11);
	gotoXY(81, 19);
	cout << "NHAP HOC KY:";
	box(100, 18, 18, 2, 11, 0, "");

	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 177);
	gotoXY(95, 22);
	cout << "          ";
	gotoXY(95, 23);
	cout << " TRUY CAP ";
	gotoXY(95, 24);
	cout << "          ";

	string nk_hk[2];
	int y_sang_nk_hk = 14;

	while (77)
	{
		char c = _getch();
		if (c >= 47 && c <= 57)
		{
			if (y_sang_nk_hk == 14)
			{
				nk_hk[0].push_back(c);
				box(100, 14, 18, 2, 14, 0, nk_hk[0]);
			}
			else if (y_sang_nk_hk == 18)
			{
				nk_hk[1].push_back(c);
				box(100, 18, 18, 2, 14, 0, nk_hk[1]);
			}
		}
		else if (c == 13) // enter
		{
			if (y_sang_nk_hk == 22)
			{
				SetConsoleTextAttribute(hConsoleColor, 0);
				xoa_giao_dien_mo_lop_tin_chi();
				// in danh sách các lớp tín chỉ đuọc mở theo niên khoá và học kỳ
				break;
			}
		}
		else if (c == 8)
		{
			if (y_sang_nk_hk == 14 && !nk_hk[0].empty())
			{
				nk_hk[0].pop_back();
				box(100, 14, 18, 2, 14, 0, nk_hk[0]);
			}
			else if (y_sang_nk_hk == 18 && !nk_hk[1].empty())
			{
				nk_hk[1].pop_back();
				box(100, 18, 18, 2, 14, 0, nk_hk[1]);
			}
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 72) // lên
			{
				if (y_sang_nk_hk > 14)
				{
					if (y_sang_nk_hk == 18)
					{
						// tắt thanh sáng cũ
						box(100, 18, 18, 2, 11, 0, nk_hk[1]);
						y_sang_nk_hk -= 4;
						// bật thanh sáng mới
						box(100, 14, 18, 2, 14, 0, nk_hk[0]);
					}
					if (y_sang_nk_hk == 22)
					{
						// tắt thanh sáng cũ
						SetConsoleTextAttribute(hConsoleColor, 177);
						gotoXY(95, 22);
						cout << "          ";
						gotoXY(95, 23);
						cout << " TRUY CAP ";
						gotoXY(95, 24);
						cout << "          ";
						y_sang_nk_hk -= 4;
						// bật thanh sáng mới
						box(100, 18, 18, 2, 14, 0, nk_hk[1]);
					}
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang_nk_hk < 22)
				{
					// tắt thanh sáng cũ
					if (y_sang_nk_hk == 14)
					{
						box(100, 14, 18, 2, 11, 0, nk_hk[0]);
						y_sang_nk_hk += 4;
						// bật thanh sáng mới
						box(100, 18, 18, 2, 14, 0, nk_hk[1]);
					}
					else if (y_sang_nk_hk == 18)
					{
						// tắt thanh sáng cũ
						box(100, 18, 18, 2, 11, 0, nk_hk[1]);
						y_sang_nk_hk += 4;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 233);
						gotoXY(95, 22);
						cout << "          ";
						gotoXY(95, 23);
						cout << " TRUY CAP ";
						gotoXY(95, 24);
						cout << "          ";
					}
				}
			}
		}
	}
	// in danh sách các lớp tín chỉ đuọc mở theo niên khoá và học kỳ
	giao_dien_xuat_ds_lop_tc_theo_nk_hk_phien_ban_1_sv(ds_lop_tc, atoi(nk_hk[0].c_str()), atoi(nk_hk[1].c_str()), ds_mh, ma_sv_input);
	SetConsoleTextAttribute(hConsoleColor, 0);
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

void giao_dien_xuat_ds_lop_tc_theo_nk_hk_phien_ban_1_sv(DS_LOP_TIN_CHI &ds_lop_tc, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh, string ma_sv_dk)
{
	gotoXY(93, 5);
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << char(17);
	SetConsoleTextAttribute(hConsoleColor, 225);
	cout << " " << "NIEN KHOA: " << nien_khoa << " - HOC KY: " << hoc_ky << " ";
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << char(16);
	SetConsoleTextAttribute(hConsoleColor, 9);
	gotoXY(87, 6);
	gotoXY(62, 8);
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << "Chon" << "     " << setw(2) << "Ma LTC " << "    " << setw(18) << "Ten mon hoc" << "              " << setw(2) << "Nhom" << "     " << setw(2) << "Si so da dang ky" << "     " << setw(2) << "Slot con trong";
	// vẽ đường kẻ
	for (int i = 0; i < 98; i++)
	{
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoXY(61 + i, 9);
		cout << char(196);
	}
	int g = 0;
	int sl_lop_tc_ = ds_lop_tc.sl; // biến dùng để đếm các lớp tín chỉ chưa đăng ký
	while (66)
	{
		// duyệt để xuất danh sách ra thông tin các lớp để đăng kí
		// tạo biến đếm để đếm xem bao nhiêu lớp học phần đã mở
		string ds_ma_ltc[15];
		int sl_lop_tc_da_xuat = 0;
		int dem = 0;
		for (; g < ds_lop_tc.sl; g++)
		{
			if (ds_lop_tc.Lop_Tin_Chi[g]->nien_khoa == nien_khoa && ds_lop_tc.Lop_Tin_Chi[g]->hoc_ky == hoc_ky && ds_lop_tc.Lop_Tin_Chi[g]->trang_thai_lop == 1 && kt_lop_tc_sv_dk(ds_lop_tc.Lop_Tin_Chi[g]->DS_SV_DANG_KY_TIN_CHI, ma_sv_dk) != -1)
			{

				gotoXY(73, 11 + dem * 4);
				ds_ma_ltc[sl_lop_tc_da_xuat].insert(0, to_string(ds_lop_tc.Lop_Tin_Chi[g]->maLopTinCHi));
				sl_lop_tc_da_xuat++;

				SetConsoleTextAttribute(hConsoleColor, 11);
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->maLopTinCHi << "    ";
				Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds_lop_tc.Lop_Tin_Chi[g]->ma_mh);
				cout << setw(27) << p->data.ten_mh << "        ";
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->nhom << "            ";
				int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_lop_tc.Lop_Tin_Chi[g]->DS_SV_DANG_KY_TIN_CHI);
				cout << setw(2) << sl_sv_con_dang_ky << "                   ";
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->so_sv_max - sl_sv_con_dang_ky;

				// vẽ đường kẻ
				if (dem % 6 != 0 || dem == 0)
				{
					if (g != ds_lop_tc.sl - 1)
					{
						for (int j = 0; j < 98; j++)
						{
							SetConsoleTextAttribute(hConsoleColor, 7);
							gotoXY(61 + j, 13 + (dem * 4));
							cout << char(196);
						}
					}
				}
				dem++;
				// --------------- nếu xuất đủ 7 lớp tín chỉ thì dừng
				if (dem % 7 == 0)
				{
					break;
				}
			}
		}

		// vẽ hộp chọn
		for (int j = 0; j < dem; j++)
		{
			if (j == 0)
			{
				SetConsoleTextAttribute(hConsoleColor, 172);
				gotoXY(63, 11);
				cout << char(2);
			}
			else
			{
				SetConsoleTextAttribute(hConsoleColor, 2);
				gotoXY(63, 11 + (j * 4));
				cout << char(1);
			}
		}
		// di chuyển
		int y_sang_chon_lop = 11;
		int vt_sang = 0;
		while (77)
		{
			char c = _getch();
			if (c == 27) // esc
			{
				return;
			}
			else if (c == 72) // lên
			{
				if (y_sang_chon_lop > 11)
				{
					// tắt thanh sáng cũ
					SetConsoleTextAttribute(hConsoleColor, 2);
					gotoXY(62, 39);
					cout << "                                             ";
					gotoXY(63, y_sang_chon_lop);
					cout << char(1);
					y_sang_chon_lop -= 4;
					vt_sang--;
					// bật thanh sáng mới
					SetConsoleTextAttribute(hConsoleColor, 172);
					gotoXY(63, y_sang_chon_lop);
					cout << char(2);
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang_chon_lop < 11 + (dem - 1) * 4)
				{

					// tắt thanh sáng cũ
					SetConsoleTextAttribute(hConsoleColor, 2);
					gotoXY(62, 39);
					cout << "                                             ";
					gotoXY(63, y_sang_chon_lop);
					cout << char(1);
					y_sang_chon_lop += 4;
					vt_sang++;
					// bật thanh sáng mới
					SetConsoleTextAttribute(hConsoleColor, 172);
					gotoXY(63, y_sang_chon_lop);
					cout << char(2);
				}
			}
			else if (c == 13) // enter
			{
				// lấy ra mã lớp tín chỉ đăng kí của lớp đó dựa vào vt_sang
				int ma_lop_dk = atoi(ds_ma_ltc[vt_sang].c_str());
				int vt = kt_ma_lop_tc_theo_hoc_ky_nien_khoa(ds_lop_tc, nien_khoa, hoc_ky, ma_lop_dk, ma_sv_dk);
				if (so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_lop_tc.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI) == ds_lop_tc.Lop_Tin_Chi[vt]->so_sv_max)
				{
					SetConsoleTextAttribute(hConsoleColor, 12);
					gotoXY(62, 39);
					cout << "Lop nay da du sinh vien!";
				}
				else
				{
					
					SINH_VIEN_DANG_KY_TIN_CHI x;
					viet_hoa_ma_lop(ma_sv_dk);
					x.ma_sv = ma_sv_dk;
					x.trang_thai_dang_ky = 1;
					x.diem = NULL;
					NODE_SV_DANG_KY_TIN_CHI *p = khoiTaoNode_sv_dk_tin_chi(x);
					ThemNode_sv_dk_tin_chi(ds_lop_tc.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI, p);
					ds_lop_tc.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.sl++; // ghi bên file không chạm vào

					SetConsoleTextAttribute(hConsoleColor, 10);
					gotoXY(62, 39);
					cout << "DA DANG KY";
					sl_lop_tc_--;
					g = 0;
					while (66)
					{
						SetConsoleTextAttribute(hConsoleColor, 9);
						gotoXY(62, 41);
						cout << "Nhan phim bat ky de refesh lai trang";
						char c_con = _getch();
						if (c_con)
						{
							break;
						}
					}
					xoa_mot_trang_dk_tin_chi();
					break;
				}
				///// ->  sai
				// xuất chữ đã đăng kí 
				/*gotoXY(56, y_sang_chon_lop);
				SetConsoleTextAttribute(hConsoleColor, 164);
				cout << " DK ";*/
			}
			else if (c == 77) // sang phải
			{
				// nếu  trang đã xuất đủ 7 tín chỉ thì sang trang 2
				if (dem % 7 == 0 && sl_lop_tc_ > 7)
				{
					g++;
					SetConsoleTextAttribute(hConsoleColor, 0);
					xoa_mot_trang_dk_tin_chi();
					break;
				}
			}
			else if (c == 75) // sang trái
			{
				// nếu  trang đã xuất đủ 7 tín chỉ thì sang trang 2
				if (dem < 7 || dem % 7 == 0 && sl_lop_tc_ < 7)
				{
					SetConsoleTextAttribute(hConsoleColor, 0);
					xoa_mot_trang_dk_tin_chi();
					g = 0;
					break;
				}
			}
		}
	}
}

 // ------------------------------------ DANH SÁCH SINH VIÊN CÒN ĐĂNG KÝ TÍN CHỈ ------------------------------------
void giao_dien_xem_ds_sv_con_dk_tin_chi_main(DANH_SACH_MON_HOC ds_mh, DS_LOP_TIN_CHI ds_ltc, Sinh_Vien ds_sv[], int sl_sv,int &cong_tac_dau_nhay)
{
	SetColor(11);
	gotoXY(81, 15); // --------------------- ô sáng đầu tiên ---------------------
	cout << "NHAP NIEN KHOA:";
	box(100, 14, 18, 2, 14, 0, "");

	SetColor(11);
	gotoXY(81, 19);
	cout << "NHAP HOC KY:";
	box(100, 18, 18, 2, 11, 0, "");

	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 177);
	gotoXY(95, 22);
	cout << "          ";
	gotoXY(95, 23);
	cout << " TRUY CAP ";
	gotoXY(95, 24);
	cout << "          ";

	string nk_hk[2];
	int y_sang_nk_hk = 14;

	while (77)
	{
		char c = _getch();
		if (c >= 47 && c <= 57)
		{
			if (y_sang_nk_hk == 14)
			{
				nk_hk[0].push_back(c);
				box(100, 14, 18, 2, 14, 0, nk_hk[0]);
			}
			else if (y_sang_nk_hk == 18)
			{
				nk_hk[1].push_back(c);
				box(100, 18, 18, 2, 14, 0, nk_hk[1]);
			}
		}
		else if (c == 13) // enter
		{
			if (y_sang_nk_hk == 22)
			{
				SetConsoleTextAttribute(hConsoleColor, 0);
				xoa_giao_dien_mo_lop_tin_chi();
				// in danh sách các lớp tín chỉ đuọc mở theo niên khoá và học kỳ
				break;
			}
		}
		else if (c == 8)
		{
			if (y_sang_nk_hk == 14 && !nk_hk[0].empty())
			{
				nk_hk[0].pop_back();
				box(100, 14, 18, 2, 14, 0, nk_hk[0]);
			}
			else if (y_sang_nk_hk == 18 && !nk_hk[1].empty())
			{
				nk_hk[1].pop_back();
				box(100, 18, 18, 2, 14, 0, nk_hk[1]);
			}
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 72) // lên
			{
				if (y_sang_nk_hk > 14)
				{
					if (y_sang_nk_hk == 18)
					{
						// tắt thanh sáng cũ
						box(100, 18, 18, 2, 11, 0, nk_hk[1]);
						y_sang_nk_hk -= 4;
						// bật thanh sáng mới
						box(100, 14, 18, 2, 14, 0, nk_hk[0]);
					}
					if (y_sang_nk_hk == 22)
					{
						// tắt thanh sáng cũ
						SetConsoleTextAttribute(hConsoleColor, 177);
						gotoXY(95, 22);
						cout << "          ";
						gotoXY(95, 23);
						cout << " TRUY CAP ";
						gotoXY(95, 24);
						cout << "          ";
						y_sang_nk_hk -= 4;
						// bật thanh sáng mới
						box(100, 18, 18, 2, 14, 0, nk_hk[1]);
					}
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang_nk_hk < 22)
				{
					// tắt thanh sáng cũ
					if (y_sang_nk_hk == 14)
					{
						box(100, 14, 18, 2, 11, 0, nk_hk[0]);
						y_sang_nk_hk += 4;
						// bật thanh sáng mới
						box(100, 18, 18, 2, 14, 0, nk_hk[1]);
					}
					else if (y_sang_nk_hk == 18)
					{
						// tắt thanh sáng cũ
						box(100, 18, 18, 2, 11, 0, nk_hk[1]);
						y_sang_nk_hk += 4;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 233);
						gotoXY(95, 22);
						cout << "          ";
						gotoXY(95, 23);
						cout << " TRUY CAP ";
						gotoXY(95, 24);
						cout << "          ";
					}
				}
			}
		}
	}
	giao_dien_xem_ds_sv_con_dk_tin_chi_support(ds_mh, ds_ltc, ds_sv, sl_sv, atoi(nk_hk[0].c_str()), atoi(nk_hk[1].c_str()));
	SetConsoleTextAttribute(hConsoleColor, 0);
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;
}

void giao_dien_xem_ds_sv_con_dk_tin_chi_support(DANH_SACH_MON_HOC ds_mh, DS_LOP_TIN_CHI ds_lop_tc, Sinh_Vien ds_sv[], int sl_sv, int nien_khoa, int hoc_ky)
{
	gotoXY(93, 5);
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << char(17);
	SetConsoleTextAttribute(hConsoleColor, 225);
	cout << " " << "NIEN KHOA: " << nien_khoa << " - HOC KY: " << hoc_ky << " ";
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << char(16);
	SetConsoleTextAttribute(hConsoleColor, 9);
	gotoXY(87, 6);
	gotoXY(62, 8);
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << "Chon" << "     " << setw(2) << "Ma LTC " << "    " << setw(18) << "Ten mon hoc" << "              " << setw(2) << "Nhom" << "     " << setw(2) << "Si so da dang ky" << "     " << setw(2) << "Slot con trong";
	// vẽ đường kẻ
	for (int i = 0; i < 98; i++)
	{
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoXY(61 + i, 9);
		cout << char(196);
	}
	int g = 0;
	while (66)
	{
		// duyệt để xuất danh sách ra thông tin các lớp để đăng kí
		// tạo biến đếm để đếm xem bao nhiêu lớp học phần đã mở
		string ds_ma_ltc[15];
		int sl_lop_tc_da_xuat = 0;
		int dem = 0;
		int trang = 0;
		for (; g < ds_lop_tc.sl; g++)
		{
			if (ds_lop_tc.Lop_Tin_Chi[g]->nien_khoa == nien_khoa && ds_lop_tc.Lop_Tin_Chi[g]->hoc_ky == hoc_ky && ds_lop_tc.Lop_Tin_Chi[g]->trang_thai_lop == 1 )
			{

				gotoXY(73, 11 + dem * 4);
				ds_ma_ltc[sl_lop_tc_da_xuat].insert(0, to_string(ds_lop_tc.Lop_Tin_Chi[g]->maLopTinCHi));
				sl_lop_tc_da_xuat++;

				SetConsoleTextAttribute(hConsoleColor, 11);
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->maLopTinCHi << "    ";
				Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds_lop_tc.Lop_Tin_Chi[g]->ma_mh);
				cout << setw(27) << p->data.ten_mh << "        ";
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->nhom << "            ";
				int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_lop_tc.Lop_Tin_Chi[g]->DS_SV_DANG_KY_TIN_CHI);
				cout << setw(2) << sl_sv_con_dang_ky << "                   ";
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->so_sv_max - sl_sv_con_dang_ky;

				// vẽ đường kẻ
				if (dem % 6 != 0 || dem == 0)
				{
					if (g != ds_lop_tc.sl - 1)
					{
						for (int j = 0; j < 98; j++)
						{
							SetConsoleTextAttribute(hConsoleColor, 7);
							gotoXY(61 + j, 13 + (dem * 4));
							cout << char(196);
						}
					}
				}
				dem++;
				// --------------- nếu xuất đủ 7 lớp tín chỉ thì dừng
				if (dem % 7 == 0)
				{
					break;
				}
			}
		}

		// vẽ hộp chọn
		for (int j = 0; j < dem; j++)
		{
			if (j == 0)
			{
				SetConsoleTextAttribute(hConsoleColor, 160);
				gotoXY(63, 11);
				cout << " XEM ";
			}
			else
			{
				SetConsoleTextAttribute(hConsoleColor, 2);
				gotoXY(63, 11 + (j * 4));
				cout << " XEM ";
			}
		}
		// di chuyển
		int y_sang_chon_lop = 11;
		int vt_sang = 0;
		while (77)
		{
			char c = _getch();
			if (c == 27) // esc
			{
				return;
			}
			else if (c == 72) // lên
			{
				if (y_sang_chon_lop > 11)
				{
					// tắt thanh sáng cũ
					SetConsoleTextAttribute(hConsoleColor, 2);
					gotoXY(62, 39);
					cout << "                                             ";
					gotoXY(63, y_sang_chon_lop);
					cout << " XEM ";
					y_sang_chon_lop -= 4;
					vt_sang--;
					// bật thanh sáng mới
					SetConsoleTextAttribute(hConsoleColor, 160);
					gotoXY(63, y_sang_chon_lop);
					cout << " XEM ";
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang_chon_lop < 11 + (dem - 1) * 4)
				{

					// tắt thanh sáng cũ
					SetConsoleTextAttribute(hConsoleColor, 2);
					gotoXY(62, 39);
					cout << "                                             ";
					gotoXY(63, y_sang_chon_lop);
					cout << " XEM ";
					y_sang_chon_lop += 4;
					vt_sang++;
					// bật thanh sáng mới
					SetConsoleTextAttribute(hConsoleColor, 160);
					gotoXY(63, y_sang_chon_lop);
					cout << " XEM ";
				}
			}
			else if (c == 13) // enter
			{
				SetConsoleTextAttribute(hConsoleColor, 0);
				xoa_giao_dien_mo_lop_tin_chi();
				while (77)
				{
					xuat_ds_sv_trong_1_lop_tc_theo_ma_lop_tc(ds_lop_tc, atoi(ds_ma_ltc[vt_sang].c_str()), ds_sv, sl_sv, ds_mh);
					char c = _getch();
					if (c == 27)
					{
						break;
					}
				}
				xoa_giao_dien_mo_lop_tin_chi();
				gotoXY(93, 5);
				HANDLE hConsoleColor;
				hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsoleColor, 14);
				cout << char(17);
				SetConsoleTextAttribute(hConsoleColor, 225);
				cout << " " << "NIEN KHOA: " << nien_khoa << " - HOC KY: " << hoc_ky << " ";
				SetConsoleTextAttribute(hConsoleColor, 14);
				cout << char(16);
				SetConsoleTextAttribute(hConsoleColor, 9);
				gotoXY(87, 6);
				gotoXY(62, 8);
				SetConsoleTextAttribute(hConsoleColor, 14);
				cout << "Chon" << "     " << setw(2) << "Ma LTC " << "    " << setw(18) << "Ten mon hoc" << "              " << setw(2) << "Nhom" << "     " << setw(2) << "Si so da dang ky" << "     " << setw(2) << "Slot con trong";
				// vẽ đường kẻ
				for (int i = 0; i < 98; i++)
				{
					SetConsoleTextAttribute(hConsoleColor, 15);
					gotoXY(61 + i, 9);
					cout << char(196);
				}
				g = 0;
				break;
			}
			else if (c == 77) // sang phải
			{
				// nếu  trang đã xuất đủ 7 tín chỉ thì sang trang 2
				if (dem % 7 == 0)
				{
					g++;
					SetConsoleTextAttribute(hConsoleColor, 0);
					xoa_mot_trang_dk_tin_chi();
					break;
				}
			}
			else if (c == 75) // sang trái
			{
				// nếu  trang đã xuất đủ 7 tín chỉ thì sang trang 2
				if (dem < 7 || dem % 7 == 0 && trang > 0)
				{
					SetConsoleTextAttribute(hConsoleColor, 0);
					xoa_mot_trang_dk_tin_chi();
					g = 0;
					break;
				}
			}
		}
	}
}

void xuat_ds_sv_trong_1_lop_tc_theo_ma_lop_tc(DS_LOP_TIN_CHI ds_lop_tc, int ma_lop_tc,Sinh_Vien ds[],int sl_sv,DANH_SACH_MON_HOC ds_mh)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 14);
	gotoXY(93, 5);
	cout << "DANH SACH SINH VIEN";
	gotoXY(85, 6);
	Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds_lop_tc.Lop_Tin_Chi[ma_lop_tc - 1]->ma_mh);
	cout << "LOP HOC PHAN: ";
	SetConsoleTextAttribute(hConsoleColor, 11);
	cout << p->data.ten_mh;
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << " - Nhom: ";
	SetConsoleTextAttribute(hConsoleColor, 11);
	cout << ds_lop_tc.Lop_Tin_Chi[ma_lop_tc - 1]->nhom;


	gotoXY(80, 8);
	cout << setw(2) << "STT" << "\t"<< setw(9) << "MA SINH VIEN" << "\t" << setw(27) << "HO VA TEN";
	int y_sang = 10;
	for (int j = 0; j < 55; j++)
	{
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoXY(78 + j, 9);
		cout << char(254);
	}
	int stt = 1;
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds_lop_tc.Lop_Tin_Chi[ma_lop_tc - 1]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.trang_thai_dang_ky == 1)
		{
			for (int i = 0; i < sl_sv; i++)
			{
				if (_stricmp(k->data.ma_sv.c_str(), ds[i].ma_sv.c_str()) == 0)
				{
					SetConsoleTextAttribute(hConsoleColor, 12);
					gotoXY(80, y_sang);
					cout << setw(2) << stt++ << "\t" << setw(9) << ds[i].ma_sv;
					string hoten = ds[i].ho + " " + ds[i].ten;
					cout << "\t" << setw(27) << hoten;
					y_sang++;
					if (k->pNext != NULL)
					{
						for (int j = 0; j < 55; j++)
						{
							SetConsoleTextAttribute(hConsoleColor, 7);
							gotoXY(78 + j, y_sang);
							cout << char(254);
						}
					}
					y_sang++;
				}
			}
		}	
	}
}

// ------------------------------------ HUỶ ĐĂNG KÝ LỚP TÍN CHỈ ------------------------------------
void giao_dien_huy_dang_ky_1_lop(DS_LOP_TIN_CHI &ds_lop_tc, Sinh_Vien ds_sv[],int sl_sv, DANH_SACH_MON_HOC ds_mh,int &cong_tac_dau_nhay)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

	// b1------------------- nhập mã lớp -------------------
	SetColor(11);
	gotoXY(81, 15);
	cout << "NHAP MA LOP:";
	box(100, 14, 18, 2, 14, 0, "");
	vector<string> ds_ma_sv;
	string ma_lop_input;
	while (77)
	{
		char c = _getch();
		if (c != -32 && c != 72 && c != 80 && c != 75 && c != 77 && c != 8 && c != 13 && c != 27)
		{
			gotoXY(84, 16);
			cout << "                     ";
			ma_lop_input.push_back(c);
		}
		else if (c == 27)
		{
			return;
		}
		else if (c == 8 && !ma_lop_input.empty())
		{
			gotoXY(84, 16);
			cout << "                     ";
			ma_lop_input.pop_back();
		}
		else if (c == 13)
		{
			// duyệt qua danh sách sinh viên kiểm tra mã lớp đó có tồn tại hay không

			int check_malop = 0;
			for (int i = 0; i < sl_sv; i++)
			{
				if (_stricmp(ds_sv[i].Ma_Lop.c_str(), ma_lop_input.c_str()) == 0)
				{
					check_malop = 1;
					ds_ma_sv.push_back(ds_sv[i].ma_sv);
					
				}
			}

			if (check_malop == 0)
			{
				gotoXY(84, 16);
				SetColor(12);
				cout << "Ma lop khong ton tai!";
			}
			else
			{
				break;
			}
		}
		box(100, 14, 18, 2, 14, 0, ma_lop_input);
	}
	xoa_giao_dien_mo_lop_tin_chi();
	int g = 0;
	gotoXY(62, 4);
	
	SetConsoleTextAttribute(hConsoleColor, 15);
	cout << "    _____    _     _     _  _     __      " << char(92) << " /       _  __    _     _    ";
	gotoXY(62, 5);
	cout << "|/ |_  |    / " << char(92) << "| ||_|   | " << char(92) << "|_||" << char(92) << "|/__   |/  Y    |_|/ " << char(92) << "/     |_)|_||_||" << char(92) << "|";
	gotoXY(62, 6);
	cout << "|" << char(92) << " |__ |    " << char(92) << "_X|_|| |   |_/| || |" << char(92) << "_|   |" << char(92) << "  |    | |" << char(92) << "_/" << char(92) << "__   |  | || || |";
	SetConsoleTextAttribute(hConsoleColor, 9);
	gotoXY(87, 6);
	gotoXY(62, 8);
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << "Chon" << "     " << setw(2) << "Ma LTC " << "    " << setw(18) << "Ten mon hoc" << "              " << setw(2) << "Nhom" << "     " << setw(2) << "Si so da dang ky" << "     " << setw(2) << "Slot con trong";
	// vẽ đường kẻ
	for (int i = 0; i < 98; i++)
	{
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoXY(61 + i, 9);
		cout << char(196);
	}
		while (66)
		{
			int nien_khoa, hoc_ky;
			// duyệt để xuất danh sách ra thông tin các lớp để đăng kí
			// tạo biến đếm để đếm xem bao nhiêu lớp học phần đã mở
			string ds_ma_ltc[15];
			int sl_lop_tc_da_xuat = 0;
			int dem = 0;
			xuat_ds_ket_qua_dky_hoc_phan_1_lop(g, ds_lop_tc, nien_khoa, hoc_ky, dem, ds_ma_ltc, sl_lop_tc_da_xuat, ds_mh, ds_ma_sv[0]);
			
			// vẽ hộp chọn
			for (int j = 0; j < dem; j++)
			{
				if (j == 0)
				{
					SetConsoleTextAttribute(hConsoleColor, 172);
					gotoXY(63, 11);
					cout << " HUY ";
				}
				else
				{
					SetConsoleTextAttribute(hConsoleColor, 2);
					gotoXY(63, 11 + (j * 4));
					cout << " HUY ";
				}
			}
			// di chuyển
			int y_sang_chon_lop = 11;
			int vt_sang = 0;
			while (77)
			{
				char c = _getch();
				if (c == 27) // esc
				{
					SetConsoleTextAttribute(hConsoleColor, 0);
					xoa_giao_dien_mo_lop_tin_chi();
					cong_tac_dau_nhay = 0;
					return;
				}
				else if (c == 72) // lên
				{
					if (y_sang_chon_lop > 11)
					{
						// tắt thanh sáng cũ
						SetConsoleTextAttribute(hConsoleColor, 10);
						gotoXY(62, 39);
						cout << "                                             ";
						gotoXY(63, y_sang_chon_lop);
						cout << " HUY ";
						y_sang_chon_lop -= 4;
						vt_sang--;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 172);
						gotoXY(63, y_sang_chon_lop);
						cout << " HUY ";
					}
				}
				else if (c == 80) // xuống
				{
					if (y_sang_chon_lop < 11 + (dem - 1) * 4)
					{

						// tắt thanh sáng cũ
						SetConsoleTextAttribute(hConsoleColor, 10);
						gotoXY(62, 39);
						cout << "                                             ";
						gotoXY(63, y_sang_chon_lop);
						cout << " HUY ";
						y_sang_chon_lop += 4;
						vt_sang++;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 172);
						gotoXY(63, y_sang_chon_lop);
						cout << " HUY ";
					}
				}
				else if (c == 13) // enter
				{
					while (77)
					{
						SetConsoleTextAttribute(hConsoleColor, 10);;
						gotoXY(75, 39);
						cout << "Ban co chac chan muon xoa?";
						gotoXY(75, 40);
						cout << "Nhan enter de tiep tuc, esc de huy!";
						char c_con = _getch();
						if (c == 13) // enter
						{
							// thực hiện thao tác huỷ đăng ký
							int ma_lop_dk = atoi(ds_ma_ltc[vt_sang].c_str());
							huy_dang_ki_tin_chi_1_lop_new(ds_ma_sv, ds_lop_tc, ma_lop_dk, ds_ma_sv.size());
							// xoá thông báo
							gotoXY(75, 39);
							cout << "                          ";
							gotoXY(75, 40);
							cout << "                                   ";
							xoa_mot_trang_dk_tin_chi();
							break;
						}
						else if (c == 27) // esc
						{
							// xoá thông báo
							gotoXY(75, 39);
							cout << "                          ";
							gotoXY(75, 40);
							cout << "                                   ";
							break;
						}
					}
					break;
				}
				else if (c == 77) // sang phải
				{
					// nếu  trang đã xuất đủ 7 tín chỉ thì sang trang 2
					if (dem % 7 == 0 && sl_lop_tc_da_xuat > 7)
					{
						g++;
						SetConsoleTextAttribute(hConsoleColor, 0);
						xoa_mot_trang_dk_tin_chi();
						break;
					}
				}
				else if (c == 75) // sang trái
				{
					// nếu  trang đã xuất đủ 7 tín chỉ thì sang trang 2
					if (dem < 7 || dem % 7 == 0 && sl_lop_tc_da_xuat < 7)
					{
						SetConsoleTextAttribute(hConsoleColor, 0);
						xoa_mot_trang_dk_tin_chi();
						g = 0;
						break;
					}
				}
			}
		}
}

void xuat_ds_ket_qua_dky_hoc_phan_1_lop(int &g,DS_LOP_TIN_CHI ds_lop_tc,int &nien_khoa,int &hoc_ky,int &dem,string ds_ma_ltc[],int &sl_lop_tc_da_xuat,DANH_SACH_MON_HOC ds_mh,string ma_sv)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	for (g = 0; g < ds_lop_tc.sl; g++)
	{
		if (ds_lop_tc.Lop_Tin_Chi[g]->trang_thai_lop == 1 && kt_lop_tc_sv_dk(ds_lop_tc.Lop_Tin_Chi[g]->DS_SV_DANG_KY_TIN_CHI, ma_sv) == -1)
		{
				nien_khoa = ds_lop_tc.Lop_Tin_Chi[g]->nien_khoa;
				hoc_ky = ds_lop_tc.Lop_Tin_Chi[g]->hoc_ky;
				gotoXY(73, 11 + dem * 4);
				ds_ma_ltc[sl_lop_tc_da_xuat].insert(0, to_string(ds_lop_tc.Lop_Tin_Chi[g]->maLopTinCHi));
				sl_lop_tc_da_xuat++;

				SetConsoleTextAttribute(hConsoleColor, 11);
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->maLopTinCHi << "    ";
				Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds_lop_tc.Lop_Tin_Chi[g]->ma_mh);
				cout << setw(27) << p->data.ten_mh << "        ";
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->nhom << "            ";
				int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_lop_tc.Lop_Tin_Chi[g]->DS_SV_DANG_KY_TIN_CHI);
				cout << setw(2) << sl_sv_con_dang_ky << "                   ";
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->so_sv_max - sl_sv_con_dang_ky;

				// vẽ đường kẻ
				if (dem % 6 != 0 || dem == 0)
				{
					if (g != ds_lop_tc.sl - 1)
					{
						for (int j = 0; j < 98; j++)
						{
							SetConsoleTextAttribute(hConsoleColor, 7);
							gotoXY(61 + j, 13 + (dem * 4));
							cout << char(196);
						}
					}
				}
				dem++;
				// --------------- nếu xuất đủ 7 lớp tín chỉ thì dừng
				if (dem % 7 == 0)
				{
					break;
				}
		}
	}
}

void huy_dang_ki_tin_chi_1_lop_new(vector<string> ds_ma_sv, DS_LOP_TIN_CHI &ds_ltc,int ma_lop_tc,int sl_sv)
{
	for (int i = 0; i < sl_sv; i++)
	{
		for (NODE_SV_DANG_KY_TIN_CHI *k = ds_ltc.Lop_Tin_Chi[ma_lop_tc - 1]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
		{
			if (_stricmp(ds_ma_sv[i].c_str(), k->data.ma_sv.c_str()) == 0 && k->data.trang_thai_dang_ky == 1)
			{
				k->data.trang_thai_dang_ky = 0;
			}
		}
	}
	
}

void giao_dien_huy_dky_hoc_phan_1_sv(DS_LOP_TIN_CHI &ds_lop_tc, Sinh_Vien ds_sv[], int sl_sv, DANH_SACH_MON_HOC ds_mh, int &cong_tac_dau_nhay)
{
	// b1------------------ - nhập mã sinh viên ------------------ -
		SetColor(11);
	gotoXY(81, 15);
	cout << "NHAP MA SINH VIEN:";
	box(100, 14, 18, 2, 14, 0, "");
	string ma_sv_input;
	while (77)
	{
		char c = _getch();
		if (c != -32 && c != 72 && c != 80 && c != 75 && c != 77 && c != 8 && c != 13 && c != 27)
		{
			gotoXY(84, 17);
			cout << "                           ";
			ma_sv_input.push_back(c);
		}
		else if (c == 8 && !ma_sv_input.empty())
		{
			gotoXY(84, 17);
			cout << "                           ";
			ma_sv_input.pop_back();
		}
		else if (c == 13)
		{
			// duyệt qua danh sách sinh viên kiểm tra mã lớp đó có tồn tại hay không
			if (kt_ma_sv_ton_tai(ds_sv, sl_sv, ma_sv_input) == -1)
			{
				gotoXY(84, 17);
				SetColor(12);
				cout << "Ma sinh vien khong ton tai!";
			}
			else
			{
				break;
			}
		}
		box(100, 14, 18, 2, 14, 0, ma_sv_input);
	}


	xoa_giao_dien_mo_lop_tin_chi();
	int g = 0;
	
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoXY(62, 4);
	SetConsoleTextAttribute(hConsoleColor, 15);
	cout << "    _____    _     _     _  _     __      " << char(92) << " /       _  __    _     _    ";
	gotoXY(62, 5);
	cout << "|/ |_  |    / " << char(92) << "| ||_|   | " << char(92) << "|_||" << char(92) << "|/__   |/  Y    |_|/ " << char(92) << "/     |_)|_||_||" << char(92) << "|";
	gotoXY(62, 6);
	cout << "|" << char(92) << " |__ |    " << char(92) << "_X|_|| |   |_/| || |" << char(92) << "_|   |" << char(92) << "  |    | |" << char(92) << "_/" << char(92) << "__   |  | || || |";
	SetConsoleTextAttribute(hConsoleColor, 9);
	gotoXY(87, 6);
	gotoXY(62, 8);
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << "Chon" << "     " << setw(2) << "Ma LTC " << "    " << setw(18) << "Ten mon hoc" << "              " << setw(2) << "Nhom" << "     " << setw(2) << "Si so da dang ky" << "     " << setw(2) << "Slot con trong";
	// vẽ đường kẻ
	for (int i = 0; i < 98; i++)
	{
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoXY(61 + i, 9);
		cout << char(196);
	}
	while (66)
	{
		// duyệt để xuất danh sách ra thông tin các lớp để đăng kí
		// tạo biến đếm để đếm xem bao nhiêu lớp học phần đã mở
		string ds_ma_ltc[15];
		int sl_lop_tc_da_xuat = 0;
		int dem = 0;
		xuat_ds_ket_qua_dky_hoc_phan_1_sv(g, ds_lop_tc, dem, ds_ma_ltc, sl_lop_tc_da_xuat, ds_mh, ma_sv_input);

		// vẽ hộp chọn
		for (int j = 0; j < dem; j++)
		{
			if (j == 0)
			{
				SetConsoleTextAttribute(hConsoleColor, 172);
				gotoXY(63, 11);
				cout << " HUY ";
			}
			else
			{
				SetConsoleTextAttribute(hConsoleColor, 2);
				gotoXY(63, 11 + (j * 4));
				cout << " HUY ";
			}
		}
		// di chuyển
		int y_sang_chon_lop = 11;
		int vt_sang = 0;
		while (77)
		{
			char c = _getch();
			if (c == 27) // esc
			{
				SetConsoleTextAttribute(hConsoleColor, 0);
				xoa_giao_dien_mo_lop_tin_chi();
				cong_tac_dau_nhay = 0;
				return;
			}
			else if (c == 72) // lên
			{
				if (y_sang_chon_lop > 11)
				{
					// tắt thanh sáng cũ
					SetConsoleTextAttribute(hConsoleColor, 10);
					gotoXY(62, 39);
					cout << "                                             ";
					gotoXY(63, y_sang_chon_lop);
					cout << " HUY ";
					y_sang_chon_lop -= 4;
					vt_sang--;
					// bật thanh sáng mới
					SetConsoleTextAttribute(hConsoleColor, 172);
					gotoXY(63, y_sang_chon_lop);
					cout << " HUY ";
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang_chon_lop < 11 + (dem - 1) * 4)
				{

					// tắt thanh sáng cũ
					SetConsoleTextAttribute(hConsoleColor, 10);
					gotoXY(62, 39);
					cout << "                                             ";
					gotoXY(63, y_sang_chon_lop);
					cout << " HUY ";
					y_sang_chon_lop += 4;
					vt_sang++;
					// bật thanh sáng mới
					SetConsoleTextAttribute(hConsoleColor, 172);
					gotoXY(63, y_sang_chon_lop);
					cout << " HUY ";
				}
			}
			else if (c == 13) // enter
			{
				while (77)
				{
					SetConsoleTextAttribute(hConsoleColor, 10);;
					gotoXY(75, 39);
					cout << "Ban co chac chan muon xoa?";
					gotoXY(75, 40);
					cout << "Nhan enter de tiep tuc, esc de huy!";
					char c_con = _getch();
					if (c == 13) // enter
					{
						// thực hiện thao tác huỷ đăng ký
						int ma_lop_dk = atoi(ds_ma_ltc[vt_sang].c_str());
						NODE_SV_DANG_KY_TIN_CHI *check = kt_sv_co_ton_tai_trong_lop_tin_chi(ds_lop_tc.Lop_Tin_Chi[ma_lop_dk - 1]->DS_SV_DANG_KY_TIN_CHI, ma_sv_input);
						check->data.trang_thai_dang_ky = 0;
						// xoá thông báo
						gotoXY(75, 39);
						cout << "                          ";
						gotoXY(75, 40);
						cout << "                                   ";
						xoa_mot_trang_dk_tin_chi();
						break;
					}
					else if (c == 27) // esc
					{
						// xoá thông báo
						gotoXY(75, 39);
						cout << "                          ";
						gotoXY(75, 40);
						cout << "                                   ";
						break;
					}
				}
				break;
			}
			else if (c == 77) // sang phải
			{
				// nếu  trang đã xuất đủ 7 tín chỉ thì sang trang 2
				if (dem % 7 == 0 && sl_lop_tc_da_xuat > 7)
				{
					g++;
					SetConsoleTextAttribute(hConsoleColor, 0);
					xoa_mot_trang_dk_tin_chi();
					break;
				}
			}
			else if (c == 75) // sang trái
			{
				// nếu  trang đã xuất đủ 7 tín chỉ thì sang trang 2
				if (dem < 7 || dem % 7 == 0 && sl_lop_tc_da_xuat < 7)
				{
					SetConsoleTextAttribute(hConsoleColor, 0);
					xoa_mot_trang_dk_tin_chi();
					g = 0;
					break;
				}
			}
		}
	}
}

void xuat_ds_ket_qua_dky_hoc_phan_1_sv(int &g, DS_LOP_TIN_CHI ds_lop_tc, int &dem, string ds_ma_ltc[], int &sl_lop_tc_da_xuat, DANH_SACH_MON_HOC ds_mh, string ma_sv_input)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	for (g = 0; g < ds_lop_tc.sl; g++)
	{
		if (ds_lop_tc.Lop_Tin_Chi[g]->trang_thai_lop == 1)
		{
			NODE_SV_DANG_KY_TIN_CHI *check = kt_sv_co_ton_tai_trong_lop_tin_chi(ds_lop_tc.Lop_Tin_Chi[g]->DS_SV_DANG_KY_TIN_CHI, ma_sv_input);
			if (check != NULL)
			{
				gotoXY(73, 11 + dem * 4);
				ds_ma_ltc[sl_lop_tc_da_xuat].insert(0, to_string(ds_lop_tc.Lop_Tin_Chi[g]->maLopTinCHi));
				sl_lop_tc_da_xuat++;

				SetConsoleTextAttribute(hConsoleColor, 11);
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->maLopTinCHi << "    ";
				Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds_lop_tc.Lop_Tin_Chi[g]->ma_mh);
				cout << setw(27) << p->data.ten_mh << "        ";
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->nhom << "            ";
				int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_lop_tc.Lop_Tin_Chi[g]->DS_SV_DANG_KY_TIN_CHI);
				cout << setw(2) << sl_sv_con_dang_ky << "                   ";
				cout << setw(2) << ds_lop_tc.Lop_Tin_Chi[g]->so_sv_max - sl_sv_con_dang_ky;

				// vẽ đường kẻ
				if (dem % 6 != 0 || dem == 0)
				{
					if (g != ds_lop_tc.sl - 1)
					{
						for (int j = 0; j < 98; j++)
						{
							SetConsoleTextAttribute(hConsoleColor, 7);
							gotoXY(61 + j, 13 + (dem * 4));
							cout << char(196);
						}
					}
				}
				dem++;
				// --------------- nếu xuất đủ 7 lớp tín chỉ thì dừng
				if (dem % 7 == 0)
				{
					break;
				}
			}
			
		}
	}
}

// ================================ LỌC LỚP TÍN CHỈ ================================
void loc_ds_lop_hoc_phan_new(DS_LOP_TIN_CHI &ds_lop_tc,DANH_SACH_MON_HOC ds_mh)
{
	SetColor(11);
	gotoXY(81, 15); // --------------------- ô sáng đầu tiên ---------------------
	cout << "NHAP NIEN KHOA:";
	box(100, 14, 18, 2, 14, 0, "");

	SetColor(11);
	gotoXY(81, 19);
	cout << "NHAP HOC KY:";
	box(100, 18, 18, 2, 11, 0, "");

	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 177);
	gotoXY(95, 22);
	cout << "          ";
	gotoXY(95, 23);
	cout << " TRUY CAP ";
	gotoXY(95, 24);
	cout << "          ";

	string nk_hk[2];
	int y_sang_nk_hk = 14;

	while (77)
	{
		char c = _getch();
		if (c >= 47 && c <= 57)
		{
			if (y_sang_nk_hk == 14)
			{
				nk_hk[0].push_back(c);
				box(100, 14, 18, 2, 14, 0, nk_hk[0]);
			}
			else if (y_sang_nk_hk == 18)
			{
				nk_hk[1].push_back(c);
				box(100, 18, 18, 2, 14, 0, nk_hk[1]);
			}
		}
		else if (c == 13) // enter
		{
			if (y_sang_nk_hk == 22)
			{
				SetConsoleTextAttribute(hConsoleColor, 0);
				xoa_giao_dien_mo_lop_tin_chi();
				// in danh sách các lớp tín chỉ đuọc mở theo niên khoá và học kỳ
				break;
			}
		}
		else if (c == 8)
		{
			if (y_sang_nk_hk == 14 && !nk_hk[0].empty())
			{
				nk_hk[0].pop_back();
				box(100, 14, 18, 2, 14, 0, nk_hk[0]);
			}
			else if (y_sang_nk_hk == 18 && !nk_hk[1].empty())
			{
				nk_hk[1].pop_back();
				box(100, 18, 18, 2, 14, 0, nk_hk[1]);
			}
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 72) // lên
			{
				if (y_sang_nk_hk > 14)
				{
					if (y_sang_nk_hk == 18)
					{
						// tắt thanh sáng cũ
						box(100, 18, 18, 2, 11, 0, nk_hk[1]);
						y_sang_nk_hk -= 4;
						// bật thanh sáng mới
						box(100, 14, 18, 2, 14, 0, nk_hk[0]);
					}
					if (y_sang_nk_hk == 22)
					{
						// tắt thanh sáng cũ
						SetConsoleTextAttribute(hConsoleColor, 177);
						gotoXY(95, 22);
						cout << "          ";
						gotoXY(95, 23);
						cout << " TRUY CAP ";
						gotoXY(95, 24);
						cout << "          ";
						y_sang_nk_hk -= 4;
						// bật thanh sáng mới
						box(100, 18, 18, 2, 14, 0, nk_hk[1]);
					}
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang_nk_hk < 22)
				{
					// tắt thanh sáng cũ
					if (y_sang_nk_hk == 14)
					{
						box(100, 14, 18, 2, 11, 0, nk_hk[0]);
						y_sang_nk_hk += 4;
						// bật thanh sáng mới
						box(100, 18, 18, 2, 14, 0, nk_hk[1]);
					}
					else if (y_sang_nk_hk == 18)
					{
						// tắt thanh sáng cũ
						box(100, 18, 18, 2, 11, 0, nk_hk[1]);
						y_sang_nk_hk += 4;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 233);
						gotoXY(95, 22);
						cout << "          ";
						gotoXY(95, 23);
						cout << " TRUY CAP ";
						gotoXY(95, 24);
						cout << "          ";
					}
				}
			}
		}
	}
	// cho xem danh sách các lớp học phần không đủ điều kiện
	while (true)
	{
		in_ds_lop_bi_huy_new(ds_lop_tc, atoi(nk_hk[0].c_str()), atoi(nk_hk[1].c_str()), ds_mh);
		char c = _getch();
		if (c == 27)
		{
			break;
		}
	}
	SetConsoleTextAttribute(hConsoleColor, 0);
	xoa_giao_dien_mo_lop_tin_chi();
}

void in_ds_lop_bi_huy_new(DS_LOP_TIN_CHI &ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 237);
	gotoXY(93, 4);
	cout << "                          ";
	gotoXY(93, 5);
	cout << " DANH SACH CAC LOP BI HUY ";
	
	SetConsoleTextAttribute(hConsoleColor, 225);
	gotoXY(91, 6);
	cout  << " "<< "Nien Khoa: " << nien_khoa << " - Hoc Ky: " << hoc_ky << " ";
	SetConsoleTextAttribute(hConsoleColor, 11);
	gotoXY(69, 9);
	cout << "\t" << setw(11) << "Trang Thai Lop" << "     " << setw(5) << "Ma lop tin chi " << "  " << setw(20) << "Ten mon hoc"  << setw(7) << "               " << "Nhom";
	// vẽ đường kẻ
	for (int i = 0; i < 86; i++)
	{
		SetConsoleTextAttribute(hConsoleColor, 15);
		gotoXY(69 + i, 10);
		cout << char(196);
	}
	int sl = 0;
	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->nien_khoa == nien_khoa && ds.Lop_Tin_Chi[i]->hoc_ky == hoc_ky)
		{
			int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI);
			if (sl_sv_con_dang_ky < ds.Lop_Tin_Chi[i]->so_sv_min)
			{
				SetConsoleTextAttribute(hConsoleColor, 10);
				gotoXY(69, 11 + sl);
				sl++;
				cout << "\t" << setw(13) << "Huy Dang Ky";
				ds.Lop_Tin_Chi[i]->trang_thai_lop = 0;
				cout << "           "<< setw(2) << ds.Lop_Tin_Chi[i]->maLopTinCHi;
				Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds.Lop_Tin_Chi[i]->ma_mh);
				cout <<  "           " << setw(27) << p->data.ten_mh;
				cout << setw(9) << ds.Lop_Tin_Chi[i]->nhom;
				for (int i = 0; i < 86; i++)
				{
					SetConsoleTextAttribute(hConsoleColor, 15);
					gotoXY(69 + i, 11 + sl);
					cout << char(196);
				}
				sl++;
			}
		}
	}
}

void in_ds_lop_tc_sau_khi_loc_new(DS_LOP_TIN_CHI ds, DANH_SACH_MON_HOC ds_mh)
{
	SetColor(11);
	gotoXY(81, 15); // --------------------- ô sáng đầu tiên ---------------------
	cout << "NHAP NIEN KHOA:";
	box(100, 14, 18, 2, 14, 0, "");

	SetColor(11);
	gotoXY(81, 19);
	cout << "NHAP HOC KY:";
	box(100, 18, 18, 2, 11, 0, "");

	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 177);
	gotoXY(95, 22);
	cout << "          ";
	gotoXY(95, 23);
	cout << " TRUY CAP ";
	gotoXY(95, 24);
	cout << "          ";

	string nk_hk[2];
	int y_sang_nk_hk = 14;

	while (77)
	{
		char c = _getch();
		if (c >= 47 && c <= 57)
		{
			if (y_sang_nk_hk == 14)
			{
				nk_hk[0].push_back(c);
				box(100, 14, 18, 2, 14, 0, nk_hk[0]);
			}
			else if (y_sang_nk_hk == 18)
			{
				nk_hk[1].push_back(c);
				box(100, 18, 18, 2, 14, 0, nk_hk[1]);
			}
		}
		else if (c == 13) // enter
		{
			if (y_sang_nk_hk == 22)
			{
				SetConsoleTextAttribute(hConsoleColor, 0);
				xoa_giao_dien_mo_lop_tin_chi();
				// in danh sách các lớp tín chỉ đuọc mở theo niên khoá và học kỳ
				break;
			}
		}
		else if (c == 8)
		{
			if (y_sang_nk_hk == 14 && !nk_hk[0].empty())
			{
				nk_hk[0].pop_back();
				box(100, 14, 18, 2, 14, 0, nk_hk[0]);
			}
			else if (y_sang_nk_hk == 18 && !nk_hk[1].empty())
			{
				nk_hk[1].pop_back();
				box(100, 18, 18, 2, 14, 0, nk_hk[1]);
			}
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 72) // lên
			{
				if (y_sang_nk_hk > 14)
				{
					if (y_sang_nk_hk == 18)
					{
						// tắt thanh sáng cũ
						box(100, 18, 18, 2, 11, 0, nk_hk[1]);
						y_sang_nk_hk -= 4;
						// bật thanh sáng mới
						box(100, 14, 18, 2, 14, 0, nk_hk[0]);
					}
					if (y_sang_nk_hk == 22)
					{
						// tắt thanh sáng cũ
						SetConsoleTextAttribute(hConsoleColor, 177);
						gotoXY(95, 22);
						cout << "          ";
						gotoXY(95, 23);
						cout << " TRUY CAP ";
						gotoXY(95, 24);
						cout << "          ";
						y_sang_nk_hk -= 4;
						// bật thanh sáng mới
						box(100, 18, 18, 2, 14, 0, nk_hk[1]);
					}
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang_nk_hk < 22)
				{
					// tắt thanh sáng cũ
					if (y_sang_nk_hk == 14)
					{
						box(100, 14, 18, 2, 11, 0, nk_hk[0]);
						y_sang_nk_hk += 4;
						// bật thanh sáng mới
						box(100, 18, 18, 2, 14, 0, nk_hk[1]);
					}
					else if (y_sang_nk_hk == 18)
					{
						// tắt thanh sáng cũ
						box(100, 18, 18, 2, 11, 0, nk_hk[1]);
						y_sang_nk_hk += 4;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 233);
						gotoXY(95, 22);
						cout << "          ";
						gotoXY(95, 23);
						cout << " TRUY CAP ";
						gotoXY(95, 24);
						cout << "          ";
					}
				}
			}
		}
	}
	int nien_khoa = atoi(nk_hk[0].c_str());
	int hoc_ky = atoi(nk_hk[1].c_str());
	// in danh sách
	while (77)
	{
		
		SetConsoleTextAttribute(hConsoleColor, 237);
		gotoXY(93, 4);
		cout << "                                               ";
		gotoXY(93, 5);
		cout << " DANH SACH CAC LOP TIN CHI DUOC MO SAU KHI LOC ";

		SetConsoleTextAttribute(hConsoleColor, 225);
		gotoXY(91, 6);
		cout << " " << "Nien Khoa: " << nien_khoa << " - Hoc Ky: " << hoc_ky << " ";
		SetConsoleTextAttribute(hConsoleColor, 11);
		gotoXY(69, 9);
		cout  << setw(5) << "Ma lop tin chi " << "    " << setw(20) << "Ten mon hoc" << setw(7) << "               " << "Nhom" << setw(2) << "     " << "So Sinh vien da dang ky";
		// vẽ đường kẻ
		for (int i = 0; i < 86; i++)
		{
			SetConsoleTextAttribute(hConsoleColor, 15);
			gotoXY(69 + i, 10);
			cout << char(196);
		}
		int sl = 0;
		for (int i = 0; i < ds.sl; i++)
		{
			if (ds.Lop_Tin_Chi[i]->nien_khoa == nien_khoa && ds.Lop_Tin_Chi[i]->hoc_ky == hoc_ky)
			{
				if (ds.Lop_Tin_Chi[i]->nien_khoa == nien_khoa && ds.Lop_Tin_Chi[i]->hoc_ky == hoc_ky && ds.Lop_Tin_Chi[i]->trang_thai_lop == 1)
				{
					SetConsoleTextAttribute(hConsoleColor, 10);
					gotoXY(69, 11 + sl);
					sl++;
					ds.Lop_Tin_Chi[i]->trang_thai_lop = 0;
					cout << "   "<< setw(2) << ds.Lop_Tin_Chi[i]->maLopTinCHi;
					Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds.Lop_Tin_Chi[i]->ma_mh);
					cout << "             " << setw(27) << p->data.ten_mh << "  ";
					cout << setw(9) << ds.Lop_Tin_Chi[i]->nhom;
					int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI);
					cout << setw(16) << sl_sv_con_dang_ky;

					// vẽ đường kẻ
					for (int i = 0; i < 86; i++)
					{
						SetConsoleTextAttribute(hConsoleColor, 15);
						gotoXY(69 + i, 11 + sl);
						cout << char(196);
					}
					sl++;
				}
			}
		}

		char c = _getch();
		if (c == 27)
		{
			SetConsoleTextAttribute(hConsoleColor, 0);
			break;
		}
	}
}

// ================================ NHẬP ĐIỂM ======================================
void menu_con_nhap_diem_sinh_vien(Sinh_Vien ds[], int sl_sv, DANH_SACH_MON_HOC ds_mh, DS_LOP_TIN_CHI &ds_lop_tc)
{
	SetColor(11);
	gotoXY(7, 15);
	cout << "1. Nhap diem cho 1 lop tin chi";
	gotoXY(7, 16);
	cout << "2. In bang diem cua 1 lop tin chi";
	gotoXY(7, 17);
	cout << "3. Thoat";
	

	int x_sang = 7;
	int y_sang = 15;
	// ------- hiện thanh sáng
	m.lock();
	gotoXY(x_sang, y_sang);
	textcolor(70);
	cout << "                              ";
	gotoXY(x_sang, y_sang);
	SetColor(11);
	cout << "1. Nhap diem cho 1 lop tin chi";
	textcolor(0);
	m.unlock();
	// -------------- di chuyển của menu con
	int cong_tac_dau_nhay = 0; // CÔNG TẮC KHI NHẤN PHÍM ENTER

	while (77)
	{
		// ------------------ xử lí lệnh nhập điểm cho sinh viên
		if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 15)
		{
			giao_dien_nhap_diem_cho_sinh_vien(cong_tac_dau_nhay, ds, sl_sv, ds_mh, ds_lop_tc);
		}
		// ------------------ xử lí lệnh xem dan sách điểm
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 16)
		{
			giao_dien_xem_ds_diem_1_lop_tc_giao_dien_xem(cong_tac_dau_nhay, ds, sl_sv, ds_mh, ds_lop_tc);
		}
		// ------------------- thoát
		else if (cong_tac_dau_nhay == 1 && x_sang == 7 && y_sang == 17)
		{
			break;
		}
		// menu nhỏ ======================= LUỒNG  CHÍNH CỦA MENU NHỎ
		char c = _getch();
		// đã nhấn phím enter
		if (c == 13)
		{
			// nhấp số lượng lớp tín chỉ cần thêm
			if (x_sang == 7 && y_sang == 15 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			// xem lớp tín chỉ
			else if (x_sang == 7 && y_sang == 16 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
			else if (x_sang == 7 && y_sang == 17 && cong_tac_dau_nhay == 0)
			{
				cong_tac_dau_nhay = 1;
			}
		}
		if (cong_tac_dau_nhay == 0)
		{
			if (c == -32)
			{
				c = _getch();
				if (c == 72) // đi lên
				{
					if (y_sang > 15)
					{
						int y_cu = y_sang;

						// xóa thanh sang sáng cũ
						if (x_sang == 7 && y_cu == 16)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                                 ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "2. In bang diem cua 1 lop tin chi";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 17)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "        ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "3. Thoat";
							m.unlock();
						}
						y_sang--;
						// hiển thị lại thanh sáng mới
						if (x_sang == 7 && y_sang == 15)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                              ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "1. Nhap diem cho 1 lop tin chi";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 16)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                  ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "2. In bang diem cua 1 lop tin chi";
							textcolor(0);
							m.unlock();
						}
					}
				}
				else if (c == 80) // đi xuống
				{
					if (y_sang < 17)
					{
						int y_cu = y_sang;
						// xóa thanh sang sáng cũ
						if (x_sang == 7 && y_cu == 15)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                   ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "1. Nhap diem cho 1 lop tin chi";
							m.unlock();
						}
						else if (x_sang == 7 && y_cu == 16)
						{
							m.lock();
							gotoXY(x_sang, y_cu);
							textcolor(0);
							cout << "                                 ";
							gotoXY(x_sang, y_cu);
							SetColor(11);
							cout << "2. In bang diem cua 1 lop tin chi";
							m.unlock();
						}
						
						y_sang++;
						// hiện thanh sáng mới
						if (x_sang == 7 && y_sang == 16)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "                                 ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "2. In bang diem cua 1 lop tin chi";
							textcolor(0);
							m.unlock();
						}
						else if (x_sang == 7 && y_sang == 17)
						{
							m.lock();
							gotoXY(x_sang, y_sang);
							textcolor(70);
							cout << "        ";
							gotoXY(x_sang, y_sang);
							SetColor(11);
							cout << "3. Thoat";
							textcolor(0);
							m.unlock();
						}
					}
				}
			}
		}

	}
}

void giao_dien_nhap_diem_cho_sinh_vien(int &cong_tac_dau_nhay, Sinh_Vien ds_sv[], int sl_sv, DANH_SACH_MON_HOC ds_mh, DS_LOP_TIN_CHI &ds_lop_tc)
{
		HANDLE hConsoleColor;
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

		// chữ tiêu đề
		SetColor(10);
		gotoXY(83, 10);
		cout << "Nhap nien khoa: ";
		gotoXY(83, 14);
		cout << "Nhap hoc ky:";
		gotoXY(83, 18);
		cout << "Nhap nhom:";
		gotoXY(83, 22);
		cout << "Nhap ma moc hoc:";

		// khung nhập
		box(108, 9, 20, 2, 14, 0, "");
		box(108, 13, 20, 2, 11, 0, "");
		box(108, 17, 20, 2, 11, 0, "");
		box(108, 21, 20, 2, 11, 0, "");

		// nút truy cập
		
		SetConsoleTextAttribute(hConsoleColor, 177);
		gotoXY(95, 25);
		cout << "          ";
		gotoXY(95, 26);
		cout << " TRUY CAP ";
		gotoXY(95, 27);
		cout << "          ";

		// di chuyển
		int y_sang = 9;
		string tt_input[4];
		while (77)
		{
			char c = _getch();
			if (c >= 48 && c <= 57)
			{
				if (y_sang == 9)
				{
					tt_input[0].push_back(c);
					box(108, 9, 20, 2, 14, 0, tt_input[0]);
				}
				else if (y_sang == 13)
				{
					tt_input[1].push_back(c);
					box(108, 13, 20, 2, 14, 0, tt_input[1]);
				}
				else if (y_sang == 17)
				{
					tt_input[2].push_back(c);
					box(108, 17, 20, 2, 14, 0, tt_input[2]);
				}
				else if (y_sang == 21)
				{
					tt_input[3].push_back(c);
					box(108, 21, 20, 2, 14, 0, tt_input[3]);
				}
			}
			else if (c == 13)
			{
				if (y_sang == 25)
				{
					int check = 0;
					if (tt_input[0].empty())
					{
						box(108, 9, 20, 2, 12, 0, "");
						check = 1;
					}
					if (tt_input[1].empty())
					{
						box(108, 13, 20, 2, 12, 0, "");
						check = 1;
					}
					if (tt_input[2].empty())
					{
						box(108, 17, 20, 2, 12, 0, "");
						check = 1;
					}
					if (tt_input[3].empty())
					{
						box(108, 21, 20, 2, 12, 0, "");
						check = 1;
					}
					if (check == 1)
					{

						SetConsoleTextAttribute(hConsoleColor, 12);
						gotoXY(117, 29);
						cout << "Khong duoc de trong du lieu!";
					}
					else if (check == 0)
					{

						// kiểm tra thông tin nhập có tồn tại
						if (kt_lop_tc_ton_tai_theo_nk_nhom_hk_mamh(ds_lop_tc, atoi(tt_input[0].c_str()), atoi(tt_input[1].c_str()), atoi(tt_input[2].c_str()), atoi(tt_input[3].c_str())) == -1)
						{
							SetConsoleTextAttribute(hConsoleColor, 12);
							gotoXY(117, 29);
							cout << "Lop khong ton tai";
						}
						else
						{
							break;
						}
						
						// nếu kiểm tra điều kiện đúng thì thoát khỏi vòng lặp	
					}
				}
			}
			else if (c == 8)
			{
				if (y_sang == 9 && !tt_input[0].empty())
				{
					tt_input[0].pop_back();
					box(108, 9, 20, 2, 14, 0, tt_input[0]);
				}
				else if (y_sang == 13 && !tt_input[1].empty())
				{
					tt_input[1].pop_back();
					box(108, 13, 20, 2, 14, 0, tt_input[1]);
				}
				else if (y_sang == 17 && !tt_input[2].empty())
				{
					tt_input[2].pop_back();
					box(108, 17, 20, 2, 14, 0, tt_input[2]);
				}
				else if (y_sang == 21 && !tt_input[3].empty())
				{
					tt_input[3].pop_back();
					box(108, 21, 20, 2, 14, 0, tt_input[3]);
				}
			}
			else if (c == -32)
			{
				c = _getch();
				if (c == 72) // lên
				{
					if (y_sang > 9)
					{
						// tắt thanh sáng
						if (y_sang == 13)
						{
							box(108, y_sang, 20, 2, 11, 0, tt_input[1]);
						}
						else if (y_sang == 17)
						{
							box(108, y_sang, 20, 2, 11, 0, tt_input[2]);
						}
						else if (y_sang == 21)
						{
							box(108, y_sang, 20, 2, 11, 0, tt_input[3]);
						}
						else if (y_sang == 25)
						{
							SetConsoleTextAttribute(hConsoleColor, 0);
							gotoXY(117, 29);
							cout << "                            ";
							SetConsoleTextAttribute(hConsoleColor, 177);
							gotoXY(95, 25);
							cout << "          ";
							gotoXY(95, 26);
							cout << " TRUY CAP ";
							gotoXY(95, 27);
							cout << "          ";
						}
						y_sang -= 4;
						// bật thanh sáng mới
						if (y_sang == 9)
						{
							box(108, 9, 20, 2, 14, 0, tt_input[0]);
						}
						else if (y_sang == 13)
						{
							box(108, 13, 20, 2, 14, 0, tt_input[1]);
						}
						else if (y_sang == 17)
						{
							box(108, 17, 20, 2, 14, 0, tt_input[2]);
						}
						else if (y_sang == 21)
						{
							box(108, 21, 20, 2, 14, 0, tt_input[3]);
						}
					}
				}
				else if (c == 80) // xuống
				{
					if (y_sang < 25)
					{
						// tắt thanh sáng
						if (y_sang == 9)
						{
							box(108, y_sang, 20, 2, 11, 0, tt_input[0]);
						}
						if (y_sang == 13)
						{
							box(108, y_sang, 20, 2, 11, 0, tt_input[1]);
						}
						else if (y_sang == 17)
						{
							box(108, y_sang, 20, 2, 11, 0, tt_input[2]);
						}
						else if (y_sang == 21)
						{
							box(108, y_sang, 20, 2, 11, 0, tt_input[3]);
						}

						y_sang += 4;
						// bật thanh sáng mới
						if (y_sang == 13)
						{
							box(108, 13, 20, 2, 14, 0, tt_input[1]);
						}
						else if (y_sang == 17)
						{
							box(108, 17, 20, 2, 14, 0, tt_input[2]);
						}
						else if (y_sang == 21)
						{
							box(108, 21, 20, 2, 14, 0, tt_input[3]);
						}
						else if (y_sang == 25)
						{
							SetConsoleTextAttribute(hConsoleColor, 233);
							gotoXY(95, 25);
							cout << "          ";
							gotoXY(95, 26);
							cout << " TRUY CAP ";
							gotoXY(95, 27);
							cout << "          ";
						}
					}
				}
			}
		}

		// lấy ra lớp tín chỉ để xuất
		int vt_lop = kt_lop_tc_ton_tai_theo_nk_nhom_hk_mamh(ds_lop_tc, atoi(tt_input[0].c_str()), atoi(tt_input[1].c_str()), atoi(tt_input[2].c_str()), atoi(tt_input[3].c_str()));
		
		SetConsoleTextAttribute(hConsoleColor, 0);
		xoa_giao_dien_mo_lop_tin_chi();

		Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, atoi(tt_input[3].c_str()));
		string ten_mh = p->data.ten_mh;
		// in danh sách điểm của một lớp tín chỉ
		in_ds_diem_cua_1_lop_tc(ds_lop_tc.Lop_Tin_Chi[vt_lop]->DS_SV_DANG_KY_TIN_CHI, ds_sv, sl_sv, atoi(tt_input[0].c_str()), atoi(tt_input[1].c_str()), atoi(tt_input[2].c_str()),ten_mh);

		SetConsoleTextAttribute(hConsoleColor, 0);
		xoa_giao_dien_mo_lop_tin_chi();
		cong_tac_dau_nhay = 0;
		ghi_file_diem_cho_sv(ds_lop_tc);
}

int kt_lop_tc_ton_tai_theo_nk_nhom_hk_mamh(DS_LOP_TIN_CHI ds_ltc, int nk, int hk, int nhom, int ma_mh)
{
	for (int i = 0; i < ds_ltc.sl; i++)
	{
		if (ds_ltc.Lop_Tin_Chi[i]->trang_thai_lop == 1)
		{
			if (ds_ltc.Lop_Tin_Chi[i]->trang_thai_lop == 1 && ds_ltc.Lop_Tin_Chi[i]->nien_khoa == nk && ds_ltc.Lop_Tin_Chi[i]->hoc_ky == hk && ds_ltc.Lop_Tin_Chi[i]->nhom == nhom && ds_ltc.Lop_Tin_Chi[i]->ma_mh == ma_mh)
			{
				return i;
			}
		}

	}
	return -1;
}

void in_ds_diem_cua_1_lop_tc(DSSV_DANG_KY_TIN_CHI &ds_sv_dk, Sinh_Vien ds_sv[], int sl_sv,int nk,int hk,int nhom,string ten_mh)
{
	// sắp xếp điểm của sinh viên
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds_sv_dk.pHead; k != NULL; k = k->pNext)
	{
		for (NODE_SV_DANG_KY_TIN_CHI *h = k->pNext; h != NULL; h = h->pNext)
		{
			if (k->data.diem < h->data.diem)
			{
				SINH_VIEN_DANG_KY_TIN_CHI tam = k->data;
				k->data = h->data;
				h->data = tam;
			}
		}
	}

	// in danh sách sinh viên
	
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);


	SetConsoleTextAttribute(hConsoleColor, 10);
	gotoXY(72, 5);
	cout << ",-----.    ,---.  ,--.  ,--. ,----.       ,------.  ,--.,------.,--.   ,--.";
	gotoXY(72, 6);
	cout << "|  |) /_  /  O  " << char(92) << " |  ,'.|  |'  .-./       |  .-.  " << char(92) << " |  ||  .---'|   `.'   |";
	gotoXY(72, 7);
	cout << "|  .-.  " << char(92) << "|  .-.  ||  |' '  ||  | .---.    |  |  " << char(92) << "  :|  ||  `--, |  |'.'|  |";
	gotoXY(72, 8);
	cout << "|  '--' /|  | |  ||  | `   |'  '--'  |    |  '--'  /|  ||  `---.|  |   |  |";
	gotoXY(72, 9);
	cout << "`------' `--' `--'`--'  `--' `------'     `-------' `--'`------'`--'   `--' ";
	int  sl_sv_con_dk = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_sv_dk);
	box(75, 12, 68, 2 + sl_sv_con_dk * 2, 14, 0, "");
	gotoXY(91, 10);
	cout << "TEN MON HOC : " << ten_mh;
	gotoXY(91, 11);
	cout << "Nien Khoa: " << nk << " - Hoc Ky: " << hk << " - Nhom: " << nhom << endl << endl;
	
	box(75, 12, 68, 2,14, 0, "");
	gotoXY(82, 13);
	SetConsoleTextAttribute(hConsoleColor, 11);
	cout << setw(3) << "STT" << "\t" << setw(9) << "MASV" << setw(25) << "HO VA TEN" << "\t" << setw(2) << "   DIEM";
	
	int stt = 1;
	int can_dong = 0;
	// in ra danh sách sinh viên
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds_sv_dk.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.trang_thai_dang_ky == 1)
		{
			for (int i = 0; i < sl_sv; i++)
			{
				if (_stricmp(k->data.ma_sv.c_str(), ds_sv[i].ma_sv.c_str()) == 0)
				{
					SetConsoleTextAttribute(hConsoleColor, 15);
					gotoXY(82, 15 + can_dong);
					string hoten = ds_sv[i].ho + " " + ds_sv[i].ten;
					cout << setw(2) << stt  << "\t  " << setw(9) << k->data.ma_sv << setw(25) << hoten << "\t";
					//vẽ đường kẻ
					for (int ke = 0; ke < 66; ke++)
					{
						gotoXY(77 + ke, 16 + can_dong);
						cout << char(196);
					}
					can_dong += 2;
					stt++;
				}
			}
		}
	}

	// fix tuong
	SetConsoleTextAttribute(hConsoleColor, 14);
	gotoXY(75, 14);
	cout << char(179);
	gotoXY(143, 14);
	cout << char(179);

	
	string ds_diem[70];
	int sl_diem = 0;
	// truyền điểm vào ds_diem
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds_sv_dk.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.trang_thai_dang_ky == 1 && k->data.diem != NULL)
		{
			ds_diem[sl_diem] = float_to_string(k->data.diem);
			sl_diem++;
		}
		else
		{
			sl_diem++;
		}
	}

	// fix lại từng ô điểm đã nhập và chưa nhập

	sl_diem = 0;
	for (int mk = 0; mk < sl_sv_con_dk; mk++)
	{
		if (ds_diem[mk].empty())
		{
			gotoXY(128, 15 + mk * 2);
			cout << "Chua nhap diem";
		}
		else
		{
			gotoXY(132, 15 + mk * 2);
			cout << ds_diem[mk];
		}
	}

	// ô sáng đầu tiên
	SetConsoleTextAttribute(hConsoleColor, 253);
	if (ds_diem[0].empty())
	{
		gotoXY(128, 15);
		cout << "Chua nhap diem";
	}
	else
	{
		gotoXY(132, 15 + 0 * 2);
		cout << ds_diem[0];
	}
	// box enter
	SetConsoleTextAttribute(hConsoleColor, 176);
	gotoXY(110, 14 + sl_sv_con_dk * 2 + 3);
	cout << "       ";
	gotoXY(110, 15 + sl_sv_con_dk * 2 + 3);
	cout << " Enter ";
	gotoXY(110, 16 + sl_sv_con_dk * 2 + 3);
	cout << "       ";

	// di chuyển nhập điểm
	while (true)
	{
		char c = _getch();
		if (c == 13) //enter
		{
			if (sl_diem == sl_sv_con_dk)
			{
				bool false_input = false;
				// kiểm tra dữ liệu truyền vào đã đúng hay chưa
				for (int h = 0; h < sl_sv_con_dk; h++)
				{
					if (kt_du_lieu_diem_input(ds_diem[h]) == -2)
					{
						gotoXY(145, 15 + h * 2);
						SetConsoleTextAttribute(hConsoleColor, 12);
						cout << char(26) << " False input data!";
						false_input = true;
					}
					else if(kt_du_lieu_diem_input(ds_diem[h]) == -1)
					{
						gotoXY(145, 15 + h * 2);
						SetConsoleTextAttribute(hConsoleColor, 12);
						cout << char(26) << "Empty data!";
						false_input = true;
					}
				}
				if (false_input == false)
				{
					int sl_ = 0;
					for (NODE_SV_DANG_KY_TIN_CHI *k = ds_sv_dk.pHead; k != NULL; k = k->pNext)
					{
						if (k->data.trang_thai_dang_ky == 1)
						{
							if (ds_diem[sl_].empty())
							{
								sl_++;
							}
							else
							{
								k->data.diem = to_Float(ds_diem[sl_++]);
							}
						}
					}
					break;
				}
			}
		}
		if (c >= 48 && c <= 57 || c == 46)
		{
			if (sl_diem < sl_sv_con_dk)
			{
				ds_diem[sl_diem].push_back(c);
				SetConsoleTextAttribute(hConsoleColor, 0);
				gotoXY(128, 15 + sl_diem * 2);
				cout << "              ";
				SetConsoleTextAttribute(hConsoleColor, 253);
				gotoXY(132, 15 + sl_diem * 2);
				cout << ds_diem[sl_diem];
			}
		}
		else if (c == 8) // backspace
		{
			if (!ds_diem[sl_diem].empty())
			{
				SetConsoleTextAttribute(hConsoleColor, 0);
				gotoXY(132, 15 + sl_diem * 2);
				cout << "           ";
				ds_diem[sl_diem].pop_back();
				SetConsoleTextAttribute(hConsoleColor, 253);
				gotoXY(132, 15 + sl_diem * 2);
				cout << ds_diem[sl_diem];
			}
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 72) // lên
			{
				if (sl_diem > 0)
				{
					// xoá dữ liêu cũ
					for (int h = 0; h < sl_sv_con_dk; h++)
					{
							gotoXY(145, 15 + h * 2);
							SetConsoleTextAttribute(hConsoleColor, 12);
							cout << "                   ";
					}

					if (sl_diem == sl_sv_con_dk)
					{
						// tắt thanh sáng cũ
						SetConsoleTextAttribute(hConsoleColor, 176);
						gotoXY(110, 14 + sl_sv_con_dk * 2 + 3);
						cout << "       ";
						gotoXY(110, 15 + sl_sv_con_dk * 2 + 3);
						cout << " Enter ";
						gotoXY(110, 16 + sl_sv_con_dk * 2 + 3);
						cout << "       ";

						sl_diem--;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 253);
						if (ds_diem[sl_diem].empty())
						{
							gotoXY(128, 15 + sl_diem * 2);
							cout << "Chua nhap diem";
						}
						else
						{
							gotoXY(132, 15 + sl_diem * 2);
							cout << ds_diem[sl_diem];
						}
					}
					else
					{
						// tắt thanh sáng 
						SetConsoleTextAttribute(hConsoleColor, 15);
						gotoXY(128, 15 + sl_diem * 2);
						if (ds_diem[sl_diem].empty())
						{
							gotoXY(128, 15 + sl_diem * 2);
							cout << "Chua nhap diem";
						}
						else
						{
							gotoXY(132, 15 + sl_diem * 2);
							cout << ds_diem[sl_diem];
						}
						sl_diem--;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 253);
						if (ds_diem[sl_diem].empty())
						{
							gotoXY(128, 15 + sl_diem * 2);
							cout << "Chua nhap diem";
						}
						else
						{
							gotoXY(132, 15 + sl_diem * 2);
							cout << ds_diem[sl_diem];
						}
					}
				}
			}
			else if (c == 80) // xuống
			{
				if (sl_diem < sl_sv_con_dk)
				{
					if (sl_diem == sl_sv_con_dk - 1)
					{
						// tắt thanh sáng cũ
						SetConsoleTextAttribute(hConsoleColor, 15);
						if (ds_diem[sl_diem].empty())
						{
							gotoXY(128, 15 + sl_diem * 2);
							cout << "Chua nhap diem";
						}
						else
						{
							gotoXY(132, 15 + sl_diem * 2);
							cout << ds_diem[sl_diem];
						}
						sl_diem++;
						// bật thanh sáng mới
						// box enter
						SetConsoleTextAttribute(hConsoleColor, 228);
						gotoXY(110, 14 + sl_sv_con_dk * 2 + 3);
						cout << "       ";
						gotoXY(110, 15 + sl_sv_con_dk * 2 + 3);
						cout << " Enter ";
						gotoXY(110, 16 + sl_sv_con_dk * 2 + 3);
						cout << "       ";
					}
					else
					{
						// tắt thanh sáng 
						SetConsoleTextAttribute(hConsoleColor, 15);
						if (ds_diem[sl_diem].empty())
						{
							gotoXY(128, 15 + sl_diem * 2);
							cout << "Chua nhap diem";
						}
						else
						{
							gotoXY(132, 15 + sl_diem * 2);
							cout << ds_diem[sl_diem];
						}
						sl_diem++;
						// bật thanh sáng mới
						SetConsoleTextAttribute(hConsoleColor, 253);
						gotoXY(128, 15 + sl_diem * 2);
						if (ds_diem[sl_diem].empty())
						{
							gotoXY(128, 15 + sl_diem * 2);
							cout << "Chua nhap diem";
						}
						else
						{
							gotoXY(132, 15 + sl_diem * 2);
							cout << ds_diem[sl_diem];
						}
					}
				}
			}
		}
	}
}

int kt_du_lieu_diem_input(string diem)
{
	if (diem.empty())
	{
		return -1;
	}
	// chuỗi sai điều kiện
	int check_dau_cham = 0;
	for (int i = 0; i < diem.length(); i++)
	{
		if (diem.at(i) == '.')
		{
			check_dau_cham++;
		}
	}
	if (diem.at(0) == '.')
	{
		return -2;
	}
	if (diem == "10" | diem == "10.0")
	{
		return 1;
	}
	if (diem.length() == 2)
	{
		if ((diem.at(0) >= 48 && diem.at(0) <= 57) && (diem.at(1) >= 48 && diem.at(1) <= 57))
		{
			return -2;
		}
	}
	if (diem.length() == 3)
	{
		if (diem.at(1) != '.')
		{
			return -2;
		}
	}
	if (check_dau_cham > 1)
	{
		return -2;
	}
	if (diem.length() == 1 && diem.at(0) == '.')
	{
		return -2;
	}
	if (diem.length() == 2 && diem.at(1) == '.')
	{
		return -2;
	}
	if (diem.length() > 3)
	{
		return -2;
	}
	if (diem.length() == 3 && diem.at(2) == ',')
	{
		return -2;
	}
	return 1;
}

float to_Float(string diem)
{
	float a = 0;
	if (diem == "10" || diem == "10.0")
	{
		a = 10;
	}
	else if (diem.length() == 3)
	{
		if (diem.at(0) >= 48 && diem.at(0) <= 57)
		{
			a = diem.at(0) - 48;
		}
		if (diem.at(2) >= 48 && diem.at(2) <= 57)
		{
			float du = diem.at(2) - 48;
			du /= 10;
			a += du;
		}
	}
	else if (diem.length() == 1)
	{
		a = diem.at(0) - 48;
	}
	return a;
}

string float_to_string(float a)
{
	string s = "";
	if (a == 10)
	{
		s = to_string(10);
		return s;
	}
	float sd = 0;
	for (int i = 0; i < 9; i++)
	{
		if (a - i < 1)
		{
			// đây là số thực
			sd = a - i;
			break;
		}
		else if (a - i == 0)
		{
			int tam = a;
			s = to_string(tam);
			return s;
		}
	}
	s = (a - sd) + 48;
	s.push_back('.');
	sd *= 10;
	s.push_back(sd + 48);
	return s;
}

void giao_dien_xem_ds_diem_1_lop_tc_giao_dien_xem(int &cong_tac_dau_nhay, Sinh_Vien ds_sv[], int sl_sv, DANH_SACH_MON_HOC ds_mh, DS_LOP_TIN_CHI &ds_lop_tc)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

	// chữ tiêu đề
	SetColor(10);
	gotoXY(83, 10);
	cout << "Nhap nien khoa: ";
	gotoXY(83, 14);
	cout << "Nhap hoc ky:";
	gotoXY(83, 18);
	cout << "Nhap nhom:";
	gotoXY(83, 22);
	cout << "Nhap ma moc hoc:";

	// khung nhập
	box(108, 9, 20, 2, 14, 0, "");
	box(108, 13, 20, 2, 11, 0, "");
	box(108, 17, 20, 2, 11, 0, "");
	box(108, 21, 20, 2, 11, 0, "");

	// nút truy cập

	SetConsoleTextAttribute(hConsoleColor, 177);
	gotoXY(95, 25);
	cout << "          ";
	gotoXY(95, 26);
	cout << " TRUY CAP ";
	gotoXY(95, 27);
	cout << "          ";

	// di chuyển
	int y_sang = 9;
	string tt_input[4];
	while (77)
	{
		char c = _getch();
		if (c >= 48 && c <= 57)
		{
			if (y_sang == 9)
			{
				tt_input[0].push_back(c);
				box(108, 9, 20, 2, 14, 0, tt_input[0]);
			}
			else if (y_sang == 13)
			{
				tt_input[1].push_back(c);
				box(108, 13, 20, 2, 14, 0, tt_input[1]);
			}
			else if (y_sang == 17)
			{
				tt_input[2].push_back(c);
				box(108, 17, 20, 2, 14, 0, tt_input[2]);
			}
			else if (y_sang == 21)
			{
				tt_input[3].push_back(c);
				box(108, 21, 20, 2, 14, 0, tt_input[3]);
			}
		}
		else if (c == 13)
		{
			if (y_sang == 25)
			{
				int check = 0;
				if (tt_input[0].empty())
				{
					box(108, 9, 20, 2, 12, 0, "");
					check = 1;
				}
				if (tt_input[1].empty())
				{
					box(108, 13, 20, 2, 12, 0, "");
					check = 1;
				}
				if (tt_input[2].empty())
				{
					box(108, 17, 20, 2, 12, 0, "");
					check = 1;
				}
				if (tt_input[3].empty())
				{
					box(108, 21, 20, 2, 12, 0, "");
					check = 1;
				}
				if (check == 1)
				{

					SetConsoleTextAttribute(hConsoleColor, 12);
					gotoXY(117, 29);
					cout << "Khong duoc de trong du lieu!";
				}
				else if (check == 0)
				{

					// kiểm tra thông tin nhập có tồn tại
					if (kt_lop_tc_ton_tai_theo_nk_nhom_hk_mamh(ds_lop_tc, atoi(tt_input[0].c_str()), atoi(tt_input[1].c_str()), atoi(tt_input[2].c_str()), atoi(tt_input[3].c_str())) == -1)
					{
						SetConsoleTextAttribute(hConsoleColor, 12);
						gotoXY(117, 29);
						cout << "Lop khong ton tai";
					}
					else
					{
						break;
					}

					// nếu kiểm tra điều kiện đúng thì thoát khỏi vòng lặp	
				}
			}
		}
		else if (c == 8)
		{
			if (y_sang == 9 && !tt_input[0].empty())
			{
				tt_input[0].pop_back();
				box(108, 9, 20, 2, 14, 0, tt_input[0]);
			}
			else if (y_sang == 13 && !tt_input[1].empty())
			{
				tt_input[1].pop_back();
				box(108, 13, 20, 2, 14, 0, tt_input[1]);
			}
			else if (y_sang == 17 && !tt_input[2].empty())
			{
				tt_input[2].pop_back();
				box(108, 17, 20, 2, 14, 0, tt_input[2]);
			}
			else if (y_sang == 21 && !tt_input[3].empty())
			{
				tt_input[3].pop_back();
				box(108, 21, 20, 2, 14, 0, tt_input[3]);
			}
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 72) // lên
			{
				if (y_sang > 9)
				{
					// tắt thanh sáng
					if (y_sang == 13)
					{
						box(108, y_sang, 20, 2, 11, 0, tt_input[1]);
					}
					else if (y_sang == 17)
					{
						box(108, y_sang, 20, 2, 11, 0, tt_input[2]);
					}
					else if (y_sang == 21)
					{
						box(108, y_sang, 20, 2, 11, 0, tt_input[3]);
					}
					else if (y_sang == 25)
					{
						SetConsoleTextAttribute(hConsoleColor, 0);
						gotoXY(117, 29);
						cout << "                            ";
						SetConsoleTextAttribute(hConsoleColor, 177);
						gotoXY(95, 25);
						cout << "          ";
						gotoXY(95, 26);
						cout << " TRUY CAP ";
						gotoXY(95, 27);
						cout << "          ";
					}
					y_sang -= 4;
					// bật thanh sáng mới
					if (y_sang == 9)
					{
						box(108, 9, 20, 2, 14, 0, tt_input[0]);
					}
					else if (y_sang == 13)
					{
						box(108, 13, 20, 2, 14, 0, tt_input[1]);
					}
					else if (y_sang == 17)
					{
						box(108, 17, 20, 2, 14, 0, tt_input[2]);
					}
					else if (y_sang == 21)
					{
						box(108, 21, 20, 2, 14, 0, tt_input[3]);
					}
				}
			}
			else if (c == 80) // xuống
			{
				if (y_sang < 25)
				{
					// tắt thanh sáng
					if (y_sang == 9)
					{
						box(108, y_sang, 20, 2, 11, 0, tt_input[0]);
					}
					if (y_sang == 13)
					{
						box(108, y_sang, 20, 2, 11, 0, tt_input[1]);
					}
					else if (y_sang == 17)
					{
						box(108, y_sang, 20, 2, 11, 0, tt_input[2]);
					}
					else if (y_sang == 21)
					{
						box(108, y_sang, 20, 2, 11, 0, tt_input[3]);
					}

					y_sang += 4;
					// bật thanh sáng mới
					if (y_sang == 13)
					{
						box(108, 13, 20, 2, 14, 0, tt_input[1]);
					}
					else if (y_sang == 17)
					{
						box(108, 17, 20, 2, 14, 0, tt_input[2]);
					}
					else if (y_sang == 21)
					{
						box(108, 21, 20, 2, 14, 0, tt_input[3]);
					}
					else if (y_sang == 25)
					{
						SetConsoleTextAttribute(hConsoleColor, 233);
						gotoXY(95, 25);
						cout << "          ";
						gotoXY(95, 26);
						cout << " TRUY CAP ";
						gotoXY(95, 27);
						cout << "          ";
					}
				}
			}
		}
	}

	// lấy ra lớp tín chỉ để xuất
	int vt_lop = kt_lop_tc_ton_tai_theo_nk_nhom_hk_mamh(ds_lop_tc, atoi(tt_input[0].c_str()), atoi(tt_input[1].c_str()), atoi(tt_input[2].c_str()), atoi(tt_input[3].c_str()));

	SetConsoleTextAttribute(hConsoleColor, 0);
	xoa_giao_dien_mo_lop_tin_chi();

	Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, atoi(tt_input[3].c_str()));
	string ten_mh = p->data.ten_mh;
	in_ds_diem_cua_1_lop_tc_trong_che_do_xem(ds_lop_tc.Lop_Tin_Chi[vt_lop]->DS_SV_DANG_KY_TIN_CHI, ds_sv, sl_sv, atoi(tt_input[0].c_str()), atoi(tt_input[1].c_str()), atoi(tt_input[2].c_str()), ten_mh);

	SetConsoleTextAttribute(hConsoleColor, 0);
	xoa_giao_dien_mo_lop_tin_chi();
	cong_tac_dau_nhay = 0;

}

void in_ds_diem_cua_1_lop_tc_trong_che_do_xem(DSSV_DANG_KY_TIN_CHI &ds_sv_dk, Sinh_Vien ds_sv[], int sl_sv, int nk, int hk, int nhom, string ten_mh)
{
	// sắp xếp điểm của sinh viên
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds_sv_dk.pHead; k != NULL; k = k->pNext)
	{
		for (NODE_SV_DANG_KY_TIN_CHI *h = k->pNext; h != NULL; h = h->pNext)
		{
			if (k->data.diem < h->data.diem)
			{
				SINH_VIEN_DANG_KY_TIN_CHI tam = k->data;
				k->data = h->data;
				h->data = tam;
			}
		}
	}

	// in danh sách sinh viên

	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);


	SetConsoleTextAttribute(hConsoleColor, 10);
	gotoXY(72, 5);
	cout << ",-----.    ,---.  ,--.  ,--. ,----.       ,------.  ,--.,------.,--.   ,--.";
	gotoXY(72, 6);
	cout << "|  |) /_  /  O  " << char(92) << " |  ,'.|  |'  .-./       |  .-.  " << char(92) << " |  ||  .---'|   `.'   |";
	gotoXY(72, 7);
	cout << "|  .-.  " << char(92) << "|  .-.  ||  |' '  ||  | .---.    |  |  " << char(92) << "  :|  ||  `--, |  |'.'|  |";
	gotoXY(72, 8);
	cout << "|  '--' /|  | |  ||  | `   |'  '--'  |    |  '--'  /|  ||  `---.|  |   |  |";
	gotoXY(72, 9);
	cout << "`------' `--' `--'`--'  `--' `------'     `-------' `--'`------'`--'   `--' ";
	int  sl_sv_con_dk = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_sv_dk);
	box(75, 12, 68, 2 + sl_sv_con_dk * 2, 14, 0, "");
	gotoXY(91, 10);
	cout << "TEN MON HOC : " << ten_mh;
	gotoXY(91, 11);
	cout << "Nien Khoa: " << nk << " - Hoc Ky: " << hk << " - Nhom: " << nhom << endl << endl;

	box(75, 12, 68, 2, 14, 0, "");
	gotoXY(82, 13);
	SetConsoleTextAttribute(hConsoleColor, 11);
	cout << setw(3) << "STT" << "\t" << setw(9) << "MASV" << setw(25) << "HO VA TEN" << "\t" << setw(2) << "   DIEM";

	int stt = 1;
	int can_dong = 0;
	// in ra danh sách sinh viên
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds_sv_dk.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.trang_thai_dang_ky == 1)
		{
			for (int i = 0; i < sl_sv; i++)
			{
				if (_stricmp(k->data.ma_sv.c_str(), ds_sv[i].ma_sv.c_str()) == 0)
				{
					SetConsoleTextAttribute(hConsoleColor, 15);
					gotoXY(82, 15 + can_dong);
					string hoten = ds_sv[i].ho + " " + ds_sv[i].ten;
					cout << setw(2) << stt << "\t  " << setw(9) << k->data.ma_sv << setw(25) << hoten << "\t";
					//vẽ đường kẻ
					for (int ke = 0; ke < 66; ke++)
					{
						gotoXY(77 + ke, 16 + can_dong);
						cout << char(196);
					}
					can_dong += 2;
					stt++;
				}
			}
		}
	}

	// fix tuong
	SetConsoleTextAttribute(hConsoleColor, 14);
	gotoXY(75, 14);
	cout << char(179);
	gotoXY(143, 14);
	cout << char(179);


	string ds_diem[70];
	int sl_diem = 0;
	// truyền điểm vào ds_diem
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds_sv_dk.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.trang_thai_dang_ky == 1 && k->data.diem != NULL)
		{
			ds_diem[sl_diem] = float_to_string(k->data.diem);
			sl_diem++;
		}
		else
		{
			sl_diem++;
		}
	}

	// fix lại từng ô điểm đã nhập và chưa nhập

	sl_diem = 0;
	for (int mk = 0; mk < sl_sv_con_dk; mk++)
	{
		if (ds_diem[mk].empty())
		{
			gotoXY(128, 15 + mk * 2);
			cout << "Chua nhap diem";
		}
		else
		{
			gotoXY(132, 15 + mk * 2);
			cout << ds_diem[mk];
		}
	}

	while (77)
	{
		char c = _getch();
		if (c == 27)
		{
			break;
		}
	}
}

int main()
{
	srand(time(NULL));
	ancontro();

	giao_dien();



	_getch();
}