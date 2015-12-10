#include<afxwin.h>
#include<afxres.h>
#include"resource.h"


class CMainWin:public CFrameWnd
{
public:
	CMainWin();

	afx_msg void OnDialog();
	afx_msg void OnExit();
	afx_msg void OnHelp();

	DECLARE_MESSAGE_MAP()
};

class CApp:public CWinApp
{
public:
	BOOL InitInstance();
};

class CSampleDialog:public CDialog
{
	//CProgressCtrl m_Prog;
	int m_ProgPos;
public:
	CSampleDialog(LPCSTR DialogName, CWnd *Owner):
	  CDialog(DialogName, Owner){}

	  BOOL OnInitDialog();

	  afx_msg void ProcessButtonPress();
	  afx_msg void OnRed();
	  afx_msg void OnGreen();
	  afx_msg void OnCancel();
	  afx_msg void OnRB1();
	  afx_msg void OnRB2();
	  afx_msg void OnRB3();
	  afx_msg void OnRB4();
	  afx_msg void OnRB5();
	  afx_msg void OnRB6();
	  afx_msg void OnCB1();
	  afx_msg void OnCB2();
	  afx_msg void OnCB3();
	  void ProcessButtonPress(char Letter);
	  void RefreshScoreDisplay()	
	  //afx_msg void OnProgress();


	  DECLARE_MESSAGE_MAP();
};




CMainWin::CMainWin()
{
	Create(NULL,"Demonstrate dolog boxle lksdjf",WS_OVERLAPPEDWINDOW, rectDefault,NULL,MAKEINTRESOURCE(IDR_MENU1));
	/*
	INITCOMMONCONTROLSEX initCtrls;
	
	initCtrls.dwSize=sizeof(intiCtrls);
	initCtrls.dwICC=ICC_PRGRESS_CLASS;
	InitCommonControlEx(&initCtrls);
*/
/*	if(!LoadAccelTable("DialogMenu"))
		MessageBox("cant load accelerators","Errror");*/
}

BOOL CApp::InitInstance()
{

	m_pMainWnd=new CMainWin;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWin,CFrameWnd)
ON_COMMAND(ID_M1,OnDialog)
ON_COMMAND(ID_EXIT,OnExit)
ON_COMMAND(ID_HELP,OnHelp)

END_MESSAGE_MAP()

afx_msg void CMainWin::OnDialog()
{
	CSampleDialog diagOb(MAKEINTRESOURCE(IDD_DIALOG1),this);

	diagOb.DoModal();
}

afx_msg void CMainWin::OnExit()
{
	int response;

	response=MessageBox("Quit the Program?","Exit",MB_YESNO);

	if(response==IDYES)
		SendMessage(WM_CLOSE);
}

afx_msg void CMainWin::OnHelp()
{
	
	MessageBox("Dialog Demo","Help");
}

BEGIN_MESSAGE_MAP(CSampleDialog,CDialog)
ON_COMMAND(IDC_BUTTON1,OnRed)
ON_COMMAND(IDC_BUTTON2,OnGreen)
ON_COMMAND(IDC_RADIO1,OnRB1)
ON_COMMAND(IDC_RADIO2,OnRB2)
ON_COMMAND(IDC_RADIO3,OnRB3)
ON_COMMAND(IDC_RADIO4,OnRB4)
ON_COMMAND(IDC_RADIO5,OnRB5)
ON_COMMAND(IDC_RADIO6,OnRB6)
ON_COMMAND(IDC_CHECK1,OnCB1)
ON_COMMAND(IDC_CHECK2,OnCB2)
ON_COMMAND(IDC_CHECK3,OnCB3)
//ON_COMMAND(IDD_PROGRESS1,OnProgress)
END_MESSAGE_MAP()


BOOL CSampleDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	/*m_Prog.Create(WS_VISIBLE | WS_CHILD | WS_BORDER,r,this,IDD_PROGBAR);
	m_Prog.SetRange(0,120);
	m_Prog.SetStep(5);
	m_ProgPos=0;
	*/return TRUE;
}

