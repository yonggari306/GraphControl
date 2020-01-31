
// Sample ApplicationDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Sample Application.h"
#include "Sample ApplicationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSampleApplicationDlg dialog



CSampleApplicationDlg::CSampleApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SAMPLEAPPLICATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSampleApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_CIRCLE, sliderCircle);
}

BEGIN_MESSAGE_MAP(CSampleApplicationDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CSampleApplicationDlg message handlers

BOOL CSampleApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	m_CtrlGraph.Create(NULL,NULL, WS_CHILD | WS_VISIBLE , CRect(0, 0, 102, 102), this, 10001);

	bool ret = m_CtrlGraph.addPlot(plot1);
	if (ret == true)
	{
		((CCirclePlot*)plot1->get())->setColor(Gdiplus::Color::OrangeRed);
	
	}

	ret = m_CtrlGraph.addPlot(plot2);
	//if (ret == true)
	//{
	//	((CCirclePlot*)plot2->get())->setValue(45.0f, 360.0f-45.0f);
	//
	//}
	//((CCirclePlot*)(*plot1))->setValue(0.0f, 45.0f);

	SetBackgroundColor(RGB(255, 255, 255));
	sliderCircle.SetRange(0, 3600);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSampleApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSampleApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSampleApplicationDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	if (IDC_SLIDER_CIRCLE == pScrollBar->GetDlgCtrlID())
	{
		int iPos = sliderCircle.GetPos();

		((CCirclePlot*)m_CtrlGraph.getPlot(0).get())->setValue(0.0f, (Gdiplus::REAL)iPos / 10);
		//((CCirclePlot*)m_CtrlGraph.getPlot(1).get())->setValue((Gdiplus::REAL)iPos / 10, 360.0f - (Gdiplus::REAL)iPos / 10);
		//((CCirclePlot*)plot1->get())->setValue(0.0f, (Gdiplus::REAL)iPos / 10);
		//((CCirclePlot*)plot2->get())->setValue((Gdiplus::REAL)iPos / 10, 360.0f - (Gdiplus::REAL)iPos / 10);
		m_CtrlGraph.Invalidate();

	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}