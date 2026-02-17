object FormRail: TFormRail
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = '"'#1046#1077#1083#1077#1079#1085#1086#1076#1086#1088#1086#1078#1085#1072#1103' '#1080#1079#1075#1086#1088#1086#1076#1100'"'
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
    Left = 104
    Top = 24
    Width = 417
    Height = 41
    AutoSize = False
    Caption = '"'#1046#1077#1083#1077#1079#1085#1086#1076#1086#1088#1086#1078#1085#1072#1103' '#1080#1079#1075#1086#1088#1086#1076#1100'"'#13#10#1040#1085#1075#1083#1080#1081#1089#1082#1080#1081' '#1072#1083#1092#1072#1074#1080#1090
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Yu Gothic'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 88
    Width = 49
    Height = 25
    AutoSize = False
    Caption = #1050#1083#1102#1095':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 152
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
    Left = 24
    Top = 232
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
  object EPlainText: TEdit
    Left = 24
    Top = 181
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
  object ECiphertext: TEdit
    Left = 24
    Top = 261
    Width = 577
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
  end
  object EncipherButton: TButton
    Left = 79
    Top = 328
    Width = 161
    Height = 57
    Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1090#1100
    Enabled = False
    TabOrder = 2
    OnClick = EncipherButtonClick
  end
  object DecipherButton: TButton
    Left = 360
    Top = 328
    Width = 161
    Height = 57
    Caption = #1044#1077#1096#1080#1092#1088#1086#1074#1072#1090#1100
    Enabled = False
    TabOrder = 3
    OnClick = DecipherButtonClick
  end
  object ClearButton: TButton
    Left = 176
    Top = 150
    Width = 112
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 4
    OnClick = ClearButtonClick
  end
  object Key: TComboBox
    Left = 79
    Top = 88
    Width = 145
    Height = 23
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 5
    Text = '2'
    Items.Strings = (
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15')
  end
  object MainMenu1: TMainMenu
    OwnerDraw = True
    Left = 568
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
    Left = 568
    Top = 72
  end
  object SaveDialog1: TSaveDialog
    Left = 568
    Top = 128
  end
end
