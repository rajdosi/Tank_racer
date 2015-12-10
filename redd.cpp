// redd.cpp : implementation file
//

#include "stdafx.h"
#include "md.h"
#include "redd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// redd dialog


redd::redd(CWnd* pParent /*=NULL*/)
	: CDialog(redd::IDD, pParent)
{
	//{{AFX_DATA_INIT(redd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void redd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(redd)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(redd, CDialog)
	//{{AFX_MSG_MAP(redd)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// redd message handlers
