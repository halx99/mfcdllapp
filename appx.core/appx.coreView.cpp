
// appx.coreView.cpp : CappxcoreView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CappxcoreView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CappxcoreView ����/����

CappxcoreView::CappxcoreView()
{
	// TODO: �ڴ˴���ӹ������

}

CappxcoreView::~CappxcoreView()
{
}

BOOL CappxcoreView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CappxcoreView ����

void CappxcoreView::OnDraw(CDC* /*pDC*/)
{
	CappxcoreDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CappxcoreView ��ӡ


void CappxcoreView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CappxcoreView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CappxcoreView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CappxcoreView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CappxcoreView ���

#ifdef _DEBUG
void CappxcoreView::AssertValid() const
{
	CView::AssertValid();
}

void CappxcoreView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CappxcoreDoc* CappxcoreView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CappxcoreDoc)));
	return (CappxcoreDoc*)m_pDocument;
}
#endif //_DEBUG


// CappxcoreView ��Ϣ�������
