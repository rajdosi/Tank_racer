#if !defined(AFX_REDD_H__2767DFFD_C5FE_4A17_88DE_52BC1BBE2E2C__INCLUDED_)
#define AFX_REDD_H__2767DFFD_C5FE_4A17_88DE_52BC1BBE2E2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// redd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// redd dialog

class redd : public CDialog
{
// Construction
public:
	redd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(redd)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(redd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(redd)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REDD_H__2767DFFD_C5FE_4A17_88DE_52BC1BBE2E2C__INCLUDED_)