void CSampleDialog::ProcessButtonPress(char Letter)
{
	CHangmanFinalDoc *pDoc = GetDocument();
	BOOL boolean;
	char Str[30];
	UINT OldGuessRemaining;

	OldGuessRemaining = pDoc->m_Hangman.GetGuessRemain();	// Get # of guess remaining
    boolean = pDoc->m_Hangman.CheckLetter(Letter);		// Check the letter
    if(boolean)
		SetDlgItemText( IDC_GUESS, pDoc->m_Hangman.GetCurrentGuess() );  // If true update
	_itoa_s(pDoc->m_Hangman.GetGuessRemain(), Str, 12);
	SetDlgItemText( IDC_GUESS_REMAINING, Str );

	if( OldGuessRemaining != pDoc->m_Hangman.GetGuessRemain() )
		DrawPic();									// Only draw picture if have to

	if( pDoc->m_Hangman.GetGuessRemain() == 0 )
		DoLoser();									// We have a loser do processing
	else
	if( pDoc->m_Hangman.CheckWordCompleted() )
		DoWinner();									// We have a winner do processing
}
void CSampleDialog::RefreshScoreDisplay()
{
	CHangmanFinalDoc *pDoc = GetDocument();
	char tmpStr[30];
	SetDlgItemText(IDC_WORD, pDoc->m_Hangman.GetCurrentWord());
	// Refresh all the text in the main dialog
	SetDlgItemText( IDC_GUESS, pDoc->m_Hangman.GetCurrentGuess() );
	_itoa_s( pDoc->m_Hangman.GetGamesPlayed(), tmpStr, 12 );
	SetDlgItemText( IDC_GAMES_PLAYED, tmpStr );
	_itoa_s( pDoc->m_Hangman.GetGamesWon(), tmpStr, 12 );
	SetDlgItemText( IDC_GAMES_WON, tmpStr );
	_itoa_s( pDoc->m_Hangman.GetPercentage(), tmpStr, 12 );
	SetDlgItemText( IDC_PERCENT_WON, tmpStr );	
	_itoa_s( pDoc->m_Hangman.GetGuessRemain(), tmpStr, 12 );
	SetDlgItemText( IDC_GUESS_REMAINING, tmpStr );

}

void CSampleDialog::DoLoser()
{
	CHangmanFinalDoc *pDoc = GetDocument();
	CString tmpStr1;

	// Display what the word was to the player
	tmpStr1 = "Sorry, the word was " + pDoc->m_Hangman.GetCurrentWord();
	
	if (AfxMessageBox(tmpStr1,MB_OK,0)==IDOK)
	{
		// Reset everything and do another round
		ResetButtons();
		pDoc->m_Hangman.LoadNewWord();
		pDoc->m_Hangman.IncrementGamesPlayed();
		DrawPic();
		RefreshScoreDisplay();
	}
}


void CSampleDialog::DoWinner()
{
	CHangmanFinalDoc *pDoc = GetDocument();
	CString tmpStr1;
	char tmpStr2[30];

	// Display message to player
	tmpStr1 =  "Good job!  You won in ";
	tmpStr1 += tmpStr2;
	tmpStr1 += " guesses.";

	if (AfxMessageBox(tmpStr1,MB_OK,0)==IDOK)
	{
	// Reset everything and do another round
	ResetButtons();
	pDoc->m_Hangman.LoadNewWord();
	pDoc->m_Hangman.IncrementGamesPlayed();
	pDoc->m_Hangman.IncrementGamesWon();
	DrawPic();
	RefreshScoreDisplay();
	}
}

void CSampleDialog::OnFileNew()
{
	CHangmanFinalDoc *pDoc = GetDocument();
	pDoc->m_Hangman.Reset();
	pDoc->m_Hangman.LoadNewWord();
	ResetButtons();
	DrawPic();
	RefreshScoreDisplay();
}
afx_msg void CSampleDialog::OnRed()
{
	MessageBox("Red","Collor selected");
}

afx_msg void CSampleDialog::OnGreen()
{
	MessageBox("Green","collor selected");
}
afx_msg void CSampleDialog::OnCancel()
{	
	int a;
	a=MessageBox("JO Baka,Close nahi karvanu?","Cancel",MB_YESNO);
	if(a==IDYES) EndDialog(0);	

}

afx_msg void CSampleDialog::OnRB1()
{
	CButton *rb1=(CButton *) GetDlgItem(IDC_RADIO1);
	CString str;
  // toggle check box
  if(rb1->GetCheck()) 
  {
		//ed1ptr->SetWindowText("pizza one selected");
		rb1->SetCheck(1);
	  	  rb1->GetWindowText(str);
  }
  else rb1->SetCheck(0);
 

//AfxMessageBox(str);

CEdit *cp=(CEdit *)GetDlgItem(IDC_EDIT1);
cp->SetWindowText(str);

}


