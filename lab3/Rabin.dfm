object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1050#1088#1080#1087#1090#1086#1089#1080#1089#1090#1077#1084#1072' '#1056#1072#1073#1080#1085#1072
  ClientHeight = 605
  ClientWidth = 544
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 32
    Width = 109
    Height = 31
    Caption = #1042#1074#1077#1076#1080#1090#1077' p:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 88
    Width = 109
    Height = 31
    Caption = #1042#1074#1077#1076#1080#1090#1077' q:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 144
    Width = 109
    Height = 31
    Caption = #1042#1074#1077#1076#1080#1090#1077' b:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 24
    Top = 200
    Width = 135
    Height = 28
    Caption = #1042#1093#1086#1076#1085#1086#1081' '#1092#1072#1081#1083':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 24
    Top = 234
    Width = 185
    Height = 28
    Caption = #1060#1072#1081#1083' '#1089' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1084':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 139
    Top = 42
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 139
    Top = 98
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 139
    Top = 154
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object BtnEncrypt: TButton
    Left = 24
    Top = 280
    Width = 153
    Height = 25
    Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1090#1100
    Enabled = False
    TabOrder = 3
    OnClick = BtnEncryptClick
  end
  object BtnDecrypt: TButton
    Left = 240
    Top = 280
    Width = 153
    Height = 25
    Caption = #1056#1072#1089#1096#1080#1092#1088#1086#1074#1072#1090#1100
    Enabled = False
    TabOrder = 4
    OnClick = BtnDecryptClick
  end
  object Memo1: TMemo
    Left = 24
    Top = 328
    Width = 481
    Height = 241
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object Edit4: TEdit
    Left = 176
    Top = 208
    Width = 233
    Height = 23
    TabOrder = 6
    OnChange = Edit4Change
  end
  object Edit5: TEdit
    Left = 215
    Top = 237
    Width = 194
    Height = 23
    TabOrder = 7
    OnChange = Edit5Change
  end
  object Button1: TButton
    Left = 415
    Top = 206
    Width = 75
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100
    TabOrder = 8
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 415
    Top = 237
    Width = 75
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100
    TabOrder = 9
    OnClick = Button2Click
  end
  object OpenDialog1: TOpenDialog
    Left = 458
    Top = 80
  end
  object SaveDialog1: TSaveDialog
    Left = 458
    Top = 120
  end
end
