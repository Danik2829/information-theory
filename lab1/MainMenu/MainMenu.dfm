object MainMenuForm: TMainMenuForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'lab 1 TI'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  TextHeight = 15
  object LDescription: TLabel
    Left = 40
    Top = 40
    Width = 553
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = #1055#1077#1088#1077#1089#1090#1072#1085#1086#1074#1086#1095#1085#1099#1077' '#1080' '#1087#1086#1076#1089#1090#1072#1085#1086#1074#1086#1095#1085#1099#1077' '#1084#1077#1090#1086#1076#1099' '#1096#1080#1092#1088#1086#1074#1072#1085#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object RailButton: TButton
    Left = 56
    Top = 232
    Width = 217
    Height = 81
    Caption = #1052#1077#1090#1086#1076' "'#1046#1077#1083#1077#1079#1085#1086#1076#1086#1088#1086#1078#1085#1072#1103' '#1080#1079#1075#1086#1088#1086#1076#1100'"'
    TabOrder = 0
    OnClick = RailButtonClick
  end
  object VingerButton: TButton
    Left = 352
    Top = 232
    Width = 217
    Height = 81
    Caption = 'A'#1083#1075#1086#1088#1080#1090#1084' '#1042#1080#1078#1077#1085#1077#1088#1072
    TabOrder = 1
    OnClick = VingerButtonClick
  end
end
