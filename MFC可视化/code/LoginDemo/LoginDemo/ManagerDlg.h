#pragma once


// CManagerDlg 对话框

class CManagerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManagerDlg)

public:
	CManagerDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CManagerDlg();

// 对话框数据
	enum { IDD = IDD_MANAGER 
	};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
