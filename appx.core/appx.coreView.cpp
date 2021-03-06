
// appx.coreView.cpp : CappxcoreView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "appx.core.h"
#endif

#include "appx.coreDoc.h"
#include "appx.coreView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CappxcoreView

IMPLEMENT_DYNCREATE(CappxcoreView, CView)

BEGIN_MESSAGE_MAP(CappxcoreView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CappxcoreView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CappxcoreView 构造/析构

CappxcoreView::CappxcoreView()
{
	// TODO: 在此处添加构造代码

}

CappxcoreView::~CappxcoreView()
{
}

BOOL CappxcoreView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CappxcoreView 绘制

void CappxcoreView::OnDraw(CDC* /*pDC*/)
{
	CappxcoreDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CappxcoreView 打印


void CappxcoreView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CappxcoreView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CappxcoreView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CappxcoreView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CappxcoreView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CappxcoreView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CappxcoreView 诊断

#ifdef _DEBUG
void CappxcoreView::AssertValid() const
{
	CView::AssertValid();
}

void CappxcoreView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CappxcoreDoc* CappxcoreView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CappxcoreDoc)));
	return (CappxcoreDoc*)m_pDocument;
}
#endif //_DEBUG


// CappxcoreView 消息处理程序
