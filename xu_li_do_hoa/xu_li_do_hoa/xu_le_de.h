#include"ctdl.h"



// ========================= DANH SÁCH LỚP TÍN CHỈ =========================
int tao_ma_tc(DS_LOP_TIN_CHI ds_lop_tc);
void in_trang_thai_lop(int trang_thai);
void Nhap_Lop_Tin_Chi(LOP_TIN_CHI *lop_tc, DS_LOP_TIN_CHI ds_lop_tc, DANH_SACH_MON_HOC ds_mh);
int kt_lop_tc(int ma_lop_tc, DS_LOP_TIN_CHI ds);
void xoa_lop_tc(DS_LOP_TIN_CHI &ds, int vt);
void Hieu_Chinh_Lop_Tin_Chi(LOP_TIN_CHI *&lop_tc);


// ========================= DANH SÁCH MÔN HỌC =========================
void them_mon_hoc(TREE &t, Node_Mon_Hoc *p);
void tim_node_trai_nhat_cua_cay_con_phai(TREE &t, Node_Mon_Hoc *p);
void Xoa_1_moc_hoc(TREE &t, int ma_mh, int &check);
int tao_ma_mon_hoc(DANH_SACH_MON_HOC ds);
Node_Mon_Hoc* kt_trung_ma_mh(TREE t, int ma_mh);
void Nhap_1_mon_hoc(DANH_SACH_MON_HOC &ds_mh);
void xuat_ds_mon_hoc(TREE t);
void cap_nhat_1_mh(Node_Mon_Hoc *&p);

// ========================= DANH SÁCH SINH VIÊN =========================
void tao_ma_sv(string &ma_sv, Sinh_Vien ds[], int sl);
void Nhap_tt_1_sv(Sinh_Vien &x, string ma_lop_nhap, Sinh_Vien ds[], int sl);
void viet_hoa_ma_lop(string &ma_lop);
void xuat_ds_sv(Sinh_Vien ds[], int sl, string ma_lop, int &check);
void chuan_hoa_chu(string &a); // chuẩn hoá chữ
int kt_ma_sv_ton_tai(Sinh_Vien ds[], int sl, string ma_sv);
void xoa_sinh_vien(Sinh_Vien ds[], int &sl);
string cat_ten(string ten);
void sap_xep_sv_theo_ten(Sinh_Vien ds[], int sl);
void swap(Sinh_Vien &x, Sinh_Vien &y);
void hieu_chinh_sinh_vien(Sinh_Vien ds[], int sl);

// ========================= THAO TÁC VỚI ĐĂNG KÝ TÍN CHỈ =================================
void in_ds_lop_tc_theo_hoc_ky_nien_khoa(DS_LOP_TIN_CHI ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh);
int kt_ma_lop_tc_theo_hoc_ky_nien_khoa(DS_LOP_TIN_CHI ds, int nien_khoa, int hoc_ky, int ma_lop_tc, string ma_sv);
void ThemNode_sv_dk_tin_chi(DSSV_DANG_KY_TIN_CHI &ds, NODE_SV_DANG_KY_TIN_CHI *p);
void in_ds_sinh_vien_lop_tc_theo_hoc_ky_nien_khoa_nhom_ma_mh(DS_LOP_TIN_CHI ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh, int ma_mh, int nhom, Sinh_Vien ds_sv[], int sl_sv);
void xuat_ds_lop_tin_chi_1_sv_dk(DS_LOP_TIN_CHI ds, string ma_sv, DANH_SACH_MON_HOC ds_mh);
int kt_sv_co_ton_tai_trong_lop_tc_theo_ma_sv_nhom_ma_mh(DS_LOP_TIN_CHI ds, string ma_sv, int nhom, int ma_mh);
void xoa_node_sv_trong_lop_tc(DS_LOP_TIN_CHI &ds, string ma_sv, int vt);
int so_luong_sinh_vien_con_dang_ky_1_lop_tc(DSSV_DANG_KY_TIN_CHI ds);
void in_ds_lop_tc_truoc_khi_huy_cac_lop_tc(DS_LOP_TIN_CHI ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh);
void in_ds_lop_bi_huy(DS_LOP_TIN_CHI &ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh);
void in_ds_lop_tc_sau_khi_loc(DS_LOP_TIN_CHI ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh);

// ======================== LOAD,READ FILE =====================================
void load_file_ds_sv(Sinh_Vien ds[], int &sl, set<string> &ds_ma_lop);
void load_file_mon_hoc(DANH_SACH_MON_HOC &ds);
void ghi_file_ds_lop_tin_chi(DS_LOP_TIN_CHI ds);
void load_file_ds_lop_tin_chi(DS_LOP_TIN_CHI &ds_lop_tin_chi);
void ghi_file_ds_sv_dang_ky_lop_tc(DS_LOP_TIN_CHI ds);
void load_file_ds_sv_dk_tin_chi(DS_LOP_TIN_CHI &ds);
void ghi_file_diem_cho_sv(DS_LOP_TIN_CHI ds);
void load_file_diem_thi(DS_LOP_TIN_CHI &ds);

// ======================= THAO TÁC VỚI ĐIỂM ============================================
void in_ds_sinh_vien_trong_1_lop_tc(DS_LOP_TIN_CHI  &ds, int nk, int hk, int nhom, int ma_mh, Sinh_Vien ds_sv[], int sl_sv, DANH_SACH_MON_HOC ds_mh, int &vt_lop);
NODE_SV_DANG_KY_TIN_CHI *kt_sv_co_ton_tai_trong_lop_tin_chi(DSSV_DANG_KY_TIN_CHI ds, string ma_sv);
void in_bang_diem_1_lop_theo_ma_lop(Sinh_Vien ds_sv[], int sl_sv, string ma_lop, DS_LOP_TIN_CHI ds_lop_tc, DANH_SACH_MON_HOC ds_mh);

// ======================= XỬ LÍ NGOÀI LỀ =================================
int sl_lop_sv_con_dk_va_huy_dk(DS_LOP_TIN_CHI ds, string ma_sv);
void ghi_file_lich_su_dang_ky_tin_chi(DS_LOP_TIN_CHI ds_lop_tc, Sinh_Vien ds_sv[], int sl_sv);
void xem_ls_dk_hoc_phan_cua_1_sinh_vien(DS_LOP_TIN_CHI ds, string ma_sv, DANH_SACH_MON_HOC ds_mh);

// =========================================================================



// ================= a. Mở lớp tín chỉ =================
int tao_ma_tc(DS_LOP_TIN_CHI ds_lop_tc)
{
	if (ds_lop_tc.sl == 0)
	{
		return 1;
	}
	return ds_lop_tc.Lop_Tin_Chi[ds_lop_tc.sl - 1]->maLopTinCHi + 1;
}
void in_trang_thai_lop(int trang_thai)
{
	if (trang_thai == 1)
	{
		cout << "Lop duoc mo";
	}
	else if (trang_thai == 0)
	{
		cout << "Lop bi huy";
	}
}
void Nhap_Lop_Tin_Chi(LOP_TIN_CHI *lop_tc, DS_LOP_TIN_CHI ds_lop_tc, DANH_SACH_MON_HOC ds_mh)
{
	lop_tc->maLopTinCHi = tao_ma_tc(ds_lop_tc);
	cout << "Ma lop tin chi: " << lop_tc->maLopTinCHi << endl;
	do
	{
		cout << "Nhap ma moc hoc: ";
		cin >> lop_tc->ma_mh;
	} while (kt_trung_ma_mh(ds_mh.t, lop_tc->ma_mh) == NULL);
	cout << "Nhap nien khoa: ";
	cin >> lop_tc->nien_khoa;
	cout << "Nhap hoc ky: ";
	cin >> lop_tc->hoc_ky;
	cout << "Nhap nhom: ";
	cin >> lop_tc->nhom;
	cout << "Nhap so sinh vien min: ";
	cin >> lop_tc->so_sv_min;
	cout << "Nhap so sinh vien max: ";
	cin >> lop_tc->so_sv_max;
	lop_tc->trang_thai_lop = 1;
	cout << "Trang thai lop: "; in_trang_thai_lop(lop_tc->trang_thai_lop);
}
void Hieu_Chinh_Lop_Tin_Chi(LOP_TIN_CHI *&lop_tc)
{
	cout << "Ma lop tin chi: " << lop_tc->maLopTinCHi << endl;
	cout << "Nhap ma moc hoc: ";
	cin >> lop_tc->ma_mh;
	cout << "Nhap nien khoa: ";
	cin >> lop_tc->nien_khoa;
	cout << "Nhap hoc ky: ";
	cin >> lop_tc->hoc_ky;
	cout << "Nhap nhom: ";
	cin >> lop_tc->nhom;
	cout << "Nhap so sinh vien min: ";
	cin >> lop_tc->so_sv_min;
	cout << "Nhap so sinh vien max: ";
	cin >> lop_tc->so_sv_max;
	lop_tc->trang_thai_lop = 1;
	cout << "Trang thai lop: "; in_trang_thai_lop(lop_tc->trang_thai_lop);
}

void Xem_Lop_Tin_Chi(DS_LOP_TIN_CHI ds)
{
	cout << "     " << setw(5) << "Ma lop tin chi " << "     " << setw(5) << "Ma mon hoc" << setw(7) << "     " << "Nien Khoa" << setw(5) << "     " << "Hoc Ky" << setw(3) << "     " << "Nhom" << setw(2) << "     " << "So Sinh vien min" << setw(3) << "     " << "So sinh vien max" << "     " << setw(14) << "Trang thai lop" << endl;
	for (int i = 0; i < ds.sl; i++)
	{
		cout << setw(10) << ds.Lop_Tin_Chi[i]->maLopTinCHi;
		cout << setw(22) << ds.Lop_Tin_Chi[i]->ma_mh;
		cout << setw(18) << ds.Lop_Tin_Chi[i]->nien_khoa;
		cout << setw(10) << ds.Lop_Tin_Chi[i]->hoc_ky;
		cout << setw(10) << ds.Lop_Tin_Chi[i]->nhom;
		cout << setw(16) << ds.Lop_Tin_Chi[i]->so_sv_min;
		cout << setw(20) << ds.Lop_Tin_Chi[i]->so_sv_max;
		cout << setw(24); in_trang_thai_lop(ds.Lop_Tin_Chi[i]->trang_thai_lop);  cout << endl;
	}
}

