//---------------------------------------------------------------------------

#ifndef RailH
#define RailH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormRail : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *EPlainText;
	TLabel *Label4;
	TEdit *ECiphertext;
	TButton *EncipherButton;
	TButton *DecipherButton;
	TButton *ClearButton;
	TComboBox *Key;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	void __fastcall ClearButtonClick(TObject *Sender);
	String __fastcall EncipherString(String str);
    String __fastcall DecipherString(String cipher);
	void __fastcall EncipherButtonClick(TObject *Sender);
	void __fastcall DecipherButtonClick(TObject *Sender);
	void __fastcall EPlainTextChange(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TFormRail(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRail *FormRail;
//---------------------------------------------------------------------------
#endif
