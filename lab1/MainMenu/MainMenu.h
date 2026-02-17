//---------------------------------------------------------------------------

#ifndef MainMenuH
#define MainMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Rail.h"
#include "Vigenere.h"
//---------------------------------------------------------------------------
class TMainMenuForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *LDescription;
	TButton *RailButton;
	TButton *VingerButton;
	void __fastcall RailButtonClick(TObject *Sender);
	void __fastcall VingerButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainMenuForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainMenuForm *MainMenuForm;
//---------------------------------------------------------------------------
#endif
