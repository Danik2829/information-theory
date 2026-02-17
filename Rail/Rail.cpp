//---------------------------------------------------------------------------
#include <fstream>
#include <vcl.h>
#pragma hdrstop

#include "Rail.h"
#include <String.h>
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRail *FormRail;
//---------------------------------------------------------------------------
__fastcall TFormRail::TFormRail(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormRail::ClearButtonClick(TObject *Sender)
{
	EPlainText->Text = "";
}
//---------------------------------------------------------------------------
bool isEnglishLetter(wchar_t c)
{
	return ((c >= L'a' && c <= L'z') || (c >= L'A' && c <= L'Z'));
}

String __fastcall TFormRail::EncipherString(String str)
{
    int key = StrToInt(Key->Items->Strings[Key->ItemIndex]);

    String letters;
    std::vector<int> positions;

    for (int i = 1; i <= str.Length(); i++)
    {
        wchar_t ch = str[i];
        if (isEnglishLetter(ch))
        {
            letters += ch;
            positions.push_back(i);
        }
    }

    int lettersLen = letters.Length();
    std::vector<String> rows(key);

    int row = 0, step = 1;

    for (int i = 1; i <= lettersLen; i++)
    {
        rows[row] += letters[i];

        if (row == 0)
            step = 1;
        else if (row == key - 1)
            step = -1;

        row += step;
    }

    String encryptedLetters;
    for (auto &s : rows)
        encryptedLetters += s;

    String result = str;
    int idx = 1;
    for (int pos : positions)
    {
        result[pos] = encryptedLetters[idx];
        idx++;
    }

    return result;
}

void __fastcall TFormRail::EncipherButtonClick(TObject *Sender)
{
	ECiphertext->Text = EncipherString(EPlainText->Text);
}

String __fastcall TFormRail::DecipherString(String cipher)
{
    int key = StrToInt(Key->Items->Strings[Key->ItemIndex]);

    String letters;
    std::vector<int> positions;

    for (int i = 1; i <= cipher.Length(); i++)
    {
        wchar_t ch = cipher[i];
        if (isEnglishLetter(ch))
        {
            letters += ch;
            positions.push_back(i);
        }
    }

    int len = letters.Length();

    std::vector<int> rowLengths(key, 0);
    int row = 0, step = 1;

    for (int i = 0; i < len; i++)
    {
        rowLengths[row]++;

        if (row == 0)
            step = 1;
        else if (row == key - 1)
            step = -1;

        row += step;
    }

    std::vector<String> rows(key);
    int pos = 1;

    for (int i = 0; i < key; i++)
    {
        int cnt = rowLengths[i];
        if (cnt > 0)
        {
            rows[i] = letters.SubString(pos, cnt);
            pos += cnt;
        }
    }

    String decryptedLetters;
    std::vector<int> currentIndex(key, 1);
    row = 0;
	step = 1;
    for (int i = 0; i < len; i++)
    {
        decryptedLetters += rows[row][currentIndex[row]];
        currentIndex[row]++;

        if (row == 0)
            step = 1;
        else if (row == key - 1)
            step = -1;

        row += step;
    }

    String result = cipher;
    int idx = 1;
    for (int posi : positions)
    {
        result[posi] = decryptedLetters[idx];
        idx++;
    }

    return result;
}

//---------------------------------------------------------------------------
void __fastcall TFormRail::DecipherButtonClick(TObject *Sender)
{
    ECiphertext->Text = DecipherString(EPlainText->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormRail::EPlainTextChange(TObject *Sender)
{
	if (EPlainText->Text != "") {
		EncipherButton->Enabled = true;
		DecipherButton->Enabled = true;
	} else {
		EncipherButton->Enabled = false;
		DecipherButton->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormRail::N2Click(TObject *Sender)
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

void __fastcall TFormRail::N3Click(TObject *Sender)
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