int kt_lop_tc(int ma_lop_tc, DS_LOP_TIN_CHI ds)
{
	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->maLopTinCHi == ma_lop_tc)
		{
			return i;
		}
	}
	return -1;
}

void xoa_lop_tc(DS_LOP_TIN_CHI &ds, int vt)
{
	if (ds.sl == 1)
	{
		LOP_TIN_CHI *tam = ds.Lop_Tin_Chi[0];
		delete tam;
		ds.sl = 0;
		return;
	}
	for (int i = vt; i < ds.sl - 1; i++)
	{
		ds.Lop_Tin_Chi[i] = ds.Lop_Tin_Chi[i + 1];
	}
	ds.sl--;
}

int so_luong_sinh_vien_con_dang_ky_1_lop_tc(DSSV_DANG_KY_TIN_CHI ds)
{
	int sl = 0;
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.trang_thai_dang_ky == 1)
		{
			sl++;
		}
	}
	return sl;
}

void in_ds_lop_tc_theo_hoc_ky_nien_khoa(DS_LOP_TIN_CHI ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh)
{
	cout << "\n\t\t\t\t\t\tNien Khoa: " << nien_khoa << " - Hoc Ky: " << hoc_ky << endl;
	cout << "\t\t\t\t\t==================== * ====================" << endl;
	cout << "     " << setw(5) << "Ma lop tin chi " << "     " << setw(5) << "Ma mon hoc" << setw(30) << "Ten mon hoc" << setw(7) << "     " << "Nhom" << setw(2) << "     " << "So Sinh vien da dang ky" << setw(3) << "     " << "So slot con trong" << "     " << endl;
	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->nien_khoa == nien_khoa && ds.Lop_Tin_Chi[i]->hoc_ky == hoc_ky && ds.Lop_Tin_Chi[i]->trang_thai_lop == 1)
		{
			cout << setw(10) << ds.Lop_Tin_Chi[i]->maLopTinCHi;
			cout << setw(22) << ds.Lop_Tin_Chi[i]->ma_mh;
			Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds.Lop_Tin_Chi[i]->ma_mh);
			cout << setw(33) << p->data.ten_mh;
			cout << setw(10) << ds.Lop_Tin_Chi[i]->nhom;
			int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI);
			cout << setw(16) << sl_sv_con_dang_ky;
			cout << setw(25) << ds.Lop_Tin_Chi[i]->so_sv_max - sl_sv_con_dang_ky << endl;
		}
	}
}

void in_ds_sinh_vien_lop_tc_theo_hoc_ky_nien_khoa_nhom_ma_mh(DS_LOP_TIN_CHI ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh, int ma_mh, int nhom, Sinh_Vien ds_sv[], int sl_sv)
{
	cout << "\n\t\tMa mon hoc: " << ma_mh << " - Nhom: " << nhom << endl;
	cout << "\t" << setw(9) << "Ma SV" << setw(30) << "Ho va ten" << endl;
	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->nien_khoa == nien_khoa && ds.Lop_Tin_Chi[i]->hoc_ky == hoc_ky && ds.Lop_Tin_Chi[i]->nhom == nhom && ds.Lop_Tin_Chi[i]->ma_mh == ma_mh)
		{
			for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.trang_thai_dang_ky == 1)
				{
					// dựa vào mã sinh viên để tìm
					for (int j = 0; j < sl_sv; j++)
					{
						if (_stricmp(k->data.ma_sv.c_str(), ds_sv[j].ma_sv.c_str()) == 0)
						{
							string ten = ds_sv[j].ho + " " + ds_sv[j].ten;
							cout << "\t" << setw(9) << ds_sv[j].ma_sv << setw(30) << ten << endl;
							break;
						}
					}
				}
			}
		}
	}
}

// kiểm tra sinh viên có tồn tại trong lớp này chưa
int kt_ma_lop_tc_theo_hoc_ky_nien_khoa(DS_LOP_TIN_CHI ds, int nien_khoa, int hoc_ky, int ma_lop_tc, string ma_sv)
{

	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->nien_khoa == nien_khoa && ds.Lop_Tin_Chi[i]->hoc_ky == hoc_ky && ds.Lop_Tin_Chi[i]->maLopTinCHi == ma_lop_tc && ds.Lop_Tin_Chi[i]->trang_thai_lop == 1)
		{

			for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
			{
				if (_stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0 && k->data.trang_thai_dang_ky == 1)
				{
					return -2;
				}
			}
			return i;
		}
	}
	return -1;
}

NODE_SV_DANG_KY_TIN_CHI *khoiTaoNode_sv_dk_tin_chi(SINH_VIEN_DANG_KY_TIN_CHI x)
{
	NODE_SV_DANG_KY_TIN_CHI *p = new NODE_SV_DANG_KY_TIN_CHI;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void ThemNode_sv_dk_tin_chi(DSSV_DANG_KY_TIN_CHI &ds, NODE_SV_DANG_KY_TIN_CHI *p)
{
	// danh sách rỗng
	if (ds.pHead == NULL)
	{
		ds.pHead = ds.pTail = p;
	}
	else
	{
		ds.pTail->pNext = p;
		ds.pTail = p;
	}
}

void xuat_ds_lop_tin_chi_1_sv_dk(DS_LOP_TIN_CHI ds, string ma_sv, DANH_SACH_MON_HOC ds_mh)
{
	cout << "     " << setw(5) << "Ma lop tin chi " << "     " << setw(5) << "Ma mon hoc" << setw(30) << "Ten mon hoc" << setw(7) << "     " << "Nhom" << setw(2) << "     " << "So Sinh vien da dang ky" << setw(3) << "     " << "So slot con trong" << "     " << endl;
	for (int i = 0; i < ds.sl; i++)
	{
		for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
		{
			if (_stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0 && k->data.trang_thai_dang_ky == 1)
			{
				cout << setw(10) << ds.Lop_Tin_Chi[i]->maLopTinCHi;
				cout << setw(22) << ds.Lop_Tin_Chi[i]->ma_mh;
				Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds.Lop_Tin_Chi[i]->ma_mh);
				cout << setw(33) << p->data.ten_mh;
				cout << setw(10) << ds.Lop_Tin_Chi[i]->nhom;
				int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI);
				cout << setw(16) << sl_sv_con_dang_ky;
				cout << setw(25) << ds.Lop_Tin_Chi[i]->so_sv_max - sl_sv_con_dang_ky << endl;
			}
		}
	}
}

int kt_sv_co_ton_tai_trong_lop_tc_theo_ma_sv_nhom_ma_mh(DS_LOP_TIN_CHI ds, string ma_sv, int nhom, int ma_mh)
{
	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->nhom == nhom && ds.Lop_Tin_Chi[i]->ma_mh == ma_mh)
		{
			for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
			{
				if (_stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0 && k->data.trang_thai_dang_ky == 1)
				{
					return i;
				}
			}
			return -1;
		}
	}
	return -1;
}

void xoa_node_sv_trong_lop_tc(DS_LOP_TIN_CHI &ds, string ma_sv, int vt)
{
	// neu danh sach chi co 1 phan tu ma phan tu do la phan tu vt
	if (ds.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.pHead->pNext == NULL && _stricmp(ds.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.pHead->data.ma_sv.c_str(), ma_sv.c_str()) == 0)
	{
		if (ds.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.pHead == NULL)
		{
			return;
		}
		NODE_SV_DANG_KY_TIN_CHI *p = new NODE_SV_DANG_KY_TIN_CHI;
		p = ds.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.pHead;
		ds.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.pHead = ds.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.pHead->pNext;
		delete p;

	}
	// truong hop cac phan tu o giua tru dau va cuoi
	NODE_SV_DANG_KY_TIN_CHI *h = NULL;
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
	{
		if (_stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0)
		{
			h->pNext = k->pNext;
			delete k;
			k = h;
			return;
		}
		// xoá cuối
		if (k->pNext == NULL && _stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0)
		{
			ds.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.pTail = h;
			h->pNext = NULL;
			delete k;
			return;
		}
		h = k;
	}
}

void in_ds_lop_tc_truoc_khi_huy_cac_lop_tc(DS_LOP_TIN_CHI ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh)
{
	cout << "\n\t\t\t\t\t\tNien Khoa: " << nien_khoa << " - Hoc Ky: " << hoc_ky << endl;
	cout << "\t\t\t\t\t==================== * ====================" << endl;
	cout << "     " << setw(5) << "Ma lop tin chi " << "     " << setw(5) << "Ma mon hoc" << setw(30) << "Ten mon hoc" << setw(7) << "     " << "Nhom" << setw(2) << "     " << "So Sinh vien da dang ky" << setw(3) << "     " << "So slot con trong" << "     " << setw(3) << "Gioi han sinh vien min" << endl;
	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->nien_khoa == nien_khoa && ds.Lop_Tin_Chi[i]->hoc_ky == hoc_ky && ds.Lop_Tin_Chi[i]->trang_thai_lop == 1)
		{
			cout << setw(10) << ds.Lop_Tin_Chi[i]->maLopTinCHi;
			cout << setw(22) << ds.Lop_Tin_Chi[i]->ma_mh;
			Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds.Lop_Tin_Chi[i]->ma_mh);
			cout << setw(33) << p->data.ten_mh;
			cout << setw(10) << ds.Lop_Tin_Chi[i]->nhom;
			int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI);
			cout << setw(16) << sl_sv_con_dang_ky;
			cout << setw(25) << ds.Lop_Tin_Chi[i]->so_sv_max - sl_sv_con_dang_ky;
			cout << setw(25) << ds.Lop_Tin_Chi[i]->so_sv_min << endl;
		}
	}
}
// danh sách lớp bị huỷ vì không đủ số lượng sinh viên
void in_ds_lop_bi_huy(DS_LOP_TIN_CHI &ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh)
{
	cout << "\n\t\t\t\t\t\tDANH SACH CAC LOP BI HUY" << endl;
	cout << "\n\t\t\t\t\t\tNien Khoa: " << nien_khoa << " - Hoc Ky: " << hoc_ky << endl;
	cout << "\t\t\t\t\t==================== * ====================" << endl;
	cout << "\t" << setw(11) << "Trang Thai Lop" << "     " << setw(5) << "Ma lop tin chi " << "     " << setw(5) << "Ma mon hoc" << setw(30) << "Ten mon hoc" << setw(7) << "     " << "Nhom" << endl;
	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->nien_khoa == nien_khoa && ds.Lop_Tin_Chi[i]->hoc_ky == hoc_ky)
		{
			int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI);
			if (sl_sv_con_dang_ky < ds.Lop_Tin_Chi[i]->so_sv_min)
			{
				cout << "\t" << setw(13) << "Huy Dang Ky";
				ds.Lop_Tin_Chi[i]->trang_thai_lop = 0;
				cout << setw(10) << ds.Lop_Tin_Chi[i]->maLopTinCHi;
				cout << setw(22) << ds.Lop_Tin_Chi[i]->ma_mh;
				Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds.Lop_Tin_Chi[i]->ma_mh);
				cout << setw(34) << p->data.ten_mh;
				cout << setw(9) << ds.Lop_Tin_Chi[i]->nhom << endl;;
			}
		}
	}
}

