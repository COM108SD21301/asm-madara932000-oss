#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Chuc nang 1 : kiem tra so nguyen
void kt_songuyen(int a)
{
    if (a == (int)a)
        cout << a << " la so nguyen!\n";
    else
        cout << a << " khong phai la so nguyen!\n";
}

void kt_songuyento(int a)
{
    int dem = 0;
    if (a > 1)
    {
        for (int i = 2; i <= sqrt(a); i++)
        {
            if (a % i == 0)
                dem++;
        }
    }
    else dem++;

    if (dem == 0)
        cout << a << " la so nguyen to!\n";
    else
        cout << a << " khong phai la so nguyen to!\n";
}

void kt_sochinhphuong(int a)
{
    bool ok = false;
    for (int i = 1; i <= sqrt(a); i++)
    {
        if (i * i == a)
        {
            ok = true;
            break;
        }
    }
    if (ok)
        cout << a << " la so chinh phuong!\n";
    else
        cout << a << " khong phai la so chinh phuong!\n";
}

// Chuc nang 2 : UCLN & BCNN
void tim_uoc(int a, int b)
{
    if (a == 0 || b == 0)
    {
        cout << "Uoc chung lon nhat la: " << a + b << endl;
        return;
    }
    while (a != b)
    {
        if (a > b) a -= b;
        else b -= a;
    }
    cout << "Uoc chung lon nhat la: " << a << endl;
}

void tim_boi(int a, int b)
{
    int step = max(a, b);
    int temp = 0;

    for (int i = step; i <= a * b; i += step)
    {
        if (i % a == 0 && i % b == 0)
        {
            temp = i;
            break;
        }
    }
    cout << "Boi chung nho nhat la: " << temp << endl;
}

// Chuc nang 3 : Karaoke
void karaoke()
{
    int gio_batdau, gio_ketthuc;
    float tien = 0;

    cout << "Nhap vao thoi gian bat dau: ";
    cin >> gio_batdau;

    cout << "Nhap vao thoi gian ket thuc: ";
    cin >> gio_ketthuc;

    int tonggio = gio_ketthuc - gio_batdau;

    if (gio_batdau < 12 || gio_ketthuc > 23)
        cout << "Quan hien tai chua mo cua!\n";

    if (tonggio <= 3)
    {
        tien = 150000;
    }
    else
    {
        tien = 150000 * 3 + (tonggio - 3) * 150000 * 0.7;
    }

    if (gio_batdau >= 14 && gio_ketthuc <= 17)
        tien *= 0.9;

    cout << "Tong so tien can thanh toan la: " << tien << " VND\n";
}

// Chuc nang 4: tinh tien dien
void tinhtiendien(int a)
{
    float bac1 = 50 * 1.678;
    float bac2 = bac1 + 50 * 1.734;
    float bac3 = bac2 + 100 * 2.014;
    float bac4 = bac3 + 100 * 2.536;
    float bac5 = bac4 + 100 * 2.834;

    if (a <= 50)
        cout << "So tien can phai tra la: " << bac1 << " VND\n";
    else if (a <= 100)
        cout << "So tien can phai tra la: " << bac1 + (a - 50) * 1.734 << " VND\n";
    else if (a <= 200)
        cout << "So tien can phai tra la: " << bac2 + (a - 100) * 2.014 << " VND\n";
    else if (a <= 300)
        cout << "So tien can phai tra la: " << bac3 + (a - 200) * 2.536 << " VND\n";
    else if (a <= 400)
        cout << "So tien can phai tra la: " << bac4 + (a - 300) * 2.834 << " VND\n";
    else
        cout << "So tien can phai tra la: " << bac5 + (a - 400) * 2.927 << " VND\n";
}

