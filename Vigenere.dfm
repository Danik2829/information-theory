object VigenerForm: TVigenerForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1064#1080#1092#1088' '#1042#1080#1078#1077#1085#1077#1088#1072
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesktopCenter
  TextHeight = 15
  object Label1: TLabel
    Left = 96
    Top = 24
    Width = 465
    Height = 41
    AutoSize = False
    Caption = #1040#1083#1075#1086#1088#1080#1090#1084' '#1042#1080#1078#1077#1085#1077#1088#1072', '#1087#1088#1103#1084#1086#1081' '#1082#1083#1102#1095#13#10#1056#1091#1089#1089#1082#1080#1081' '#1072#1083#1092#1072#1074#1080#1090
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Yu Gothic'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 16
    Top = 96
    Width = 128
    Height = 23
    Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 16
    Top = 272
    Width = 181
    Height = 23
    Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1085#1085#1099#1081' '#1090#1077#1082#1089't:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 168
    Width = 47
    Height = 23
    Caption = #1050#1083#1102#1095':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object EPlainText: TEdit
    Left = 16
    Top = 125
    Width = 577
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnChange = EPlainTextChange
  end
  object ClearButton: TButton
    Left = 168
    Top = 94
    Width = 112
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 1
    OnClick = ClearButtonClick
  end
  object ECiphertext: TEdit
    Left = 16
    Top = 301
    Width = 577
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
  end
  object EKey: TEdit
    Left = 16
    Top = 197
    Width = 577
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnChange = EKeyChange
  end
  object ClearKeyButton: TButton
    Left = 85
    Top = 166
    Width = 112
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 4
    OnClick = ClearKeyButtonClick
  end
  object EncipherButton: TButton
    Left = 85
    Top = 360
    Width = 161
    Height = 57
    Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1090#1100
    Enabled = False
    TabOrder = 5
    OnClick = EncipherButtonClick
  end
  object DecipherButton: TButton
    Left = 366
    Top = 360
    Width = 161
    Height = 57
    Caption = #1044#1077#1096#1080#1092#1088#1086#1074#1072#1090#1100
    Enabled = False
    TabOrder = 6
    OnClick = DecipherButtonClick
  end
  object MainMenu1: TMainMenu
    OwnerDraw = True
    Left = 584
    Top = 24
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        OnClick = N3Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 584
    Top = 72
  end
  object SaveDialog1: TSaveDialog
    Left = 584
    Top = 112
  end
end