void in_ds_lop_tc_sau_khi_loc(DS_LOP_TIN_CHI ds, int nien_khoa, int hoc_ky, DANH_SACH_MON_HOC ds_mh)
{
	cout << "\n\t\t\t\t\t   DANH SACH LOP TIN CHI HOAN THIEN\n";

	cout << "\n\t\t\t\t\t\tNien Khoa: " << nien_khoa << " - Hoc Ky: " << hoc_ky << endl;
	cout << "\t\t\t\t\t==================== * ====================" << endl;
	cout << "     " << setw(5) << "Ma lop tin chi " << "     " << setw(5) << "Ma mon hoc" << setw(30) << "Ten mon hoc" << setw(7) << "     " << "Nhom" << setw(2) << "     " << "So Sinh vien da dang ky" << endl;
	cout << "     ---------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->nien_khoa == nien_khoa && ds.Lop_Tin_Chi[i]->hoc_ky == hoc_ky && ds.Lop_Tin_Chi[i]->trang_thai_lop == 1)
		{
			cout << setw(10) << ds.Lop_Tin_Chi[i]->maLopTinCHi;
			cout << setw(22) << ds.Lop_Tin_Chi[i]->ma_mh;
			Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds.Lop_Tin_Chi[i]->ma_mh);
			cout << setw(33) << p->data.ten_mh;
			cout << setw(10) << ds.Lop_Tin_Chi[i]->nhom;
			int sl_sv_con_dang_ky = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI);
			cout << setw(16) << sl_sv_con_dang_ky << endl;
			cout << "     ___________________________________________________________________________________________________\n";
		}
	}
}

