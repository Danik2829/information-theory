//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Vigenere.h"
#include <String.h>
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVigenerForm *VigenerForm;
//---------------------------------------------------------------------------
__fastcall TVigenerForm::TVigenerForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TVigenerForm::ClearButtonClick(TObject *Sender)
{
    EPlainText->Text = "";
}
//---------------------------------------------------------------------------

bool isRussianLetter(wchar_t c)
{
	return ((c >= L'а' && c <= L'я') || c == L'ё');
}

int rusIndex(wchar_t c)
{
	if (c == L'ё') return 6;
	if (c > L'е')
		return c - L'а' + 1;
    return c - L'а';
}

wchar_t rusLetter(int i)
{
	if (i == 6) return L'ё';
	if (i > 6)
		return L'а' + i - 1;
	return L'а' + i;
}

String __fastcall encipherText(String plainText, String key)
{
    plainText = plainText.LowerCase();
    key = key.LowerCase();

    String cipherText = "";

    int lenKey = key.Length();
    int index = 1;

	for (int i = 1; i <= plainText.Length(); i++){
		wchar_t p = plainText[i];
		if (isRussianLetter(p)){
			wchar_t k = key[index];
            while (!isRussianLetter(k))
            {
                index++;
                if (index > lenKey) index = 1;
                k = key[index];
			}
            int pPos = rusIndex(p);
			int kPos = rusIndex(k);
            wchar_t c = rusLetter((pPos + kPos) % 33);
			cipherText += c;
            index++;
            if (index > lenKey) index = 1;
        }
		else{
			cipherText += p;
		}
	}
	return cipherText;
}

String __fastcall decipherText(String cipherText, String key)
{
    cipherText = cipherText.LowerCase();
	key = key.LowerCase();
    String plainText = "";

    int lenKey = key.Length();
	int index = 1;
	for (int i = 1; i <= cipherText.Length(); i++){
		wchar_t c = cipherText[i];
		if (isRussianLetter(c)){
			wchar_t k = key[index];
			while (!isRussianLetter(k)){
                index++;
                if (index > lenKey) index = 1;
                k = key[index];
			}
            int cPos = rusIndex(c);
			int kPos = rusIndex(k);
            wchar_t p = rusLetter((cPos - kPos + 33) % 33);
			plainText += p;
            index++;
            if (index > lenKey) index = 1;
		}else{
            plainText += c;
        }
    }

    return plainText;
}



void __fastcall TVigenerForm::EncipherButtonClick(TObject *Sender)
{
	ECiphertext->Text = encipherText(EPlainText->Text, EKey->Text);
}
//---------------------------------------------------------------------------
void __fastcall TVigenerForm::ClearKeyButtonClick(TObject *Sender)
{
     EKey->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TVigenerForm::N2Click(TObject *Sender)
{
    OpenDialog1->Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
    if (!OpenDialog1->Execute()) return;

    TStringList *list = new TStringList;
    try
	{
		list->LoadFromFile(OpenDialog1->FileName, TEncoding::UTF8);
        EPlainText->Text = list->Text;
    }
    __finally
    {
        delete list;
    }
}
//---------------------------------------------------------------------------

void __fastcall TVigenerForm::N3Click(TObject *Sender)
{
    SaveDialog1->Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";

    if (!SaveDialog1->Execute()) return;

    TStringList *list = new TStringList;
    try
    {
        list->Text = ECiphertext->Text;
		list->SaveToFile(SaveDialog1->FileName, TEncoding::UTF8);
	}
    __finally
    {
        delete list;
    }
}

//---------------------------------------------------------------------------

void __fastcall TVigenerForm::EPlainTextChange(TObject *Sender)
{
	if (EPlainText->Text != "" && EKey->Text != "") {
		EncipherButton->Enabled = true;
		DecipherButton->Enabled = true;
	} else {
		EncipherButton->Enabled = false;
		DecipherButton->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TVigenerForm::EKeyChange(TObject *Sender)
{
    if (EPlainText->Text != "" && EKey->Text != "") {
		EncipherButton->Enabled = true;
		DecipherButton->Enabled = true;
	} else {
		EncipherButton->Enabled = false;
		DecipherButton->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TVigenerForm::DecipherButtonClick(TObject *Sender)
{
	ECiphertext->Text = decipherText(EPlainText->Text, EKey->Text);
}
//---------------------------------------------------------------------------

