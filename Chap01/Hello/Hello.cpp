#include <afxwin.h>
#include "Hello.h"

CMyApp myApp;

/////////////////////////////////////////////////////////////////////////
// CMyApp member functions

BOOL CMyApp::InitInstance ()
{
    m_pMainWnd = new CMainWindow;
    m_pMainWnd->ShowWindow (m_nCmdShow);
    m_pMainWnd->UpdateWindow ();
    return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// CMainWindow message map and member functions

BEGIN_MESSAGE_MAP (CMainWindow, CFrameWnd)
    ON_WM_PAINT ()
END_MESSAGE_MAP ()

CMainWindow::CMainWindow ()
{
    Create (NULL, _T ("The Hello Application"));
}

void CMainWindow::OnPaint ()
{
	CRect rect;
	GetClientRect(&rect);


    CPaintDC dc (this);
	dc.SetViewportOrg(rect.Width()/2, rect.Height()/2);
	dc.SetBkMode(TRANSPARENT);

	for (int i = 0; i<300; i+=150)
	{
		LOGFONT lf;
		::ZeroMemory(&lf, sizeof(LOGFONT));
		lf.lfHeight = 160;
		lf.lfHeight = FW_BOLD;
		lf.lfEscapement = i;
		lf.lfOrientation = i;
		::lstrcpy(lf.lfFaceName, _T("Arial"));

		CFont font;
		font.CreateFontIndirect(&lf);

		CFont * pOldFont = dc.SelectObject(&font);
		dc.TextOut(0,0, CString(_T("M")));
		dc.SelectObject(pOldFont);
	}

}
