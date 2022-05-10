
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication1Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTT_AUTO, &CMFCApplication1Dlg::OnBnClickedButtAuto)
	ON_BN_CLICKED(IDC_BUTT_SUDONG, &CMFCApplication1Dlg::OnBnClickedButtSudong)
	ON_BN_CLICKED(IDC_BUTT_RESET, &CMFCApplication1Dlg::OnBnClickedButtReset)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CMFCApplication1Dlg::OnBnClickedButtAuto() //자동버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int i, cnt = 0;
	int arr[45] = { 0 };
	BOOL chk;
	CString s;
	int random;
	int temp;

	for (cnt = 0; cnt < 45; cnt++)
	{
		chk = IsDlgButtonChecked(IDC_CHECK1 + cnt) ? FALSE : TRUE; //체크된 버튼이 체크1이 +i이고 눌린게 펄스면 트루;
		arr[cnt] = rand() % 45 +1;
		

		for (i = 0; i < cnt; i++) //중복없애기  
			//전체 크게 다시 검사하고 
			// 만약 배열[i]안의 값이 앞의 포문[cnt] 값과 같다면?..->
			// 다시 랜덤값 넣어주고 -> 다시돌리자 주사위굴리듯이 6 6 -> 4 5 
		{
			if (arr[cnt] == arr[i])
			{
				arr[cnt] = rand() % 45 + 1;
				continue;
			}
		}
	}
	s.Format(L"자동 선택 : %d  %d  %d  %d  %d  %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
	SetDlgItemText(IDC_STATIC_A, s);
}






void CMFCApplication1Dlg::OnBnClickedButtSudong() //수동버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int i, cnt = 0;
	int arr[45] = {0 };
	BOOL chk;
	CString s;
	int random;
	int temp;


	for (i = 1; i < 46; i++)
	{
		if (chk = IsDlgButtonChecked(IDC_CHECK1 + i-1))//check == TRUE
		{
			arr[cnt] = i;
			cnt++;
		}
	}

	if (cnt == 0)
	{
		AfxMessageBox(L"버튼을 체크해주세요 !");
	}

	for (int j = 0; j < 6; j++)
	{
		random = rand() % cnt;

		temp = arr[j];
		arr[j] = arr[random];
		arr[random] = temp;

		s.Format(L"수동 선택 : %d  %d  %d  %d  %d  %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
		//배열 무작위로 돌려서 출력?..
	}
	SetDlgItemText(IDC_STATIC_A, s);
}


void CMFCApplication1Dlg::OnBnClickedButtReset() //초기화 버튼 다시 원래상태로 돌아오기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString s;
	CButton* pCheck;
	for (int i = 0; i < 45; i++)
	{
		pCheck = (CButton*)GetDlgItem(IDC_CHECK1+i);
		pCheck->SetCheck(FALSE);

	}
	SetDlgItemText(IDC_STATIC_A, s);
}




void CMFCApplication1Dlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}