// =================================== BRAIN =================================
//void menu()
//{
//	
//
//	// load file
//	load_file_ds_sv(ds_sv.ds, ds_sv.sl, ds_ma_lop);
//	load_file_mon_hoc(ds_mon_hoc);
//	load_file_ds_lop_tin_chi(ds_lop_tin_chi);
//	load_file_ds_sv_dk_tin_chi(ds_lop_tin_chi);
//
//	while (66)
//	{
//		// ghi file lịch sử đăng kí học phần của sinh viên
//		ghi_file_lich_su_dang_ky_tin_chi(ds_lop_tin_chi, ds_sv.ds, ds_sv.sl);
//
//		system("cls");
//		cout << "\n\n\t\tQUAN LI SINH VIEN\n";
//		cout << "\n\t1. Nhap lop Tin CHi";
//		cout << "\n\t2. Nhap mon hoc";
//		cout << "\n\t3. Nhap sinh vien";
//		cout << "\n\t4. Dang Ki tin chi"; // menu động phân quyền sinh viên
//		cout << "\n\t5. In danh sach sinh vien con dang ky tin chi"; // meu động phân quyền giáo viên
//		cout << "\n\t6. Huy dang ky hoc phan"; // meu động gọp chung với đăng kí tín chỉ
//		cout << "\n\t7. Lich su dang ki hoc phan cua sinh vien";
//		cout << "\n\t8. Huy lop tin chi"; // menu động phân quyền giáo viên sau khi đã thực hiện huỷ lớp tín chỉ thì không thể đăng kí tín chỉ hay huỷ đăng kí học phần
//										  // hay in danh sách sinh viên còn đăng kí tín chỉ
//		cout << "\n\t9. In danh sach cac lop tin chi sau khi loc cac lop tin chi khong du dieu kien";
//		cout << "\n\t10. Nhap diem mot lop hoc tin chi"; // quá trình nhập điểm chỉ diễn ra khi quá trình lọc tín chỉ được hoàn tất
//		cout << "\n\t11. In bang diem cua 1 lop tin chi";
//		cout << "\n\t12. In bang diem tong ket 1 lop";
//		cout << "\n\t0. Thoat";
//		int lc;
//		cout << "\n\tNhap lua chon: ";
//		cin >> lc;
//		if (lc == 0)
//		{
//			break;
//		}
//		// Mở lớp tín chỉ
//		else if (lc == 1)
//		{
//			while (77)
//			{
//				system("cls");
//				cout << "\n\t1. Them lop tin chi";
//				cout << "\n\t2. Xem lop tin chi";
//				cout << "\n\t3. Xoa lop tin chi";
//				cout << "\n\t4. Hieu chinh lop tin chi";
//				cout << "\n\t0. Thoat";
//				cout << "\n\tNhap lua chon: ";
//				int select;
//				cin >> select;
//				if (select == 0)
//				{
//					ghi_file_ds_lop_tin_chi(ds_lop_tin_chi);
//					break;
//				}
//				// thêm lớp tín chỉ
//				else if (select == 1)
//				{
//					// qua menu động cho xem danh sách lớp môn học
//					// Mã môn hoc - tên môn học
//					int sl;
//					cout << "Nhap so luong lop can them: ";
//					cin >> sl;
//					for (int i = 0; i < sl; i++)
//					{
//						cout << "\n\tNhap lop tin chi \n";
//						ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl] = new LOP_TIN_CHI;
//						Nhap_Lop_Tin_Chi(ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl], ds_lop_tin_chi, ds_mon_hoc);
//						ds_lop_tin_chi.sl++;
//						system("pause");
//					}
//				}
//				// xem lớp tín chỉ
//				else if (select == 2)
//				{
//					Xem_Lop_Tin_Chi(ds_lop_tin_chi);
//					system("pause");
//				}
//				// xoá lớp tín chỉ
//				else if (select == 3)
//				{
//
//					int ma;
//					cout << "Nhap ma lop tin chi can xoa: ";
//					cin >> ma;
//					int check = kt_lop_tc(ma, ds_lop_tin_chi);
//					if (check != -1)
//					{
//						xoa_lop_tc(ds_lop_tin_chi, check);
//						cout << "\n\tDa xoa thanh cong";
//					}
//					else
//					{
//						cout << "\n\tKhong tim thay ma lop tin chi " << ma;
//					}
//					system("pause");
//				}
//				// hiệu chỉnh lớp tín chỉ
//				else if (select == 4)
//				{
//					Xem_Lop_Tin_Chi(ds_lop_tin_chi);
//					cout << endl;
//					int ma;
//					cout << "Nhap ma lop tin chi can hieu chinh: ";
//					cin >> ma;
//					int check = kt_lop_tc(ma, ds_lop_tin_chi);
//					if (check != -1)
//					{
//						Hieu_Chinh_Lop_Tin_Chi(ds_lop_tin_chi.Lop_Tin_Chi[check]);
//					}
//					else
//					{
//						cout << "\n\tKhong tim thay ma lop tin chi " << ma;
//					}
//					system("pause");
//				}
//			}
//		}
//		else if (lc == 2)
//		{
//			while (77)
//			{
//				system("cls");
//				cout << "\n\t1. Them mon hoc";
//				cout << "\n\t2. Xem danh sach mon hoc";
//				cout << "\n\t3. Xoa mon hoc";
//				cout << "\n\t4. Hieu chinh mon hoc";
//				cout << "\n\t0. Thoat";
//				cout << "\n\tNhap lua chon: ";
//				int select;
//				cin >> select;
//				if (select == 0)
//				{
//					break;
//				}
//				else if (select == 1)
//				{
//					int sl;
//					cout << "Nhap so luong mon hoc can them vao: ";
//					cin >> sl;
//					for (int i = 0; i < sl; i++)
//					{
//						cout << "\n\tNhap mon hoc\n";
//						Nhap_1_mon_hoc(ds_mon_hoc);
//					}
//				}
//				else if (select == 2)
//				{
//					cout << "\n\t\t\tDANH SACH MON HOC\n";
//					cout << "\t\t\t=================\n";
//					cout << "\t" << setw(3) << "Ma mon hoc" << setw(30) << "Ten mon hoc" << setw(10) << "STCLT" << setw(10) << "STCTH" << endl;
//					xuat_ds_mon_hoc(ds_mon_hoc.t);
//					system("pause");
//				}
//				else if (select == 3)
//				{
//					int ma_mh_xoa;
//					int check = 0; // kiểm tra xem mã môn học có tồn tại
//					cout << "Nhap ma mon hoc: ";
//					cin >> ma_mh_xoa;
//					Xoa_1_moc_hoc(ds_mon_hoc.t, ma_mh_xoa, check);
//					if (check == 0)
//					{
//						cout << "Khong tim thay ma mon hoc can xoa";
//					}
//					else
//					{
//						cout << "Da xoa mon hoc co ma " << ma_mh_xoa;
//					}
//					system("pause");
//				}
//				else if (select == 4)
//				{
//					int ma_mh_cn;
//					cout << "Nhap ma mon hoc can cap nhat: ";
//					cin >> ma_mh_cn;
//					Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mon_hoc.t, ma_mh_cn);
//					if (p == NULL)
//					{
//						cout << "Khong co ma moc hoc nao nao nhu tren";
//					}
//					else
//					{
//						cap_nhat_1_mh(p);
//					}
//				}
//			}
//		}
//		else if (lc == 3)
//		{
//			while (true)
//			{
//				system("cls");
//				cout << "\n\t1. Them sinh vien";
//				cout << "\n\t2. Xem danh sach sinh vien";
//				cout << "\n\t3. Xoa sinh vien";
//				cout << "\n\t4. Hieu chinh thong tin sinh vien";
//				cout << "\n\t0. Thoat";
//				cout << "\n\tNhap lua chon: ";
//				int select;
//				cin >> select;
//				if (select == 0)
//				{
//					break;
//				}
//				else if (select == 1)
//				{
//					cin.ignore();
//					string ma_lop_sv;
//					cout << "Nhap ma lop sinh vien: ";
//					getline(cin, ma_lop_sv);
//					viet_hoa_ma_lop(ma_lop_sv);
//					ds_ma_lop.insert(ma_lop_sv);
//					int sl;
//					cout << "Nhap so luong sinh vien can them: ";
//					cin >> sl;
//					cin.ignore();
//					for (int i = 0; i < sl; i++)
//					{
//						cout << "\n\tNhap sinh vien\n";
//						Sinh_Vien x;
//						Nhap_tt_1_sv(x, ma_lop_sv, ds_sv.ds, ds_sv.sl);
//						ds_sv.ds[ds_sv.sl++] = x;
//					}
//				}
//				else if (select == 2)
//				{
//					system("cls");
//					cout << "\n\t\tDANH SACH LOP\n";
//					cout << setw(20) << "Ma Lop" << setw(20) << "So luong" << endl;
//					for (auto it = ds_ma_lop.begin(); it != ds_ma_lop.end(); ++it)
//					{
//						string _ml = *it;
//						int dem = 0;
//						// tìm số lượng sinh viên từng lớp
//						for (int i = 0; i < ds_sv.sl; i++)
//						{
//							if (_stricmp(ds_sv.ds[i].Ma_Lop.c_str(), _ml.c_str()) == 0)
//							{
//								dem++;
//							}
//						}
//						cout << setw(20) << *it << setw(20) << dem << endl;
//					}
//					cin.ignore();
//					cout << "Nhap ma lop can in danh sach: ";
//					string ml;
//					getline(cin, ml);
//					int check = 0;
//					viet_hoa_ma_lop(ml);
//					cout << "\n\t DANH SACH SINH VIEN LOP " << ml;
//					cout << endl;
//					xuat_ds_sv(ds_sv.ds, ds_sv.sl, ml, check);
//					if (check == 0)
//					{
//						cout << "\n\tKhong ma lop ton tai";
//					}
//					system("pause");
//				}
//				else if (select == 3)
//				{
//					cin.ignore();
//					xoa_sinh_vien(ds_sv.ds, ds_sv.sl);
//					system("pause");
//				}
//				else if (select == 4)
//				{
//					cin.ignore();
//					hieu_chinh_sinh_vien(ds_sv.ds, ds_sv.sl);
//					system("pause");
//				}
//			}
//		}
//		else if (lc == 4)
//		{
//			system("cls");
//			cin.ignore();
//			string ma_sv_dk;
//			cout << "Nhap ma sinh vien: ";
//			getline(cin, ma_sv_dk);
//			if (kt_ma_sv_ton_tai(ds_sv.ds, ds_sv.sl, ma_sv_dk) == -1)
//			{
//				cout << "Khong ton tai ma sinh vien!";
//			}
//			else
//			{
//				system("cls");
//				// in ra các thông tin của sinh viên.
//				Sinh_Vien tam = ds_sv.ds[kt_ma_sv_ton_tai(ds_sv.ds, ds_sv.sl, ma_sv_dk)];
//				cout << "\t" << setw(9) << "Ma sinh vien" << setw(20) << "Ho va ten" << "\t" << setw(3) << "Phai" << setw(15) << "SDT" << "\t" << setw(15) << "Ma lop" << endl;
//				string hoten = tam.ho + " " + tam.ten;
//				cout << "\t" << setw(9) << tam.ma_sv << setw(23) << hoten << setw(11) << tam.phai << setw(23) << tam.SO_DT << "\t" << setw(7) << tam.Ma_Lop << endl;
//				// user nhập vào Niên khóa, Học kỳ
//				// Chương trình sẽ tự động lọc ra các lớp tín chỉ đã mở trong niên khóa, học kỳ đó để sinh viên đăng ký.
//				cout << "\nNhap nien khoa: ";
//				int nk;
//				cin >> nk;
//				cout << "Nhap hoc ky: ";
//				int hk;
//				cin >> hk;
//				while (true)
//				{
//					system("cls");
//					in_ds_lop_tc_theo_hoc_ky_nien_khoa(ds_lop_tin_chi, nk, hk, ds_mon_hoc);
//					cout << "\n\tNhap -1 de thoat khoi qua trinh dang ky";
//					cout << "\n\tNhap ma lop tin chi dang ky: ";
//					int ma_lop_tc_dk;
//					cin >> ma_lop_tc_dk;
//					if (ma_lop_tc_dk == -1)
//					{
//						ghi_file_ds_sv_dang_ky_lop_tc(ds_lop_tin_chi);
//						break;
//					}
//					if (kt_ma_lop_tc_theo_hoc_ky_nien_khoa(ds_lop_tin_chi, nk, hk, ma_lop_tc_dk, ma_sv_dk) == -1)
//					{
//						cout << "Khong ton tai lop nay! Vui long kiem tra du lieu da nhap";
//						system("pause");
//					}
//					else if (kt_ma_lop_tc_theo_hoc_ky_nien_khoa(ds_lop_tin_chi, nk, hk, ma_lop_tc_dk, ma_sv_dk) == -2)
//					{
//						cout << "Lop nay sinh vien da dang ky!";
//						system("pause");
//					}
//					else
//					{
//						int vt = kt_ma_lop_tc_theo_hoc_ky_nien_khoa(ds_lop_tin_chi, nk, hk, ma_lop_tc_dk, ma_sv_dk);
//						if (so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds_lop_tin_chi.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI) == ds_lop_tin_chi.Lop_Tin_Chi[vt]->so_sv_max)
//						{
//							cout << "Lop nay da du sinh vien!";
//						}
//						else
//						{
//							SINH_VIEN_DANG_KY_TIN_CHI x;
//							viet_hoa_ma_lop(ma_sv_dk);
//							x.ma_sv = ma_sv_dk;
//							x.trang_thai_dang_ky = 1;
//							x.diem = NULL;
//							NODE_SV_DANG_KY_TIN_CHI *p = khoiTaoNode_sv_dk_tin_chi(x);
//							ThemNode_sv_dk_tin_chi(ds_lop_tin_chi.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI, p);
//							ds_lop_tin_chi.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.sl++; // ghi bên file không chạm vào
//							cout << "Da them thanh cong!";
//						}
//						system("pause");
//					}
//				}
//			}
//			system("pause");
//		}
//		else if (lc == 5)
//		{
//			// cho xem danh sách lớp tín chỉ
//			cout << "\nNhap nien khoa: ";
//			int nk;
//			cin >> nk;
//			cout << "Nhap hoc ky: ";
//			int hk;
//			cin >> hk;
//			while (true)
//			{
//				system("cls");
//				in_ds_lop_tc_theo_hoc_ky_nien_khoa(ds_lop_tin_chi, nk, hk, ds_mon_hoc);
//				int select;
//				cout << "\n\t1. Xem danh sach sinh vien trong mot lop";
//				cout << "\n\t0. Thoat";
//				cout << "\n\tNhap lc: ";
//				cin >> select;
//				if (select == 1)
//				{
//					cout << "Nhap nhom: ";
//					int nhom;
//					cin >> nhom;
//					cout << "Nhap ma mon hoc: ";
//					int ma_mh;
//					cin >> ma_mh;
//					in_ds_sinh_vien_lop_tc_theo_hoc_ky_nien_khoa_nhom_ma_mh(ds_lop_tin_chi, nk, hk, ds_mon_hoc, ma_mh, nhom, ds_sv.ds, ds_sv.sl);
//					system("pause");
//				}
//				else if (select == 0)
//				{
//					break;
//				}
//			}
//		}
//		else if (lc == 6)
//		{
//			cin.ignore();
//			string ma_sv;
//			cout << "Nhap ma sinh vien: ";
//			getline(cin, ma_sv);
//			int kt = kt_ma_sv_ton_tai(ds_sv.ds, ds_sv.sl, ma_sv);
//			if (kt == -1)
//			{
//				cout << "\nKhong ton tai ma sinh vien!";
//			}
//			else
//			{
//				while (true)
//				{
//					system("cls");
//					// xuất ra các lớp học phần mà sinh viên đó đã đăng kí
//					xuat_ds_lop_tin_chi_1_sv_dk(ds_lop_tin_chi, ma_sv, ds_mon_hoc);
//
//					cout << "\n\t1. Huy lop tin chi";
//					cout << "\n\t0. Thoat";
//					int select;
//					cout << "\n\tNhap lua chon cua ban: ";
//					cin >> select;
//					if (select == 0)
//					{
//						ghi_file_ds_sv_dang_ky_lop_tc(ds_lop_tin_chi);
//						break;
//					}
//					else if (select == 1)
//					{
//						// nhập vào mã môn hoc, nhóm để xoá sinh viên khỏi lớp tín chỉ đó
//						int ma_mh;
//						cout << "\nNhap ma mon hoc: ";
//						cin >> ma_mh;
//						cout << "Nhap nhom: ";
//						int nhom;
//						cin >> nhom;
//						int vt = kt_sv_co_ton_tai_trong_lop_tc_theo_ma_sv_nhom_ma_mh(ds_lop_tin_chi, ma_sv, nhom, ma_mh);
//						if (vt == -1)
//						{
//							viet_hoa_ma_lop(ma_sv);
//							cout << "\nKhong ton tai sinh vien co ma " << ma_sv << " trong lop nay";
//							system("pause");
//						}
//						else
//						{
//							// thao tác xoá sinh viên khỏi lớp
//							cout << "\n\tBan co chac chan muon xoa";
//							cout << "\n\tEnter de tiep tuc";
//							cout << "\n\tEsc de huy thao tac";
//							char c;
//							c = _getch();
//							if (c == 13) // enter
//							{
//								for (NODE_SV_DANG_KY_TIN_CHI *k = ds_lop_tin_chi.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
//								{
//									// huỷ đăng kí lớp tín chỉ này
//									if (_stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0 && k->data.trang_thai_dang_ky == 1)
//									{
//										k->data.trang_thai_dang_ky = 0;
//									}
//								}
//								cout << "\n\tDa xoa thanh cong";
//							}
//							else if (c == 27) // không thay đổi
//							{
//								cout << "\n\tXoa sinh vien da bi huy thao tac";
//							}
//							system("pause");
//						}
//						system("pause");
//					}
//				}
//			}
//			system("pause");
//		}
//		else if (lc == 7)
//		{
//			cin.ignore();
//			string ma_sv_ls;
//			cout << "Nhap ma sinh vien: ";
//			getline(cin, ma_sv_ls);
//			int kt = kt_ma_sv_ton_tai(ds_sv.ds, ds_sv.sl, ma_sv_ls);
//			if (kt == -1)
//			{
//				cout << "\nKhong ton tai ma sinh vien!";
//			}
//			else
//			{
//				// cho xem lịch sử đăng kí học phần của sinh viên
//				xem_ls_dk_hoc_phan_cua_1_sinh_vien(ds_lop_tin_chi, ma_sv_ls, ds_mon_hoc);
//			}
//			system("pause");
//		}
//		else if (lc == 8)
//		{
//			// cho xem danh sách lớp tín chỉ ban đầu chưa xoá những lớp tin chỉ mà số sinh viên đăng kí nhỏ hơn số sinh viên min
//			cout << "\nNhap nien khoa: ";
//			int nk;
//			cin >> nk;
//			cout << "Nhap hoc ky: ";
//			int hk;
//			cin >> hk;
//			system("cls");
//			in_ds_lop_tc_truoc_khi_huy_cac_lop_tc(ds_lop_tin_chi, nk, hk, ds_mon_hoc);
//			cout << "\n\tNhan bat ki phim nao de tiep tuc!";
//			system("pause");
//			// thực hiện chuyển đổi các lớp tín chỉ
//			system("cls");
//			in_ds_lop_bi_huy(ds_lop_tin_chi, nk, hk, ds_mon_hoc);
//			load_file_diem_thi(ds_lop_tin_chi);
//			system("pause");
//		}
//		else if (lc == 9)
//		{
//			cout << "\nNhap nien khoa: ";
//			int nk;
//			cin >> nk;
//			cout << "Nhap hoc ky: ";
//			int hk;
//			cin >> hk;
//			system("cls");
//			in_ds_lop_tc_sau_khi_loc(ds_lop_tin_chi, nk, hk, ds_mon_hoc);
//			system("pause");
//		}
//		else if (lc == 10)
//		{
//			/*
//				in ra danh sách sinh viên trong một lớp tín chỉ do user truyền vào theo tham số với trạng thái lớp được mở (1)
//				+ Niên khóa
//				+ Học kỳ
//				+ Nhóm
//				+ Mã Môn học.
//			*/
//			system("cls");
//			cout << "Nhap nien khoa: ";
//			int nk;
//			cin >> nk;
//			cout << "Nhap hoc ki: ";
//			int hk;
//			cin >> hk;
//			cout << "Nhap nhom: ";
//			int nhom;
//			cin >> nhom;
//			cout << "Nhap ma mon hoc: ";
//			int ma_mh;
//			cin >> ma_mh;
//			/*
//				Chương trình sẽ tự động lọc ra danh sách sv đã đăng ký , và in ra màn hình danh sách theo dạng sau :
//				STT	MASV	HO	TEN	DIEM
//				99	XXXX	XXXXXXXXXXX	XXXXX
//				99	XXXX	XXXXXXXXXXX	XXXXX
//
//				Bốn cột đầu đã có sẵn dữ liệu, User chỉ việc nhập điểm hoặc hiệu chỉnh điểm trực tiếp vào khung trên cột điểm.
//			*/
//			while (66)
//			{
//				int vt_lop = -1;
//				system("cls");
//				in_ds_sinh_vien_trong_1_lop_tc(ds_lop_tin_chi, nk, hk, nhom, ma_mh, ds_sv.ds, ds_sv.sl, ds_mon_hoc, vt_lop);
//				cout << "\n\t1. Nhap diem";
//				cout << "\n\t0. Thoat";
//				cout << "\n\tNhap lua chon: ";
//				int select;
//				cin >> select;
//				if (select == 0)
//				{
//					ghi_file_diem_cho_sv(ds_lop_tin_chi);
//					break;
//				}
//				else if (select == 1)
//				{
//					cin.ignore();
//					string ma_sv;
//					cout << "Nhap ma sinh vien: ";
//					getline(cin, ma_sv);
//					NODE_SV_DANG_KY_TIN_CHI *tam = kt_sv_co_ton_tai_trong_lop_tin_chi(ds_lop_tin_chi.Lop_Tin_Chi[vt_lop]->DS_SV_DANG_KY_TIN_CHI, ma_sv);
//					if (tam == NULL)
//					{
//						cout << "\n\tKhong ton tai sinh vien trong lop";
//						system("pause");
//					}
//					else
//					{
//						do
//						{
//							cout << "\n\tNhap diem cho sinh vien: ";
//							cin >> tam->data.diem;
//							if (tam->data.diem > 10 || tam->data.diem <= 0)
//							{
//								cout << "\nDiem khong hop le!";
//							}
//						} while (tam->data.diem > 10 || tam->data.diem <= 0);
//					}
//				}
//			}
//
//		}
//		else if (lc == 11)
//		{
//			system("cls");
//			cout << "Nhap nien khoa: ";
//			int nk;
//			cin >> nk;
//			cout << "Nhap hoc ki: ";
//			int hk;
//			cin >> hk;
//			cout << "Nhap nhom: ";
//			int nhom;
//			cin >> nhom;
//			cout << "Nhap ma mon hoc: ";
//			int ma_mh;
//			cin >> ma_mh;
//			system("cls");
//			int vt_lop = 1;
//			in_ds_sinh_vien_trong_1_lop_tc(ds_lop_tin_chi, nk, hk, nhom, ma_mh, ds_sv.ds, ds_sv.sl, ds_mon_hoc, vt_lop);
//			system("pause");
//		}
//		else if (lc == 12)
//		{
//			system("cls");
//			cout << "\n\t\tDANH SACH LOP\n";
//			cout << setw(20) << "Ma Lop" << setw(20) << "So luong" << endl;
//			for (auto it = ds_ma_lop.begin(); it != ds_ma_lop.end(); ++it)
//			{
//				string _ml = *it;
//				int dem = 0;
//				// tìm số lượng sinh viên từng lớp
//				for (int i = 0; i < ds_sv.sl; i++)
//				{
//					if (_stricmp(ds_sv.ds[i].Ma_Lop.c_str(), _ml.c_str()) == 0)
//					{
//						dem++;
//					}
//				}
//				cout << setw(20) << *it << setw(20) << dem << endl;
//			}
//			cin.ignore();
//			cout << "Nhap ma lop can in bang diem: ";
//			string ml;
//			getline(cin, ml);
//			in_bang_diem_1_lop_theo_ma_lop(ds_sv.ds, ds_sv.sl, ml, ds_lop_tin_chi, ds_mon_hoc);
//			system("pause");
//		}
//	}
//}

