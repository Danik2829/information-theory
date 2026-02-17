//---------------------------------------------------------------------------

#ifndef VigenereH
#define VigenereH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TVigenerForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label3;
	TEdit *EPlainText;
	TButton *ClearButton;
	TLabel *Label4;
	TEdit *ECiphertext;
	TLabel *Label2;
	TEdit *EKey;
	TButton *ClearKeyButton;
	TButton *EncipherButton;
	TButton *DecipherButton;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	void __fastcall ClearButtonClick(TObject *Sender);
	void __fastcall EncipherButtonClick(TObject *Sender);
	void __fastcall ClearKeyButtonClick(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall EPlainTextChange(TObject *Sender);
	void __fastcall EKeyChange(TObject *Sender);
	void __fastcall DecipherButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TVigenerForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVigenerForm *VigenerForm;
//---------------------------------------------------------------------------
#endif
