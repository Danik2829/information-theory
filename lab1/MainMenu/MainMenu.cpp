//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainMenu.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainMenuForm *MainMenuForm;
//---------------------------------------------------------------------------
__fastcall TMainMenuForm::TMainMenuForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TMainMenuForm::RailButtonClick(TObject *Sender)
{
	FormRail->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainMenuForm::VingerButtonClick(TObject *Sender)
{
	VigenerForm->ShowModal();
}
//---------------------------------------------------------------------------

