#include<afxwin.h>
#include<afxres.h>
#include<afxcmn.h>
#include"resource.h"

int f1=0,f2=0,f3=0;
class CMainWin:public CFrameWnd
{
public:
	CMainWin();

	afx_msg void OnDialog();
	afx_msg void OnExit();
	afx_msg void OnHelp();
	//afx_msg void OnHangL();
	//afx_msg void OnHangI();


	DECLARE_MESSAGE_MAP()
};

class CApp:public CWinApp
{
public:
	BOOL InitInstance();
};

class CSampleDialog:public CDialog
{
	CProgressCtrl m_Prog;
	int m_ProgPos;
public:
	CSampleDialog(LPCSTR DialogName, CWnd *Owner):
	  CDialog(DialogName, Owner){}

	  BOOL OnInitDialog();

	  //afx_msg void ProcessButtonPress();
	  afx_msg void OnRed();
	  afx_msg void OnGreen();
	  afx_msg void OnProgress();
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
	  afx_msg void OnOk();
	  DECLARE_MESSAGE_MAP();

	  
};




CMainWin::CMainWin()
{
	Create(NULL,"Demonstrate",WS_OVERLAPPEDWINDOW, rectDefault,NULL,MAKEINTRESOURCE(IDR_MENU1));
	
	INITCOMMONCONTROLSEX initCtrls;
	
	initCtrls.dwSize=sizeof(initCtrls);
	initCtrls.dwICC=ICC_PROGRESS_CLASS;
	//InItCommonControlEx(&initCtrls);
if(!LoadAccelTable("DialogMenu"))
		MessageBox("cant load accelerators","Errror");
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
//ON_COMMAND(ID_HANGMAN_LIMITED,)
//ON_COMMAND(ID_HANGMAN_INFINITE,OnHangI)
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
	MessageBox("TO Play HangMan\nA-Left\nD-Right\nW-Increase Speed\nS-Decrease Speed\nSpace-Bomb Fire\nESC-TO Exit.","Help");
}

/*afx_msg void CMainWin::OnHangL()
{
	    ShellExecute(NULL, "open", "C:\\Users\\Krunal Hingol\\Desktop\\oop\\Debug\\main.exe", NULL, NULL, SW_SHOWDEFAULT);

}

afx_msg void CMainWin::OnHangI()
{
	    ShellExecute(NULL, "open", "C:\\Users\\Krunal Hingol\\Desktop\\oop\\Debug\\maininfinite.exe", NULL, NULL, SW_SHOWDEFAULT);

}*/
BEGIN_MESSAGE_MAP(CSampleDialog,CDialog)
ON_COMMAND(IDC_BUTTON1,OnRed)
ON_COMMAND(IDOK,OnOk)
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
//ON_COMMAND(IDC_PROGRESS1,OnProgress)
END_MESSAGE_MAP()


BOOL CSampleDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	RECT r;
	r.left=10;r.top=10;
	r.bottom=30;
	r.right=200;
	m_Prog.Create(WS_VISIBLE | WS_BORDER,r,this,IDC_PROGRESS1);
	//m_Prog.Create(WS_VISIBLE | WS_CHILD | WS_BORDER,r,this,IDC_PROGRESS1);
	m_Prog.SetRange(0,300);
	m_Prog.SetStep(100);
	m_ProgPos=0;
	return TRUE;
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
	a=MessageBox("Are U Sure?","Cancel",MB_YESNO);
	if(a==IDYES) EndDialog(0);	

}

afx_msg void CSampleDialog::OnRB1()
{
	f1=1;
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
if(m_ProgPos==0)
{
	m_Prog.StepIt();
	m_ProgPos += 100;
}
}


afx_msg void CSampleDialog::OnRB2()
{
	f1=2;
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
if(m_ProgPos==0)
{
	m_Prog.StepIt();
	m_ProgPos += 100;
}
}


afx_msg void CSampleDialog::OnRB3()
{
	f1=3;
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
if(m_ProgPos==0)
{
	m_Prog.StepIt();
	m_ProgPos += 100;
}
}

afx_msg void CSampleDialog::OnRB4()
{
	f2=1;
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
if(m_ProgPos==100)
{
	m_Prog.StepIt();
	m_ProgPos += 100;
}
}


afx_msg void CSampleDialog::OnRB5()
{
	f2=2;
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
if(m_ProgPos==100)
{
	m_Prog.StepIt();
	m_ProgPos += 100;
}
}


afx_msg void CSampleDialog::OnRB6()
{
	f2=3;
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
if(m_ProgPos==100)
{
	m_Prog.StepIt();
	m_ProgPos += 100;
}
}

afx_msg void CSampleDialog::OnCB1()
{
	f3=1;
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
if(m_ProgPos==200)
{
	m_Prog.StepIt();
	m_ProgPos += 100;
}
}

afx_msg void CSampleDialog::OnCB2()
{
	f3=2;
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
if(m_ProgPos==200)
{
	m_Prog.StepIt();
	m_ProgPos += 100;
}
}

afx_msg void CSampleDialog::OnCB3()
{
	f3=3;
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
if(m_ProgPos==0)
{
	m_Prog.StepIt();
	m_ProgPos += 100;
}
}
/*
afx_msg void CSampleDialog::OnProgress()
{
	m_Prog.StepIt();
	m_ProgPos+=5;
	if(m_ProgPos==120)
		EndDialog(0);
}*/
afx_msg void CSampleDialog::OnOk(){
for(int i=1;i<=3;i++)
{
	for(int j=1;j<=3;j++)
	{
		for(int k=1;k<=3;k++)
		{
			if(f1==i && f2==j && f3==k)
			{	
				CString ii,jj,kk,str1,str2;
				ii.Format("%d", i);
				jj.Format("%d", j);
				kk.Format("%d", k);
				str1="C:\\Users\\Raj Dosi\\Desktop\\hangman\\exes\\main"+ii+jj+kk+".exe";
				ShellExecute(NULL,"open",str1,NULL,NULL,SW_SHOWDEFAULT);
				
					//ShellExecute(NULL, "open", str1, NULL, NULL, SW_SHOWDEFAULT);
			}
		}
	}
}

}

/*afx_msg void CSmapleDialog::OnProgress()
{
	m_Prog.StepIt();
	m_ProgPos += 30;
}*/
CApp App;

