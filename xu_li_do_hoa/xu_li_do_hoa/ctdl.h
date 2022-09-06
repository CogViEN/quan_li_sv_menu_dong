#pragma once
#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<set>
#include<conio.h>

// ================= KHAI BÁO CẤU TRÚC CÂY NHỊ PHÂN TÌM KIẾM DANH SÁCH CÁC MÔN HỌC =========================
struct MonHoc
{
	int ma_mh;
	string ten_mh;
	int STCLT;
	int STCTH;
};

struct Node_Mon_Hoc
{
	MonHoc data;
	Node_Mon_Hoc *pLeft;
	Node_Mon_Hoc *pRight;
};

typedef Node_Mon_Hoc *TREE;

struct DANH_SACH_MON_HOC
{
	TREE t = NULL;
	int sl = 0;
};

// ================= KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN DANH SÁCH SINH VIÊN ĐĂNG KÝ LỚP TÍN CHỈ =========================
struct SINH_VIEN_DANG_KY_TIN_CHI
{
	string ma_sv;
	int trang_thai_dang_ky;  // 0: huỷ đăng kí , 1 : còn đăng kí
	float diem;
};

struct NODE_SV_DANG_KY_TIN_CHI
{
	SINH_VIEN_DANG_KY_TIN_CHI data;
	NODE_SV_DANG_KY_TIN_CHI *pNext;
};

struct DSSV_DANG_KY_TIN_CHI
{
	NODE_SV_DANG_KY_TIN_CHI *pHead = NULL;
	NODE_SV_DANG_KY_TIN_CHI *pTail = NULL;
	int sl = 0; // bao gồm cả số lượng sinh viên đăng kí và huỷ đăng kí
};

// ================= KHAI BÁO CẤU TRÚC MẢNG CON TRỎ DANH SÁCH LỚP TÍN CHỈ =========================
struct LOP_TIN_CHI
{
	int maLopTinCHi;
	int ma_mh;
	int nien_khoa;
	int hoc_ky;
	int nhom;
	int so_sv_min; // số sinh viên ít nhất mà lớp có thể có để có thể mở lớp để dạy (thông tin trên mạng 30)
	int so_sv_max; // số sinh viên nhiều nhất trong 1 lớp ( thông tin trên mạng 80)
	int trang_thai_lop; // 0 lớp bị huỷ khi số sinh viên đăng kí ít hơn so_sv_min
						// 1 lớp được mở
	//danh sách sinh viên đăng kí lớp tín chỉ
	DSSV_DANG_KY_TIN_CHI DS_SV_DANG_KY_TIN_CHI;
};

struct DS_LOP_TIN_CHI
{
	LOP_TIN_CHI *Lop_Tin_Chi[10000];
	int sl = 0;
};

// ================= KHAI BÁO CẤU TRÚC MẢNG TUYẾN TÍNH DANH SÁCH SINH VIÊN =========================
struct Sinh_Vien
{
	string ma_sv;
	string ho;
	string ten;
	string phai;
	string SO_DT;
	string Ma_Lop;
};
struct DANH_SACH_SINH_VIEN
{
	Sinh_Vien ds[5000];
	int sl = 0;
};
