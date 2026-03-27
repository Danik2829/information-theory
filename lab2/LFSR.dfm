object MainForm: TMainForm
  Left = 0
  Top = 0
  Hint = '0101 1101 ...'
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1051#1072#1073#1086#1088#1072#1090#1086#1088#1085#1072#1103' '#1088#1072#1073#1086#1090#1072' '#1058#1048' '#8470'2'
  ClientHeight = 745
  ClientWidth = 1117
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesktopCenter
  ShowHint = True
  TextHeight = 15
  object Label1: TLabel
    Left = 368
    Top = 40
    Width = 405
    Height = 33
    Caption = #1055#1054#1058#1054#1050#1054#1042#1054#1045' '#1064#1048#1060#1056#1054#1042#1040#1053#1048#1045
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = 'SimSun-ExtG'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 112
    Width = 575
    Height = 23
    Caption = 
      #1042#1074#1077#1076#1080#1090#1077' '#1085#1072#1095#1072#1083#1100#1085#1086#1077' '#1089#1086#1089#1090#1086#1103#1085#1080#1077' '#1076#1083#1103' LFSR('#1076#1083#1080#1085#1072' '#1076#1086#1083#1078#1085#1072' '#1073#1099#1090#1100' 33 '#1089#1080#1084#1074#1086#1083 +
      #1072'):'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 104
    Top = 192
    Width = 146
    Height = 28
    Alignment = taCenter
    Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1092#1072#1081#1083
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 533
    Top = 192
    Width = 50
    Height = 28
    Alignment = taCenter
    Caption = #1050#1083#1102#1095
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 840
    Top = 192
    Width = 210
    Height = 28
    Alignment = taCenter
    Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1085#1085#1099#1081' '#1092#1072#1081#1083
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 8
    Top = 141
    Width = 1101
    Height = 28
    TabOrder = 0
  end
  object BtnEncipher: TButton
    Left = 614
    Top = 104
    Width = 159
    Height = 31
    Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1090#1100
    TabOrder = 1
    OnClick = BtnEncipherClick
  end
  object Memo2: TMemo
    Left = 381
    Top = 232
    Width = 357
    Height = 505
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Memo3: TMemo
    Left = 8
    Top = 232
    Width = 357
    Height = 505
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object Memo4: TMemo
    Left = 752
    Top = 232
    Width = 357
    Height = 505
    ScrollBars = ssVertical
    TabOrder = 4
  end
  object MainMenu1: TMainMenu
    OwnerDraw = True
    Left = 1040
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
    Left = 1040
    Top = 48
  end
  object SaveDialog1: TSaveDialog
    Left = 1040
    Top = 88
  end
end
