//---------------------------------------------------------------------------

#ifndef RabinH
#define RabinH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *BtnEncrypt;
	TButton *BtnDecrypt;
	TMemo *Memo1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit4;
	TEdit *Edit5;
	TButton *Button1;
	TButton *Button2;
	void __fastcall BtnEncryptClick(TObject *Sender);
	void __fastcall BtnDecryptClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Edit4Change(TObject *Sender);
	void __fastcall Edit5Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