//============================ ĐIỂM ==============================

void in_ds_sinh_vien_trong_1_lop_tc(DS_LOP_TIN_CHI  &ds, int nk, int hk, int nhom, int ma_mh, Sinh_Vien ds_sv[], int sl_sv, DANH_SACH_MON_HOC ds_mh, int &vt_lop)
{
	Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ma_mh);
	if (p == NULL)
	{
		cout << "\n\t Ma moc hoc hoac nhom nhap vao khong chinh xac";
		return;
	}
	int dem = 1;
	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->trang_thai_lop == 1 && ds.Lop_Tin_Chi[i]->nien_khoa == nk && ds.Lop_Tin_Chi[i]->ma_mh == ma_mh && ds.Lop_Tin_Chi[i]->hoc_ky == hk && ds.Lop_Tin_Chi[i]->nhom == nhom)
		{
			vt_lop = i;
			// sắp xếp sinh viên giảm dần theo điểm thi
			for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
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
			// in danh sách sinh viên còn đăng kí
			for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.trang_thai_dang_ky == 1)
				{

					for (int j = 0; j < sl_sv; j++)
					{
						if (_stricmp(k->data.ma_sv.c_str(), ds_sv[j].ma_sv.c_str()) == 0 && dem == 1)
						{
							cout << "\n\t\t BANG DIEM MON HOV: " << p->data.ten_mh << endl;
							cout << "\t\t\tNien Khoa: " << nk << " - Hoc Ky: " << hk << " - Nhom: " << nhom << endl << endl;
							cout << "\t" << setw(3) << "STT" << "\t" << setw(9) << "MASV" << setw(20) << "HO VA TEN" << "\t" << setw(14) << "DIEM" << endl;
							cout << "\t-------------------------------------------------------\n";
							string diem;
							if (k->data.diem == NULL)
							{
								string ten = ds_sv[j].ho + " " + ds_sv[j].ten;
								cout << "\t" << setw(3) << dem++ << "\t" << setw(9) << k->data.ma_sv << setw(20) << ten << "\t" << setw(14) << "Chua nhap diem" << endl;
								cout << "\t_______________________________________________________\n";
							}
							else if (k->data.diem != NULL)
							{
								string ten = ds_sv[j].ho + " " + ds_sv[j].ten;
								cout << "\t" << setw(3) << dem++ << "\t" << setw(9) << k->data.ma_sv << setw(20) << ten << "\t" << setw(13) << k->data.diem << endl;
								cout << "\t_______________________________________________________\n";
							}
							break;
						}
						else if (_stricmp(k->data.ma_sv.c_str(), ds_sv[j].ma_sv.c_str()) == 0 && dem != 1)
						{
							string diem;
							if (k->data.diem == NULL)
							{
								string ten = ds_sv[j].ho + " " + ds_sv[j].ten;
								cout << "\t" << setw(3) << dem++ << "\t" << setw(9) << k->data.ma_sv << setw(20) << ten << "\t" << setw(14) << "Chua nhap diem" << endl;
								cout << "\t_______________________________________________________\n";
							}
							else if (k->data.diem != NULL)
							{
								string ten = ds_sv[j].ho + " " + ds_sv[j].ten;
								cout << "\t" << setw(3) << dem++ << "\t" << setw(9) << k->data.ma_sv << setw(20) << ten << "\t" << setw(13) << k->data.diem << endl;
								cout << "\t_______________________________________________________\n";
							}
							break;
						}

					}
				}
			}
			break;
		}
	}
	if (dem == 1)
	{
		cout << "\n\t Ma moc hoc hoac nhom nhap vao khong chinh xac";
	}
}