afx_msg void CSampleDialog::OnRB2()
{
	CButton *rb2=(CButton *) GetDlgItem(IDC_RADIO2);
 CString str;
  // toggle check box
  if(rb2->GetCheck()) 
  {
		//ed1ptr->SetWindowText("pizza one selected");
		rb2->SetCheck(1);
	  	  rb2->GetWindowText(str);
  }
  else rb2->SetCheck(0);
 

//AfxMessageBox(str);

CEdit *cp=(CEdit *)GetDlgItem(IDC_EDIT1);
cp->SetWindowText(str);
}


afx_msg void CSampleDialog::OnRB3()
{
	CButton *rb3=(CButton *) GetDlgItem(IDC_RADIO3);
	CString str;
  // toggle check box
  if(rb3->GetCheck()) 
  {
		//ed1ptr->SetWindowText("pizza one selected");
		rb3->SetCheck(1);
	  	  rb3->GetWindowText(str);
  }
  else rb3->SetCheck(0);
 

//AfxMessageBox(str);

CEdit *cp=(CEdit *)GetDlgItem(IDC_EDIT1);
cp->SetWindowText(str);

}

afx_msg void CSampleDialog::OnRB4()
{
	CButton *rb4=(CButton *) GetDlgItem(IDC_RADIO4);
	CString str;
  // toggle check box
  if(rb4->GetCheck()) 
  {
		//ed4ptr->SetWindowText("pizza one selected");
		rb4->SetCheck(1);
	  	  rb4->GetWindowText(str);
  }
  else rb4->SetCheck(0);
 

//AfxMessageBox(str);

CEdit *cp=(CEdit *)GetDlgItem(IDC_EDIT2);
cp->SetWindowText(str);

}


afx_msg void CSampleDialog::OnRB5()
{
	CButton *rb5=(CButton *) GetDlgItem(IDC_RADIO5);
 CString str;
  // toggle check box
  if(rb5->GetCheck()) 
  {
		//ed1ptr->SetWindowText("pizza one selected");
		rb5->SetCheck(1);
	  	  rb5->GetWindowText(str);
  }
  else rb5->SetCheck(0);
 

//AfxMessageBox(str);

CEdit *cp=(CEdit *)GetDlgItem(IDC_EDIT2);
cp->SetWindowText(str);
}


afx_msg void CSampleDialog::OnRB6()
{
	CButton *rb6=(CButton *) GetDlgItem(IDC_RADIO6);
	CString str;
  // toggle check box
  if(rb6->GetCheck()) 
  {
		//ed1ptr->SetWindowText("pizza one selected");
		rb6->SetCheck(1);
	  	  rb6->GetWindowText(str);
  }
  else rb6->SetCheck(0);
 

//AfxMessageBox(str);

CEdit *cp=(CEdit *)GetDlgItem(IDC_EDIT2);
cp->SetWindowText(str);

}

afx_msg void CSampleDialog::OnCB1()
{
	CButton *cb1=(CButton *) GetDlgItem(IDC_CHECK1);
	CString str;
  // toggle check box
  if(cb1->GetCheck()) 
  {
		//ed1ptr->SetWindowText("pizza one selected");
		cb1->SetCheck(1);
	  	  cb1->GetWindowText(str);
  }
  else cb1->SetCheck(0);
 

//AfxMessageBox(str);

CEdit *cp=(CEdit *)GetDlgItem(IDC_EDIT3);
cp->SetWindowText(str);

}

afx_msg void CSampleDialog::OnCB2()
{
	CButton *cb2=(CButton *) GetDlgItem(IDC_CHECK2);
	CString str;
  // toggle check box
  if(cb2->GetCheck()) 
  {
		//ed1ptr->SetWindowText("pizza one selected");
		cb2->SetCheck(1);
	  	  cb2->GetWindowText(str);
  }
  else cb2->SetCheck(0);
 

//AfxMessageBox(str);

CEdit *cp=(CEdit *)GetDlgItem(IDC_EDIT3);
cp->SetWindowText(str);

}

afx_msg void CSampleDialog::OnCB3()
{
	CButton *cb3=(CButton *) GetDlgItem(IDC_CHECK3);
	CString str;
  // toggle check box
  if(cb3->GetCheck()) 
  {
		//ed1ptr->SetWindowText("pizza one selected");
		cb3->SetCheck(1);
	  	  cb3->GetWindowText(str);
  }
  else cb3->SetCheck(0);
 

//AfxMessageBox(str);

CEdit *cp=(CEdit *)GetDlgItem(IDC_EDIT3);
cp->SetWindowText(str);

}
/*
afx_msg void CSampleDialog::OnProgress()
{
	m_Prog.StepIt();
	m_ProgPos+=5;
	if(m_ProgPos==120)
		EndDialog(0);
}*/


CApp App;

