//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LFSR.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm* MainForm;

//---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {}

//---------------------------------------------------------------------------

int64_t fileSize = 0;
std::vector<char> key;
std::vector<char> PlainText;
std::vector<char> CipherText;

//---------------------------------------------------------------------------

std::vector<char> generateKey(int len, int* arr)
{
    std::vector<char> keyReg;
    keyReg.resize(len);

    for (int i = 0; i < 33; i++)
        keyReg[i] = arr[i];

    for (int i = 33; i < len; i++)
        keyReg[i] = keyReg[i - 33] ^ keyReg[i - 13];

    return keyReg;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnEncipherClick(TObject* Sender)
{
    int arr[33];
    int index = 0;
    bool isOne = false;

    String text = Memo1->Text;

    for (int i = 1; i <= text.Length(); i++) {
        if (text[i] == '0' || text[i] == '1') {
            if (index < 33) {
                if (text[i] == '1')
                    isOne = true;

                arr[index++] = text[i] - '0';
            }
        }
    }

    if (index != 33 || !isOne) {
        Application->MessageBox(
            L"Ошибка: нужно 33 бита и хотя бы одна 1", L"Ошибка", MB_OK);
        return;
    }

    key = generateKey(fileSize * 8, arr);

    String out = "";
    for (size_t i = 0; i < key.size(); i++) {
        out += IntToStr(key[i]);
        if ((i + 1) % 8 == 0)
            out += " ";
    }
    Memo2->Lines->Text = out;

    CipherText.resize(fileSize * 8);

    out = "";

    for (size_t i = 0; i < key.size(); i++) {
        CipherText[i] = key[i] ^ PlainText[i];

        out += IntToStr(CipherText[i]);

        if ((i + 1) % 8 == 0)
            out += " ";
    }

    Memo4->Lines->Text = out;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::N2Click(TObject* Sender)
{
    if (!OpenDialog1->Execute())
        return;

    Memo3->Clear();

    TFileStream* fs =
        new TFileStream(OpenDialog1->FileName, fmOpenRead | fmShareDenyWrite);

    try {
        fileSize = fs->Size;

        if (fileSize == 0) {
            Memo3->Lines->Add("Файл пуст.");
            return;
        }

        unsigned char* buffer = new unsigned char[fileSize];

        __try
        {
            fs->Read(buffer, fileSize);

            PlainText.resize(fileSize * 8);

            String out = "";

            for (int64_t i = 0; i < fileSize; ++i) {
                unsigned char b = buffer[i];

                for (int bit = 7; bit >= 0; --bit) {
                    int value = ((b >> bit) & 1);

                    PlainText[i * 8 + (7 - bit)] = value;

                    out += value ? '1' : '0';
                }

                out += " ";
            }

            Memo3->Lines->Text = out;
        } __finally
        {
            delete[] buffer;
        }
    } __finally
    {
		delete fs;
	}
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::N3Click(TObject* Sender)
{
    if (CipherText.empty()) {
        ShowMessage("Нет данных для сохранения.");
        return;
    }

    if (!SaveDialog1->Execute())
        return;

    try {
        TFileStream* fs = new TFileStream(SaveDialog1->FileName, fmCreate);

        unsigned char byte = 0;
        int bitIndex = 0;

        for (size_t i = 0; i < CipherText.size(); i++) {
            if (CipherText[i] == 1)
                byte |= (1 << (7 - bitIndex));

            bitIndex++;
            if (bitIndex == 8) {
				fs->Write(&byte, 1);
                byte = 0;
                bitIndex = 0;
            }
        }
        if (bitIndex > 0)
            fs->Write(&byte, 1);
        delete fs;
        ShowMessage("Сохранено.");
    } catch (...) {
        ShowMessage("Ошибка при сохранении файла.");
    }
}