NODE_SV_DANG_KY_TIN_CHI *kt_sv_co_ton_tai_trong_lop_tin_chi(DSSV_DANG_KY_TIN_CHI ds, string ma_sv)
{
	for (NODE_SV_DANG_KY_TIN_CHI *k = ds.pHead; k != NULL; k = k->pNext)
	{
		if ((_stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0) && k->data.trang_thai_dang_ky == 1)
		{
			return k;
		}
	}
	return NULL;
}
bool kt_khong_trung_nhau_trong_mang(int mang[], int sl, int so_dua_vao)
{
	if (sl == 0)
	{
		return true;
	}
	for (int i = 0; i < sl; i++)
	{
		if (mang[i] == so_dua_vao)
		{
			return false;
		}
	}
	return true;
}
void in_bang_diem_1_lop_theo_ma_lop(Sinh_Vien ds_sv[], int sl_sv, string ma_lop, DS_LOP_TIN_CHI ds_lop_tc, DANH_SACH_MON_HOC ds_mh)
{

	string mang_ma_sv[20];
	int sl_mang_sv = 0;
	// duyệt để tìm mảng mã sinh viên trong 1 lớp
	for (int i = 0; i < sl_sv; i++)
	{
		if (_stricmp(ds_sv[i].Ma_Lop.c_str(), ma_lop.c_str()) == 0)
		{
			mang_ma_sv[sl_mang_sv++] = ds_sv[i].ma_sv;
		}
	}

	for (int i = 0; i < sl_mang_sv; i++)
	{
		int mang_ten_mh[20];
		int sl_mang_ten_mh = 0;
		float ds_diem[20];
		int sl_diem = 0;
		int _kt = 0;
		// duyệt qua từng lớp tín chỉ
		for (int j = 0; j < ds_lop_tc.sl; j++)
		{
			for (NODE_SV_DANG_KY_TIN_CHI *k = ds_lop_tc.Lop_Tin_Chi[j]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
			{
				if (_stricmp(k->data.ma_sv.c_str(), mang_ma_sv[i].c_str()) == 0 && k->data.trang_thai_dang_ky == 1 && i == 0)
				{
					bool kt_trung = kt_khong_trung_nhau_trong_mang(mang_ten_mh, sl_mang_ten_mh, ds_lop_tc.Lop_Tin_Chi[j]->ma_mh);
					if (kt_trung == true)
					{
						mang_ten_mh[sl_mang_ten_mh++] = ds_lop_tc.Lop_Tin_Chi[j]->ma_mh;
					}
					ds_diem[sl_diem++] = k->data.diem;
				}
				else if (_stricmp(k->data.ma_sv.c_str(), mang_ma_sv[i].c_str()) == 0 && k->data.trang_thai_dang_ky == 1 && i != 0 && _kt == 0)
				{
					int vt_sv = kt_ma_sv_ton_tai(ds_sv, sl_sv, mang_ma_sv[i]);
					string hoten = ds_sv[vt_sv].ho + " " + ds_sv[vt_sv].ten;
					cout << "  " << setw(2) << i + 1 << "  " << setw(10) << k->data.ma_sv << setw(20) << hoten << "\t\t" << setw(2) << k->data.diem << "\t\t\t\t";
					_kt = 1;
				}
				else if (_stricmp(k->data.ma_sv.c_str(), mang_ma_sv[i].c_str()) == 0 && k->data.trang_thai_dang_ky == 1 && i != 0 && _kt == 1)
				{
					cout << setw(2) << k->data.diem << "\t\t\t";
				}
			}
		}
		if (i == 0)
		{
			// xuất tiêu đề
			cout << "\n\t\t\t\t\t\tBANG DIEM TONG KET\n";
			viet_hoa_ma_lop(ma_lop);
			cout << "\t\t\t\t\t\tLop: " << ma_lop << endl << endl;
			cout << "  " << setw(2) << "STT" << "  " << setw(9) << "MASV" << setw(20) << "Ho va ten" << "\t";
			int vt_sv = kt_ma_sv_ton_tai(ds_sv, sl_sv, mang_ma_sv[i]);
			string hoten = ds_sv[vt_sv].ho + " " + ds_sv[vt_sv].ten;

			// xuất danh sách các tên khoá học
			for (int g = 0; g < sl_mang_ten_mh; g++)
			{
				Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, mang_ten_mh[g]);
				cout << setw(2) << p->data.ten_mh << "\t";
			}
			cout << endl;
			cout << "  ---------------------------------------------------------------------------------------------------------------\n";
			// xuất thông tin sinh viên đầu tiên
			int check = 0;
			for (int j = 0; j < ds_lop_tc.sl; j++)
			{
				for (NODE_SV_DANG_KY_TIN_CHI *k = ds_lop_tc.Lop_Tin_Chi[j]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
				{
					if (_stricmp(k->data.ma_sv.c_str(), mang_ma_sv[i].c_str()) == 0 && k->data.trang_thai_dang_ky == 1 && check == 0)
					{
						cout << "  " << setw(2) << i + 1 << "  " << setw(10) << k->data.ma_sv << setw(20) << hoten << "\t\t" << setw(2) << k->data.diem << "\t\t\t\t";
						check++;
					}
					else if (_stricmp(k->data.ma_sv.c_str(), mang_ma_sv[i].c_str()) == 0 && k->data.trang_thai_dang_ky == 1 && check == 1)
					{
						cout << setw(2) << k->data.diem << "\t\t\t";
					}
				}
			}

		}
		cout << "\n  _______________________________________________________________________________________________________________\n";
	}
}

// ============================ MÔN HỌC ==============================
void Nhap_1_mon_hoc(DANH_SACH_MON_HOC &ds_mh)
{
	Node_Mon_Hoc *p = new Node_Mon_Hoc;
	p->data.ma_mh = tao_ma_mon_hoc(ds_mh);
	cout << "Ma mon hoc: " << p->data.ma_mh << endl;
	cin.ignore();
	cout << "Nhap ten moc hoc: ";
	getline(cin, p->data.ten_mh);
	cout << "Nhap so tin chi li thuyet: ";
	cin >> p->data.STCLT;
	cout << "Nhap so tin chi thuc hanh: ";
	cin >> p->data.STCTH;
	them_mon_hoc(ds_mh.t, p);
	ds_mh.sl++;
}
Node_Mon_Hoc* kt_trung_ma_mh(TREE t, int ma_mh)
{
	if (t != NULL)
	{
		if (t->data.ma_mh > ma_mh)
		{
			kt_trung_ma_mh(t->pLeft, ma_mh);
		}
		else if (t->data.ma_mh < ma_mh)
		{
			kt_trung_ma_mh(t->pRight, ma_mh);
		}
		else
		{
			return t;
		}
	}
	else
	{
		return NULL;
	}
}
int tao_ma_mon_hoc(DANH_SACH_MON_HOC ds)
{
	int ma_mh;
	do
	{
		ma_mh = rand() % (999 - 100 + 1) + 100;
	} while (kt_trung_ma_mh(ds.t, ma_mh) != NULL);
	return ma_mh;
}
void them_mon_hoc(TREE &t, Node_Mon_Hoc *p)
{
	if (t != NULL)
	{
		if (t->data.ma_mh > p->data.ma_mh)
		{
			them_mon_hoc(t->pLeft, p);
		}
		else if (t->data.ma_mh < p->data.ma_mh)
		{
			them_mon_hoc(t->pRight, p);
		}
	}
	else
	{
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
}
void tim_node_trai_nhat_cua_cay_con_phai(TREE &t, Node_Mon_Hoc *p) // t = t->pRight , // p là node cần xoá
{
	if (t->pLeft == NULL)
	{
		p->data = t->data;
		Node_Mon_Hoc *tam = t;
		t = t->pLeft;
		delete tam;
	}
	else
	{
		tim_node_trai_nhat_cua_cay_con_phai(t->pLeft, p);
	}
}
void Xoa_1_moc_hoc(TREE &t, int ma_mh, int &check)
{
	if (t != NULL)
	{
		if (t->data.ma_mh > ma_mh)
		{
			Xoa_1_moc_hoc(t->pLeft, ma_mh, check);
		}
		else if (t->data.ma_mh < ma_mh)
		{
			Xoa_1_moc_hoc(t->pRight, ma_mh, check);
		}
		else
		{
			check = 1;
			// xoá node lá
			if (t->pLeft == NULL && t->pRight == NULL)
			{
				Node_Mon_Hoc *tam = t;
				delete tam;
				t = NULL;
				return;
			}
			// xoá node có 1 con
			else if (t->pLeft == NULL && t->pRight != NULL)
			{
				Node_Mon_Hoc *tam = t;
				t = t->pRight;
				delete tam;
				return;
			}
			else if (t->pLeft != NULL && t->pRight == NULL)
			{
				Node_Mon_Hoc *tam = t;
				t = t->pLeft;
				delete tam;
				return;
			}
			// xoá node có 2 con
			else
			{
				tim_node_trai_nhat_cua_cay_con_phai(t->pRight, t);
			}
		}
	}
}
void xuat_ds_mon_hoc(TREE t)
{

	if (t != NULL)
	{
		xuat_ds_mon_hoc(t->pLeft);
		cout << "   " << setw(3) << "\t" << t->data.ma_mh << setw(37) << t->data.ten_mh << setw(8) << t->data.STCLT << setw(10) << t->data.STCTH << endl;
		xuat_ds_mon_hoc(t->pRight);
	}
}

void cap_nhat_1_mh(Node_Mon_Hoc *&p)
{
	// cho xem thông tin của môn học đó
	cout << "\n\t\tTHONG TIN MON HOC\n";;
	cout << setw(20) << "Ma mon hoc" << setw(20) << "Ten mon hoc" << setw(20) << "STCLT" << setw(20) << "STCTH" << endl;
	cout << setw(17) << p->data.ma_mh << setw(23) << p->data.ten_mh << setw(20) << p->data.STCLT << setw(20) << p->data.STCTH << endl;
	cout << "\n\tCap nhat thong tin\n";
	cout << "Nhap ten mon hoc: ";
	cin.ignore();
	getline(cin, p->data.ten_mh);
	cout << "Nhap STCLT: ";
	cin >> p->data.STCLT;
	cout << "Nhap STCTH: ";
	cin >> p->data.STCTH;
}

// ========================= SINH VIÊN =====================
void Nhap_tt_1_sv(Sinh_Vien &x, string ma_lop_nhap, Sinh_Vien ds[], int sl)
{
	x.Ma_Lop = ma_lop_nhap;
	viet_hoa_ma_lop(x.Ma_Lop);
	cout << "Ma lop: " << x.Ma_Lop << endl;
	tao_ma_sv(x.ma_sv, ds, sl);
	cout << "Ma sinh vien: " << x.ma_sv << endl;
	cout << "Nhap ho: "; getline(cin, x.ho);
	chuan_hoa_chu(x.ho);
	cout << "Nhap ten: "; getline(cin, x.ten);
	chuan_hoa_chu(x.ten);
	cout << "Nhap phai: "; getline(cin, x.phai);
	cout << "Nhap so dien thoai: "; getline(cin, x.SO_DT);
}

void tao_ma_sv(string &ma_sv, Sinh_Vien ds[], int sl)
{
	ma_sv.insert(ma_sv.length(), "QNU44");
	if (sl == 0)
	{
		ma_sv.insert(ma_sv.length(), "0001");
	}
	else
	{
		int so_sv = 0;
		for (int i = 5; i < ds[sl - 1].ma_sv.length(); i++)
		{
			so_sv = so_sv * 10 + (ds[sl - 1].ma_sv[i] - 48);
		}
		string so = to_string(so_sv + 1);
		if (so.length() == 1)
		{
			so.insert(0, "000");
		}
		else if (so.length() == 2)
		{
			so.insert(0, "00");
		}
		else if (so.length() == 3)
		{
			so.insert(0, "0");
		}
		ma_sv.insert(ma_sv.length(), so);
	}
}

void xuat_ds_sv(Sinh_Vien ds[], int sl, string ma_lop, int &check)
{
	sap_xep_sv_theo_ten(ds, sl);
	cout << "\t" << setw(9) << "Ma sinh vien" << setw(20) << "Ho va ten" << "\t" << setw(3) << "Phai" << setw(15) << "SDT" << endl;
	for (int i = 0; i < sl; i++)
	{
		if (_stricmp(ma_lop.c_str(), ds[i].Ma_Lop.c_str()) == 0)
		{
			check = 1;
			string hoten = ds[i].ho + " " + ds[i].ten;
			cout << "\t" << setw(9) << ds[i].ma_sv << setw(23) << hoten << setw(11) << ds[i].phai << setw(23) << ds[i].SO_DT << endl;
		}

	}
}

void xuat_ds_sv(Sinh_Vien ds[], int sl)
{
	sap_xep_sv_theo_ten(ds, sl);
	cout << "\t" << setw(9) << "Ma sinh vien" << setw(20) << "Ho va ten" << "\t" << setw(3) << "Phai" << setw(15) << "SDT" << endl;
	for (int i = 0; i < sl; i++)
	{

		string hoten = ds[i].ho + " " + ds[i].ten;
		cout << "\t" << setw(9) << ds[i].ma_sv << setw(23) << hoten << setw(11) << ds[i].phai << setw(23) << ds[i].SO_DT << endl;


	}
}

void viet_hoa_ma_lop(string &ma_lop)
{
	for (int i = 0; i < ma_lop.length(); i++)
	{
		if (ma_lop[i] >= 97 && ma_lop[i] <= 122)
		{
			ma_lop[i] -= 32;
		}
	}
}

void chuan_hoa_chu(string &a)
{
	// xứ lí kí tự đầu
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	// xử lí kí tự cuối
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	// xoá kí tự giữa
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	// chuẩn hoá kí tự
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if ((a[i] >= 97 && a[i] <= 122) && a[i - 1] == ' ')
		{
			a[i] -= 32;
		}
		else
		{
			if (a[i] >= 65 && a[i] <= 90)
			{
				a[i] += 32;
			}
		}
	}
}
int kt_ma_sv_ton_tai(Sinh_Vien ds[], int sl, string ma_sv)
{
	for (int i = 0; i < sl; i++)
	{
		if (_stricmp(ds[i].ma_sv.c_str(), ma_sv.c_str()) == 0)
		{
			return i;
		}
	}
	return -1;
}
void xoa_sinh_vien(Sinh_Vien ds[], int &sl)
{
	string ma_sv_xoa;
	cout << "Nhap ma sinh vien can xoa: ";
	getline(cin, ma_sv_xoa);
	if (kt_ma_sv_ton_tai(ds, sl, ma_sv_xoa) == -1)
	{
		cout << "\n\tKhong ton tai ma sinh vien";
	}
	else
	{
		if (sl == 1)
		{
			sl--;
			return;
		}
		for (int i = kt_ma_sv_ton_tai(ds, sl, ma_sv_xoa); i < sl - 1; i++)
		{
			ds[i] = ds[i + 1];
		}
		sl--;
		cout << "\n\tDa xoa thanh cong";
	}
}

string cat_ten(string ten)
{
	string ten_cat;
	int i;
	// cắt chuỗi
	int dem = 0;
	for (i = ten.length() - 1; i >= 0; i--)
	{
		if (ten[i] == ' ')
			break;
		dem++;
	}
	ten_cat = ten.substr(i + 1, dem);
	return ten_cat;
}

void sap_xep_sv_theo_ten(Sinh_Vien ds[], int sl)
{
	for (int i = 0; i < sl - 1; i++)
	{
		for (int j = i + 1; j < sl; j++)
		{
			if (_stricmp(cat_ten(ds[i].ten).c_str(), cat_ten(ds[j].ten).c_str()) > 0)
			{
				swap(ds[i], ds[j]);
			}
			if (_stricmp(cat_ten(ds[i].ten).c_str(), cat_ten(ds[j].ten).c_str()) == 0)
			{
				if (_stricmp(ds[i].ho.c_str(), ds[j].ho.c_str()) > 0)
				{
					swap(ds[i], ds[j]);
				}
			}
		}
	}
}

void swap(Sinh_Vien &x, Sinh_Vien &y)
{
	Sinh_Vien tam = x;
	x = y;
	y = tam;
}

void hieu_chinh_sinh_vien(Sinh_Vien ds[], int sl)
{
	string ma_sv_xoa;
	cout << "Nhap ma sinh vien can xoa: ";
	getline(cin, ma_sv_xoa);
	if (kt_ma_sv_ton_tai(ds, sl, ma_sv_xoa) == -1)
	{
		cout << "\n\tKhong ton tai ma sinh vien";
	}
	else
	{

		// thông tin cũ của sinh viên
		int vt = kt_ma_sv_ton_tai(ds, sl, ma_sv_xoa);
		Sinh_Vien tam = ds[vt]; // lưu thông tin của sinh viên muốn sửa
		string hoten = ds[vt].ho + " " + ds[vt].ten;
		cout << "\n\tThong tin sinh vien muon cap nhat\n";
		cout << "\t" << setw(9) << "Ma sinh vien" << setw(20) << "Ho va ten" << "\t" << setw(3) << "Phai" << setw(11) << "SDT" << endl;
		cout << "\t" << setw(9) << ds[vt].ma_sv << setw(23) << hoten << setw(11) << ds[vt].phai << setw(11) << ds[vt].SO_DT << endl;
		// cập nhật thông tin sinh viên
		cout << "\n\t\tCap nhat thong tin sinh vien\n";
		cout << "Nhap ho : "; getline(cin, ds[vt].ho);
		if (ds[vt].ho.empty())
		{
			ds[vt].ho = tam.ho;
			cout << ds[vt].ho << endl;
		}
		chuan_hoa_chu(ds[vt].ho);
		cout << "Nhap ten: "; getline(cin, ds[vt].ten);
		if (ds[vt].ten.empty())
		{
			ds[vt].ten = tam.ten;
			cout << ds[vt].ten << endl;
		}
		chuan_hoa_chu(ds[vt].ten);
		cout << "Nhap phai: "; getline(cin, ds[vt].phai);
		if (ds[vt].phai.empty())
		{
			ds[vt].phai = tam.phai;
			cout << ds[vt].phai << endl;
		}
		cout << "Nhap so dien thoai: "; getline(cin, ds[vt].SO_DT);
		if (ds[vt].SO_DT.empty())
		{
			ds[vt].SO_DT = tam.SO_DT;
			cout << ds[vt].SO_DT << endl;
		}
	}
}

// ================ LOAD FILE ======================
void load_file_ds_sv(Sinh_Vien ds[], int &sl, set<string> &ds_ma_lop)
{
	ifstream FileIn;
	FileIn.open("ds_sv.txt");
	while (!FileIn.eof())
	{
		Sinh_Vien x;
		getline(FileIn, x.ma_sv, ',');
		getline(FileIn, x.ho, ',');
		getline(FileIn, x.ten, ',');
		getline(FileIn, x.phai, ',');
		getline(FileIn, x.SO_DT, ',');
		getline(FileIn, x.Ma_Lop);
		if (!x.Ma_Lop.empty())
		{
			ds_ma_lop.insert(x.Ma_Lop);
		}
		ds[sl++] = x;
	}
	FileIn.close();
}

void load_file_mon_hoc(DANH_SACH_MON_HOC &ds)
{
	ifstream FileIn;
	FileIn.open("ds_mh.txt");
	while (!FileIn.eof())
	{
		Node_Mon_Hoc *p = new Node_Mon_Hoc;
		FileIn >> p->data.ma_mh;
		FileIn.ignore();
		getline(FileIn, p->data.ten_mh, ',');
		FileIn >> p->data.STCLT;
		FileIn.ignore();
		FileIn >> p->data.STCTH;
		FileIn.ignore();
		them_mon_hoc(ds.t, p);
		ds.sl++;
	}
	FileIn.close();
}

void ghi_file_ds_lop_tin_chi(DS_LOP_TIN_CHI ds)
{
	ofstream Fileout;
	Fileout.open("ds_lop_tc.txt");
	for (int i = 0; i < ds.sl; i++)
	{
		Fileout << ds.Lop_Tin_Chi[i]->maLopTinCHi << ",";
		Fileout << ds.Lop_Tin_Chi[i]->ma_mh << ",";
		Fileout << ds.Lop_Tin_Chi[i]->nien_khoa << ",";
		Fileout << ds.Lop_Tin_Chi[i]->hoc_ky << ",";
		Fileout << ds.Lop_Tin_Chi[i]->nhom << ",";
		Fileout << ds.Lop_Tin_Chi[i]->so_sv_min << ",";
		Fileout << ds.Lop_Tin_Chi[i]->so_sv_max << ",";
		if (ds.sl - 1 == i)
		{
			Fileout << ds.Lop_Tin_Chi[i]->trang_thai_lop;
		}
		else
		{
			Fileout << ds.Lop_Tin_Chi[i]->trang_thai_lop << endl;
		}
	}
	Fileout.close();
}

void load_file_ds_lop_tin_chi(DS_LOP_TIN_CHI &ds_lop_tin_chi)
{
	ifstream FileIn;
	FileIn.open("ds_lop_tc.txt");
	while (!FileIn.eof())
	{
		ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl] = new LOP_TIN_CHI;
		FileIn >> ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->maLopTinCHi;
		FileIn.ignore();
		FileIn >> ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->ma_mh;
		FileIn.ignore();
		FileIn >> ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->nien_khoa;
		FileIn.ignore();
		FileIn >> ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->hoc_ky;
		FileIn.ignore();
		FileIn >> ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->nhom;
		FileIn.ignore();
		FileIn >> ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->so_sv_min;
		FileIn.ignore();
		FileIn >> ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->so_sv_max;
		FileIn.ignore();
		FileIn >> ds_lop_tin_chi.Lop_Tin_Chi[ds_lop_tin_chi.sl]->trang_thai_lop;
		FileIn.ignore();
		ds_lop_tin_chi.sl++;
	}
	FileIn.close();
}