// Chuc nang 5: doi tien
void doitien()
{
    int giaTien[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int tien;

    cout << "Nhap vao so tien can doi: ";
    cin >> tien;

    for (int i = 0; i < 9; i++)
    {
        int soTo = tien / giaTien[i];
        if (soTo > 0)
            cout << soTo << " to " << giaTien[i] << endl;
        tien %= giaTien[i];
    }
}

// Chuc nang 6: tinh lai suat
void tinhlaisuat()
{
    int tienvay;
    cout << "Nhap vao so tien can vay: ";
    cin >> tienvay;

    int laisuat = tienvay * 0.05;
    int laimoithang = laisuat / 12;
    int tiengoc = tienvay / 12;

    cout << "|Ky han|Lai tra|Goc tra|Tong tra|Tien con lai|\n";

    for (int i = 1; i <= 12; i++)
    {
        cout << "|" << i << "\t|" << laisuat << "\t|" << tiengoc << "\t|"
            << tiengoc + laisuat << "\t|" << tienvay - tiengoc << endl;

        laisuat -= laimoithang;
        tienvay -= tiengoc;
    }
}

// Chuc nang 7: vay tien mua xe
void vaytien()
{
    float tien_codinh = 500000000.0;
    float phantram;

    cout << "Nhap vao so phan tram can vay trong 500 trieu: ";
    cin >> phantram;

    if (phantram < 0 || phantram > 100)
    {
        cout << "Nhap sai so phan tram!\n";
        return;
    }

    float tratruoc = (100 - phantram) / 100.0;
    float tien_tratruoc = tien_codinh * tratruoc;

    float tienthang =
        (tien_codinh - tien_tratruoc) * (0.006 * pow(1 + 0.006, 288)) /
        (pow(1 + 0.006, 288) - 1);

    cout << "|So tien co dinh|So tien tra truoc|So tien tra moi thang|\n";
    cout << "|" << tien_codinh << "\t|" << tien_tratruoc << "\t|" << tienthang << endl;
}

// Chuc nang 8: sap xep sinh vien
void checkDiem(float diem)
{
    if (diem < 0 || diem > 10)
        cout << "Diem khong hop le!\n";
    else if (diem >= 9)
        cout << "Hoc luc xuat sac!\n";
    else if (diem >= 8)
        cout << "Hoc luc gioi!\n";
    else if (diem >= 6.5)
        cout << "Hoc luc kha!\n";
    else if (diem >= 5)
        cout << "Hoc luc trung binh!\n";
    else
        cout << "Hoc luc yeu!\n";
}

void sapxepSV()
{
    int sv;
    cout << "Nhap vao so luong sinh vien: ";
    cin >> sv;

    struct sinhVien
    {
        string tenSV;
        float diem;
    };

    sinhVien* mangSV = new sinhVien[sv];

    for (int i = 0; i < sv; i++)
    {
        cout << "Nhap ten SV " << i + 1 << ": ";
        cin >> mangSV[i].tenSV;

        cout << "Nhap diem SV " << i + 1 << ": ";
        cin >> mangSV[i].diem;
    }

    for (int i = 0; i < sv - 1; i++)
    {
        for (int j = i + 1; j < sv; j++)
        {
            if (mangSV[i].diem < mangSV[j].diem)
                swap(mangSV[i], mangSV[j]);
        }
    }

    cout << "+----------------------------+\n";
    for (int i = 0; i < sv; i++)
    {
        cout << "Name: " << mangSV[i].tenSV << endl;
        cout << "Mark: " << mangSV[i].diem << endl;
        checkDiem(mangSV[i].diem);
        cout << "+----------------------------+\n";
    }

    delete[] mangSV;
}

int main()
{
    int luachon;
    cout << "++----------------------------MENU----------------------------++\n";
    cout << "|1 : Kiem tra so nguyen                                        |\n";
    cout << "|2 : Tim UCLN & BCNN                                            |\n";
    cout << "|3 : Tinh tien karaoke                                         |\n";
    cout << "|4 : Tinh tien dien                                            |\n";
    cout << "|5 : Doi tien                                                  |\n";
    cout << "|6 : Tinh lai suat                                             |\n";
    cout << "|7 : Vay tien mua xe                                           |\n";
    cout << "|8 : Sap xep sinh vien                                         |\n";
    cout << "|9 : Game FPOLY-LOTT                                           |\n";
    cout << "|10: Tinh toan phan so                                         |\n";
    cout << "++------------------------------------------------------------++\n";
    cout << "Nhap lua chon: ";

    cin >> luachon;

    switch (luachon)
    {
    case 1:
    {
        int x;
        cout << "Nhap X: ";
        cin >> x;
        kt_songuyen(x);
        kt_songuyento(x);
        kt_sochinhphuong(x);
        break;
    }
    case 2:
    {
        int x, y;
        cout << "Nhap X: ";
        cin >> x;
        cout << "Nhap Y: ";
        cin >> y;
        tim_uoc(x, y);
        tim_boi(x, y);
        break;
    }
    case 3: karaoke(); break;
    case 4:
    {
        int kwh;
        cout << "Nhap so kWh: ";
        cin >> kwh;
        tinhtiendien(kwh);
        break;
    }
    case 5: doitien(); break;
    case 6: tinhlaisuat(); break;
    case 7: vaytien(); break;
    case 8: sapxepSV(); break;

    default:
        cout << "Lua chon khong hop le!\n";
        break;
    }
    return 0;
}
