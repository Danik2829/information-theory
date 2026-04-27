//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rabin.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

#include <System.SysUtils.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;
//---------------------------------------------------------------------------

// ===================== МАТЕМАТИКА =====================

long long modPow(long long a, long long e, long long mod)
{
    long long res = 1;
    a %= mod;

    while (e > 0)
    {
        if (e & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;
        e >>= 1;
    }
    return res;
}

long long egcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long d = egcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

long long crt(long long ap, long long aq, long long p, long long q)
{
    long long yp, yq;
    egcd(p, q, yp, yq);

    long long n = p * q;
    long long x = (ap * yq * q + aq * yp * p) % n;

    if (x < 0)
        x += n;

    return x;
}

long long rabinEncrypt(long long m, long long b, long long n)
{
    return (m * (m + b)) % n;
}

std::vector<long long> rabinDecrypt(long long c, long long p, long long q, long long b)
{
    long long n = p * q;

    long long D = (b * b + 4 * c) % n;

    long long mp = modPow(D, (p + 1) / 4, p);
    long long mq = modPow(D, (q + 1) / 4, q);

    long long d1 = crt(mp, mq, p, q);
    long long d2 = crt(mp, (q - mq) % q, p, q);
    long long d3 = crt((p - mp) % p, mq, p, q);
    long long d4 = crt((p - mp) % p, (q - mq) % q, p, q);

    std::vector<long long> d = { d1, d2, d3, d4 };
    std::vector<long long> m;

    for (int i = 0; i < 4; i++)
    {
        long long temp = (d[i] - b) % n;
        if (temp < 0)
            temp += n;

        if (temp % 2 != 0)
            temp += n;

        long long mi = (temp / 2) % n;
        m.push_back(mi);
    }

    std::sort(m.begin(), m.end());
    m.erase(std::unique(m.begin(), m.end()), m.end());

    return m;
}

// ===================== ПРОСТОТА =====================

bool isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

// ===================== ПЕРВЫЕ 10 ПРОСТЫХ (mod 4 = 3) =====================

String getFirst10PrimesMod4eq3()
{
    String s = "";
    int count = 0;

    for (int x = 2; count < 10; x++)
    {
        if (isPrime(x) && x % 4 == 3)
        {
            s += IntToStr(x) + " ";
            count++;
        }
    }

    return s;
}

// ===================== ПРОВЕРКА КЛЮЧЕЙ =====================

bool getKeys(TEdit* Edit1, TEdit* Edit2, TEdit* Edit3,
             long long &p, long long &q, long long &b,
             String &errorMsg)
{
    int n;

    // ---- p ----
    if (!TryStrToInt(Edit1->Text, n))
    {
        errorMsg = "Ошибка: p должно быть целым числом";
        return false;
    }

    if (!isPrime(n))
    {
        errorMsg = "Ошибка: p не простое число";
        return false;
    }

    if (n % 4 != 3)
    {
        errorMsg = "Ошибка: p должно удовлетворять p mod 4 = 3\n\n"
                   "Примеры подходящих простых чисел:\n" +
                   getFirst10PrimesMod4eq3();
        return false;
    }

    p = n;

    // ---- q ----
    if (!TryStrToInt(Edit2->Text, n))
    {
        errorMsg = "Ошибка: q должно быть целым числом";
        return false;
    }

    if (!isPrime(n))
    {
        errorMsg = "Ошибка: q не простое число";
        return false;
    }

    if (n % 4 != 3)
    {
        errorMsg = "Ошибка: q должно удовлетворять q mod 4 = 3\n\n"
                   "Примеры подходящих простых чисел:\n" +
                   getFirst10PrimesMod4eq3();
        return false;
    }

    q = n;

    if (p == q)
    {
        errorMsg = "Ошибка: p и q должны быть разными";
        return false;
    }

    long long mod = p * q;

    if (mod <= 256)
    {
        errorMsg = "Ошибка: n = p*q должно быть > 256";
        return false;
    }

    // ---- b ----
    if (!TryStrToInt(Edit3->Text, n))
    {
        errorMsg = "Ошибка: b должно быть целым числом";
        return false;
    }

    b = n;

    if (b <= 0)
    {
        errorMsg = "Ошибка: b должно быть больше 0";
        return false;
    }

    if (b >= mod)
    {
        errorMsg = "Ошибка: b должно быть меньше n = p*q";
        return false;
    }

    errorMsg = "";
    return true;
}

// ===================== КОНСТРУКТОР =====================

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

// ===================== ЗНАЧЕНИЯ ПО УМОЛЧАНИЮ =====================

void __fastcall TForm1::FormCreate(TObject* Sender)
{
    Edit1->Text = "5003";
    Edit2->Text = "5227";
    Edit3->Text = "1234";

    Memo1->Clear();
    Memo1->Lines->Add("Готово. Выберите файл и нажмите Encrypt.");
}

// ===================== ШИФРОВАНИЕ (ФАЙЛ -> ФАЙЛ + MEMO) =====================

void encryptFileToFileAndMemo(const String &inputFile, const String &outputFile,
                              long long p, long long q, long long b, TMemo* memo)
{
    long long n = p * q;

    std::ifstream fin(AnsiString(inputFile).c_str(), std::ios::binary);
    if (!fin.is_open())
        throw Exception("Не удалось открыть входной файл");

    std::ofstream fout(AnsiString(outputFile).c_str(), std::ios::binary);
    if (!fout.is_open())
        throw Exception("Не удалось создать выходной файл");

    memo->Clear();
    String line = "";

    unsigned char byte;

    while (fin.read((char*)&byte, 1))
    {
        long long m = (long long)byte;
        long long c = rabinEncrypt(m, b, n);

        fout.write((char*)&c, sizeof(c));

        line += IntToStr(c) + " ";
        if (line.Length() > 200)
        {
            memo->Lines->Add(line);
            line = "";
        }
    }

    if (line != "")
        memo->Lines->Add(line);

    fin.close();
    fout.close();
}

// ===================== РАСШИФРОВАНИЕ (ФАЙЛ -> ФАЙЛ) =====================

void decryptFileToFileBinary(const String &inputFile, const String &outputFile,
                             long long p, long long q, long long b)
{
    std::ifstream fin(AnsiString(inputFile).c_str(), std::ios::binary);
    if (!fin.is_open())
        throw Exception("Не удалось открыть файл с шифротекстом");

    std::ofstream fout(AnsiString(outputFile).c_str(), std::ios::binary);
    if (!fout.is_open())
        throw Exception("Не удалось создать выходной файл");

    long long c;
    long long index = 0;

    while (fin.read((char*)&c, sizeof(c)))
    {
        auto roots = rabinDecrypt(c, p, q, b);

        std::vector<long long> candidates;

        for (auto r : roots)
        {
            if (r >= 0 && r < 256)
                candidates.push_back(r);
        }

        if (candidates.size() != 1)
        {
            fin.close();
            fout.close();

            throw Exception("Нельзя однозначно расшифровать байт №" +
                            IntToStr((int)index) +
                            "\nКоличество корней <256: " +
                            IntToStr((int)candidates.size()));
        }

        unsigned char byte = (unsigned char)candidates[0];
        fout.write((char*)&byte, 1);

        index++;
    }

    fin.close();
    fout.close();
}

// ===================== КНОПКА ШИФРОВАНИЯ =====================

void __fastcall TForm1::BtnEncryptClick(TObject* Sender)
{
    long long p, q, b;
    String err;

    if (!getKeys(Edit1, Edit2, Edit3, p, q, b, err))
    {
        ShowMessage(err);
        return;
    }

    if (Edit4->Text.Trim().IsEmpty() || Edit5->Text.Trim().IsEmpty())
    {
        ShowMessage("Выберите входной и выходной файл");
        return;
    }

    if (Edit4->Text == Edit5->Text)
    {
        ShowMessage("Ошибка: входной и выходной файл не должны совпадать!");
        return;
    }

    try
    {
        encryptFileToFileAndMemo(Edit4->Text, Edit5->Text, p, q, b, Memo1);
        ShowMessage("Файл зашифрован. Шифртекст выведен в Memo и сохранён в:\n" + Edit5->Text);
    }
    catch (Exception &e)
    {
        ShowMessage(e.Message);
    }
}

// ===================== КНОПКА РАСШИФРОВКИ =====================

void __fastcall TForm1::BtnDecryptClick(TObject* Sender)
{
    long long p, q, b;
    String err;

    if (!getKeys(Edit1, Edit2, Edit3, p, q, b, err))
    {
        ShowMessage(err);
        return;
    }

    if (Edit4->Text.Trim().IsEmpty() || Edit5->Text.Trim().IsEmpty())
    {
        ShowMessage("Выберите входной и выходной файл");
        return;
    }

    if (Edit4->Text == Edit5->Text)
    {
        ShowMessage("Ошибка: входной и выходной файл не должны совпадать!");
        return;
    }

    try
    {
        decryptFileToFileBinary(Edit4->Text, Edit5->Text, p, q, b);
        ShowMessage("Файл расшифрован и сохранён в:\n" + Edit5->Text);
    }
    catch (Exception &e)
    {
        ShowMessage(e.Message);
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Change(TObject* Sender)
{
    BtnEncrypt->Enabled = (!Edit4->Text.Trim().IsEmpty() && !Edit5->Text.Trim().IsEmpty());
    BtnDecrypt->Enabled = BtnEncrypt->Enabled;
}

void __fastcall TForm1::Edit5Change(TObject* Sender)
{
    BtnEncrypt->Enabled = (!Edit4->Text.Trim().IsEmpty() && !Edit5->Text.Trim().IsEmpty());
    BtnDecrypt->Enabled = BtnEncrypt->Enabled;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject* Sender)
{
    if (OpenDialog1->Execute())
        Edit4->Text = OpenDialog1->FileName;
}

void __fastcall TForm1::Button2Click(TObject* Sender)
{
    if (SaveDialog1->Execute())
        Edit5->Text = SaveDialog1->FileName;
}

//---------------------------------------------------------------------------