// cấu trúc file này
//			số mã lớp tín chỉ,số sinh viên trong lớp tín chỉ đó
//			ds sinh viên bao gồm mã sinh viên, trạng thái đăng ký

void ghi_file_ds_sv_dang_ky_lop_tc(DS_LOP_TIN_CHI ds)
{
	ofstream FileOut;
	FileOut.open("ds_sv_dang_ky_tin_chi.txt");
	for (int i = 0; i < ds.sl; i++)
	{
		// dòng đầu tiên ghi mã lớp tín chỉ và ghi số lượng sinh viên đã đăng ký của lớp tín chỉ đó
		FileOut << ds.Lop_Tin_Chi[i]->maLopTinCHi;
		FileOut << ",";
		FileOut << ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.sl;  // ghi bên file không chạm vào
		FileOut << endl;
		for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
		{
			FileOut << k->data.ma_sv;
			FileOut << ",";
			FileOut << k->data.trang_thai_dang_ky;
			FileOut << endl;
		}
	}
	FileOut.close();
}

void load_file_ds_sv_dk_tin_chi(DS_LOP_TIN_CHI &ds)
{
	ifstream FileIn;
	FileIn.open("ds_sv_dang_ky_tin_chi.txt");
	for (int i = 0; i < ds.sl; i++)
	{
		FileIn >> ds.Lop_Tin_Chi[i]->maLopTinCHi;
		FileIn.ignore();
		FileIn >> ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.sl;  // ghi bên file không chạm vào
		int sl_sv = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.sl;  // ghi bên file không chạm vào
		for (int j = 0; j < sl_sv; j++)
		{
			FileIn.ignore();
			SINH_VIEN_DANG_KY_TIN_CHI x;
			getline(FileIn, x.ma_sv, ',');
			FileIn >> x.trang_thai_dang_ky;
			x.diem = NULL;
			NODE_SV_DANG_KY_TIN_CHI *p = khoiTaoNode_sv_dk_tin_chi(x);
			ThemNode_sv_dk_tin_chi(ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI, p);
		}
	}
	FileIn.close();
}

void xuat_ds_sv_dky_tin_chi(DS_LOP_TIN_CHI ds)
{
	int sl = 0;
	for (int i = 0; i < ds.sl; i++)
	{
		for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
		{
			cout << k->data.ma_sv << endl;
			sl++;
		}
	}
	cout << sl;
}

// ============ Cấu trúc file
/*
	vị trí lớp tín chỉ, số lượng sinh viên còn đăng kí
	mã sinh viên, điểm
	...
*/

void ghi_file_diem_cho_sv(DS_LOP_TIN_CHI ds)
{
	ofstream Fo;
	Fo.open("diem_thi.txt");
	for (int i = 0; i < ds.sl; i++)
	{
		if (ds.Lop_Tin_Chi[i]->trang_thai_lop == 1)
		{
			// ghi vào vị trí lớp tín chỉ
			Fo << i;
			Fo << ",";
			int sl_sv_con_dk = so_luong_sinh_vien_con_dang_ky_1_lop_tc(ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI);
			// ghi vào số lượng còn đăng kí
			Fo << sl_sv_con_dk;
			Fo << endl;
			for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.trang_thai_dang_ky == 1)
				{
					Fo << k->data.diem;
					Fo << endl;
				}
			}
		}
	}
	Fo.close();
}

void load_file_diem_thi(DS_LOP_TIN_CHI &ds)
{
	ifstream FileIn;
	FileIn.open("diem_thi.txt");
	while (!FileIn.eof())
	{
		int vt;
		FileIn >> vt;
		FileIn.ignore();
		int sl;
		FileIn >> sl;

		for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[vt]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
		{
			if (k->data.trang_thai_dang_ky == 1)
			{
				FileIn >> k->data.diem;
			}
		}
	}
	FileIn.close();
}
// ================== XỬ LÍ THÊM ======================
/*
	// CẤU TRÚC FILE

	Mã sinh viên, Số lượng lớp mà sinh viên đó còn đăng kí và huỷ đăng kí
	Mã lớp tín chỉ, trạng thái đăng kí(còn đăng kí hoặc đã huỷ đăng kí)

*/

void ghi_file_lich_su_dang_ky_tin_chi(DS_LOP_TIN_CHI ds_lop_tc, Sinh_Vien ds_sv[], int sl_sv)
{
	ofstream FileOut;
	FileOut.open("lich_su_dang_ky_tin_chi.txt");
	// duyệt qua từng sinh viên
	for (int i = 0; i < sl_sv - 1; i++)
	{
		// ghi mã sinh viên
		string ma_sv_tam = ds_sv[i].ma_sv;
		FileOut << ma_sv_tam;
		if (ma_sv_tam == "")
		{
			break;
		}
		FileOut << ",";
		// ghi số lượng lớp tín chỉ mà sinh viên đó còn đăng kí và huỷ đăng kí
		FileOut << sl_lop_sv_con_dk_va_huy_dk(ds_lop_tc, ds_sv[i].ma_sv);
		FileOut << endl;
		// duyệt qua từng lớp học phần
		for (int j = 0; j < ds_lop_tc.sl; j++)
		{
			for (NODE_SV_DANG_KY_TIN_CHI *k = ds_lop_tc.Lop_Tin_Chi[j]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
			{
				if (_stricmp(k->data.ma_sv.c_str(), ds_sv[i].ma_sv.c_str()) == 0)
				{
					// ghi mã lớp tín chỉ
					FileOut << ds_lop_tc.Lop_Tin_Chi[j]->maLopTinCHi;
					FileOut << ",";
					// ghi trạng thái đăng kí
					FileOut << k->data.trang_thai_dang_ky;
					FileOut << endl;
				}
			}
		}
	}
	FileOut.close();
}
// =========== số lượng lớp mà sinh viên đó còn đăng kí và huỷ đăng kí
int sl_lop_sv_con_dk_va_huy_dk(DS_LOP_TIN_CHI ds, string ma_sv)
{
	int sl_lop = 0;
	for (int i = 0; i < ds.sl; i++)
	{
		for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
		{
			if (_stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0)
			{
				sl_lop++;
			}
		}
	}
	return sl_lop;
}

void xem_ls_dk_hoc_phan_cua_1_sinh_vien(DS_LOP_TIN_CHI ds, string ma_sv, DANH_SACH_MON_HOC ds_mh)
{
	cout << "\t" << setw(11) << "Thao tac" << "\t" << setw(5) << "Ma lop tin chi " << setw(30) << "Ten mon hoc" << setw(7) << "     " << "Nhom" << endl;
	cout << "\t----------------------------------------------------------------------------\n";
	for (int i = 0; i < ds.sl; i++)
	{
		for (NODE_SV_DANG_KY_TIN_CHI *k = ds.Lop_Tin_Chi[i]->DS_SV_DANG_KY_TIN_CHI.pHead; k != NULL; k = k->pNext)
		{
			if (_stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0)
			{
				if (k->data.trang_thai_dang_ky == 1)
				{
					cout << "\t" << setw(11) << "Dang ki";
				}
				else
				{
					cout << "\t" << setw(11) << "Huy dang ki";
				}
				cout << "\t" << setw(10) << ds.Lop_Tin_Chi[i]->maLopTinCHi;
				Node_Mon_Hoc *p = kt_trung_ma_mh(ds_mh.t, ds.Lop_Tin_Chi[i]->ma_mh);
				cout << setw(35) << p->data.ten_mh;
				cout << setw(10) << ds.Lop_Tin_Chi[i]->nhom << endl;
				cout << "\t____________________________________________________________________________\n";

			}
		}
	}
	// qua xử lí đồ hoạ xoá màn hình
}
#pragma once
